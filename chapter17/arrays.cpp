#include <iostream>
#include <cstdint>
#include <array>

template <typename T, std::size_t N>
std::array<T, N> addOneForAll(std::array<T, N>& array) {
  static_assert(N > 0 && "The array must be non-empty, for fun!");

  for (auto& val : array) {
    val++;
  }

  return array;
}

int32_t main() {
  constexpr int32_t length{ 5 };
  constexpr std::array<int32_t, length> array{ 1, 2, 3, 4, 5 };

  for (auto val : array) {
    std::cout << val << std::endl;
  }

  static_assert(array.size() == length && "Something is wrong with the length!");

  std::array array2{ 3, 2, 1 };

  for (auto val : array2) {
    std::cout << val << std::endl;
  }

  decltype(array2)::size_type index{ 0 };
  for (; index < array2.size(); index++) {
    std::cout << array2[index] << std::endl;    
  }

  constexpr auto array2Length { std::size(array2) };

  std::array newArray = addOneForAll(array2);

  std::cout << "Array2 len " << array2Length << std::endl;
  std::cout << "Get: " << std::get<2>(newArray) << std::endl;

  return 0;
}
