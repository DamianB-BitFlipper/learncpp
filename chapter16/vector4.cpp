#include <iostream>
#include <cstdint>
#include <vector>

template <typename T>
class VectorView {
public:
  using Index = std::ptrdiff_t;

  VectorView(T& vector) : m_vector{ vector } {}

  friend std::ostream& operator<<(std::ostream& out, const VectorView<T>& vecView) {
    for (Index index{ 0 }; index < vecView.size(); index++) {
      out << vecView[index] << std::endl;
    }

    return out;
  }

  constexpr auto& operator[](Index index) {
    return m_vector[static_cast<typename T::size_type>(index)];
  }

  constexpr const auto& operator[](Index index) const {
    return m_vector[static_cast<typename T::size_type>(index)];    
  }

  constexpr Index size() const {
    return static_cast<Index>(m_vector.size());
  }

  void print() const {
    for (Index index{ 0 }; index < this->size(); index++) {
      std::cout << (*this)[index] << std::endl;
    }
  }

private:
  T& m_vector{};
};

int32_t main() {

  std::vector<int32_t> vector{ 6, 5, 4, 3, 2, 1, 2, 3, 4, 5, };

  VectorView vecView{ vector };

  std::cout << vecView << std::endl;

  vecView.print();
  vecView[5] = 69;
  std::cout << vecView[5] << std::endl;

  return 0;
}
