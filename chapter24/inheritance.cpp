#include <iostream>
#include <cstdint>
#include <string_view>
#include <cassert>

enum class Gender {
  male,
  female,
  diverse,
};

std::ostream& operator<<(std::ostream& out, Gender gender) {
  switch (gender) {
  case Gender::male:
    return out << "Male";
  case Gender::female:
    return out << "Female";
  case Gender::diverse:
    return out << "Diverse";
  }

  assert(false && "Unknown Gender encountered!");
}

class Person {
public:

  Person(std::string_view name, int32_t age, Gender gender) 
    : m_gender{ gender } 
    , m_age{ age }
    , m_name{ name }
  {
    std::cout << "Instantiating Person: " << getName() << std::endl;
  }

  ~Person() {
    std::cout << "Destroying Person: " << getName() << std::endl;
  }

  int32_t getAge() const { return m_age; }
  const std::string& getName() const { return m_name; }

protected:
  const Gender m_gender{};

private:
  int32_t m_age{};
  const std::string m_name{};
};

class BaseballPlayer : public Person {
public:
  BaseballPlayer(
    std::string_view name,
    int age,
    Gender gender,
    double battingAverage=0.0, 
    int homeRuns=0
    )
    : Person{ name, age, gender }
    , m_battingAverage{battingAverage}
    , m_homeRuns{homeRuns}
  {
    std::cout << "Instantiating Baseball Player: " << getName() << " Gender: " << m_gender << std::endl;
  }

  ~BaseballPlayer() {
    std::cout << "Destroying Baseball Player: " << getName() << std::endl;    
  }

  double getBattingAverage() const { return m_battingAverage; }
  int getHomeRuns() const { return m_homeRuns; }

private:
  double m_battingAverage{};
  int m_homeRuns{};
};

int32_t main() {
  using namespace std::string_view_literals;
  Person person1{ "Damian"sv, 25, Gender::male };

  std::cout << "Age: " << person1.getAge() << std::endl;

  BaseballPlayer bball1{.name="Joe"sv, .age=25, .gender=Gender::male, .battingAverage=6.9 };

  std::cout << "Batting Average: " << bball1.getBattingAverage() << std::endl;

  return 0;
}
