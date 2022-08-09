#include "searcher.h"
#include <iostream>

using s21::SimpleSearch;

SimpleSearch::SimpleSearch(std::shared_ptr<IGraph> graph) : graph_(graph) {}

void SimpleSearch::Execute() const {
    std::cout << "search" << std::endl;
}
