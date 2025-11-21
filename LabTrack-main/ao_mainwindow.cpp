#include "ao_mainwindow.h"
#include "ui_ao_mainwindow.h"
#include <QTableWidgetItem>
#include <QListWidgetItem>
#include <QFileDialog>
#include <QPdfWriter>
#include <QPainter>
#include <QMessageBox>
#include <QInputDialog>
#include <QDateTime>

AOMainWindow::AOMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AOMainWindow),
    labRepo("test_labs.bin"),
    instructorRepo("test_instructors.bin"),
    roomRepo("test_rooms.bin"),
    buildingRepo("test_buildings.bin"),
    taRepo("test_tas.bin"),
    actualTimingRepo("test_timings.bin"),
    reportService(labRepo, instructorRepo, taRepo, roomRepo, buildingRepo, actualTimingRepo)
{
    ui->setupUi(this);

    // Connect sidebar buttons to switch pages
    connect(ui->btnDashboard, &QPushButton::clicked, this, &AOMainWindow::on_btnDashboard_clicked);
    connect(ui->btnManageLabs, &QPushButton::clicked, this, &AOMainWindow::on_btnManageLabs_clicked);
    connect(ui->btnManageInstructors, &QPushButton::clicked, this, &AOMainWindow::on_btnManageInstructors_clicked);
    connect(ui->btnManageTAs, &QPushButton::clicked, this, &AOMainWindow::on_btnManageTAs_clicked);
    connect(ui->btnScheduleLabs, &QPushButton::clicked, this, &AOMainWindow::on_btnScheduleLabs_clicked);
    connect(ui->btnReports, &QPushButton::clicked, this, &AOMainWindow::on_btnReports_clicked);

    // Connect manage buttons
    connect(ui->btnAddLab, &QPushButton::clicked, this, &AOMainWindow::on_btnAddLab_clicked);
    connect(ui->btnEditLab, &QPushButton::clicked, this, &AOMainWindow::on_btnEditLab_clicked);
    connect(ui->btnDeleteLab, &QPushButton::clicked, this, &AOMainWindow::on_btnDeleteLab_clicked);

    connect(ui->btnAddInstructor, &QPushButton::clicked, this, &AOMainWindow::on_btnAddInstructor_clicked);
    connect(ui->btnEditInstructor, &QPushButton::clicked, this, &AOMainWindow::on_btnEditInstructor_clicked);
    connect(ui->btnDeleteInstructor, &QPushButton::clicked, this, &AOMainWindow::on_btnDeleteInstructor_clicked);

    connect(ui->btnAddTA, &QPushButton::clicked, this, &AOMainWindow::on_btnAddTA_clicked);
    connect(ui->btnEditTA, &QPushButton::clicked, this, &AOMainWindow::on_btnEditTA_clicked);
    connect(ui->btnDeleteTA, &QPushButton::clicked, this, &AOMainWindow::on_btnDeleteTA_clicked);

    connect(ui->btnSetSchedule, &QPushButton::clicked, this, &AOMainWindow::on_btnSetSchedule_clicked);

    connect(ui->btnGenerateWeeklySchedule, &QPushButton::clicked, this, &AOMainWindow::on_btnGenerateWeeklySchedule_clicked);
    connect(ui->btnGenerateTimesheets, &QPushButton::clicked, this, &AOMainWindow::on_btnGenerateTimesheets_clicked);
    connect(ui->btnGenerateMakeupSchedule, &QPushButton::clicked, this, &AOMainWindow::on_btnGenerateMakeupSchedule_clicked);

    // Load initial data
    loadDashboard();
    loadManageLabs();
    loadManageInstructors();
    loadManageTAs();
    loadScheduleLabs();
    loadReports();

    // Set default page to Dashboard
    ui->stackedWidget->setCurrentWidget(ui->dashboardPage);
}

AOMainWindow::~AOMainWindow()
{
    delete ui;
}

void AOMainWindow::on_btnDashboard_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->dashboardPage);
}

void AOMainWindow::on_btnManageLabs_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->manageLabsPage);
}

void AOMainWindow::on_btnManageInstructors_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->manageInstructorsPage);
}

void AOMainWindow::on_btnManageTAs_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->manageTAsPage);
}

void AOMainWindow::on_btnScheduleLabs_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->scheduleLabsPage);
}

void AOMainWindow::on_btnReports_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->reportsPage);
}

void AOMainWindow::on_btnAddLab_clicked()
{
    bool ok;
    QString name = QInputDialog::getText(this, "Add Lab", "Lab Name:", QLineEdit::Normal, "", &ok);
    if (ok && !name.isEmpty()) {
        Lab lab(0, name.toStdString(), "", 0, 0, 0, "Active");
        labRepo.addLab(lab);
        loadManageLabs();
    }
}

void AOMainWindow::on_btnEditLab_clicked()
{
    // Placeholder: Implement edit logic
    QMessageBox::information(this, "Edit Lab", "Edit functionality not implemented yet.");
}

void AOMainWindow::on_btnDeleteLab_clicked()
{
    // Placeholder: Implement delete logic
    QMessageBox::information(this, "Delete Lab", "Delete functionality not implemented yet.");
}

void AOMainWindow::on_btnAddInstructor_clicked()
{
    bool ok;
    QString name = QInputDialog::getText(this, "Add Instructor", "Instructor Name:", QLineEdit::Normal, "", &ok);
    if (ok && !name.isEmpty()) {
        Instructor instructor(0, name.toStdString(), "");
        instructorRepo.addInstructor(instructor);
        loadManageInstructors();
    }
}

void AOMainWindow::on_btnEditInstructor_clicked()
{
    QMessageBox::information(this, "Edit Instructor", "Edit functionality not implemented yet.");
}

void AOMainWindow::on_btnDeleteInstructor_clicked()
{
    QMessageBox::information(this, "Delete Instructor", "Delete functionality not implemented yet.");
}

void AOMainWindow::on_btnAddTA_clicked()
{
    bool ok;
    QString name = QInputDialog::getText(this, "Add TA", "TA Name:", QLineEdit::Normal, "", &ok);
    if (ok && !name.isEmpty()) {
        TA ta(0, name.toStdString(), "");
        taRepo.addTA(ta);
        loadManageTAs();
    }
}

void AOMainWindow::on_btnEditTA_clicked()
{
    QMessageBox::information(this, "Edit TA", "Edit functionality not implemented yet.");
}

void AOMainWindow::on_btnDeleteTA_clicked()
{
    QMessageBox::information(this, "Delete TA", "Delete functionality not implemented yet.");
}

void AOMainWindow::on_btnSetSchedule_clicked()
{
    QMessageBox::information(this, "Set Schedule", "Set schedule functionality not implemented yet.");
}

void AOMainWindow::on_btnGenerateWeeklySchedule_clicked()
{
    QString report = QString::fromStdString(reportService.generateWeeklyScheduleReport());
    ui->textEditReports->setPlainText(report);
}

void AOMainWindow::on_btnGenerateTimesheets_clicked()
{
    QString report = QString::fromStdString(reportService.generateTimesheetReport());
    ui->textEditReports->setPlainText(report);
}

void AOMainWindow::on_btnGenerateMakeupSchedule_clicked()
{
    QString report = QString::fromStdString(reportService.generateMakeupScheduleReport());
    ui->textEditReports->setPlainText(report);
}

void AOMainWindow::loadDashboard()
{
    auto allLabs = labRepo.getAllLabs();
    ui->lblTotalLabsCount->setText(QString::number(allLabs.size()));

    auto allInstructors = instructorRepo.getAllInstructors();
    ui->lblTotalInstructorsCount->setText(QString::number(allInstructors.size()));

    auto allTAs = taRepo.getAllTAs();
    ui->lblTotalTAsCount->setText(QString::number(allTAs.size()));
}

void AOMainWindow::loadManageLabs()
{
    auto allLabs = labRepo.getAllLabs();
    ui->tableLabs->setRowCount(allLabs.size());
    ui->tableLabs->setColumnCount(4);
    ui->tableLabs->setHorizontalHeaderLabels({"ID", "Name", "Instructor", "Status"});

    for (int i = 0; i < allLabs.size(); ++i) {
        const auto& lab = allLabs[i];
        auto instructor = instructorRepo.getInstructorById(lab.getInstructorId());

        ui->tableLabs->setItem(i, 0, new QTableWidgetItem(QString::number(lab.getId())));
        ui->tableLabs->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(lab.getName())));
        ui->tableLabs->setItem(i, 2, new QTableWidgetItem(instructor ? QString::fromStdString(instructor->getName()) : "Unknown"));
        ui->tableLabs->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(lab.getStatus())));
    }
}

void AOMainWindow::loadManageInstructors()
{
    auto allInstructors = instructorRepo.getAllInstructors();
    ui->tableInstructors->setRowCount(allInstructors.size());
    ui->tableInstructors->setColumnCount(3);
    ui->tableInstructors->setHorizontalHeaderLabels({"ID", "Name", "Email"});

    for (int i = 0; i < allInstructors.size(); ++i) {
        const auto& instructor = allInstructors[i];
        ui->tableInstructors->setItem(i, 0, new QTableWidgetItem(QString::number(instructor.getId())));
        ui->tableInstructors->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(instructor.getName())));
        ui->tableInstructors->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(instructor.getEmail())));
    }
}

void AOMainWindow::loadManageTAs()
{
    auto allTAs = taRepo.getAllTAs();
    ui->tableTAs->setRowCount(allTAs.size());
    ui->tableTAs->setColumnCount(3);
    ui->tableTAs->setHorizontalHeaderLabels({"ID", "Name", "Email"});

    for (int i = 0; i < allTAs.size(); ++i) {
        const auto& ta = allTAs[i];
        ui->tableTAs->setItem(i, 0, new QTableWidgetItem(QString::number(ta.getId())));
        ui->tableTAs->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(ta.getName())));
        ui->tableTAs->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(ta.getEmail())));
    }
}

void AOMainWindow::loadScheduleLabs()
{
    auto allLabs = labRepo.getAllLabs();
    ui->tableSchedule->setRowCount(allLabs.size());
    ui->tableSchedule->setColumnCount(5);
    ui->tableSchedule->setHorizontalHeaderLabels({"Lab Name", "Instructor", "Room", "Day", "Time"});

    for (int i = 0; i < allLabs.size(); ++i) {
        const auto& lab = allLabs[i];
        auto instructor = instructorRepo.getInstructorById(lab.getInstructorId());
        auto room = roomRepo.getRoomById(lab.getRoomId());

        ui->tableSchedule->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(lab.getName())));
        ui->tableSchedule->setItem(i, 1, new QTableWidgetItem(instructor ? QString::fromStdString(instructor->getName()) : "Unknown"));
        ui->tableSchedule->setItem(i, 2, new QTableWidgetItem(room ? QString::fromStdString(room->getName()) : "Unknown"));
        ui->tableSchedule->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(lab.getSchedule()).split(" ")[0]));
        ui->tableSchedule->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(lab.getSchedule()).split(" ")[1]));
    }
}

void AOMainWindow::loadReports()
{
    // Reports page is loaded on button clicks
}

void AOMainWindow::exportToPDF(const QString& title, QTableWidget* table)
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
        if (y > 1000) {
            writer.newPage();
            y = 100;
        }
    }

    QMessageBox::information(this, "Export Complete", "PDF exported successfully!");
}
