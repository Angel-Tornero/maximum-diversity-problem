#include "../include/GreedyAlgorithm.h"
#include <iostream>

std::vector<Element*> GreedyAlgorithm::solve(MaximumDiversityProblem& problem) {
  std::vector<Element*> elementSet = problem.getS();
  std::vector<Element*> solution;
  Element gravityCenter = calculateGravityCenter(elementSet, problem.getK());
  do {
    solution.push_back(extractFarthest(elementSet, gravityCenter));
    gravityCenter = calculateGravityCenter(solution, problem.getK());
  } while (solution.size() < problem.getM());
  return solution;
}

Element* GreedyAlgorithm::extractFarthest(std::vector<Element*>& elementSet, Element& center) {
  int farthestElementIndex;
  double longestDistance = 0;
  for (int i = 0; i < elementSet.size(); i++) {
    double newDistance = calculateDistance(elementSet[i], &center);
    if (newDistance > longestDistance) {
      longestDistance = newDistance;
      farthestElementIndex = i;
    }
  }
  Element* farthestElement = elementSet[farthestElementIndex];
  elementSet.erase(elementSet.begin() + farthestElementIndex);
  return farthestElement;
}

