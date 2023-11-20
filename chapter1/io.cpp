#include <cstdint>
#include <iostream>

#include "add.h"

bool compare(int32_t a) {
  if (a == 3) {
    return true;
  } else {
    return false;
  }
}

int32_t main() {

  std::cout << "Enter your number: ";
  int32_t a{}, b{};
  std::cin >> a >> b;

  std::cout << "The sum is: " << add(a, b) << std::endl;

  std::cout << "Cast Double: " << static_cast<int32_t>(-5.5) << std::endl;
  
  std::cout << std::boolalpha;
  std::cout << "Compare: " << compare(a) << std::endl;

  char ch { 'a' };
  std::cout << "Char: " << ch << " has int value " << static_cast<int>(ch) << std::endl;
  
  return 0;
}
