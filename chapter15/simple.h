#pragma once

#include <iostream>
#include <cstdint>

class Simple {
public:
  explicit Simple(int32_t x);

  template <int N>
  void print();

  Simple& incr(int32_t n=1);
  Simple& reset();

  int32_t getX() const { return m_x; }

private:
  int32_t m_x{};

  int32_t oneOnTop() const;
};

template <int N>
inline void Simple::print() { 
  std::cout << "N is: " << N << " " << this->oneOnTop() << std::endl; 
}
