/********************************************************************************
** Form generated from reading UI file 'startpage.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTPAGE_H
#define UI_STARTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RoleSelectionWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *lblTitle;
    QLabel *lblSubtitle;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnAdmin;
    QPushButton *btnInstructor;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnTA;
    QPushButton *btnHOD;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QMainWindow *RoleSelectionWindow)
    {
        if (RoleSelectionWindow->objectName().isEmpty())
            RoleSelectionWindow->setObjectName("RoleSelectionWindow");
        RoleSelectionWindow->resize(800, 600);
        RoleSelectionWindow->setStyleSheet(QString::fromUtf8("\n"
"    QMainWindow {\n"
"        background: qlineargradient(\n"
"            x1:0, y1:0, x2:1, y2:1,\n"
"            stop:0 #138A7D,\n"
"            stop:1 #1F2D3D\n"
"        );\n"
"        font-family: \"Segoe UI\";\n"
"        color: white;\n"
"    }\n"
"\n"
"    QLabel {\n"
"        font-size: 24px;\n"
"        font-weight: bold;\n"
"        color: white;\n"
"    }\n"
"\n"
"    QPushButton {\n"
"        background-color: #1ABC9C;\n"
"        color: white;\n"
"        font-size: 18px;\n"
"        font-weight: 600;\n"
"        border-radius: 10px;\n"
"        padding: 15px;\n"
"        margin: 10px;\n"
"        min-width: 200px;\n"
"        min-height: 60px;\n"
"    }\n"
"\n"
"    QPushButton:hover {\n"
"        background-color: #16A085;\n"
"    }\n"
"\n"
"    QPushButton:pressed {\n"
"        background-color: #13856E;\n"
"    }\n"
"   "));
        centralWidget = new QWidget(RoleSelectionWindow);
        centralWidget->setObjectName("centralWidget");
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        lblTitle = new QLabel(centralWidget);
        lblTitle->setObjectName("lblTitle");
        lblTitle->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lblTitle);

        lblSubtitle = new QLabel(centralWidget);
        lblSubtitle->setObjectName("lblSubtitle");
        lblSubtitle->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lblSubtitle);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnAdmin = new QPushButton(centralWidget);
        btnAdmin->setObjectName("btnAdmin");

        horizontalLayout->addWidget(btnAdmin);

        btnInstructor = new QPushButton(centralWidget);
        btnInstructor->setObjectName("btnInstructor");

        horizontalLayout->addWidget(btnInstructor);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        btnTA = new QPushButton(centralWidget);
        btnTA->setObjectName("btnTA");

        horizontalLayout_2->addWidget(btnTA);

        btnHOD = new QPushButton(centralWidget);
        btnHOD->setObjectName("btnHOD");

        horizontalLayout_2->addWidget(btnHOD);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        RoleSelectionWindow->setCentralWidget(centralWidget);

        retranslateUi(RoleSelectionWindow);

        QMetaObject::connectSlotsByName(RoleSelectionWindow);
    } // setupUi

    void retranslateUi(QMainWindow *RoleSelectionWindow)
    {
        RoleSelectionWindow->setWindowTitle(QCoreApplication::translate("RoleSelectionWindow", "LabTrack - Role Selection", nullptr));
        lblTitle->setText(QCoreApplication::translate("RoleSelectionWindow", "Welcome to LabTrack", nullptr));
        lblSubtitle->setText(QCoreApplication::translate("RoleSelectionWindow", "Select Your Role", nullptr));
        btnAdmin->setText(QCoreApplication::translate("RoleSelectionWindow", "\360\237\221\221 Admin", nullptr));
        btnInstructor->setText(QCoreApplication::translate("RoleSelectionWindow", "\360\237\221\250\342\200\215\360\237\217\253 Instructor", nullptr));
        btnTA->setText(QCoreApplication::translate("RoleSelectionWindow", "\360\237\216\223 Teaching Assistant", nullptr));
        btnHOD->setText(QCoreApplication::translate("RoleSelectionWindow", "\360\237\217\233\357\270\217 Head of Department", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RoleSelectionWindow: public Ui_RoleSelectionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTPAGE_H
