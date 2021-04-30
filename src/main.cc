#include "../include/MaximumDiversityProblem.h"
#include "../include/GreedyAlgorithm.h"
#include <iostream>

int main(int argc, char* argv[]) {
  std::string fileName = argv[1];
  MaximumDiversityProblem problem(fileName);
  Strategy* algorithm = new GreedyAlgorithm;
  std::vector<Element> vector = problem.getS();
  algorithm->gravityCenter(vector, vector[0].dimensions());

  return 0;
}