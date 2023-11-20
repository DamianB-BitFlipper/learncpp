#include "fixed_array.h"

#include <cstdint>

template <typename T>
T& FixedArray<T>::operator[](int32_t index) const {
  return m_data[index];  
}

// Explicitly create a `FixedArray` of various types
template class FixedArray<int8_t>;
template class FixedArray<int16_t>;
template class FixedArray<int32_t>;
