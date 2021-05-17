#include <vector>

#ifndef _ELEMENT_
#define _ELEMENT_
/**
 * @class Element
 * 
 */
class Element {
  private:
    std::vector<double> coordinates_;
    bool chosen_;
    bool selected_;
    int id_;
  
  public:
    /**
     * @brief Construct a new Element object
     * 
     */
    Element();

    /**
     * @brief Construct a new Element object
     * @param coordinates_;
     * @param id 
     */
    Element(std::vector<double> coordinates_, int id);

    /**
     * @brief Destroy the Element object
     * 
     */
    ~Element()=default;

    /**
     * @brief Set the value of a coordinate
     * 
     * @param coordinate 
     * @param value 
     */
    void setCoordinate(int coordinate, double value);

    /**
     * @brief Get a coordinate value
     * 
     * @param coordinate 
     * @return double 
     */
    double getCoordinate(int coordinate);

    /**
     * @brief Get the dimensions
     * 
     * @return int 
     */
    int dimensions();

    /**
     * @brief Print the element
     * 
     */
    void print();

    /**
     * @brief Indicate is the element have been chosen for the solution
     * 
     * @return true 
     * @return false 
     */
    bool isChosen();

    /**
     * @brief Indicate is the element have been selected for the partial solution
     * 
     * @return true 
     * @return false 
     */
    bool isSelected();

    /**
     * @brief Toggle the chosen property
     * 
     */
    void toggleChosen();

    /**
     * @brief Toggle the selected property
     * 
     */
    void toggleSelected();

    /**
     * @brief Get the id value
     * 
     * @return int 
     */
    int getId();
};

#endif