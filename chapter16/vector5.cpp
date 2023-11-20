#include <iostream>
#include <cstdint>
#include <vector>

namespace NIndex {
  
  enum {
    zero,
    one,
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    max,
  };

}

enum class Index {
  zero,
  one,
  two,
  three,
  four,
  five,
  six,
  seven,
  eight,
  nine,
  ten,
  max,
};

constexpr auto operator+(const Index index) {
  return static_cast<std::underlying_type_t<Index>>(index);
}

int32_t main() {
  using namespace std::literals;
  std::vector fibStrs{ "1"s, "1"s, "2"s, "3"s, "5"s, "7"s, "12"s, "19"s };

  for (const auto& v : fibStrs) {
    std::cout << v << std::endl;
  }

  std::cout << fibStrs[NIndex::four] << std::endl;
  std::cout << fibStrs[+Index::four] << std::endl;

  return 0;
}
