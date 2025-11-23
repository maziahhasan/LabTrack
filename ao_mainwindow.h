#ifndef AOMAINWINDOW_H
#define AOMAINWINDOW_H

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
#include "backend/repositories/UserRepository.h"
#include "backend/services/AuthService.h"
#include "backend/repositories/HODRepository.h"
#include "backend/repositories/AcademicOfficerRepository.h"

QT_BEGIN_NAMESPACE
namespace Ui { class AOMainWindow; }
QT_END_NAMESPACE

class AOMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    AOMainWindow(QWidget *parent = nullptr);
    explicit AOMainWindow(int aoId, QWidget *parent = nullptr);
    ~AOMainWindow();

private slots:
    void on_btnDashboard_clicked();
    void on_btnManageLabs_clicked();
    void on_btnManageInstructors_clicked();
    void on_btnManageTAs_clicked();
    void on_btnScheduleLabs_clicked();
    void on_btnReports_clicked();

    void on_btnAddLab_clicked();
    void on_btnEditLab_clicked();
    void on_btnDeleteLab_clicked();

    void on_btnAddInstructor_clicked();
    void on_btnEditInstructor_clicked();
    void on_btnDeleteInstructor_clicked();

    void on_btnAddTA_clicked();
    void on_btnEditTA_clicked();
    void on_btnDeleteTA_clicked();

    void on_btnAddHOD_clicked();

    void on_btnSetSchedule_clicked();

    void on_btnGenerateWeeklySchedule_clicked();
    void on_btnGenerateTimesheets_clicked();
    void on_btnGenerateMakeupSchedule_clicked();

private:
    Ui::AOMainWindow *ui;
    LabRepository labRepo;
    InstructorRepository instructorRepo;
    TARepository taRepo;
    HODRepository hodRepo;
    RoomRepository roomRepo;
    BuildingRepository buildingRepo;
    ActualTimingRepository actualTimingRepo;
    UserRepository userRepo;
    AcademicOfficerRepository aoRepo;
    AuthService authService;
    ReportService reportService;
    int aoId = -1;

    void loadDashboard();
    void loadManageLabs();
    void loadManageInstructors();
    void loadManageTAs();
    void loadScheduleLabs();
    void loadReports();

    void exportToPDF(const QString& title, QTableWidget* table);
};

#endif // AOMAINWINDOW_H
