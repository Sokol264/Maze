#ifndef LABYRINTHDRAWER_H
#define LABYRINTHDRAWER_H

#include <QWidget>
#include <QPainter>
#include <fstream>
#include <vector>

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

protected:
    void paintEvent(QPaintEvent *event);

private:
    int width_, height_;
    TripleVector walls_;

signals:

};

#endif // LABYRINTHDRAWER_H
