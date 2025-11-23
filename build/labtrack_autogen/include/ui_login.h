/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QHBoxLayout *mainLayout;
    QFrame *leftPanel;
    QVBoxLayout *leftLayout;
    QFrame *circle1;
    QLabel *mainTitle;
    QLabel *tagline;
    QFrame *circle2;
    QFrame *rightPanel;
    QVBoxLayout *rightLayout;
    QLabel *loginTitle;
    QLineEdit *txtEmail;
    QLineEdit *txtPassword;
    QPushButton *btnSignIn;
    QPushButton *btnBack;

    void setupUi(QWidget *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(880, 540);
        LoginWindow->setStyleSheet(QString::fromUtf8("\n"
"    QWidget {\n"
"        background: qlineargradient(\n"
"            x1:0, y1:0, x2:1, y2:1,\n"
"            stop:0 #138A7D,\n"
"            stop:1 #1F2D3D\n"
"        );\n"
"        font-family: \"Segoe UI\";\n"
"        color: white;\n"
"    }\n"
"\n"
"    /* Decorative Glow Circles */\n"
"    #circle1, #circle2 {\n"
"        background-color: rgba(255,255,255,0.10);\n"
"        border-radius: 70px;\n"
"    }\n"
"\n"
"    /* PANELS */\n"
"    #leftPanel, #rightPanel {\n"
"        background-color: rgba(255,255,255,0.18);\n"
"        border-radius: 22px;\n"
"        border: 1px solid rgba(255,255,255,0.22);\n"
"    }\n"
"\n"
"    /* Accent Glow Border for Right Login Panel */\n"
"    #rightPanel {\n"
"        border: 2px solid rgba(26,188,156,0.45);\n"
"    }\n"
"\n"
"    QLabel#mainTitle {\n"
"        font-size: 30px;\n"
"        font-weight: 800;\n"
"        color: white;\n"
"    }\n"
"\n"
"    QLabel#tagline {\n"
"        font-size: 15px;\n"
"        color: #ECF0F1;\n"
"    }\n"
"\n"
"    QLabel#log"
                        "inTitle {\n"
"        font-size: 24px;\n"
"        font-weight: bold;\n"
"        color: white;\n"
"    }\n"
"\n"
"    /* INPUTS */\n"
"    QLineEdit {\n"
"        background: rgba(255,255,255,0.85);\n"
"        border-radius: 10px;\n"
"        padding: 10px;\n"
"        border: 1px solid #d0d0d0;\n"
"        color: #2C3E50;\n"
"        font-size: 15px;\n"
"    }\n"
"\n"
"    QLineEdit:focus {\n"
"        border: 2px solid #1ABC9C;\n"
"        background: white;\n"
"    }\n"
"\n"
"    /* BUTTONS */\n"
"    QPushButton {\n"
"        background-color: #1ABC9C;\n"
"        color: white;\n"
"        font-size: 16px;\n"
"        border-radius: 10px;\n"
"        padding: 10px;\n"
"        font-weight: 600;\n"
"    }\n"
"    QPushButton:hover {\n"
"        background-color: #16A085;\n"
"    }\n"
"    QPushButton:pressed {\n"
"        background-color: #13856E;\n"
"    }\n"
"\n"
"    /* Signup link */\n"
"    QLabel#signupText {\n"
"        color: #ECF0F1;\n"
"        font-size: 13px;\n"
"    }\n"
"   "));
        mainLayout = new QHBoxLayout(LoginWindow);
        mainLayout->setSpacing(30);
        mainLayout->setContentsMargins(40, 40, 40, 40);
        mainLayout->setObjectName("mainLayout");
        leftPanel = new QFrame(LoginWindow);
        leftPanel->setObjectName("leftPanel");
        leftLayout = new QVBoxLayout(leftPanel);
        leftLayout->setSpacing(20);
        leftLayout->setObjectName("leftLayout");
        leftLayout->setAlignment(Qt::AlignCenter);
        circle1 = new QFrame(leftPanel);
        circle1->setObjectName("circle1");
        circle1->setMinimumSize(QSize(140, 140));

        leftLayout->addWidget(circle1);

        mainTitle = new QLabel(leftPanel);
        mainTitle->setObjectName("mainTitle");
        mainTitle->setAlignment(Qt::AlignCenter);

        leftLayout->addWidget(mainTitle);

        tagline = new QLabel(leftPanel);
        tagline->setObjectName("tagline");
        tagline->setAlignment(Qt::AlignCenter);

        leftLayout->addWidget(tagline);

        circle2 = new QFrame(leftPanel);
        circle2->setObjectName("circle2");
        circle2->setMinimumSize(QSize(120, 120));

        leftLayout->addWidget(circle2);


        mainLayout->addWidget(leftPanel);

        rightPanel = new QFrame(LoginWindow);
        rightPanel->setObjectName("rightPanel");
        rightLayout = new QVBoxLayout(rightPanel);
        rightLayout->setSpacing(15);
        rightLayout->setObjectName("rightLayout");
        loginTitle = new QLabel(rightPanel);
        loginTitle->setObjectName("loginTitle");
        loginTitle->setAlignment(Qt::AlignCenter);

        rightLayout->addWidget(loginTitle);

        txtEmail = new QLineEdit(rightPanel);
        txtEmail->setObjectName("txtEmail");

        rightLayout->addWidget(txtEmail);

        txtPassword = new QLineEdit(rightPanel);
        txtPassword->setObjectName("txtPassword");
        txtPassword->setEchoMode(QLineEdit::Password);

        rightLayout->addWidget(txtPassword);

        btnSignIn = new QPushButton(rightPanel);
        btnSignIn->setObjectName("btnSignIn");

        rightLayout->addWidget(btnSignIn);

        btnBack = new QPushButton(rightPanel);
        btnBack->setObjectName("btnBack");

        rightLayout->addWidget(btnBack);


        mainLayout->addWidget(rightPanel);


        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QWidget *LoginWindow)
    {
        mainTitle->setText(QCoreApplication::translate("LoginWindow", "Welcome Back \360\237\221\213", nullptr));
        tagline->setText(QCoreApplication::translate("LoginWindow", "Manage Labs, Schedules & Attendance Seamlessly", nullptr));
        loginTitle->setText(QCoreApplication::translate("LoginWindow", "Login", nullptr));
        txtEmail->setPlaceholderText(QCoreApplication::translate("LoginWindow", "Username / Email", nullptr));
        txtPassword->setPlaceholderText(QCoreApplication::translate("LoginWindow", "Password", nullptr));
        btnSignIn->setText(QCoreApplication::translate("LoginWindow", "Sign In", nullptr));
        btnBack->setText(QCoreApplication::translate("LoginWindow", "Back", nullptr));
        (void)LoginWindow;
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
