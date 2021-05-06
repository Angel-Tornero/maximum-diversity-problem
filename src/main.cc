#include "../include/MaximumDiversityProblem.h"
#include "../include/GreedyAlgorithm.h"
#include "../include/GRASP.h"
#include <iostream>
#include <chrono>

int main(int argc, char* argv[]) {
  std::vector<std::string> problems = {"max_div_15_3", "max_div_20_3", "max_div_30_3"};//, "max_div_15_3", "max_div_20_3", "max_div_30_3"};
  std::vector<int> ms = {2, 3, 4, 5};
  std::vector<int> lrcsizes = {2, 3};
  std::cout << "| Problema | n | k | m | Iter | |LRC| | z | S | CPU |\n|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|\n";
  
  for (int i = 0; i < problems.size(); i++) {
    for (int j = 0; j < ms.size(); j++) {
      std::string fileName = "problems/" + problems[i] + ".txt";
      int mValue = ms[j];
      MaximumDiversityProblem problem(fileName, mValue);
      for (int k = 10; k < 30; k += 10) {
        for (int l = 2; l < 4; l++) {
          std::cout << problems[i] << "|" << problems[i][8] << problems[i][9] << '|' << problems[i][problems[i].size() - 1] << '|' << ms[j] << '|' << k << '|' << l << '|';
          MaximumDiversityProblem problem(fileName, mValue);
          Strategy* algorithm = new GRASP(l, k);
          auto start = std::chrono::high_resolution_clock::now();
          std::vector<Element*> solution = algorithm->solve(problem);
          auto stop = std::chrono::high_resolution_clock::now();
          std::cout << algorithm->calculateZ(solution) << '|';
          std::cout << "{ ";
          for (int i = 0; i < solution.size(); i++) {
            solution[i]->print();
            std::cout << ((i == solution.size() - 1) ? " " : ", ");
          }
          std::cout << "}|";
          std::chrono::duration<double, std::milli> elapsed = stop - start;
          std::cout << elapsed.count() << " ms\n";
        }
      }
    }
  }

  return 0;
}