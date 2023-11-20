#include <iostream>
#include <cstdint>

struct Company {

  struct Employee {
    const std::string_view name;
  };

  int32_t wage{};
  Employee CEO{};

};

struct __attribute__ ((packed)) Foo {
  int16_t a{};
  int32_t b{};
};

int32_t main() {
  Company::Employee CEO{ .name = "Karl and Johann" };
  Company quantco{ .wage = 450'000, .CEO = CEO };

  std::cout << "CEO name: " << quantco.CEO.name << std::endl;

  std::cout << "Size of Foo: " << sizeof(Foo) << std::endl;

  return 0;
}
