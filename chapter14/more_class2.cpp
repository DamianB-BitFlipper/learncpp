#include <iostream>
#include <cstdint>

class Foo {
public:
  
  Foo(int32_t x) : m_x { x } {}

  explicit Foo(std::string_view) : m_x { 420 } {}

  int32_t getX() const { return m_x; }

  friend std::ostream& operator<<(std::ostream& out, const Foo& foo) {
    return out << "Foo(x=" << foo.getX() << ")";
  }

private:
  const int32_t m_x{};
};

void print(const Foo& foo) {
  std::cout << foo << std::endl;
}

int32_t main() {
  using namespace std::literals;

  Foo f = 69;
  print(f);
  print(70);

  //print("Hello"sv);
  //Foo g = "World"sv;
  //print(g);
  print(Foo{"Hello"});

  return 0;
}
