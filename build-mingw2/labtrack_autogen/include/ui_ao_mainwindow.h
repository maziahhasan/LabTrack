/********************************************************************************
** Form generated from reading UI file 'ao_mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AO_MAINWINDOW_H
#define UI_AO_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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

class Ui_AOMainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QFrame *sidebarFrame;
    QVBoxLayout *verticalLayoutSidebar;
    QPushButton *btnDashboard;
    QPushButton *btnManageLabs;
    QPushButton *btnManageInstructors;
    QPushButton *btnManageTAs;
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
    QFrame *frameTotalInstructors;
    QVBoxLayout *verticalLayoutTotalInstructors;
    QLabel *lblTotalInstructors;
    QLabel *lblTotalInstructorsCount;
    QFrame *frameTotalTAs;
    QVBoxLayout *verticalLayoutTotalTAs;
    QLabel *lblTotalTAs;
    QLabel *lblTotalTAsCount;
    QWidget *manageLabsPage;
    QVBoxLayout *verticalLayoutManageLabs;
    QLabel *lblManageLabsTitle;
    QHBoxLayout *horizontalLayoutManageLabsButtons;
    QPushButton *btnAddLab;
    QPushButton *btnEditLab;
    QPushButton *btnDeleteLab;
    QTableWidget *tableLabs;
    QWidget *manageInstructorsPage;
    QVBoxLayout *verticalLayoutManageInstructors;
    QLabel *lblManageInstructorsTitle;
    QHBoxLayout *horizontalLayoutManageInstructorsButtons;
    QPushButton *btnAddInstructor;
    QPushButton *btnEditInstructor;
    QPushButton *btnDeleteInstructor;
    QTableWidget *tableInstructors;
    QWidget *manageTAsPage;
    QVBoxLayout *verticalLayoutManageTAs;
    QLabel *lblManageTAsTitle;
    QHBoxLayout *horizontalLayoutManageTAsButtons;
    QPushButton *btnAddTA;
    QPushButton *btnEditTA;
    QPushButton *btnDeleteTA;
    QTableWidget *tableTAs;
    QWidget *makeupRequestsPage;
    QVBoxLayout *verticalLayoutMakeupRequests;
    QLabel *lblMakeupRequestsTitle;
    QHBoxLayout *horizontalLayoutMakeupButtons;
    QPushButton *btnAcceptMakeup;
    QPushButton *btnRejectMakeup;
    QSpacerItem *horizontalSpacerMakeup;
    QTableWidget *tableMakeupRequests;

    void setupUi(QMainWindow *AOMainWindow)
    {
        if (AOMainWindow->objectName().isEmpty())
            AOMainWindow->setObjectName("AOMainWindow");
        AOMainWindow->resize(1000, 700);
        centralWidget = new QWidget(AOMainWindow);
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

        btnManageLabs = new QPushButton(sidebarFrame);
        btnManageLabs->setObjectName("btnManageLabs");
        btnManageLabs->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        verticalLayoutSidebar->addWidget(btnManageLabs);

        btnManageInstructors = new QPushButton(sidebarFrame);
        btnManageInstructors->setObjectName("btnManageInstructors");
        btnManageInstructors->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        verticalLayoutSidebar->addWidget(btnManageInstructors);

        btnManageTAs = new QPushButton(sidebarFrame);
        btnManageTAs->setObjectName("btnManageTAs");
        btnManageTAs->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        verticalLayoutSidebar->addWidget(btnManageTAs);

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

        frameTotalInstructors = new QFrame(dashboardPage);
        frameTotalInstructors->setObjectName("frameTotalInstructors");
        verticalLayoutTotalInstructors = new QVBoxLayout(frameTotalInstructors);
        verticalLayoutTotalInstructors->setObjectName("verticalLayoutTotalInstructors");
        lblTotalInstructors = new QLabel(frameTotalInstructors);
        lblTotalInstructors->setObjectName("lblTotalInstructors");

        verticalLayoutTotalInstructors->addWidget(lblTotalInstructors);

        lblTotalInstructorsCount = new QLabel(frameTotalInstructors);
        lblTotalInstructorsCount->setObjectName("lblTotalInstructorsCount");

        verticalLayoutTotalInstructors->addWidget(lblTotalInstructorsCount);


        horizontalLayoutCards->addWidget(frameTotalInstructors);

        frameTotalTAs = new QFrame(dashboardPage);
        frameTotalTAs->setObjectName("frameTotalTAs");
        verticalLayoutTotalTAs = new QVBoxLayout(frameTotalTAs);
        verticalLayoutTotalTAs->setObjectName("verticalLayoutTotalTAs");
        lblTotalTAs = new QLabel(frameTotalTAs);
        lblTotalTAs->setObjectName("lblTotalTAs");

        verticalLayoutTotalTAs->addWidget(lblTotalTAs);

        lblTotalTAsCount = new QLabel(frameTotalTAs);
        lblTotalTAsCount->setObjectName("lblTotalTAsCount");

        verticalLayoutTotalTAs->addWidget(lblTotalTAsCount);


        horizontalLayoutCards->addWidget(frameTotalTAs);


        verticalLayoutDashboard->addLayout(horizontalLayoutCards);

        stackedWidget->addWidget(dashboardPage);
        manageLabsPage = new QWidget();
        manageLabsPage->setObjectName("manageLabsPage");
        verticalLayoutManageLabs = new QVBoxLayout(manageLabsPage);
        verticalLayoutManageLabs->setObjectName("verticalLayoutManageLabs");
        lblManageLabsTitle = new QLabel(manageLabsPage);
        lblManageLabsTitle->setObjectName("lblManageLabsTitle");

        verticalLayoutManageLabs->addWidget(lblManageLabsTitle);

        horizontalLayoutManageLabsButtons = new QHBoxLayout();
        horizontalLayoutManageLabsButtons->setObjectName("horizontalLayoutManageLabsButtons");
        btnAddLab = new QPushButton(manageLabsPage);
        btnAddLab->setObjectName("btnAddLab");

        horizontalLayoutManageLabsButtons->addWidget(btnAddLab);

        btnEditLab = new QPushButton(manageLabsPage);
        btnEditLab->setObjectName("btnEditLab");

        horizontalLayoutManageLabsButtons->addWidget(btnEditLab);

        btnDeleteLab = new QPushButton(manageLabsPage);
        btnDeleteLab->setObjectName("btnDeleteLab");

        horizontalLayoutManageLabsButtons->addWidget(btnDeleteLab);


        verticalLayoutManageLabs->addLayout(horizontalLayoutManageLabsButtons);

        tableLabs = new QTableWidget(manageLabsPage);
        tableLabs->setObjectName("tableLabs");

        verticalLayoutManageLabs->addWidget(tableLabs);

        stackedWidget->addWidget(manageLabsPage);
        manageInstructorsPage = new QWidget();
        manageInstructorsPage->setObjectName("manageInstructorsPage");
        verticalLayoutManageInstructors = new QVBoxLayout(manageInstructorsPage);
        verticalLayoutManageInstructors->setObjectName("verticalLayoutManageInstructors");
        lblManageInstructorsTitle = new QLabel(manageInstructorsPage);
        lblManageInstructorsTitle->setObjectName("lblManageInstructorsTitle");

        verticalLayoutManageInstructors->addWidget(lblManageInstructorsTitle);

        horizontalLayoutManageInstructorsButtons = new QHBoxLayout();
        horizontalLayoutManageInstructorsButtons->setObjectName("horizontalLayoutManageInstructorsButtons");
        btnAddInstructor = new QPushButton(manageInstructorsPage);
        btnAddInstructor->setObjectName("btnAddInstructor");

        horizontalLayoutManageInstructorsButtons->addWidget(btnAddInstructor);

        btnEditInstructor = new QPushButton(manageInstructorsPage);
        btnEditInstructor->setObjectName("btnEditInstructor");

        horizontalLayoutManageInstructorsButtons->addWidget(btnEditInstructor);

        btnDeleteInstructor = new QPushButton(manageInstructorsPage);
        btnDeleteInstructor->setObjectName("btnDeleteInstructor");

        horizontalLayoutManageInstructorsButtons->addWidget(btnDeleteInstructor);


        verticalLayoutManageInstructors->addLayout(horizontalLayoutManageInstructorsButtons);

        tableInstructors = new QTableWidget(manageInstructorsPage);
        tableInstructors->setObjectName("tableInstructors");

        verticalLayoutManageInstructors->addWidget(tableInstructors);

        stackedWidget->addWidget(manageInstructorsPage);
        manageTAsPage = new QWidget();
        manageTAsPage->setObjectName("manageTAsPage");
        verticalLayoutManageTAs = new QVBoxLayout(manageTAsPage);
        verticalLayoutManageTAs->setObjectName("verticalLayoutManageTAs");
        lblManageTAsTitle = new QLabel(manageTAsPage);
        lblManageTAsTitle->setObjectName("lblManageTAsTitle");

        verticalLayoutManageTAs->addWidget(lblManageTAsTitle);

        horizontalLayoutManageTAsButtons = new QHBoxLayout();
        horizontalLayoutManageTAsButtons->setObjectName("horizontalLayoutManageTAsButtons");
        btnAddTA = new QPushButton(manageTAsPage);
        btnAddTA->setObjectName("btnAddTA");

        horizontalLayoutManageTAsButtons->addWidget(btnAddTA);

        btnEditTA = new QPushButton(manageTAsPage);
        btnEditTA->setObjectName("btnEditTA");

        horizontalLayoutManageTAsButtons->addWidget(btnEditTA);

        btnDeleteTA = new QPushButton(manageTAsPage);
        btnDeleteTA->setObjectName("btnDeleteTA");

        horizontalLayoutManageTAsButtons->addWidget(btnDeleteTA);


        verticalLayoutManageTAs->addLayout(horizontalLayoutManageTAsButtons);

        tableTAs = new QTableWidget(manageTAsPage);
        tableTAs->setObjectName("tableTAs");

        verticalLayoutManageTAs->addWidget(tableTAs);

        stackedWidget->addWidget(manageTAsPage);
        makeupRequestsPage = new QWidget();
        makeupRequestsPage->setObjectName("makeupRequestsPage");
        verticalLayoutMakeupRequests = new QVBoxLayout(makeupRequestsPage);
        verticalLayoutMakeupRequests->setObjectName("verticalLayoutMakeupRequests");
        lblMakeupRequestsTitle = new QLabel(makeupRequestsPage);
        lblMakeupRequestsTitle->setObjectName("lblMakeupRequestsTitle");

        verticalLayoutMakeupRequests->addWidget(lblMakeupRequestsTitle);

        horizontalLayoutMakeupButtons = new QHBoxLayout();
        horizontalLayoutMakeupButtons->setObjectName("horizontalLayoutMakeupButtons");
        btnAcceptMakeup = new QPushButton(makeupRequestsPage);
        btnAcceptMakeup->setObjectName("btnAcceptMakeup");

        horizontalLayoutMakeupButtons->addWidget(btnAcceptMakeup);

        btnRejectMakeup = new QPushButton(makeupRequestsPage);
        btnRejectMakeup->setObjectName("btnRejectMakeup");

        horizontalLayoutMakeupButtons->addWidget(btnRejectMakeup);

        horizontalSpacerMakeup = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayoutMakeupButtons->addItem(horizontalSpacerMakeup);


        verticalLayoutMakeupRequests->addLayout(horizontalLayoutMakeupButtons);

        tableMakeupRequests = new QTableWidget(makeupRequestsPage);
        tableMakeupRequests->setObjectName("tableMakeupRequests");

        verticalLayoutMakeupRequests->addWidget(tableMakeupRequests);

        stackedWidget->addWidget(makeupRequestsPage);

        horizontalLayout->addWidget(stackedWidget);

        AOMainWindow->setCentralWidget(centralWidget);

        retranslateUi(AOMainWindow);

        QMetaObject::connectSlotsByName(AOMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AOMainWindow)
    {
        sidebarFrame->setStyleSheet(QCoreApplication::translate("AOMainWindow", "\n"
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
        btnDashboard->setText(QCoreApplication::translate("AOMainWindow", "\360\237\223\212 Dashboard", nullptr));
        btnManageLabs->setText(QCoreApplication::translate("AOMainWindow", "\360\237\217\253 Manage Labs", nullptr));
        btnManageInstructors->setText(QCoreApplication::translate("AOMainWindow", "\360\237\221\250\342\200\215\360\237\217\253 Manage Instructors", nullptr));
        btnManageTAs->setText(QCoreApplication::translate("AOMainWindow", "\360\237\221\250\342\200\215\360\237\216\223 Manage TAs", nullptr));
        btnMakeupRequests->setText(QCoreApplication::translate("AOMainWindow", "\360\237\224\204 Makeup Requests", nullptr));
        dashboardPage->setStyleSheet(QCoreApplication::translate("AOMainWindow", "background-color: #FFDDC1;", nullptr));
        lblDashboardTitle->setStyleSheet(QCoreApplication::translate("AOMainWindow", "font-family:\"Segoe UI\"; font-size:22px; font-weight:bold; color:#2C3E50;", nullptr));
        lblDashboardTitle->setText(QCoreApplication::translate("AOMainWindow", "\360\237\223\212 AO Dashboard", nullptr));
        frameTotalLabs->setStyleSheet(QCoreApplication::translate("AOMainWindow", "background-color: white; border-radius: 8px; padding: 10px; border: 1px solid #ccc;", nullptr));
        lblTotalLabs->setStyleSheet(QCoreApplication::translate("AOMainWindow", "font-family:\"Segoe UI\"; font-size:16px; font-weight:bold; color:#2C3E50;", nullptr));
        lblTotalLabs->setText(QCoreApplication::translate("AOMainWindow", "Total Labs", nullptr));
        lblTotalLabsCount->setStyleSheet(QCoreApplication::translate("AOMainWindow", "font-family:\"Segoe UI\"; font-size:24px; font-weight:bold; color:#1ABC9C;", nullptr));
        lblTotalLabsCount->setText(QCoreApplication::translate("AOMainWindow", "25", nullptr));
        frameTotalInstructors->setStyleSheet(QCoreApplication::translate("AOMainWindow", "background-color: white; border-radius: 8px; padding: 10px; border: 1px solid #ccc;", nullptr));
        lblTotalInstructors->setStyleSheet(QCoreApplication::translate("AOMainWindow", "font-family:\"Segoe UI\"; font-size:16px; font-weight:bold; color:#2C3E50;", nullptr));
        lblTotalInstructors->setText(QCoreApplication::translate("AOMainWindow", "Total Instructors", nullptr));
        lblTotalInstructorsCount->setStyleSheet(QCoreApplication::translate("AOMainWindow", "font-family:\"Segoe UI\"; font-size:24px; font-weight:bold; color:#1ABC9C;", nullptr));
        lblTotalInstructorsCount->setText(QCoreApplication::translate("AOMainWindow", "10", nullptr));
        frameTotalTAs->setStyleSheet(QCoreApplication::translate("AOMainWindow", "background-color: white; border-radius: 8px; padding: 10px; border: 1px solid #ccc;", nullptr));
        lblTotalTAs->setStyleSheet(QCoreApplication::translate("AOMainWindow", "font-family:\"Segoe UI\"; font-size:16px; font-weight:bold; color:#2C3E50;", nullptr));
        lblTotalTAs->setText(QCoreApplication::translate("AOMainWindow", "Total TAs", nullptr));
        lblTotalTAsCount->setStyleSheet(QCoreApplication::translate("AOMainWindow", "font-family:\"Segoe UI\"; font-size:24px; font-weight:bold; color:#1ABC9C;", nullptr));
        lblTotalTAsCount->setText(QCoreApplication::translate("AOMainWindow", "50", nullptr));
        manageLabsPage->setStyleSheet(QCoreApplication::translate("AOMainWindow", "background-color: #C1FFD7;", nullptr));
        lblManageLabsTitle->setStyleSheet(QCoreApplication::translate("AOMainWindow", "font-family:\"Segoe UI\"; font-size:22px; font-weight:bold; color:#2C3E50;", nullptr));
        lblManageLabsTitle->setText(QCoreApplication::translate("AOMainWindow", "\360\237\217\253 Manage Labs", nullptr));
        btnAddLab->setText(QCoreApplication::translate("AOMainWindow", "Add Lab", nullptr));
        btnEditLab->setText(QCoreApplication::translate("AOMainWindow", "Edit Lab", nullptr));
        btnDeleteLab->setText(QCoreApplication::translate("AOMainWindow", "Delete Lab", nullptr));
        tableLabs->setStyleSheet(QCoreApplication::translate("AOMainWindow", "background:white; border-radius:8px; padding:6px; border:1px solid #ccc;", nullptr));
        manageInstructorsPage->setStyleSheet(QCoreApplication::translate("AOMainWindow", "background-color: #C1E1FF;", nullptr));
        lblManageInstructorsTitle->setStyleSheet(QCoreApplication::translate("AOMainWindow", "font-family:\"Segoe UI\"; font-size:22px; font-weight:bold; color:#2C3E50;", nullptr));
        lblManageInstructorsTitle->setText(QCoreApplication::translate("AOMainWindow", "\360\237\221\250\342\200\215\360\237\217\253 Manage Instructors", nullptr));
        btnAddInstructor->setText(QCoreApplication::translate("AOMainWindow", "Add Instructor", nullptr));
        btnEditInstructor->setText(QCoreApplication::translate("AOMainWindow", "Edit Instructor", nullptr));
        btnDeleteInstructor->setText(QCoreApplication::translate("AOMainWindow", "Delete Instructor", nullptr));
        tableInstructors->setStyleSheet(QCoreApplication::translate("AOMainWindow", "background:white; border-radius:8px; padding:6px; border:1px solid #ccc;", nullptr));
        manageTAsPage->setStyleSheet(QCoreApplication::translate("AOMainWindow", "background-color: #FFD1DC;", nullptr));
        lblManageTAsTitle->setStyleSheet(QCoreApplication::translate("AOMainWindow", "font-family:\"Segoe UI\"; font-size:22px; font-weight:bold; color:#2C3E50;", nullptr));
        lblManageTAsTitle->setText(QCoreApplication::translate("AOMainWindow", "\360\237\221\250\342\200\215\360\237\216\223 Manage TAs", nullptr));
        btnAddTA->setText(QCoreApplication::translate("AOMainWindow", "Add TA", nullptr));
        btnEditTA->setText(QCoreApplication::translate("AOMainWindow", "Edit TA", nullptr));
        btnDeleteTA->setText(QCoreApplication::translate("AOMainWindow", "Delete TA", nullptr));
        tableTAs->setStyleSheet(QCoreApplication::translate("AOMainWindow", "background:white; border-radius:8px; padding:6px; border:1px solid #ccc;", nullptr));
        makeupRequestsPage->setStyleSheet(QCoreApplication::translate("AOMainWindow", "background-color: #FFE5CC;", nullptr));
        lblMakeupRequestsTitle->setStyleSheet(QCoreApplication::translate("AOMainWindow", "font-family:\"Segoe UI\"; font-size:22px; font-weight:bold; color:#2C3E50;", nullptr));
        lblMakeupRequestsTitle->setText(QCoreApplication::translate("AOMainWindow", "\360\237\224\204 Makeup Lab Requests", nullptr));
        btnAcceptMakeup->setStyleSheet(QCoreApplication::translate("AOMainWindow", "background-color: #27AE60; color: white; font-weight: bold; padding: 8px;", nullptr));
        btnAcceptMakeup->setText(QCoreApplication::translate("AOMainWindow", "\342\234\223 Accept Request", nullptr));
        btnRejectMakeup->setStyleSheet(QCoreApplication::translate("AOMainWindow", "background-color: #E74C3C; color: white; font-weight: bold; padding: 8px;", nullptr));
        btnRejectMakeup->setText(QCoreApplication::translate("AOMainWindow", "\342\234\227 Reject Request", nullptr));
        tableMakeupRequests->setStyleSheet(QCoreApplication::translate("AOMainWindow", "background:white; border-radius:8px; padding:6px; border:1px solid #ccc;", nullptr));
        (void)AOMainWindow;
    } // retranslateUi

};

namespace Ui {
    class AOMainWindow: public Ui_AOMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AO_MAINWINDOW_H
