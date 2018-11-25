#include "Polynomial.h"
#include <iostream>

void init_poly( poly_t &p, double const init_coeffs[], unsigned int const init_degree ){
	if (p.a_coeffs != nullptr){
			delete[] p.a_coeffs;
	}
	p.a_coeffs = new double[init_degree + 1];
	for (std::size_t k = 0; k < (init_degree + 1); ++k){
		p.a_coeffs[k] = init_coeffs[k];
	}
	p.degree = init_degree;
}
void destroy_poly( poly_t &p ){
	delete[] p.a_coeffs;
	p.a_coeffs = nullptr;
	p.degree = 0;
}
unsigned int poly_degree( poly_t const &p ){
	if (p.a_coeffs == nullptr){
		throw 0;
	}
	return p.degree;
}
double poly_coeff(poly_t const &p, unsigned int n){
	if (n <= p.degree){
		return p.a_coeffs[n];
	}
	else if (n > p.degree){
		return 0;
	}
	else{
		throw 0;
	}
}
double poly_val(poly_t const &p, double const x){
	if (p.a_coeffs == nullptr){
		throw 0;
	}
	double result = p.a_coeffs[p.degree];

	for (int k = p.degree; k > 0; --k){
		result = result*x +p.a_coeffs[k - 1];

	}

	return result;
}
void poly_add( poly_t &p, poly_t const &q){
	if (p.a_coeffs == nullptr || q.a_coeffs == nullptr){
		throw 0;
	}
	int newsize = (p.degree > q.degree)? (p.degree + 1) : (q.degree + 1);
	double new_list[newsize];
	if (p.degree >= q.degree){
		for (std::size_t k = 0; k < q.degree + 1; ++k ){
			new_list[k] = p.a_coeffs[k] + q.a_coeffs[k];
		}
		for (int k = q.degree + 1; k < newsize; ++k){
			new_list[k] = p.a_coeffs[k];
		}
	}
	else if (p.degree < q.degree){
		for (std::size_t k = 0; k < p.degree + 1; ++k ){
			new_list[k] = p.a_coeffs[k] + q.a_coeffs[k];
		}
		for (std::size_t k = p.degree + 1; k < newsize; ++k){
			new_list[k] = q.a_coeffs[k];
		}
	}


	/*for (int i = 0; i < newsize; ++i){
			std::cout << new_list[i] << std::endl;
	}*/


	for (int i = newsize - 1; i >= 0; --i){
		if (new_list[i] == 0){
			--newsize;
		}
		else{
			break;
		}
	}
	if (newsize == p.degree + 1){
		for (int j = 0; j < newsize; ++j){
			p.a_coeffs[j] = new_list[j];
		}
	}
	else{
		delete[] p.a_coeffs;
		p.a_coeffs = new double[newsize];
		for (int j = 0; j < newsize; ++j){
			p.a_coeffs[j] = new_list[j];
		}
		p.degree = newsize - 1;
	}
}
void poly_subtract( poly_t &p, poly_t const &q){
	if (p.a_coeffs == nullptr || q.a_coeffs == nullptr){
		throw 0;
	}
	int newsize = (p.degree > q.degree)? (p.degree + 1) : (q.degree + 1);
	double new_list[newsize];
	if (p.degree >= q.degree){
		for (std::size_t k = 0; k < q.degree + 1; ++k ){
			new_list[k] = p.a_coeffs[k] - q.a_coeffs[k];
		}
		for (int k = q.degree + 1; k < newsize; ++k){
			new_list[k] = p.a_coeffs[k];
		}
	}
	else if (p.degree < q.degree){
		for (std::size_t k = 0; k < p.degree + 1; ++k ){
			new_list[k] = p.a_coeffs[k] - q.a_coeffs[k];
		}
		for (std::size_t k = p.degree + 1; k < newsize; ++k){
			new_list[k] = -q.a_coeffs[k];
		}
	}


	/*for (int i = 0; i < newsize; ++i){
			std::cout << new_list[i] << std::endl;
	}*/


	for (int i = newsize - 1; i >= 0; --i){
		if (new_list[i] == 0){
			--newsize;
		}
		else{
			break;
		}
	}
	if (newsize == p.degree + 1){
		for (int j = 0; j < newsize; ++j){
			p.a_coeffs[j] = new_list[j];
		}
	}
	else{
		delete[] p.a_coeffs;
		p.a_coeffs = new double[newsize];
		for (int j = 0; j < newsize; ++j){
			p.a_coeffs[j] = new_list[j];
		}
		p.degree = newsize - 1;
	}
}

void poly_multiply( poly_t &p, poly_t const &q){
	if (p.a_coeffs == nullptr || q.a_coeffs == nullptr){
		throw 0;
	}
	else if ((p.degree == 0 && p.a_coeffs[0] == 0)||
			(q.degree == 0 && q.a_coeffs[0] == 0)){
		p.degree = 0;
		p.a_coeffs[0] = 0;
	}
	else{
		double *newlist = new double[p.degree + q.degree + 1]();
		for (std::size_t indexP = 0; indexP < p.degree + 1; ++indexP){
			for (std::size_t indexQ = 0; indexQ < q.degree + 1; ++indexQ){
				newlist[indexP + indexQ] += p.a_coeffs[indexP]*q.a_coeffs[indexQ];
			}
		}
		/*for (int k = 0; k < p.degree + q.degree + 1; ++k){
			std::cout << newlist[k] <<std::endl;
		}*/
		delete[] p.a_coeffs;
		p.a_coeffs = newlist;
		for (std::size_t index = 0; index < p.degree + q.degree + 1; ++index){
			p.a_coeffs[index] = newlist[index];
		}
		newlist = nullptr;
		p.degree = p.degree + q.degree;
	}
}
double poly_divide( poly_t &p, double r){
	if (p.a_coeffs == nullptr){
		throw 0;

	}
	else if( p.degree == 0){
		double * temp = new double[0];
		temp[0] = 0;
		double result = p.a_coeffs[0];
		delete[] p.a_coeffs;
		p.a_coeffs = temp;
		temp = nullptr;
		return result;
	}
	else {
		double remainder = p.a_coeffs[p.degree - 1];
		double factor = p.a_coeffs[p.degree];
		//std::cout << remainder <<" " << factor << std::endl;
		double *newElem = new double[p.degree];
		newElem[p.degree - 1] = factor;
		for (std::size_t i = 0; i < p.degree - 1; ++i){
			remainder = p.a_coeffs[p.degree - 1 - i] + r*factor;
			factor = remainder;
			if (p.degree != 1){
				newElem[p.degree - 2 - i] = factor;
			}
			//std::cout << remainder <<" " << factor << std::endl;

		}
		remainder = p.a_coeffs[0] + r*factor;
		delete[] p.a_coeffs;
		p.a_coeffs = newElem;
		p.degree = p.degree - 1;
		return remainder;
	}

}
void poly_diff( poly_t &p){
	if (p.a_coeffs == nullptr){
		throw 0;
	}
	else if (p.degree == 0){
		p.a_coeffs[0] = 0;
	}
	else{
		int newsize = p.degree;
		double newlist[newsize];
		for (std::size_t k = 0; k < newsize; ++k){
			newlist[k] = p.a_coeffs[k + 1]*(k + 1);
		}
		delete[] p.a_coeffs;
		p.a_coeffs = new double[newsize];
		for (std::size_t k = 0; k < newsize; ++k){
			p.a_coeffs[k] = newlist[k];
		}
		p.degree = p.degree - 1;
	}
}
double poly_approx_int (poly_t const &p,
		double a, double b, unsigned int n){
	int numberOfX = n + 1;
	double h = (b - a)/n;
	double coord[numberOfX];
	for (std::size_t k = 0; k < numberOfX; ++k){
		coord[k] = a + k*h;
	}
	double result = poly_val(p, coord[0]) + poly_val(p, coord[n]);
	for (int k = 1; k < (numberOfX - 1); ++k){
		result += 2*poly_val(p, coord[k]);
	}
	result = result*h/2;
	return result;
}
#ifndef MARMOSET_TESTING
int main(){
	poly_t poly_a{nullptr, 0};
	poly_t poly_b{nullptr, 0};
	poly_t poly_c{nullptr, 0};
	double elem1[4] = {0.159811, 7.67029, 0.0590364, 152.477};
	double elem2[5] = {-733.262, 1114.25, 16.0888, 0.920128, -50};
	double elem3[3] = {-733.262, 1114.25, 39};
	init_poly(poly_a, elem1, 3);
	init_poly(poly_b, elem2, 4);
	init_poly(poly_c, elem3, 2);
	double remainder = poly_divide(poly_a, 1.67329);
	for ( int x = 0; x <= poly_a.degree ; ++x){
		std::cout << poly_a.a_coeffs[x] << " " <<std::endl;
	}
	std::cout << "remainder is " << remainder;
}
#endif
