#include "../include/Element.h"
#include <iostream>

Element::Element(std::vector<double>& coordinates) {
  coordinates_ = coordinates;
}

void Element::setCoordinate(int coordinate, double value) {
  coordinates_[coordinate] = value;
}

double Element::getCoordinate(int coordinate) {
  return coordinates_[coordinate];
}

int Element::dimensions() {
  return coordinates_.size();
}