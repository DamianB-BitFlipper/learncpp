#include <iostream>
#include <cstdint>

int32_t main() {
  std::cout << "You have 12 apples. Enter how many servings of apples you want: ";
  double d{};
  std::cin >> d;

  if (d > 0 and d != 3) {
    std::cout << "Each serving is " << (d++, 12 / d) << " apples.\n";
  }

  std::bitset<8> bits {0b0001'0101};
  std::cout << "Number of bits is: " << sizeof(bits) << std::endl;
  
  return 0;
}
