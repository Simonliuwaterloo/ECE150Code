#include <iostream>
struct human_t {
  int age = 0;
  std::string name;
};

int main();
template <typename T>
T add (T a, T b = 0);
template <typename T>
T add (T a, T b){
  T c = 2;
  return a + b + c;
}

template <typename T>
std::size_t linear_search(T const array[], std::size_t const begin, std::size_t const end, T const &value );
template <typename T>
std::size_t linear_search(T const array[], std::size_t const begin, std::size_t const end, T const &value ) {
  for (std::size_t index = begin; index < end; ++index) {
    if (array[index] == value) {
      return index;
    }
  }
  return end;
}
template <typename T>
std::size_t linear_search(T const array[], std::size_t const capacity, T const &value ) {
  return linear_search(array, 0, capacity, value);
}

template <typename T>
bool is_sorted(T const array[], std::size_t const begin, std::size_t const end) {
  for (std::size_t index = begin + 1; index < end; ++index) {
    if (array[index - 1] > array[index]) {
      return false;
    }
  }
  return true;
}
template<typename t> //t also works
bool is_sorted(t const array[], std::size_t const capacity) {
  return is_sorted(array, 0, capacity);
}

template<typename T>
std::size_t binary_search(T const array[], std::size_t const capacity, T const value) { //return value is std::size_t
  if (value < array[0]) {
    return capacity;
  }
  std::size_t left = 0;
  std::size_t right = capacity - 1;
  while(left <= right) {
    std::size_t midpoint = (left + right)/2;
    if (array[midpoint] == value) {
      return midpoint;
    }
    else if (midpoint > value) {
      right = midpoint - 1;
    }
    else{
      left = midpoint + 1;
    }
  }
  return capacity;
}
template <typename T>
std::size_t find_max(T const array[], std::size_t begin, std::size_t end ) {
  std::size_t max = begin;
  for (std::size_t index = begin + 1; index < end; ++index) {
    if (array[index] > array[max]) {
      max = index;
    }
  }
  return max;
}
template <typename T>
std::size_t find_max(T const array[], std::size_t capacity) {
  return find_max(array, 0, capacity );
}
template <typename T>
std::size_t selection_sort(T const array[])
int main(){
  int list[246];
  int sort[247];
  int sorted[7] = {1, 6, 9, 10, 13, 17, 21};
  sort[246] = -1;
  std::size_t count = 0;
  for (std::size_t index = 0; index < 245; ++index) {
    list[count] = index;
    sort[count] = index;
    ++count;
  }
  std::cout << find_max(sorted, 7) << std::endl;
  return 0;
}
