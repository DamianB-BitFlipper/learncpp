#include <iostream>
#include <cstdint>

class Food {
public:
  Food() : Food{ 100 } {
  };

  Food(int32_t cost, int32_t tax=10) : m_cost { cost }, m_tax { tax }, m_something { 150 } {}

  /*
  Food(const Food& food) 
    : m_cost { food.m_cost }
    , m_tax { food.m_tax }
    , m_something { food.m_something + 50 } 
  {
  }
  */
  Food(const Food& food) = default;

  void print() const {
    std::cout << "Food: " << m_cost << " " << m_tax << " " << m_something << std::endl;
  }

private:
  const int32_t m_cost{};
  const int32_t m_tax{};
  int32_t m_something;

};

void print(const Food& food) {
  std::cout << "Outside" << std::endl;
  food.print();
}

Food printCopy(const Food food) {
  std::cout << "Outside Copy" << std::endl;
  food.print();
  return food;
}

int32_t main() {
  Food e;
  Food f{};
  Food g{ 69 };
  Food h{ g };

  e.print();
  f.print();
  g.print();
  h.print();
  Food i{ printCopy(h) };
  print(i);

  print({1, 2});

  return 0;
}
