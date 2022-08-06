#include "facade.h"
#include <iostream>

using s21::Facade;

Facade::Facade() :
    fileManager_(std::make_unique<FileManager>()),
    mazeGenerator_(std::make_unique<EllerAlgorithm>()) {}

void Facade::GenerateMaze() {
    mazeGenerator_->setHeight(height_);
    mazeGenerator_->setWidth(width_);
    walls_ = mazeGenerator_->generateLabyrinth();
}

void Facade::ReadLabyrinthFromFile(const std::string &fileName) {
    fileManager_->readLabyrinthFile(fileName);
    walls_ = fileManager_->walls();
    width_ = fileManager_->width();
    height_ = fileManager_->height();
}

void Facade::SearchWay() {
    std::shared_ptr<IGraph> graph = std::make_shared<MatrixGraph>(walls_, width_, height_);
    std::cout << graph->VertexCount() << std::endl;
    std::cout << graph->EdgeCount() << std::endl;
    std::make_unique<SimpleSearch>(graph)->Execute();
}

void Facade::SetHeight(int value) {
    height_ = value;
}
void Facade::SetWidth(int value) {
    width_ = value;
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
