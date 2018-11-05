#include <iostream>
double addition(double input_x, double input_y);
double subtraction(double input_x, double input_y);
double division(double input_x, double input_y);
double multiplication(double input_x, double input_y);
double calculate(double operand1, char operation, double operand2);
int main();

int main(){
  std::cout << calculate(1,'+', 2) << std::endl;
  return 0;
}

double addition(double input_x, double input_y){
  return input_x + input_y;
}
double subtraction(double input_x, double input_y){
  return input_x - input_y;
}
double division(double input_x, double input_y){
  return input_x/input_y;
}
double multiplication(double input_x, double input_y){
  return input_x*input_y;
}
double calculate(double operand1, char operation, double operand2){
  if (operation == '+'){
    return addition(operand1, operand2);
  }
  else if (operation == '-'){
    return subtraction(operand1, operand2);
  }
  else if (operation == '/'){
    return division(operand1, operand2);
  }
  else if (operation == '*'){
    return multiplication(operand1, operand2);
  }
  else{
    std::cout << "wrong operation";
    return 0;
  }
}
