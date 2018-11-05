#include <iostream>
#include <cmath>

int main();
int roots_number(double a, double b, double c);
int roots(double a, double b, double c);

int main(){
  roots(3, -2, 5);
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

int roots(double a, double b, double c){
  if (roots_number(a, b, c) == 0){
    std::cout << "the complex roots are " << std::endl << -b/(2*a) << '+' << sqrt(4*a*c - b*b)/(2*a) << 'j'  <<  std::endl;
    std::cout << -b/(2*a) << '-' << sqrt(4*a*c - b*b)/(2*a) << 'j' <<std::endl;
  }
  else if (roots_number(a, b, c) == 1){
    std::cout << "the root is " << -b/(2*a);
  }
  else{
    double root1 = -b/2*a + sqrt(b*b - 4*a*c)/(2*a);
    double root2 = -b/2*a + sqrt(b*b - 4*a*c)/(2*a);
    std::cout << "the roots are" << root1 << root2 << std::endl;

  }
  return 0;
}
