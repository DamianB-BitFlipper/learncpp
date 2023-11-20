#include <iostream>
#include <cstdint>

class Cents{
public:
  
  explicit Cents(int32_t cents) : m_cents{ cents } {}

  void print() const {
    std::cout << m_cents << std::endl;
  }

  friend Cents operator+(const Cents& a, const Cents& b);

  friend Cents operator+(const Cents& a, int32_t b);

  friend Cents operator+(int32_t a, const Cents& b) {
    return b + a;
  }

private:
  const int32_t m_cents{};
};

Cents operator+(const Cents& a, const Cents& b) {
  return Cents{ a.m_cents + b.m_cents };
}

Cents operator+(const Cents& a, int32_t b) {
  return a + Cents{ b };
}

int32_t main() {
  Cents c1{ 34 }, c2{ 35 };

  Cents c3{ 2 + c1 + c2 + 1 };

  c3.print();
  
  return 0;
}
