#ifndef SRC_GRAPH_H_
#define SRC_GRAPH_H_
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
    virtual void Print() const = 0;
    virtual ~IGraph() {}
};

class s21::MatrixGraph final : public IGraph {
    using TripleVector = std::vector<std::vector<std::vector<int>>>;
    using DoubleVector = std::vector<std::vector<int>>;
    using Data = std::vector<std::vector<bool>>;
    enum class BorderType {
        kRightBorder,
        kDownBorder
    };

 public:
    MatrixGraph(int v, int e);
    MatrixGraph(const TripleVector& labyrinthMatrix, int width, int height);
    void SetVertexCount(int value) override;
    void SetEdgeCount(int value) override;
    int VertexCount() const override;
    int EdgeCount() const override;
    void Print() const override;

 private:
    void InitEdgeCount(const TripleVector& labyrinthMatrix);
    void InitData(const TripleVector& labyrinthMatrix);
    void ReserveMemory();
    void FillData(const TripleVector& borders);
    void ReadBorders(const DoubleVector& borders, BorderType type);
    void SetValuesToMatrix(size_t i, size_t j, size_t sz, BorderType type);
    size_t GetColValue(size_t i, size_t j, size_t sz, BorderType type);
    size_t GetRowValue(size_t i, size_t j, size_t sz);
    

 private:
    int v_;
    int e_;
    Data adjMatrix_;
 
};

#endif  // SRC_GRAPH_H_
