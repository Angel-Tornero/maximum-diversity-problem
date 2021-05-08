#include "../include/GRASP.h"
#include <iostream>
#include <random>

GRASP::GRASP(int size, int iterations) {
  LRCSize_ = size;
  iterations_ = iterations;
}

std::vector<Element*> GRASP::solve(MaximumDiversityProblem& problem) {
  srand(time(NULL));
  std::vector<Element*> elementSet = problem.getS();
  std::vector<Element*> currentSolution = generateSolution(problem);
  std::vector<Element*> bestSolution = currentSolution;
  int bestZ = calculateZ(bestSolution);
  int it = 0;
  do {
    currentSolution = localSearch(currentSolution, elementSet);
    int newZ = calculateZ(currentSolution);
    if (newZ > bestZ) {
      bestZ = newZ;
      bestSolution = currentSolution;
    }
    problem.setElementsAsNonChosen();
    currentSolution = generateSolution(problem);
    it++;
  } while (it < iterations_);
  return bestSolution;
}

std::vector<Element*> GRASP::generateSolution(MaximumDiversityProblem& problem) {
  std::vector<Element*> elementSet = problem.getS();
  std::vector<Element*> solution;
  Element gravityCenter = calculateGravityCenter(elementSet, problem.getK());
  do {
    solution.push_back(extractFarthest(elementSet, gravityCenter));
    gravityCenter = calculateGravityCenter(solution, problem.getK());
  } while (solution.size() < problem.getM());
  return solution;
}

Element* GRASP::extractFarthest(std::vector<Element*>& elementSet, Element& center) {
  int farthestElementIndex;
  std::vector<Element*> LRC;
  for (int k = 0; k < LRCSize_; k++) {
    double longestDistance = 0;
    for (int i = 0; i < elementSet.size(); i++) {
      if (elementSet[i]->isChosen()) continue;
      double newDistance = calculateDistance(elementSet[i], &center);
      if (newDistance > longestDistance) {
        longestDistance = newDistance;
        farthestElementIndex = i;
      }
    }
    Element* farthestElement = elementSet[farthestElementIndex];
    farthestElement->toggleChosen();
    LRC.push_back(farthestElement);
  }
  int randomIndex = rand() % LRC.size();
  Element* randomElement = LRC[randomIndex];
  for (int i = 0; i < LRC.size(); i++) {
    if (i == randomIndex) continue;
    LRC[i]->toggleChosen();
  }
  return randomElement;
}

