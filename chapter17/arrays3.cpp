#include <iostream>
#include <cstdint>
#include <array>

namespace Color {
  
  enum Type {
    black,
    red,
    blue,
    max_colors,
  };

  using namespace std::literals;
  constexpr std::array colorNames{ 
    "Black"sv,
    "Red"sv,
    "Blue"sv,
  };

  constexpr std::string_view toStr(Type colorType) {
    return colorNames[colorType];
  }

  static_assert(
    std::size(colorNames) == max_colors && 
    "Color types and string names size mismatch"
    );

};

std::ostream& operator<<(std::ostream& out, Color::Type colorType) {
  return out << Color::toStr(colorType);
}

int32_t main() {
  Color::Type color{ Color::blue };

  std::cout << color << std::endl;

  return 0;
}
