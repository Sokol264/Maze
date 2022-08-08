#include "controller.h"

using s21::Controller;

Controller::Controller() : facade_(std::make_unique<Facade>()) {}

void Controller::SetHeight(int value) {
    facade_->SetHeight(value);
}

void Controller::SetWidth(int value) {
    facade_->SetWidth(value);
}

void Controller::SetDrawer(QWidget *widget) {
    facade_->SetDrawer(widget);
}

void Controller::GenerateMaze() {
    facade_->GenerateMaze();
}

void Controller::ReadLabyrinthFromFile(const std::string &fileName) {
    facade_->ReadLabyrinthFromFile(fileName);
}

void Controller::SearchWay() {
    facade_->SearchWay();
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

