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
    s_.push_back(new Element(coordinates));
  }
  for (int i = 0; i < n_; i++) {
    d_.push_back(std::vector<double>());
    for (int j = 0; j < n_; j++) {
      d_[i].push_back(0.0);
    }
  }
  //calculateDistances();
}

MaximumDiversityProblem::~MaximumDiversityProblem() {}

void MaximumDiversityProblem::print() {
  std::cout << "n = " << n_ << "\nk = " << k_ << '\n';
  for (int i = 0; i < n_; i++) {
    std::cout << "Elemento " << i + 1 << " = \t[    ";
    for (int j = 0; j < k_; j++) {
      std::cout << s_[i]->getCoordinate(j) << "\t";
    }
    std::cout << "]\n";
  }
  /*std::cout << "\nDistances:\n";
  for (int i = 0; i < n_; i++) {
    for (int j = 0; j < n_; j++) {
      std::cout << d_[i][j] << "\t";
    }
    std::cout << '\n';
  }*/
}

/*void MaximumDiversityProblem::calculateDistances() {
  for (int i = 0; i < n_; i++) {
    for (int j = i + 1; j < n_; j++) {
      double sum = 0.0;
      for (int k = 0; k < k_; k++) {
        sum += (s_[i].getCoordinate(k) - s_[j].getCoordinate(k)) * (s_[i].getCoordinate(k) - s_[j].getCoordinate(k));
      }
      double distance = sqrt(sum);
      d_[i][j] = distance;
      d_[j][i] = distance;
    }
  }
}*/

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