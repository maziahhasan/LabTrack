#ifndef ATTENDANT_MAINWINDOW_H
#define ATTENDANT_MAINWINDOW_H

#include <QMainWindow>
#include "backend/repositories/LabRepository.h"
#include "backend/repositories/RoomRepository.h"
#include "backend/repositories/BuildingRepository.h"
#include "backend/repositories/ActualTimingRepository.h"
#include "backend/services/LabService.h"
#include "backend/models/User.h"

namespace Ui {
class AttendantMainWindow;
}

class AttendantMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AttendantMainWindow(QWidget *parent = nullptr);
    explicit AttendantMainWindow(int attendantId, QWidget *parent = nullptr);
    ~AttendantMainWindow();

private slots:
    void on_btnDashboard_clicked();
    void on_btnTimesheets_clicked();
    void on_btnFillTimesheet_clicked();
    void on_comboSelectLab_currentIndexChanged(int index);
    void on_btnSubmitTimesheet_clicked();

private:
    Ui::AttendantMainWindow *ui;
    int attendantId = -1;
    User currentUser;
    LabRepository labRepo;
    RoomRepository roomRepo;
    BuildingRepository buildingRepo;
    ActualTimingRepository actualTimingRepo;
    LabService *labService;
    
    void loadDashboard();
    void loadTimesheets();
    void loadFillTimesheet();
    int getBuildingIdForAttendant();
};

#endif // ATTENDANT_MAINWINDOW_H

