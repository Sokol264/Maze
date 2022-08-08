#ifndef CONTROLLER_H_
#define CONTROLLER_H_

namespace s21 { class Controller; }

#include <QWidget>

#include "../facade.h"

class s21::Controller {
    using TripleVector = std::vector<std::vector<std::vector<int>>>;
 public:
    Controller();
    void SetHeight(int value);
    void SetWidth(int value);
    void SetDrawer(QWidget *widget);
    void GenerateMaze();
    void SearchWay();
    void ReadLabyrinthFromFile(const std::string &fileName);
    // Getters
    int width();
    int height();
    TripleVector walls();
 private:
    std::unique_ptr<Facade> facade_;
};

#endif  // CONTROLLER_H_
