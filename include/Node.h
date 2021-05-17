#include "Element.h"

#ifndef _NODE_
#define _NODE_

/**
 * @class Node
 * 
 */
class Node {
  public:
    std::vector<Element*> partialSolution_;
    int k_;
    int label_;
    bool pruned_;

    /**
     * @brief Construct a new Node object
     * 
     */
    Node();

    /**
     * @brief Construct a new Node object
     * 
     * @param partialSolution 
     * @param label 
     */
    Node(std::vector<Element*> partialSolution, int label);

    /**
     * @brief Destroy the Node object
     * 
     */
    ~Node()=default;

    /**
     * @brief Prune a node
     * 
     */
    void prune();

    /**
     * @brief Indicate if a node is pruned
     * 
     * @return true 
     * @return false 
     */
    bool isPruned();
};

#endif