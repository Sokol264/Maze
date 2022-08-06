#ifndef FINDWAY_H_
#define FINDWAY_H_
#include <vector>
#include "graph.h"

namespace s21 {
class ISearch;
class SimpleSearch;
}

class s21::ISearch {
 public:
    virtual void Execute() const = 0;
};

class s21::SimpleSearch final : public ISearch {
 public:
    SimpleSearch(std::shared_ptr<IGraph> graph);
    void Execute() const override;
 private:
    std::shared_ptr<IGraph> graph_;
};

#endif  // FINDWAY_H_
