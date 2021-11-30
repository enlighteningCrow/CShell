#ifndef UTILS_H
#define UTILS_H

#include <bits/stdc++.h>
#include <cstddef>
#include <iterator>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

typedef long long int size_ut;

#include <initializer_list>
#include <iostream>
#include "misc.h"

#include "file_io.h"

// #define int1_t char

typedef char int1_t;

// #include "array_view.h"

template<class T>
class Array_view;

class String_view;

/* class FileWrapper {
friend FileWrapper& operator<<(FileWrapper& out, const char* ch) {
    for (char* c{ ch }; *c; ++c) {
        fputc(c, file);
    }
    return out;
}
};
*/
/* FILE& operator<<(FILE& out, const char* ch) {
    for (const char* c{ ch }; *c; ++c) {
        fputc(*c, &out);
    }
    return out;
} */


// template<class T>
// class Array_view<T>;

template<typename T>
class Array {
protected:
    size_ut      m_size;
    size_ut      m_allocated;
    T *          m_data;
    mutable bool m_is_sorted;
    // friend class String;
    virtual void _print(std::ostream &out) const {
        out << ("{");
        for (int i{0}; i < m_size; ++i) {
            if (i) out << (',');
            out << ' ' << m_data[i];
        }
        out << (" }");
    }
    virtual void _print(FILE &out) const {
        out << ("{");
        for (int i{0}; i < m_size; ++i) {
            if (i) out << (',');
            out << ' ' << m_data[i];
        }
        out << (" }");
    }

public:
    struct Iter {
    public:
        using value_type        = T;
        using pointer           = value_type *;
        using reference         = value_type &;
        using iterator_category = std::random_access_iterator_tag;
        using difference_type   = std::ptrdiff_t;

    protected:
        pointer m_ptr;

    public:
        reference operator*() const { return *m_ptr; }
        pointer   operator->() const { return m_ptr; }
        Iter &    operator++() {
            ++m_ptr;
            return *this;
        }
        Iter operator++(int) {
            ++m_ptr;
            return Iter(m_ptr - 1);
        }
        friend bool operator==(const Iter &a, const Iter &b) { return a.m_ptr == b.m_ptr; };
        friend bool operator!=(const Iter &a, const Iter &b) { return a.m_ptr != b.m_ptr; };
        Iter(const pointer &ptr) : m_ptr{ptr} {}
        Iter(const Iter &ptr) : m_ptr{ptr.m_ptr} {}
    };
    /*
    Array(Array<T>& array)
        : m_size{ array.m_size }
        , m_allocated{ array.m_allocated }
        , m_data{ array.m_data }
        , m_is_sorted{ m_is_sorted }
        , _middle{ 0 }
    {
        array.m_data = NULL;
    }
    Array(const Array<T>& array)
        : m_size{ array.m_size }
        , m_allocated{ array.m_allocated }
        , m_data{ array.m_data }
        , m_is_sorted{ array.m_is_sorted }
        , _middle{ 0 }
    {
        memcpy(m_data, array.m_data, m_size * sizeof(T));
    } */
    Array(Array<T> &array) :
        m_size{array.m_size}, m_allocated{array.m_allocated}, m_data{(T *)malloc(sizeof(T) * array.m_size)},
        m_is_sorted{array.m_is_sorted}, _middle{0} {
        memcpy(m_data, array.m_data, m_size * sizeof(T));
        // array.m_data = NULL;
    }
    Array(Array<T> &&array) :
        m_size{array.m_size}, m_allocated{array.m_allocated}, m_data{array.m_data},
        m_is_sorted{array.m_is_sorted}, _middle{0} {
        array.m_data = NULL;
        // memcpy(m_data, array.m_data, m_size * sizeof(T));
    }
    Array(const Array<T> &array) :
        m_size{array.m_size}, m_allocated{array.m_allocated}, m_data{(T *)malloc(sizeof(T) * array.m_size)},
        m_is_sorted{array.m_is_sorted}, _middle{0} {
        memcpy(m_data, array.m_data, m_size * sizeof(T));
    }
    Array(size_ut size) :
        m_size{size}, m_allocated{(size_ut)(size * 1.3 + 1)}, m_data{(T *)(malloc(sizeof(T) * m_allocated))},
        m_is_sorted{false}, _middle{0} {
        memset(m_data, 0, sizeof(T) * m_size);
    }
    Array() : Array(0UL) {}
    Array(const std::initializer_list<T> &list) :
        m_size{list.size()}, m_allocated{(size_ut)(m_size * 1.3 + 1)}, m_data{(T *)(malloc(sizeof(T) * m_allocated))},
        m_is_sorted{false} {
        int j{0};
        for (const T &i : list) {
            m_data[j] = i;
            ++j;
        }
    }
    virtual ~Array() { free(m_data); }
    virtual size_ut size() const { return m_size; }
    Array<T> &      resize(size_ut size) {
        if (m_size == size) return *this;
        bool expanded{(m_allocated < size)};
        if ((m_allocated < size) || ((size_ut)(m_allocated * 0.7 + 1) > size)) {
            m_allocated = (size_ut)((size * 1.3) + 1);
        }
        else {
            m_size = size;
            return *this;
        }
        T *tmp{(T *)(realloc(m_data, (sizeof(T) * m_allocated)))};
        if (tmp != NULL) m_data = tmp;
        if (expanded) {
            memset(m_data + m_size, 0, (size - m_size) * sizeof(T));
            if (tmp == NULL) {
                fprintf(stderr, "Out of memory.\n");
                return *this;
            }
            // throw "Out of memory.\n";
            m_is_sorted = false;
        }
        m_data = tmp;
        m_size = size;
        return *this;
    }

    Array<T> &remove(size_ut start, size_ut end) {
        memcpy(m_data + start, m_data + end, (m_size - end) * sizeof(T));
        resize(m_size - (end - start));
        return *this;
    }

    Array<T> &insert(const T &value, size_ut index) {
        std::cout << "called resize with " << m_size + 1 << ".\n";
        resize(m_size + 1);
        std::cout << "called memmove with m_data + " << index + 1 << ", m_data + " << index << ", "
                  << m_size - index - 1 << ".\n";
        memmove(m_data + index + 1, m_data + index, (m_size - index - 1) * sizeof(T));
        m_data[index] = value;
        return *this;
    }

    // NOTE!!!!!: this replace is NON-INCLUSIVE, like for loops.
    Array<T> &replace(const T &value, size_ut start, size_ut end) {
        // memcpy(m_data + start, m_data + end, m_size - end);
        // remove(start + 1, end);

        // memcpy(m_data + start + 1, m_data + end, (m_size - end) * sizeof(T) - 1);
        memcpy(m_data + start + 1, m_data + end, (m_size - end) * sizeof(T));
        resize(m_size - (end - start) + 1);
        m_data[start] = value;
        return *this;
    }

    Array<T> &fill(const T &value, size_ut start, size_ut end) {
        for (size_ut i{start}; i < end; ++i) { m_data[i] = value; }
        return *this;
    }

    Array<T> &pop_front(size_ut indexes = 1ULL) {
        memcpy(m_data, m_data + indexes, m_size - indexes);
        resize(m_size - indexes);
        return *this;
    }

    Array<T> &push_front(const T &val) {
        resize(++m_size);
        memmove(m_data + 1, m_data, m_size);
        *m_data = val;
        return *this;
    }

    virtual T &operator[](size_ut index) const {
        if (index < 0) index += m_size;
        if (index >= m_size || index < 0) {
            fprintf(stderr, "Out of range.\n");
            // return T();
            throw "Out of range.\n";
        }
        return m_data[index];
    }
    Array<T> operator+(const Array<T> &array) const {
        Array<T> arr(m_size + array.m_size);
        memcpy(arr.m_data, m_data, m_size * sizeof(T));
        memcpy(arr.m_data + m_size, array.m_data, array.m_size * sizeof(T));
        m_is_sorted = false;
        return arr;
    }
    Array<T> &operator+=(const Array<T> &array) {
        size_ut old_size{m_size};
        resize(m_size + array.m_size);
        memcpy(m_data + old_size, array.m_data, array.m_size * sizeof(T));
        m_is_sorted = false;
        return *this;
    }
    Array<T> &operator=(const Array<T> &array) {
        resize(array.m_size);
        memcpy(m_data, array.m_data, array.m_size * sizeof(T));
        m_is_sorted = array.m_is_sorted;
        return *this;
    }


    Array<T> operator+(const Array_view<T> &array) const;
    // Array<T> operator+(const Array_view<T> &array) const {
    //     Array<T> arr(m_size + array.m_size);
    //     memcpy(arr.m_data, m_data, m_size * sizeof(T));
    //     memcpy(arr.m_data + m_size, array.m_data, array.size() * sizeof(T));
    //     m_is_sorted = false;
    //     return arr;
    // }
    Array<T> &operator+=(const Array_view<T> &array);
    // Array<T> &operator+=(const Array<T> &array) {
    //     size_ut old_size{m_size};
    //     resize(m_size + array.m_size);
    //     memcpy(m_data + old_size, array.m_data, array.m_size * sizeof(T));
    //     m_is_sorted = false;
    //     return *this;
    // }
    Array<T> &operator=(const Array_view<T> &array);
    // Array<T> &operator=(const Array<T> &array) {
    //     resize(array.m_size);
    //     memcpy(m_data, array.m_data, array.m_size * sizeof(T));
    //     m_is_sorted = array.m_is_sorted;
    //     return *this;
    // }

    virtual size_ut find(const T &target) {
        if (!m_size) { return 0UL; }
        if (!m_is_sorted) { sort(); }
        return _find(target, 0, m_size - 1);
    }
    virtual size_ut findGreater(const T &target) {
        if (!m_size) { return 0UL; }
        if (!m_is_sorted) { sort(); }
        return _findg(target, 0, m_size - 1);
    }
    virtual size_ut findGreaterEq(const T &target) {
        if (!m_size) { return 0UL; }
        if (!m_is_sorted) { sort(); }
        return _findge(target, 0, m_size - 1);
    }
    virtual size_ut findLesser(const T &target) {
        if (!m_size) { return 0UL; }
        if (!m_is_sorted) { sort(); }
        return _findl(target, 0, m_size - 1);
    }
    virtual size_ut findLesserEq(const T &target) {
        if (!m_size) { return 0UL; }
        if (!m_is_sorted) { sort(); }
        return _findle(target, 0, m_size - 1);
    }

    friend std::ostream &operator<<(std::ostream &out, const Array<T> &arr) {
        arr._print(out);
        return out;
    }
    friend FILE &operator<<(FILE &out, const Array<T> &arr) {
        arr._print(out);
        return out;
    }

    Array<T> &clear() { resize(0); }

protected:
    size_ut         _middle;
    virtual size_ut _find(const T &target, size_ut left, size_ut right) {
        if (right < left) return m_size;
        _middle = (left + (right - left) / 2);
        if (m_data[_middle] == target)
            return _middle;
        else if (m_data[_middle] > target)
            return _find(target, left, _middle - 1);
        else
            return _find(target, _middle + 1, right);
    }
    virtual size_ut _findg(const T &target, size_ut left, size_ut right) {
        if (right < left) return _middle;
        _middle = (left + (right - left) / 2);
        if (m_data[_middle] == target)
            return _find(target, _middle + 1, right);
        else if (m_data[_middle] > target) {
            if (_middle == 0) { return _middle; }
            if (!(m_data[_middle - 1] > target)) return _middle;
            return _find(target, left, _middle - 1);
        }
        else
            return _find(target, _middle + 1, right);
    }
    virtual size_ut _findl(const T &target, size_ut left, size_ut right) {
        if (right < left) return _middle;
        _middle = (left + (right - left) / 2);
        if (m_data[_middle] == target)
            return _find(target, _middle + 1, right);
        else if (m_data[_middle] > target) {
            return _find(target, left, _middle - 1);
        }
        else {
            if (_middle == m_size - 1) { return _middle; }
            if (!(m_data[_middle + 1] < target)) return _middle;
            return _find(target, _middle + 1, right);
        }
    }
    virtual size_ut _findge(const T &target, size_ut left, size_ut right) {
        if (right < left) return _middle;
        _middle = (left + (right - left) / 2);
        if (m_data[_middle] == target) {
            if (_middle == m_size - 1) { return _middle; }
            return _find(target, _middle + 1, right);
        }
        else if (m_data[_middle] > target) {
            if (_middle == 0) { return _middle; }
            if (!(m_data[_middle - 1] > target)) return _middle - 1;
            return _find(target, left, _middle - 1);
        }
        else
            return _find(target, _middle + 1, right);
    }
    virtual size_ut _findle(const T &target, size_ut left, size_ut right) {
        if (right < left) return _middle;
        _middle = (left + (right - left) / 2);
        if (m_data[_middle] == target) {
            if (_middle == 0) { return _middle; }
            return _find(target, _middle + 1, right);
        }
        else if (m_data[_middle] > target) {
            return _find(target, left, _middle - 1);
        }
        else {
            if (_middle == m_size - 1) { return _middle; }
            if (!(m_data[_middle + 1] < target)) return _middle + 1;
            return _find(target, _middle + 1, right);
        }
    }
    // TODO: edit the comparison function!!!!
public:
    Array<T> &push_back(const T &element) {
        //    ++m_size;
        //    if (m_size > m_allocated) {
        //      m_data = realloc(m_data, (size_ut)(m_size * 1.5 + 1));
        //      m_allocated = (size_ut)(m_size * 1.5 + 1);
        //    }
        //    *(m_data + m_size - 1) = element;
        //    return *this;
        resize(m_size + 1);
        m_data[m_size - 1] = element;
        m_is_sorted        = false;
        return *this;
    }
    Array<T> &pop_back() {
        //    --m_size;
        //    if (m_size < (size_ut)(m_allocated * 0.7)) {
        //      m_data = realloc(m_data, (size_ut)(m_size * 0.7 + 1));
        //      m_allocated = (size_ut)(m_size * 0.7 + 1);
        //    }
        //    return *this;
        resize(m_size - 1);
        return *this;
    }

    virtual Array<T> &sort() {
        if (m_is_sorted) { return *this; }
        qsort(m_data, m_size, sizeof(T), [](const void *a, const void *b) -> int { return *((T *)(a)) > *((T *)(b)); });
        m_is_sorted = true;
        return *this;
    }
    inline bool operator==(const Array<T> &arr) const {
        if (m_size != arr.m_size) return 0;
        return !(memcmp(m_data, arr.m_data, m_size));
    }
    inline bool operator!=(const Array<T> &arr) const {
        if (m_size != arr.m_size) return 1;
        return (memcmp(m_data, arr.m_data, m_size));
    }
    explicit operator T *() const { return m_data; }
    //   friend std::ostream& operator<<(std::ostream& out, const Array<T>& arr) {
    //       for (int i{ 0 }; i < arr.size(); ++i) {
    //           out << i;
    //       }
    //       return arr;
    //   }
    Iter begin() { return Iter(m_data); }
    Iter end() { return Iter(m_data + m_size() - 1); }
};


// template<typename T = char>
class String : public Array<char> {
protected:
    virtual void _print(std::ostream &out) const override {
        for (int i{0}; i < m_size; ++i) {
            if (!m_data[i]) return;
            out << (m_data[i]);
        }
        return;
    }
    virtual void _print(FILE &out) const override {
        for (int i{0}; i < m_size; ++i) {
            if (!m_data[i]) return;
            out << (m_data[i]);
        }
        return;
    }
    void shrink() {}

public:
    String(String &array) : Array<char>{array} {}
    String(String &&array) : Array<char>{array} {}
    String(size_ut size) : Array(size) {}
    String(const char *str) : Array<char>((size_ut)strlen(str)) { memcpy(m_data, str, m_size); }
    String(String_view &strview); // : Array<char>(strview.size()) { memcpy(m_data, str, m_size); }
    String() : Array<char>(0UL) {}
    bool            operator<(const String &array) const { return strcmp(this->m_data, array.m_data) < 0; }
    bool            operator>(const String &array) const { return strcmp(this->m_data, array.m_data) > 0; }
    bool            operator<=(const String &array) const { return strcmp(this->m_data, array.m_data) <= 0; }
    bool            operator>=(const String &array) const { return strcmp(this->m_data, array.m_data) >= 0; }
    virtual size_ut find(const char *target) {
        size_ut str_size = strlen(target);
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
    virtual size_ut find(const String &target) {
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
    virtual size_ut find(/* const Array_view<char> */ String_view &target);
    // virtual size_ut find(const Array_view<char>& target) {
    //     size_ut str_size = target.size();
    //     for (size_ut i{ 0 }; i <= this->size() - str_size; ++i) {
    //         for (size_ut j{ 0 }; j < str_size; ++j) {
    //             if (target[j] == this->operator[](i + j)) continue;
    //             goto not_equal;
    //             // break;
    //             // for (const char* ptr{})
    //         }
    //         return i;
    //     not_equal:;
    //     }
    //     return this->size();
    // }
    String &purge(size_ut start, size_ut end) {
        memset(m_data + start, 0, end - start);
        // for (;start < end; ++start) {
        //
        // }
    }
    String &operator<<(FILE &f) {
        // int fd = fileno(&f);
        // struct stat buf;
        // fstat(fd, buf);
        // buf.st_size;
        // resize(buf.st_size);
        // for(size_ut i {0}; i < buf.st_size; ++i) {
        //     fgetc(buf)
        // }

        // clear();
        fseek(&f, 0, SEEK_END);
        size_ut size = ftell(&f);
        fseek(&f, 0, SEEK_SET);
        resize(size + 1);
        fread(this->m_data, 1, size, &f);
        m_data[size] = '\0';
        // TODO: do this, like in std::stringstream: parse and get chars from the whole file.
        return *this;
    }
    /* bool operator==(const String& array) const {
        return !strcmp(this->m_data, array.m_data);
    } */
    String operator+(const String &array) const {
        String arr{m_size + array.m_size};
        memcpy(arr.m_data, m_data, m_size);
        memcpy(arr.m_data + m_size, array.m_data, array.m_size);
        return arr;
    }
    String operator+(const char *array) const {
        String arr{m_size + strlen(array)};
        memcpy(arr.m_data, m_data, m_size);
        strcpy(arr.m_data + m_size, array);
        return arr;
    }
    String operator+(char ch) const {
        String arr{m_size + 1};
        memcpy(arr.m_data, m_data, m_size);
        arr.m_data[m_size] = ch;
        return arr;
    }
    friend String operator+(const char *array, const String &str) {
        // TODO: this
        String arr{str.m_size + strlen(array)};
        strcpy(arr.m_data, array);
        memcpy(arr.m_data + strlen(array), str.m_data, str.m_size);
        return arr;
    }
    friend String operator+(char ch, const String &str) {
        // TODO: this
        String arr{str.m_size + 1};
        *arr.m_data = ch;
        memcpy(arr.m_data + 1, str.m_data, str.m_size);
        return arr;
    }
    String &operator+=(const String &array) {
        size_ut old_size{m_size};
        resize(m_size + array.m_size);
        memcpy(m_data + old_size, array.m_data, array.m_size);
        return *this;
    }
    String &operator+=(const char *array) {
        size_ut old_size{m_size};
        resize(m_size + strlen(array));
        strcpy(m_data + old_size, array);
        return *this;
    }
    String &operator+=(char ch) {
        size_ut old_size{m_size};
        resize(m_size + 1);
        m_data[old_size] = ch;
        return *this;
    }
    String &operator=(const String &array) {
        resize(array.m_size);
        memcpy(m_data, array.m_data, array.m_size);
        return *this;
    }
    String &operator=(const char *array) {
        resize(strlen(array));
        strcpy(m_data, array);
        return *this;
    }
    String &operator=(char ch) {
        resize(1);
        m_data[0] = ch;
        return *this;
    }
    inline bool operator==(const String &arr) const {
        if (m_size != arr.m_size) return 0;
        return !(memcmp(m_data, arr.m_data, m_size));
    }
    inline bool operator!=(const String &arr) const {
        if (m_size != arr.m_size) return 1;
        return (memcmp(m_data, arr.m_data, m_size));
    }
    // inline bool operator==(const String& arr) const {
    //     if (m_size != arr.m_size)
    //         return 0;
    //     return !(memcmp(m_data, arr.m_data, m_size));
    // }
    // inline bool operator!=(const String& arr) const {
    //     if (m_size != arr.m_size)
    //         return 1;
    //     return (memcmp(m_data, arr.m_data, m_size));
    // }
    //   operator char*() const { return m_data; }
    int readChars(FILE *f, size_ut count) {
        resize(count);
        size_ut i{0};
        for (char *d{m_data}; i < count; ++i) {
            *(d++) = fgetc(f);
            if (*(d - 1) == EOF) return -1;
        }
        return 0;
    }
    friend class String_view;
};


// TODO: Change to Map from Array the [] operator and find functions using only
// TODO: and also make it a set (no duplicates of keys allowed on
// TODO: push_back/insert) the key
// template <class T1, class T2>
// // typedef int T1;
// // typedef int T2;
// class Map : public Array<Pair<T1, T2>> {
// public:
//     Map(Map<T1, T2>& map)
//         : Array<Pair<T1, T2>>(map)
//     {
//         std::cout << m_data;
//     }
//     //     : m_size{array.m_size},
//     //       m_allocated{array.m_allocated},
//     //       m_data{array.m_data},
//     //       m_is_sorted{false} {
//     //   array.m_data = NULL;
//     // }
//     Map(const Map<T1, T2>& map)
//         : Array<Pair<T1, T2>>(map)
//     {
//     }
//     //     : m_size{array.m_size},
//     //       m_allocated{array.m_allocated},
//     //       m_data{array.m_data},
//     //       m_is_sorted{false} {
//     //   memcpy(m_data, array.m_data, m_size * sizeof(T));
//     // }
//     Map(size_ut size)
//         : Array<Pair<T1, T2>>(size)
//     {
//     }
//     //   : m_size{size},
//     //     m_allocated{(size_ut)(m_size * 1.3 + 1)},
//     //     m_data{(T*)(malloc(sizeof(T) * m_allocated))},
//     //     m_is_sorted{false} {
//     // memset(m_data, 0, sizeof(T) * m_size);

//     Map()
//         : Array<Pair<T1, T2>>(0UL)
//     {
//     }
//     Map(const std::initializer_list<Pair<T1, T2>>& list)
//         : Array<Pair<T1, T2>>(list)
//     {
//     }
//     //     : m_size{list.size()},
//     //       m_allocated{(size_ut)(m_size * 1.3 + 1)},
//     //       m_data{(T*)(malloc(sizeof(T) * m_allocated))},
//     //       m_is_sorted{false} {
//     //   int j{0};
//     //   for (const T& i : list) {
//     //     m_data[j] = i;
//     //     ++j;
//     //   }
//     // }
//     virtual Array<Pair<T1, T2>>& sort() override
//     {
//         qsort(m_data, m_size, sizeof(Pair<T1, T2>), [](const void* a, const void* b) -> int {
//             return (*((T1*)(a))).first > (*((T1*)(b))).first;
//         });
//         return *this;
//     }

//     virtual size_ut find(const T1& target)
//     {
//         if (!m_is_sorted) {
//             sort();
//         }
//         return _find(target, 0, m_size - 1);
//     }

// protected:
//     virtual size_ut _find(const T1& target, size_ut left,
//         size_ut right)
//     {
//         _middle = (left + (right - left) / 2);
//         if (m_data[_middle].first == target)
//             return _middle;
//         else if (m_data[_middle].first > target)
//             return _find(target, left, _middle - 1);
//         else
//             return _find(target, _middle + 1, right);
//     }
//     size_ut index;

// public:
//     Map<T1, T2>& insert(const Pair<T1, T2>& pair)
//     {
//         if (find(pair.first) != m_size) {
//             fprintf(stderr, "Key already exists!\n");
//             throw "Key already exists!\n";
//         }
//         index = findGreater(pair.first);
//         memmove(index + 1, index, m_size - index + 1);
//         resize(m_size + 1);
//         // push_back(pair);
//         // sort();
//     }
//     Map<T1, T2>& remove(const T1& key)
//     {
//         index = find(key);
//         if (index == m_size) {
//             fprintf(stderr, "Key does not exist!\n");
//             throw "Key does not exist!\n";
//         }
//         memcpy(index, index + 1, m_size - index - 1);
//         resize(m_size - 1);
//     }
//     virtual T2& operator[](const T1& key) const
//     {
//         index = find(key);
//         if (index == m_size) {
//             fprintf(stderr, "Warning: Key does not exist!\n");
//             throw "Key does not exist!\n";
//         }
//         return m_data[index];
//     }
//     virtual Pair<T1, T2>& operator()(size_ut ind) const
//     {
//         return m_data[ind];
//         // index = find(ind);
//         // if (index == m_size) {
//         //     fprintf(stderr, "Warning: Key does not exist!\n");
//         //     throw "Key does not exist!\n";
//         // }
//         // return m_data[index];
//     }
// };

// typedef int T1;
// typedef int T2;
template<class T1, class T2>
class Map : public Array<Pair<T1, T2>> {
public:
    Map(Map &map) : Array<Pair<T1, T2>>(map), index{0} {
        // std::cout << m_data;
    }
    //     : m_size{array.m_size},
    //       m_allocated{array.m_allocated},
    //       m_data{array.m_data},
    //       m_is_sorted{false} {
    //   array.m_data = NULL;
    // }
    Map(const Map &map) : Array<Pair<T1, T2>>(map), index{0} {}
    //     : m_size{array.m_size},
    //       m_allocated{array.m_allocated},
    //       m_data{array.m_data},
    //       m_is_sorted{false} {
    //   memcpy(m_data, array.m_data, m_size * sizeof(T));
    // }
    Map(size_ut size) : Array<Pair<T1, T2>>(size), index{0} {}
    //   : m_size{size},
    //     m_allocated{(size_ut)(m_size * 1.3 + 1)},
    //     m_data{(T*)(malloc(sizeof(T) * m_allocated))},
    //     m_is_sorted{false} {
    // memset(m_data, 0, sizeof(T) * m_size);

    Map() : Array<Pair<T1, T2>>(0UL), index{0} {}
    Map(const std::initializer_list<Pair<T1, T2>> &list) : Array<Pair<T1, T2>>(list), index{0} {}
    //     : m_size{list.size()},
    //       m_allocated{(size_ut)(m_size * 1.3 + 1)},
    //       m_data{(T*)(malloc(sizeof(T) * m_allocated))},
    //       m_is_sorted{false} {
    //   int j{0};
    //   for (const T& i : list) {
    //     m_data[j] = i;
    //     ++j;
    //   }
    // }
    virtual Array<Pair<T1, T2>> &sort() override {
        qsort(this->m_data, this->m_size, sizeof(Pair<T1, T2>), [](const void *a, const void *b) -> int {
            return (*((Pair<T1, T2> *)(a))).first > (*((Pair<T1, T2> *)(b))).first;
        });
        return *this;
    }

    // virtual size_ut find(const T1& target)
    // {
    //     if (!m_size) {
    //         return 0UL;
    //     }
    //     if (!m_is_sorted) {
    //         sort();
    //     }
    //     return _find(target, 0, m_size - 1);
    // }

protected:
    // virtual size_ut _find(const T1& target, size_ut left,
    //     size_ut right)
    // {
    //     _middle = (left + (right - left) / 2);
    //     if (m_data[_middle].first == target)
    //         return _middle;
    //     else if (m_data[_middle].first > target)
    //         return _find(target, left, _middle - 1);
    //     else
    //         return _find(target, _middle + 1, right);
    // }
    size_ut index;

public:
    Map &insert(const Pair<T1, T2> &pair) {
        if (find(pair.first) != this->m_size) {
            fprintf(stderr, "Key already exists!\n");
            return *this;
            // throw "Key already exists!\n";
        }
        index = findGreater(pair.first);
        memmove(this->m_data + index + 1, this->m_data + index, this->m_size - index + 1);
        resize(this->m_size + 1);
        // push_back(pair);
        // sort();
    }
    Map &remove(const T1 &key) {
        index = find(key);
        if (index == this->m_size) {
            fprintf(stderr, "Key does not exist!\n");
            return *this;
            // throw "Key does not exist!\n";
        }
        memcpy(this->m_data + index, this->m_data + index + 1, this->m_size - index - 1);
        resize(this->m_size - 1);
    }
    virtual Pair<T1, T2> &operator[](T1 &&key) {
        index = this->find(key);
        if (index == this->m_size) {
            fprintf(stderr, "Warning: Key does not exist!\n");
            // return Pair<T1, T2>();
            throw "Key does not exist!\n";
        }
        return this->m_data[index];
    }
    virtual Pair<T1, T2> &operator()(size_ut ind) const {
        return this->m_data[ind];
        // index = find(ind);
        // if (index == this->m_size) {
        //     fprintf(stderr, "Warning: Key does not exist!\n");
        //     throw "Key does not exist!\n";
        // }
        // return this->m_data[index];
    }
    size_ut   findStartingWith(const T1 &key) { return this->findLesserEq(key) - this->findGreaterEq(key); }
    Array<T1> keys() const {
        Array<T1> keyArr(this->m_size);
        for (size_ut i{0}; i < this->m_size; ++i) { keyArr[i] = this->m_data[i].first; }
        return keyArr;
    }

    virtual size_ut find(const T1 &target) {
        if (!m_size) { return 0UL; }
        if (!m_is_sorted) { sort(); }
        return _find(target, 0, m_size - 1);
    }
    virtual size_ut findGreater(const T1 &target) {
        if (!m_size) { return 0UL; }
        if (!m_is_sorted) { sort(); }
        return _findg(target, 0, m_size - 1);
    }
    virtual size_ut findGreaterEq(const T1 &target) {
        if (!m_size) { return 0UL; }
        if (!m_is_sorted) { sort(); }
        return _findge(target, 0, m_size - 1);
    }
    virtual size_ut findLesser(const T1 &target) {
        if (!m_size) { return 0UL; }
        if (!m_is_sorted) { sort(); }
        return _findl(target, 0, m_size - 1);
    }
    virtual size_ut findLesserEq(const T1 &target) {
        if (!m_size) { return 0UL; }
        if (!m_is_sorted) { sort(); }
        return _findle(target, 0, m_size - 1);
    }


    virtual size_ut _find(const T1 &target, size_ut left, size_ut right) {
        if (right < left) return m_size;
        _middle = (left + (right - left) / 2);
        if (m_data[_middle].first == target)
            return _middle;
        else if (m_data[_middle].first > target)
            return _find(target, left, _middle - 1);
        else
            return _find(target, _middle + 1, right);
    }
    virtual size_ut _findg(const T1 &target, size_ut left, size_ut right) {
        if (right < left) return _middle;
        _middle = (left + (right - left) / 2);
        if (m_data[_middle].first == target)
            return _findg(target, _middle + 1, right);
        else if (m_data[_middle].first > target) {
            if (_middle == 0) { return _middle; }
            if (!(m_data[_middle - 1].first > target)) return _middle;
            return _findg(target, left, _middle - 1);
        }
        else
            return _findg(target, _middle + 1, right);
    }
    virtual size_ut _findl(const T1 &target, size_ut left, size_ut right) {
        if (right < left) return _middle;
        _middle = (left + (right - left) / 2);
        if (m_data[_middle].first == target)
            return _findl(target, _middle + 1, right);
        else if (m_data[_middle].first > target) {
            return _findl(target, left, _middle - 1);
        }
        else {
            if (_middle == m_size - 1) { return _middle; }
            if (!(m_data[_middle + 1].first < target)) return _middle;
            return _findl(target, _middle + 1, right);
        }
    }
    virtual size_ut _findge(const T1 &target, size_ut left, size_ut right) {
        if (right < left) return _middle;
        _middle = (left + (right - left) / 2);
        if (m_data[_middle].first == target) {
            if (_middle == m_size - 1) { return _middle; }
            return _findge(target, _middle + 1, right);
        }
        else if (m_data[_middle].first > target) {
            if (_middle == 0) { return _middle; }
            if (!(m_data[_middle - 1].first > target)) return _middle - 1;
            return _findge(target, left, _middle - 1);
        }
        else
            return _findge(target, _middle + 1, right);
    }
    virtual size_ut _findle(const T1 &target, size_ut left, size_ut right) {
        if (right < left) return _middle;
        _middle = (left + (right - left) / 2);
        if (m_data[_middle].first == target) {
            if (_middle == 0) { return _middle; }
            return _findle(target, _middle + 1, right);
        }
        else if (m_data[_middle].first > target) {
            return _findle(target, left, _middle - 1);
        }
        else {
            if (_middle == m_size - 1) { return _middle; }
            if (!(m_data[_middle + 1].first < target)) return _middle + 1;
            return _findle(target, _middle + 1, right);
        }
    }
};

inline bool isCharacter(char a) { return ((a <= 'Z') && (a >= 'A')) || ((a <= 'z') && (a >= 'a')); }

// void swap(size_ut& a, size_ut& b) {
//     size_ut& c = b;
//     b = a;
//     a = c;
// }

// void swap(bool& a, size_ut& b) {
//     size_ut& c = b;
//     b = a;
//     a = c;
// }

template<class T>
void swap(Array<T> &a, Array<T> b) {
    std::swap(a.m_allocated, b.m_allocated);
    std::swap(a.m_is_sorted, b.m_is_sorted);
    std::swap(a.m_size, b.m_size);
    std::swap(a._middle, b._middle);
    std::swap(a.m_data, b.m_data);
}

template<class T1, class T2>
void swap(Map<T1, T2> &a, Map<T1, T2> b) {
    std::swap(a.m_allocated, b.m_allocated);
    std::swap(a.m_is_sorted, b.m_is_sorted);
    std::swap(a.m_size, b.m_size);
    std::swap(a._middle, b._middle);
    std::swap(a.m_data, b.m_data);
    std::swap(a.index, b.index);
    // std::swap(a., b.index);


    // a.index
}

// bool isAlphanumeric(char c) { return ((c <= 'Z' && c >= 'A') || (c <= 'z' && c >= 'a') || (c <= '9' && c >=
// '0')); }
bool isAlnum(char c);
bool isAlphabet(char c);
bool isNumber(char c);

// bool
#endif
