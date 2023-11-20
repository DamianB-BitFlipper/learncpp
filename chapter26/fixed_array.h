#pragma once

#include <iostream>
#include <initializer_list>
#include <cstdint>

template <typename T>
class FixedArray {
public:

  FixedArray(int32_t length) 
    : m_length{ length }
    , m_data{ new T[length]{} } // Zero initialize the `m_data`
  {
    std::cout << "Instantiating via size!" << std::endl;
  }

  FixedArray(std::initializer_list<T> list)
    : m_length{ static_cast<int32_t>(list.size()) }
    , m_data{ new T[m_length] }
  {
    std::cout << "Instantiating via list!" << std::endl;

    int32_t i{ 0 };
    for (auto& element : list) {
      m_data[i] = element;
      i++;
    }
  }

  ~FixedArray() {
    std::cout << "Cleaning Up!" << std::endl;
    delete[] m_data;
  }

  FixedArray(const FixedArray&) = delete;
  FixedArray& operator=(const FixedArray&) = delete;

  T& operator[](int32_t index) const;

  int32_t getLength() const { return m_length; }
  
private:
  const int32_t m_length{};
  T* m_data{};
};

// #include "fixed_array.inl"
