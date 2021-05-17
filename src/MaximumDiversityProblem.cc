#include "../include/MaximumDiversityProblem.h"
#include <fstream>
#include <iostream>
#include <cmath>

MaximumDiversityProblem::MaximumDiversityProblem(std::string& fileName, int m) {
  m_ = m;
  std::ifstream inFile(fileName);
  inFile >> n_ >> k_;
  for (int i = 0; i < n_; i++) {
    std::vector<double> coordinates = {};
    for (int j = 0; j < k_; j++) {
      double value;
      inFile >> value;
      coordinates.push_back(value);
    }
    s_.push_back(new Element(coordinates, i + 1));
  }
}

MaximumDiversityProblem::~MaximumDiversityProblem() {
  for (int i = 0; i < s_.size(); i++) {
    delete s_[i];
  }
}

void MaximumDiversityProblem::print() {
  std::cout << "n = " << n_ << "\nk = " << k_ << '\n';
  for (int i = 0; i < n_; i++) {
    std::cout << "Elemento " << i + 1 << " = \t[    ";
    for (int j = 0; j < k_; j++) {
      std::cout << s_[i]->getCoordinate(j) << "\t";
    }
    std::cout << "]\n";
  }
}

std::vector<Element*> MaximumDiversityProblem::getS() {
  return s_;
}

int MaximumDiversityProblem::getM() {
  return m_;
}

int MaximumDiversityProblem::getK() {
  return k_;
}

void MaximumDiversityProblem::setElementsAsNonChosen() {
  for (int i = 0; i < s_.size(); i++) {
    if (s_[i]->isChosen()) s_[i]->toggleChosen();
  }
}
