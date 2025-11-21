#ifndef STARTPAGE_H
#define STARTPAGE_H

#include <QMainWindow>
#include "login.h"

namespace Ui {
class RoleSelectionWindow;  // matches startpage.ui <class>
}

class StartPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartPage(QWidget *parent = nullptr);
    ~StartPage();

private slots:
    void on_btnAdmin_clicked();
    void on_btnInstructor_clicked();
    void on_btnTA_clicked();
    void on_btnHOD_clicked();

private:
    Ui::RoleSelectionWindow *ui;
    Login *loginWindow;  // pointer to login window
};

#endif // STARTPAGE_H
