#include <iostream>
#include <cstdint>

struct Fraction {
  
  int32_t numerator{};
  int32_t denominator{};
  
};

int32_t main() {
  Fraction frac{ 3, 4 };

  std::cout << "Numerator: " << frac.numerator << " Denominator: " << frac.denominator << std::endl;
  
  return 0;
}
