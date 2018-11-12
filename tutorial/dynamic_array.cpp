#include <iostream>
#include <cstring>

struct flex_array_t
{
    double * a_values;
    std::size_t capacity;
    int quantity;
};

int main();
flex_array_t init_flex();
void print_flex( flex_array_t to_print);
void dealloc_flex(flex_array_t &to_dealloc);
void append_elements(flex_array_t &to_append, double element[], unsigned int size);

int main(){
  flex_array_t speeds = init_flex();

  print_flex(speeds);

  const int new_quantity_1{2};
  double add_elements_1[new_quantity_1]{62.3, 63.0};
  append_elements(speeds, add_elements_1, new_quantity_1);

  print_flex(speeds);

  const int new_quantity_2{5};
  double add_elements_2[new_quantity_2]{64.9, 64.5, 64.1, 63.8, 63.0};
  append_elements(speeds, add_elements_2, new_quantity_2);

  print_flex(speeds);

  dealloc_flex(speeds);
  return 0;
}

void print_flex( flex_array_t to_print) {
  for (int value_index = 0; value_index < to_print.quantity; ++value_index){
    std::cout << to_print.a_values[value_index] << " ";
  }
  std::cout << std::endl;
  std::cout << "current capacity: " << to_print.capacity << std::endl;
}

flex_array_t init_flex() {
  flex_array_t new_array;
  new_array.capacity = 3;
  new_array.a_values = new double[3];
  new_array.quantity = 0;
  return new_array;
}
void dealloc_flex(flex_array_t &to_dealloc){
  delete[] to_dealloc.a_values;
  to_dealloc.a_values = nullptr;
  to_dealloc.capacity = 0;
  to_dealloc.quantity = 0;
}
void append_elements(flex_array_t &to_append, double element[], unsigned int size){
  if ((size + to_append.quantity) > to_append.capacity){
    int new_capacity = to_append.quantity + size;
    double *temp_p = new double [new_capacity];
    for (std::size_t k = 0; k < to_append.quantity; ++k){
      temp_p[k] = to_append.a_values[k];
    }
    for (std::size_t k = to_append.quantity; k < new_capacity; ++k){
      temp_p[k] = element[k - to_append.quantity];
    }
    delete[] to_append.a_values;
    to_append.a_values = temp_p;
    to_append.capacity = new_capacity;
    to_append.quantity = new_capacity;

  }
}
