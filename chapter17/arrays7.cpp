#include <iostream>
#include <cstdint>
#include <array>

template <typename T, std::size_t NRow, std::size_t NCol>
using Array2D = std::array<std::array<T, NCol>, NRow>;

template <typename T, std::size_t NRow, std::size_t NCol>
constexpr std::size_t nRows(Array2D<T, NRow, NCol>) noexcept {
  return NRow;
}

int32_t main() {
  Array2D<int32_t, 3, 4> array{{
    { 1, 2, 3, 4 },
    { 2, 3, 4, 5 },
    { 3, 4, 5, 6 },
  }};

  for (const auto& row : array) {
    for (const auto& col : row) {
      std::cout << col << ' ';
    }
    std::cout << std::endl;
  }

  std::cout << "NRows: " << nRows(array) << std::endl;

  return 0;
}
