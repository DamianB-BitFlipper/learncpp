#include <iostream>
#include <cstdint>
#include <string_view>

class A {
public:
  virtual std::string_view getName() const { return "A"; }
};

class B: public A {
public:
  virtual std::string_view getName() const override { return "B"; }
};

class C: public B {
public:
  virtual std::string_view getName() const { return "C"; }
};

class D: public C {
public:
  virtual std::string_view getName() const { return "D"; }
};

int32_t main() {
  D d{};
  B& rBase{ d };
  A a{ d };
  std::cout << "rBase is a " << rBase.getName() << std::endl;
  std::cout << "A is a " << a.getName() << std::endl;

  return 0;
}
