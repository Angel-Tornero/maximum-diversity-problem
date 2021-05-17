#include "../include/Element.h"
#include <iostream>

Element::Element() {
  chosen_ = false;
  selected_ = false;
}

Element::Element(std::vector<double> coordinates, int id) {
  coordinates_ = coordinates;
  id_ = id;
  chosen_ = false;
  selected_ = false;
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

void Element::print() {
  std::cout << "[ ";
  for (int i = 0; i < dimensions(); i++) {
    std::cout << coordinates_[i] << ((i == dimensions() - 1)? " " : ", ");
  }
  std::cout << "]";
}

bool Element::isChosen() {
  return chosen_;
}

bool Element::isSelected() {
  return selected_;
}

void Element::toggleChosen() {
  chosen_ = !chosen_;
}

void Element::toggleSelected() {
  selected_ = !selected_;
}

int Element::getId() {
  return id_;
}