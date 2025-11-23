#ifndef INSTRUCTORMainWindow_H
#define INSTRUCTORMainWindow_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include <QListWidgetItem>
#include <QFileDialog>
#include <QPdfWriter>
#include <QPainter>
#include <QMessageBox>
#include "backend/repositories/LabRepository.h"
#include "backend/repositories/InstructorRepository.h"
#include "backend/repositories/TARepository.h"
#include "backend/repositories/RoomRepository.h"
#include "backend/repositories/BuildingRepository.h"
#include "backend/repositories/ActualTimingRepository.h"
#include "backend/services/ReportService.h"
#include "backend/services/MakeupService.h"
#include "backend/repositories/MakeupRequestRepository.h"
#include "backend/models/User.h"

QT_BEGIN_NAMESPACE
namespace Ui { class InstructorMainWindow; }
QT_END_NAMESPACE

class InstructorMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    InstructorMainWindow(int instructorId, QWidget *parent = nullptr);
    ~InstructorMainWindow();

private slots:
    void on_btnDashboard_clicked();
    void on_btnMyLabs_clicked();
    void on_btnLabDetails_clicked();
    void on_btnTimesheet_clicked();
    void on_btnNotifications_clicked();
    void on_btnProfile_clicked();

    void on_comboSelectLab_currentIndexChanged(int index);
    void on_comboSelectLabTimesheet_currentIndexChanged(int index);
    void on_btnUpdateProfile_clicked();
    void on_btnRequestMakeup_clicked();

private:
    Ui::InstructorMainWindow *ui;
    int instructorId;
    LabRepository labRepo;
    InstructorRepository instructorRepo;
    TARepository taRepo;
    RoomRepository roomRepo;
    BuildingRepository buildingRepo;
    ActualTimingRepository actualTimingRepo;
    ReportService reportService;
    MakeupRequestRepository makeupRequestRepo;
    MakeupService *makeupService;
    User currentUser;

    void loadDashboard();
    void loadMyLabs();
    void loadLabDetails();
    void loadTimesheet();
    void loadNotifications();
    void loadProfile();

    void exportToPDF(const QString& title, QTableWidget* table);
};

#endif // INSTRUCTORMainWindow_H
