#include "Element.h"

#ifndef _NODE_
#define _NODE_

class Node {
  public:
    std::vector<Element*> partialSolution_;
    int k_;
    int label_;
    bool pruned_;

    Node();
    Node(std::vector<Element*> partialSolution, int label);
    void prune();
    bool isPruned();
};

#endif