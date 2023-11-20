#include <iostream>
#include <cstdint>

int32_t main() {
  constexpr int32_t array[3][5] = {
    { 1, 2, 3, 4, 5 },
    { 2, 3, 4, 5, 6 },
    { 3, 4, 5, 6, 7 },
  };

  for (const auto& row : array) {
    for (const auto& col : row) {
      std::cout << col << ' ';
    }
    std::cout << std::endl;
  }

  return 0;
}
