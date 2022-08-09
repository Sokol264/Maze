#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Controller/controller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
namespace s21 { class MainWindow; }
QT_END_NAMESPACE

class s21::MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void ConnectSignals();

private:
    std::unique_ptr<Ui::MainWindow> ui;
    std::unique_ptr<Controller> controller_;

private slots:
    void btnClicked();
    void findPathBtnClicked();
    void openFileBtnClicked();
};
#endif // MAINWINDOW_H
