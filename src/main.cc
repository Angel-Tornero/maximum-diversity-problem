#include "../include/MaximumDiversityProblem.h"
#include "../include/GreedyAlgorithm.h"
#include "../include/GRASP.h"
#include "../include/RamificacionPoda.h"
#include <iostream>
#include <chrono>

int main(int argc, char* argv[]) {
  std::vector<std::string> problems = {"max_div_15_2", "max_div_20_2", "max_div_30_2", "max_div_15_3", "max_div_20_3", "max_div_30_3"};
  std::vector<int> ms = {2, 3, 4, 5};
  std::cout << "| Problema | n | k | m | z | S | CPU | nodos generados |\n|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|\n";
  
  for (int i = 0; i < problems.size(); i++) {
    for (int j = 0; j < ms.size(); j++) {
      std::string fileName = "problems/" + problems[i] + ".txt";
      int mValue = ms[j];
      std::cout << problems[i] << "|" << problems[i][8] << problems[i][9] << '|' << problems[i][problems[i].size() - 1] << '|' << ms[j] << '|';
      MaximumDiversityProblem problem(fileName, mValue);
      //Strategy* algorithm = new GRASP(l, k);
      Strategy* algorithm = new GRASP(3, 10);
      auto start = std::chrono::high_resolution_clock::now();
      std::vector<Element*> solution = algorithm->solve(problem);
      algorithm = new RamificacionPoda(solution);
      solution = algorithm->solve(problem);
      auto stop = std::chrono::high_resolution_clock::now();
      std::cout << algorithm->calculateZ(solution) << '|';
      std::cout << "{ ";
      for (int i = 0; i < solution.size(); i++) {
        solution[i]->print();
        std::cout << ((i == solution.size() - 1) ? " " : ", ");
      }
      std::cout << "}|";
      std::chrono::duration<double, std::milli> elapsed = stop - start;
      std::cout << elapsed.count() << " ms|" << ((RamificacionPoda*)algorithm)->getGenerated() << '\n';
    }
  }

  /*std::string file = "problems/max_div_15_2.txt";
  MaximumDiversityProblem problem(file, 5);
  
  Strategy* algoritmo = new GreedyAlgorithm;
  std::vector<Element*> initialSolution = algoritmo->solve(problem);
  algoritmo = new RamificacionPoda(initialSolution);

  std::vector<Element*> solution = algoritmo->solve(problem);
  for (int i = 0; i < solution.size(); i++) {
    solution[i]->print();
    std::cout << ((i == solution.size() - 1) ? " " : ", ");
  }
  std::cout << '\n';
  std::cout << "z = " << algoritmo->calculateZ(solution) << '\n';
  std::cout << ((RamificacionPoda*)algoritmo)->getGenerated();
  delete algoritmo;*/
  return 0;
}