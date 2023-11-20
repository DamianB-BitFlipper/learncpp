#include <iostream>
#include <cstdint>
#include <iterator>

template <typename T, std::size_t N>
constexpr std::size_t length(const T(&)[N]) noexcept {
  return N;
}

template <typename T>
void addOneForAll(T (&array)[5]) {
  for (T& value : array) {
    value++;
  }
}

int32_t main() {
  constexpr int32_t array[4]{};

  static_assert(std::size(array) == 4);
  static_assert(length(array) == 4);

  int32_t array2[5]{};

  addOneForAll(array2);

  for (auto val : array2) {
    std::cout << val << std::endl;
  }

  return 0;
}
