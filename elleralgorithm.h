#ifndef ELLERALGORITHM_H
#define ELLERALGORITHM_H

#include <vector>
#include <random>

enum WallType {
    Right = 0, Lower
};

class EllerAlgorithm
{
public:
    using TripleVector = std::vector<std::vector<std::vector<int>>>;
    using DoubleVector = std::vector<std::vector<int>>;
    using Vector = std::vector<int>;

    EllerAlgorithm();
    TripleVector generateLabyrinth();
    void setWidth(int value);
    void setHeight(int value);
private:
    std::vector<int> row;
    int width, height;

    void AssignNewSet(int &setNumber);
    void CreateVerticalWallsInRow(int index, TripleVector &result);
    void CreateHorizontalWallsInRow(int index, TripleVector &result);
    void FinishLastRow(TripleVector &result);
    bool ThrowCoin();
    void UniteSets(int a, int b);
    int UniqueSetCount(int number);
};

#endif // ELLERALGORITHM_H
