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
  for (int i = 0; i < n_; i++) {
    d_.push_back(std::vector<double>());
    for (int j = 0; j < n_; j++) {
      d_[i].push_back(0.0);
    }
  }
  //calculateDistances();
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

std::vector<Node*> MaximumDiversityProblem::generateTree() {
  std::vector<Node*> tree = {new Node()};
  int levelIni = 1;
  int nextLevel = levelIni;
  int counter;
  for (int i = 0; i < n_ - m_ + 1; i++) {
    std::vector<Element*> temp = tree[0]->partialSolution_;
    temp.push_back(s_[i]);
    tree.push_back(new Node(temp, s_[i]->getId()));
    nextLevel++;
  }

  for (int i = 1; i < m_; i++) {
    counter = 0;
    for (int j = levelIni; j < nextLevel; j++) {
      if (i == 2)std::cout << tree[j]->label_ << '\n';
      for (int k = tree[j]->label_; k <= n_ - (m_ - tree[j]->k_); k++) {
        std::vector<Element*> temp = tree[j]->partialSolution_;
        temp.push_back(s_[k]);
        tree.push_back(new Node(temp, s_[k]->getId()));
        counter++;
      }
    }
    levelIni = nextLevel;
    nextLevel += counter;
  }

  //
  for (int i = 0; i < tree.size(); i++) {
    std::cout << "x = { ";
    for (int j = 0; j < tree[i]->k_; j++) {
      std::cout << tree[i]->partialSolution_[j]->getId() << ' ';
    }
    std::cout << "}\n";
  }
  //
  return tree;
}