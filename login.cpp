#include "login.h"
#include "ui_login.h"
#include "ta_mainwindow.h"
#include "signup.h"
#include "instructor_mainwindow.h"
#include "hod_mainwindow.h"
#include "ao_mainwindow.h"
#include "attendant_mainwindow.h"
#include "backend/repositories/BuildingRepository.h"
#include <QMessageBox>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    // Initialize repositories and auth service (uses default users.txt)
    userRepo = new UserRepository("users.txt");
    // pass nullptr for other repos for now
    authService = new AuthService(*userRepo, nullptr, nullptr, nullptr, nullptr, nullptr);

    // Connect sign in button
    connect(ui->btnSignIn, &QPushButton::clicked, this, &Login::on_btnSignIn_clicked);
    // Connect back button to return to start page
    if (ui->btnBack) connect(ui->btnBack, &QPushButton::clicked, this, &Login::on_btnBack_clicked);
}

Login::~Login()
{
    delete authService;
    delete userRepo;
    delete ui;
}

void Login::on_btnSignIn_clicked()
{
    QString email = ui->txtEmail->text().trimmed();
    QString password = ui->txtPassword->text().trimmed();  // Trim password input here

    if (email.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Login", "Please enter email and password.");
        return;
    }
    // First check whether the username exists (give clear feedback)
    User found = userRepo->findByUsername(email.toStdString());
    if (found.getUsername().empty()) {
        QMessageBox::critical(this, "Login Failed", "Username not found. Please check your username/email.");
        return;
    }

    // Check password against stored hash and give clear feedback
    std::string attemptedHash = AuthService::computeHash(password.toStdString());
    if (attemptedHash != found.getPasswordHash()) {
        // debug output for password hash mismatch
        QString debugInfo = QString("Attempted Hash: %1\nStored Hash: %2")
                                .arg(QString::fromStdString(attemptedHash))
                                .arg(QString::fromStdString(found.getPasswordHash()));
        QMessageBox::critical(this, "Login Failed", "Incorrect password. Please try again.\n" + debugInfo);
        return;
    }

    // Password matches — perform authentication and continue
    User u;
    bool ok = authService->authenticate(email.toStdString(), password.toStdString(), u);
    if (!ok) {
        QMessageBox::critical(this, "Login Failed", "Authentication failed. Please try again.");
        return;
    }

    // Open role-specific window
    std::string role = u.getRole();
    if (role == "TA") {
        TAMainWindow *taWindow = new TAMainWindow(u.getId(), this->parentWidget());
        taWindow->show();
    } else if (role == "Instructor") {
        InstructorMainWindow *inst = new InstructorMainWindow(u.getId(), this->parentWidget());
        inst->show();
    } else if (role == "HOD") {
        HODMainWindow *hod = new HODMainWindow(u.getId(), this->parentWidget());
        hod->show();
    } else if (role == "AcademicOfficer") {
        AOMainWindow *ao = new AOMainWindow(u.getId(), this->parentWidget());
        ao->show();
    } else if (role == "Attendant") {
        AttendantMainWindow *attendant = new AttendantMainWindow(u.getId(), this->parentWidget());
        attendant->show();
    } else {
        // Check if user is assigned as attendant to any building
        BuildingRepository buildingRepo("test_buildings.bin");
        auto buildings = buildingRepo.getAll();
        bool isAttendant = false;
        for (const auto& b : buildings) {
            if (b.getAttendantId() == u.getId()) {
                isAttendant = true;
                break;
            }
        }
        if (isAttendant) {
            AttendantMainWindow *attendant = new AttendantMainWindow(u.getId(), this->parentWidget());
            attendant->show();
        } else {
            // default: show TA window
            TAMainWindow *taWindow = new TAMainWindow(u.getId(), this->parentWidget());
            taWindow->show();
        }
    }

    this->accept(); // Close login dialog
}

void Login::on_btnBack_clicked()
{
    // Show parent (StartPage) and close this dialog
    if (this->parentWidget()) this->parentWidget()->show();
    this->reject();
}

// signup removed — AO-only creation enforced via AO UI
