#include <iostream>
#include <cstdint>
#include <vector>

class Foo {
public:
  Foo() = default;

  friend void printFooBody(const Foo& foo);

private:
  const std::vector<int> body{ std::vector<int>(5) };
};

void printFooBody(const Foo& foo) {
  for (std::size_t i = 0; i < foo.body.size(); i++) {
    std::cout << foo.body[i] << std::endl;
  }
}

int32_t main() {
  using std::cout;
  using std::endl;

  std::vector<int16_t> primes { 2, 3, 5, 7, 11, 13, 17, 19 };

  cout << "Size of int16_t: " << sizeof(int16_t) << endl;
  cout << "Length in vector: " << sizeof(std::vector<int16_t>::size_type) << endl;
  cout << "Length in vector: " << sizeof(decltype(primes)::size_type) << endl;
  cout << "Length: " << std::size(primes) << endl;

  for (std::size_t i = 0; i < std::size(primes); i++) {
    cout << primes.at(i) << " : " << &(primes.at(i)) << endl;
  }

  std::size_t i = 3;
  cout << primes[i] << endl;

  Foo f{};
  printFooBody(f);

  return 0;
}
