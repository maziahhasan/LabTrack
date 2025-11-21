#include "hod_mainwindow.h"
#include "ui_hod_mainwindow.h"
#include <QTableWidgetItem>
#include <QListWidgetItem>
#include <QFileDialog>
#include <QPdfWriter>
#include <QPainter>
#include <QMessageBox>

HODMainWindow::HODMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HODMainWindow),
    labRepo("test_labs.bin"),
    instructorRepo("test_instructors.bin"),
    roomRepo("test_rooms.bin"),
    buildingRepo("test_buildings.bin"),
    taRepo("test_tas.bin"),
    actualTimingRepo("test_timings.bin")
{
    ui->setupUi(this);

    // Connect sidebar buttons to switch pages
    connect(ui->btnDashboard, &QPushButton::clicked, this, &HODMainWindow::on_btnDashboard_clicked);
    connect(ui->btnWeeklySchedule, &QPushButton::clicked, this, &HODMainWindow::on_btnWeeklySchedule_clicked);
    connect(ui->btnWeeklyTimesheets, &QPushButton::clicked, this, &HODMainWindow::on_btnWeeklyTimesheets_clicked);
    connect(ui->btnLabHistory, &QPushButton::clicked, this, &HODMainWindow::on_btnLabHistory_clicked);
    connect(ui->btnMakeupRequests, &QPushButton::clicked, this, &HODMainWindow::on_btnMakeupRequests_clicked);

    // Connect other controls
    connect(ui->comboSelectLab, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &HODMainWindow::on_comboSelectLab_currentIndexChanged);
    connect(ui->btnExportSchedule, &QPushButton::clicked, this, &HODMainWindow::on_btnExportSchedule_clicked);
    connect(ui->btnExportTimesheets, &QPushButton::clicked, this, &HODMainWindow::on_btnExportTimesheets_clicked);
    connect(ui->btnExportHistory, &QPushButton::clicked, this, &HODMainWindow::on_btnExportHistory_clicked);
    connect(ui->btnExportRequests, &QPushButton::clicked, this, &HODMainWindow::on_btnExportRequests_clicked);

    // Load initial data
    loadDashboard();
    loadWeeklySchedule();
    loadWeeklyTimesheets();
    loadLabHistory();
    loadMakeupRequests();

    // Set default page to Dashboard
    ui->stackedWidget->setCurrentWidget(ui->dashboardPage);
}

HODMainWindow::~HODMainWindow()
{
    delete ui;
}

void HODMainWindow::on_btnDashboard_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->dashboardPage);
}

void HODMainWindow::on_btnWeeklySchedule_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->weeklySchedulePage);
}

void HODMainWindow::on_btnWeeklyTimesheets_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->weeklyTimesheetsPage);
}

void HODMainWindow::on_btnLabHistory_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->labHistoryPage);
}

void HODMainWindow::on_btnMakeupRequests_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->makeupRequestsPage);
}

void HODMainWindow::on_comboSelectLab_currentIndexChanged(int index)
{
    if (index >= 0) {
        loadLabHistory();
    }
}

void HODMainWindow::on_btnExportSchedule_clicked()
{
    exportToPDF("Weekly Lab Schedule", ui->tableWeeklySchedule);
}

void HODMainWindow::on_btnExportTimesheets_clicked()
{
    exportToPDF("Weekly Timesheets", ui->tableWeeklyTimesheets);
}

void HODMainWindow::on_btnExportHistory_clicked()
{
    exportToPDF("Lab History", ui->tableLabHistory);
}

void HODMainWindow::on_btnExportRequests_clicked()
{
    exportToPDF("Makeup Lab Requests", ui->tableMakeupRequests);
}

void HODMainWindow::loadDashboard()
{
    auto allLabs = labRepo.getAllLabs();
    ui->lblTotalLabsCount->setText(QString::number(allLabs.size()));

    int activeLabs = 0;
    for (const auto& lab : allLabs) {
        if (lab.getStatus() == "Active") activeLabs++;
    }
    ui->lblActiveLabsCount->setText(QString::number(activeLabs));

    // Placeholder for pending makeup requests
    ui->lblPendingRequestsCount->setText("3");
}

void HODMainWindow::loadWeeklySchedule()
{
    auto allLabs = labRepo.getAllLabs();
    ui->tableWeeklySchedule->setRowCount(allLabs.size());
    ui->tableWeeklySchedule->setColumnCount(6);
    ui->tableWeeklySchedule->setHorizontalHeaderLabels({"Lab Name", "Instructor", "Room", "Day", "Time", "Status"});

    for (int i = 0; i < allLabs.size(); ++i) {
        const auto& lab = allLabs[i];
        auto instructor = instructorRepo.getInstructorById(lab.getInstructorId());
        auto room = roomRepo.getRoomById(lab.getRoomId());

        ui->tableWeeklySchedule->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(lab.getName())));
        ui->tableWeeklySchedule->setItem(i, 1, new QTableWidgetItem(instructor ? QString::fromStdString(instructor->getName()) : "Unknown"));
        ui->tableWeeklySchedule->setItem(i, 2, new QTableWidgetItem(room ? QString::fromStdString(room->getName()) : "Unknown"));
        ui->tableWeeklySchedule->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(lab.getSchedule()).split(" ")[0])); // Day
        ui->tableWeeklySchedule->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(lab.getSchedule()).split(" ")[1])); // Time
        ui->tableWeeklySchedule->setItem(i, 5, new QTableWidgetItem(QString::fromStdString(lab.getStatus())));
    }

    // Populate week combo
    ui->comboWeek->clear();
    ui->comboWeek->addItem("Current Week");
    ui->comboWeek->addItem("Next Week");
}

void HODMainWindow::loadWeeklyTimesheets()
{
    auto timings = actualTimingRepo.getAllActualTimings();
    ui->tableWeeklyTimesheets->setRowCount(timings.size());
    ui->tableWeeklyTimesheets->setColumnCount(7);
    ui->tableWeeklyTimesheets->setHorizontalHeaderLabels({"Date", "Lab", "TA", "Scheduled Start", "Actual Start", "Actual End", "Contact Hours"});

    for (int i = 0; i < timings.size(); ++i) {
        const auto& timing = timings[i];
        auto lab = labRepo.getLabById(timing.getLabId());
        auto ta = taRepo.getTAById(timing.getTaId());

        ui->tableWeeklyTimesheets->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(timing.getDate())));
        ui->tableWeeklyTimesheets->setItem(i, 1, new QTableWidgetItem(lab ? QString::fromStdString(lab->getName()) : "Unknown"));
        ui->tableWeeklyTimesheets->setItem(i, 2, new QTableWidgetItem(ta ? QString::fromStdString(ta->getName()) : "Unknown"));
        ui->tableWeeklyTimesheets->setItem(i, 3, new QTableWidgetItem("10:00")); // Placeholder
        ui->tableWeeklyTimesheets->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(timing.getStartTime())));
        ui->tableWeeklyTimesheets->setItem(i, 5, new QTableWidgetItem(QString::fromStdString(timing.getEndTime())));
        ui->tableWeeklyTimesheets->setItem(i, 6, new QTableWidgetItem("2.0")); // Placeholder calculation
    }

    // Populate week combo
    ui->comboTimesheetWeek->clear();
    ui->comboTimesheetWeek->addItem("Current Week");
    ui->comboTimesheetWeek->addItem("Next Week");
}

void HODMainWindow::loadLabHistory()
{
    ui->comboSelectLab->clear();
    auto allLabs = labRepo.getAllLabs();
    for (const auto& lab : allLabs) {
        ui->comboSelectLab->addItem(QString::fromStdString(lab.getName()), QVariant(lab.getId()));
    }

    if (!allLabs.empty()) {
        const auto& selectedLab = allLabs[0]; // Default to first lab
        auto timings = actualTimingRepo.getActualTimingsByLabId(selectedLab.getId());

        double totalHours = 0;
        int totalLeaves = 0;
        int totalMakeup = 0;

        for (const auto& timing : timings) {
            // Calculate hours (placeholder)
            totalHours += 2.0;
        }

        ui->lblTotalContactHoursValue->setText(QString::number(totalHours));
        ui->lblTotalLeavesValue->setText(QString::number(totalLeaves));
        ui->lblTotalMakeupSessionsValue->setText(QString::number(totalMakeup));

        ui->tableLabHistory->setRowCount(timings.size());
        ui->tableLabHistory->setColumnCount(5);
        ui->tableLabHistory->setHorizontalHeaderLabels({"Date", "TA", "Start Time", "End Time", "Status"});

        for (int i = 0; i < timings.size(); ++i) {
            const auto& timing = timings[i];
            auto ta = taRepo.getTAById(timing.getTaId());

            ui->tableLabHistory->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(timing.getDate())));
            ui->tableLabHistory->setItem(i, 1, new QTableWidgetItem(ta ? QString::fromStdString(ta->getName()) : "Unknown"));
            ui->tableLabHistory->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(timing.getStartTime())));
            ui->tableLabHistory->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(timing.getEndTime())));
            ui->tableLabHistory->setItem(i, 4, new QTableWidgetItem("Completed")); // Placeholder
        }
    }
}

void HODMainWindow::loadMakeupRequests()
{
    // Placeholder data for makeup requests
    ui->tableMakeupRequests->setRowCount(3);
    ui->tableMakeupRequests->setColumnCount(6);
    ui->tableMakeupRequests->setHorizontalHeaderLabels({"Lab Name", "Instructor", "Requested Date", "Reason", "Status", "Actions"});

    QStringList labs = {"CS101", "CS102", "CS103"};
    QStringList instructors = {"Dr. Smith", "Dr. Johnson", "Dr. Brown"};
    QStringList dates = {"2024-11-20", "2024-11-22", "2024-11-25"};
    QStringList reasons = {"Instructor unavailable", "Room maintenance", "Holiday"];
    QStringList statuses = {"Pending", "Approved", "Rejected"};

    for (int i = 0; i < 3; ++i) {
        ui->tableMakeupRequests->setItem(i, 0, new QTableWidgetItem(labs[i]));
        ui->tableMakeupRequests->setItem(i, 1, new QTableWidgetItem(instructors[i]));
        ui->tableMakeupRequests->setItem(i, 2, new QTableWidgetItem(dates[i]));
        ui->tableMakeupRequests->setItem(i, 3, new QTableWidgetItem(reasons[i]));
        ui->tableMakeupRequests->setItem(i, 4, new QTableWidgetItem(statuses[i]));

        // Add action buttons (placeholder)
        QPushButton* approveBtn = new QPushButton("Approve");
        QPushButton* rejectBtn = new QPushButton("Reject");
        QWidget* widget = new QWidget();
        QHBoxLayout* layout = new QHBoxLayout(widget);
        layout->addWidget(approveBtn);
        layout->addWidget(rejectBtn);
        layout->setContentsMargins(0, 0, 0, 0);
        ui->tableMakeupRequests->setCellWidget(i, 5, widget);
    }

    // Populate status filter
    ui->comboFilterStatus->clear();
    ui->comboFilterStatus->addItem("All");
    ui->comboFilterStatus->addItem("Pending");
    ui->comboFilterStatus->addItem("Approved");
    ui->comboFilterStatus->addItem("Rejected");
}

void HODMainWindow::exportToPDF(const QString& title, QTableWidget* table)
{
    QString fileName = QFileDialog::getSaveFileName(this, "Export to PDF", "", "PDF Files (*.pdf)");
    if (fileName.isEmpty()) return;

    QPdfWriter writer(fileName);
    writer.setPageSize(QPageSize(QPageSize::A4));
    writer.setTitle(title);

    QPainter painter(&writer);
    painter.setFont(QFont("Arial", 12));

    int y = 100;
    painter.drawText(100, y, title);
    y += 50;

    // Draw table headers
    for (int col = 0; col < table->columnCount(); ++col) {
        QTableWidgetItem* headerItem = table->horizontalHeaderItem(col);
        if (headerItem) {
            painter.drawText(100 + col * 150, y, headerItem->text());
        }
    }
    y += 30;

    // Draw table data
    for (int row = 0; row < table->rowCount(); ++row) {
        for (int col = 0; col < table->columnCount(); ++col) {
            QTableWidgetItem* item = table->item(row, col);
            if (item) {
                painter.drawText(100 + col * 150, y, item->text());
            }
        }
        y += 25;
        if (y > 1000) { // New page if needed
            writer.newPage();
            y = 100;
        }
    }

    QMessageBox::information(this, "Export Complete", "PDF exported successfully!");
}
