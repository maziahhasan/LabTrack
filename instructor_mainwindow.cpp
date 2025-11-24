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
#include <QMap>
#include "backend/repositories/UserRepository.h"
#include "backend/models/MakeupRequest.h"

InstructorMainWindow::InstructorMainWindow(int instructorId, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InstructorMainWindow),
    instructorId(instructorId),
    labRepo("labs.bin"),
    instructorRepo("instructors.bin"),
    roomRepo("rooms.bin"),
    buildingRepo("buildings.bin"),
    taRepo("tas.bin"),
    actualTimingRepo("actual_timings.bin"),
    reportService(labRepo, instructorRepo, taRepo, roomRepo, buildingRepo, actualTimingRepo),
    makeupRequestRepo("makeup_requests.bin"),
    makeupService(nullptr)
{
    ui->setupUi(this);
    
    // Initialize makeup service
    makeupService = new MakeupService(makeupRequestRepo, labRepo);
    
    // Load current user
    UserRepository userRepo; // uses users.bin by default
    auto users = userRepo.loadAll();
    for (const auto& u : users) {
        if (u.getId() == instructorId) {
            currentUser = u;
            break;
        }
    }

    // Connect sidebar buttons to switch pages
    connect(ui->btnMyLabs, &QPushButton::clicked, this, &InstructorMainWindow::on_btnMyLabs_clicked);
    connect(ui->btnRequestMakeup, &QPushButton::clicked, this, &InstructorMainWindow::on_btnRequestMakeup_clicked);
    connect(ui->btnProfile, &QPushButton::clicked, this, &InstructorMainWindow::on_btnProfile_clicked);

    // Connect update profile button
    connect(ui->btnUpdateProfile, &QPushButton::clicked, this, &InstructorMainWindow::on_btnUpdateProfile_clicked);

    // Load initial data
    loadMyLabs();
    loadProfile();

    // Set default page to My Labs
    ui->stackedWidget->setCurrentWidget(ui->myLabsPage);
    
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

void InstructorMainWindow::on_btnMyLabs_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->myLabsPage);
}

void InstructorMainWindow::on_btnProfile_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->profilePage);
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
    QString selectedLab = QInputDialog::getItem(this, "Request Makeup Lab", 
        "Select Lab:", labNames, 0, false, &ok);
    if (!ok || selectedLab.isEmpty()) return;
    
    int labId = labMap[selectedLab];
    auto labOpt = labRepo.getLabById(labId);
    if (!labOpt) return;
    
    // Get date
    QString dateStr = QInputDialog::getText(this, "Request Makeup Lab", 
        "Enter date (YYYY-MM-DD):", QLineEdit::Normal, 
        QDate::currentDate().toString("yyyy-MM-dd"), &ok);
    if (!ok || dateStr.isEmpty()) return;
    
    // Get start time
    QString startTime = QInputDialog::getText(this, "Request Makeup Lab", 
        "Enter start time (HH:MM):", QLineEdit::Normal, "09:00", &ok);
    if (!ok || startTime.isEmpty()) return;
    
    // Get end time
    QString endTime = QInputDialog::getText(this, "Request Makeup Lab", 
        "Enter end time (HH:MM):", QLineEdit::Normal, "11:00", &ok);
    if (!ok || endTime.isEmpty()) return;
    
    // Get reason
    QString reason = QInputDialog::getText(this, "Request Makeup Lab", 
        "Enter reason for makeup request:", QLineEdit::Normal, "", &ok);
    if (!ok) reason = "";
    
    // Create makeup request
    int requestId = makeupRequestRepo.getNextId();
    MakeupRequest request(requestId, labId, instructorId, dateStr.toStdString(), 
        startTime.toStdString(), endTime.toStdString(), "Pending");
    makeupRequestRepo.add(request);
    
    QMessageBox::information(this, "Success", 
        QString("Makeup lab request submitted successfully!\nRequest ID: %1\n"
                "Lab: %2\nDate: %3\nTime: %4 - %5")
            .arg(requestId)
            .arg(selectedLab)
            .arg(dateStr)
            .arg(startTime)
            .arg(endTime));
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
