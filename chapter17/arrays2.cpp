#include <iostream>
#include <cstdint>
#include <functional>
#include <array>

struct House {
  int32_t number{};
  int32_t stories{};
  int32_t roomsPerStory{};
};

int32_t main() {
  std::array<House, 3> array{
    {
      { 13, 1, 7 },
      { 14, 2, 5 },
      { 15, 2, 4 },
    }
  };

  for (const auto& house : array) {
    std::cout << "Number: " << house.number << std::endl;
  }

  int32_t x{ 1 };
  int32_t y{ 2 };
  int32_t z{ 3 };

  std::array<std::reference_wrapper<int32_t>, 3> array2{ x, y, z };

  array2[0].get() = 69;

  for (auto i : array2) {
    std::cout << "I: " << i << std::endl;
  }

  std::array<decltype(std::cref(x)), 3> array3{ x, y, z };

  for (auto i : array3) {
    std::cout << "I: " << i << std::endl;
  }

  return 0;
}
