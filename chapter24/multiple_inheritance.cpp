#include <iostream>
#include <cstdint>
#include <string>
#include <string_view>

class Person
{
public:
  Person(std::string_view name, int age) : m_name{ name }, m_age{ age } {
    std::cout << "Making Person" << std::endl;
  }

  ~Person() {
    std::cout << "Destroying Person" << std::endl;    
  }

  const std::string& getName() const { return m_name; }
  int getAge() const { return m_age; }

private:
  std::string m_name;
  int m_age{};
};

class Employee
{
public:
  Employee(std::string_view employer, double wage, int age) 
    : m_employer{ employer }
    , m_wage{ wage }
    , m_age{ age }
  {
    std::cout << "Making Employee" << std::endl;
  }

  ~Employee() {
    std::cout << "Destroying Employee" << std::endl;
  }

  const std::string& getEmployer() const { return m_employer; }
  double getWage() const { return m_wage; }
  int getAge() const { return m_age; }

private:
  std::string m_employer;
  double m_wage{};
  int m_age{};
};

// Teacher publicly inherits Person and Employee
class Teacher : public Person, public Employee
{
public:
  Teacher(std::string_view name, int age, std::string_view employer, double wage, int teachesGrade)
    : Person{ name, age }
    , Employee{ employer, wage, age }
    , m_teachesGrade{ teachesGrade }
  {
    std::cout << "Making Teacher" << std::endl;
  }

  ~Teacher() {
    std::cout << "Destroying Teacher" << std::endl;
  }

private:
  int m_teachesGrade{};
};


int32_t main() {
  Teacher teacher{ .name="Bill", .age=45, .employer="Winchester", .wage=100'000, .teachesGrade=11 };

  std::cout << teacher.Employee::getAge() << std::endl;
  std::cout << teacher.Person::getAge() << std::endl;

  return 0;
}
