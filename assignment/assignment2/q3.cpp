#include <iostream>
int main();
int fibo(int term_number);
int main(){
  fibo(10);
  return 0;
}
int fibo(int term_number){
  int term0 = 0;
  int term1 = 1;
  for (int n = 1; n <= term_number; ++n){
    std::cout << term1 << std::endl;
    int tmp = term1;
    term1 = term0 + term1;
    term0 = tmp;
  }
  return 0;
}
