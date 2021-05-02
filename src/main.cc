#include "../include/MaximumDiversityProblem.h"
#include "../include/GreedyAlgorithm.h"
#include <iostream>
#include <chrono>

int main(int argc, char* argv[]) {
  std::vector<std::string> problems = {"max_div_15_2", "max_div_20_2", "max_div_30_2", "max_div_15_3", "max_div_20_3", "max_div_30_3"};
  std::vector<int> ms = {2, 3, 4, 5};
  std::cout << "| Problema | n | k | m | z | S | CPU |\n|:-:|:-:|:-:|:-:|:-:|:-:|:-:|\n";
  
  for (int i = 0; i < problems.size(); i++) {
    for (int j = 0; j < ms.size(); j++) {
      std::cout << problems[i] << "|" << problems[i][8] << problems[i][9] << '|' << problems[i][problems.size() - 1] << '|' << ms[j] << '|';
      std::string fileName = "problems/" + problems[i] + ".txt";
      int mValue = ms[j];
      MaximumDiversityProblem problem(fileName, mValue);
      Strategy* algorithm = new GreedyAlgorithm;
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

  return 0;
}