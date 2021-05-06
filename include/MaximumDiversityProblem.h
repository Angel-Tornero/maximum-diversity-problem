#include <string>
#include <vector>
#include "Element.h"

#ifndef _PROBLEM_
#define _PROBLEM_

class MaximumDiversityProblem {
  private:
    int n_;                               //número de elementos
    int k_;                               //número de dimensiones de los elementos
    int m_;                               //tamaño del subconjunto de la solución
    std::vector<Element*> s_;              //conjunto de elementos
    std::vector<std::vector<double>> d_;  //matriz de distancias entre elementos

    //void calculateDistances();
  public:
    MaximumDiversityProblem(std::string& fileName, int m);
    ~MaximumDiversityProblem();
    void print();
    std::vector<Element*> getS();
    int getM();
    int getK();
    void setElementsAsNonChosen();
};

#endif