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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RoleSelectionWindow
{
public:
    QVBoxLayout *mainLayout;
    QLabel *lblTitle;
    QPushButton *btnAdmin;
    QPushButton *btnTA;
    QPushButton *btnInstructor;
    QPushButton *btnHOD;

    void setupUi(QWidget *RoleSelectionWindow)
    {
        if (RoleSelectionWindow->objectName().isEmpty())
            RoleSelectionWindow->setObjectName("RoleSelectionWindow");
        RoleSelectionWindow->resize(600, 400);
        mainLayout = new QVBoxLayout(RoleSelectionWindow);
        mainLayout->setObjectName("mainLayout");
        lblTitle = new QLabel(RoleSelectionWindow);
        lblTitle->setObjectName("lblTitle");
        lblTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        mainLayout->addWidget(lblTitle);

        btnAdmin = new QPushButton(RoleSelectionWindow);
        btnAdmin->setObjectName("btnAdmin");

        mainLayout->addWidget(btnAdmin);

        btnTA = new QPushButton(RoleSelectionWindow);
        btnTA->setObjectName("btnTA");

        mainLayout->addWidget(btnTA);

        btnInstructor = new QPushButton(RoleSelectionWindow);
        btnInstructor->setObjectName("btnInstructor");

        mainLayout->addWidget(btnInstructor);

        btnHOD = new QPushButton(RoleSelectionWindow);
        btnHOD->setObjectName("btnHOD");

        mainLayout->addWidget(btnHOD);

        mainLayout->setStretch(1, 1);
        mainLayout->setStretch(2, 1);
        mainLayout->setStretch(3, 1);

        retranslateUi(RoleSelectionWindow);

        QMetaObject::connectSlotsByName(RoleSelectionWindow);
    } // setupUi

    void retranslateUi(QWidget *RoleSelectionWindow)
    {
        RoleSelectionWindow->setStyleSheet(QCoreApplication::translate("RoleSelectionWindow", "\n"
"    QWidget {\n"
"        font-family: \"Segoe UI\";\n"
"        background: qlineargradient(\n"
"            x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 #1ABC9C,\n"
"            stop:1 #2C3E50\n"
"        );\n"
"    }\n"
"\n"
"    /* Buttons (Theme-Matched) */\n"
"    QPushButton {\n"
"        background-color: #34495E;\n"
"        color: #ECF0F1;\n"
"        font-size: 16px;\n"
"        font-weight: 600;\n"
"        border-radius: 8px;\n"
"        padding: 12px;\n"
"    }\n"
"    QPushButton:hover {\n"
"        background-color: #1ABC9C;\n"
"        color: white;\n"
"    }\n"
"    QPushButton:pressed {\n"
"        background-color: #16A085;\n"
"        color: #FDFEFE;\n"
"    }\n"
"\n"
"    QLabel#lblTitle {\n"
"        font-size: 22px;\n"
"        font-weight: bold;\n"
"        color: white;\n"
"    }\n"
"   ", nullptr));
        lblTitle->setText(QCoreApplication::translate("RoleSelectionWindow", "\360\237\221\213 Welcome! Please Choose Your Role", nullptr));
        btnAdmin->setText(QCoreApplication::translate("RoleSelectionWindow", "\360\237\233\240\357\270\217 Admin", nullptr));
        btnTA->setText(QCoreApplication::translate("RoleSelectionWindow", "\360\237\223\230 Teaching Assistant", nullptr));
        btnInstructor->setText(QCoreApplication::translate("RoleSelectionWindow", "\360\237\221\251\342\200\215\360\237\217\253 Instructor", nullptr));
        btnHOD->setText(QCoreApplication::translate("RoleSelectionWindow", "\360\237\217\253 Head of Department", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RoleSelectionWindow: public Ui_RoleSelectionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTPAGE_H
