#include <iostream>
#include <cstdint>

class Printer {
public:
  virtual ~Printer() = default;

  virtual void print() const = 0;
};

void Printer::print() const {
  std::cout << "Default" << std::endl;
}

class Number : public Printer {
public:
  void print() const override {
    std::cout << "Number" << std::endl;
  }
};

class Frog : public Printer {
public:
  void print() const override {
    Printer::print();
  }
};

int32_t main() {
  Number n{};
  n.print();

  Frog f{};
  f.print();

  return 0;
}
