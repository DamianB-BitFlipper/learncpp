#include <iostream>
#include <cstdint>

class Fruit {
public:
  
  enum Type {
    apple,
    cherry,
    orange,
  };

  class Pit {
  public:
    explicit Pit(bool pitted) : m_pitted{ pitted } {}   
  private:
    const bool m_pitted{};
  };

  explicit Fruit(Type type) : m_fruit{ type }, m_pit{ Pit{ isPitted(type) } } {}

  ~Fruit() {
    std::cout << "Destructing" << std::endl;
  }

  Fruit& eat(int32_t percent) {
    m_percentEaten = std::min(m_percentEaten + percent, 100);
    return *this;
  }

  void print() {
    std::cout << "Eaten: " << m_percentEaten << std::endl;
  }

  static constexpr bool isPitted(Type type) {
    return type != orange;
  }

private:
  
  int32_t m_percentEaten{ 0 };
  const Type m_fruit{};
  const Pit m_pit{ false };

};

int32_t main() {
  
  Fruit fruit{ Fruit::apple };
  fruit.eat(34);
  fruit.print();

  return 0;
}
