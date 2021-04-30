#include "MaximumDiversityProblem.h"
#include "Element.h"

#ifndef _STRATEGY_
#define _STRATEGY_

class Strategy {
  public:
    Strategy()=default;
    ~Strategy()=default;
    virtual std::vector<Element> solve(MaximumDiversityProblem& problem)=0;
    Element gravityCenter(std::vector<Element>& elementSet, int dimensions);
};

#endif