#pragma once

#include <iostream>
#include <cstdint>

class Cents{
public:
  
  explicit Cents(int32_t cents) : m_cents{ cents } {}

  void print() const {
    std::cout << m_cents << std::endl;
  }

  int32_t getCents() const { return m_cents; }

  friend Cents operator+(const Cents& a, const Cents& b);

  friend Cents operator+(const Cents& a, int32_t b);

  friend Cents operator+(int32_t a, const Cents& b) {
    return b + a;
  }

  friend bool operator==(const Cents& a, const Cents& b) {
    return a.m_cents == b.m_cents;
  }

  Cents operator*(const Cents& b) const {
    return Cents{ m_cents * b.m_cents};
  }

  Cents operator*(int32_t b) const {
    return *this * Cents{ b };
  }

  Cents operator-() const;

  Cents operator!() const;

  // Prefix
  Cents& operator++() {
    m_cents++;
    return *this;
  }

  // Post fix
  Cents operator++(int) {
    Cents ret{ *this };
    m_cents++;
    return ret;
  }

  int32_t& operator[](int32_t) {
    return m_cents;
  }

  int32_t operator[](int32_t) const {
    return m_cents;
  }

  void operator[](std::string_view sv) const {
    this->print();
    std::cout << sv << std::endl;
  }

  Cents operator()(int32_t i, int32_t j) const {
    return (*this) + i + j;
  }

  void operator()() const;

  explicit operator int() const;

  Cents& operator=(const Cents& a) {
    std::cout << "Overload" << std::endl;
    m_cents = a.m_cents;
    return *this;
  }

  const Cents& operator=(const Cents&) const = delete;

  Cents* operator->() {
    m_cents++;
    return this;
  }

  int32_t m_public{ 69 };

private:
  int32_t m_cents{};
};

Cents operator-(const Cents& a, const Cents& b);

Cents operator-(const Cents& a, int32_t b);

Cents operator-(int32_t a, const Cents& b);
