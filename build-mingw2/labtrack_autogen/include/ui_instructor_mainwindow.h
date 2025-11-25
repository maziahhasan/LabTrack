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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
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
    QPushButton *btnMyLabs;
    QPushButton *btnRequestMakeup;
    QSpacerItem *verticalSpacer;
    QPushButton *btnProfile;
    QStackedWidget *stackedWidget;
    QWidget *myLabsPage;
    QVBoxLayout *verticalLayoutMyLabs;
    QLabel *lblMyLabsTitle;
    QTableWidget *tableMyLabs;
    QWidget *requestMakeupPage;
    QVBoxLayout *verticalLayoutRequestMakeup;
    QLabel *lblRequestMakeupTitle;
    QHBoxLayout *horizontalLayoutMakeupButtons;
    QPushButton *btnSubmitMakeupRequest;
    QSpacerItem *horizontalSpacerMakeup;
    QTableWidget *tableMakeupRequests;
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
        btnMyLabs = new QPushButton(sidebarFrame);
        btnMyLabs->setObjectName("btnMyLabs");
        btnMyLabs->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        verticalLayoutSidebar->addWidget(btnMyLabs);

        btnRequestMakeup = new QPushButton(sidebarFrame);
        btnRequestMakeup->setObjectName("btnRequestMakeup");
        btnRequestMakeup->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        verticalLayoutSidebar->addWidget(btnRequestMakeup);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayoutSidebar->addItem(verticalSpacer);

        btnProfile = new QPushButton(sidebarFrame);
        btnProfile->setObjectName("btnProfile");
        btnProfile->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        verticalLayoutSidebar->addWidget(btnProfile);


        horizontalLayout->addWidget(sidebarFrame);

        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName("stackedWidget");
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
        requestMakeupPage = new QWidget();
        requestMakeupPage->setObjectName("requestMakeupPage");
        verticalLayoutRequestMakeup = new QVBoxLayout(requestMakeupPage);
        verticalLayoutRequestMakeup->setObjectName("verticalLayoutRequestMakeup");
        lblRequestMakeupTitle = new QLabel(requestMakeupPage);
        lblRequestMakeupTitle->setObjectName("lblRequestMakeupTitle");

        verticalLayoutRequestMakeup->addWidget(lblRequestMakeupTitle);

        horizontalLayoutMakeupButtons = new QHBoxLayout();
        horizontalLayoutMakeupButtons->setObjectName("horizontalLayoutMakeupButtons");
        btnSubmitMakeupRequest = new QPushButton(requestMakeupPage);
        btnSubmitMakeupRequest->setObjectName("btnSubmitMakeupRequest");

        horizontalLayoutMakeupButtons->addWidget(btnSubmitMakeupRequest);

        horizontalSpacerMakeup = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayoutMakeupButtons->addItem(horizontalSpacerMakeup);


        verticalLayoutRequestMakeup->addLayout(horizontalLayoutMakeupButtons);

        tableMakeupRequests = new QTableWidget(requestMakeupPage);
        tableMakeupRequests->setObjectName("tableMakeupRequests");

        verticalLayoutRequestMakeup->addWidget(tableMakeupRequests);

        stackedWidget->addWidget(requestMakeupPage);
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
        btnMyLabs->setText(QCoreApplication::translate("InstructorMainWindow", "\360\237\217\253 My Labs", nullptr));
        btnRequestMakeup->setText(QCoreApplication::translate("InstructorMainWindow", "\360\237\223\235 Request Makeup Lab", nullptr));
        btnProfile->setText(QCoreApplication::translate("InstructorMainWindow", "\360\237\221\244 Profile", nullptr));
        myLabsPage->setStyleSheet(QCoreApplication::translate("InstructorMainWindow", "background-color: #C1E1FF;", nullptr));
        lblMyLabsTitle->setStyleSheet(QCoreApplication::translate("InstructorMainWindow", "font-family:\"Segoe UI\"; font-size:22px; font-weight:bold; color:#2C3E50;", nullptr));
        lblMyLabsTitle->setText(QCoreApplication::translate("InstructorMainWindow", "\360\237\217\253 My Labs", nullptr));
        tableMyLabs->setStyleSheet(QCoreApplication::translate("InstructorMainWindow", "background:white; border-radius:8px; padding:6px; border:1px solid #ccc;", nullptr));
        requestMakeupPage->setStyleSheet(QCoreApplication::translate("InstructorMainWindow", "background-color: #FFE1C1;", nullptr));
        lblRequestMakeupTitle->setStyleSheet(QCoreApplication::translate("InstructorMainWindow", "font-family:\"Segoe UI\"; font-size:22px; font-weight:bold; color:#2C3E50;", nullptr));
        lblRequestMakeupTitle->setText(QCoreApplication::translate("InstructorMainWindow", "\360\237\223\235 Request Makeup Lab", nullptr));
        btnSubmitMakeupRequest->setStyleSheet(QCoreApplication::translate("InstructorMainWindow", "background-color: #27AE60; color: white; font-weight: bold; padding: 8px;", nullptr));
        btnSubmitMakeupRequest->setText(QCoreApplication::translate("InstructorMainWindow", "\342\236\225 Submit New Request", nullptr));
        tableMakeupRequests->setStyleSheet(QCoreApplication::translate("InstructorMainWindow", "background:white; border-radius:8px; padding:6px; border:1px solid #ccc;", nullptr));
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
