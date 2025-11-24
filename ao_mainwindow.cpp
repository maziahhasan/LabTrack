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
    , actualTimingRepo("timings.bin")
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
    connect(ui->btnScheduleLabs, &QPushButton::clicked, this, &AOMainWindow::on_btnScheduleLabs_clicked);
    connect(ui->btnReports, &QPushButton::clicked, this, &AOMainWindow::on_btnReports_clicked);

    // Manage actions
    connect(ui->btnAddLab, &QPushButton::clicked, this, &AOMainWindow::on_btnAddLab_clicked);
    connect(ui->btnAddInstructor, &QPushButton::clicked, this, &AOMainWindow::on_btnAddInstructor_clicked);
    connect(ui->btnAddTA, &QPushButton::clicked, this, &AOMainWindow::on_btnAddTA_clicked);
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
    bool ok;
    QString name = QInputDialog::getText(this, "Add Lab", "Lab Name:", QLineEdit::Normal, "", &ok);
    if (ok && !name.isEmpty()) {
        // Parse course code and section (e.g., "CS101 A" or just "CS101")
        QStringList parts = name.split(" ");
        QString courseCode = parts[0];
        QString section = parts.size() > 1 ? parts[1] : "";
        Lab lab(0, courseCode.toStdString(), section.toStdString());
        labRepo.add(lab);
        loadManageLabs();
    }
}
void AOMainWindow::loadManageLabs() {
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
void AOMainWindow::on_btnScheduleLabs_clicked() {}
void AOMainWindow::on_btnReports_clicked() {}
void AOMainWindow::on_btnEditLab_clicked() {}
void AOMainWindow::on_btnDeleteLab_clicked() {}
void AOMainWindow::on_btnEditInstructor_clicked() {}
void AOMainWindow::on_btnDeleteInstructor_clicked() {}
void AOMainWindow::on_btnEditTA_clicked() {}
void AOMainWindow::on_btnDeleteTA_clicked() {}
void AOMainWindow::on_btnSetSchedule_clicked() {}
void AOMainWindow::on_btnGenerateWeeklySchedule_clicked() {}
void AOMainWindow::on_btnGenerateTimesheets_clicked() {}
void AOMainWindow::on_btnGenerateMakeupSchedule_clicked() {}

AOMainWindow::~AOMainWindow() {
    delete ui;
    // Free other resources if needed
}



// Schedule/report methods: Call your ReportService's supported methods only.

