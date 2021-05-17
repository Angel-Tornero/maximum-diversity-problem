#include "../include/Node.h"

Node::Node() {
  label_ = 0;
  k_ = 0;
  pruned_ = false;
}

Node::Node(std::vector<Element*> partialSolution, int label) {
  partialSolution_ = partialSolution;
  k_ = partialSolution.size();
  label_ = label;
  pruned_ = false;
}

void Node::prune() {
  pruned_ = true;
}

bool Node::isPruned() {
  return pruned_;
}