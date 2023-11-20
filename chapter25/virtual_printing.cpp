#include <iostream>
#include <cstdint>
#include <string_view>

class Base {
public:
  virtual ~Base() = default;

  virtual std::string_view identify() const { return "Base"; }

  virtual std::ostream& print(std::ostream& out) const { 
    return out << identify();
  }

  friend std::ostream& operator<<(std::ostream& out, const Base& b) {
    return b.print(out);
  }
};

class Derived : public Base {
public:
  std::string_view identify() const override { return "Derived"; }

  friend std::ostream& operator<<(std::ostream& out, const Derived& d) {
    return d.print(out);
  }
};

int main() {
  Base b{};
  std::cout << b << std::endl;

  Derived d{};
  std::cout << d << std::endl;

  Base& bref{ d };
  std::cout << bref << std::endl;

  return 0;
}
