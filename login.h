#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "backend/repositories/UserRepository.h"
#include "backend/services/AuthService.h"
#include "backend/repositories/TARepository.h"
#include "backend/repositories/InstructorRepository.h"
#include "backend/repositories/HODRepository.h"
#include "backend/repositories/AcademicOfficerRepository.h"
#include "backend/repositories/BuildingRepository.h"

namespace Ui {
class LoginWindow;  // matches the .ui class name
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private:
    Ui::LoginWindow *ui;  // pointer to the UI
    UserRepository *userRepo;
    AuthService *authService;
private slots:
    void on_btnSignIn_clicked();
    void on_btnBack_clicked();
};

#endif // LOGIN_H
