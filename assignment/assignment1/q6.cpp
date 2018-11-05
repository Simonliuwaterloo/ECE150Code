#include <iostream>
double median(double x1, double x2, double x3);
int main();

int main(){
  std::cout << median(3.444, 34.43, 11.23);
  return 0;
}

double median(double x1, double x2, double x3){
  if ((x2 - x1)*(x3 - x1) < 0){
    return x1;
  }
  if ((x1 - x2)*(x3 - x2) < 0){
    return x2;
  }
  else{
    return x3;
  }
}
