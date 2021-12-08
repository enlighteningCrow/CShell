#include "utils.h"
#include "array_view.h"

String::String(String_view &strview) : Array<char>(strview.size()) { memcpy(m_data, &strview[0], m_size); }
// String::String(String_view &&strview) : Array<char>(strview.size()) { memcpy(m_data, &strview[0], m_size); }

template<class T>
Array<T> Array<T>::operator+(const Array_view<T> &array) const {
    if (!array.size()) { return Array<T>(); }
    Array<T> arr(m_size + array.m_size);
    memcpy(arr.m_data, m_data, m_size * sizeof(T));
    memcpy(arr.m_data + m_size, &array[0], array.size() * sizeof(T));
    m_is_sorted = false;
    return arr;
}

template<class T>
Array<T> &Array<T>::operator+=(const Array_view<T> &array) {
    if (!array.size()) { return Array<T>(); }
    size_ut old_size{m_size};
    resize(m_size + array.size());
    memcpy(m_data + old_size, &array[0], array.size() * sizeof(T));
    m_is_sorted = false;
    return *this;
}

template<class T>
Array<T> &Array<T>::operator=(const Array_view<T> &array) {
    if (!array.size()) { return Array<T>(); }
    resize(array.size());
    memcpy(m_data, &array[0], array.size() * sizeof(T));
    m_is_sorted = array.arr.m_is_sorted;
    return *this;
}


size_ut String::find(String_view &target) {
    size_ut str_size = target.size();
    for (size_ut i{0}; i <= this->size() - str_size; ++i) {
        for (size_ut j{0}; j < str_size; ++j) {
            if (target[j] == this->operator[](i + j)) continue;
            goto not_equal;
            // break;
            // for (const char* ptr{})
        }
        return i;
    not_equal:;
    }
    return this->size();
}

bool isAlnum(char c) { return ((c <= 'Z' && c >= 'A') || (c <= 'z' && c >= 'a') || (c <= '9' && c >= '0')); }
bool isAlphabet(char c) { return ((c <= 'Z' && c >= 'A') || (c <= 'z' && c >= 'a')); }
bool isNumber(char c) { return (c <= '9' && c >= '0'); }