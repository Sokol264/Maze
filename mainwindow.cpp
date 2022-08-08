#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

using s21::MainWindow;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(std::make_unique<Ui::MainWindow>()) {
    ui->setupUi(this);
    controller_ = std::make_unique<Controller>(ui->widget);
    ConnectSignals();
}

MainWindow::~MainWindow() {}

void MainWindow::ConnectSignals() {
    connect(ui->newMazeButton, &QPushButton::clicked, this, &MainWindow::btnClicked);
    connect(ui->findPathButton, &QPushButton::clicked, this, &MainWindow::findPathBtnClicked);
    connect(ui->openFileButton, &QPushButton::clicked, this, &MainWindow::openFileBtnClicked);
}

void MainWindow::btnClicked() {
    controller_->SetHeight(ui->heightSpinBox->value());
    controller_->SetWidth(ui->widthSpinBox->value());
    controller_->GenerateMaze();
    /* ui->widget->setWidth(controller_->width()); */
    /* ui->widget->setHeight(controller_->height()); */
    /* ui->widget->setWalls(controller_->walls()); */
    /* ui->widget->update(); */
}

void MainWindow::findPathBtnClicked() {
    controller_->SearchWay(0, 2);
}

void MainWindow::openFileBtnClicked() {
    auto name = QFileDialog::getOpenFileName(nullptr,
                QObject::tr("Open File"),
                "./",
                QObject::tr("Text files(*.txt)"));
    if (!name.isEmpty()) {
        controller_->ReadLabyrinthFromFile(name.toStdString());
    }
}
