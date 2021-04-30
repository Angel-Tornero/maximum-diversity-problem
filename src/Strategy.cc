#include "../include/Strategy.h"
#include <iostream>

Element Strategy::gravityCenter(std::vector<Element>& elementSet, int dimensions) {
  std::vector<double> centerCoordinates(dimensions);
  for (int i = 0; i < dimensions; i++) {
    double value = 0.0;
    for (int j = 0; j < elementSet.size(); j++) {
      centerCoordinates[i] += elementSet[j].getCoordinate(i) / elementSet.size();
    }
  }
  return centerCoordinates;
}