#include <iostream>
#include <cstdint>
  
enum class Color {
  red,
  green,
  blue,
};

std::ostream& operator<<(std::ostream& out, Color color) {
  switch (color) {
  case Color::red:
    return out << "Red" << std::endl;
  case Color::green:
    return out << "Green" << std::endl;
  case Color::blue:
    return out << "Blue" << std::endl;
  default:
    return out << "????" << std::endl;
  } 
};

std::istream& operator>>(std::istream& in, Color& color) {
  int8_t v{};
  in >> v;

  color = static_cast<Color>(v);
  return in;
}

constexpr auto operator+(Color color) {
  return static_cast<int32_t>(color);
}

inline namespace Feeling {

  enum Feeling {
    happy = 67,
    neutral,
    blue,
  };

}

int32_t main() {

  Color eyes{ 1 };

  std::cout << "Eye color is: " << +eyes << std::endl;
  std::cout << "Size of Color: " << sizeof(Color) << std::endl;
  
  switch (eyes) {
  case Color::red:
    std::cout << "Red Eyes" << std::endl;
    break;
  case Color::green:
    std::cout << "Green Eyes" << std::endl;
    break;
  case Color::blue:
    std::cout << "Blue Eyes" << std::endl;
    break;
  }

  Feeling::Feeling feeling { blue };

  std::cout << "I am not feeling: " << feeling << std::endl;

  return 0;
}
