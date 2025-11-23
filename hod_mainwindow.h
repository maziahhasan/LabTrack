#ifndef HOD_MAINWINDOW_H
#define HOD_MAINWINDOW_H

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
#include "backend/utils/DateUtils.h"

namespace Ui { class HODMainWindow; }

class HODMainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit HODMainWindow(QWidget *parent = nullptr);
    // overload to accept authenticated HOD id
    explicit HODMainWindow(int hodId, QWidget *parent = nullptr);
    ~HODMainWindow();

private slots:
    void on_btnDashboard_clicked();
    void on_btnWeeklySchedule_clicked();
    void on_btnWeeklyTimesheets_clicked();
    void on_btnLabHistory_clicked();
    void on_btnMakeupRequests_clicked();

    void on_comboSelectLab_currentIndexChanged(int index);
    void on_btnExportSchedule_clicked();
    void on_btnExportTimesheets_clicked();
    void on_btnExportHistory_clicked();
    void on_btnExportRequests_clicked();

private:
    Ui::HODMainWindow *ui;
    LabRepository labRepo;
    InstructorRepository instructorRepo;
    RoomRepository roomRepo;
    BuildingRepository buildingRepo;
    TARepository taRepo;
    ActualTimingRepository actualTimingRepo;
    ReportService *reportService;
    int hodId = -1;

    void loadDashboard();
    void loadWeeklySchedule();
    void loadWeeklyTimesheets();
    void loadLabHistory();
    void loadMakeupRequests();
    void exportToPDF(const QString &title, QTableWidget *table);
};

#endif // HOD_MAINWINDOW_H
