#include "nontype_fixed_array.h"

#include <cstdint>

template <typename T, int32_t size>
T& FixedArray<T, size>::operator[](int32_t index) const {
  return m_data[index];  
}
