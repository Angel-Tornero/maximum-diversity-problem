#include "../include/RamificacionPoda.h"
#include "../include/Node.h"
#include <map>
#include <iostream>

RamificacionPoda::RamificacionPoda(std::vector<Element*> initialSolution) {
  initialSolution_ = initialSolution;
}

std::vector<Element*> RamificacionPoda::solve(MaximumDiversityProblem& problem) {
  changeSelected(initialSolution_);
  double lowerBound = calculateUpperBound(initialSolution_, problem.getS(), problem.getM());
  changeSelected(initialSolution_);
  std::vector<Node*> tree = {new Node()};
  int levelIni = 1;
  int nextLevel = levelIni;
  int counter;
  for (int i = 0; i < problem.getS().size() - problem.getM() + 1; i++) {
    std::vector<Element*> temp = tree[0]->partialSolution_;
    temp.push_back(problem.getS()[i]);
    tree.push_back(new Node(temp, problem.getS()[i]->getId()));
    nextLevel++;
    changeSelected(temp);
    if (calculateUpperBound(temp, problem.getS(), problem.getM()) < lowerBound) {
      tree[tree.size() - 1]->prune();
    }
    changeSelected(temp);
  }
  for (int i = 1; i < problem.getM(); i++) {
    counter = 0;
    for (int j = levelIni; j < nextLevel; j++) {
      if (tree[j]->isPruned()) {
        for (int k = tree[j]->label_; k <= problem.getS().size() - (problem.getM() - tree[j]->k_); k++) {
          tree.push_back(new Node());
        }
        continue;
      }
      double lowerUpperBound = 0;
      for (int k = tree[j]->label_; k <= problem.getS().size() - (problem.getM() - tree[j]->k_); k++) {
        std::vector<Element*> temp = tree[j]->partialSolution_;
        temp.push_back(problem.getS()[k]);
        tree.push_back(new Node(temp, problem.getS()[k]->getId()));
        changeSelected(temp);
        if (calculateUpperBound(temp, problem.getS(), problem.getM()) < lowerBound) {
          tree[tree.size() - 1]->prune();
        }
        changeSelected(temp);
        counter++;
      }
    }
    if (i + 1 == problem.getM()) {
      break;
    }
    levelIni = nextLevel;
    nextLevel += counter;
  }
  double bestZ = 0;
  std::vector<Element*> bestSolution;
  for (int i = 0; i < tree.size(); i++) {
    if (tree[i]->isPruned()) continue;
    double newZ = calculateZ(tree[i]->partialSolution_);
    if (newZ > bestZ) {
      bestZ = newZ;
      bestSolution = tree[i]->partialSolution_;
    }
  }
  
  return bestSolution;
}

double RamificacionPoda::calculateUB2(std::vector<Element*> elementSet, int m, int k) {
  std::vector<double> ZSel;
  for (int i = 0; i < elementSet.size(); i++) {
    if (elementSet[i]->isSelected()) continue;
    ZSel.push_back(calculateZSel(elementSet, elementSet[i]));
  }
  double UB2 = 0;
  for (int i = 0; i < m - k; i++) {
    int bestIndex = 0;
    for (int j = 0; j < ZSel.size(); j++) {
      if (ZSel[j] > ZSel[bestIndex]) {
        bestIndex = j;
      }
    }
    UB2 += ZSel[bestIndex];
    ZSel.erase(ZSel.begin() + bestIndex);
  }
  return UB2;
}

double RamificacionPoda::calculateZSel(std::vector<Element*> elementSet, Element* v) {
  double ZSel = 0;
  for (int i = 0; i < elementSet.size(); i++) {
    if (!elementSet[i]->isSelected()) continue;
    ZSel += calculateDistance(elementSet[i], v);
  }
  return ZSel;
}

double RamificacionPoda::calculateUB3(std::vector<Element*> elementSet, int m, int k) {
  std::vector<double> ZUnsel;
  for (int i = 0; i < elementSet.size(); i++) {
    if (elementSet[i]->isSelected()) continue;
    ZUnsel.push_back(calculateZUnsel(elementSet, elementSet[i], m, k));
  }
  double UB3 = 0;
  for (int i = 0; i < m - k; i++) {
    int bestIndex = 0;
    for (int j = 0; j < ZUnsel.size(); j++) {
      if (ZUnsel[j] > ZUnsel[bestIndex]) {
        bestIndex = j;
      }
    }
    UB3 += ZUnsel[bestIndex];
    ZUnsel.erase(ZUnsel.begin() + bestIndex);
  }
  return UB3;
}

double RamificacionPoda::calculateZUnsel(std::vector<Element*> elementSet, Element* v, int m, int k) {
  std::vector<double> dUnsel;
  for (int i = 0; i < elementSet.size(); i++) {
    if (elementSet[i]->isSelected()) continue;
    dUnsel.push_back(calculateDistance(elementSet[i], v));
  }
  double ZUnsel = 0;
  for (int i = 0; i < m - k - 1; i++) {
    int bestIndex = 0;
    for (int j = 0; j < dUnsel.size(); j++) {
      if (dUnsel[j] > dUnsel[bestIndex]) {
        bestIndex = j;
      }
    }
    ZUnsel += dUnsel[bestIndex];
    dUnsel.erase(dUnsel.begin() + bestIndex);
  }
  return ZUnsel / 2;
}

double RamificacionPoda::calculateUpperBound(std::vector<Element*> partialSolution, std::vector<Element*> elementSet, int m) {
  double upperBound = calculateZ(partialSolution) + calculateUB2(elementSet, m, partialSolution.size()) + calculateUB3(elementSet, m, partialSolution.size());
  return upperBound;
}

void RamificacionPoda::changeSelected(std::vector<Element*> elementSet) {
  for (int i = 0; i < elementSet.size(); i++) {
    elementSet[i]->toggleSelected();
  }
}