/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QFrame *sidebarFrame;
    QVBoxLayout *verticalLayoutSidebar;
    QPushButton *btnLabs;
    QPushButton *btnSections;
    QPushButton *btnTimings;
    QPushButton *btnInstructors;
    QPushButton *btnVenues;
    QPushButton *btnReports;
    QStackedWidget *stackedWidget;
    QWidget *labsPage;
    QVBoxLayout *verticalLayoutLabs;
    QLabel *lblLabsTitle;
    QTableWidget *tableLabs;
    QWidget *sectionsPage;
    QVBoxLayout *verticalLayoutSections;
    QLabel *lblSectionsTitle;
    QTableWidget *tableSections;
    QWidget *timingsPage;
    QVBoxLayout *verticalLayoutTimings;
    QLabel *lblTimingsTitle;
    QTableWidget *tableTimings;
    QWidget *instructorsPage;
    QVBoxLayout *verticalLayoutInstructors;
    QLabel *lblInstructorsTitle;
    QTableWidget *tableInstructors;
    QWidget *venuesPage;
    QVBoxLayout *verticalLayoutVenues;
    QLabel *lblVenuesTitle;
    QTableWidget *tableVenues;
    QWidget *reportsPage;
    QVBoxLayout *verticalLayoutReports;
    QLabel *lblReportsTitle;
    QTableWidget *tableReports;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(900, 600);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        sidebarFrame = new QFrame(centralWidget);
        sidebarFrame->setObjectName("sidebarFrame");
        sidebarFrame->setFrameShape(QFrame::Shape::NoFrame);
        verticalLayoutSidebar = new QVBoxLayout(sidebarFrame);
        verticalLayoutSidebar->setObjectName("verticalLayoutSidebar");
        btnLabs = new QPushButton(sidebarFrame);
        btnLabs->setObjectName("btnLabs");
        btnLabs->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        verticalLayoutSidebar->addWidget(btnLabs);

        btnSections = new QPushButton(sidebarFrame);
        btnSections->setObjectName("btnSections");
        btnSections->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        verticalLayoutSidebar->addWidget(btnSections);

        btnTimings = new QPushButton(sidebarFrame);
        btnTimings->setObjectName("btnTimings");
        btnTimings->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        verticalLayoutSidebar->addWidget(btnTimings);

        btnInstructors = new QPushButton(sidebarFrame);
        btnInstructors->setObjectName("btnInstructors");
        btnInstructors->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        verticalLayoutSidebar->addWidget(btnInstructors);

        btnVenues = new QPushButton(sidebarFrame);
        btnVenues->setObjectName("btnVenues");
        btnVenues->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        verticalLayoutSidebar->addWidget(btnVenues);

        btnReports = new QPushButton(sidebarFrame);
        btnReports->setObjectName("btnReports");
        btnReports->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        verticalLayoutSidebar->addWidget(btnReports);


        horizontalLayout->addWidget(sidebarFrame);

        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName("stackedWidget");
        labsPage = new QWidget();
        labsPage->setObjectName("labsPage");
        verticalLayoutLabs = new QVBoxLayout(labsPage);
        verticalLayoutLabs->setObjectName("verticalLayoutLabs");
        lblLabsTitle = new QLabel(labsPage);
        lblLabsTitle->setObjectName("lblLabsTitle");

        verticalLayoutLabs->addWidget(lblLabsTitle);

        tableLabs = new QTableWidget(labsPage);
        tableLabs->setObjectName("tableLabs");

        verticalLayoutLabs->addWidget(tableLabs);

        stackedWidget->addWidget(labsPage);
        sectionsPage = new QWidget();
        sectionsPage->setObjectName("sectionsPage");
        verticalLayoutSections = new QVBoxLayout(sectionsPage);
        verticalLayoutSections->setObjectName("verticalLayoutSections");
        lblSectionsTitle = new QLabel(sectionsPage);
        lblSectionsTitle->setObjectName("lblSectionsTitle");

        verticalLayoutSections->addWidget(lblSectionsTitle);

        tableSections = new QTableWidget(sectionsPage);
        tableSections->setObjectName("tableSections");

        verticalLayoutSections->addWidget(tableSections);

        stackedWidget->addWidget(sectionsPage);
        timingsPage = new QWidget();
        timingsPage->setObjectName("timingsPage");
        verticalLayoutTimings = new QVBoxLayout(timingsPage);
        verticalLayoutTimings->setObjectName("verticalLayoutTimings");
        lblTimingsTitle = new QLabel(timingsPage);
        lblTimingsTitle->setObjectName("lblTimingsTitle");

        verticalLayoutTimings->addWidget(lblTimingsTitle);

        tableTimings = new QTableWidget(timingsPage);
        tableTimings->setObjectName("tableTimings");

        verticalLayoutTimings->addWidget(tableTimings);

        stackedWidget->addWidget(timingsPage);
        instructorsPage = new QWidget();
        instructorsPage->setObjectName("instructorsPage");
        verticalLayoutInstructors = new QVBoxLayout(instructorsPage);
        verticalLayoutInstructors->setObjectName("verticalLayoutInstructors");
        lblInstructorsTitle = new QLabel(instructorsPage);
        lblInstructorsTitle->setObjectName("lblInstructorsTitle");

        verticalLayoutInstructors->addWidget(lblInstructorsTitle);

        tableInstructors = new QTableWidget(instructorsPage);
        tableInstructors->setObjectName("tableInstructors");

        verticalLayoutInstructors->addWidget(tableInstructors);

        stackedWidget->addWidget(instructorsPage);
        venuesPage = new QWidget();
        venuesPage->setObjectName("venuesPage");
        verticalLayoutVenues = new QVBoxLayout(venuesPage);
        verticalLayoutVenues->setObjectName("verticalLayoutVenues");
        lblVenuesTitle = new QLabel(venuesPage);
        lblVenuesTitle->setObjectName("lblVenuesTitle");

        verticalLayoutVenues->addWidget(lblVenuesTitle);

        tableVenues = new QTableWidget(venuesPage);
        tableVenues->setObjectName("tableVenues");

        verticalLayoutVenues->addWidget(tableVenues);

        stackedWidget->addWidget(venuesPage);
        reportsPage = new QWidget();
        reportsPage->setObjectName("reportsPage");
        verticalLayoutReports = new QVBoxLayout(reportsPage);
        verticalLayoutReports->setObjectName("verticalLayoutReports");
        lblReportsTitle = new QLabel(reportsPage);
        lblReportsTitle->setObjectName("lblReportsTitle");

        verticalLayoutReports->addWidget(lblReportsTitle);

        tableReports = new QTableWidget(reportsPage);
        tableReports->setObjectName("tableReports");

        verticalLayoutReports->addWidget(tableReports);

        stackedWidget->addWidget(reportsPage);

        horizontalLayout->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        sidebarFrame->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
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
        btnLabs->setText(QCoreApplication::translate("MainWindow", "\360\237\247\252 Labs", nullptr));
        btnSections->setText(QCoreApplication::translate("MainWindow", "\360\237\223\232 Sections", nullptr));
        btnTimings->setText(QCoreApplication::translate("MainWindow", "\342\217\260 Timings", nullptr));
        btnInstructors->setText(QCoreApplication::translate("MainWindow", "\360\237\221\251\342\200\215\360\237\217\253 Instructors & TAs", nullptr));
        btnVenues->setText(QCoreApplication::translate("MainWindow", "\360\237\217\253 Venues", nullptr));
        btnReports->setText(QCoreApplication::translate("MainWindow", "\360\237\223\212 Reports", nullptr));
        labsPage->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: #FFDDC1;", nullptr));
        lblLabsTitle->setStyleSheet(QCoreApplication::translate("MainWindow", "font-family:\"Segoe UI\"; font-size:22px; font-weight:bold; color:#2C3E50;", nullptr));
        lblLabsTitle->setText(QCoreApplication::translate("MainWindow", "\360\237\247\252 Labs", nullptr));
        tableLabs->setStyleSheet(QCoreApplication::translate("MainWindow", "background:white; border-radius:8px; padding:6px; border:1px solid #ccc;", nullptr));
        sectionsPage->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: #C1FFD7;", nullptr));
        lblSectionsTitle->setStyleSheet(QCoreApplication::translate("MainWindow", "font-family:\"Segoe UI\"; font-size:22px; font-weight:bold; color:#2C3E50;", nullptr));
        lblSectionsTitle->setText(QCoreApplication::translate("MainWindow", "\360\237\223\232 Sections", nullptr));
        tableSections->setStyleSheet(QCoreApplication::translate("MainWindow", "background:white; border-radius:8px; padding:6px; border:1px solid #ccc;", nullptr));
        timingsPage->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: #C1E1FF;", nullptr));
        lblTimingsTitle->setStyleSheet(QCoreApplication::translate("MainWindow", "font-family:\"Segoe UI\"; font-size:22px; font-weight:bold; color:#2C3E50;", nullptr));
        lblTimingsTitle->setText(QCoreApplication::translate("MainWindow", "\342\217\260 Timings", nullptr));
        tableTimings->setStyleSheet(QCoreApplication::translate("MainWindow", "background:white; border-radius:8px; padding:6px; border:1px solid #ccc;", nullptr));
        instructorsPage->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: #FFD1DC;", nullptr));
        lblInstructorsTitle->setStyleSheet(QCoreApplication::translate("MainWindow", "font-family:\"Segoe UI\"; font-size:22px; font-weight:bold; color:#2C3E50;", nullptr));
        lblInstructorsTitle->setText(QCoreApplication::translate("MainWindow", "\360\237\221\251\342\200\215\360\237\217\253 Instructors & HOD", nullptr));
        tableInstructors->setStyleSheet(QCoreApplication::translate("MainWindow", "background:white; border-radius:8px; padding:6px; border:1px solid #ccc;", nullptr));
        venuesPage->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: #FFFAC1;", nullptr));
        lblVenuesTitle->setStyleSheet(QCoreApplication::translate("MainWindow", "font-family:\"Segoe UI\"; font-size:22px; font-weight:bold; color:#2C3E50;", nullptr));
        lblVenuesTitle->setText(QCoreApplication::translate("MainWindow", "\360\237\217\253 Venues", nullptr));
        tableVenues->setStyleSheet(QCoreApplication::translate("MainWindow", "background:white; border-radius:8px; padding:6px; border:1px solid #ccc;", nullptr));
        reportsPage->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: #E1C1FF;", nullptr));
        lblReportsTitle->setStyleSheet(QCoreApplication::translate("MainWindow", "font-family:\"Segoe UI\"; font-size:22px; font-weight:bold; color:#2C3E50;", nullptr));
        lblReportsTitle->setText(QCoreApplication::translate("MainWindow", "\360\237\223\212 Reports", nullptr));
        tableReports->setStyleSheet(QCoreApplication::translate("MainWindow", "background:white; border-radius:8px; padding:6px; border:1px solid #ccc;", nullptr));
        (void)MainWindow;
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
