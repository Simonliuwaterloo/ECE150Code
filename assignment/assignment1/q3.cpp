#include <iostream>
#include<cmath>
int main();
double arithmetic(double x1, double x2, double x3, double x4, double x5);
double geometric (double x1, double x2, double x3, double x4, double x5);
double harmonic(double x1, double x2, double x3, double x4, double x5);
double largest_of_mean(double input1, double input2, double input3);
int main(){
  std::cout << arithmetic(2, 3, 5, 7, 9) << std::endl
            << geometric(2, 3, 5, 7, 9) << std::endl
            << harmonic(2, 3, 5, 7, 9) << std::endl
            << largest_of_mean(arithmetic(2, 3, 5, 7, 9),  geometric(2, 3, 5, 7, 9), harmonic(2, 3, 5, 7, 9)) <<std::endl;
  return 0;
}

double arithmetic(double x1, double x2, double x3, double x4, double x5){
  return (x1 + x2 + x3 + x4 + x5)/5;
}
double geometric(double x1, double x2, double x3, double x4, double x5){
  return pow((x1*x2*x3*x4*x5),1.0/5.0);
}
double harmonic(double x1, double x2, double x3, double x4, double x5){
  return 5/(1/x1 + 1/x2 + 1/x3 + 1/x4 + 1/x5);
}
double largest_of_mean(double input1, double input2, double input3){
	if (input1 > input2){
		if (input1 > input3){
			return input1;
		}
		else{
			return input3;
		}
  }
	 else{
		if (input1 > input3){
			return input2;
		}
		else if (input3 > input2){
		  return input3;
		}
		else{
			return input2;
		}
}
}
