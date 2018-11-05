#include<iostream>

int main();

int main(){
  long int sum = 0;
  for (int n = 1; n <= 150150; ++n){
    sum = sum + n;
  }
  std::cout << sum;
}
