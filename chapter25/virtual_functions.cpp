#include <iostream>
#include <cstdint>
#include <string_view>

class Base
{
public:
  Base(int value) : m_value{ value } {}

  std::string_view getName() const { return "Base"; }
  int getValue() const { return m_value; }

protected:
  int m_value{};
};

class Derived: public Base
{
public:
  Derived(int value) : Base{ value } {}

  std::string_view getName() const { return "Derived"; }
  int getValueDoubled() const { return m_value * 2; }
};

int32_t main() {
  Derived derived{ 69 };

  Base& refBase{ derived };
  Base* ptrBase{ &derived };

  std::cout << "derived is a " << derived.getName() << " and has value " << derived.getValue() << std::endl;
  std::cout << "rBase is a " << refBase.getName() << " and has value " << refBase.getValue() << std::endl;
  std::cout << "pBase is a " << ptrBase->getName() << " and has value " << ptrBase->getValue() << std::endl;

  return 0;
}
