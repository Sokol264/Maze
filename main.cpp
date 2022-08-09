#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    srand(time(NULL));
    QApplication a(argc, argv);
    s21::MainWindow w;
    w.show();
    return a.exec();
}
