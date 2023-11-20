#include "cents.h"

#include <cstdint>

Cents operator+(const Cents& a, const Cents& b) {
  return Cents{ a.m_cents + b.m_cents };
}

Cents operator+(const Cents& a, int32_t b) {
  return a + Cents{ b };
}

Cents operator-(const Cents& a, const Cents& b) {
  return Cents{ a.getCents() - b.getCents() };
}

Cents operator-(const Cents& a, int32_t b) {
  return a - Cents{ b };
}

Cents operator-(int32_t a, const Cents& b) {
  return Cents{ a } - b;
}

Cents Cents::operator-() const {
  return Cents{ -1 * getCents() };
}

Cents Cents::operator!() const {
  return Cents{ -1 * getCents() };
}

void Cents::operator()() const {
  this->print();
}

Cents::operator int() const { return m_cents; }
