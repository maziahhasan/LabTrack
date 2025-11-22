#include "login.h"
#include "ui_login.h"
#include "ta_mainwindow.h"
#include "signup.h"
#include "instructor_mainwindow.h"
#include "hod_mainwindow.h"
#include "ao_mainwindow.h"
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
    // Connect signup link (label) to open signup dialog
    connect(ui->signupText, &QLabel::linkActivated, this, &Login::on_signupText_linkActivated);
}

Login::~Login()
{
    delete authService;
    delete userRepo;
    delete ui;
}

void Login::on_btnSignIn_clicked()
{
    QString email = ui->txtEmail->text();
    QString password = ui->txtPassword->text();

    if (email.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Login", "Please enter email and password.");
        return;
    }

    User u;
    bool ok = authService->authenticate(email.toStdString(), password.toStdString(), u);
    if (!ok) {
        QMessageBox::critical(this, "Login Failed", "Invalid username or password.");
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
        HODMainWindow *hod = new HODMainWindow(this->parentWidget());
        hod->show();
    } else if (role == "AcademicOfficer") {
        AOMainWindow *ao = new AOMainWindow(this->parentWidget());
        ao->show();
    } else {
        // default: show TA window
        TAMainWindow *taWindow = new TAMainWindow(u.getId(), this->parentWidget());
        taWindow->show();
    }

    this->accept(); // Close login dialog
}

void Login::on_signupText_linkActivated(const QString &link)
{
    if (!signupDialog) {
        signupDialog = new Signup(authService, this);
    }
    signupDialog->exec();
}
