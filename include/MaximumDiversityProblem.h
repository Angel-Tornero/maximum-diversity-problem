#include <string>
#include <vector>
#include "Element.h"
#include "Node.h"

#ifndef _PROBLEM_
#define _PROBLEM_

/**
 * @class MaximumDiversityProblem
 * 
 */
class MaximumDiversityProblem {
  private:
    int n_;                               //número de elementos
    int k_;                               //número de dimensiones de los elementos
    int m_;                               //tamaño del subconjunto de la solución
    std::vector<Element*> s_;              //conjunto de elementos

  public:
    /**
     * @brief Construct a new Maximum Diversity Problem object
     * 
     * @param fileName 
     * @param m 
     */
    MaximumDiversityProblem(std::string& fileName, int m);

    /**
     * @brief Destroy the Maximum Diversity Problem object
     * 
     */
    ~MaximumDiversityProblem();

    /**
     * @brief Print the data of the problem
     * 
     */
    void print();

    /**
     * @brief Get the array of Elements of the problem
     * 
     * @return std::vector<Element*> 
     */
    std::vector<Element*> getS();

    /**
     * @brief Get the m value
     * 
     * @return int 
     */
    int getM();

    /**
     * @brief Get the k value
     * 
     * @return int 
     */
    int getK();

    /**
     * @brief Set the Elements As Non Chosen
     * 
     */
    void setElementsAsNonChosen();

};

#endif