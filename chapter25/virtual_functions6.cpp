#include <iostream>
#include <cstdint>
#include <string_view>

class A {
public:
  virtual std::string_view getName() { return "A"; }
};

class B final : public A {
public:
  // note use of final specifier on following line -- that makes this function no longer overridable
  std::string_view getName() override { return "B"; } // okay, overrides A::getName()
};

class C : public B {
public:
  std::string_view getName() override { return "C"; } // compile error: overrides B::getName(), which is final
};

int32_t main() {
  return 0;
}
