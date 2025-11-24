/********************************************************************************
** Form generated from reading UI file 'attendant_mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATTENDANT_MAINWINDOW_H
#define UI_ATTENDANT_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AttendantMainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QFrame *sidebarFrame;
    QVBoxLayout *verticalLayoutSidebar;
    QPushButton *btnDashboard;
    QPushButton *btnTimesheets;
    QPushButton *btnFillTimesheet;
    QStackedWidget *stackedWidget;
    QWidget *dashboardPage;
    QVBoxLayout *verticalLayoutDashboard;
    QLabel *lblDashboardTitle;
    QHBoxLayout *horizontalLayoutCards;
    QFrame *frameBuilding;
    QVBoxLayout *verticalLayoutBuilding;
    QLabel *label;
    QLabel *lblBuildingName;
    QFrame *frameTotalLabs;
    QVBoxLayout *verticalLayoutTotalLabs;
    QLabel *label1;
    QLabel *lblTotalLabsCount;
    QWidget *timesheetsPage;
    QVBoxLayout *verticalLayoutTimesheets;
    QLabel *label2;
    QTableWidget *tableTimesheets;
    QWidget *fillTimesheetPage;
    QVBoxLayout *verticalLayoutFillTimesheet;
    QLabel *label3;
    QFormLayout *formLayout;
    QLabel *label4;
    QComboBox *comboSelectLab;
    QLabel *label5;
    QDateEdit *dateEdit;
    QLabel *label6;
    QTimeEdit *timeStart;
    QLabel *label7;
    QTimeEdit *timeEnd;
    QPushButton *btnSubmitTimesheet;

    void setupUi(QMainWindow *AttendantMainWindow)
    {
        if (AttendantMainWindow->objectName().isEmpty())
            AttendantMainWindow->setObjectName("AttendantMainWindow");
        AttendantMainWindow->resize(1000, 700);
        centralWidget = new QWidget(AttendantMainWindow);
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

        verticalLayoutSidebar->addWidget(btnDashboard);

        btnTimesheets = new QPushButton(sidebarFrame);
        btnTimesheets->setObjectName("btnTimesheets");

        verticalLayoutSidebar->addWidget(btnTimesheets);

        btnFillTimesheet = new QPushButton(sidebarFrame);
        btnFillTimesheet->setObjectName("btnFillTimesheet");

        verticalLayoutSidebar->addWidget(btnFillTimesheet);


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
        frameBuilding = new QFrame(dashboardPage);
        frameBuilding->setObjectName("frameBuilding");
        verticalLayoutBuilding = new QVBoxLayout(frameBuilding);
        verticalLayoutBuilding->setObjectName("verticalLayoutBuilding");
        label = new QLabel(frameBuilding);
        label->setObjectName("label");

        verticalLayoutBuilding->addWidget(label);

        lblBuildingName = new QLabel(frameBuilding);
        lblBuildingName->setObjectName("lblBuildingName");

        verticalLayoutBuilding->addWidget(lblBuildingName);


        horizontalLayoutCards->addWidget(frameBuilding);

        frameTotalLabs = new QFrame(dashboardPage);
        frameTotalLabs->setObjectName("frameTotalLabs");
        verticalLayoutTotalLabs = new QVBoxLayout(frameTotalLabs);
        verticalLayoutTotalLabs->setObjectName("verticalLayoutTotalLabs");
        label1 = new QLabel(frameTotalLabs);
        label1->setObjectName("label1");

        verticalLayoutTotalLabs->addWidget(label1);

        lblTotalLabsCount = new QLabel(frameTotalLabs);
        lblTotalLabsCount->setObjectName("lblTotalLabsCount");

        verticalLayoutTotalLabs->addWidget(lblTotalLabsCount);


        horizontalLayoutCards->addWidget(frameTotalLabs);


        verticalLayoutDashboard->addLayout(horizontalLayoutCards);

        stackedWidget->addWidget(dashboardPage);
        timesheetsPage = new QWidget();
        timesheetsPage->setObjectName("timesheetsPage");
        verticalLayoutTimesheets = new QVBoxLayout(timesheetsPage);
        verticalLayoutTimesheets->setObjectName("verticalLayoutTimesheets");
        label2 = new QLabel(timesheetsPage);
        label2->setObjectName("label2");

        verticalLayoutTimesheets->addWidget(label2);

        tableTimesheets = new QTableWidget(timesheetsPage);
        tableTimesheets->setObjectName("tableTimesheets");
        tableTimesheets->setAlternatingRowColors(true);

        verticalLayoutTimesheets->addWidget(tableTimesheets);

        stackedWidget->addWidget(timesheetsPage);
        fillTimesheetPage = new QWidget();
        fillTimesheetPage->setObjectName("fillTimesheetPage");
        verticalLayoutFillTimesheet = new QVBoxLayout(fillTimesheetPage);
        verticalLayoutFillTimesheet->setObjectName("verticalLayoutFillTimesheet");
        label3 = new QLabel(fillTimesheetPage);
        label3->setObjectName("label3");

        verticalLayoutFillTimesheet->addWidget(label3);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label4 = new QLabel(fillTimesheetPage);
        label4->setObjectName("label4");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label4);

        comboSelectLab = new QComboBox(fillTimesheetPage);
        comboSelectLab->setObjectName("comboSelectLab");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, comboSelectLab);

        label5 = new QLabel(fillTimesheetPage);
        label5->setObjectName("label5");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label5);

        dateEdit = new QDateEdit(fillTimesheetPage);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setCalendarPopup(true);

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, dateEdit);

        label6 = new QLabel(fillTimesheetPage);
        label6->setObjectName("label6");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label6);

        timeStart = new QTimeEdit(fillTimesheetPage);
        timeStart->setObjectName("timeStart");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, timeStart);

        label7 = new QLabel(fillTimesheetPage);
        label7->setObjectName("label7");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, label7);

        timeEnd = new QTimeEdit(fillTimesheetPage);
        timeEnd->setObjectName("timeEnd");

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, timeEnd);

        btnSubmitTimesheet = new QPushButton(fillTimesheetPage);
        btnSubmitTimesheet->setObjectName("btnSubmitTimesheet");

        formLayout->setWidget(4, QFormLayout::ItemRole::SpanningRole, btnSubmitTimesheet);


        verticalLayoutFillTimesheet->addLayout(formLayout);

        stackedWidget->addWidget(fillTimesheetPage);

        horizontalLayout->addWidget(stackedWidget);

        AttendantMainWindow->setCentralWidget(centralWidget);

        retranslateUi(AttendantMainWindow);

        QMetaObject::connectSlotsByName(AttendantMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AttendantMainWindow)
    {
        sidebarFrame->setStyleSheet(QCoreApplication::translate("AttendantMainWindow", "\n"
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
        btnDashboard->setText(QCoreApplication::translate("AttendantMainWindow", "\360\237\223\212 Dashboard", nullptr));
        btnTimesheets->setText(QCoreApplication::translate("AttendantMainWindow", "\342\217\260 Timesheets", nullptr));
        btnFillTimesheet->setText(QCoreApplication::translate("AttendantMainWindow", "\342\234\217\357\270\217 Fill Timesheet", nullptr));
        lblDashboardTitle->setStyleSheet(QCoreApplication::translate("AttendantMainWindow", "font-family:\"Segoe UI\"; font-size:22px; font-weight:bold; color:#2C3E50;", nullptr));
        lblDashboardTitle->setText(QCoreApplication::translate("AttendantMainWindow", "\360\237\223\212 Attendant Dashboard", nullptr));
        frameBuilding->setStyleSheet(QCoreApplication::translate("AttendantMainWindow", "background-color: white; border-radius: 8px; padding: 10px; border: 1px solid #ccc;", nullptr));
        label->setText(QCoreApplication::translate("AttendantMainWindow", "Building", nullptr));
        lblBuildingName->setStyleSheet(QCoreApplication::translate("AttendantMainWindow", "font-family:\"Segoe UI\"; font-size:18px; font-weight:bold; color:#1ABC9C;", nullptr));
        lblBuildingName->setText(QCoreApplication::translate("AttendantMainWindow", "Not assigned", nullptr));
        frameTotalLabs->setStyleSheet(QCoreApplication::translate("AttendantMainWindow", "background-color: white; border-radius: 8px; padding: 10px; border: 1px solid #ccc;", nullptr));
        label1->setText(QCoreApplication::translate("AttendantMainWindow", "Total Labs", nullptr));
        lblTotalLabsCount->setStyleSheet(QCoreApplication::translate("AttendantMainWindow", "font-family:\"Segoe UI\"; font-size:24px; font-weight:bold; color:#1ABC9C;", nullptr));
        lblTotalLabsCount->setText(QCoreApplication::translate("AttendantMainWindow", "0", nullptr));
        label2->setStyleSheet(QCoreApplication::translate("AttendantMainWindow", "font-family:\"Segoe UI\"; font-size:22px; font-weight:bold; color:#2C3E50;", nullptr));
        label2->setText(QCoreApplication::translate("AttendantMainWindow", "\342\217\260 Timesheets", nullptr));
        label3->setStyleSheet(QCoreApplication::translate("AttendantMainWindow", "font-family:\"Segoe UI\"; font-size:22px; font-weight:bold; color:#2C3E50;", nullptr));
        label3->setText(QCoreApplication::translate("AttendantMainWindow", "\342\234\217\357\270\217 Fill Timesheet", nullptr));
        label4->setText(QCoreApplication::translate("AttendantMainWindow", "Lab:", nullptr));
        label5->setText(QCoreApplication::translate("AttendantMainWindow", "Date:", nullptr));
        label6->setText(QCoreApplication::translate("AttendantMainWindow", "Start Time:", nullptr));
        label7->setText(QCoreApplication::translate("AttendantMainWindow", "End Time:", nullptr));
        btnSubmitTimesheet->setText(QCoreApplication::translate("AttendantMainWindow", "Submit Timesheet", nullptr));
        btnSubmitTimesheet->setStyleSheet(QCoreApplication::translate("AttendantMainWindow", "background-color: #1ABC9C; color: white; padding: 10px; border-radius: 5px;", nullptr));
        (void)AttendantMainWindow;
    } // retranslateUi

};

namespace Ui {
    class AttendantMainWindow: public Ui_AttendantMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATTENDANT_MAINWINDOW_H
