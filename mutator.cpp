#include "geometricobject.h"

int main() {
  double side1, side2, side3;
  std::string color;
  bool filled;
  int filled_entry;

  Triangle triangle(side1, side2, side3);
  
 std::cout<<"What is the color ? \n";
 std::cin>>color;

 std::cout<<"Is the Triangle filled ?, 1 for yes and 0 for No \n";
 std::cin>>filled_entry;
 

 if(filled_entry == 1){
 	filled = true;
 }else if(filled_entry==0){
 filled = false;
 }
 
 //MUTATOR(MODIFY) FUNCTIONS OF THE PROGRAM
 triangle.setColor(color);
 triangle.setFill(filled);
 
  std::cout << "Perimeter of triangle: " << triangle.getPerimeter() << std::endl;
  
  std::cout << triangle.toString() << std::endl;

  return 0;
}

