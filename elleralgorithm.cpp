#include "elleralgorithm.h"

using s21::EllerAlgorithm;

EllerAlgorithm::EllerAlgorithm() : width(0), height(0) {}

EllerAlgorithm::TripleVector EllerAlgorithm::generateLabyrinth() {
    int setNumber = 1;
    row = std::vector<int>(width, 0);
    TripleVector result = TripleVector(2);
    for (int i = 0; i < 2; ++i) {
        result[i] = DoubleVector(height);
        for (int j = 0; j < height; ++j) {
            result[i][j] = Vector(width);
        }
    }

    for (int i = 0; i < height; ++i) {
        AssignNewSet(setNumber);
        CreateVerticalWallsInRow(i, result);
        CreateHorizontalWallsInRow(i, result);
    }
    FinishLastRow(result);
    return result;
}

void EllerAlgorithm::AssignNewSet(int &setNumber) {
    for (int j = 0; j < width; ++j) {
        if (row[j] == 0) {
            row[j] = setNumber++;
        }
    }
}

void EllerAlgorithm::CreateVerticalWallsInRow(int index, TripleVector &result) {
    for (int j = 0; j < width - 1; ++j) {
        if (ThrowCoin() || row[j] == row[j + 1]) {
            result[Right][index][j] = 1;
        } else {
            UniteSets(row[j], row[j + 1]);
        }
    }
    result[Right][index][width - 1] = 1;
}

void EllerAlgorithm::CreateHorizontalWallsInRow(int index, TripleVector &result) {
    for (int j = 0; j < width; ++j) {
        if (ThrowCoin() && UniqueSetCount(row[j]) != 1) {
            result[Lower][index][j] = 1;
            row[j] = 0;
        }
    }
}

void EllerAlgorithm::FinishLastRow(TripleVector &result) {
    for (int j = 0; j < width; ++j) {
        result[Lower][height - 1][j] = 1;
        if (row[j] != row[j + 1]) {
            result[Right][height - 1][j] = 0;
            UniteSets(row[j], row[j + 1]);
        }
    }
//    result[Right][height - 1][width - 1] = 1;
}

bool EllerAlgorithm::ThrowCoin() {
    return rand() % 2;
}

int EllerAlgorithm::UniqueSetCount(int number) {
    int count = 0;
    for (int i = 0; i < width; ++i) {
        if (row[i] == number) count++;
    }
    return count;
}

void EllerAlgorithm::UniteSets(int a, int b) {
    for (int i = 0; i < width; ++i) {
        if (row[i] == b) row[i] = a;
    }
}

void EllerAlgorithm::setWidth(int value) {
    width = value;
}
void EllerAlgorithm::setHeight(int value) {
    height = value;
}
