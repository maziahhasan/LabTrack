#include "ta_mainwindow.h"
#include "ui_ta_mainwindow.h"  // Make sure this matches the generated header name

ta_mainwindow::ta_mainwindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ta_mainwindow)
{
    ui->setupUi(this);

    // Connect sidebar buttons to stackedWidget pages
    connect(ui->btnDashboard, &QPushButton::clicked, [=](){ ui->stackedWidget->setCurrentWidget(ui->dashboardPage); });
    connect(ui->btnMyLabs, &QPushButton::clicked, [=](){ ui->stackedWidget->setCurrentWidget(ui->myLabsPage); });
    connect(ui->btnLabDetails, &QPushButton::clicked, [=](){ ui->stackedWidget->setCurrentWidget(ui->labDetailsPage); });
    connect(ui->btnTimesheet, &QPushButton::clicked, [=](){ ui->stackedWidget->setCurrentWidget(ui->timesheetPage); });
    connect(ui->btnNotifications, &QPushButton::clicked, [=](){ ui->stackedWidget->setCurrentWidget(ui->notificationsPage); });
    connect(ui->btnProfile, &QPushButton::clicked, [=](){ ui->stackedWidget->setCurrentWidget(ui->profilePage); });

    // Optional: Set default page on startup
    ui->stackedWidget->setCurrentWidget(ui->dashboardPage);
}

ta_mainwindow::~ta_mainwindow()
{
    delete ui;
}
