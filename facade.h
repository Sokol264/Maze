#ifndef FACADE_H
#define FACADE_H

#include "filemanager.h"
#include "elleralgorithm.h"
#include "labyrinthdrawer.h"
#include "searcher.h"
#include <memory>

namespace s21 { class Facade; }

class s21::Facade {

public:
    using TripleVector = std::vector<std::vector<std::vector<int>>>;
    using DoubleVector = std::vector<std::vector<int>>;

    Facade();
    void GenerateMaze();
    void ReadLabyrinthFromFile(const std::string &fileName);
    void SearchWay();
    void SetHeight(int value);
    void SetWidth(int value);
    int width();
    int height();
    TripleVector walls();

private:
    int width_, height_;
    TripleVector walls_;
    DoubleVector cave_;

    std::unique_ptr<FileManager> fileManager_;
    std::unique_ptr<EllerAlgorithm> mazeGenerator_;
    std::unique_ptr<s21::Searcher> searcher_;
};

#endif // FACADE_H
