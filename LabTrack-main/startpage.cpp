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
}

StartPage::~StartPage()
{
    delete ui;
    delete loginWindow;
}

void StartPage::on_btnTA_clicked()
{
    // For demo, assume TA ID 1
    TAMainWindow *taWindow = new TAMainWindow(1, this);
    taWindow->show();
    this->hide();
}

void StartPage::on_btnHOD_clicked()
{
    // For demo, open HOD MainWindow
    HODMainWindow *hodWindow = new HODMainWindow(this);
    hodWindow->show();
    this->hide();
}
