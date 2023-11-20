#include <iostream>
#include <initializer_list>
#include <cstdint>

class IntArray {
public:

  IntArray(int32_t length) 
    : m_length{ length }
    , m_data{ new (std::nothrow) int[static_cast<std::size_t>(length)]{} }
  {}

  ~IntArray() {
    delete[] m_data;
  }

  IntArray(std::initializer_list<int32_t> list) 
    : IntArray(static_cast<int32_t>(list.size())) 
  {
    int32_t count{ 0 };
    for (auto value : list) {
      m_data[count] = value;
      count++;
    }
  }

  IntArray(const IntArray&) = delete;
  IntArray& operator=(const IntArray&) = delete;
  IntArray& operator=(const IntArray&) const = delete;

  int32_t getLength() const { return m_length; }

private:
  int32_t m_length{};
  int32_t* m_data{};
};

int32_t main() {
  IntArray iarray{ 1, 2, 3, 4 };

  std::cout << "Length: " << iarray.getLength() << std::endl;

  return 0;
}
