#include <iostream>
#include <cstdint>
#include <cstring>

template <typename T, int size> // size is the expression parameter
class StaticArray {
private:
  // The expression parameter controls the size of the array
  T m_array[size]{};

public:
  T* getArray() { return m_array; }

  T& operator[](int index) {
    return m_array[index];
  }
};

template <typename T, int size>
void print(StaticArray<T, size>& array) {
  for (int count{ 0 }; count < size; ++count) {
    std::cout << array[count] << ' ';
  }
  std::cout << std::endl;
}

template <int size>
void print(StaticArray<char, size>& array) {
  for (int count{ 0 }; count < size; ++count) {
    std::cout << array[count];
  }
  std::cout << std::endl;
}

int main() {
  // declare an int array
  StaticArray<int, 4> int4{};
  int4[0] = 0;
  int4[1] = 1;
  int4[2] = 2;
  int4[3] = 3;

  // Print the array
  print(int4);

  // declare a char array
  StaticArray<char, 14> char14{};
  std::strcpy(char14.getArray(), "Hello, world!");

  // Print the array
  print(char14);

  return 0;
}
