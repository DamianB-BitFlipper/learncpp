#include <iostream>
#include <cstdint>

int32_t noexcepter(int32_t x) noexcept(true) {
  if (x <= 0) {
    throw x - 1;
  }

  return x;
}

void neverThrower() noexcept {
  //throw 0;
  std::cout << "HI" << std::endl;
}

int32_t main() {
  bool b1{ noexcept(neverThrower()) };

  std::cout << std::boolalpha << b1 << std::endl;

  try {
    [[maybe_unused]] int32_t x{ noexcepter(-69) };
  } catch (int32_t ex) {
    std::cerr << "Caught: " << ex << std::endl;
  }

  return 0;
}
