#include <iostream>
#include <cstdint>

#include <iostream>

class Base {
public:
  Base() {}
};

class Derived : public Base {
public:
  Derived() {}

  Derived(const Derived&) = delete; // not copyable
};

int main() {
  Base b{};
  Derived d{};

  try {
    throw b;
    //throw d; // compile error: Derived copy constructor was deleted
  } catch (const Derived& derived) {
    std::cerr << "Caught Derived" << std::endl;
  } catch (const Base& base) {
    std::cerr << "Caught Base" << std::endl;
  }

  return 0;
}
