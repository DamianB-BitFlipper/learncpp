#include <iostream>
#include <cstdint>

class Base {
public:
  int m_base{};

  Base(int base) : m_base{ base } {}

  Base& operator=(const Base&) = default;
};

class Derived : public Base {
public:
  int m_derived{};

  Derived(int derived) 
    : Base{ derived }
    , m_derived{ derived } 
  {
  }
};

int32_t main() {
  Derived d1{ 34 };
  Derived d2{ 35 };
  Base& b{ d1 };

  b = d2;

  std::cout << d1.m_base << " " << d1.m_derived << std::endl;

  return 0;
}
