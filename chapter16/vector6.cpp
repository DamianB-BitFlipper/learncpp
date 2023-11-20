#include <iostream>
#include <cstdint>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vector) {
  for (const T& v : vector) {
    out << v << std::endl;
  }
  return out;
}

class Foo {
public:

  explicit Foo(int32_t val) : m_val{ val } {}

private:
  const int32_t m_val{};
};

int32_t main() {
  std::vector<int32_t> vector(100);

  for (int32_t i{ 0 }; i < 20; i++) {
    vector.push_back(i);
  }

  vector.resize(3);
  vector.resize(15);
  vector.reserve(50);

  std::cout << vector << std::endl;
  std::cout << vector.size() << std::endl;
  std::cout << vector.capacity() << std::endl;
  std::cout << vector.back() << std::endl;

  std::vector<Foo> fooVector{};
  fooVector.push_back(Foo{ 6 });
  fooVector.emplace_back(9);

  std::cout << fooVector.size() << std::endl;

  return 0;
}
