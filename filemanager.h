#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include <fstream>
class FileManager
{
public:
    using TripleVector = std::vector<std::vector<std::vector<int>>>;
    using DoubleVector = std::vector<std::vector<int>>;
    using Vector = std::vector<int>;

    FileManager();
    void readLabyrinthFile(std::string filename);
    void readCaveFile(std::string filename);

    void writeLabyrinthFile(std::string filename);
    void writeCaveFile(std::string filename);

    // Setters
    void setWidth(int value);
    void setHeight(int value);
    void setWalls(TripleVector value);
    void setCave(DoubleVector value);

    // Getters
    int width();
    int height();
    TripleVector walls();
    DoubleVector cave();
private:
    void initMazeVectors();
    void initCaveVectors();
    void clearParameters();

    int width_, height_;

    std::ifstream inputFile;
    std::ofstream outputFile;

    TripleVector walls_;
    DoubleVector cave_;
};

#endif // FILEMANAGER_H
