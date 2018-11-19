// Example program
#include <iostream>
#include <string>

void print(int * p, int * q);
void print(int * p, int * q){
    std::cout<<"The value of p is: "<< *p<<std::endl;
    std::cout<<"The value of q is: "<< *q<<std::endl;
}

int main(){
    int *q_value = new int {19};
    int *p_value = new int {14};
    *p_value = 10;


   print(p_value, q_value);

}

//Example Program
#include <iostream>
int main();
void times_two(int *p);

void times_two(int *p){
    *p=(*p)*2;
}

int main() {
    int *p_value_1{new int{42}};
    delete p_value_1;
    p_value_1 = nullptr;

    int *p_value_2{new int{91}};
    std::cout << "Before: " << *p_value_2  << std::endl;

    times_two(p_value_2);

    *p_value_1 = new int {42};
    std::cout << "After:  " << *p_value_2  << std::endl;
    delete p_value_1;
    delete p_value_2;
    p_value_1 = nullptr;
    p_value_2 = nullptr;

    return 0;
}
