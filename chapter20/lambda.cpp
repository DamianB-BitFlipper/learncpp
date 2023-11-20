#include <iostream>
#include <cstdint>
#include <functional>

template <typename T>
constexpr auto addOne(T x) -> T {
  return x + 1;
}

template <typename T>
constexpr T applyFn(T x, T fn(T)) {
  return fn(x);
}

template <typename T>
constexpr T applyLambdaFn(T x, const std::function<T(T)>& fn) {
  return fn(x);
}

void repeat1(const int repetitions, const std::function<void(int)>& fn)
{
  for (int i{ 0 }; i < repetitions; ++i) {
    fn(i);
  }
}

int32_t main() {
  constexpr int32_t result{ applyFn(4, addOne) };
  static_assert(result == 5);

  std::cout << result << std::endl;

  /*
  constexpr int32_t result2{ 
    applyLambdaFn(
      4, 
      [](int32_t x) { return x + 1; }
      )
  };
  //static_assert(result2 == 5);

  std::cout << result2 << std::endl;
  */

  repeat1(
    3,
    [](int i) { std::cout << i << std::endl; }
    );

  return 0;
}
