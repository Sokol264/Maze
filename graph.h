#ifndef GRAPH_H_
#define GRAPH_H_
#include <vector>

namespace s21 {
class IGraph;
class MatrixGraph;
}

class s21::IGraph {
 public:
    virtual void SetVertexCount(int value) = 0;
    virtual void SetEdgeCount(int value) = 0;
    virtual int VertexCount() const = 0;
    virtual int EdgeCount() const = 0;
    virtual ~IGraph() {}
};

class s21::MatrixGraph final : public IGraph {
    using TripleVector = std::vector<std::vector<std::vector<int>>>;
    using Data = std::vector<std::vector<int>>;

 public:
    MatrixGraph(int v, int e);
    MatrixGraph(const TripleVector& labyrinthMatrix, int width, int height);
    void SetVertexCount(int value) override;
    void SetEdgeCount(int value) override;
    int VertexCount() const override;
    int EdgeCount() const override;

 private:
    void InitEdgeCount(const TripleVector& labyrinthMatrix);
    void InitData(const TripleVector& labyrinthMatrix);


 private:
    int v_;
    int e_;
    Data data_;
 
};

#endif  // GRAPH_H_
