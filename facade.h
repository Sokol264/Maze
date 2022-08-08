#ifndef FACADE_H
#define FACADE_H

#include "filemanager.h"
#include "elleralgorithm.h"
#include "labyrinthdrawer.h"

class Facade
{
public:
    using TripleVector = std::vector<std::vector<std::vector<int>>>;
    using DoubleVector = std::vector<std::vector<int>>;

    Facade();
    void GenerateMaze();
    void setHeight(int value);
    void setWidth(int value);

    int width();
    int height();
    TripleVector walls();

private:
    int width_, height_;
    TripleVector walls_;
    DoubleVector cave_;

    FileManager fileManager;
    EllerAlgorithm mazeGenerator;
};

#endif // FACADE_H
