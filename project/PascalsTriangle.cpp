#include <iostream>
#ifndef MARMOSET_TESTING
int main();
#endif
int pascal_triangle(int n);
int pascal_triangle_recursive(int n);
int generate_number(int row, int column);
#ifndef MARMOSET_TESTING
int main(){
	return 0;
}
#endif

int pascal_triangle(int n){
	long int row_number[n + 1];
	long int temp[n + 1];
    temp[0] = 1;
    row_number[0] = 1;
    std::cout << "1" << std::endl;
    for (std::size_t i = 1; i <= n; i++)
    {
        for (std::size_t k = 1; k < n; k++)
        {
            row_number[k] = temp[k - 1] + temp[k];      
        }
        row_number[i] = 1;
        for (std::size_t l = 0; l <= i; l++)
        {
            std::cout << row_number[l];
            std::cout << " ";
            temp[l] = row_number[l];
        }
        std::cout << std::endl;
    }
	return (n+2)*(n+1)/2;
}
int pascal_triangle_recursive(int n){
	for (std::size_t i = 0; i <= n; ++i){
		for (std::size_t k = 1; k <= i + 1; ++k){
			std::cout << generate_number(i, k);
			std::cout << " ";
		}
		std::cout << std::endl;
	}
	return (n+2)*(n+1)/2;
}
int generate_number(int row, int column){
	if (row < column - 1 || row < 0 || column < 0){
		return 0;
	}
	else if (column == 1 || column == row + 1){
		return 1;
	}
	else{
		return generate_number(row - 1, column - 1) + generate_number(row - 1, column);
	}
}

