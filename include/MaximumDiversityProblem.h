#include <string>
#include <vector>
#include "Element.h"

#ifndef _PROBLEM_
#define _PROBLEM_

class MaximumDiversityProblem {
  private:
    int n_;                               //número de elementos
    int k_;                               //número de dimensiones de los elementos
    std::vector<Element> s_;              //conjunto de elementos
    std::vector<std::vector<double>> d_;  //matriz de distancias entre elementos

    void calculateDistances();
  public:
    MaximumDiversityProblem(std::string& fileName);
    ~MaximumDiversityProblem();
    void print();
    std::vector<Element> getS();
};

#endif