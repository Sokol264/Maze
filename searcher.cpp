#include "searcher.h"
#include <iostream>

using s21::Searcher;

Searcher::Searcher(const TripleVector &labirintMatrix, int width, int height) :
        v_(width * height), e_(0) {
    for (size_t i = 0; i < labirintMatrix.size(); ++i) {
        for (size_t j = 0; j < labirintMatrix[i].size(); ++j) {
            for (size_t k = 0; k < labirintMatrix[i][j].size(); ++k) {
                if (labirintMatrix[i][j][k] == 0)
                    ++e_;
            }
        }
    }
}

void Searcher::Execute() {
    std::cout << "v_ = " << v_ << std::endl;
    std::cout << "e_ = " << e_ << std::endl;
}
