#include <vector>

#ifndef _ELEMENT_
#define _ELEMENT_

class Element {
  private:
    std::vector<double> coordinates_;
  
  public:
    Element()=default;
    Element(std::vector<double>&);
    ~Element()=default;
    void setCoordinate(int coordinate, double value);
    double getCoordinate(int coordinate);
    int dimensions();
};

#endif