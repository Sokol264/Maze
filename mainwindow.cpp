#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->newMazeButton, &QPushButton::clicked, this, &MainWindow::btnClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::btnClicked() {
    facade.setHeight(ui->heightSpinBox->value());
    facade.setWidth(ui->widthSpinBox->value());
    facade.GenerateMaze();
    ui->widget->setWidth(facade.width());
    ui->widget->setHeight(facade.height());
    ui->widget->setWalls(facade.walls());
    ui->widget->update();
}
