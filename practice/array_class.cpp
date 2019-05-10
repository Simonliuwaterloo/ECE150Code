template<typename T>
class Array;
template<typename T>
class Array {
public:
  Array(int cap = 16);
  Array(int capacity, T value);
  ~Array();
private:
  int array_capacity;
  T* array;
};

template<typename T>
Array<T>::Array(int cap) {
  array_capacity = cap;
  array = new T[array_capacity];
}
template<typename T>
Array<T>::Array(int capacity, T value) {
  array_capacity = capacity;
  array = new T[capacity];
  for (int k = 0; k < capacity; ++k) {
    array[k] = value;
  }
}
template<typename T>
Array<T>::~Array() {
  delete[] array;
  array = nullptr;
}
int main() {
  return 0;
}
