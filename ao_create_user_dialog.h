#pragma once

#include <QDialog>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>

#include "backend/services/AuthService.h"
#include "backend/repositories/InstructorRepository.h"
#include "backend/repositories/TARepository.h"
#include "backend/repositories/HODRepository.h"

class AOCreateUserDialog : public QDialog {
    Q_OBJECT
public:
    AOCreateUserDialog(AuthService* auth, InstructorRepository* iRepo, TARepository* tRepo, HODRepository* hRepo, QWidget* parent = nullptr);

    // exposed so callers (AOMainWindow) can preset/lock the role
    QComboBox* comboRole;

private:
    AuthService* authService;
    InstructorRepository* instrRepo;
    TARepository* taRepo;
    HODRepository* hodRepo;

    QLineEdit* editUsername;
    QLineEdit* editPassword;
    QLineEdit* editFullName;
    QLineEdit* editEmail;
    QPushButton* btnOk;
    QPushButton* btnCancel;

private slots:
    void onOk();
};
