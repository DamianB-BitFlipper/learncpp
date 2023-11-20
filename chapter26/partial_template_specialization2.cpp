#include <iostream>
#include <cstdint>
#include <cstring>

template <typename T, int size> // size is the expression parameter
class StaticArray_Base {
public:

  void print() const {
    for (int count{ 0 }; count < size; ++count) {
      std::cout << m_array[count] << ' ';
    }
    std::cout << std::endl;
  }

  T* getArray() { return m_array; }

  T& operator[](int index) {
    return m_array[index];
  }

protected:
  // The expression parameter controls the size of the array
  T m_array[size]{};
};

template <typename T, int size>
class StaticArray : public StaticArray_Base<T, size> {};

template <int size>
class StaticArray<char, size> : public StaticArray_Base<char, size> {
public:
  void print() const {
    for (int count{ 0 }; count < size; ++count) {
      std::cout << this->m_array[count];
    }
    std::cout << std::endl;    
  }

};

int main() {
  // declare an int array
  StaticArray<int, 4> int4{};
  int4[0] = 0;
  int4[1] = 1;
  int4[2] = 2;
  int4[3] = 3;

  // Print the array
  int4.print();

  // declare a char array
  StaticArray<char, 14> char14{};
  std::strcpy(char14.getArray(), "Hello, world!");

  // Print the array
  char14.print();

  return 0;
}
