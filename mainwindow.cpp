#include "mainwindow.h"
#include "ui_mainwindow.h"

using s21::MainWindow;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(std::make_unique<Ui::MainWindow>()),
      controller_(std::make_unique<Controller>()) {
    ui->setupUi(this);
    ConnectSignals();
}

MainWindow::~MainWindow() {}

void MainWindow::ConnectSignals() {
    connect(ui->newMazeButton, &QPushButton::clicked, this, &MainWindow::btnClicked);
    connect(ui->findPathButton, &QPushButton::clicked, this, &MainWindow::findPathBtnClicked);
}

void MainWindow::btnClicked() {
    controller_->SetHeight(ui->heightSpinBox->value());
    controller_->SetWidth(ui->widthSpinBox->value());
    controller_->GenerateMaze();
    ui->widget->setWidth(controller_->width());
    ui->widget->setHeight(controller_->height());
    ui->widget->setWalls(controller_->walls());
    ui->widget->update();
}

void MainWindow::findPathBtnClicked() {
    controller_->SearchWay();
}
