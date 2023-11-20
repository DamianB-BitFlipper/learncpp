#include <iostream>

int sum(int a, int b) {
  return a + b;
}

int main() {
  int a { 6 };
  int b { 9 };
  
  std::cout << sum(a, b) << std::endl;
  return 0;
}
