#include "ta_mainwindow.h"
#include "ui_ta_mainwindow.h"  // Make sure this matches the generated header name
#include <QMenuBar>

TAMainWindow::TAMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TAMainWindow)
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

    // Add logout action to menu bar (for this constructor)
    QAction *logout = new QAction("Logout", this);
    connect(logout, &QAction::triggered, this, [this]() {
        if (this->parentWidget()) this->parentWidget()->show();
        this->close();
    });
    menuBar()->addAction(logout);

    // (logout action already added above)
}

TAMainWindow::TAMainWindow(int taId, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TAMainWindow), taId(taId)
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

TAMainWindow::~TAMainWindow()
{
    delete ui;
}
