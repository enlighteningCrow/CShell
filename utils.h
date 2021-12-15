#ifndef UTILS_H
#define UTILS_H

#include "stdc++.h"

// using std::vector;
// using std::string;
// using std::map;

#include <cstddef>
#include <iterator>
#include <memory>
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


typedef char int1_t;


template<class T>
class Array_view;

class String_view;

class Exception : public std::exception {
    std::string message;

public:
    Exception(const char* m = "") : message{m} {
    }

    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};

template<class T>
class Array : public std::vector<T> {

protected:
    bool m_is_sorted;

public:
    using std::vector<T>::vector;

    Array(const Array_view<T>& arr) : Array<T>() {
        this->std::vector<T>::insert(end(), arr.arr().begin() + arr.start(), arr.arr().begin() + arr.end());
    }

    virtual void _print(std::ostream& out) const {
        out << ("{");
        for (int i{0}; i < this->size(); ++i) {
            if (i)
                out << (',');
            out << ' ' << this->data()[i];
        }
        out << (" }");
    }
    virtual void _print(FILE& out) const {
        out << ("{");
        for (int i{0}; i < this->size(); ++i) {
            if (i)
                out << (',');
            out << ' ' << this->data()[i];
        }
        out << (" }");
    }

    Array<T>& remove(size_ut start, size_ut end) {
        this->erase(this->begin() + start, this->begin() + end);
        return *this;
    }

    Array<T>& insert(const T& value, size_ut index) {
        this->std::vector<T>::insert(this->begin() + index, value);
        m_is_sorted = true;
        return *this;
    }

    Array<T>& replace(const T& value, size_ut start, size_ut end) {
        remove(start + 1, end);
        (*this)[start] = value;
        m_is_sorted    = true;
        return *this;
    }

    Array<T>& fill(const T& value, size_ut start, size_ut end) {
        for (size_ut i{start}; i < end; ++i) {
            (*this)[i] = value;
        }
        m_is_sorted = true;
        return *this;
    }
    Array<T> operator+(const Array<T>& array) const {
        Array<T> arr(this->size() + array.size());
        arr.std::vector<T>::insert(arr.end(), this->begin(), this->end());
        arr.std::vector<T>::insert(arr.end(), array.begin(), array.end());
        return arr;
    }
    Array<T>& operator+=(const Array<T>& array) {
        this->std::vector<T>::insert(this->end(), array.begin(), array.end());
        m_is_sorted = true;
        return *this;
    }
    friend std::ostream& operator<<(std::ostream& out, const Array<T>& arr) {
        arr._print(out);
        return out;
    }
    friend FILE& operator<<(FILE& out, const Array<T>& arr) {
        arr._print(out);
        return out;
    }

    Array<T>& clear() {
        this->std::vector<T>::resize(0);
        return *this;
    }
    explicit operator T*() const {
        return this->data();
    }
    T& operator[](size_ut index) {
        if (!size())
            throw Exception{"Out of range.\n"};
        if (index < 0) {
            if (size() == 1)
                index = 0;
            else {
                index = -index;
                index %= size();
                index = size() - index;
            }
        }
        else {
            index %= size();
        }
        return this->std::vector<T>::operator[](index);
    }
    const T& operator[](size_ut index) const {
        if (!size())
            throw Exception{"Out of range.\n"};
        if (index < 0) {
            if (size() == 1)
                index = 0;
            else {
                index = -index;
                index %= size();
                index = size() - index;
            }
        }
        else {
            index %= size();
        }
        return this->std::vector<T>::operator[](index);
    }
    virtual Array<T>& sort() {
        std::sort(this->begin(), this->end(), [](const T& a, const T& b) -> bool { return a < b; });
        m_is_sorted = true;
        return *this;
    }
    static void swap(Array<T>& a, Array<T>& b) {
        a.std::vector<T>::swap(b);
        std::swap(a.m_is_sorted, b.m_is_sorted);
    }


    virtual size_ut find(const T& target) {
        if (!this->size()) {
            return 0UL;
        }
        if (!m_is_sorted) {
            sort();
        }
        // Minus the return value by begin()
        return std::find(this->begin(), this->end(), target) - begin();
    }
    virtual size_ut findGreater(const T& target) {
        if (!this->size()) {
            return 0UL;
        }
        if (!m_is_sorted) {
            sort();
        }
        return std::upper_bound(this->begin(), this->end(), target) - begin();
    }
    virtual size_ut findGreaterEq(const T& target) {
        if (!this->size()) {
            return 0UL;
        }
        if (!m_is_sorted) {
            sort();
        }
        return std::lower_bound(this->begin(), this->end(), target) - this->begin();
    }
};

class String : public Array<char> {
protected:
    virtual void _print(std::ostream& out) const override {
        for (int i{0}; i < this->size(); ++i) {
            if (!this->data()[i])
                return;
            out << (data()[i]);
        }
        return;
    }
    virtual void _print(FILE& out) const override {
        for (int i{0}; i < this->size(); ++i) {
            if (!this->data()[i])
                return;
            out << (data()[i]);
        }
        return;
    }

public:
    using Array<char>::Array;
    String(const String& str) : Array<char>(str) {
    }
    String(const String_view& arr);
    String(const char* arr) : Array<char>() {
        std::stringstream ss{};
        ss << arr;
        const std::string& str{ss.str()};
        std::copy(str.begin(), str.end(), std::back_inserter(*this));
    }
    String(char arr) : Array<char>(2) {
        (*this)[0] = arr;
    }
    ~String() {
    }

    bool operator<(const String& array) const {
        return strcmp(this->data(), array.data()) < 0;
    }
    bool operator>(const String& array) const {
        return strcmp(this->data(), array.data()) > 0;
    }
    bool operator<=(const String& array) const {
        return strcmp(this->data(), array.data()) <= 0;
    }
    bool operator>=(const String& array) const {
        return strcmp(this->data(), array.data()) >= 0;
    }
    virtual size_ut find(const char* target) {
        size_ut str_size = strlen(target);
        for (size_ut i{0}; i <= this->size() - str_size; ++i) {
            for (size_ut j{0}; j < str_size; ++j) {
                if (target[j] == this->operator[](i + j))
                    continue;
                goto not_equal;
            }
            return i;
        not_equal:;
        }
        return this->size();
    }
    virtual size_ut find(const String& target) {
        size_ut str_size = target.size();
        for (size_ut i{0}; i <= this->size() - str_size; ++i) {
            for (size_ut j{0}; j < str_size; ++j) {
                if (target[j] == this->operator[](i + j))
                    continue;
                goto not_equal;
            }
            return i;
        not_equal:;
        }
        return this->size();
    }
    virtual size_ut find(String_view& target);
    String&         purge(size_ut start, size_ut end) {
        memset(data() + start, 0, end - start);
        return *this;
    }
    friend std::istream& operator>>(std::istream& in, String& str) {
        str.clear();
        char c;
        while (in.get(c)) {
            if (c == '\n')
                break;
            str.push_back(c);
        }
        return in;
    }
    String& operator<<(std::fstream& f) {
        std::stringstream ss;
        ss << f.rdbuf();
        std::string str{ss.str()};
        resize(str.size() + 1);
        memcpy(data(), str.c_str(), str.size());
        this->data()[str.size()] = '\n';
        return *this;
    }
    String& operator<<(FILE& f) {
        fseek(&f, 0, SEEK_END);
        size_ut size = ftell(&f);
        fseek(&f, 0, SEEK_SET);
        resize(size + 1);
        fread(this->data(), 1, size, &f);
        this->data()[size] = '\0';
        return *this;
    }
    friend std::ostream& operator<<(std::ostream& out, const String& str) {
        str._print(out);
        return out;
    }
    friend FILE& operator<<(FILE& out, const String& str) {
        str._print(out);
        return out;
    }

    bool operator==(const String& str) const {
        return this->toStdString() == str.toStdString();
    }
    bool operator!=(const String& str) const {
        return this->toStdString() != str.toStdString();
    }
    String operator+(const String& array) const {
        String arr(*this);
        arr.std::vector<char>::insert(arr.end(), array.begin(), array.end());
        return arr;
    }
    String operator+(const char* array) const {
        String arr(*this);
        String arr2(array);
        return arr + arr2;
    }
    String operator+(char ch) const {
        String arr(*this);
        String arr2(ch);
        return arr + arr2;
    }
    friend String operator+(const char* array, const String& str) {
        String arr(array);
        return arr + str;
    }
    friend String operator+(char ch, const String& str) {
        return String(ch) + str;
    }
    String& operator+=(const String& array) {
        this->std::vector<char>::insert(end(), array.begin(), array.end());
        return *this;
    }
    String& operator+=(const char* array) {
        (*this) += String(array);
        return *this;
    }
    String& operator+=(char ch) {
        (*this) += String(ch);
        return *this;
    }
    String& operator=(const String& array) {
        this->Array<char>::operator=(array);
        return *this;
    }
    String& operator=(const char* array) {
        (*this) = String(array);
        return *this;
    }
    String& operator=(char ch) {
        (*this) = String(ch);
        return *this;
    }
    int readChars(FILE* f, size_ut count) {
        resize(count);
        size_ut i{0};
        for (char* d{this->data()}; i < count; ++i) {
            *(d++) = fgetc(f);
            if (*(d - 1) == EOF)
                return -1;
        }
        return 0;
    }
    std::unique_ptr<char> cStr() const {
        char* a{new char[this->size() + 1]};
        memcpy(a, this->data(), this->size());
        a[this->size()] = 0;
        return std::unique_ptr<char>(a);
    }
    friend class String_view;
    std::string toStdString() const {
        return std::string(begin(), end());
    }
};


template<class T1, class T2>
class Map : public Array<Pair<T1, T2>> {
public:
    Map(Map& map) : Array<Pair<T1, T2>>(map), index{0} {
    }
    Map(const Map& map) : Array<Pair<T1, T2>>(map), index{0} {
    }
    Map(size_ut size) : Array<Pair<T1, T2>>(size), index{0} {
    }
    Map() : Array<Pair<T1, T2>>(0UL), index{0} {
    }
    Map(const std::initializer_list<Pair<T1, T2>>& list) : Array<Pair<T1, T2>>(list), index{0} {
    }
    virtual Array<Pair<T1, T2>>& sort() override {
        qsort(this->data(), this->size(), sizeof(Pair<T1, T2>), [](const void* a, const void* b) -> int {
            return (*((Pair<T1, T2>*)(a))).first > (*((Pair<T1, T2>*)(b))).first;
        });
        return *this;
    }

protected:
    size_ut index;

public:
    Map& insert(const Pair<T1, T2>& pair) {
        if (find(pair.first) != this->size()) {
            fprintf(stderr, "Key already exists!\n");
            return *this;
        }
        index = findGreater(pair.first);
        this->Array<Pair<T1, T2>>::insert(pair, index);
        return *this;
    }
    Map& remove(const T1& key) {
        index = find(key);
        if (index == this->size()) {
            fprintf(stderr, "Key does not exist!\n");
            return *this;
        }
        this->Array<Pair<T1, T2>>::remove(index, index + 1);
        return *this;
    }
    virtual Pair<T1, T2>& operator[](T1&& key) {
        index = this->find(key);
        if (index == this->size()) {
            fprintf(stderr, "Warning: Key does not exist!\n");
            throw "Key does not exist!\n";
        }
        return this->data()[index];
    }
    virtual Pair<T1, T2>& operator()(size_ut ind) {
        if (ind >= this->size()) {
            fprintf(stderr, "Warning: Index out of bounds!\n");
            throw "Index out of bounds!\n";
        }
        return this->data()[ind];
    }
    size_ut findStartingWith(const T1& key) {
        return this->findLesserEq(key) - this->findGreaterEq(key);
    }
    Array<T1> keys() const {
        Array<T1> keyArr(this->size());
        for (size_ut i{0}; i < this->size(); ++i) {
            keyArr[i] = this->data()[i].first;
        }
        return keyArr;
    }

    virtual size_ut find(const T1& target) {
        if (!this->size()) {
            return 0UL;
        }
        if (!this->m_is_sorted) {
            sort();
        }
        return std::find_if(
                   begin(), end(), [&target](const Pair<T1, T2>& pair) -> bool { return pair.first == target; }) -
            begin();
    }
    virtual size_ut findGreater(const T1& target) {
        if (!this->size()) {
            return 0UL;
        }
        if (!this->m_is_sorted) {
            sort();
        }
        return std::upper_bound(
                   begin(), end(), target,
                   [](const T1& target, const Pair<T1, T2>& pair) -> bool { return target < pair.first; }) -
            begin();
    }
    virtual size_ut findGreaterEq(const T1& target) {
        if (!this->size()) {
            return 0UL;
        }
        if (!this->m_is_sorted) {
            sort();
        }
        return std::lower_bound(
                   begin(), end(), target,
                   [](const Pair<T1, T2>& pair, const T1& target) -> bool { return target < pair.first; }) -
            begin();
    }
    static void swap(Map<T1, T2>& a, Map<T1, T2>& b) {
        Array<Pair<T1, T2>>::swap(a, b);
        std::swap(a.index, b.index);
    }
};


inline bool isCharacter(char a) {
    return ((a <= 'Z') && (a >= 'A')) || ((a <= 'z') && (a >= 'a'));
}


bool isAlnum(char c);
bool isAlphabet(char c);
bool isNumber(char c);


#endif// UTILS_H