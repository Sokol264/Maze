#include "labyrinthdrawer.h"
#include <QDebug>

LabyrinthDrawer::LabyrinthDrawer(QWidget *parent) : QWidget{parent}, width_(1), height_(1) {}

void LabyrinthDrawer::paintEvent(QPaintEvent *event) {

    Q_UNUSED(event);
    QPainter painter(this);

    int cellWidth = 500 / width_;
    int cellHeight = 500 / height_;

    painter.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::FlatCap));
    painter.drawLine(1, 1, 1, 499);
    painter.drawLine(1, 1, 499, 1);
    painter.drawLine(499, 1, 499, 499);
    painter.drawLine(1, 499, 499, 499);

    if (drawMazeFlag) {
        if (!walls_.empty()) {
            for (int i = 0; i < height_; ++i) {
                for (int j = 0; j < width_; ++j) {
                    if (walls_[0][i][j])
                        painter.drawLine(j * cellWidth + cellWidth, i * cellHeight, j * cellWidth + cellWidth, i * cellHeight + cellHeight);
                    if (walls_[1][i][j])
                        painter.drawLine(j * cellWidth, i * cellHeight + cellHeight, j * cellWidth + cellWidth, i * cellHeight + cellHeight);
                }
            }
        }
    }

    painter.setPen(QPen(Qt::red, 2, Qt::SolidLine, Qt::FlatCap));
    if (drawPathFlag) {
        if (!mazePath_.empty()) {
            auto prevCell = mazePath_.begin();
            for (auto curCell = mazePath_.begin(); curCell != mazePath_.end(); ++curCell) {
                painter.drawLine(prevCell->second * cellWidth + cellWidth/2, prevCell->first * cellHeight + cellHeight/2, curCell->second * cellWidth + cellWidth/2, curCell->first * cellHeight + cellHeight/2);
                prevCell = curCell;
            }
        }
    }

    if (drawCaveFlag) {
        if (!cave_.empty()) {
            for (int i = 0; i < height_; ++i) {
                for (int j = 0; j < width_; ++j) {
                    if (cave_[i][j]) {
                        painter.drawRect(i, j, cellWidth, cellHeight);
                    }
                }
            }
        }
    }
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
void LabyrinthDrawer::setPath(std::vector<std::pair<int,int>> path) {
    mazePath_ = path;
}
void LabyrinthDrawer::enableDrawerCase(char key) {
    drawMazeFlag = key & Maze;
    drawPathFlag = key & Path;
    drawCaveFlag = key & Cave;
}
