#include <iostream>
#include <cstdint>
#include <string>
#include <string_view>

class Base {
protected:
  int m_value{};

public:
  Base(int value) : m_value{value} {}

  virtual ~Base() = default;
};

class Derived : public Base {
protected:
  std::string m_name{};

public:
  Derived(int value, std::string_view name) : Base{value}, m_name{name} {}

  const std::string& getName() const { return m_name; }
};

Base* getObject(bool returnDerived) {
  if (returnDerived) {
    return new Derived{ 1, "Apple" };
  } else {
    return new Base{ 2 };
  }
}

int32_t main() {
  Derived apple{ 1, "Apple" };
  Base base{ 2 };

  Base* bPtr{ getObject(true) };

  Derived* dPtr{ dynamic_cast<Derived*>(bPtr) };
  //Derived* dPtr { static_cast<Derived*>(bPtr) };

  Base& bRef{ apple };
  Derived& dRef{ dynamic_cast<Derived&>(bRef) };

  if (dPtr) {
    std::cout << "Printing" << std::endl;
    std::cout << dPtr->getName() << std::endl;
  }

  std::cout << "Ref: " << dRef.getName() << std::endl;

  return 0;
}
