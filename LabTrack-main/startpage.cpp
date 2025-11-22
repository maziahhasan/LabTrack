#include "startpage.h"
#include "ui_startpage.h"

StartPage::StartPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RoleSelectionWindow)
{
    ui->setupUi(this);
    loginWindow = new Login(this);

    // Connect buttons to open Login window
    connect(ui->btnAdmin, &QPushButton::clicked, loginWindow, &QDialog::show);
    connect(ui->btnInstructor, &QPushButton::clicked, loginWindow, &QDialog::show);
    connect(ui->btnTA, &QPushButton::clicked, loginWindow, &QDialog::show);
    connect(ui->btnHOD, &QPushButton::clicked, loginWindow, &QDialog::show);
}

StartPage::~StartPage()
{
    delete ui;
    delete loginWindow;
}
