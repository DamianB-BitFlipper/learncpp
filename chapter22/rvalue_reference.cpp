#include <iostream>
#include <cstdint>

void fn1(int& y) {
  std::cout << "lvalue Y: " << y << std::endl;
}

void fn1(int&& y) {
  std::cout << "rvalue Y: " << y << std::endl;
}

int32_t main() {
  int&& x{ 5 };

  fn1(x);
  fn1(10);

  std::cout << x << std::endl;

  return 0;
}
