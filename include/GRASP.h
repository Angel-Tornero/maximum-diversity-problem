#include "Strategy.h"
#include "MaximumDiversityProblem.h"
#include "Element.h"

/**
 * @class GRASP
 * 
 */
class GRASP: public Strategy {
  private:
    int LRCSize_;
    int iterations_;
  public:
    /**
     * @brief Construct a new GRASP object
     * 
     */
    GRASP()=default;

    /**
     * @brief Construct a new GRASP object
     * 
     * @param size 
     * @param iterations 
     */
    GRASP(int size, int iterations);

    /**
     * @brief Destroy the GRASP object
     * 
     */
    ~GRASP()=default;
    /**
     * @brief Solve the problem
     * 
     * @param problem 
     * @return std::vector<Element> 
     */
    std::vector<Element*> solve(MaximumDiversityProblem& problem);

    /**
     * @brief Generate a solution using LRC
     * 
     * @param problem 
     * @return std::vector<Element*> 
     */
    std::vector<Element*> generateSolution(MaximumDiversityProblem& problem);
    /**
     * @brief Calculate the element of the vector that is farthest from the center
     * of gravity, removes it from the vector and returns it
     * 
     * @param elementSet 
     * @return Element 
     */
    Element* extractFarthest(std::vector<Element*>& elementSet, Element& center);

    
};