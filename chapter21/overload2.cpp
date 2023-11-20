#include "cents.h"

#include <cstdint>

void printInt(int x) {
  std::cout << x << std::endl;
}

int32_t main() {
  using namespace std::literals;

  const Cents c1{ 34 }, c2{ 35 };

  Cents c3{ (2 + c1 + c2 + 1 - 4) * 2};

  (!-c3).print();

  c3[69] = 123;
  c3.print();

  std::cout << c1[123] << std::endl;
  c1["Yolo"sv];

  Cents c4{ c1(4, 5) };
  c4["Hey!"];
  c4();

  printInt(static_cast<int>(c4));

  c3 = c4;
  c3();

  c3->m_public;
  c3();

  return 0;
}
