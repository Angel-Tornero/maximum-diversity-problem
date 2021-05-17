#include <vector>

#ifndef _ELEMENT_
#define _ELEMENT_

class Element {
  private:
    std::vector<double> coordinates_;
    bool chosen_;
    bool selected_;
    int id_;
  
  public:
    Element();
    Element(std::vector<double>, int id);
    ~Element()=default;
    void setCoordinate(int coordinate, double value);
    double getCoordinate(int coordinate);
    int dimensions();
    void print();
    bool isChosen();
    bool isSelected();
    void toggleChosen();
    void toggleSelected();
    int getId();
};

#endif