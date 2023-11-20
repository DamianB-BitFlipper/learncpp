#include <iostream>
#include <cstdint>

template <int* X>
consteval void printP() {
  static_assert(X == nullptr && "Only call with nullptr");

  if constexpr (X != nullptr) {
    std::cout << "PrintP X: " << *X << std::endl;
  }

  return;
}

int32_t main() {
  using std::cout;
  using std::endl;

  int x { 69 };
  int y { 96 };  
  int* const ptr{ &x };

  (*ptr)++;
  printP<nullptr>();
  
  cout << "X is: " << x << " Y is: " << y << endl;
  cout << "Ptr is: " << ptr << " value " << *ptr << endl;
  
  return 0;
}
