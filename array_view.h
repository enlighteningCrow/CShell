#ifndef ARRAY_VIEW_H
#define ARRAY_VIEW_H

#include "file_io.h"
#include "utils.h"

template<class T>
class Array_view {
protected:
    Array<T>&   m_arr;
    std::size_t m_start, m_end;

public:
    Array_view(Array<T>& arr) : m_arr{arr}, m_start{0}, m_end{arr.size()} {
    }
    Array_view(Array<T>& arr, std::size_t start) : m_arr{arr}, m_start{start}, m_end{arr.size()} {
    }
    Array_view(Array<T>& arr, std::size_t start, std::size_t end) : m_arr{arr}, m_start{start}, m_end{end} {
    }
    Array_view(const Array_view<T>& arr) :
        m_arr{arr.m_arr}, m_start{arr.m_start}, m_end{arr.m_end /* arr.size() - 1 */} {
    }
    Array_view(const Array_view<T>& arr, std::size_t start) :
        m_arr{arr.m_arr}, m_start{arr.m_start + start}, m_end{arr.m_end /* arr.size() - 1 */} {
    }
    Array_view(const Array_view<T>& arr, std::size_t start, std::size_t end) :
        m_arr{arr.m_arr}, m_start{arr.m_start + start}, m_end{arr.m_start + end /* arr.size() - 1 */} {
    }
    std::size_t size() const {
        return m_end - m_start;
    }
    std::size_t start() const {
        return m_start;
    }
    std::size_t end() const {
        return m_end;
    }
    Array_view<T>& setView(std::size_t start, std::size_t end) {
        m_start = start;
        m_end   = end;
        return *this;
    }
    Array_view<T>& setViewStart(std::size_t start) {
        m_start = start;
        return *this;
    }
    Array_view<T>& setViewStart() {
        m_start = 0;
        return *this;
    }
    Array_view<T>& setViewEnd(std::size_t end) {
        m_end = end;
        return *this;
    }
    Array_view<T>& setViewEnd() {
        m_end = arr().size();
        return *this;
    }
    Array_view<T>& truncFront(std::size_t size) {
        setViewStart(m_start + size);
        return *this;
    }
    Array_view<T>& truncFrontIgnore(std::size_t size, const T& ignore) {
        std::size_t counter{0};
        for (std::size_t i{m_start}; (i < this->size()) && (counter <= size); ++i)
            counter += ignore != (*this)[i];
        setViewStart(m_start + counter - 1);
        return *this;
    }
    Array_view<T>& truncBack(std::size_t size) {
        setViewEnd(m_end - size);
        return *this;
    }
    Array_view<T>& extendFront(std::size_t size) {
        if (size <= m_start)
            setViewStart(m_start - size);
        else
            *stderr << "Out of range";
        return *this;
    }
    Array_view<T>& extendBack(std::size_t size) {
        if ((size + m_end) <= m_arr.size())
            setViewEnd(m_end + size);
        else
            *stderr << "Out of range";
        return *this;
    }
    T& operator[](std::size_t index) const {
        if (index > size())
            *stderr << "Out of range";
        return m_arr[index + m_start];
    }
    Array<T>& arr() const {
        return this->m_arr;
    }

    virtual void _print(FILE& out) const {
        for (int i{0}; i < size(); ++i) {
            // if (!(operator[](i)))
            //     return;
            out << (operator[](i));
        }
        return;
    }

    friend FILE& operator<<(FILE& out, const Array_view<T>& arr) {
        arr._print(out);
        return out;
    }

    virtual void _print(std::ostream& out) const {
        for (int i{0}; i < size(); ++i) {
            // if (!(operator[](i)))
            //     return;
            out << (operator[](i));
        }
        return;
    }

    friend std::ostream& operator<<(std::ostream& out, const Array_view<T>& arr) {
        arr._print(out);
        return out;
    }

    Array<T> cutIgnored(const T& ignore) {
        Array<T> arr{};
        for (std::size_t i{m_start}; i < m_end; ++i) {
            if (m_arr[i] == ignore)
                continue;
            arr.push_back(m_arr[i]);
        }
        return arr;
    }
};

// class String;

// template<>
class String_view : Array_view<char> {
protected:
    // String &    m_arr;
    // std::size_t m_start, m_end;
    String& m_str;

public:
    // String_view(String &arr) : m_arr{arr}, m_start{0}, m_end{arr.size()} {}
    String_view(String& arr) : Array_view{arr}, m_str{arr} {
    }
    // String_view(String_view &arr) : m_arr{arr.m_arr}, m_start{arr.m_start}, m_end{arr.m_end /* arr.size() - 1 */} {}
    String_view(const String_view& arr) : Array_view{arr}, m_str{arr.m_str} {
    }
    std::size_t size() const {
        return m_end - m_start;
    }
    std::size_t start() const {
        return m_start;
    }
    std::size_t end() const {
        return m_end;
    }

    std::size_t find(const String& target) {
        std::size_t str_size = target.size();
        for (std::size_t i{0}; i <= this->size() - str_size; ++i) {
            for (std::size_t j{0}; j < str_size; ++j) {
                if (target[j] == this->operator[](i + j))
                    continue;
                goto not_equal;
                // break;
                // for (const char* ptr{})
            }
            return i;
        not_equal:;
        }
        return size();
    }
    friend FILE& operator<<(FILE& out, const String_view& arr) {
        arr._print(out);
        return out;
    }
    virtual void _print(FILE& out) const override {
        for (int i{0}; i < size(); ++i) {
            if (!(operator[](i)))
                return;
            out << (operator[](i));
        }
        return;
    }
    friend std::ostream& operator<<(std::ostream& out, const String_view& arr) {
        arr._print(out);
        return out;
    }
    virtual void _print(std::ostream& out) const override {
        for (int i{0}; i < size(); ++i) {
            if (!(operator[](i)))
                return;
            out << (operator[](i));
        }
        return;
    }

    bool match_starting(String& target) const {
        // target.size();
        // // target.size();
        // size();
        if (target.size() < size())
            return false;
        if (!size())
            return true;
        return !(memcmp(&(operator[](0)), &(target.data()[0]), size()));
    }

    String_view& setView(std::size_t start, std::size_t end) {
        m_start = start;
        m_end   = end;
        return *this;
    }
    String_view& setViewStart(std::size_t start) {
        m_start = start;
        return *this;
    }
    String_view& setViewEnd(std::size_t end) {
        m_end = end;
        return *this;
    }
    String_view& truncFront(std::size_t size) {
        setViewStart(m_start + size);
        return *this;
    }
    String_view& truncBack(std::size_t size) {
        setViewEnd(m_end - size);
        return *this;
    }
    String_view& extendFront(std::size_t size) {
        if (size <= m_start)
            setViewStart(m_start - size);
        else
            *stderr << "Out of range";
        return *this;
    }
    String_view& extendBack(std::size_t size) {
        if ((size + m_end) <= m_str.size())
            setViewEnd(m_end + size);
        else
            *stderr << "Out of range";
        return *this;
    }
    // char &operator[](std::size_t index) const {
    //     if (index >= size()) *stderr << "Out of range";
    //     return m_str[index + m_start];
    // }
    char& operator[](size_ut index) const {
        if (!size())
            throw Exception{"Out of range.\n"};
        // if (index >= size()) *stderr << "Out of range";
        index %= size();
        if (index < 0)
            index += size();
        return m_str[index + m_start];
    }
    String& arr() const {
        return dynamic_cast<String&>(this->m_str);
    }

    // bool operator<(const String& array) const {
    //     return strcmp(this->data() , array.data() ) < 0;
    // }
    // bool operator>(const String& array) const {
    //     return strcmp(this->data() , array.data() ) > 0;
    // }
    // bool operator<=(const String& array) const {
    //     return strcmp(this->data() , array.data() ) <= 0;
    // }
    // bool operator>=(const String& array) const {
    //     return strcmp(this->data() , array.data() ) >= 0;
    // }

    // inline bool operator==(const String& arr) const {
    //     if (size() != arr.size()) return 0;
    //     return !(memcmp(data() , arr.data() , size()));
    // }
    inline bool operator!=(const String& arr) const {
        if ((m_end - m_start) != arr.size())
            return 1;
        return (memcmp(m_str.data(), arr.data(), arr.size()));
    }
    inline bool operator==(const String& arr) const {
        if ((m_end - m_start) != arr.size())
            return 0;
        return !(memcmp(m_str.data(), arr.data(), arr.size()));
    }
    inline bool operator<(const String& arr) const {
        if ((m_end - m_start) < arr.size())
            return 1;
        if ((m_end - m_start) > arr.size())
            return 0;
        return memcmp(m_str.data(), arr.data(), arr.size()) < 0;
    }
    inline bool operator>(const String& arr) const {
        if ((m_end - m_start) < arr.size())
            return 0;
        if ((m_end - m_start) > arr.size())
            return 1;
        return memcmp(m_str.data(), arr.data(), arr.size()) > 0;
    }
    inline bool operator<=(const String& arr) const {
        if ((m_end - m_start) < arr.size())
            return 1;
        if ((m_end - m_start) > arr.size())
            return 0;
        return memcmp(m_str.data(), arr.data(), arr.size()) <= 0;
    }
    inline bool operator>=(const String& arr) const {
        if ((m_end - m_start) < arr.size())
            return 0;
        if ((m_end - m_start) > arr.size())
            return 1;
        return memcmp(m_str.data(), arr.data(), arr.size()) >= 0;
    }
    String str() const {
        return String(*this);
    }
};

#endif