#include "ao_mainwindow.h"
#include "ui_ao_mainwindow.h"
#include "ao_create_user_dialog.h"
#include <QTableWidgetItem>
#include <QListWidgetItem>
#include <QFileDialog>
#include <QPdfWriter>
#include <QPainter>
#include <QMessageBox>
#include <QInputDialog>
#include <QDateTime>
#include <QMenuBar>
#include "ao_add_lab_dialog.h"

// Constructor: initialize repositories and view
AOMainWindow::AOMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AOMainWindow)
    , labRepo("labs.bin")
    , instructorRepo("instructors.bin")
    , taRepo("tas.bin")
    , hodRepo("hods.bin")
    , roomRepo("rooms.bin")
    , buildingRepo("buildings.bin")
    , actualTimingRepo("actual_timings.bin")
    , makeupRequestRepo("makeup_requests.bin")
    , userRepo("users.txt")
    , aoRepo("academic_officers.bin")
    , authService(userRepo, &instructorRepo, &taRepo, &hodRepo, &aoRepo, &buildingRepo)
    , reportService(labRepo, instructorRepo, taRepo, roomRepo, buildingRepo, actualTimingRepo)
{
    ui->setupUi(this);

    // Connect sidebar buttons
    connect(ui->btnDashboard, &QPushButton::clicked, this, &AOMainWindow::on_btnDashboard_clicked);
    connect(ui->btnManageLabs, &QPushButton::clicked, this, &AOMainWindow::on_btnManageLabs_clicked);
    connect(ui->btnManageInstructors, &QPushButton::clicked, this, &AOMainWindow::on_btnManageInstructors_clicked);
    connect(ui->btnManageTAs, &QPushButton::clicked, this, &AOMainWindow::on_btnManageTAs_clicked);
    connect(ui->btnMakeupRequests, &QPushButton::clicked, this, &AOMainWindow::on_btnMakeupRequests_clicked);

    // Manage actions
    connect(ui->btnAddLab, &QPushButton::clicked, this, &AOMainWindow::on_btnAddLab_clicked);
    connect(ui->btnAddInstructor, &QPushButton::clicked, this, &AOMainWindow::on_btnAddInstructor_clicked);
    connect(ui->btnAddTA, &QPushButton::clicked, this, &AOMainWindow::on_btnAddTA_clicked);
    connect(ui->btnAcceptMakeup, &QPushButton::clicked, this, &AOMainWindow::on_btnAcceptMakeup_clicked);
    connect(ui->btnRejectMakeup, &QPushButton::clicked, this, &AOMainWindow::on_btnRejectMakeup_clicked);
    // ... connect other actions as needed

    loadDashboard();
    loadManageLabs();
    loadManageInstructors();
    loadManageTAs();

    // add logout action
    QAction *logout = new QAction("Logout", this);
    connect(logout, &QAction::triggered, this, [this]() {
        if (this->parentWidget()) this->parentWidget()->show();
        this->close();
    });
    menuBar()->addAction(logout);
}

AOMainWindow::AOMainWindow(int aoId, QWidget *parent)
    : AOMainWindow(parent)
{
    this->aoId = aoId;
}

// Dashboard
void AOMainWindow::on_btnDashboard_clicked() {
    ui->stackedWidget->setCurrentWidget(ui->dashboardPage);
    loadDashboard();
}
void AOMainWindow::loadDashboard() {
    auto allLabs = labRepo.getAllLabs();
    ui->lblTotalLabsCount->setText(QString::number(allLabs.size()));

    auto allInstructors = instructorRepo.getAll();
    ui->lblTotalInstructorsCount->setText(QString::number(allInstructors.size()));

    auto allTAs = taRepo.getAll();
    ui->lblTotalTAsCount->setText(QString::number(allTAs.size()));
}

// Labs management
void AOMainWindow::on_btnManageLabs_clicked() {
    ui->stackedWidget->setCurrentWidget(ui->manageLabsPage);
    loadManageLabs();
}
void AOMainWindow::on_btnAddLab_clicked() {
    // Use a dedicated dialog to collect complete lab and schedule data
    AOAddLabDialog dlg(instructorRepo, roomRepo, this);
    if (dlg.exec() != QDialog::Accepted) return;

    QString course = dlg.courseCode();
    QString section = dlg.section();
    int instructorId = dlg.selectedInstructorId();
    int roomId = dlg.selectedRoomId();
    QString day = dlg.dayOfWeek();
    QString start = dlg.startTime().toString("HH:mm");
    QString end = dlg.endTime().toString("HH:mm");
    QDate semStart = dlg.semesterStart();
    QDate semEnd = dlg.semesterEnd();
    
    // Check for clashes before creating lab
    QTime startTime = dlg.startTime();
    QTime endTime = dlg.endTime();
    
    // Get all existing timings
    auto allTimings = actualTimingRepo.getAllActualTimings();
    
    // Find first occurrence of the day of week in semester range
    QDate currentDate = semStart;
    int targetDayOfWeek = 1; // Monday=1, Sunday=7
    QStringList days = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    for (int i = 0; i < days.size(); ++i) {
        if (days[i] == day) {
            targetDayOfWeek = i + 1;
            break;
        }
    }
    
    // Move to first occurrence of target day
    while (currentDate.dayOfWeek() != targetDayOfWeek && currentDate <= semEnd) {
        currentDate = currentDate.addDays(1);
    }
    
    // Check for clashes on each proposed session date
    QDate checkDate = currentDate;
    while (checkDate <= semEnd) {
        QString dateStr = checkDate.toString("yyyy-MM-dd");
        
        // Check for instructor clash
        for (const auto& timing : allTimings) {
            if (timing.getDate() == dateStr.toStdString() && timing.getTaId() == instructorId) {
                QTime existingStart = QTime::fromString(QString::fromStdString(timing.getStartTime()), "HH:mm");
                QTime existingEnd = QTime::fromString(QString::fromStdString(timing.getEndTime()), "HH:mm");
                
                // Check if times overlap
                if ((startTime < existingEnd && endTime > existingStart)) {
                    QMessageBox::warning(this, "Instructor Clash", 
                        QString("Instructor has another session on %1 from %2 to %3")
                        .arg(dateStr)
                        .arg(existingStart.toString("HH:mm"))
                        .arg(existingEnd.toString("HH:mm")));
                    return;
                }
            }
        }
        
        // Check for room clash
        if (roomId > 0) {
            auto allLabs = labRepo.getAllLabs();
            for (const auto& timing : allTimings) {
                // Find lab for this timing
                auto labOpt = labRepo.getLabById(timing.getLabId());
                if (labOpt.has_value() && labOpt->getRoomId() == roomId && timing.getDate() == dateStr.toStdString()) {
                    QTime existingStart = QTime::fromString(QString::fromStdString(timing.getStartTime()), "HH:mm");
                    QTime existingEnd = QTime::fromString(QString::fromStdString(timing.getEndTime()), "HH:mm");
                    
                    // Check if times overlap
                    if ((startTime < existingEnd && endTime > existingStart)) {
                        QMessageBox::warning(this, "Room Clash", 
                            QString("Room is already booked on %1 from %2 to %3")
                            .arg(dateStr)
                            .arg(existingStart.toString("HH:mm"))
                            .arg(existingEnd.toString("HH:mm")));
                        return;
                    }
                }
            }
        }
        
        checkDate = checkDate.addDays(7); // Next week
    }

    // No clashes found, proceed with creating lab
    int id = labRepo.getNextId();
    Lab lab(id, course.toStdString(), section.toStdString());
    lab.setInstructorId(instructorId);
    lab.setRoomId(roomId);
    ScheduleTiming sch(day.toStdString(), start.toStdString(), end.toStdString(), 
                      semStart.toString("yyyy-MM-dd").toStdString(), 
                      semEnd.toString("yyyy-MM-dd").toStdString());
    lab.setSchedule(sch);
    labRepo.add(lab);
    
    // Calculate duration
    double duration = startTime.secsTo(endTime) / 3600.0;
    
    // Create weekly sessions
    currentDate = semStart;
    while (currentDate.dayOfWeek() != targetDayOfWeek && currentDate <= semEnd) {
        currentDate = currentDate.addDays(1);
    }
    
    while (currentDate <= semEnd) {
        ActualTiming timing(id, instructorId, currentDate.toString("yyyy-MM-dd").toStdString(), 
                          start.toStdString(), end.toStdString(), duration, "Scheduled");
        actualTimingRepo.add(timing);
        currentDate = currentDate.addDays(7); // Next week
    }
    
    QMessageBox::information(this, "Lab Created", 
        QString("Lab created with %1 weekly sessions (clash-free)").arg((semStart.daysTo(semEnd) / 7) + 1));
    loadManageLabs();
}
void AOMainWindow::loadManageLabs() {
    auto allLabs = labRepo.getAllLabs();
    ui->tableLabs->setRowCount(allLabs.size());
    ui->tableLabs->setColumnCount(8);
    ui->tableLabs->setHorizontalHeaderLabels({"ID", "Course", "Day", "Time", "Room", "Building", "Instructor", "Semester Dates"});
    
    for (int i = 0; i < allLabs.size(); ++i) {
        const auto& lab = allLabs[i];
        auto instructorOpt = instructorRepo.getInstructorById(lab.getInstructorId());
        auto roomOpt = roomRepo.getRoomById(lab.getRoomId());
        
        QString buildingName = "N/A";
        if (roomOpt.has_value()) {
            auto building = buildingRepo.getBuildingById(roomOpt->getBuildingId());
            if (building) {
                buildingName = QString::fromStdString(building->getName());
            }
        }
        
        auto schedule = lab.getSchedule();
        QString timeRange = QString::fromStdString(schedule.getStart()) + " - " + 
                           QString::fromStdString(schedule.getEnd());
        QString semesterDates = QString::fromStdString(schedule.getSemesterStart()) + " to " + 
                               QString::fromStdString(schedule.getSemesterEnd());
        
        ui->tableLabs->setItem(i, 0, new QTableWidgetItem(QString::number(lab.getId())));
        ui->tableLabs->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(lab.getName())));
        ui->tableLabs->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(schedule.getDay())));
        ui->tableLabs->setItem(i, 3, new QTableWidgetItem(timeRange));
        ui->tableLabs->setItem(i, 4, new QTableWidgetItem(roomOpt.has_value() ? QString::fromStdString(roomOpt->getName()) : "N/A"));
        ui->tableLabs->setItem(i, 5, new QTableWidgetItem(buildingName));
        ui->tableLabs->setItem(i, 6, new QTableWidgetItem(instructorOpt.has_value() ? QString::fromStdString(instructorOpt->getName()) : "Unknown"));
        ui->tableLabs->setItem(i, 7, new QTableWidgetItem(semesterDates));
    }
    
    ui->tableLabs->resizeColumnsToContents();
}

// Instructors management
void AOMainWindow::on_btnManageInstructors_clicked() {
    ui->stackedWidget->setCurrentWidget(ui->manageInstructorsPage);
    loadManageInstructors();
}
void AOMainWindow::on_btnAddInstructor_clicked() {
    AOCreateUserDialog dlg(&authService, &instructorRepo, &taRepo, &hodRepo, this);
    dlg.comboRole->setCurrentText("Instructor");
    dlg.comboRole->setEnabled(false);
    if (dlg.exec() == QDialog::Accepted) loadManageInstructors();
}
void AOMainWindow::loadManageInstructors() {
    auto allInstructors = instructorRepo.getAll();
    ui->tableInstructors->setRowCount(allInstructors.size());
    ui->tableInstructors->setColumnCount(2); // ID, Name. Add Email column if your model supports it
    ui->tableInstructors->setHorizontalHeaderLabels({"ID", "Name"});
    for (int i = 0; i < allInstructors.size(); ++i) {
        const auto& instructor = allInstructors[i];
        ui->tableInstructors->setItem(i, 0, new QTableWidgetItem(QString::number(instructor.getId())));
        ui->tableInstructors->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(instructor.getName())));
    }
}

// TA management
void AOMainWindow::on_btnManageTAs_clicked() {
    ui->stackedWidget->setCurrentWidget(ui->manageTAsPage);
    loadManageTAs();
}
void AOMainWindow::on_btnAddTA_clicked() {
    AOCreateUserDialog dlg(&authService, &instructorRepo, &taRepo, &hodRepo, this);
    dlg.comboRole->setCurrentText("TA");
    dlg.comboRole->setEnabled(false);
    if (dlg.exec() == QDialog::Accepted) loadManageTAs();
}

void AOMainWindow::on_btnAddHOD_clicked() {
    AOCreateUserDialog dlg(&authService, &instructorRepo, &taRepo, &hodRepo, this);
    dlg.comboRole->setCurrentText("HOD");
    dlg.comboRole->setEnabled(false);
    if (dlg.exec() == QDialog::Accepted) loadManageInstructors();
}
void AOMainWindow::loadManageTAs() {
    auto allTAs = taRepo.getAll();
    ui->tableTAs->setRowCount(allTAs.size());
    ui->tableTAs->setColumnCount(2); // ID, Name
    ui->tableTAs->setHorizontalHeaderLabels({"ID", "Name"});
    for (int i = 0; i < allTAs.size(); ++i) {
        const auto& ta = allTAs[i];
        ui->tableTAs->setItem(i, 0, new QTableWidgetItem(QString::number(ta.getId())));
        ui->tableTAs->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(ta.getName())));
    }
}
void AOMainWindow::on_btnEditLab_clicked() {
    int row = ui->tableLabs->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "No Selection", "Please select a lab to edit.");
        return;
    }
    int labId = ui->tableLabs->item(row, 0)->text().toInt();
    auto labOpt = labRepo.getLabById(labId);
    if (!labOpt.has_value()) {
        QMessageBox::warning(this, "Error", "Lab not found.");
        return;
    }
    Lab lab = labOpt.value();
    
    AOAddLabDialog dlg(instructorRepo, roomRepo, lab, this);
    if (dlg.exec() != QDialog::Accepted) return;
    
    // Update lab with new values
    lab.setCourseCode(dlg.courseCode().toStdString());
    lab.setSection(dlg.section().toStdString());
    lab.setInstructorId(dlg.selectedInstructorId());
    lab.setRoomId(dlg.selectedRoomId());
    ScheduleTiming sch(dlg.dayOfWeek().toStdString(), 
                      dlg.startTime().toString("HH:mm").toStdString(), 
                      dlg.endTime().toString("HH:mm").toStdString(),
                      dlg.semesterStart().toString("yyyy-MM-dd").toStdString(),
                      dlg.semesterEnd().toString("yyyy-MM-dd").toStdString());
    lab.setSchedule(sch);
    
    if (labRepo.update(lab)) {
        QMessageBox::information(this, "Success", "Lab updated successfully.");
        loadManageLabs();
    } else {
        QMessageBox::warning(this, "Error", "Failed to update lab.");
    }
}

void AOMainWindow::on_btnDeleteLab_clicked() {
    int row = ui->tableLabs->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "No Selection", "Please select a lab to delete.");
        return;
    }
    int labId = ui->tableLabs->item(row, 0)->text().toInt();
    
    auto reply = QMessageBox::question(this, "Confirm Delete", 
        "Are you sure you want to delete this lab? This will also remove all associated sessions.",
        QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        if (labRepo.remove(labId)) {
            // Also remove all ActualTiming entries for this lab
            actualTimingRepo.removeByLabId(labId);
            QMessageBox::information(this, "Success", "Lab deleted successfully.");
            loadManageLabs();
        } else {
            QMessageBox::warning(this, "Error", "Failed to delete lab.");
        }
    }
}

void AOMainWindow::on_btnEditInstructor_clicked() {
    int row = ui->tableInstructors->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "No Selection", "Please select an instructor to edit.");
        return;
    }
    int instrId = ui->tableInstructors->item(row, 0)->text().toInt();
    QString newName = QInputDialog::getText(this, "Edit Instructor", "Enter new name:",
                                           QLineEdit::Normal,
                                           ui->tableInstructors->item(row, 1)->text());
    if (!newName.isEmpty()) {
        Instructor instr(instrId, newName.toStdString());
        if (instructorRepo.update(instr)) {
            QMessageBox::information(this, "Success", "Instructor updated successfully.");
            loadManageInstructors();
        } else {
            QMessageBox::warning(this, "Error", "Failed to update instructor.");
        }
    }
}

void AOMainWindow::on_btnDeleteInstructor_clicked() {
    int row = ui->tableInstructors->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "No Selection", "Please select an instructor to delete.");
        return;
    }
    int instrId = ui->tableInstructors->item(row, 0)->text().toInt();
    
    auto reply = QMessageBox::question(this, "Confirm Delete", 
        "Are you sure you want to delete this instructor?",
        QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        if (instructorRepo.remove(instrId)) {
            QMessageBox::information(this, "Success", "Instructor deleted successfully.");
            loadManageInstructors();
        } else {
            QMessageBox::warning(this, "Error", "Failed to delete instructor.");
        }
    }
}

void AOMainWindow::on_btnEditTA_clicked() {
    int row = ui->tableTAs->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "No Selection", "Please select a TA to edit.");
        return;
    }
    int taId = ui->tableTAs->item(row, 0)->text().toInt();
    QString newName = QInputDialog::getText(this, "Edit TA", "Enter new name:",
                                           QLineEdit::Normal,
                                           ui->tableTAs->item(row, 1)->text());
    if (!newName.isEmpty()) {
        TA ta(taId, newName.toStdString());
        if (taRepo.update(ta)) {
            QMessageBox::information(this, "Success", "TA updated successfully.");
            loadManageTAs();
        } else {
            QMessageBox::warning(this, "Error", "Failed to update TA.");
        }
    }
}

void AOMainWindow::on_btnDeleteTA_clicked() {
    int row = ui->tableTAs->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "No Selection", "Please select a TA to delete.");
        return;
    }
    int taId = ui->tableTAs->item(row, 0)->text().toInt();
    
    auto reply = QMessageBox::question(this, "Confirm Delete", 
        "Are you sure you want to delete this TA?",
        QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        if (taRepo.remove(taId)) {
            QMessageBox::information(this, "Success", "TA deleted successfully.");
            loadManageTAs();
        } else {
            QMessageBox::warning(this, "Error", "Failed to delete TA.");
        }
    }
}

void AOMainWindow::on_btnMakeupRequests_clicked() {
    ui->stackedWidget->setCurrentWidget(ui->makeupRequestsPage);
    loadMakeupRequests();
}

void AOMainWindow::loadMakeupRequests() {
    auto allRequests = makeupRequestRepo.load();
    ui->tableMakeupRequests->setRowCount(0);
    ui->tableMakeupRequests->setColumnCount(8);
    ui->tableMakeupRequests->setHorizontalHeaderLabels({"ID", "Lab", "Instructor", "Room", "Date", "Time", "Reason", "Status"});
    
    int row = 0;
    for (const auto& req : allRequests) {
        ui->tableMakeupRequests->insertRow(row);
        
        auto labOpt = labRepo.getLabById(req.getLabId());
        QString labName = labOpt.has_value() ? QString::fromStdString(labOpt->getName()) : "Unknown";
        
        auto instrOpt = instructorRepo.getInstructorById(req.getInstructorId());
        QString instrName = instrOpt.has_value() ? QString::fromStdString(instrOpt->getName()) : "Unknown";
        
        auto roomOpt = roomRepo.getRoomById(req.getRoomId());
        QString roomName = roomOpt.has_value() ? QString::fromStdString(roomOpt->getName()) : "Unknown";
        
        ui->tableMakeupRequests->setItem(row, 0, new QTableWidgetItem(QString::number(req.getId())));
        ui->tableMakeupRequests->setItem(row, 1, new QTableWidgetItem(labName));
        ui->tableMakeupRequests->setItem(row, 2, new QTableWidgetItem(instrName));
        ui->tableMakeupRequests->setItem(row, 3, new QTableWidgetItem(roomName));
        ui->tableMakeupRequests->setItem(row, 4, new QTableWidgetItem(QString::fromStdString(req.getDate())));
        ui->tableMakeupRequests->setItem(row, 5, new QTableWidgetItem(QString::fromStdString(req.getTime())));
        ui->tableMakeupRequests->setItem(row, 6, new QTableWidgetItem(QString::fromStdString(req.getReason())));
        ui->tableMakeupRequests->setItem(row, 7, new QTableWidgetItem(QString::fromStdString(req.getStatus())));
        
        row++;
    }
    
    ui->tableMakeupRequests->resizeColumnsToContents();
}

void AOMainWindow::on_btnAcceptMakeup_clicked() {
    int row = ui->tableMakeupRequests->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "No Selection", "Please select a makeup request to accept.");
        return;
    }
    
    int requestId = ui->tableMakeupRequests->item(row, 0)->text().toInt();
    auto allRequests = makeupRequestRepo.load();
    
    MakeupRequest* selectedRequest = nullptr;
    for (auto& req : allRequests) {
        if (req.getId() == requestId) {
            selectedRequest = &req;
            break;
        }
    }
    
    if (!selectedRequest) {
        QMessageBox::warning(this, "Error", "Request not found.");
        return;
    }
    
    // Get the lab to find room and instructor
    auto labOpt = labRepo.getLabById(selectedRequest->getLabId());
    if (!labOpt.has_value()) {
        QMessageBox::warning(this, "Error", "Lab not found.");
        return;
    }
    Lab lab = labOpt.value();
    
    // Parse time to get start and end
    QString timeStr = QString::fromStdString(selectedRequest->getTime());
    QStringList timeParts = timeStr.split("-");
    if (timeParts.size() != 2) {
        QMessageBox::warning(this, "Error", "Invalid time format.");
        return;
    }
    
    QTime startTime = QTime::fromString(timeParts[0].trimmed(), "HH:mm");
    QTime endTime = QTime::fromString(timeParts[1].trimmed(), "HH:mm");
    QString dateStr = QString::fromStdString(selectedRequest->getDate());
    
    // Check for clashes
    auto allTimings = actualTimingRepo.getAllActualTimings();
    for (const auto& timing : allTimings) {
        if (timing.getDate() == dateStr.toStdString()) {
            QTime existingStart = QTime::fromString(QString::fromStdString(timing.getStartTime()), "HH:mm");
            QTime existingEnd = QTime::fromString(QString::fromStdString(timing.getEndTime()), "HH:mm");
            
            // Check instructor clash
            if (timing.getTaId() == lab.getInstructorId()) {
                if (startTime < existingEnd && endTime > existingStart) {
                    QMessageBox::warning(this, "Instructor Clash", 
                        QString("Instructor has another session on %1 from %2 to %3")
                        .arg(dateStr)
                        .arg(existingStart.toString("HH:mm"))
                        .arg(existingEnd.toString("HH:mm")));
                    return;
                }
            }
            
            // Check room clash using the room from the request
            auto timingLabOpt = labRepo.getLabById(timing.getLabId());
            if (timingLabOpt.has_value() && timingLabOpt->getRoomId() == selectedRequest->getRoomId()) {
                if (startTime < existingEnd && endTime > existingStart) {
                    QMessageBox::warning(this, "Room Clash", 
                        QString("Room is already booked on %1 from %2 to %3")
                        .arg(dateStr)
                        .arg(existingStart.toString("HH:mm"))
                        .arg(existingEnd.toString("HH:mm")));
                    return;
                }
            }
        }
    }
    
    // No clashes, create the makeup session
    double duration = startTime.secsTo(endTime) / 3600.0;
    ActualTiming makeup(selectedRequest->getLabId(), 
                       lab.getInstructorId(), 
                       dateStr.toStdString(),
                       startTime.toString("HH:mm").toStdString(),
                       endTime.toString("HH:mm").toStdString(),
                       duration,
                       "Makeup - " + selectedRequest->getReason());
    actualTimingRepo.add(makeup);
    
    // Update request status
    selectedRequest->setStatus("Approved");
    makeupRequestRepo.update(*selectedRequest);
    
    QMessageBox::information(this, "Success", "Makeup session scheduled successfully.");
    loadMakeupRequests();
}

void AOMainWindow::on_btnRejectMakeup_clicked() {
    int row = ui->tableMakeupRequests->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "No Selection", "Please select a makeup request to reject.");
        return;
    }
    
    auto reply = QMessageBox::question(this, "Confirm Rejection", 
        "Are you sure you want to reject this makeup request?",
        QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        int requestId = ui->tableMakeupRequests->item(row, 0)->text().toInt();
        auto allRequests = makeupRequestRepo.load();
        
        for (auto& req : allRequests) {
            if (req.getId() == requestId) {
                req.setStatus("Rejected");
                makeupRequestRepo.update(req);
                break;
            }
        }
        
        QMessageBox::information(this, "Success", "Makeup request rejected.");
        loadMakeupRequests();
    }
}

AOMainWindow::~AOMainWindow() {
    delete ui;
    // Free other resources if needed
}



// Schedule/report methods: Call your ReportService's supported methods only.

