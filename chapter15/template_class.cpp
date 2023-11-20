#include <iostream>
#include <cstdint>

template <typename T>
class Pair {
public:
  Pair(const T& a, const T& b) 
    : m_a { a }
    , m_b { b }
    , m_id { Pair<T>::initID() + Pair<T>::m_npairs }  
  {
    m_npairs++;
  }

  void print() const;

  static int32_t getNPairs() { return m_npairs; }

private:
  T m_a{};
  T m_b{};

  static inline int32_t m_npairs{ 0 };
  const int32_t m_id;

  static int32_t initID() {
    return 69;
  }
};

template <typename T>
void Pair<T>::print() const  {
  std::cout << "npairs: " << m_npairs << std::endl;
  std::cout << "id: " << m_id << std::endl;
  std::cout << "A: " << m_a << " B: " << m_b << std::endl;
}

int32_t main() {
  Pair a{ 1, 5 };
  a.print();

  Pair b{ 2, 6 };
  b.print();

  std::cout << "NPairs int: " << Pair<int>::getNPairs() << std::endl;
  std::cout << "NPairs double: " << Pair<double>::getNPairs() << std::endl;

  return 0;
}
