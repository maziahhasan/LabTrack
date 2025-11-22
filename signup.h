#pragma once
#include <QDialog>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include "backend/services/AuthService.h"

class Signup : public QDialog {
    Q_OBJECT
public:
    explicit Signup(AuthService *auth, QWidget *parent = nullptr);
    ~Signup();
private slots:
    void on_btnSignUp_clicked();
private:
    AuthService *authService;
    QLineEdit *txtEmail;
    QLineEdit *txtPassword;
    QComboBox *comboRole;
    QPushButton *btnSignUp;
};
