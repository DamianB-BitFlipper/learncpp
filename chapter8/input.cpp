#include <iostream>
#include <cstdint>
#include <cassert>
#include <random>

void ignoreLine() {
  if (!std::cin) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
}

double getDouble() {
  double v{};
  std::cout << "Enter a decimal: ";
  std::cin >> v;
  ignoreLine();

  return v;
}

char getOperator() {
  char c{};
  std::cout << "Enter an operator: ";
  std::cin >> c;
  ignoreLine();

  return c;
}

int32_t main() {
  const double v1{ getDouble() };
  const char op{ getOperator() };
  const double v2{ getDouble() };

  assert(v1 >= 0.0 && "V1 must be positive!");
  assert(v2 >= 0.0 && "V2 must be positive!");
  static_assert(sizeof(int) == 4, "ints must be 4 bytes!");
  
  switch (op) {
  case '+':
    std::cout << "Result: " << v1 + v2 << std::endl;
    break;    
  case '-':
    std::cout << "Result: " << v1 - v2 << std::endl;
    break;    
  case '*':
    std::cout << "Result: " << v1 * v2 << std::endl;
    break;    
  case '/':
    std::cout << "Result: " << v1 / v2 << std::endl;
    break;
  default:
    std::cerr << "Invalid operator: " << op << std::endl;
    break;
  }
  
  return 0;
}
