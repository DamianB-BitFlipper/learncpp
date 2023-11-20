#include <iostream>
#include <cstdint>
#include <cstddef>

void greet(std::nullptr_t) {
  std::cout << "Hello darkness my old friend" << std::endl;
}

void greet(std::string_view name) {
  std::cout << "Hi my friend: " << name << std::endl;
}

std::string getGuest() {
  return std::string{"guestaloo"};
}

void greet() {
  greet(getGuest());
}

void nullify(int*& ptr) {
  ptr = nullptr;
}

const int& breakLifeExtension(const int& ref) {
  return ref;
}

std::string& smallerStrings(std::string& a, std::string& b) {
  return (a < b) ? a : b;
}

int32_t main() {

  greet();
  greet("Vicky");

  int x{ 69 };
  int* x_ptr{ &x };

  std::cout << "X_ptr is " << x_ptr << std::endl;
  
  nullify(x_ptr);

  std::cout << "X_ptr is " << x_ptr << std::endl;  

  const int x_const{ breakLifeExtension(5) };

  std::cout << "This is bad: " << x_const << std::endl;

  std::string a{ "Hello" };
  std::string b{ "World" };
  std::string& smaller = smallerStrings(a, b);
  std::cout << smaller << std::endl;
  
  return 0;
}
