#include <iostream>
#include <cstdint>
#include <functional>

constexpr int foo(int x) {
  return x;
}

void printFn(int (*const& fn)(int), int x) {
  std::cout << "Printing " << fn(x) << std::endl;
}

void printFn2(int fn(int), int x) {
  std::cout << "Printing " << fn(x) << std::endl;
}

using Intable = int(*)(int);

void printFn3(Intable fn, int x) {
  std::cout << "Printing " << fn(x) << std::endl;
}

void printFn4(std::function<int(int)> fn, int x) {
  std::cout << "Printing " << fn(x) << std::endl;
}

void arrayRef(const int (&array)[]) {
  std::cout << "Address: " << array << std::endl;
}

int32_t main() {
  int (*const fnPtr)(int){ &foo };
  void* fnPtr2{ reinterpret_cast<void*>(foo) };

  printFn(fnPtr, 69);
  printFn2(fnPtr, 69);
  printFn3(fnPtr, 69);
  printFn4(fnPtr, 69);

  std::cout << reinterpret_cast<void*>(fnPtr) << std::endl;
  std::cout << fnPtr2 << std::endl;

  return 0;
}
