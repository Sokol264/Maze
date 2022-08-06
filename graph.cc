#include "graph.h"
#include <iostream>

using s21::MatrixGraph;

MatrixGraph::MatrixGraph(int v, int e) : v_(v), e_(e) {}

MatrixGraph::MatrixGraph(const TripleVector& labyrinthMatrix, int w, int h) :
    v_(w * h),
    e_(0) {
    InitEdgeCount(labyrinthMatrix);
    InitData(labyrinthMatrix);
}

void MatrixGraph::InitEdgeCount(const TripleVector& labyrinthMatrix) {
    for (size_t i = 0; i < labyrinthMatrix.size(); ++i) {
        for (size_t j = 0; j < labyrinthMatrix[i].size(); ++j) {
            for (size_t k = 0; k < labyrinthMatrix[i][j].size(); ++k) {
                std::cout << labyrinthMatrix[i][j][k] << ' ';
                if (!labyrinthMatrix[i][j][k])
                    ++e_;
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

void MatrixGraph::InitData(const TripleVector& labyrinthMatrix) {
    if (labyrinthMatrix.size()) {
    }
}

void MatrixGraph::SetVertexCount(int value)  {
    v_ = value;
}

void MatrixGraph::SetEdgeCount(int value) {
    e_ = value;
}

int MatrixGraph::VertexCount() const {
    return v_;
}

int MatrixGraph::EdgeCount() const {
    return e_;
}









