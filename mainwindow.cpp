#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect sidebar buttons to stackedWidget pages
    connect(ui->btnLabs, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentWidget(ui->labsPage);
    });
    connect(ui->btnSections, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentWidget(ui->sectionsPage);
    });
    connect(ui->btnTimings, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentWidget(ui->timingsPage);
    });
    connect(ui->btnInstructors, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentWidget(ui->instructorsPage);
    });
    connect(ui->btnVenues, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentWidget(ui->venuesPage);
    });
    connect(ui->btnReports, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentWidget(ui->reportsPage);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
