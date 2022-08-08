#include "controller.h"

using s21::Controller;

Controller::Controller(QWidget *drawer) : facade_(std::make_unique<Facade>(drawer)) {}

void Controller::SetHeight(int value) {
    facade_->SetHeight(value);
}

void Controller::SetWidth(int value) {
    facade_->SetWidth(value);
}

void Controller::GenerateMaze() {
    facade_->GenerateMaze();
}

void Controller::ReadLabyrinthFromFile(const std::string &fileName) {
    facade_->ReadLabyrinthFromFile(fileName);
}

void Controller::SearchWay(int start_index, int end_index) {
    facade_->SearchWay(start_index, end_index);
}

int Controller::width() {
    return facade_->width();
}

int Controller::height() {
    return facade_->height();
}

typename Controller::TripleVector Controller::walls() {
    return facade_->walls();
}

