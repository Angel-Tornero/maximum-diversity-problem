#include "MaximumDiversityProblem.h"
#include "Element.h"

#ifndef _STRATEGY_
#define _STRATEGY_

class Strategy {
  public:
    Strategy()=default;
    ~Strategy()=default;
    virtual std::vector<Element*> solve(MaximumDiversityProblem& problem)=0;
    Element calculateGravityCenter(std::vector<Element*>& elementSet, int dimensions);
    double calculateDistance(Element* elementA, Element* elementB);
    double calculateZ(std::vector<Element*>& solution);
    std::vector<Element*> localSearch(std::vector<Element*>& solution, std::vector<Element*> allElements);
    std::vector<Element*> bestNeighbour(std::vector<Element*>& solution, std::vector<Element*>& allElements);
};

#endif