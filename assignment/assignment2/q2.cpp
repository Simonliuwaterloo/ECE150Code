#include <iostream>

int main();
long int factorial(int number);
int main(){
  std::cout << factorial(12);
}

long int factorial(int number){
  long int base = 1;
  for (int n = 1; n <= number; ++n){
    base = base * n;
  }
  return base;
}
