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
        adjMatrix_.push_back(cols);
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
                SetValuesToMatrix(i, j, sz, type);
            }
        }
    }
}

inline void MatrixGraph::SetValuesToMatrix(size_t i, size_t j, size_t sz, BorderType type) {
    int row = GetRowValue(i, j , sz);
    int col = GetColValue(i, j, sz, type);
    adjMatrix_[row][col] = true;
    adjMatrix_[col][row] = true;
}

inline size_t MatrixGraph::GetRowValue(size_t i, size_t j, size_t sz) {
    return i * sz + j;
}

inline size_t MatrixGraph::GetColValue(size_t i, size_t j, size_t sz, BorderType type) {
    return type == BorderType::kRightBorder ? (i * sz + j) : (i * sz + j + sz);
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
    for (size_t i = 0, sz = adjMatrix_.size(); i != sz; ++i) {
        for (size_t j = 0, jSize = adjMatrix_[i].size(); j != jSize; ++j) {
            std::cout << adjMatrix_[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

