#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <initializer_list>
#include <bits/stdc++.h>

#define int1_t char

template<typename T>
class Array {
protected:
    std::size_t m_size;
    std::size_t m_allocated;
    T* m_data;
    friend class String;
    virtual void _print(std::ostream& out) const {
        out << ("{");
        for (int i{ 0 }; i < m_size; ++i) {
            if (i) out << (',');
            out << ' ' << m_data[i];
        }
        out << (" }");
    }
public:
    Array(Array<T>& array) : m_size{ array.m_size }, m_allocated{ array.m_allocated }, m_data{ array.m_data } {
        array.m_data = NULL;
    }
    Array(const Array<T>& array) : m_size{ array.m_size }, m_allocated{ array.m_allocated }, m_data{ array.m_data } {
        memcpy(m_data, array.m_data, m_size * sizeof(T));
    }
    Array(std::size_t size) : m_size{ size }, m_allocated{ (std::size_t)(m_size * 1.3 + 1) }, m_data{ (T*)(malloc(sizeof(T) * m_allocated)) } {
        memset(m_data, 0, sizeof(T)* m_size);
    }
    Array(const std::initializer_list<T>& list) : m_size{ list.size() }, m_allocated{ (std::size_t)(m_size * 1.3 + 1) }, m_data{ (T*)(malloc(sizeof(T) * m_allocated)) } {
        int j{ 0 };
        for (const T& i : list) {
            m_data[j] = i;
            ++j;
        }
    }
    virtual ~Array() {
        free(m_data);
    }
    virtual std::size_t size() const {
        return m_size;
    }
    Array<T>& resize(std::size_t size) {
        if (m_size == size) return *this;
        bool expanded{ (m_allocated < size) };
        if ((m_allocated < size) || ((std::size_t)(m_allocated * 0.7 + 1) > size)) {
            m_allocated = (std::size_t)((size * 1.3) + 1);
        }
        else {
            m_size = size;
            return *this;
        }
        T* tmp{ (T*)(realloc(m_data, (sizeof(T) * m_allocated))) };
        if (tmp != NULL) m_data = tmp;
        if (expanded) {
            memset(m_data + m_size, 0, (size - m_size) * sizeof(T));
            if (tmp == NULL) throw "Out of memory.\n";
        }
        m_data = tmp;
        m_size = size;
        return *this;
    }
    T& operator[] (std::size_t index) const {
        if (index < 0) index += m_size;
        if (index >= m_size || index < 0) throw "Out of range.\n";
        return m_data[index];
    }
    Array<T> operator+ (const Array<T>& array) const {
        Array<T> arr(m_size + array.m_size);
        memcpy(arr.m_data, m_data, m_size * sizeof(T));
        memcpy(arr.m_data + m_size, array.m_data, array.m_size * sizeof(T));
        return arr;
    }
    Array<T>& operator+= (const Array<T>& array) {
        std::size_t old_size{ m_size };
        resize(m_size + array.m_size);
        memcpy(m_data + old_size, array.m_data, array.m_size * sizeof(T));
        return *this;
    }
    Array<T>& operator= (const Array<T>& array) {
        resize(array.m_size);
        memcpy(m_data, array.m_data, array.m_size * sizeof(T));
        return *this;
    }
    friend std::ostream& operator<<(std::ostream& out, const Array<T>& arr) {
        arr._print(out);
        return out;
    }
protected:
    //TODO: edit the comparison function!!!!
public:
    Array<T>& sort() {
        qsort(m_data, m_size, sizeof(T), [](const void* a, const void* b) -> int {
            return *((T*)(a)) > *((T*)(b));
            });
        return *this;
    }
    inline bool operator==(const Array<T>& arr) const {
        if (m_size != arr.m_size) return 0;
        return !(memcmp(m_data, arr.m_data, m_size));
    }
    inline bool operator!=(const Array<T>& arr) const {
        if (m_size != arr.m_size) return 1;
        return (memcmp(m_data, arr.m_data, m_size));
    }
    operator T* () const {
        return m_data;
    }
};

// template<typename T = char>
class String : public Array<char> {
protected:
    virtual void _print(std::ostream& out) const override {
        for (int i{ 0 }; i < m_size; ++i) {
            if (m_data[i] == '\0') return;
            out << (m_data[i]);
        }
        return;
    }
    String(String& array) : Array<char>{ array } {}
public:
    String(std::size_t size) : Array(size) {}
    String(const char* str) : Array<char>((std::size_t)strlen(str)) {
        strcpy(m_data, str);
    }
    String() : Array<char>(0UL) {}
    String operator+ (String& array) const {
        String arr{ m_size + array.m_size };
        memcpy(arr.m_data, m_data, m_size);
        memcpy(arr.m_data + m_size, array.m_data, array.m_size);
        return arr;
    }
    String operator+ (const char* array) const {
        String arr{ m_size + strlen(array) };
        memcpy(arr.m_data, m_data, m_size);
        strcpy(arr.m_data + m_size, array);
        return arr;
    }
    String operator+ (char ch) const {
        String arr{ m_size + 1 };
        memcpy(arr.m_data, m_data, m_size);
        arr.m_data[m_size] = ch;
        return arr;
    }
    String& operator+= (String& array) {
        std::size_t old_size{ m_size };
        resize(m_size + array.m_size);
        memcpy(m_data + old_size, array.m_data, array.m_size);
        return *this;
    }
    String& operator+= (const char* array) {
        std::size_t old_size{ m_size };
        resize(m_size + strlen(array));
        strcpy(m_data + old_size, array);
        return *this;
    }
    String& operator+= (char ch) {
        std::size_t old_size{ m_size };
        resize(m_size + 1);
        m_data[old_size] = ch;
        return *this;
    }
    String& operator= (String& array) {
        resize(array.m_size);
        memcpy(m_data, array.m_data, array.m_size);
        return *this;
    }
    String& operator= (const char* array) {
        resize(strlen(array));
        strcpy(m_data, array);
        return *this;
    }
    String& operator= (char ch) {
        resize(1);
        m_data[0] = ch;
        return *this;
    }
    inline bool operator==(const String& arr) const {
        if (m_size != arr.m_size) return 0;
        return !(memcmp(m_data, arr.m_data, m_size));
    }
    inline bool operator!=(const String& arr) const {
        if (m_size != arr.m_size) return 1;
        return (memcmp(m_data, arr.m_data, m_size));
    }
    operator char* () const {
        return m_data;
    }
    int readChars(FILE* f, std::size_t count) {
        resize(count);
        std::size_t i{ 0 };
        for (char* d{ m_data }; i < count; ++i) {
            *(d++) = fgetc(f);
            if (*(d - 1) == EOF) return -1;
        }
        return 0;
    }
};