#ifndef CONTROLLER_H_
#define CONTROLLER_H_

namespace s21 { class Controller; }

#include <QWidget>

#include "../facade.h"

class s21::Controller {
    using TripleVector = std::vector<std::vector<std::vector<int>>>;
 public:
    Controller(QWidget *drawer);
    void SetHeight(int value);
    void SetWidth(int value);
    void GenerateMaze();
    void SearchWay(int start_index, int end_index);
    void ReadLabyrinthFromFile(const std::string &fileName);
    // Getters
    int width();
    int height();
    TripleVector walls();
 private:
    std::unique_ptr<Facade> facade_;
};

#endif  // CONTROLLER_H_
