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

        QString timeStr = QString::fromStdString(lab.getSchedule().getStart()) + " - " + QString::fromStdString(lab.getSchedule().getEnd());

        ui->tableWeeklySchedule->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(lab.getName())));
        ui->tableWeeklySchedule->setItem(i, 1, new QTableWidgetItem(instructor ? QString::fromStdString(instructor->getName()) : "Unknown"));
        ui->tableWeeklySchedule->setItem(i, 2, new QTableWidgetItem(room ? QString::fromStdString(room->getName()) : "Unknown"));
        ui->tableWeeklySchedule->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(lab.getSchedule().getDay())));
        ui->tableWeeklySchedule->setItem(i, 4, new QTableWidgetItem(timeStr));
        ui->tableWeeklySchedule->setItem(i, 5, new QTableWidgetItem(QString::fromStdString(lab.getStatus())));
    }

    // Populate week combo
    ui->comboWeek->clear();
    ui->comboWeek->addItem("Current Week");
    ui->comboWeek->addItem("Next Week");
}

void HODMainWindow::loadWeeklyTimesheets()
{
    // Get current week's date range
    QDate today = QDate::currentDate();
    int daysToMonday = (today.dayOfWeek() - 1); // Qt uses 1=Monday
    QDate monday = today.addDays(-daysToMonday);
    QDate sunday = monday.addDays(6);
    
    // Get all timings for this week
    auto allTimings = actualTimingRepo.getAllActualTimings();
    
    // Filter timings within this week
    std::vector<ActualTiming> weekTimings;
    for (const auto& timing : allTimings) {
        QDate timingDate = QDate::fromString(QString::fromStdString(timing.getDate()), "yyyy-MM-dd");
        if (timingDate >= monday && timingDate <= sunday) {
            weekTimings.push_back(timing);
        }
    }
    
    ui->tableWeeklyTimesheets->setRowCount(weekTimings.size());
    ui->tableWeeklyTimesheets->setColumnCount(6);
    ui->tableWeeklyTimesheets->setHorizontalHeaderLabels({"Date", "Lab", "Instructor", "Start Time", "End Time", "Duration (hrs)"});

    for (int i = 0; i < weekTimings.size(); ++i) {
        const auto& timing = weekTimings[i];
        auto lab = labRepo.getLabById(timing.getLabId());
        QString instructorName = "Unknown";
        if (lab) {
            auto instructor = instructorRepo.getInstructorById(lab->getInstructorId());
            if (instructor) {
                instructorName = QString::fromStdString(instructor->getName());
            }
        }

        ui->tableWeeklyTimesheets->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(timing.getDate())));
        ui->tableWeeklyTimesheets->setItem(i, 1, new QTableWidgetItem(lab ? QString::fromStdString(lab->getName()) : "Unknown"));
        ui->tableWeeklyTimesheets->setItem(i, 2, new QTableWidgetItem(instructorName));
        ui->tableWeeklyTimesheets->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(timing.getStartTime())));
        ui->tableWeeklyTimesheets->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(timing.getEndTime())));
        ui->tableWeeklyTimesheets->setItem(i, 5, new QTableWidgetItem(QString::number(timing.getDuration(), 'f', 2)));
    }

    // Populate week combo
    ui->comboTimesheetWeek->clear();
    ui->comboTimesheetWeek->addItem(QString("Week of %1").arg(monday.toString("MMM dd")));
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

        int selectedLabId = ui->comboSelectLab->currentData().toInt();
        if (selectedLabId == 0) {
            selectedLabId = allLabs[0].getId();
        }
        
        // Get all timings for this lab
        auto timings = actualTimingRepo.getActualTimingsByLabId(selectedLabId);
        
        // Calculate total contact hours
        double totalHours = 0.0;
        for (const auto& timing : timings) {
            totalHours += timing.getDuration();
        }
        ui->lblTotalContactHoursValue->setText(QString::number(totalHours, 'f', 2));
        
        // Calculate leaves (sessions marked as 00:00 - 00:00)
        int leaves = 0;
        for (const auto& timing : timings) {
            if (timing.getStartTime() == "00:00" && timing.getEndTime() == "00:00") {
                leaves++;
            }
        }
        ui->lblTotalLeavesValue->setText(QString::number(leaves));
        
        // Count makeup sessions (sessions not on scheduled day)
        int makeupCount = 0;
        auto lab = labRepo.getLabById(selectedLabId);
        if (lab) {
            std::string scheduledDay = lab->getSchedule().getDay();
            for (const auto& timing : timings) {
                QDate timingDate = QDate::fromString(QString::fromStdString(timing.getDate()), "yyyy-MM-dd");
                if (timingDate.isValid()) {
                    QString actualDay = timingDate.toString("dddd");
                    if (actualDay.toStdString() != scheduledDay) {
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
            const auto& timing = timings[i];
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
