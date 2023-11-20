#include <iostream>
#include <cstdint>

int32_t main() {
  int** array2D{ new (std::nothrow)int*[4] };
  for (int i{ 0 }; i < 4; i++) {
    array2D[i] = new (std::nothrow)int[3]{};
  }

  for (int i{ 0 }; i < 4; i++) {
    for (int j{ 0 }; j < 3; j++) {
      std::cout << array2D[i][j] << ' ';
    }
    std::cout << std::endl;
  }

  for (int i{ 0 }; i < 4; i++) {
    delete[] array2D[i];
  }
  delete[] array2D;

  return 0;
}
