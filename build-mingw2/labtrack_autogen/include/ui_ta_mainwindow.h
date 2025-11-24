/********************************************************************************
** Form generated from reading UI file 'ta_mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TA_MAINWINDOW_H
#define UI_TA_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TAMainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QFrame *sidebarFrame;
    QVBoxLayout *verticalLayoutSidebar;
    QPushButton *btnDashboard;
    QPushButton *btnMyLabs;
    QPushButton *btnLabDetails;
    QPushButton *btnTimesheet;
    QPushButton *btnNotifications;
    QPushButton *btnProfile;
    QStackedWidget *stackedWidget;
    QWidget *dashboardPage;
    QVBoxLayout *verticalLayoutDashboard;
    QLabel *lblDashboardTitle;
    QHBoxLayout *horizontalLayoutCards;
    QFrame *frameAssignedLabs;
    QVBoxLayout *verticalLayoutAssignedLabs;
    QLabel *lblAssignedLabs;
    QLabel *lblAssignedLabsCount;
    QFrame *frameTodaysSessions;
    QVBoxLayout *verticalLayoutTodaysSessions;
    QLabel *lblTodaysSessions;
    QLabel *lblTodaysSessionsCount;
    QFrame *frameNotifications;
    QVBoxLayout *verticalLayoutNotifications;
    QLabel *lblNotifications;
    QLabel *lblNotificationsCount;
    QWidget *myLabsPage;
    QVBoxLayout *verticalLayoutMyLabs;
    QLabel *lblMyLabsTitle;
    QTableWidget *tableMyLabs;
    QWidget *labDetailsPage;
    QVBoxLayout *verticalLayoutLabDetails;
    QLabel *lblLabDetailsTitle;
    QFormLayout *formLayoutLabDetails;
    QLabel *lblLabName;
    QLabel *lblLabNameValue;
    QLabel *lblInstructor;
    QLabel *lblInstructorValue;
    QLabel *lblTimings;
    QLabel *lblTimingsValue;
    QLabel *lblVenue;
    QLabel *lblVenueValue;
    QLabel *lblOtherTAs;
    QLabel *lblOtherTAsValue;
    QLabel *lblUpcomingSessions;
    QLabel *lblUpcomingSessionsValue;
    QWidget *timesheetPage;
    QVBoxLayout *verticalLayoutTimesheet;
    QLabel *lblTimesheetTitle;
    QTableWidget *tableTimesheet;
    QWidget *notificationsPage;
    QVBoxLayout *verticalLayoutNotifications1;
    QLabel *lblNotificationsTitle;
    QListWidget *listNotifications;
    QWidget *profilePage;
    QVBoxLayout *verticalLayoutProfile;
    QLabel *lblProfileTitle;
    QFormLayout *formLayoutProfile;
    QLabel *lblName;
    QLineEdit *txtName;
    QLabel *lblEmail;
    QLineEdit *txtEmail;
    QLabel *lblPhone;
    QLineEdit *txtPhone;

    void setupUi(QMainWindow *TAMainWindow)
    {
        if (TAMainWindow->objectName().isEmpty())
            TAMainWindow->setObjectName("TAMainWindow");
        TAMainWindow->resize(900, 600);
        centralWidget = new QWidget(TAMainWindow);
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

        btnMyLabs = new QPushButton(sidebarFrame);
        btnMyLabs->setObjectName("btnMyLabs");
        btnMyLabs->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        verticalLayoutSidebar->addWidget(btnMyLabs);

        btnLabDetails = new QPushButton(sidebarFrame);
        btnLabDetails->setObjectName("btnLabDetails");
        btnLabDetails->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        verticalLayoutSidebar->addWidget(btnLabDetails);

        btnTimesheet = new QPushButton(sidebarFrame);
        btnTimesheet->setObjectName("btnTimesheet");
        btnTimesheet->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        verticalLayoutSidebar->addWidget(btnTimesheet);

        btnNotifications = new QPushButton(sidebarFrame);
        btnNotifications->setObjectName("btnNotifications");
        btnNotifications->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        verticalLayoutSidebar->addWidget(btnNotifications);

        btnProfile = new QPushButton(sidebarFrame);
        btnProfile->setObjectName("btnProfile");
        btnProfile->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        verticalLayoutSidebar->addWidget(btnProfile);


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
        frameAssignedLabs = new QFrame(dashboardPage);
        frameAssignedLabs->setObjectName("frameAssignedLabs");
        verticalLayoutAssignedLabs = new QVBoxLayout(frameAssignedLabs);
        verticalLayoutAssignedLabs->setObjectName("verticalLayoutAssignedLabs");
        lblAssignedLabs = new QLabel(frameAssignedLabs);
        lblAssignedLabs->setObjectName("lblAssignedLabs");

        verticalLayoutAssignedLabs->addWidget(lblAssignedLabs);

        lblAssignedLabsCount = new QLabel(frameAssignedLabs);
        lblAssignedLabsCount->setObjectName("lblAssignedLabsCount");

        verticalLayoutAssignedLabs->addWidget(lblAssignedLabsCount);


        horizontalLayoutCards->addWidget(frameAssignedLabs);

        frameTodaysSessions = new QFrame(dashboardPage);
        frameTodaysSessions->setObjectName("frameTodaysSessions");
        verticalLayoutTodaysSessions = new QVBoxLayout(frameTodaysSessions);
        verticalLayoutTodaysSessions->setObjectName("verticalLayoutTodaysSessions");
        lblTodaysSessions = new QLabel(frameTodaysSessions);
        lblTodaysSessions->setObjectName("lblTodaysSessions");

        verticalLayoutTodaysSessions->addWidget(lblTodaysSessions);

        lblTodaysSessionsCount = new QLabel(frameTodaysSessions);
        lblTodaysSessionsCount->setObjectName("lblTodaysSessionsCount");

        verticalLayoutTodaysSessions->addWidget(lblTodaysSessionsCount);


        horizontalLayoutCards->addWidget(frameTodaysSessions);

        frameNotifications = new QFrame(dashboardPage);
        frameNotifications->setObjectName("frameNotifications");
        verticalLayoutNotifications = new QVBoxLayout(frameNotifications);
        verticalLayoutNotifications->setObjectName("verticalLayoutNotifications");
        lblNotifications = new QLabel(frameNotifications);
        lblNotifications->setObjectName("lblNotifications");

        verticalLayoutNotifications->addWidget(lblNotifications);

        lblNotificationsCount = new QLabel(frameNotifications);
        lblNotificationsCount->setObjectName("lblNotificationsCount");

        verticalLayoutNotifications->addWidget(lblNotificationsCount);


        horizontalLayoutCards->addWidget(frameNotifications);


        verticalLayoutDashboard->addLayout(horizontalLayoutCards);

        stackedWidget->addWidget(dashboardPage);
        myLabsPage = new QWidget();
        myLabsPage->setObjectName("myLabsPage");
        verticalLayoutMyLabs = new QVBoxLayout(myLabsPage);
        verticalLayoutMyLabs->setObjectName("verticalLayoutMyLabs");
        lblMyLabsTitle = new QLabel(myLabsPage);
        lblMyLabsTitle->setObjectName("lblMyLabsTitle");

        verticalLayoutMyLabs->addWidget(lblMyLabsTitle);

        tableMyLabs = new QTableWidget(myLabsPage);
        tableMyLabs->setObjectName("tableMyLabs");

        verticalLayoutMyLabs->addWidget(tableMyLabs);

        stackedWidget->addWidget(myLabsPage);
        labDetailsPage = new QWidget();
        labDetailsPage->setObjectName("labDetailsPage");
        verticalLayoutLabDetails = new QVBoxLayout(labDetailsPage);
        verticalLayoutLabDetails->setObjectName("verticalLayoutLabDetails");
        lblLabDetailsTitle = new QLabel(labDetailsPage);
        lblLabDetailsTitle->setObjectName("lblLabDetailsTitle");

        verticalLayoutLabDetails->addWidget(lblLabDetailsTitle);

        formLayoutLabDetails = new QFormLayout();
        formLayoutLabDetails->setObjectName("formLayoutLabDetails");
        lblLabName = new QLabel(labDetailsPage);
        lblLabName->setObjectName("lblLabName");

        formLayoutLabDetails->setWidget(0, QFormLayout::ItemRole::LabelRole, lblLabName);

        lblLabNameValue = new QLabel(labDetailsPage);
        lblLabNameValue->setObjectName("lblLabNameValue");

        formLayoutLabDetails->setWidget(0, QFormLayout::ItemRole::FieldRole, lblLabNameValue);

        lblInstructor = new QLabel(labDetailsPage);
        lblInstructor->setObjectName("lblInstructor");

        formLayoutLabDetails->setWidget(1, QFormLayout::ItemRole::LabelRole, lblInstructor);

        lblInstructorValue = new QLabel(labDetailsPage);
        lblInstructorValue->setObjectName("lblInstructorValue");

        formLayoutLabDetails->setWidget(1, QFormLayout::ItemRole::FieldRole, lblInstructorValue);

        lblTimings = new QLabel(labDetailsPage);
        lblTimings->setObjectName("lblTimings");

        formLayoutLabDetails->setWidget(2, QFormLayout::ItemRole::LabelRole, lblTimings);

        lblTimingsValue = new QLabel(labDetailsPage);
        lblTimingsValue->setObjectName("lblTimingsValue");

        formLayoutLabDetails->setWidget(2, QFormLayout::ItemRole::FieldRole, lblTimingsValue);

        lblVenue = new QLabel(labDetailsPage);
        lblVenue->setObjectName("lblVenue");

        formLayoutLabDetails->setWidget(3, QFormLayout::ItemRole::LabelRole, lblVenue);

        lblVenueValue = new QLabel(labDetailsPage);
        lblVenueValue->setObjectName("lblVenueValue");

        formLayoutLabDetails->setWidget(3, QFormLayout::ItemRole::FieldRole, lblVenueValue);

        lblOtherTAs = new QLabel(labDetailsPage);
        lblOtherTAs->setObjectName("lblOtherTAs");

        formLayoutLabDetails->setWidget(4, QFormLayout::ItemRole::LabelRole, lblOtherTAs);

        lblOtherTAsValue = new QLabel(labDetailsPage);
        lblOtherTAsValue->setObjectName("lblOtherTAsValue");

        formLayoutLabDetails->setWidget(4, QFormLayout::ItemRole::FieldRole, lblOtherTAsValue);

        lblUpcomingSessions = new QLabel(labDetailsPage);
        lblUpcomingSessions->setObjectName("lblUpcomingSessions");

        formLayoutLabDetails->setWidget(5, QFormLayout::ItemRole::LabelRole, lblUpcomingSessions);

        lblUpcomingSessionsValue = new QLabel(labDetailsPage);
        lblUpcomingSessionsValue->setObjectName("lblUpcomingSessionsValue");

        formLayoutLabDetails->setWidget(5, QFormLayout::ItemRole::FieldRole, lblUpcomingSessionsValue);


        verticalLayoutLabDetails->addLayout(formLayoutLabDetails);

        stackedWidget->addWidget(labDetailsPage);
        timesheetPage = new QWidget();
        timesheetPage->setObjectName("timesheetPage");
        verticalLayoutTimesheet = new QVBoxLayout(timesheetPage);
        verticalLayoutTimesheet->setObjectName("verticalLayoutTimesheet");
        lblTimesheetTitle = new QLabel(timesheetPage);
        lblTimesheetTitle->setObjectName("lblTimesheetTitle");

        verticalLayoutTimesheet->addWidget(lblTimesheetTitle);

        tableTimesheet = new QTableWidget(timesheetPage);
        tableTimesheet->setObjectName("tableTimesheet");

        verticalLayoutTimesheet->addWidget(tableTimesheet);

        stackedWidget->addWidget(timesheetPage);
        notificationsPage = new QWidget();
        notificationsPage->setObjectName("notificationsPage");
        verticalLayoutNotifications1 = new QVBoxLayout(notificationsPage);
        verticalLayoutNotifications1->setObjectName("verticalLayoutNotifications1");
        lblNotificationsTitle = new QLabel(notificationsPage);
        lblNotificationsTitle->setObjectName("lblNotificationsTitle");

        verticalLayoutNotifications1->addWidget(lblNotificationsTitle);

        listNotifications = new QListWidget(notificationsPage);
        listNotifications->setObjectName("listNotifications");

        verticalLayoutNotifications1->addWidget(listNotifications);

        stackedWidget->addWidget(notificationsPage);
        profilePage = new QWidget();
        profilePage->setObjectName("profilePage");
        verticalLayoutProfile = new QVBoxLayout(profilePage);
        verticalLayoutProfile->setObjectName("verticalLayoutProfile");
        lblProfileTitle = new QLabel(profilePage);
        lblProfileTitle->setObjectName("lblProfileTitle");

        verticalLayoutProfile->addWidget(lblProfileTitle);

        formLayoutProfile = new QFormLayout();
        formLayoutProfile->setObjectName("formLayoutProfile");
        lblName = new QLabel(profilePage);
        lblName->setObjectName("lblName");

        formLayoutProfile->setWidget(0, QFormLayout::ItemRole::LabelRole, lblName);

        txtName = new QLineEdit(profilePage);
        txtName->setObjectName("txtName");

        formLayoutProfile->setWidget(0, QFormLayout::ItemRole::FieldRole, txtName);

        lblEmail = new QLabel(profilePage);
        lblEmail->setObjectName("lblEmail");

        formLayoutProfile->setWidget(1, QFormLayout::ItemRole::LabelRole, lblEmail);

        txtEmail = new QLineEdit(profilePage);
        txtEmail->setObjectName("txtEmail");

        formLayoutProfile->setWidget(1, QFormLayout::ItemRole::FieldRole, txtEmail);

        lblPhone = new QLabel(profilePage);
        lblPhone->setObjectName("lblPhone");

        formLayoutProfile->setWidget(2, QFormLayout::ItemRole::LabelRole, lblPhone);

        txtPhone = new QLineEdit(profilePage);
        txtPhone->setObjectName("txtPhone");

        formLayoutProfile->setWidget(2, QFormLayout::ItemRole::FieldRole, txtPhone);


        verticalLayoutProfile->addLayout(formLayoutProfile);

        stackedWidget->addWidget(profilePage);

        horizontalLayout->addWidget(stackedWidget);

        TAMainWindow->setCentralWidget(centralWidget);

        retranslateUi(TAMainWindow);

        QMetaObject::connectSlotsByName(TAMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *TAMainWindow)
    {
        sidebarFrame->setStyleSheet(QCoreApplication::translate("TAMainWindow", "\n"
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
        btnDashboard->setText(QCoreApplication::translate("TAMainWindow", "\360\237\223\212 Dashboard", nullptr));
        btnMyLabs->setText(QCoreApplication::translate("TAMainWindow", "\360\237\247\252 My Labs", nullptr));
        btnLabDetails->setText(QCoreApplication::translate("TAMainWindow", "\360\237\223\213 Lab Details", nullptr));
        btnTimesheet->setText(QCoreApplication::translate("TAMainWindow", "\342\217\260 Timesheet", nullptr));
        btnNotifications->setText(QCoreApplication::translate("TAMainWindow", "\360\237\224\224 Notifications", nullptr));
        btnProfile->setText(QCoreApplication::translate("TAMainWindow", "\360\237\221\244 Profile", nullptr));
        dashboardPage->setStyleSheet(QCoreApplication::translate("TAMainWindow", "background-color: #FFDDC1;", nullptr));
        lblDashboardTitle->setStyleSheet(QCoreApplication::translate("TAMainWindow", "font-family:\"Segoe UI\"; font-size:22px; font-weight:bold; color:#2C3E50;", nullptr));
        lblDashboardTitle->setText(QCoreApplication::translate("TAMainWindow", "\360\237\223\212 Dashboard", nullptr));
        frameAssignedLabs->setStyleSheet(QCoreApplication::translate("TAMainWindow", "background-color: white; border-radius: 8px; padding: 10px; border: 1px solid #ccc;", nullptr));
        lblAssignedLabs->setStyleSheet(QCoreApplication::translate("TAMainWindow", "font-family:\"Segoe UI\"; font-size:16px; font-weight:bold; color:#2C3E50;", nullptr));
        lblAssignedLabs->setText(QCoreApplication::translate("TAMainWindow", "Assigned Labs", nullptr));
        lblAssignedLabsCount->setStyleSheet(QCoreApplication::translate("TAMainWindow", "font-family:\"Segoe UI\"; font-size:24px; font-weight:bold; color:#1ABC9C;", nullptr));
        lblAssignedLabsCount->setText(QCoreApplication::translate("TAMainWindow", "5", nullptr));
        frameTodaysSessions->setStyleSheet(QCoreApplication::translate("TAMainWindow", "background-color: white; border-radius: 8px; padding: 10px; border: 1px solid #ccc;", nullptr));
        lblTodaysSessions->setStyleSheet(QCoreApplication::translate("TAMainWindow", "font-family:\"Segoe UI\"; font-size:16px; font-weight:bold; color:#2C3E50;", nullptr));
        lblTodaysSessions->setText(QCoreApplication::translate("TAMainWindow", "Today's Sessions", nullptr));
        lblTodaysSessionsCount->setStyleSheet(QCoreApplication::translate("TAMainWindow", "font-family:\"Segoe UI\"; font-size:24px; font-weight:bold; color:#1ABC9C;", nullptr));
        lblTodaysSessionsCount->setText(QCoreApplication::translate("TAMainWindow", "2", nullptr));
        frameNotifications->setStyleSheet(QCoreApplication::translate("TAMainWindow", "background-color: white; border-radius: 8px; padding: 10px; border: 1px solid #ccc;", nullptr));
        lblNotifications->setStyleSheet(QCoreApplication::translate("TAMainWindow", "font-family:\"Segoe UI\"; font-size:16px; font-weight:bold; color:#2C3E50;", nullptr));
        lblNotifications->setText(QCoreApplication::translate("TAMainWindow", "Notifications", nullptr));
        lblNotificationsCount->setStyleSheet(QCoreApplication::translate("TAMainWindow", "font-family:\"Segoe UI\"; font-size:24px; font-weight:bold; color:#E74C3C;", nullptr));
        lblNotificationsCount->setText(QCoreApplication::translate("TAMainWindow", "3", nullptr));
        myLabsPage->setStyleSheet(QCoreApplication::translate("TAMainWindow", "background-color: #C1FFD7;", nullptr));
        lblMyLabsTitle->setStyleSheet(QCoreApplication::translate("TAMainWindow", "font-family:\"Segoe UI\"; font-size:22px; font-weight:bold; color:#2C3E50;", nullptr));
        lblMyLabsTitle->setText(QCoreApplication::translate("TAMainWindow", "\360\237\247\252 My Labs", nullptr));
        tableMyLabs->setStyleSheet(QCoreApplication::translate("TAMainWindow", "background:white; border-radius:8px; padding:6px; border:1px solid #ccc;", nullptr));
        labDetailsPage->setStyleSheet(QCoreApplication::translate("TAMainWindow", "background-color: #C1E1FF;", nullptr));
        lblLabDetailsTitle->setStyleSheet(QCoreApplication::translate("TAMainWindow", "font-family:\"Segoe UI\"; font-size:22px; font-weight:bold; color:#2C3E50;", nullptr));
        lblLabDetailsTitle->setText(QCoreApplication::translate("TAMainWindow", "\360\237\223\213 Lab Details", nullptr));
        lblLabName->setText(QCoreApplication::translate("TAMainWindow", "Lab Name:", nullptr));
        lblLabNameValue->setText(QString());
        lblInstructor->setText(QCoreApplication::translate("TAMainWindow", "Instructor:", nullptr));
        lblInstructorValue->setText(QString());
        lblTimings->setText(QCoreApplication::translate("TAMainWindow", "Timings:", nullptr));
        lblTimingsValue->setText(QString());
        lblVenue->setText(QCoreApplication::translate("TAMainWindow", "Venue:", nullptr));
        lblVenueValue->setText(QString());
        lblOtherTAs->setText(QCoreApplication::translate("TAMainWindow", "Other TAs:", nullptr));
        lblOtherTAsValue->setText(QString());
        lblUpcomingSessions->setText(QCoreApplication::translate("TAMainWindow", "Upcoming Sessions:", nullptr));
        lblUpcomingSessionsValue->setText(QString());
        timesheetPage->setStyleSheet(QCoreApplication::translate("TAMainWindow", "background-color: #FFD1DC;", nullptr));
        lblTimesheetTitle->setStyleSheet(QCoreApplication::translate("TAMainWindow", "font-family:\"Segoe UI\"; font-size:22px; font-weight:bold; color:#2C3E50;", nullptr));
        lblTimesheetTitle->setText(QCoreApplication::translate("TAMainWindow", "\342\217\260 Timesheet", nullptr));
        tableTimesheet->setStyleSheet(QCoreApplication::translate("TAMainWindow", "background:white; border-radius:8px; padding:6px; border:1px solid #ccc;", nullptr));
        notificationsPage->setStyleSheet(QCoreApplication::translate("TAMainWindow", "background-color: #FFFAC1;", nullptr));
        lblNotificationsTitle->setStyleSheet(QCoreApplication::translate("TAMainWindow", "font-family:\"Segoe UI\"; font-size:22px; font-weight:bold; color:#2C3E50;", nullptr));
        lblNotificationsTitle->setText(QCoreApplication::translate("TAMainWindow", "\360\237\224\224 Notifications", nullptr));
        listNotifications->setStyleSheet(QCoreApplication::translate("TAMainWindow", "background:white; border-radius:8px; padding:6px; border:1px solid #ccc;", nullptr));
        profilePage->setStyleSheet(QCoreApplication::translate("TAMainWindow", "background-color: #E1C1FF;", nullptr));
        lblProfileTitle->setStyleSheet(QCoreApplication::translate("TAMainWindow", "font-family:\"Segoe UI\"; font-size:22px; font-weight:bold; color:#2C3E50;", nullptr));
        lblProfileTitle->setText(QCoreApplication::translate("TAMainWindow", "\360\237\221\244 Profile", nullptr));
        lblName->setText(QCoreApplication::translate("TAMainWindow", "Name:", nullptr));
        txtName->setStyleSheet(QCoreApplication::translate("TAMainWindow", "background:white; border-radius:4px; padding:4px; border:1px solid #ccc;", nullptr));
        lblEmail->setText(QCoreApplication::translate("TAMainWindow", "Email:", nullptr));
        txtEmail->setStyleSheet(QCoreApplication::translate("TAMainWindow", "background:white; border-radius:4px; padding:4px; border:1px solid #ccc;", nullptr));
        lblPhone->setText(QCoreApplication::translate("TAMainWindow", "Phone:", nullptr));
        txtPhone->setStyleSheet(QCoreApplication::translate("TAMainWindow", "background:white; border-radius:4px; padding:4px; border:1px solid #ccc;", nullptr));
        (void)TAMainWindow;
    } // retranslateUi

};

namespace Ui {
    class TAMainWindow: public Ui_TAMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TA_MAINWINDOW_H
