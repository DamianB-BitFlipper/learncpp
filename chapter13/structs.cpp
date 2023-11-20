#include <iostream>
#include <cstdint>

struct Employee {

  int32_t id{};
  std::string_view name{};
  int32_t age{ 35 };

};

Employee genericEmployee() {
  return { .id = 45, .name = "Billy", .age = 19 };
}

void printEmployee(const Employee& employee) {
  std::cout << "Name: " << employee.name << " Age: " << employee.age << std::endl;  
}

int32_t main() {

  Employee joe{ genericEmployee() };

  Employee joeTwo{ joe };

  std::cout << "Name: " << joe.name << " Age: " << joe.age << std::endl;
  printEmployee(joeTwo);

  return 0;
}
