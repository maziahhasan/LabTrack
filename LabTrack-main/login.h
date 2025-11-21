#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

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
};

#endif // LOGIN_H
