#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class GeometricObject {
  // class definition for GeometricObject
};
class Triangle : public GeometricObject {
  public:
  std::string color;
  bool filled;
  	
  	void setColor(string newValue) {
    color = newValue;
  	}
  	
  	void setFill(bool newValue) {
    filled = newValue;
  	}
  
    Triangle() : side1(1.0), side2(1.0), side3(1.0) {}
    
    Triangle(double side1, double side2, double side3) : side1(side1), side2(side2), side3(side3) {}
    
    double getSide1() const { return side1; }
    double getSide2() const { return side2; }
    double getSide3() const { return side3; }
    
    void setSide1(double side1) { this->side1 = side1; }
    void setSide2(double side2) { this->side2 = side2; }
    void setSide3(double side3) { this->side3 = side3; }
    
    double getPerimeter() const { return side1 + side2 + side3; }
    
    std::string toString() const {
      std::stringstream ss;
      ss << "Triangle: side1 = " << side1 << " side2 = " << side2 << " side3 = " << side3;
      return ss.str();
    }

  private:
    double side1;
    double side2;
    double side3;
};

