#include "signup.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>

Signup::Signup(AuthService *auth, QWidget *parent)
    : QDialog(parent), authService(auth)
{
    setWindowTitle("Sign Up");
    auto *layout = new QVBoxLayout(this);

    layout->addWidget(new QLabel("Email:"));
    txtEmail = new QLineEdit(this);
    layout->addWidget(txtEmail);

    layout->addWidget(new QLabel("Password:"));
    txtPassword = new QLineEdit(this);
    txtPassword->setEchoMode(QLineEdit::Password);
    layout->addWidget(txtPassword);

    layout->addWidget(new QLabel("Role:"));
    comboRole = new QComboBox(this);
    comboRole->addItem("TA");
    comboRole->addItem("Instructor");
    comboRole->addItem("HOD");
    comboRole->addItem("AcademicOfficer");
    layout->addWidget(comboRole);

    btnSignUp = new QPushButton("Sign Up", this);
    layout->addWidget(btnSignUp);

    connect(btnSignUp, &QPushButton::clicked, this, &Signup::on_btnSignUp_clicked);
}

Signup::~Signup() {}

void Signup::on_btnSignUp_clicked()
{
    QString email = txtEmail->text();
    QString pw = txtPassword->text();
    QString role = comboRole->currentText();

    if (email.isEmpty() || pw.isEmpty()) {
        QMessageBox::warning(this, "Sign Up", "Please enter email and password.");
        return;
    }

    bool ok = authService->registerUser(email.toStdString(), pw.toStdString(), role.toStdString());
    if (!ok) {
        QMessageBox::critical(this, "Sign Up Failed", "User already exists or registration failed.");
        return;
    }

    QMessageBox::information(this, "Sign Up", "Registration successful. You can now sign in.");
    accept();
}
