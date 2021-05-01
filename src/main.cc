#include "../include/MaximumDiversityProblem.h"
#include "../include/GreedyAlgorithm.h"
#include <iostream>

int main(int argc, char* argv[]) {
  std::string fileName = argv[1];
  int mValue = atoi(argv[2]);
  MaximumDiversityProblem problem(fileName, mValue) ;
  Strategy* algorithm = new GreedyAlgorithm;
  std::vector<Element*> solution = algorithm->solve(problem);
  std::cout << "Solución:\n";
  for (int i = 0; i < solution.size(); i++) {
    solution[i]->print();
    std::cout << '\n';
  }
  std::cout << "z = \n" << algorithm->calculateZ(solution) << '\n';

  std::vector<Element*> bestLocal = algorithm->localSearch(solution, problem.getS());
  std::cout << "\nSolución:\n";
  for (int i = 0; i < bestLocal.size(); i++) {
    bestLocal[i]->print();
    std::cout << '\n';
  }
  std::cout << "z = \n" << algorithm->calculateZ(bestLocal) << '\n';

  return 0;
}