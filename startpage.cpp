#include "startpage.h"
#include "ui_startpage.h"
#include "ta_mainwindow.h"
#include "hod_mainwindow.h"
#include "instructor_mainwindow.h"

StartPage::StartPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RoleSelectionWindow)
{
    ui->setupUi(this);
    loginWindow = new Login(this);

    // Connect buttons to open Login window
    connect(ui->btnAdmin, &QPushButton::clicked, loginWindow, &QDialog::show);
    connect(ui->btnInstructor, &QPushButton::clicked, loginWindow, &QDialog::show);
    connect(ui->btnTA, &QPushButton::clicked, this, &StartPage::on_btnTA_clicked);
    connect(ui->btnHOD, &QPushButton::clicked, loginWindow, &QDialog::show);
    connect(ui->btnAttendant, &QPushButton::clicked, this, &StartPage::on_btnAttendant_clicked);
}

StartPage::~StartPage()
{
    delete ui;
    delete loginWindow;
}

void StartPage::on_btnTA_clicked()
{
    // Require TA to log in instead of directly opening TA window
    if (loginWindow) {
        loginWindow->show();
        this->hide();
    }
}

void StartPage::on_btnHOD_clicked()
{
    // Require HOD to log in instead of directly opening HOD window
    if (loginWindow) {
        loginWindow->show();
        this->hide();
    }
}

void StartPage::on_btnAdmin_clicked()
{
    // open login for admin/academic officer
    if (loginWindow) {
        loginWindow->show();
        this->hide();
    }
}

void StartPage::on_btnInstructor_clicked()
{
    // open login for instructor
    if (loginWindow) {
        loginWindow->show();
        this->hide();
    }
}

void StartPage::on_btnAttendant_clicked()
{
    // open login for attendant
    if (loginWindow) {
        loginWindow->show();
        this->hide();
    }
}
