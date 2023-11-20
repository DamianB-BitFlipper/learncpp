#include <iostream>
#include <cstdint>
#include <vector>

template <int32_t N, typename T>
void printVector(const std::vector<T>& vector) {
  std::cout << "Printing N: " << N << " not defined!" << std::endl;
}

template<>
void printVector<1>(const std::vector<int32_t>& vector) {
  typename std::remove_reference_t<decltype(vector)>::size_type index{ 0 };
  for (; index < vector.size(); index++) {
    std::cout << "1: " << index << " : " << vector[index] << std::endl;
  }
}

template<>
void printVector<2>(const std::vector<int32_t>& vector) {
  for (std::ptrdiff_t i{ 0 }; i < static_cast<std::ptrdiff_t>(vector.size()); i++) {
    std::cout << "2: " << i << " : " << vector[i] << std::endl;
  }
}

int32_t main() {
  std::vector<int32_t> vector{ 1, 3, 2, 4, 3, 5, 4, 6 };

  printVector<1>(vector);
  std::cout << std::string(10, '-') << std::endl;
  printVector<2>(vector);

  return 0;
}
