#include "Strategy.h"
#include "MaximumDiversityProblem.h"
#include "Element.h"

class RamificacionPoda: public Strategy {
  private:
    int LRCSize_;
    int iterations_;
    std::vector<Element*> initialSolution_;
  public:
    RamificacionPoda()=default;
    RamificacionPoda(std::vector<Element*> initialSolution);
    ~RamificacionPoda()=default;
    /**
     * @brief Solve the problem
     * 
     * @param problem 
     * @return std::vector<Element> 
     */
    std::vector<Element*> solve(MaximumDiversityProblem& problem);

    std::vector<Element*> generateSolution(MaximumDiversityProblem& problem);
    /**
     * @brief Calculate the element of the vector that is farthest from the center
     * of gravity, removes it from the vector and returns it
     * 
     * @param elementSet 
     * @return Element 
     */
    Element* extractFarthest(std::vector<Element*>& elementSet, Element& center);

    double calculateUB2(std::vector<Element*> selected, int m, int k);
    double calculateZSel(std::vector<Element*> sel, Element* v);

    double calculateUB3(std::vector<Element*> selected, int m, int k);
    double calculateZUnsel(std::vector<Element*> sel, Element* v, int m, int k);

    double calculateUpperBound(std::vector<Element*> partialSolution, std::vector<Element*> elementSet, int m);

    void changeSelected(std::vector<Element*> elementSet);
};