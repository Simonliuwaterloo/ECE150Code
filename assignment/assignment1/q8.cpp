#include <iostream>
int main();
int roots_number(double a, double b, double c);

int main(){
  std::cout << roots_number(2, 4, 2);
  return 0;
}
int roots_number(double a, double b, double c){
  double delta = b*b - 4*a*c;
  if (delta < 0){
    return 0;
  }
  if (delta == 0){
    return 1;
  }
  else{
    return 2;
  }
}
