/********************************************************************************
** Form generated from reading UI file 'hod_mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOD_MAINWINDOW_H
#define UI_HOD_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HODMainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QFrame *sidebarFrame;
    QVBoxLayout *verticalLayoutSidebar;
    QPushButton *btnDashboard;
    QPushButton *btnWeeklySchedule;
    QPushButton *btnWeeklyTimesheets;
    QPushButton *btnLabHistory;
    QPushButton *btnMakeupRequests;
    QStackedWidget *stackedWidget;
    QWidget *dashboardPage;
    QVBoxLayout *verticalLayoutDashboard;
    QLabel *lblDashboardTitle;
    QHBoxLayout *horizontalLayoutCards;
    QFrame *frameTotalLabs;
    QVBoxLayout *verticalLayoutTotalLabs;
    QLabel *lblTotalLabs;
    QLabel *lblTotalLabsCount;
    QFrame *frameActiveLabs;
    QVBoxLayout *verticalLayoutActiveLabs;
    QLabel *lblActiveLabs;
    QLabel *lblActiveLabsCount;
    QFrame *framePendingRequests;
    QVBoxLayout *verticalLayoutPendingRequests;
    QLabel *lblPendingRequests;
    QLabel *lblPendingRequestsCount;
    QWidget *weeklySchedulePage;
    QVBoxLayout *verticalLayoutWeeklySchedule;
    QLabel *lblWeeklyScheduleTitle;
    QHBoxLayout *horizontalLayoutFilters;
    QLabel *lblFilterWeek;
    QCalendarWidget *calendarWeekSchedule;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnExportSchedule;
    QTableWidget *tableWeeklySchedule;
    QWidget *weeklyTimesheetsPage;
    QVBoxLayout *verticalLayoutWeeklyTimesheets;
    QLabel *lblWeeklyTimesheetsTitle;
    QHBoxLayout *horizontalLayoutTimesheetFilters;
    QLabel *lblFilterTimesheetWeek;
    QCalendarWidget *calendarWeekTimesheets;
    QSpacerItem *horizontalSpacerTimesheets;
    QPushButton *btnExportTimesheets;
    QTableWidget *tableWeeklyTimesheets;
    QWidget *labHistoryPage;
    QVBoxLayout *verticalLayoutLabHistory;
    QLabel *lblLabHistoryTitle;
    QHBoxLayout *horizontalLayoutLabHistoryFilters;
    QLabel *lblSelectLab;
    QComboBox *comboSelectLab;
    QPushButton *btnExportHistory;
    QFormLayout *formLayoutLabHistory;
    QLabel *lblTotalContactHours;
    QLabel *lblTotalContactHoursValue;
    QLabel *lblTotalLeaves;
    QLabel *lblTotalLeavesValue;
    QLabel *lblTotalMakeupSessions;
    QLabel *lblTotalMakeupSessionsValue;
    QTableWidget *tableLabHistory;
    QWidget *makeupRequestsPage;
    QVBoxLayout *verticalLayoutMakeupRequests;
    QLabel *lblMakeupRequestsTitle;
    QHBoxLayout *horizontalLayoutMakeupFilters;
    QLabel *lblFilterStatus;
    QComboBox *comboFilterStatus;
    QPushButton *btnExportRequests;
    QTableWidget *tableMakeupRequests;

    void setupUi(QMainWindow *HODMainWindow)
    {
        if (HODMainWindow->objectName().isEmpty())
            HODMainWindow->setObjectName("HODMainWindow");
        HODMainWindow->resize(1000, 700);
        centralWidget = new QWidget(HODMainWindow);
        centralWidget->setObjectName("centralWidget");
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        sidebarFrame = new QFrame(centralWidget);
        sidebarFrame->setObjectName("sidebarFrame");
        sidebarFrame->setFrameShape(QFrame::Shape::NoFrame);
        verticalLayoutSidebar = new QVBoxLayout(sidebarFrame);
        verticalLayoutSidebar->setObjectName("verticalLayoutSidebar");
        btnDashboard = new QPushButton(sidebarFrame);
        btnDashboard->setObjectName("btnDashboard");
        btnDashboard->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        verticalLayoutSidebar->addWidget(btnDashboard);

        btnWeeklySchedule = new QPushButton(sidebarFrame);
        btnWeeklySchedule->setObjectName("btnWeeklySchedule");
        btnWeeklySchedule->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        verticalLayoutSidebar->addWidget(btnWeeklySchedule);

        btnWeeklyTimesheets = new QPushButton(sidebarFrame);
        btnWeeklyTimesheets->setObjectName("btnWeeklyTimesheets");
        btnWeeklyTimesheets->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        verticalLayoutSidebar->addWidget(btnWeeklyTimesheets);

        btnLabHistory = new QPushButton(sidebarFrame);
        btnLabHistory->setObjectName("btnLabHistory");
        btnLabHistory->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        verticalLayoutSidebar->addWidget(btnLabHistory);

        btnMakeupRequests = new QPushButton(sidebarFrame);
        btnMakeupRequests->setObjectName("btnMakeupRequests");
        btnMakeupRequests->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        verticalLayoutSidebar->addWidget(btnMakeupRequests);


        horizontalLayout->addWidget(sidebarFrame);

        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName("stackedWidget");
        dashboardPage = new QWidget();
        dashboardPage->setObjectName("dashboardPage");
        verticalLayoutDashboard = new QVBoxLayout(dashboardPage);
        verticalLayoutDashboard->setObjectName("verticalLayoutDashboard");
        lblDashboardTitle = new QLabel(dashboardPage);
        lblDashboardTitle->setObjectName("lblDashboardTitle");

        verticalLayoutDashboard->addWidget(lblDashboardTitle);

        horizontalLayoutCards = new QHBoxLayout();
        horizontalLayoutCards->setObjectName("horizontalLayoutCards");
        frameTotalLabs = new QFrame(dashboardPage);
        frameTotalLabs->setObjectName("frameTotalLabs");
        verticalLayoutTotalLabs = new QVBoxLayout(frameTotalLabs);
        verticalLayoutTotalLabs->setObjectName("verticalLayoutTotalLabs");
        lblTotalLabs = new QLabel(frameTotalLabs);
        lblTotalLabs->setObjectName("lblTotalLabs");

        verticalLayoutTotalLabs->addWidget(lblTotalLabs);

        lblTotalLabsCount = new QLabel(frameTotalLabs);
        lblTotalLabsCount->setObjectName("lblTotalLabsCount");

        verticalLayoutTotalLabs->addWidget(lblTotalLabsCount);


        horizontalLayoutCards->addWidget(frameTotalLabs);

        frameActiveLabs = new QFrame(dashboardPage);
        frameActiveLabs->setObjectName("frameActiveLabs");
        verticalLayoutActiveLabs = new QVBoxLayout(frameActiveLabs);
        verticalLayoutActiveLabs->setObjectName("verticalLayoutActiveLabs");
        lblActiveLabs = new QLabel(frameActiveLabs);
        lblActiveLabs->setObjectName("lblActiveLabs");

        verticalLayoutActiveLabs->addWidget(lblActiveLabs);

        lblActiveLabsCount = new QLabel(frameActiveLabs);
        lblActiveLabsCount->setObjectName("lblActiveLabsCount");

        verticalLayoutActiveLabs->addWidget(lblActiveLabsCount);


        horizontalLayoutCards->addWidget(frameActiveLabs);

        framePendingRequests = new QFrame(dashboardPage);
        framePendingRequests->setObjectName("framePendingRequests");
        verticalLayoutPendingRequests = new QVBoxLayout(framePendingRequests);
        verticalLayoutPendingRequests->setObjectName("verticalLayoutPendingRequests");
        lblPendingRequests = new QLabel(framePendingRequests);
        lblPendingRequests->setObjectName("lblPendingRequests");

        verticalLayoutPendingRequests->addWidget(lblPendingRequests);

        lblPendingRequestsCount = new QLabel(framePendingRequests);
        lblPendingRequestsCount->setObjectName("lblPendingRequestsCount");

        verticalLayoutPendingRequests->addWidget(lblPendingRequestsCount);


        horizontalLayoutCards->addWidget(framePendingRequests);


        verticalLayoutDashboard->addLayout(horizontalLayoutCards);

        stackedWidget->addWidget(dashboardPage);
        weeklySchedulePage = new QWidget();
        weeklySchedulePage->setObjectName("weeklySchedulePage");
        verticalLayoutWeeklySchedule = new QVBoxLayout(weeklySchedulePage);
        verticalLayoutWeeklySchedule->setObjectName("verticalLayoutWeeklySchedule");
        lblWeeklyScheduleTitle = new QLabel(weeklySchedulePage);
        lblWeeklyScheduleTitle->setObjectName("lblWeeklyScheduleTitle");

        verticalLayoutWeeklySchedule->addWidget(lblWeeklyScheduleTitle);

        horizontalLayoutFilters = new QHBoxLayout();
        horizontalLayoutFilters->setObjectName("horizontalLayoutFilters");
        lblFilterWeek = new QLabel(weeklySchedulePage);
        lblFilterWeek->setObjectName("lblFilterWeek");

        horizontalLayoutFilters->addWidget(lblFilterWeek);

        calendarWeekSchedule = new QCalendarWidget(weeklySchedulePage);
        calendarWeekSchedule->setObjectName("calendarWeekSchedule");

        horizontalLayoutFilters->addWidget(calendarWeekSchedule);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayoutFilters->addItem(horizontalSpacer);

        btnExportSchedule = new QPushButton(weeklySchedulePage);
        btnExportSchedule->setObjectName("btnExportSchedule");

        horizontalLayoutFilters->addWidget(btnExportSchedule);


        verticalLayoutWeeklySchedule->addLayout(horizontalLayoutFilters);

        tableWeeklySchedule = new QTableWidget(weeklySchedulePage);
        tableWeeklySchedule->setObjectName("tableWeeklySchedule");

        verticalLayoutWeeklySchedule->addWidget(tableWeeklySchedule);

        stackedWidget->addWidget(weeklySchedulePage);
        weeklyTimesheetsPage = new QWidget();
        weeklyTimesheetsPage->setObjectName("weeklyTimesheetsPage");
        verticalLayoutWeeklyTimesheets = new QVBoxLayout(weeklyTimesheetsPage);
        verticalLayoutWeeklyTimesheets->setObjectName("verticalLayoutWeeklyTimesheets");
        lblWeeklyTimesheetsTitle = new QLabel(weeklyTimesheetsPage);
        lblWeeklyTimesheetsTitle->setObjectName("lblWeeklyTimesheetsTitle");

        verticalLayoutWeeklyTimesheets->addWidget(lblWeeklyTimesheetsTitle);

        horizontalLayoutTimesheetFilters = new QHBoxLayout();
        horizontalLayoutTimesheetFilters->setObjectName("horizontalLayoutTimesheetFilters");
        lblFilterTimesheetWeek = new QLabel(weeklyTimesheetsPage);
        lblFilterTimesheetWeek->setObjectName("lblFilterTimesheetWeek");

        horizontalLayoutTimesheetFilters->addWidget(lblFilterTimesheetWeek);

        calendarWeekTimesheets = new QCalendarWidget(weeklyTimesheetsPage);
        calendarWeekTimesheets->setObjectName("calendarWeekTimesheets");

        horizontalLayoutTimesheetFilters->addWidget(calendarWeekTimesheets);

        horizontalSpacerTimesheets = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayoutTimesheetFilters->addItem(horizontalSpacerTimesheets);

        btnExportTimesheets = new QPushButton(weeklyTimesheetsPage);
        btnExportTimesheets->setObjectName("btnExportTimesheets");

        horizontalLayoutTimesheetFilters->addWidget(btnExportTimesheets);


        verticalLayoutWeeklyTimesheets->addLayout(horizontalLayoutTimesheetFilters);

        tableWeeklyTimesheets = new QTableWidget(weeklyTimesheetsPage);
        tableWeeklyTimesheets->setObjectName("tableWeeklyTimesheets");

        verticalLayoutWeeklyTimesheets->addWidget(tableWeeklyTimesheets);

        stackedWidget->addWidget(weeklyTimesheetsPage);
        labHistoryPage = new QWidget();
        labHistoryPage->setObjectName("labHistoryPage");
        verticalLayoutLabHistory = new QVBoxLayout(labHistoryPage);
        verticalLayoutLabHistory->setObjectName("verticalLayoutLabHistory");
        lblLabHistoryTitle = new QLabel(labHistoryPage);
        lblLabHistoryTitle->setObjectName("lblLabHistoryTitle");

        verticalLayoutLabHistory->addWidget(lblLabHistoryTitle);

        horizontalLayoutLabHistoryFilters = new QHBoxLayout();
        horizontalLayoutLabHistoryFilters->setObjectName("horizontalLayoutLabHistoryFilters");
        lblSelectLab = new QLabel(labHistoryPage);
        lblSelectLab->setObjectName("lblSelectLab");

        horizontalLayoutLabHistoryFilters->addWidget(lblSelectLab);

        comboSelectLab = new QComboBox(labHistoryPage);
        comboSelectLab->setObjectName("comboSelectLab");

        horizontalLayoutLabHistoryFilters->addWidget(comboSelectLab);

        btnExportHistory = new QPushButton(labHistoryPage);
        btnExportHistory->setObjectName("btnExportHistory");

        horizontalLayoutLabHistoryFilters->addWidget(btnExportHistory);


        verticalLayoutLabHistory->addLayout(horizontalLayoutLabHistoryFilters);

        formLayoutLabHistory = new QFormLayout();
        formLayoutLabHistory->setObjectName("formLayoutLabHistory");
        lblTotalContactHours = new QLabel(labHistoryPage);
        lblTotalContactHours->setObjectName("lblTotalContactHours");

        formLayoutLabHistory->setWidget(0, QFormLayout::ItemRole::LabelRole, lblTotalContactHours);

        lblTotalContactHoursValue = new QLabel(labHistoryPage);
        lblTotalContactHoursValue->setObjectName("lblTotalContactHoursValue");

        formLayoutLabHistory->setWidget(0, QFormLayout::ItemRole::FieldRole, lblTotalContactHoursValue);

        lblTotalLeaves = new QLabel(labHistoryPage);
        lblTotalLeaves->setObjectName("lblTotalLeaves");

        formLayoutLabHistory->setWidget(1, QFormLayout::ItemRole::LabelRole, lblTotalLeaves);

        lblTotalLeavesValue = new QLabel(labHistoryPage);
        lblTotalLeavesValue->setObjectName("lblTotalLeavesValue");

        formLayoutLabHistory->setWidget(1, QFormLayout::ItemRole::FieldRole, lblTotalLeavesValue);

        lblTotalMakeupSessions = new QLabel(labHistoryPage);
        lblTotalMakeupSessions->setObjectName("lblTotalMakeupSessions");

        formLayoutLabHistory->setWidget(2, QFormLayout::ItemRole::LabelRole, lblTotalMakeupSessions);

        lblTotalMakeupSessionsValue = new QLabel(labHistoryPage);
        lblTotalMakeupSessionsValue->setObjectName("lblTotalMakeupSessionsValue");

        formLayoutLabHistory->setWidget(2, QFormLayout::ItemRole::FieldRole, lblTotalMakeupSessionsValue);


        verticalLayoutLabHistory->addLayout(formLayoutLabHistory);

        tableLabHistory = new QTableWidget(labHistoryPage);
        tableLabHistory->setObjectName("tableLabHistory");

        verticalLayoutLabHistory->addWidget(tableLabHistory);

        stackedWidget->addWidget(labHistoryPage);
        makeupRequestsPage = new QWidget();
        makeupRequestsPage->setObjectName("makeupRequestsPage");
        verticalLayoutMakeupRequests = new QVBoxLayout(makeupRequestsPage);
        verticalLayoutMakeupRequests->setObjectName("verticalLayoutMakeupRequests");
        lblMakeupRequestsTitle = new QLabel(makeupRequestsPage);
        lblMakeupRequestsTitle->setObjectName("lblMakeupRequestsTitle");

        verticalLayoutMakeupRequests->addWidget(lblMakeupRequestsTitle);

        horizontalLayoutMakeupFilters = new QHBoxLayout();
        horizontalLayoutMakeupFilters->setObjectName("horizontalLayoutMakeupFilters");
        lblFilterStatus = new QLabel(makeupRequestsPage);
        lblFilterStatus->setObjectName("lblFilterStatus");

        horizontalLayoutMakeupFilters->addWidget(lblFilterStatus);

        comboFilterStatus = new QComboBox(makeupRequestsPage);
        comboFilterStatus->setObjectName("comboFilterStatus");

        horizontalLayoutMakeupFilters->addWidget(comboFilterStatus);

        btnExportRequests = new QPushButton(makeupRequestsPage);
        btnExportRequests->setObjectName("btnExportRequests");

        horizontalLayoutMakeupFilters->addWidget(btnExportRequests);


        verticalLayoutMakeupRequests->addLayout(horizontalLayoutMakeupFilters);

        tableMakeupRequests = new QTableWidget(makeupRequestsPage);
        tableMakeupRequests->setObjectName("tableMakeupRequests");

        verticalLayoutMakeupRequests->addWidget(tableMakeupRequests);

        stackedWidget->addWidget(makeupRequestsPage);

        horizontalLayout->addWidget(stackedWidget);

        HODMainWindow->setCentralWidget(centralWidget);

        retranslateUi(HODMainWindow);

        QMetaObject::connectSlotsByName(HODMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *HODMainWindow)
    {
        sidebarFrame->setStyleSheet(QCoreApplication::translate("HODMainWindow", "\n"
"        QFrame {\n"
"          background-color: #2C3E50;\n"
"          border-right: 2px solid #1ABC9C;\n"
"        }\n"
"        QPushButton {\n"
"          font-family: \"Segoe UI\";\n"
"          font-size: 14px;\n"
"          font-weight: 600;\n"
"          color: #ECF0F1;\n"
"          background-color: #34495E;\n"
"          border-radius: 6px;\n"
"          padding: 10px;\n"
"          margin: 4px 0;\n"
"          text-align: left;\n"
"        }\n"
"        QPushButton:hover {\n"
"          background-color: #1ABC9C;\n"
"          color: white;\n"
"        }\n"
"        QPushButton:pressed {\n"
"          background-color: #16A085;\n"
"          color: #FDFEFE;\n"
"        }\n"
"       ", nullptr));
        btnDashboard->setText(QCoreApplication::translate("HODMainWindow", "\360\237\223\212 Dashboard", nullptr));
        btnWeeklySchedule->setText(QCoreApplication::translate("HODMainWindow", "\360\237\223\205 Weekly Schedule", nullptr));
        btnWeeklyTimesheets->setText(QCoreApplication::translate("HODMainWindow", "\342\217\260 Weekly Timesheets", nullptr));
        btnLabHistory->setText(QCoreApplication::translate("HODMainWindow", "\360\237\223\210 Lab History", nullptr));
        btnMakeupRequests->setText(QCoreApplication::translate("HODMainWindow", "\360\237\223\235 Makeup Requests", nullptr));
        dashboardPage->setStyleSheet(QCoreApplication::translate("HODMainWindow", "background-color: #FFDDC1;", nullptr));
        lblDashboardTitle->setStyleSheet(QCoreApplication::translate("HODMainWindow", "font-family:\"Segoe UI\"; font-size:22px; font-weight:bold; color:#2C3E50;", nullptr));
        lblDashboardTitle->setText(QCoreApplication::translate("HODMainWindow", "\360\237\223\212 HOD Dashboard", nullptr));
        frameTotalLabs->setStyleSheet(QCoreApplication::translate("HODMainWindow", "background-color: white; border-radius: 8px; padding: 10px; border: 1px solid #ccc;", nullptr));
        lblTotalLabs->setStyleSheet(QCoreApplication::translate("HODMainWindow", "font-family:\"Segoe UI\"; font-size:16px; font-weight:bold; color:#2C3E50;", nullptr));
        lblTotalLabs->setText(QCoreApplication::translate("HODMainWindow", "Total Labs", nullptr));
        lblTotalLabsCount->setStyleSheet(QCoreApplication::translate("HODMainWindow", "font-family:\"Segoe UI\"; font-size:24px; font-weight:bold; color:#1ABC9C;", nullptr));
        lblTotalLabsCount->setText(QCoreApplication::translate("HODMainWindow", "25", nullptr));
        frameActiveLabs->setStyleSheet(QCoreApplication::translate("HODMainWindow", "background-color: white; border-radius: 8px; padding: 10px; border: 1px solid #ccc;", nullptr));
        lblActiveLabs->setStyleSheet(QCoreApplication::translate("HODMainWindow", "font-family:\"Segoe UI\"; font-size:16px; font-weight:bold; color:#2C3E50;", nullptr));
        lblActiveLabs->setText(QCoreApplication::translate("HODMainWindow", "Active Labs", nullptr));
        lblActiveLabsCount->setStyleSheet(QCoreApplication::translate("HODMainWindow", "font-family:\"Segoe UI\"; font-size:24px; font-weight:bold; color:#1ABC9C;", nullptr));
        lblActiveLabsCount->setText(QCoreApplication::translate("HODMainWindow", "20", nullptr));
        framePendingRequests->setStyleSheet(QCoreApplication::translate("HODMainWindow", "background-color: white; border-radius: 8px; padding: 10px; border: 1px solid #ccc;", nullptr));
        lblPendingRequests->setStyleSheet(QCoreApplication::translate("HODMainWindow", "font-family:\"Segoe UI\"; font-size:16px; font-weight:bold; color:#2C3E50;", nullptr));
        lblPendingRequests->setText(QCoreApplication::translate("HODMainWindow", "Pending Makeup Requests", nullptr));
        lblPendingRequestsCount->setStyleSheet(QCoreApplication::translate("HODMainWindow", "font-family:\"Segoe UI\"; font-size:24px; font-weight:bold; color:#E74C3C;", nullptr));
        lblPendingRequestsCount->setText(QCoreApplication::translate("HODMainWindow", "3", nullptr));
        weeklySchedulePage->setStyleSheet(QCoreApplication::translate("HODMainWindow", "background-color: #C1FFD7;", nullptr));
        lblWeeklyScheduleTitle->setStyleSheet(QCoreApplication::translate("HODMainWindow", "font-family:\"Segoe UI\"; font-size:22px; font-weight:bold; color:#2C3E50;", nullptr));
        lblWeeklyScheduleTitle->setText(QCoreApplication::translate("HODMainWindow", "\360\237\223\205 Weekly Lab Schedule", nullptr));
        lblFilterWeek->setText(QCoreApplication::translate("HODMainWindow", "Select Week:", nullptr));
        calendarWeekSchedule->setStyleSheet(QCoreApplication::translate("HODMainWindow", "background:white; border-radius:4px; padding:4px; border:1px solid #ccc;", nullptr));
        btnExportSchedule->setText(QCoreApplication::translate("HODMainWindow", "Export to PDF", nullptr));
        tableWeeklySchedule->setStyleSheet(QCoreApplication::translate("HODMainWindow", "background:white; border-radius:8px; padding:6px; border:1px solid #ccc;", nullptr));
        weeklyTimesheetsPage->setStyleSheet(QCoreApplication::translate("HODMainWindow", "background-color: #C1E1FF;", nullptr));
        lblWeeklyTimesheetsTitle->setStyleSheet(QCoreApplication::translate("HODMainWindow", "font-family:\"Segoe UI\"; font-size:22px; font-weight:bold; color:#2C3E50;", nullptr));
        lblWeeklyTimesheetsTitle->setText(QCoreApplication::translate("HODMainWindow", "\342\217\260 Weekly Timesheets", nullptr));
        lblFilterTimesheetWeek->setText(QCoreApplication::translate("HODMainWindow", "Select Week:", nullptr));
        calendarWeekTimesheets->setStyleSheet(QCoreApplication::translate("HODMainWindow", "background:white; border-radius:4px; padding:4px; border:1px solid #ccc;", nullptr));
        btnExportTimesheets->setText(QCoreApplication::translate("HODMainWindow", "Export to PDF", nullptr));
        tableWeeklyTimesheets->setStyleSheet(QCoreApplication::translate("HODMainWindow", "background:white; border-radius:8px; padding:6px; border:1px solid #ccc;", nullptr));
        labHistoryPage->setStyleSheet(QCoreApplication::translate("HODMainWindow", "background-color: #FFD1DC;", nullptr));
        lblLabHistoryTitle->setStyleSheet(QCoreApplication::translate("HODMainWindow", "font-family:\"Segoe UI\"; font-size:22px; font-weight:bold; color:#2C3E50;", nullptr));
        lblLabHistoryTitle->setText(QCoreApplication::translate("HODMainWindow", "\360\237\223\210 Lab History", nullptr));
        lblSelectLab->setText(QCoreApplication::translate("HODMainWindow", "Select Lab:", nullptr));
        comboSelectLab->setStyleSheet(QCoreApplication::translate("HODMainWindow", "background:white; border-radius:4px; padding:4px; border:1px solid #ccc;", nullptr));
        btnExportHistory->setText(QCoreApplication::translate("HODMainWindow", "Export to PDF", nullptr));
        lblTotalContactHours->setText(QCoreApplication::translate("HODMainWindow", "Total Contact Hours:", nullptr));
        lblTotalContactHoursValue->setText(QString());
        lblTotalLeaves->setText(QCoreApplication::translate("HODMainWindow", "Total Leaves:", nullptr));
        lblTotalLeavesValue->setText(QString());
        lblTotalMakeupSessions->setText(QCoreApplication::translate("HODMainWindow", "Total Makeup Sessions:", nullptr));
        lblTotalMakeupSessionsValue->setText(QString());
        tableLabHistory->setStyleSheet(QCoreApplication::translate("HODMainWindow", "background:white; border-radius:8px; padding:6px; border:1px solid #ccc;", nullptr));
        makeupRequestsPage->setStyleSheet(QCoreApplication::translate("HODMainWindow", "background-color: #FFFAC1;", nullptr));
        lblMakeupRequestsTitle->setStyleSheet(QCoreApplication::translate("HODMainWindow", "font-family:\"Segoe UI\"; font-size:22px; font-weight:bold; color:#2C3E50;", nullptr));
        lblMakeupRequestsTitle->setText(QCoreApplication::translate("HODMainWindow", "\360\237\223\235 Makeup Lab Requests", nullptr));
        lblFilterStatus->setText(QCoreApplication::translate("HODMainWindow", "Status:", nullptr));
        comboFilterStatus->setStyleSheet(QCoreApplication::translate("HODMainWindow", "background:white; border-radius:4px; padding:4px; border:1px solid #ccc;", nullptr));
        btnExportRequests->setText(QCoreApplication::translate("HODMainWindow", "Export to PDF", nullptr));
        tableMakeupRequests->setStyleSheet(QCoreApplication::translate("HODMainWindow", "background:white; border-radius:8px; padding:6px; border:1px solid #ccc;", nullptr));
        (void)HODMainWindow;
    } // retranslateUi

};

namespace Ui {
    class HODMainWindow: public Ui_HODMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOD_MAINWINDOW_H
