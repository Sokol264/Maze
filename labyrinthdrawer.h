#ifndef LABYRINTHDRAWER_H
#define LABYRINTHDRAWER_H

#include <QWidget>
#include <QPainter>
#include <fstream>
#include <vector>

enum DrawerCase {
    Maze = 1, Path = 2, Cave = 4
};

class LabyrinthDrawer : public QWidget
{
    Q_OBJECT
public:
    using TripleVector = std::vector<std::vector<std::vector<int>>>;
    using DoubleVector = std::vector<std::vector<int>>;
    using Vector = std::vector<int>;

    explicit LabyrinthDrawer(QWidget *parent = nullptr);
    void setWidth(int value);
    void setHeight(int value);
    void setWalls(TripleVector value);
    void setPath(std::vector<std::pair<int,int>> path);
    void enableDrawerCase(char key);


protected:
    void paintEvent(QPaintEvent *event);

private:
    bool drawPathFlag, drawMazeFlag, drawCaveFlag;
    int width_, height_;
    std::vector<std::pair<int, int>> mazePath_;
    TripleVector walls_;
    DoubleVector cave_;

};

#endif // LABYRINTHDRAWER_H
