#include <iostream>
#include <cstdint>

class IntArray {
public:

  IntArray(std::size_t length, int defaultVal=69) 
    : m_length{ length }
    , m_id{ IntArray::id++ }
  {
    m_array = new int[length]{};

    for (std::size_t i{ 0 }; i < length; i++) {
      m_array[i] = defaultVal;
    }
  }

  ~IntArray() {
    std::cout << "Freeing array: " << m_id << std::endl;
    delete[] m_array;
  }

  // Make this class non-copyable
  IntArray(const IntArray&) = delete;
  IntArray& operator=(const IntArray&) = delete;

  std::size_t getLength() const { return m_length; }

  void print() const {
    for (std::size_t i{ 0 }; i < m_length; i++) {
      std::cout << m_array[i] << ' ';
    }    
    std::cout << std::endl;
  }

private:
  const std::size_t m_length{};
  const int m_id{};
  int* m_array{};

  // static inline int id{ 0 };
  static int id;
};

int IntArray::id{0};

int32_t main() {
  int* dynArray{ new (std::nothrow) int[5]{} };

  for (std::size_t i{ 0 }; i < 5; i++) {
    std::cout << dynArray[i] << std::endl;
  }

  delete[] dynArray;

  IntArray iarray{ 10 };
  iarray.print();

  IntArray* dynIArray{ new (std::nothrow) IntArray{4} };
  dynIArray->print();
  delete dynIArray;

  return 0;
}
