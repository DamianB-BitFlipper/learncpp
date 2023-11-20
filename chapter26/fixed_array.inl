#include "fixed_array.h"

#include <cstdint>

template <typename T>
T& FixedArray<T>::operator[](int32_t index) const {
  return m_data[index];  
}
