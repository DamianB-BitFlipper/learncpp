#include <iostream>
#include <cstdint>

#define isSmall(T) (sizeof(T) <= 2 * sizeof(void*))

const int g_x{ 10 };

void addOne(const int& b) {
  std::cout << "Printing b: " << b << std::endl;
}

void printSV(std::string_view sv) {
  std::cout << "String value: " << sv << std::endl;
}

void printS(const std::string& s) {
  std::cout << "String value: " << s << std::endl;
}

int32_t main() {
  using std::cout;
  using std::endl;
  
  int x{ 69 };
  int xx{ 13 };
  int* x_ptr{ &x };
  constexpr const int& y{ g_x };
  const int& z{ x };
  int& a{ x };

  char c{ 'E' };
  int* c_int { reinterpret_cast<int*>(&c) };
  
  x++;

  x_ptr = &xx;
  (*x_ptr)++;
  
  addOne(a);

  double x_arr[3] = {3, 4, 5};
  int b{ 30 };
  int* b_ptr{ &b };
  
  cout << std::boolalpha << isSmall(x_arr) << endl;
  cout << "X is: " << x << " " << y << " " << z << endl;
  cout << "XX is: " << xx << endl;
  
  printSV("Hello");
  printS("World");

  cout << "Address of x_arr " << x_arr << endl;
  cout << "B " << *&b << endl;
  cout << "B ptr " << *b_ptr << endl;

  cout << "C " << c << " C int " << *c_int << endl;
  
  return 0;
}
