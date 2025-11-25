#include "attendant_mainwindow.h"
#include "ui_attendant_mainwindow.h"
#include <QMessageBox>
#include <QMenuBar>
#include <QDate>
#include <QTime>
#include <QTableWidgetItem>
#include "backend/repositories/UserRepository.h"
#include "backend/models/ActualTiming.h"
#include "backend/utils/DateUtils.h"

AttendantMainWindow::AttendantMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AttendantMainWindow),
    labRepo("labs.bin"),
    roomRepo("rooms.bin"),
    buildingRepo("buildings.bin"),
    actualTimingRepo("actual_timings.bin"),
    labService(nullptr)
{
    ui->setupUi(this);
    
    labService = new LabService(labRepo, roomRepo, buildingRepo);
    
    connect(ui->btnDashboard, &QPushButton::clicked, this, &AttendantMainWindow::on_btnDashboard_clicked);
    connect(ui->btnTimesheets, &QPushButton::clicked, this, &AttendantMainWindow::on_btnTimesheets_clicked);
    connect(ui->btnFillTimesheet, &QPushButton::clicked, this, &AttendantMainWindow::on_btnFillTimesheet_clicked);
    connect(ui->btnSubmitTimesheet, &QPushButton::clicked, this, &AttendantMainWindow::on_btnSubmitTimesheet_clicked);
    connect(ui->comboSelectLab, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &AttendantMainWindow::on_comboSelectLab_currentIndexChanged);
    
    loadDashboard();
    loadTimesheets();
    loadFillTimesheet();
    
    ui->stackedWidget->setCurrentWidget(ui->dashboardPage);
    
    QAction *logout = new QAction("Logout", this);
    connect(logout, &QAction::triggered, this, [this]() {
        if (this->parentWidget()) this->parentWidget()->show();
        this->close();
    });
    menuBar()->addAction(logout);
}

AttendantMainWindow::AttendantMainWindow(int attendantId, QWidget *parent) :
    AttendantMainWindow(parent)
{
    this->attendantId = attendantId;
    UserRepository userRepo("users.bin");
    auto users = userRepo.loadAll();
    for (const auto& u : users) {
        if (u.getId() == attendantId) {
            currentUser = u;
            break;
        }
    }
}

AttendantMainWindow::~AttendantMainWindow()
{
    delete labService;
    delete ui;
}

int AttendantMainWindow::getBuildingIdForAttendant()
{
    auto buildings = buildingRepo.getAll();
    for (const auto& b : buildings) {
        if (b.getAttendantId() == attendantId) {
            return b.getId();
        }
    }
    return -1;
}

void AttendantMainWindow::on_btnDashboard_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->dashboardPage);
    loadDashboard();
}

void AttendantMainWindow::on_btnTimesheets_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->timesheetsPage);
    loadTimesheets();
}

void AttendantMainWindow::on_btnFillTimesheet_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->fillTimesheetPage);
    loadFillTimesheet();
}

void AttendantMainWindow::on_comboSelectLab_currentIndexChanged(int index)
{
    if (index < 0) return;
    int labId = ui->comboSelectLab->itemData(index).toInt();
    auto labOpt = labRepo.getLabById(labId);
    if (!labOpt.has_value()) return;
    
    // Set scheduled time as default
    ui->timeStart->setTime(QTime::fromString(QString::fromStdString(labOpt->getSchedule().getStart()), "hh:mm"));
    ui->timeEnd->setTime(QTime::fromString(QString::fromStdString(labOpt->getSchedule().getEnd()), "hh:mm"));
}

void AttendantMainWindow::on_btnSubmitTimesheet_clicked()
{
    int labId = ui->comboSelectLab->currentData().toInt();
    if (labId == 0) {
        QMessageBox::warning(this, "Error", "Please select a lab.");
        return;
    }
    
    QString dateStr = ui->dateEdit->date().toString("yyyy-MM-dd");
    QString startStr = ui->timeStart->time().toString("hh:mm");
    QString endStr = ui->timeEnd->time().toString("hh:mm");
    
    // Check if this is a leave (00:00 - 00:00)
    bool isLeave = (startStr == "00:00" && endStr == "00:00");
    
    if (!isLeave && startStr >= endStr) {
        QMessageBox::warning(this, "Error", "Start time must be before end time (or use 00:00 - 00:00 to mark as leave).");
        return;
    }
    
    // Calculate duration in hours (0 for leaves)
    QTime start = QTime::fromString(startStr, "hh:mm");
    QTime end = QTime::fromString(endStr, "hh:mm");
    double duration = isLeave ? 0.0 : start.secsTo(end) / 3600.0;
    
    // Verify attendant is assigned to this building
    auto labOpt = labRepo.getLabById(labId);
    if (!labOpt.has_value()) {
        QMessageBox::critical(this, "Error", "Lab not found.");
        return;
    }
    
    int buildingId = getBuildingIdForAttendant();
    if (buildingId == -1 || labOpt->getBuildingId() != buildingId) {
        QMessageBox::critical(this, "Error", "You can only fill timesheets for labs in your assigned building.");
        return;
    }
    
    // Create and save timing record
    ActualTiming timing(labId, attendantId, dateStr.toStdString(), startStr.toStdString(), endStr.toStdString(), duration, "Submitted");
    actualTimingRepo.add(timing);
    
    QMessageBox::information(this, "Success", "Timesheet entry added successfully.");
    loadTimesheets();
    loadFillTimesheet();
}

void AttendantMainWindow::loadDashboard()
{
    int buildingId = getBuildingIdForAttendant();
    if (buildingId == -1) {
        ui->lblBuildingName->setText("Not assigned to any building");
        ui->lblTotalLabsCount->setText("0");
        return;
    }
    
    auto building = buildingRepo.getAll();
    for (const auto& b : building) {
        if (b.getId() == buildingId) {
            ui->lblBuildingName->setText(QString::fromStdString(b.getName()));
            break;
        }
    }
    
    auto labs = labRepo.getLabsByBuildingId(buildingId);
    ui->lblTotalLabsCount->setText(QString::number(labs.size()));
}

void AttendantMainWindow::loadTimesheets()
{
    int buildingId = getBuildingIdForAttendant();
    if (buildingId == -1) return;
    
    auto labs = labRepo.getLabsByBuildingId(buildingId);
    ui->tableTimesheets->setRowCount(0);
    ui->tableTimesheets->setColumnCount(5);
    ui->tableTimesheets->setHorizontalHeaderLabels({"Date", "Lab", "Start Time", "End Time", "Duration (hrs)"});
    
    int row = 0;
    for (const auto& lab : labs) {
        auto timings = actualTimingRepo.getTimingsByLabId(lab.getId());
        for (const auto& timing : timings) {
            ui->tableTimesheets->insertRow(row);
            
            ui->tableTimesheets->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(timing.getDate())));
            ui->tableTimesheets->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(lab.getName())));
            ui->tableTimesheets->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(timing.getStartTime())));
            ui->tableTimesheets->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(timing.getEndTime())));
            ui->tableTimesheets->setItem(row, 4, new QTableWidgetItem(QString::number(timing.getDuration(), 'f', 2)));
            row++;
        }
    }
}

void AttendantMainWindow::loadFillTimesheet()
{
    int buildingId = getBuildingIdForAttendant();
    if (buildingId == -1) return;
    
    ui->comboSelectLab->clear();
    auto labs = labRepo.getLabsByBuildingId(buildingId);
    for (const auto& lab : labs) {
        ui->comboSelectLab->addItem(QString::fromStdString(lab.getName()), QVariant(lab.getId()));
    }
    
    ui->dateEdit->setDate(QDate::currentDate());
    if (!labs.empty()) {
        on_comboSelectLab_currentIndexChanged(0);
    }
}

