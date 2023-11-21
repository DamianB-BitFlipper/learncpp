#include <iostream>
#include <cstdint>
#include <string_view>

class Base {
public:
  Base() {}
  virtual ~Base() = default;

  virtual std::string_view identify() const { return "Base"; }
};

class Derived : public Base {
public:
  Derived() {}

  std::string_view identify() const override { return "Derived"; }
};

void throwDerived() {
  Derived d{};
  Derived& ref{ d };
  std::cout << "Addr of ref: " << &ref << std::endl;
  throw ref;
}

void catchDerivedAsBaseRethrow() {
  try {
    throwDerived();
  } catch (const Base& base) {
    std::cout << "Caught a base which is really: " << base.identify() << " addr " << &base << std::endl;
    throw;
  }
}

int32_t main() {

  try {
    catchDerivedAsBaseRethrow();
  } /*catch (const Derived& derived) {
    std::cout << "Outer most caught Derived. Self identify: " << derived.identify() << std::endl;
  } */ catch (const Base& base) {
    std::cout << "Outer most caught Base. Self identify: " << base.identify() << " addr " << &base << std::endl;
  }

  return 0;
}
