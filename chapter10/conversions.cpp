#include "subtract.h"

#include <iostream>
#include <cstdint>

int add(int a=6, int b=9);

int add(int a, int b) {
  std::cout << "Adding ints" << std::endl;
  return a + b;
}

template <typename T>
T add(T a, T b) = delete;

double add(double a, double b) {
  std::cout << "Adding doubles" << std::endl;
  return a + b;
}

template <typename T, typename U>
auto max(T a, U b) {
  return (a > b) ? a : b;
}

template<>
auto max(double a, double b) {
  std::cout << "Template Double max" << std::endl;
  return (a > b) ? a : b;
}

double max(double a, double b) {
  std::cout << "No template Double max" << std::endl;
  return (a > b) ? a : b;
}

template <typename T>
T addOne(T a, int) {
  std::cout << "int called" << std::endl;
  return a + 1;
}

template <typename T>
T addOne(T a, uint32_t) {
  std::cout << "unsigned int called" << std::endl;
  return a + 1;
}

template<>
double addOne(double a, uint32_t) = delete;

int32_t main() {
  using poop = int32_t;
  
  constexpr poop u1{ 10 };
  uint32_t u2{ u1 };

  if (u1 <= 20.0) {
    std::cout << u1 << " " << u2 << '\n';
  }

  std::cout << "The type is: " << typeid(u1 <= 20.0).name() << std::endl;

  std::cout << "Addition: " << add(3, 1) << std::endl;
  std::cout << "Max: " << max(3, 1) << std::endl;
  std::cout << "Max Doubles: " << max<>(3.0, 1.0) << std::endl;

  addOne(1.0f, static_cast<uint32_t>('a'));

  std::cout << "Subtraction: " << sub<double>(10.4, 1) << std::endl;
  std::cout << "Max mix: " << max(10.4, 1) << std::endl;  
  
  return 0;
}
