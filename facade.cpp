#include "facade.h"

Facade::Facade() {}

void Facade::GenerateMaze() {
    mazeGenerator.setHeight(height_);
    mazeGenerator.setWidth(width_);
    walls_ = mazeGenerator.generateLabyrinth();
}

void Facade::setHeight(int value) {
    height_ = value;
}
void Facade::setWidth(int value) {
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
