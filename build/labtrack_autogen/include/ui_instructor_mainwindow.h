/********************************************************************************
** Form generated from reading UI file 'instructor_mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSTRUCTOR_MAINWINDOW_H
#define UI_INSTRUCTOR_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
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

class Ui_InstructorMainWindow
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
    QFrame *frameUpcomingSessions;
    QVBoxLayout *verticalLayoutUpcomingSessions;
    QLabel *lblUpcomingSessions;
    QLabel *lblUpcomingSessionsCount;
    QFrame *framePendingNotifications;
    QVBoxLayout *verticalLayoutPendingNotifications;
    QLabel *lblPendingNotifications;
    QLabel *lblPendingNotificationsCount;
    QWidget *myLabsPage;
    QVBoxLayout *verticalLayoutMyLabs;
    QLabel *lblMyLabsTitle;
    QTableWidget *tableMyLabs;
    QWidget *labDetailsPage;
    QVBoxLayout *verticalLayoutLabDetails;
    QLabel *lblLabDetailsTitle;
    QHBoxLayout *horizontalLayoutLabDetails;
    QLabel *lblSelectLab;
    QComboBox *comboSelectLab;
    QFormLayout *formLayoutLabDetails;
    QLabel *lblLabName;
    QLabel *lblLabNameValue;
    QLabel *lblTimings;
    QLabel *lblTimingsValue;
    QLabel *lblVenue;
    QLabel *lblVenueValue;
    QLabel *lblAssignedTAs;
    QLabel *lblAssignedTAsValue;
    QWidget *timesheetPage;
    QVBoxLayout *verticalLayoutTimesheet;
    QLabel *lblTimesheetTitle;
    QHBoxLayout *horizontalLayoutTimesheet;
    QLabel *lblSelectLabTimesheet;
    QComboBox *comboSelectLabTimesheet;
    QTableWidget *tableTimesheet;
    QWidget *notificationsPage;
    QVBoxLayout *verticalLayoutNotifications;
    QLabel *lblNotificationsTitle;
    QListWidget *listNotifications;
    QWidget *profilePage;
    QVBoxLayout *verticalLayoutProfile;
    QLabel *lblProfileTitle;
    QFormLayout *formLayoutProfile;
    QLabel *lblName;
    QLineEdit *lineEditName;
    QLabel *lblEmail;
    QLineEdit *lineEditEmail;
    QLabel *lblPhone;
    QLineEdit *lineEditPhone;
    QPushButton *btnUpdateProfile;

    void setupUi(QMainWindow *InstructorMainWindow)
    {
        if (InstructorMainWindow->objectName().isEmpty())
            InstructorMainWindow->setObjectName("InstructorMainWindow");
        InstructorMainWindow->resize(1000, 700);
        centralWidget = new QWidget(InstructorMainWindow);
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

        frameUpcomingSessions = new QFrame(dashboardPage);
        frameUpcomingSessions->setObjectName("frameUpcomingSessions");
        verticalLayoutUpcomingSessions = new QVBoxLayout(frameUpcomingSessions);
        verticalLayoutUpcomingSessions->setObjectName("verticalLayoutUpcomingSessions");
        lblUpcomingSessions = new QLabel(frameUpcomingSessions);
        lblUpcomingSessions->setObjectName("lblUpcomingSessions");

        verticalLayoutUpcomingSessions->addWidget(lblUpcomingSessions);

        lblUpcomingSessionsCount = new QLabel(frameUpcomingSessions);
        lblUpcomingSessionsCount->setObjectName("lblUpcomingSessionsCount");

        verticalLayoutUpcomingSessions->addWidget(lblUpcomingSessionsCount);


        horizontalLayoutCards->addWidget(frameUpcomingSessions);

        framePendingNotifications = new QFrame(dashboardPage);
        framePendingNotifications->setObjectName("framePendingNotifications");
        verticalLayoutPendingNotifications = new QVBoxLayout(framePendingNotifications);
        verticalLayoutPendingNotifications->setObjectName("verticalLayoutPendingNotifications");
        lblPendingNotifications = new QLabel(framePendingNotifications);
        lblPendingNotifications->setObjectName("lblPendingNotifications");

        verticalLayoutPendingNotifications->addWidget(lblPendingNotifications);

        lblPendingNotificationsCount = new QLabel(framePendingNotifications);
        lblPendingNotificationsCount->setObjectName("lblPendingNotificationsCount");

        verticalLayoutPendingNotifications->addWidget(lblPendingNotificationsCount);


        horizontalLayoutCards->addWidget(framePendingNotifications);


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

        horizontalLayoutLabDetails = new QHBoxLayout();
        horizontalLayoutLabDetails->setObjectName("horizontalLayoutLabDetails");
        lblSelectLab = new QLabel(labDetailsPage);
        lblSelectLab->setObjectName("lblSelectLab");

        horizontalLayoutLabDetails->addWidget(lblSelectLab);

        comboSelectLab = new QComboBox(labDetailsPage);
        comboSelectLab->setObjectName("comboSelectLab");

        horizontalLayoutLabDetails->addWidget(comboSelectLab);


        verticalLayoutLabDetails->addLayout(horizontalLayoutLabDetails);

        formLayoutLabDetails = new QFormLayout();
        formLayoutLabDetails->setObjectName("formLayoutLabDetails");
        lblLabName = new QLabel(labDetailsPage);
        lblLabName->setObjectName("lblLabName");

        formLayoutLabDetails->setWidget(0, QFormLayout::ItemRole::LabelRole, lblLabName);

        lblLabNameValue = new QLabel(labDetailsPage);
        lblLabNameValue->setObjectName("lblLabNameValue");

        formLayoutLabDetails->setWidget(0, QFormLayout::ItemRole::FieldRole, lblLabNameValue);

        lblTimings = new QLabel(labDetailsPage);
        lblTimings->setObjectName("lblTimings");

        formLayoutLabDetails->setWidget(1, QFormLayout::ItemRole::LabelRole, lblTimings);

        lblTimingsValue = new QLabel(labDetailsPage);
        lblTimingsValue->setObjectName("lblTimingsValue");

        formLayoutLabDetails->setWidget(1, QFormLayout::ItemRole::FieldRole, lblTimingsValue);

        lblVenue = new QLabel(labDetailsPage);
        lblVenue->setObjectName("lblVenue");

        formLayoutLabDetails->setWidget(2, QFormLayout::ItemRole::LabelRole, lblVenue);

        lblVenueValue = new QLabel(labDetailsPage);
        lblVenueValue->setObjectName("lblVenueValue");

        formLayoutLabDetails->setWidget(2, QFormLayout::ItemRole::FieldRole, lblVenueValue);

        lblAssignedTAs = new QLabel(labDetailsPage);
        lblAssignedTAs->setObjectName("lblAssignedTAs");

        formLayoutLabDetails->setWidget(3, QFormLayout::ItemRole::LabelRole, lblAssignedTAs);

        lblAssignedTAsValue = new QLabel(labDetailsPage);
        lblAssignedTAsValue->setObjectName("lblAssignedTAsValue");

        formLayoutLabDetails->setWidget(3, QFormLayout::ItemRole::FieldRole, lblAssignedTAsValue);


        verticalLayoutLabDetails->addLayout(formLayoutLabDetails);

        stackedWidget->addWidget(labDetailsPage);
        timesheetPage = new QWidget();
        timesheetPage->setObjectName("timesheetPage");
        verticalLayoutTimesheet = new QVBoxLayout(timesheetPage);
        verticalLayoutTimesheet->setObjectName("verticalLayoutTimesheet");
        lblTimesheetTitle = new QLabel(timesheetPage);
        lblTimesheetTitle->setObjectName("lblTimesheetTitle");

        verticalLayoutTimesheet->addWidget(lblTimesheetTitle);

        horizontalLayoutTimesheet = new QHBoxLayout();
        horizontalLayoutTimesheet->setObjectName("horizontalLayoutTimesheet");
        lblSelectLabTimesheet = new QLabel(timesheetPage);
        lblSelectLabTimesheet->setObjectName("lblSelectLabTimesheet");

        horizontalLayoutTimesheet->addWidget(lblSelectLabTimesheet);

        comboSelectLabTimesheet = new QComboBox(timesheetPage);
        comboSelectLabTimesheet->setObjectName("comboSelectLabTimesheet");

        horizontalLayoutTimesheet->addWidget(comboSelectLabTimesheet);


        verticalLayoutTimesheet->addLayout(horizontalLayoutTimesheet);

        tableTimesheet = new QTableWidget(timesheetPage);
        tableTimesheet->setObjectName("tableTimesheet");

        verticalLayoutTimesheet->addWidget(tableTimesheet);

        stackedWidget->addWidget(timesheetPage);
        notificationsPage = new QWidget();
        notificationsPage->setObjectName("notificationsPage");
        verticalLayoutNotifications = new QVBoxLayout(notificationsPage);
        verticalLayoutNotifications->setObjectName("verticalLayoutNotifications");
        lblNotificationsTitle = new QLabel(notificationsPage);
        lblNotificationsTitle->setObjectName("lblNotificationsTitle");

        verticalLayoutNotifications->addWidget(lblNotificationsTitle);

        listNotifications = new QListWidget(notificationsPage);
        listNotifications->setObjectName("listNotifications");

        verticalLayoutNotifications->addWidget(listNotifications);

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

        lineEditName = new QLineEdit(profilePage);
        lineEditName->setObjectName("lineEditName");

        formLayoutProfile->setWidget(0, QFormLayout::ItemRole::FieldRole, lineEditName);

        lblEmail = new QLabel(profilePage);
        lblEmail->setObjectName("lblEmail");

        formLayoutProfile->setWidget(1, QFormLayout::ItemRole::LabelRole, lblEmail);

        lineEditEmail = new QLineEdit(profilePage);
        lineEditEmail->setObjectName("lineEditEmail");

        formLayoutProfile->setWidget(1, QFormLayout::ItemRole::FieldRole, lineEditEmail);

        lblPhone = new QLabel(profilePage);
        lblPhone->setObjectName("lblPhone");

        formLayoutProfile->setWidget(2, QFormLayout::ItemRole::LabelRole, lblPhone);

        lineEditPhone = new QLineEdit(profilePage);
        lineEditPhone->setObjectName("lineEditPhone");

        formLayoutProfile->setWidget(2, QFormLayout::ItemRole::FieldRole, lineEditPhone);


        verticalLayoutProfile->addLayout(formLayoutProfile);

        btnUpdateProfile = new QPushButton(profilePage);
        btnUpdateProfile->setObjectName("btnUpdateProfile");

        verticalLayoutProfile->addWidget(btnUpdateProfile);

        stackedWidget->addWidget(profilePage);

        horizontalLayout->addWidget(stackedWidget);

        InstructorMainWindow->setCentralWidget(centralWidget);

        retranslateUi(InstructorMainWindow);

        QMetaObject::connectSlotsByName(InstructorMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *InstructorMainWindow)
    {
        sidebarFrame->setStyleSheet(QCoreApplication::translate("InstructorMainWindow", "\n"
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
        btnDashboard->setText(QCoreApplication::translate("InstructorMainWindow", "\360\237\223\212 Dashboard", nullptr));
        btnMyLabs->setText(QCoreApplication::translate("InstructorMainWindow", "\360\237\217\253 My Labs", nullptr));
        btnLabDetails->setText(QCoreApplication::translate("InstructorMainWindow", "\360\237\223\213 Lab Details", nullptr));
        btnTimesheet->setText(QCoreApplication::translate("InstructorMainWindow", "\342\217\260 Timesheet", nullptr));
        btnNotifications->setText(QCoreApplication::translate("InstructorMainWindow", "\360\237\224\224 Notifications", nullptr));
        btnProfile->setText(QCoreApplication::translate("InstructorMainWindow", "\360\237\221\244 Profile", nullptr));
        dashboardPage->setStyleSheet(QCoreApplication::translate("InstructorMainWindow", "background-color: #FFDDC1;", nullptr));
        lblDashboardTitle->setStyleSheet(QCoreApplication::translate("InstructorMainWindow", "font-family:\"Segoe UI\"; font-size:22px; font-weight:bold; color:#2C3E50;", nullptr));
        lblDashboardTitle->setText(QCoreApplication::translate("InstructorMainWindow", "\360\237\223\212 Instructor Dashboard", nullptr));
        frameAssignedLabs->setStyleSheet(QCoreApplication::translate("InstructorMainWindow", "background-color: white; border-radius: 8px; padding: 10px; border: 1px solid #ccc;", nullptr));
        lblAssignedLabs->setStyleSheet(QCoreApplication::translate("InstructorMainWindow", "font-family:\"Segoe UI\"; font-size:16px; font-weight:bold; color:#2C3E50;", nullptr));
        lblAssignedLabs->setText(QCoreApplication::translate("InstructorMainWindow", "Assigned Labs", nullptr));
        lblAssignedLabsCount->setStyleSheet(QCoreApplication::translate("InstructorMainWindow", "font-family:\"Segoe UI\"; font-size:24px; font-weight:bold; color:#1ABC9C;", nullptr));
        lblAssignedLabsCount->setText(QCoreApplication::translate("InstructorMainWindow", "5", nullptr));
        frameUpcomingSessions->setStyleSheet(QCoreApplication::translate("InstructorMainWindow", "background-color: white; border-radius: 8px; padding: 10px; border: 1px solid #ccc;", nullptr));
        lblUpcomingSessions->setStyleSheet(QCoreApplication::translate("InstructorMainWindow", "font-family:\"Segoe UI\"; font-size:16px; font-weight:bold; color:#2C3E50;", nullptr));
        lblUpcomingSessions->setText(QCoreApplication::translate("InstructorMainWindow", "Upcoming Sessions", nullptr));
        lblUpcomingSessionsCount->setStyleSheet(QCoreApplication::translate("InstructorMainWindow", "font-family:\"Segoe UI\"; font-size:24px; font-weight:bold; color:#E74C3C;", nullptr));
        lblUpcomingSessionsCount->setText(QCoreApplication::translate("InstructorMainWindow", "2", nullptr));
        framePendingNotifications->setStyleSheet(QCoreApplication::translate("InstructorMainWindow", "background-color: white; border-radius: 8px; padding: 10px; border: 1px solid #ccc;", nullptr));
        lblPendingNotifications->setStyleSheet(QCoreApplication::translate("InstructorMainWindow", "font-family:\"Segoe UI\"; font-size:16px; font-weight:bold; color:#2C3E50;", nullptr));
        lblPendingNotifications->setText(QCoreApplication::translate("InstructorMainWindow", "Pending Notifications", nullptr));
        lblPendingNotificationsCount->setStyleSheet(QCoreApplication::translate("InstructorMainWindow", "font-family:\"Segoe UI\"; font-size:24px; font-weight:bold; color:#F39C12;", nullptr));
        lblPendingNotificationsCount->setText(QCoreApplication::translate("InstructorMainWindow", "3", nullptr));
        myLabsPage->setStyleSheet(QCoreApplication::translate("InstructorMainWindow", "background-color: #C1FFD7;", nullptr));
        lblMyLabsTitle->setStyleSheet(QCoreApplication::translate("InstructorMainWindow", "font-family:\"Segoe UI\"; font-size:22px; font-weight:bold; color:#2C3E50;", nullptr));
        lblMyLabsTitle->setText(QCoreApplication::translate("InstructorMainWindow", "\360\237\217\253 My Labs", nullptr));
        tableMyLabs->setStyleSheet(QCoreApplication::translate("InstructorMainWindow", "background:white; border-radius:8px; padding:6px; border:1px solid #ccc;", nullptr));
        labDetailsPage->setStyleSheet(QCoreApplication::translate("InstructorMainWindow", "background-color: #C1E1FF;", nullptr));
        lblLabDetailsTitle->setStyleSheet(QCoreApplication::translate("InstructorMainWindow", "font-family:\"Segoe UI\"; font-size:22px; font-weight:bold; color:#2C3E50;", nullptr));
        lblLabDetailsTitle->setText(QCoreApplication::translate("InstructorMainWindow", "\360\237\223\213 Lab Details", nullptr));
        lblSelectLab->setText(QCoreApplication::translate("InstructorMainWindow", "Select Lab:", nullptr));
        comboSelectLab->setStyleSheet(QCoreApplication::translate("InstructorMainWindow", "background:white; border-radius:4px; padding:4px; border:1px solid #ccc;", nullptr));
        lblLabName->setText(QCoreApplication::translate("InstructorMainWindow", "Lab Name:", nullptr));
        lblLabNameValue->setText(QString());
        lblTimings->setText(QCoreApplication::translate("InstructorMainWindow", "Timings:", nullptr));
        lblTimingsValue->setText(QString());
        lblVenue->setText(QCoreApplication::translate("InstructorMainWindow", "Venue:", nullptr));
        lblVenueValue->setText(QString());
        lblAssignedTAs->setText(QCoreApplication::translate("InstructorMainWindow", "Assigned TAs:", nullptr));
        lblAssignedTAsValue->setText(QString());
        timesheetPage->setStyleSheet(QCoreApplication::translate("InstructorMainWindow", "background-color: #FFD1DC;", nullptr));
        lblTimesheetTitle->setStyleSheet(QCoreApplication::translate("InstructorMainWindow", "font-family:\"Segoe UI\"; font-size:22px; font-weight:bold; color:#2C3E50;", nullptr));
        lblTimesheetTitle->setText(QCoreApplication::translate("InstructorMainWindow", "\342\217\260 Timesheet", nullptr));
        lblSelectLabTimesheet->setText(QCoreApplication::translate("InstructorMainWindow", "Select Lab:", nullptr));
        comboSelectLabTimesheet->setStyleSheet(QCoreApplication::translate("InstructorMainWindow", "background:white; border-radius:4px; padding:4px; border:1px solid #ccc;", nullptr));
        tableTimesheet->setStyleSheet(QCoreApplication::translate("InstructorMainWindow", "background:white; border-radius:8px; padding:6px; border:1px solid #ccc;", nullptr));
        notificationsPage->setStyleSheet(QCoreApplication::translate("InstructorMainWindow", "background-color: #FFFAC1;", nullptr));
        lblNotificationsTitle->setStyleSheet(QCoreApplication::translate("InstructorMainWindow", "font-family:\"Segoe UI\"; font-size:22px; font-weight:bold; color:#2C3E50;", nullptr));
        lblNotificationsTitle->setText(QCoreApplication::translate("InstructorMainWindow", "\360\237\224\224 Notifications", nullptr));
        listNotifications->setStyleSheet(QCoreApplication::translate("InstructorMainWindow", "background:white; border-radius:8px; padding:6px; border:1px solid #ccc;", nullptr));
        profilePage->setStyleSheet(QCoreApplication::translate("InstructorMainWindow", "background-color: #E1FFC1;", nullptr));
        lblProfileTitle->setStyleSheet(QCoreApplication::translate("InstructorMainWindow", "font-family:\"Segoe UI\"; font-size:22px; font-weight:bold; color:#2C3E50;", nullptr));
        lblProfileTitle->setText(QCoreApplication::translate("InstructorMainWindow", "\360\237\221\244 Profile", nullptr));
        lblName->setText(QCoreApplication::translate("InstructorMainWindow", "Name:", nullptr));
        lineEditName->setStyleSheet(QCoreApplication::translate("InstructorMainWindow", "background:white; border-radius:4px; padding:4px; border:1px solid #ccc;", nullptr));
        lblEmail->setText(QCoreApplication::translate("InstructorMainWindow", "Email:", nullptr));
        lineEditEmail->setStyleSheet(QCoreApplication::translate("InstructorMainWindow", "background:white; border-radius:4px; padding:4px; border:1px solid #ccc;", nullptr));
        lblPhone->setText(QCoreApplication::translate("InstructorMainWindow", "Phone:", nullptr));
        lineEditPhone->setStyleSheet(QCoreApplication::translate("InstructorMainWindow", "background:white; border-radius:4px; padding:4px; border:1px solid #ccc;", nullptr));
        btnUpdateProfile->setText(QCoreApplication::translate("InstructorMainWindow", "Update Profile", nullptr));
        (void)InstructorMainWindow;
    } // retranslateUi

};

namespace Ui {
    class InstructorMainWindow: public Ui_InstructorMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSTRUCTOR_MAINWINDOW_H
