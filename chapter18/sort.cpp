#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>

template <typename T>
constexpr bool isOdd(T v) {
  return v % 2 == 1;
}

template <typename T>
constexpr bool subOne(T v) {
  return v - 1;
}

int32_t main() {
  std::vector vector{ 1, 2, 3, 4, 5, 6 };
  
  std::sort(std::begin(vector), std::end(vector), std::greater{});

  for (auto val : vector) {
    std::cout << val << std::endl;
  }

  for (auto it{ std::begin(vector) }; it != std::end(vector); ++it) {
    std::cout << *it << std::endl;    
  }

  //auto foundIt{ std::find(vector.begin(), vector.end(), 3) };
  std::for_each(vector.begin(), vector.end(), subOne<int>);

  auto foundIt2{ std::find_if(vector.begin(), vector.end(), isOdd<int>) };

  if (foundIt2 == vector.end()) {
    std::cout << "Didn't find anything" << std::endl;
  } else {
    *foundIt2 = 69;
  }

  for (auto it{ std::begin(vector) }; it != std::end(vector); ++it) {
    std::cout << *it << std::endl;    
  }

  return 0;
}
