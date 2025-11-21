#include "login.h"
#include "ui_login.h"
#include "ta_mainwindow.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    // Connect sign in button
    connect(ui->btnSignIn, &QPushButton::clicked, this, &Login::on_btnSignIn_clicked);
}

Login::~Login()
{
    delete ui;
}

void Login::on_btnSignIn_clicked()
{
    // Simple authentication - for demo, accept any email/password and assume TA role
    QString email = ui->txtEmail->text();
    QString password = ui->txtPassword->text();

    if (!email.isEmpty() && !password.isEmpty()) {
        // For demo, assume TA ID 1
        TAMainWindow *taWindow = new TAMainWindow(1, this->parentWidget());
        taWindow->show();
        this->accept(); // Close login dialog
    }
}
