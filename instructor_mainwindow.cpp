#include "instructor_mainwindow.h"
#include "ui_instructor_mainwindow.h"
#include <QMenuBar>
#include <QTableWidgetItem>
#include <QListWidgetItem>
#include <QFileDialog>
#include <QPdfWriter>
#include <QPainter>
#include <QMessageBox>
#include <QInputDialog>
#include <QDateTime>
#include <QDate>
#include <QTime>
#include "backend/repositories/UserRepository.h"

InstructorMainWindow::InstructorMainWindow(int instructorId, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InstructorMainWindow),
    instructorId(instructorId),
    labRepo("test_labs.bin"),
    instructorRepo("test_instructors.bin"),
    roomRepo("test_rooms.bin"),
    buildingRepo("test_buildings.bin"),
    taRepo("test_tas.bin"),
    actualTimingRepo("test_timings.bin"),
    reportService(labRepo, instructorRepo, taRepo, roomRepo, buildingRepo, actualTimingRepo),
    makeupRequestRepo("makeup_requests.bin"),
    makeupService(nullptr)
{
    ui->setupUi(this);
    
    // Initialize makeup service
    makeupService = new MakeupService(makeupRequestRepo, labRepo);
    
    // Load current user
    UserRepository userRepo("users.txt");
    auto users = userRepo.loadAll();
    for (const auto& u : users) {
        if (u.getId() == instructorId) {
            currentUser = u;
            break;
        }
    }

    // Connect sidebar buttons to switch pages
    connect(ui->btnDashboard, &QPushButton::clicked, this, &InstructorMainWindow::on_btnDashboard_clicked);
    connect(ui->btnMyLabs, &QPushButton::clicked, this, &InstructorMainWindow::on_btnMyLabs_clicked);
    connect(ui->btnLabDetails, &QPushButton::clicked, this, &InstructorMainWindow::on_btnLabDetails_clicked);
    connect(ui->btnTimesheet, &QPushButton::clicked, this, &InstructorMainWindow::on_btnTimesheet_clicked);
    connect(ui->btnNotifications, &QPushButton::clicked, this, &InstructorMainWindow::on_btnNotifications_clicked);
    connect(ui->btnProfile, &QPushButton::clicked, this, &InstructorMainWindow::on_btnProfile_clicked);

    // Connect combo boxes
    connect(ui->comboSelectLab, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &InstructorMainWindow::on_comboSelectLab_currentIndexChanged);
    connect(ui->comboSelectLabTimesheet, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &InstructorMainWindow::on_comboSelectLabTimesheet_currentIndexChanged);

    // Connect update profile button
    connect(ui->btnUpdateProfile, &QPushButton::clicked, this, &InstructorMainWindow::on_btnUpdateProfile_clicked);
    
    // Connect makeup request button if it exists
    if (ui->btnRequestMakeup) {
        connect(ui->btnRequestMakeup, &QPushButton::clicked, this, &InstructorMainWindow::on_btnRequestMakeup_clicked);
    }

    // Load initial data
    loadDashboard();
    loadMyLabs();
    loadLabDetails();
    loadTimesheet();
    loadNotifications();
    loadProfile();

    // Set default page to Dashboard
    ui->stackedWidget->setCurrentWidget(ui->dashboardPage);
    
        QAction *logout = new QAction("Logout", this);
        connect(logout, &QAction::triggered, this, [this]() {
            if (this->parentWidget()) this->parentWidget()->show();
            this->close();
        });
        menuBar()->addAction(logout);
}

InstructorMainWindow::~InstructorMainWindow()
{
    delete makeupService;
    delete ui;
}

void InstructorMainWindow::on_btnDashboard_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->dashboardPage);
}

void InstructorMainWindow::on_btnMyLabs_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->myLabsPage);
}

void InstructorMainWindow::on_btnLabDetails_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->labDetailsPage);
}

void InstructorMainWindow::on_btnTimesheet_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->timesheetPage);
}

void InstructorMainWindow::on_btnNotifications_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->notificationsPage);
}

void InstructorMainWindow::on_btnProfile_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->profilePage);
}

void InstructorMainWindow::on_comboSelectLab_currentIndexChanged(int index)
{
    if (index < 0) return;

    // Get selected lab ID from combo box
    int labId = ui->comboSelectLab->itemData(index).toInt();
    auto lab = labRepo.getLabById(labId);
    if (!lab) return;

    auto room = roomRepo.getRoomById(lab->getRoomId());

    ui->lblLabNameValue->setText(QString::fromStdString(lab->getName()));
    ui->lblTimingsValue->setText(QString::fromStdString(lab->getSchedule()));
    ui->lblVenueValue->setText(room ? QString::fromStdString(room->getName()) : "Unknown");

    // Load assigned TAs
    QString taNames;
    // Assuming there's a way to get TAs for a lab, for now placeholder
    taNames = "TA1, TA2"; // Placeholder
    ui->lblAssignedTAsValue->setText(taNames);
}

void InstructorMainWindow::on_comboSelectLabTimesheet_currentIndexChanged(int index)
{
    if (index < 0) return;

    // Get selected lab ID from combo box
    int labId = ui->comboSelectLabTimesheet->itemData(index).toInt();

    // Load timesheet data for the lab
    auto timings = actualTimingRepo.getTimingsByLabId(labId);
    ui->tableTimesheet->setRowCount(timings.size());
    ui->tableTimesheet->setColumnCount(4);
    ui->tableTimesheet->setHorizontalHeaderLabels({"Date", "Start Time", "End Time", "Duration"});

    for (int i = 0; i < timings.size(); ++i) {
        const auto& timing = timings[i];
        ui->tableTimesheet->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(timing.getDate())));
        ui->tableTimesheet->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(timing.getStartTime())));
        ui->tableTimesheet->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(timing.getEndTime())));
        ui->tableTimesheet->setItem(i, 3, new QTableWidgetItem(QString::number(timing.getDuration())));
    }
}

void InstructorMainWindow::on_btnUpdateProfile_clicked()
{
    auto instructor = instructorRepo.getInstructorById(instructorId);
    if (!instructor) return;

    instructor->setName(ui->lineEditName->text().toStdString());
    instructor->setEmail(ui->lineEditEmail->text().toStdString());
    // Assuming phone is stored in email or another field, adjust as needed
    instructorRepo.update(*instructor);

    QMessageBox::information(this, "Profile Updated", "Your profile has been updated successfully.");
}

void InstructorMainWindow::loadDashboard()
{
    auto allLabs = labRepo.getLabsByInstructorId(instructorId);
    ui->lblAssignedLabsCount->setText(QString::number(allLabs.size()));

    // Calculate upcoming sessions (placeholder logic)
    int upcoming = 0;
    for (const auto& lab : allLabs) {
        // Check if lab is scheduled in the future
        upcoming++; // Placeholder
    }
    ui->lblUpcomingSessionsCount->setText(QString::number(upcoming));

    // Pending notifications (placeholder)
    ui->lblPendingNotificationsCount->setText("3");
}

void InstructorMainWindow::loadMyLabs()
{
    auto myLabs = labRepo.getLabsByInstructorId(instructorId);
    ui->tableMyLabs->setRowCount(myLabs.size());
    ui->tableMyLabs->setColumnCount(4);
    ui->tableMyLabs->setHorizontalHeaderLabels({"Lab Name", "Schedule", "Room", "Status"});

    for (int i = 0; i < myLabs.size(); ++i) {
        const auto& lab = myLabs[i];
        auto room = roomRepo.getRoomById(lab.getRoomId());

        ui->tableMyLabs->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(lab.getName())));
        ui->tableMyLabs->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(lab.getSchedule())));
        ui->tableMyLabs->setItem(i, 2, new QTableWidgetItem(room ? QString::fromStdString(room->getName()) : "Unknown"));
        ui->tableMyLabs->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(lab.getStatus())));
    }
}

void InstructorMainWindow::loadLabDetails()
{
    auto myLabs = labRepo.getLabsByInstructorId(instructorId);
    ui->comboSelectLab->clear();
    for (const auto& lab : myLabs) {
        ui->comboSelectLab->addItem(QString::fromStdString(lab.getName()), lab.getId());
    }
    if (!myLabs.empty()) {
        on_comboSelectLab_currentIndexChanged(0);
    }
}

void InstructorMainWindow::loadTimesheet()
{
    auto myLabs = labRepo.getLabsByInstructorId(instructorId);
    ui->comboSelectLabTimesheet->clear();
    for (const auto& lab : myLabs) {
        ui->comboSelectLabTimesheet->addItem(QString::fromStdString(lab.getName()), lab.getId());
    }
    if (!myLabs.empty()) {
        on_comboSelectLabTimesheet_currentIndexChanged(0);
    }
}

void InstructorMainWindow::loadNotifications()
{
    ui->listNotifications->clear();
    
    // Load makeup requests for this instructor
    auto requests = makeupRequestRepo.load();
    for (const auto& req : requests) {
        if (req.getRequestedBy() == instructorId) {
            auto lab = labRepo.getLabById(req.getLabId());
            QString status = QString::fromStdString(req.getStatus());
            QString labName = lab ? QString::fromStdString(lab->getName()) : "Unknown";
            ui->listNotifications->addItem(QString("Makeup Request: %1 - Date: %2 - Status: %3")
                .arg(labName)
                .arg(QString::fromStdString(req.getDate()))
                .arg(status));
        }
    }
    
    if (ui->listNotifications->count() == 0) {
        ui->listNotifications->addItem("No notifications");
    }
}

void InstructorMainWindow::loadProfile()
{
    auto instructor = instructorRepo.getInstructorById(instructorId);
    if (instructor) {
        ui->lineEditName->setText(QString::fromStdString(instructor->getName()));
        ui->lineEditEmail->setText(QString::fromStdString(instructor->getEmail()));
        // Assuming phone is not stored, set empty
        ui->lineEditPhone->setText("");
    }
}

void InstructorMainWindow::on_btnRequestMakeup_clicked()
{
    auto myLabs = labRepo.getLabsByInstructorId(instructorId);
    if (myLabs.empty()) {
        QMessageBox::warning(this, "No Labs", "You don't have any assigned labs.");
        return;
    }
    
    // Get lab selection
    QStringList labNames;
    QMap<QString, int> labMap;
    for (const auto& lab : myLabs) {
        QString name = QString::fromStdString(lab.getName());
        labNames << name;
        labMap[name] = lab.getId();
    }
    
    bool ok;
    QString selectedLab = QInputDialog::getItem(this, "Request Makeup Lab", "Select Lab:", labNames, 0, false, &ok);
    if (!ok || selectedLab.isEmpty()) return;
    
    int labId = labMap[selectedLab];
    auto lab = labRepo.getLabById(labId);
    if (!lab) return;
    
    // Get date
    QDate date = QDate::fromString(QInputDialog::getText(this, "Request Makeup", "Enter date (YYYY-MM-DD):", QLineEdit::Normal, QDate::currentDate().toString("yyyy-MM-dd"), &ok), "yyyy-MM-dd");
    if (!ok || !date.isValid()) return;
    
    // Get time
    QString startTime = QInputDialog::getText(this, "Request Makeup", "Enter start time (HH:MM):", QLineEdit::Normal, lab->getSchedule().getStart().c_str(), &ok);
    if (!ok || startTime.isEmpty()) return;
    
    QString endTime = QInputDialog::getText(this, "Request Makeup", "Enter end time (HH:MM):", QLineEdit::Normal, lab->getSchedule().getEnd().c_str(), &ok);
    if (!ok || endTime.isEmpty()) return;
    
    // Request makeup
    int requestId = makeupService->requestMakeup(currentUser, labId, date.toString("yyyy-MM-dd").toStdString(), startTime.toStdString(), endTime.toStdString());
    if (requestId > 0) {
        QMessageBox::information(this, "Success", "Makeup request submitted successfully. Request ID: " + QString::number(requestId));
        loadNotifications();
    } else {
        QMessageBox::critical(this, "Error", "Failed to submit makeup request.");
    }
}

void InstructorMainWindow::exportToPDF(const QString& title, QTableWidget* table)
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
