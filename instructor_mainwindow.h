#ifndef INSTRUCTORMainWindow_H
#define INSTRUCTORMainWindow_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include <QListWidgetItem>
#include <QFileDialog>
#include <QPdfWriter>
#include <QPainter>
#include <QMessageBox>
#include <memory>
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
    void on_btnMyLabs_clicked();
    void on_btnProfile_clicked();

    void on_btnUpdateProfile_clicked();
    void on_btnRequestMakeup_clicked();
    void on_btnSubmitMakeupRequest_clicked();

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
    std::unique_ptr<MakeupService> makeupService;
    User currentUser;

    void loadMyLabs();
    void loadProfile();
    void loadMakeupRequests();

    void exportToPDF(const QString& title, QTableWidget* table);
};

#endif // INSTRUCTORMainWindow_H
