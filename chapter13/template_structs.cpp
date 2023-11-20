#include <iostream>
#include <cstdint>

template <typename T=int64_t, typename U=int64_t>
struct Pair {
  T a{};
  U b{};
};

template <typename T, typename U>
Pair(T, U) -> Pair<T, U>;

template <>
struct Pair<double, double> {
  double a_d{};
  double b_d{};
};

template <typename T>
using UniTypePair = Pair<T, T>;

template <typename T, typename U>
std::ostream& operator<<(std::ostream& out, Pair<T, U>& pair) {
  return out << "(" << pair.a << ", " << pair.b << ")";
}

int32_t main() {
  Pair<int32_t, double> p{ 6, 9.0 };
  std::cout << p << std::endl;

  Pair<double, double> p_d{ 61.2, 91.3 };
  std::cout << p_d.a_d << " " << p_d.b_d << std::endl;

  Pair p_deduce{ 69, 'a' };
  std::cout << p_deduce << std::endl;

  Pair no_init;
  std::cout << sizeof(no_init.a) << std::endl;

  using TwoInts = Pair<int, int>;
  TwoInts twis{ 4, 5 };
  std::cout << twis << std::endl;

  UniTypePair<int32_t> utp{ 6, 9 };
  std::cout << utp << std::endl;

  return 0;
}
