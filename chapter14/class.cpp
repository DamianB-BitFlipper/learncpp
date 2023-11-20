#include <iostream>
#include <cstdint>

class Fraction {
public:
  Fraction(std::string_view name, int32_t num, int32_t denom) 
    : m_name { name }
    , m_num { num }
    , m_denom { denom } 
  {
  }

  int32_t getNum() const { return m_num; }
  void setNum(int32_t num) { m_num = num; }

  int32_t getDenom() const { return m_denom; }
  void setDenom(int32_t denom) { m_denom = denom; }

  const std::string& getName() const { return m_name; }
  void setName(std::string_view name) { m_name = name; }

  void print() {
    std::cout << m_name << " : " << m_num << "/" << m_denom << std::endl;
  }

  void print() const {
    std::cout << "(Constant) " << m_name << " : " << m_num << "/" << m_denom << std::endl;
  }

  void dumbAdd(const Fraction& other) {
    m_num += other.m_num;
    m_denom += other.m_denom;
  }

private:
  std::string m_name{};

  int32_t m_num{};
  int32_t m_denom{};
};

int32_t main() {

  Fraction g{ "Bill", 10, 4 };
  g.print();  

  const Fraction f{ "Bob", 20, 4 };
  f.print();

  g.dumbAdd(f);
  g.print();
  [[maybe_unused]] auto& g_name = g.getName();
  //g_name = "Lewis";
  g.print();

  return 0;
}
