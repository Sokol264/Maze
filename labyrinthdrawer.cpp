#include "labyrinthdrawer.h"
#include <QDebug>

using s21::LabyrinthDrawer;

LabyrinthDrawer::LabyrinthDrawer(QWidget *parent) : QWidget{parent}, width_(5), height_(5) {}

void LabyrinthDrawer::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);

    painter.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::FlatCap));
    painter.drawLine(1, 1, 1, 499);
    painter.drawLine(1, 1, 499, 1);
//    painter.drawLine(499, 1, 499, 499);
//    painter.drawLine(1, 499, 499, 499);

    int koefWidth = 500 / width_;
    int koefHeight = 500 / height_;
    if (!walls_.empty()) {
        for (int i = 0; i < height_; ++i) {
            for (int j = 0; j < width_; ++j) {
                if (walls_[0][i][j])
                    painter.drawLine(j * (koefWidth) + (koefWidth), i * (koefHeight), j * (koefWidth) + (koefWidth), i * (koefHeight) + (koefHeight));
                if (walls_[1][i][j])
                    painter.drawLine(j * (koefWidth), i * (koefHeight) + (koefHeight), j * (koefWidth) + (koefWidth), i * (koefHeight) + (koefHeight));
            }
        }
    }
//    if (!walls_.empty()) {
//        for (int i = 0; i < height_; ++i) {
//            for (int j = 0; j < width_; ++j) {
//                int heightLeft = 500 % height_;
//                int widthLeft = 500 % width_;
//                int additionWidth = 1;
//                int additionHeight = 1;
//                if (!widthLeft)
//                    additionWidth = 0;
//                else
//                    widthLeft--;
//                if (!heightLeft)
//                    additionHeight = 0;
//                else
//                    heightLeft--;
//                qDebug() << additionWidth << ' ' << additionHeight << ' ';
//                if (walls_[0][i][j])
//                    painter.drawLine(j * (koefWidth + additionWidth) + (koefWidth + additionWidth), i * (koefHeight + additionHeight), j * (koefWidth + additionWidth) + (koefWidth + additionWidth), i * (koefHeight + additionHeight) + (koefHeight + additionHeight));
//                if (walls_[1][i][j])
//                    painter.drawLine(j * (koefWidth + additionWidth), i * (koefHeight + additionHeight) + (koefHeight + additionHeight), j * (koefWidth + additionWidth) + (koefWidth + additionWidth), i * (koefHeight + additionHeight) + (koefHeight + additionHeight));
//            }
//        }
//    }
}

void LabyrinthDrawer::setWidth(int value) {
    width_ = value;
}
void LabyrinthDrawer::setHeight(int value) {
    height_ = value;
}
void LabyrinthDrawer::setWalls(TripleVector value) {
    walls_ = value;
}
