#include <iostream>
#include <cstdint>
#include <vector>

template <typename T>
std::vector<T> generate(const T& val) {
  constexpr std::size_t N_VALS = 5;
  std::vector<T> retVec(N_VALS);

  for (std::size_t i = 0; i < 5; i++) {
    retVec[i] = val;
  }

  return retVec;
}

template <typename T>
void printZeroIndex(std::vector<T>& vec) {
  std::cout << "Zero index: " << vec.at(0) << std::endl;
}

template <typename T>
class Foo {
public:

  Foo(T val) : m_val{ val } {}

  template <typename _T>
  friend std::ostream& operator<<(std::ostream& out, const Foo<_T>& foo);

private:
  const T m_val{};
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Foo<T>& foo) {
  return out << "Foo val: " << foo.m_val;
}

int32_t main() {
  std::vector vector{ generate(10) };

  printZeroIndex(vector);

  return 0;
}
