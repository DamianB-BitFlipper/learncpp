#include <iostream>
#include <cstdint>

class Base
{
public:
  virtual ~Base() = default;

  virtual std::string_view getName() const { return "Base"; }
};

class Derived: public Base
{
public:
  virtual std::string_view getName() const { return "Derived"; }
};

int32_t main() {
  Derived derived{};
  Base& rBase{ derived };
  std::cout << "rBase is a " << rBase.getName() << '\n';

  return 0;
}
