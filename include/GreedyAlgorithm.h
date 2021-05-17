#include "Strategy.h"
#include "MaximumDiversityProblem.h"
#include "Element.h"

/**
 * @class GreedyAlgorithm
 * 
 */
class GreedyAlgorithm: public Strategy {
  public:
    /**
     * @brief Construct a new Greedy Algorithm object
     * 
     */
    GreedyAlgorithm()=default;

    /**
     * @brief Destroy the Greedy Algorithm object
     * 
     */
    ~GreedyAlgorithm()=default;

    /**
     * @brief Solve the problem
     * 
     * @param problem 
     * @return std::vector<Element> 
     */
    std::vector<Element*> solve(MaximumDiversityProblem& problem);
    
    /**
     * @brief Calculate the element of the vector that is farthest from the center
     * of gravity, removes it from the vector and returns it
     * 
     * @param elementSet 
     * @return Element 
     */
    Element* extractFarthest(std::vector<Element*>& elementSet, Element& center);

    
};