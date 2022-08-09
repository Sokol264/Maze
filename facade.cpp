#include "facade.h"

using s21::Facade;
using s21::LabyrinthDrawer;

Facade::Facade(QWidget *drawer) :
    drawer_(InitDrawer(drawer)),
    fileManager_(std::make_unique<FileManager>()),
    mazeGenerator_(std::make_unique<EllerAlgorithm>()) {}

void Facade::GenerateMaze() {
    mazeGenerator_->setHeight(height_);
    mazeGenerator_->setWidth(width_);
    walls_ = mazeGenerator_->generateLabyrinth();
    drawer_->setWalls(walls_);
    drawer_->setWidth(width_);
    drawer_->setHeight(height_);
    drawer_->update();
}

void Facade::ReadLabyrinthFromFile(const std::string &fileName) {
    fileManager_->readLabyrinthFile(fileName);
    walls_ = fileManager_->walls();
    width_ = fileManager_->width();
    height_ = fileManager_->height();
    drawer_->setWalls(walls_);
    drawer_->setWidth(width_);
    drawer_->setHeight(height_);
    drawer_->update();
}

void Facade::SearchWay(int start_index, int end_index) {
    std::shared_ptr<IGraph> graph = std::make_shared<MatrixGraph>(walls_, width_, height_);
    std::make_unique<SimpleSearch>(graph)->Execute();
    graph->Print();
}

void Facade::SetHeight(int value) {
    height_ = value;
}

void Facade::SetWidth(int value) {
    width_ = value;
}

inline LabyrinthDrawer* Facade::InitDrawer(QWidget *drawer) {
    return static_cast<LabyrinthDrawer*>(drawer);
}

int Facade::width() {
    return width_;
}
int Facade::height() {
    return height_;
}
Facade::TripleVector Facade::walls() {
    return walls_;
}
