#include "fixed_array.h"

#include <iostream>
#include <cstdint>

int32_t main() {
  FixedArray<int16_t> farray{ 4, 5, 6, 7 };

  std::cout << "Length: " << farray.getLength() << std::endl;
  std::cout << "Value: " << farray[3] << std::endl;

  return 0;
}
