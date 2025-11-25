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
    labRepo("labs.bin"),
    instructorRepo("instructors.bin"),
    roomRepo("rooms.bin"),
    buildingRepo("buildings.bin"),
    taRepo("tas.bin"),
    actualTimingRepo("actual_timings.bin"),
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
    connect(ui->calendarWeekSchedule, &QCalendarWidget::selectionChanged, this, &HODMainWindow::on_calendarWeekSchedule_selectionChanged);
    connect(ui->calendarWeekTimesheets, &QCalendarWidget::selectionChanged, this, &HODMainWindow::on_calendarWeekTimesheets_selectionChanged);
    connect(ui->btnExportSchedule, &QPushButton::clicked, this, &HODMainWindow::on_btnExportSchedule_clicked);
    connect(ui->btnExportTimesheets, &QPushButton::clicked, this, &HODMainWindow::on_btnExportTimesheets_clicked);
    connect(ui->btnExportHistory, &QPushButton::clicked, this, &HODMainWindow::on_btnExportHistory_clicked);
    connect(ui->btnExportRequests, &QPushButton::clicked, this, &HODMainWindow::on_btnExportRequests_clicked);

    // Load initial data
    loadDashboard();
    loadWeeklySchedule();
    loadWeeklyTimesheets();
    // Don't load lab history and makeup requests until user navigates to those pages

    // construct reportService now that repos are initialized
    reportService = std::make_unique<ReportService>(labRepo, instructorRepo, taRepo, roomRepo, buildingRepo, actualTimingRepo);


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
    loadWeeklyTimesheets();
    ui->stackedWidget->setCurrentWidget(ui->weeklyTimesheetsPage);
}

void HODMainWindow::on_btnLabHistory_clicked()
{
    loadLabHistory();
    ui->stackedWidget->setCurrentWidget(ui->labHistoryPage);
}

void HODMainWindow::on_btnMakeupRequests_clicked()
{
    loadMakeupRequests();
    ui->stackedWidget->setCurrentWidget(ui->makeupRequestsPage);
}

void HODMainWindow::on_comboSelectLab_currentIndexChanged(int index)
{
    if (index >= 0) {
        loadLabHistoryDetails();
    }
}

void HODMainWindow::on_calendarWeekSchedule_selectionChanged()
{
    loadWeeklySchedule();
}

void HODMainWindow::on_calendarWeekTimesheets_selectionChanged()
{
    loadWeeklyTimesheets();
}

void HODMainWindow::on_btnExportSchedule_clicked()
{
    exportToExcel("Weekly Lab Schedule", ui->tableWeeklySchedule);
}

void HODMainWindow::on_btnExportTimesheets_clicked()
{
    exportToExcel("Weekly Timesheets", ui->tableWeeklyTimesheets);
}

void HODMainWindow::on_btnExportHistory_clicked()
{
    QString labName = ui->comboSelectLab->currentText();
    QString totalHours = ui->lblTotalContactHoursValue->text();
    QString totalLeaves = ui->lblTotalLeavesValue->text();
    QString totalMakeup = ui->lblTotalMakeupSessionsValue->text();
    
    exportToExcel("Lab History - " + labName, ui->tableLabHistory, 
                  "Total Contact Hours: " + totalHours + "\n" +
                  "Total Leaves: " + totalLeaves + "\n" +
                  "Total Makeup Sessions: " + totalMakeup);
}

void HODMainWindow::on_btnExportRequests_clicked()
{
    exportToExcel("Makeup Lab Requests", ui->tableMakeupRequests);
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
    // Get selected week from calendar
    QDate selectedDate = ui->calendarWeekSchedule->selectedDate();
    int daysToMonday = (selectedDate.dayOfWeek() - 1); // Qt: 1=Monday
    QDate weekStart = selectedDate.addDays(-daysToMonday);
    QDate weekEnd = weekStart.addDays(6);
    
    // Get all timings for this week range
    auto allTimings = actualTimingRepo.getAllActualTimings();
    std::vector<ActualTiming> weekTimings;
    
    for (const auto& timing : allTimings) {
        QDate timingDate = QDate::fromString(QString::fromStdString(timing.getDate()), "yyyy-MM-dd");
        if (timingDate.isValid() && timingDate >= weekStart && timingDate <= weekEnd) {
            weekTimings.push_back(timing);
        }
    }
    
    ui->tableWeeklySchedule->setRowCount(static_cast<int>(weekTimings.size()));
    ui->tableWeeklySchedule->setColumnCount(7);
    ui->tableWeeklySchedule->setHorizontalHeaderLabels({"Date", "Day", "Lab Name", "Instructor", "Room", "Time", "Duration"});
    
    for (size_t i = 0; i < weekTimings.size(); ++i) {
        const auto& timing = weekTimings[i];
        auto labOpt = labRepo.getLabById(timing.getLabId());
        
        QDate timingDate = QDate::fromString(QString::fromStdString(timing.getDate()), "yyyy-MM-dd");
        QString day = timingDate.isValid() ? timingDate.toString("dddd") : "Unknown";
        QString labName = labOpt.has_value() ? QString::fromStdString(labOpt->getName()) : "Unknown";
        
        QString instructorName = "Unknown";
        QString roomName = "Unknown";
        if (labOpt.has_value()) {
            auto instructorOpt = instructorRepo.getInstructorById(labOpt->getInstructorId());
            auto roomOpt = roomRepo.getRoomById(labOpt->getRoomId());
            if (instructorOpt.has_value()) instructorName = QString::fromStdString(instructorOpt->getName());
            if (roomOpt.has_value()) roomName = QString::fromStdString(roomOpt->getName());
        }
        
        QString timeStr = QString::fromStdString(timing.getStartTime()) + " - " + QString::fromStdString(timing.getEndTime());
        
        ui->tableWeeklySchedule->setItem(static_cast<int>(i), 0, new QTableWidgetItem(QString::fromStdString(timing.getDate())));
        ui->tableWeeklySchedule->setItem(static_cast<int>(i), 1, new QTableWidgetItem(day));
        ui->tableWeeklySchedule->setItem(static_cast<int>(i), 2, new QTableWidgetItem(labName));
        ui->tableWeeklySchedule->setItem(static_cast<int>(i), 3, new QTableWidgetItem(instructorName));
        ui->tableWeeklySchedule->setItem(static_cast<int>(i), 4, new QTableWidgetItem(roomName));
        ui->tableWeeklySchedule->setItem(static_cast<int>(i), 5, new QTableWidgetItem(timeStr));
        ui->tableWeeklySchedule->setItem(static_cast<int>(i), 6, new QTableWidgetItem(QString::number(timing.getDuration(), 'f', 2)));
    }
}

void HODMainWindow::loadWeeklyTimesheets()
{
    // Get selected week from calendar
    QDate selectedDate = ui->calendarWeekTimesheets->selectedDate();
    int daysToMonday = (selectedDate.dayOfWeek() - 1); // Qt uses 1=Monday
    QDate monday = selectedDate.addDays(-daysToMonday);
    QDate sunday = monday.addDays(6);
    
    // Get all timings for this week
    auto allTimings = actualTimingRepo.getAllActualTimings();
    
    // Filter timings within this week
    std::vector<ActualTiming> weekTimings;
    for (const auto& timing : allTimings) {
        QDate timingDate = QDate::fromString(QString::fromStdString(timing.getDate()), "yyyy-MM-dd");
        if (timingDate.isValid() && timingDate >= monday && timingDate <= sunday) {
            weekTimings.push_back(timing);
        }
    }
    
    ui->tableWeeklyTimesheets->setRowCount(weekTimings.size());
    ui->tableWeeklyTimesheets->setColumnCount(6);
    ui->tableWeeklyTimesheets->setHorizontalHeaderLabels({"Date", "Lab", "Instructor", "Start Time", "End Time", "Duration (hrs)"});

    for (int i = 0; i < weekTimings.size(); ++i) {
        const auto& timing = weekTimings[i];
        auto labOpt = labRepo.getLabById(timing.getLabId());
        QString instructorName = "Unknown";
        if (labOpt.has_value()) {
            auto instructorOpt = instructorRepo.getInstructorById(labOpt->getInstructorId());
            if (instructorOpt.has_value()) {
                instructorName = QString::fromStdString(instructorOpt->getName());
            }
        }

        ui->tableWeeklyTimesheets->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(timing.getDate())));
        ui->tableWeeklyTimesheets->setItem(i, 1, new QTableWidgetItem(labOpt.has_value() ? QString::fromStdString(labOpt->getName()) : "Unknown"));
        ui->tableWeeklyTimesheets->setItem(i, 2, new QTableWidgetItem(instructorName));
        ui->tableWeeklyTimesheets->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(timing.getStartTime())));
        ui->tableWeeklyTimesheets->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(timing.getEndTime())));
        ui->tableWeeklyTimesheets->setItem(i, 5, new QTableWidgetItem(QString::number(timing.getDuration(), 'f', 2)));
    }
}

void HODMainWindow::loadLabHistory()
{
    try {
        // Block signals to prevent recursive calls during combo box population
        ui->comboSelectLab->blockSignals(true);
        ui->comboSelectLab->clear();
        
        auto allLabs = labRepo.getAllLabs();
        
        if (allLabs.empty()) {
            ui->comboSelectLab->blockSignals(false);
            ui->lblTotalContactHoursValue->setText("0.00");
            ui->lblTotalLeavesValue->setText("0");
            ui->lblTotalMakeupSessionsValue->setText("0");
            ui->tableLabHistory->setRowCount(0);
            return;
        }
        
        for (const auto& lab : allLabs) {
            ui->comboSelectLab->addItem(QString::fromStdString(lab.getName()), QVariant(lab.getId()));
        }
        
        // Re-enable signals after populating
        ui->comboSelectLab->blockSignals(false);
        
        // Load details for first lab
        loadLabHistoryDetails();
    } catch (...) {
        QMessageBox::critical(this, "Error", "Failed to load lab list.");
    }
}

void HODMainWindow::loadLabHistoryDetails()
{
    try {
        int selectedLabId = ui->comboSelectLab->currentData().toInt();
        if (selectedLabId == 0) {
            ui->lblTotalContactHoursValue->setText("0.00");
            ui->lblTotalLeavesValue->setText("0");
            ui->lblTotalMakeupSessionsValue->setText("0");
            ui->tableLabHistory->setRowCount(0);
            return;
        }
        
        // Get all timings for this lab
        auto timings = actualTimingRepo.getActualTimingsByLabId(selectedLabId);

        // Robust calculations:
        // - totalHours: sum of durations for recorded sessions (exclude leaves)
        // - explicitLeaves: timings explicitly recorded as 00:00 - 00:00
        // - recordedSessions: timings with valid non-leave times
        // - expectedSessions: default semester sessions (fallback to 15)
        // - implicitLeaves: expectedSessions - (recordedSessions + explicitLeaves) if positive
        // - totalLeaves = explicitLeaves + implicitLeaves
        double totalHours = 0.0;
        int explicitLeaves = 0;
        int recordedSessions = 0;

        for (const auto &timing : timings) {
            const std::string &s = timing.getStartTime();
            const std::string &e = timing.getEndTime();
            bool isLeaveEntry = (s == "00:00" && e == "00:00");
            if (isLeaveEntry) {
                explicitLeaves++;
                continue;
            }
            // only count durations for real sessions
            double dur = timing.getDuration();
            if (dur > 0.0) {
                totalHours += dur;
            }
            // if date/time parseable, consider it a recorded session
            QDate d = QDate::fromString(QString::fromStdString(timing.getDate()), "yyyy-MM-dd");
            if (d.isValid()) recordedSessions++;
        }

        ui->lblTotalContactHoursValue->setText(QString::number(totalHours, 'f', 2));

        // Determine expected sessions for semester.
        // If lab has a schedule we assume weekly sessions across a 15-week semester by default.
        int expectedSessions = 15;
        auto labOpt = labRepo.getLabById(selectedLabId);
        if (labOpt.has_value()) {
            // TODO: if semester dates are available, compute expectedSessions based on date range
        }

        int implicitLeaves = 0;
        int totalRecorded = recordedSessions + explicitLeaves;
        if (expectedSessions > totalRecorded) implicitLeaves = expectedSessions - totalRecorded;
        int totalLeaves = explicitLeaves + implicitLeaves;

        ui->lblTotalLeavesValue->setText(QString::number(totalLeaves));

        // Count makeup sessions: recorded sessions that occur on a day different from scheduled day
        int makeupCount = 0;
        if (labOpt.has_value()) {
            std::string scheduledDay = labOpt->getSchedule().getDay();
            for (const auto &timing : timings) {
                QDate timingDate = QDate::fromString(QString::fromStdString(timing.getDate()), "yyyy-MM-dd");
                if (!timingDate.isValid()) continue;
                QString actualDay = timingDate.toString("dddd");
                if (actualDay.toStdString() != scheduledDay) {
                    // ignore explicit leaves
                    if (!(timing.getStartTime() == "00:00" && timing.getEndTime() == "00:00")) {
                        makeupCount++;
                    }
                }
            }
        }

        ui->lblTotalMakeupSessionsValue->setText(QString::number(makeupCount));

        ui->tableLabHistory->setRowCount(static_cast<int>(timings.size()));
        ui->tableLabHistory->setColumnCount(5);
        ui->tableLabHistory->setHorizontalHeaderLabels({"Date", "Day", "Start Time", "End Time", "Duration (hrs)"});

        for (size_t i = 0; i < timings.size(); ++i) {
            const auto &timing = timings[i];
            QDate timingDate = QDate::fromString(QString::fromStdString(timing.getDate()), "yyyy-MM-dd");
            QString day = timingDate.isValid() ? timingDate.toString("dddd") : "Unknown";

            ui->tableLabHistory->setItem(static_cast<int>(i), 0, new QTableWidgetItem(QString::fromStdString(timing.getDate())));
            ui->tableLabHistory->setItem(static_cast<int>(i), 1, new QTableWidgetItem(day));
            ui->tableLabHistory->setItem(static_cast<int>(i), 2, new QTableWidgetItem(QString::fromStdString(timing.getStartTime())));
            ui->tableLabHistory->setItem(static_cast<int>(i), 3, new QTableWidgetItem(QString::fromStdString(timing.getEndTime())));
            ui->tableLabHistory->setItem(static_cast<int>(i), 4, new QTableWidgetItem(QString::number(timing.getDuration(), 'f', 2)));
        }
    } catch (...) {
        QMessageBox::critical(this, "Error", "Failed to load lab history. Please check the data files.");
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

void HODMainWindow::exportToExcel(const QString& title, QTableWidget* table, const QString& summary)
{
    QString fileName = QFileDialog::getSaveFileName(this, "Export to Excel", title + ".csv", "CSV Files (*.csv);;All Files (*)");
    if (fileName.isEmpty()) return;

    if (ExportService::exportToCSV(fileName, title, table, summary)) {
        QMessageBox::information(this, "Export Successful", 
            QString("Report exported successfully to:\n%1\n\nYou can open this file with Microsoft Excel.").arg(fileName));
    } else {
        QMessageBox::warning(this, "Export Failed", "Could not export the report.");
    }
}
