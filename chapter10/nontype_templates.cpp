#include <iostream>
#include <cstdint>

template <auto N>
void print() {
  std::cout << "N is: " << N << std::endl;
}

template<>
void print<69>() {
  std::cout << "Lucky number!" << std::endl;
}

template <int D>
double getSqrt() {
  static_assert(D >= 0 && "Cannot square root negative numbers!");

  if constexpr (D >= 0) {
    return std::sqrt(D);
  }

  return 0.0;
}

int32_t main() {
  print<5>();
  print<68>();
  print<69>();
  print<'a'>();    

  std::cout << getSqrt<5>() << '\n';
  
  return 0;
}
