#include "simple.h"

#include <iostream>
#include <cstdint>

Simple::Simple(int32_t x) : m_x { x } {}

Simple& Simple::incr(int32_t n) {
  m_x += n;
  return *this;
}

Simple& Simple::reset() {
  *this = Simple{ 100 };
  return *this;
}

int32_t Simple::oneOnTop() const {
  return m_x + 1;
}

int32_t main() {
  Simple s{ 10 };
  s.incr().incr().incr();
  s.print<6>();

  s.reset().incr();
  s.print<9>();

  return 0;
}
