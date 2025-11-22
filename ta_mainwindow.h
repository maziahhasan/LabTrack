#ifndef TA_MAINWINDOW_H
#define TA_MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class TAMainWindow;
}

class TAMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TAMainWindow(QWidget *parent = nullptr);
    explicit TAMainWindow(int taId, QWidget *parent = nullptr);
    ~TAMainWindow();

private:
    Ui::TAMainWindow *ui;
    int taId = -1;
};

#endif // TA_MAINWINDOW_H
