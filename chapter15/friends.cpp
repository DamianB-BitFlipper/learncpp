#include <iostream>
#include <cstdint>

class Accumulator;

class Prefix {
public:

  explicit Prefix(std::string_view sv) : m_prefix { sv } {}

  friend void print(const Accumulator& accumulator, const Prefix& prefix);

private:
  std::string_view m_prefix{};
};

class Accumulator {
public:

  Accumulator() = default;

  void add(int32_t n) {
    m_acc += n;
  }

  void print() const {
    std::cout << "Inside" << std::endl;
    std::cout << "Acc: " << m_acc << std::endl;
  }

  friend void print(const Accumulator& accumulator);

  friend void print(const Accumulator& accumulator, const Prefix& prefix) {
    std::cout << prefix.m_prefix << std::endl;
    std::cout << "Acc: " << accumulator.m_acc << std::endl;
  }

private:
  int32_t m_acc{ 0 };
};

void print(const Accumulator& accumulator) {
  std::cout << "Outside" << std::endl;
  std::cout << "Acc: " << accumulator.m_acc << std::endl;
}

int32_t main() {
  using namespace std::literals;

  Accumulator acc{};
  acc.add(34);
  acc.add(35);
  acc.print();

  print(acc);
  print(acc, Prefix{ "Yolo"sv });

  return 0;
}
