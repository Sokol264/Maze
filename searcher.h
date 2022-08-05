#ifndef FINDWAY_H_
#define FINDWAY_H_
#include <vector>

namespace s21 { class Searcher; }

class s21::Searcher {
    using TripleVector = std::vector<std::vector<std::vector<int>>>;
 public:
    Searcher(const TripleVector &labirintMatrix, int w, int h);
    void Execute();
 
 private:
    int v_;
    int e_;
};

#endif  // FINDWAY_H_
