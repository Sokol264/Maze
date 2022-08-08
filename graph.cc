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
                if (!labyrinthMatrix[i][j][k])
                    ++e_;
            }
        }
    }
}

void MatrixGraph::InitData(const TripleVector& labyrinthMatrix) {
    if (labyrinthMatrix.size()) {
        ReserveMemory();
        FillData(labyrinthMatrix);
    }
}

void MatrixGraph::ReserveMemory() {
    for (int i = 0; i < v_; ++i) {
        std::vector<bool> cols(v_, false);
        data_.push_back(cols);
    }
}

void MatrixGraph::FillData(const TripleVector& labyrinthMatrix) {
    ReadBorders(labyrinthMatrix[0], BorderType::kRightBorder);
    ReadBorders(labyrinthMatrix[1], BorderType::kDownBorder);
}

void MatrixGraph::ReadBorders(const DoubleVector &borders, BorderType type) {
    for (size_t i = 0, sz = borders.size(); i != sz; ++i) {
        for (size_t j = 0, jSize = borders[i].size(); j != jSize; ++j) {
            if (!borders[i][j]) {
                int row = i * sz + j;
                int col = type == BorderType::kRightBorder ? (i * sz + j + 1) : (i * sz + j + sz);
                data_[row][col] = true;
                data_[col][row] = true;
            }
        }
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

void MatrixGraph::Print() const {
    for (size_t i = 0, sz = data_.size(); i != sz; ++i) {
        for (size_t j = 0, jSize = data_[i].size(); j != jSize; ++j) {
            std::cout << data_[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

