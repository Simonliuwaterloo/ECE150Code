/*
 * rooling_average.cpp
 *
 *  Created on: Oct 1, 2018
 *      Author: simonli
 */
#include <iostream>
#include <vector>
#include <assert.h>
float rolling_average(double number_1, double number_2, double number_3);
#ifndef MARMOSET_TESTING
int main();
#endif

#ifndef MARMOSET_TESTING
int main(){
	std::vector<int> numbers;
	int number;
	for(int count = 0; count <= count + 1; ++count ){
		std::cout << "Enter a number." << std::endl;
		std::cin >> number ;
		assert(number >= 0);
		numbers.insert(numbers.begin(), number);
		if (count >= 2){
			std::cout << "rolling average is: ";
			std::cout << rolling_average(numbers[0], numbers[1], numbers[2]);
			std::cout << std::endl;

		}
	}
	return 0;
}
#endif
float rolling_average(double number_1, double number_2, double number_3){
	return (number_1 + number_2 + number_3)/3;
}
