
#include <iostream>
double min(double x1, double x2, double x3);
int main();

int main(){
  std::cout << min(1.34, 3.45, 6.78);
  return 0;
}
double min(double x1, double x2, double x3){
	if (x1 < x2){
		if (x1 < x3){
			  return x1;
		}
		else{
			  return x3;
		}
  }
	 else{
		if (x1 < x3){
			  return x2;
		}
		else if (x3 < x2){
		    return x3;
		}
		else{
			return x2;
		}
}
}
