#include <iostream>
#include <cstdint>

class Base {
public:
  virtual ~Base() = default;

  virtual Base* getThis() { 
    std::cout << "Base::getThis" << std::endl;
    return this; 
  }

  virtual void printType() const { std::cout << "Base" << std::endl; }
};

class Derived : public Base {
public:
  virtual ~Derived() = default;

  virtual Derived* getThis() override final {
    std::cout << "Derived::getThis" << std::endl;
    return this;
  }

  virtual void printType() const override { std::cout << "Derived" << std::endl; }
};

int32_t main() {
  Derived d{};
  Base& b{ d };
  
  d.printType();
  b.printType();
  b.Base::printType();

  return 0;
}
