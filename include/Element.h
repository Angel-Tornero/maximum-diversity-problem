#include <vector>

#ifndef _ELEMENT_
#define _ELEMENT_

class Element {
  private:
    std::vector<double> coordinates_;
    bool chosen_;
  
  public:
    Element();
    Element(std::vector<double>);
    ~Element()=default;
    void setCoordinate(int coordinate, double value);
    double getCoordinate(int coordinate);
    int dimensions();
    void print();
    bool isChosen();
    void toggleChosen();
};

#endif