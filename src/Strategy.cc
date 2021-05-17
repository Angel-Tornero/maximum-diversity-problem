#include "../include/Strategy.h"
#include <iostream>
#include <cmath>

Element Strategy::calculateGravityCenter(std::vector<Element*>& elementSet, int dimensions) {
  std::vector<double> centerCoordinates(dimensions);
  for (int i = 0; i < dimensions; i++) {
    for (int j = 0; j < elementSet.size(); j++) {
      centerCoordinates[i] += elementSet[j]->getCoordinate(i) / elementSet.size();
    }
  }
  return Element(centerCoordinates, 0);
}

double Strategy::calculateDistance(Element* elementA, Element* elementB) {
  double sum = 0.0;
  for (int i = 0; i < elementA->dimensions(); i++) {
    sum += (elementA->getCoordinate(i) - elementB->getCoordinate(i)) * (elementA->getCoordinate(i) - elementB->getCoordinate(i));
  }
  return sqrt(sum);
}

double Strategy::calculateZ(std::vector<Element*>& solution) {
  double z = 0.0;
  for (int i = 0; i < solution.size(); i++) {
    for (int j = i + 1; j < solution.size(); j++) {
      z += calculateDistance(solution[i], solution[j]);
    }
  }
  return z;
}

std::vector<Element*> Strategy::localSearch(std::vector<Element*>& solution, std::vector<Element*> allElements) {
  std::vector<Element*> currentSolution = solution;
  double bestZ = calculateZ(solution);
  do {
    std::vector<Element*> newSolution = bestNeighbour(currentSolution, allElements);
    double newZ = calculateZ(newSolution);
    if (bestZ >= newZ) break;
    bestZ = newZ;
    currentSolution = newSolution;
  } while (true);
  return currentSolution;
}

std::vector<Element*> Strategy::bestNeighbour(std::vector<Element*>& solution, std::vector<Element*>& allElements) {
  double bestZ = calculateZ(solution);
  int bestReplacedIndex = 0;
  int bestReplacerIndex = 0;
  std::vector<Element*> bestSolution = solution;
  for (int i = 0; i < allElements.size(); i++) {
    if (allElements[i]->isChosen()) continue;
    for (int j = 0; j < solution.size(); j++) {
      std::vector<Element*> newSolution = solution;
      newSolution[j] = allElements[i];
      double newZ = calculateZ(newSolution);
      if (newZ > bestZ) {
        bestZ = newZ;
        bestSolution = newSolution;
        bestReplacedIndex = j;
        bestReplacerIndex = i;
      }
    }
  }
  solution[bestReplacedIndex]->toggleChosen();
  allElements[bestReplacerIndex]->toggleChosen();
  return bestSolution;
}