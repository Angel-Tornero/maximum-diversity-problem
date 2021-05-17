#include "MaximumDiversityProblem.h"
#include "Element.h"

#ifndef _STRATEGY_
#define _STRATEGY_

/**
 * @class Strategy
 * 
 */
class Strategy {
  public:
    /**
     * @brief Construct a new Strategy object
     * 
     */
    Strategy()=default;

    /**
     * @brief Destroy the Strategy object
     * 
     */
    ~Strategy()=default;

    /**
     * @brief Solve the problem
     * 
     * @param problem 
     * @return std::vector<Element*> 
     */
    virtual std::vector<Element*> solve(MaximumDiversityProblem& problem)=0;

    /**
     * @brief Calculates the center of gravity
     * 
     * @param elementSet 
     * @param dimensions 
     * @return Element 
     */
    Element calculateGravityCenter(std::vector<Element*>& elementSet, int dimensions);

    /**
     * @brief Calculates the distance between two elements
     * 
     * @param elementA 
     * @param elementB 
     * @return double 
     */
    double calculateDistance(Element* elementA, Element* elementB);

    /**
     * @brief Calculates Z from a solution
     * 
     * @param solution 
     * @return double 
     */
    double calculateZ(std::vector<Element*>& solution);

    /**
     * @brief Perform a local search from a solution
     * 
     * @param solution 
     * @param allElements 
     * @return std::vector<Element*> 
     */
    std::vector<Element*> localSearch(std::vector<Element*>& solution, std::vector<Element*> allElements);

    /**
     * @brief Returns the best neighbour solution from a given solution
     * 
     * @param solution 
     * @param allElements 
     * @return std::vector<Element*> 
     */
    std::vector<Element*> bestNeighbour(std::vector<Element*>& solution, std::vector<Element*>& allElements);
};

#endif