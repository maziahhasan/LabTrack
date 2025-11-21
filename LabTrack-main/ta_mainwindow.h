#ifndef TA_MAINWINDOW_H
#define TA_MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class ta_mainwindow;  // Must match the name of the generated ui header
}

class ta_mainwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ta_mainwindow(QWidget *parent = nullptr);
    ~ta_mainwindow();

private:
    Ui::ta_mainwindow *ui;
};

#endif // TA_MAINWINDOW_H
