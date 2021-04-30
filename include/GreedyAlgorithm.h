#include "Strategy.h"
#include "MaximumDiversityProblem.h"
#include "Element.h"

class GreedyAlgorithm: public Strategy {
  public:
    GreedyAlgorithm()=default;
    ~GreedyAlgorithm()=default;
    std::vector<Element> solve(MaximumDiversityProblem& problem);
    Element gravityCenter(std::vector<Element>& elementSet);
};