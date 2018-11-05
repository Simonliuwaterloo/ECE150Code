#include<iostream>
#include <string>
#include <algorithm>
#include <cmath>
int main();
int interval_calculator();
struct interval;
struct interval{
	double a = 1;
	double b = 0;

};


int main(){
	interval_calculator();
	return 0;
}

int interval_calculator(){
	bool run = true;
	interval imedte;
	interval ms;
	while(run){
		std::string input;
		double a;
		double b;
		double c;
		double d;

		std::cout << "input :> ";
		std::cin >> input;
		if (input == "exit"){
			std::cout << "Bye bye: Terminating interval calculator program.";
			break;
		}
		else if (input == "enter"){
			std::cin >> a;
			std::cin >> b;
			if (a > b){

				std::cout << "Error: invalid interval as "<<a <<" > " << b << std::endl;
			}
			else{
				imedte.a = a;
				imedte.b = b;
			}
			if (imedte.a == 1 && imedte.b == 0){
				std::cout << "--" << std::endl;
			}
			else{
				std::cout << "[" << imedte.a << ", " << imedte.b << "]" << std::endl;

			}
		}
		else if (input == "negate"){
			if (imedte.a == 1 && imedte.b == 0){
				std::cout << "--" << std::endl;
			}
			else{
				double temp = imedte.a;
				imedte.a = -imedte.b;
				imedte.b = -temp;
				std::cout << "[" << imedte.a << ", " << imedte.b << "]" << std::endl;
			}
		}
		else if (input == "invert"){
			if (imedte.a == 1 && imedte.b == 0){
				std::cout << "--" << std::endl;
			}
			else if (imedte.a <= 0 && imedte.b >= 0){
				std::cout << "Error: division by zero" << std::endl << "--" << std::endl;
				imedte.a = 1;
				imedte.b = 0;
			}
			else{
				double tmp = imedte.a;
				imedte.a = 1/imedte.b;
				imedte.b = 1/tmp;
				std::cout << "[" << imedte.a << ", " << imedte.b << "]" << std::endl;
			}
		}
		else if (input == "ms"){
			if (imedte.a == 1 && imedte.b == 0){
				std::cout << "--" << std::endl;
			}
			else{
				ms.a = imedte.a;
				ms.b = imedte.b;
				std::cout << "[" << imedte.a << ", " << imedte.b << "]" << std::endl;
			}
		}
		else if (input == "mr"){
			if (imedte.a == 1 && imedte.b == 0){
				std::cout << "--" << std::endl;
			}
			else{
					if (ms.a == 1 && ms.b == 0){
						std::cout << "[" << imedte.a << ", " << imedte.b << "]" << std::endl;
					}
					else{
						imedte.a = ms.a;
						imedte.b = ms.b;
						std::cout << "[" << imedte.a << ", " << imedte.b << "]" << std::endl;
					}
			}
		}
		else if (input == "mc"){
			ms.a = 1;
			ms.b = 0;
			if (imedte.a == 1 && imedte.b == 0){
				std::cout << "--" << std::endl;
			}
			else{
				std::cout << "[" << imedte.a << ", " << imedte.b << "]" << std::endl;
			}
		}
		else if (input == "m+"){
			if (imedte.a == 1 && imedte.b == 0 && ms.a == 1 && imedte.b == 0){
				std::cout << "--" << std::endl;
			}
			else{
				ms.a += imedte.a;
				ms.b += imedte.b;
				std::cout << "[" << imedte.a << ", " << imedte.b << "]" << std::endl;
			}
		}
		else if (input == "m-"){
				if (imedte.a == 1 && imedte.b == 0 && ms.a == 1 && imedte.b == 0){
					std::cout << "--" << std::endl;
				}
				else{
					ms.a -= imedte.a;
					ms.b -= imedte.b;
					std::cout << "[" << imedte.a << ", " << imedte.b << "]" << std::endl;
				}
		}
		else if (input == "scalar_add"){
			std::cin >> c;
			if (imedte.a == 1 && imedte.b == 0){
				std::cout << "--" << std::endl;
			}
			else{

				imedte.a += c;
				imedte.b += c;
				std::cout << "[" << imedte.a << ", " << imedte.b << "]" << std::endl;
			}
		}
		else if (input == "scalar_subtract"){
			std::cin >> c;
					if (imedte.a == 1 && imedte.b == 0){
						std::cout << "--" << std::endl;
					}
					else{

						imedte.a -= c;
						imedte.b -= c;
						std::cout << "[" << imedte.a << ", " << imedte.b << "]" << std::endl;
					}
		}
		else if (input == "scalar_multiply"){
			std::cin >> c;
					if (imedte.a == 1 && imedte.b == 0){
						std::cout << "--" << std::endl;
					}
					else if (c > 0){
						imedte.a *= c;
						imedte.b *= c;
						std::cout << "[" << imedte.a << ", " << imedte.b << "]" << std::endl;
					}
					else{
						double temp = imedte.a;
						imedte.a = b*c;
						imedte.b = temp*c;
						std::cout << "[" << imedte.a << ", " << imedte.b << "]" << std::endl;
					}
		}
		else if (input == "scalar_divide"){
			std::cin >> c;
					if (imedte.a == 1 && imedte.b == 0){
						std::cout << "--" << std::endl;
					}
					else if (c > 0){
						imedte.a /= c;
						imedte.b /= c;
						std::cout << "[" << imedte.a << ", " << imedte.b << "]" << std::endl;
					}
					else if (c < 0){
						double temp = imedte.a;
						imedte.a = imedte.b/c;
						imedte.b = temp/c;
						std::cout << "[" << imedte.a << ", " << imedte.b << "]" << std::endl;
					}
					else if (c == 0){
						std::cout << "Error: division by zero" << std::endl;
						std::cout << "--" << std::endl;
						imedte.a = 1;
						imedte.b = 0;
					}
		}
		else if (input == "scalar_divided_by"){
			std::cin >> c;
				if (imedte.a == 1 && imedte.b == 0){
					std::cout << "--" << std::endl;
				}
				else if(imedte.a <= 0 && imedte.b >= 0){
					std::cout << "Error: division by zero" << std::endl;
					std::cout << "--" << std::endl;
					imedte.a = 1;
					imedte.b = 0;
				}
				else if (c > 0){
					double temp = imedte.a;
					imedte.a = c/imedte.b;
					imedte.b = c/temp;
					std::cout << "[" << imedte.a << ", " << imedte.b << "]" << std::endl;
				}
				else {

					imedte.a = c/imedte.a;
					imedte.b = c/imedte.b;
					std::cout << "[" << imedte.a << ", " << imedte.b << "]" << std::endl;
				}

		}
		else if (input == "interval_add"){
			std::cin >> c;
			std::cin >> d;
			if ( c > d ){
				std::cout << "Error: invalid interval as " << c << ">" << d << std::endl;
				if (imedte.a == 1 && imedte.b == 0){
					std::cout << "--" << std::endl;
				}
				else{
					std::cout << "[" << imedte.a << ", " << imedte.b << "]" << std::endl;
				}
			}
			else if (imedte.a == 1 && imedte.b == 0){
				std::cout << "--" << std::endl;
			}
			else{
				imedte.a += c;
				imedte.b += d;
				std::cout << "[" << imedte.a << ", " << imedte.b << "]" << std::endl;
			}

		}
		else if (input == "interval_subtract"){
			std::cin >> c;
			std::cin >> d;
			if ( c > d ){
				std::cout << "Error: invalid interval as " << c << ">" << d << std::endl;
				if (imedte.a == 1 && imedte.b == 0){
					std::cout << "--" << std::endl;
				}
				else{
					std::cout << "[" << imedte.a << ", " << imedte.b << "]" << std::endl;
				}
			}
			else if (imedte.a == 1 && imedte.b == 0){
				std::cout << "--" << std::endl;
			}
			else{
				imedte.a -= d;
				imedte.b -= c;
				std::cout << "[" << imedte.a << ", " << imedte.b << "]" << std::endl;
			}

		}
		else if (input == "interval_multiply"){
			std::cin >> c;
			std::cin >> d;
			if ( c > d ){
				std::cout << "Error: invalid interval as " << c << ">" << d << std::endl;
				if (imedte.a == 1 && imedte.b == 0){
					std::cout << "--" << std::endl;
				}
				else{
					std::cout << "[" << imedte.a << ", " << imedte.b << "]" << std::endl;
				}
			}
			else if (imedte.a == 1 && imedte.b == 0){
				std::cout << "--" << std::endl;
			}
			else{
				double min = imedte.a*c;
				double max = imedte.a*c;
				double values[4] = {imedte.a*c, imedte.a*d, imedte.b*c, imedte.b*d};
				for (std::size_t i = 1; i < 4; ++i){
					if (values[i] < min){
						min = values[i];
					}
					if (values[i] > max){
						max = values[i];
					}
				}
				imedte.a = min;
				imedte.b = max;
				std::cout << "[" << imedte.a << ", " << imedte.b << "]" << std::endl;
			}

		}
		else if (input == "interval_divide"){
			std::cin >> c;
			std::cin >> d;
			if ( c > d ){
				std::cout << "Error: invalid interval as " << c << ">" << d << std::endl;
				if (imedte.a == 1 && imedte.b == 0){
					std::cout << "--" << std::endl;
				}
				else{
					std::cout << "[" << imedte.a << ", " << imedte.b << "]" << std::endl;
				}
			}
			else if (imedte.a == 1 && imedte.b == 0){
				std::cout << "--" << std::endl;
			}
			else if (c == 0 || d == 0 || (c < 0 && d > 0)){
				std::cout << "Error: division by zero" << std::endl;
				imedte.a = 1;
				imedte.b = 0;
				std::cout << "--" << std::endl;
			}
			else{
				double min = imedte.a/c;
				double max = imedte.a/c;
				double values[4] = {imedte.a/c, imedte.a/d, imedte.b/c, imedte.b/d};
				for (std::size_t i = 1; i < 4; ++i){
					if (values[i] < min){
						min = values[i];
					}
					if (values[i] > max){
						max = values[i];
					}
				}
				imedte.a = min;
				imedte.b = max;
				std::cout << "[" << imedte.a << ", " << imedte.b << "]" << std::endl;
			}

		}
		else if (input == "intersect"){
			std::cin >> c;
			std::cin >> d;
			if (c > d){
				std::cout << "Error: invalid interval as " << c << " > " << d << std::endl;
				if (imedte.a == 1 && imedte.b == 0){
					std::cout << "--" << std::endl;
				}
				else{
					std::cout << "[" << imedte.a << ", " << imedte.b << "]" << std::endl;
				}
			}
			else if (imedte.a == 1 && imedte.b == 0){
					std::cout << "--" << std::endl;
			}
			else if (c <= imedte.b && d >= imedte.a){
				double values[4] = {imedte.a, imedte.b, c, d};
				std::sort(std::begin(values), std::end(values));
				imedte.a = values[1];
				imedte.b = values[2];
				std::cout << "[" << imedte.a << ", " << imedte.b << "]" << std::endl;
			}
			else{
				imedte.a = 1;
				imedte.b = 0;
				std::cout << "--" << std::endl;
			}
		}
		else if(input == "integers"){
			if (imedte.a == 1 && imedte.b == 0){
				std::cout << "--" << std::endl;
			}
			else{
				int start_num = std::ceil(imedte.a);
				int end_num = std::floor(imedte.b);
				for (double i = start_num; i < end_num; ++i){
					std::cout << i << ", ";
				}
				std::cout << end_num << std::endl;
				std::cout << "[" << imedte.a << ", " << imedte.b << "]" << std::endl;
			}
		}
		else if(input == "cartesian_integers"){
			std::cin >>c;
			std::cin >>d;
			if (c > d){
				std::cout << "Error: invalid interval as " << c << " > " << d << std::endl;
				if (imedte.a == 1 && imedte.b == 0){
					std::cout << "--" << std::endl;
				}
				else{
					std::cout << "[" << imedte.a << ", " << imedte.b << "]" << std::endl;
				}
			}

			else{
				if (imedte.a == 1 && imedte.b == 0){
					std::cout << "--" << std::endl;
				}
				else{
					if( (std::ceil(imedte.a) > std::floor(imedte.b))||(std::ceil(c) > std::floor(d)) ){
						std::cout << "[" << imedte.a << ", " << imedte.b << "]" << std::endl;
					}
					else{
						for (double i = std::ceil(imedte.a); i < std::floor(imedte.b); ++i){
							for (double j = std::ceil(c); j <= std::floor(d); ++j ){
								std::cout << "("<< i<<","<<j<<"), ";
							}
						}
						for (double j = std::ceil(c); j < std::floor(d); ++j ){
							std::cout << "("<< std::floor(imedte.b)<<","<<j<<"), ";
						}
						std::cout <<"("<< std::floor(imedte.b)<<","<<std::floor(d)<<")"<<std::endl;
						std::cout << "[" << imedte.a << ", " << imedte.b << "]" << std::endl;
					}
				}
			}
		}
		else{
			std::cout << "Error: illegal command" << std::endl;
		}
	}
	return 0;
}




