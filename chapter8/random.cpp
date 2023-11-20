#include "numbers.h"

#include <iostream>
#include <cstdint>
#include <random>

namespace N = Numbers;

int32_t main() {
  std::mt19937 mt{std::random_device{}()};
  std::uniform_int_distribution die6{1, N::getX()};

  std::cout << "Die roll: " << die6(mt) << std::endl;

  std::cout << "X is: " << N::getX() << std::endl;
  
  return 0;
}
