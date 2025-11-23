#include "hod_mainwindow.h"
#include "ui_hod_mainwindow.h"
#include <QTableWidgetItem>
#include <QListWidgetItem>
#include <QFileDialog>
#include <QPdfWriter>
#include <QPainter>
#include <QMessageBox>
#include <QMenuBar>
#include <QDate>
#include "backend/utils/DateUtils.h"

HODMainWindow::HODMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HODMainWindow),
    labRepo("test_labs.bin"),
    instructorRepo("test_instructors.bin"),
    roomRepo("test_rooms.bin"),
    buildingRepo("test_buildings.bin"),
    taRepo("test_tas.bin"),
    actualTimingRepo("test_timings.bin"),
    reportService(nullptr)
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

    // construct reportService now that repos are initialized
    reportService = new ReportService(labRepo, instructorRepo, taRepo, roomRepo, buildingRepo, actualTimingRepo);


    // Set default page to Dashboard
    ui->stackedWidget->setCurrentWidget(ui->dashboardPage);

    // Add Logout action to the menu bar
    QAction *logout = new QAction("Logout", this);
    connect(logout, &QAction::triggered, this, [this]() {
        if (this->parentWidget()) this->parentWidget()->show();
        this->close();
    });
    menuBar()->addAction(logout);
}

HODMainWindow::HODMainWindow(int hodId, QWidget *parent)
    : HODMainWindow(parent)
{
    this->hodId = hodId;
    // Now you can use hodId to filter data shown in the UI if needed
}

HODMainWindow::~HODMainWindow()
{
    delete reportService;
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
    // Get current week's Monday date (simplified - in production, calculate actual Monday)
    QDate today = QDate::currentDate();
    int daysToMonday = (today.dayOfWeek() == Qt::Monday) ? 0 : (today.dayOfWeek() - Qt::Monday);
    QDate monday = today.addDays(-daysToMonday);
    std::string mondayDate = monday.toString("yyyy-MM-dd").toStdString();
    
    // Get labs with timesheets for this week using ReportService
    auto labs = reportService->labsWithTimesheetsForWeek(mondayDate);
    
    // Collect all timings for these labs in the week
    std::vector<std::pair<ActualTiming, Lab>> timingLabPairs;
    long start = DateUtils::parseDate(mondayDate);
    long end = start + 6*24*60*60;
    
    for (const auto& lab : labs) {
        const auto& times = lab.getTimeSheets();
        for (const auto& t : times) {
            long d = DateUtils::parseDate(t.getDate());
            if (d >= start && d <= end) {
                timingLabPairs.push_back({t, lab});
            }
        }
    }
    
    ui->tableWeeklyTimesheets->setRowCount(timingLabPairs.size());
    ui->tableWeeklyTimesheets->setColumnCount(7);
    ui->tableWeeklyTimesheets->setHorizontalHeaderLabels({"Date", "Lab", "TA", "Scheduled Start", "Actual Start", "Actual End", "Contact Hours"});

    for (int i = 0; i < timingLabPairs.size(); ++i) {
        const auto& timing = timingLabPairs[i].first;
        const auto& lab = timingLabPairs[i].second;
        auto ta = taRepo.getTAById(timing.getTaId());
        
        // Calculate contact hours
        double hours = DateUtils::hoursBetween(timing.getStartTime(), timing.getEndTime());

        ui->tableWeeklyTimesheets->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(timing.getDate())));
        ui->tableWeeklyTimesheets->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(lab.getName())));
        ui->tableWeeklyTimesheets->setItem(i, 2, new QTableWidgetItem(ta ? QString::fromStdString(ta->getName()) : "Unknown"));
        ui->tableWeeklyTimesheets->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(lab.getSchedule().getStart())));
        ui->tableWeeklyTimesheets->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(timing.getStartTime())));
        ui->tableWeeklyTimesheets->setItem(i, 5, new QTableWidgetItem(QString::fromStdString(timing.getEndTime())));
        ui->tableWeeklyTimesheets->setItem(i, 6, new QTableWidgetItem(QString::number(hours, 'f', 2)));
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
        int selectedLabId = ui->comboSelectLab->currentData().toInt();
        if (selectedLabId == 0 && !allLabs.empty()) {
            selectedLabId = allLabs[0].getId();
        }
        
        // Get semester start and end dates (simplified - use current year)
        QDate today = QDate::currentDate();
        std::string startDate = QDate(today.year(), 1, 1).toString("yyyy-MM-dd").toStdString();
        std::string endDate = QDate(today.year(), 12, 31).toString("yyyy-MM-dd").toStdString();
        
        // Use ReportService to compute summary
        TimeSheetSummary summary = reportService->computeTimeSheetSummary(selectedLabId, startDate, endDate);
        
        ui->lblTotalContactHoursValue->setText(QString::number(summary.totalHours, 'f', 2));
        ui->lblTotalLeavesValue->setText(QString::number(summary.leaves));
        
        // Count makeup sessions (sessions not on scheduled day)
        Lab lab = labRepo.getById(selectedLabId);
        auto timings = actualTimingRepo.getActualTimingsByLabId(selectedLabId);
        std::string scheduledDay = DateUtils::normalizeDay(lab.getSchedule().getDay());
        int makeupCount = 0;
        for (const auto& timing : timings) {
            long d = DateUtils::parseDate(timing.getDate());
            std::string actualDay = DateUtils::dayOfWeek(d);
            if (DateUtils::normalizeDay(actualDay) != scheduledDay) {
                makeupCount++;
            }
        }
        ui->lblTotalMakeupSessionsValue->setText(QString::number(makeupCount));

        ui->tableLabHistory->setRowCount(timings.size());
        ui->tableLabHistory->setColumnCount(5);
        ui->tableLabHistory->setHorizontalHeaderLabels({"Date", "TA", "Start Time", "End Time", "Status"});

        for (int i = 0; i < timings.size(); ++i) {
            const auto& timing = timings[i];
            auto ta = taRepo.getTAById(timing.getTaId());
            
            // Determine if it's a makeup session
            long d = DateUtils::parseDate(timing.getDate());
            std::string actualDay = DateUtils::dayOfWeek(d);
            QString status = (DateUtils::normalizeDay(actualDay) == scheduledDay) ? "Regular" : "Makeup";

            ui->tableLabHistory->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(timing.getDate())));
            ui->tableLabHistory->setItem(i, 1, new QTableWidgetItem(ta ? QString::fromStdString(ta->getName()) : "Unknown"));
            ui->tableLabHistory->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(timing.getStartTime())));
            ui->tableLabHistory->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(timing.getEndTime())));
            ui->tableLabHistory->setItem(i, 4, new QTableWidgetItem(status));
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
    QStringList reasons = {"Instructor unavailable", "Room maintenance", "Holiday"};
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
