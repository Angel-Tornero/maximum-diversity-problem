#include "Strategy.h"
#include "MaximumDiversityProblem.h"
#include "Element.h"

/**
 * @class RamificacionPoda
 * 
 */
class RamificacionPoda: public Strategy {
  private:
    int LRCSize_;
    int iterations_;
    std::vector<Element*> initialSolution_;
    int generated_;
  public:
    /**
     * @brief Construct a new Ramificacion Poda object
     * 
     */
    RamificacionPoda()=default;

    /**
     * @brief Construct a new Ramificacion Poda object
     * 
     * @param initialSolution 
     */
    RamificacionPoda(std::vector<Element*> initialSolution);

    /**
     * @brief Destroy the Ramificacion Poda object
     * 
     */
    ~RamificacionPoda()=default;

    /**
     * @brief Solve the problem
     * 
     * @param problem 
     * @return std::vector<Element> 
     */
    std::vector<Element*> solve(MaximumDiversityProblem& problem);

    /**
     * @brief Calculate UB2 value
     * 
     * @param selected 
     * @param m 
     * @param k 
     * @return double 
     */
    double calculateUB2(std::vector<Element*> selected, int m, int k);

    /**
     * @brief Calculate ZSel value from an element
     * 
     * @param sel 
     * @param v 
     * @return double 
     */
    double calculateZSel(std::vector<Element*> sel, Element* v);

    /**
     * @brief Calculate UB3 value 
     * 
     * @param selected 
     * @param m 
     * @param k 
     * @return double 
     */
    double calculateUB3(std::vector<Element*> selected, int m, int k);

    /**
     * @brief Calculate ZUnsel value from an element
     * 
     * @param sel 
     * @param v 
     * @param m 
     * @param k 
     * @return double 
     */
    double calculateZUnsel(std::vector<Element*> sel, Element* v, int m, int k);
    
    /**
     * @brief Calculates the upper bound value from a partial solution
     * 
     * @param partialSolution 
     * @param elementSet 
     * @param m 
     * @return double 
     */
    double calculateUpperBound(std::vector<Element*> partialSolution, std::vector<Element*> elementSet, int m);

    /**
     * @brief Change the given elements property selected
     * 
     * @param elementSet 
     */
    void changeSelected(std::vector<Element*> elementSet);

    /**
     * @brief Get the number of generated nodes
     * 
     * @return int 
     */
    int getGenerated();
};