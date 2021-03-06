#ifndef MISC_H
#define MISC_H

#include <nlohmann/json.hpp>
#include "stdc++.h"

#include "file_io.h"

using namespace nlohmann;

template<class T1, class T2>
class Pair : public std::pair<T1, T2> {
public:
    using std::pair<T1, T2>::pair;
    bool operator==(const Pair<T1, T2>& pair) const {
        return (this->first != pair.first ? 0 : (this->second != pair.second ? 0 : 1));
    }
    bool operator!=(const Pair<T1, T2>& pair) const {
        return (this->first != pair.first ? 1 : (this->second != pair.second ? 1 : 0));
    }
    bool operator<(const Pair<T1, T2>& pair) const {
        return (
            this->first < pair.first
                ? 1
                : (this->first > pair.first ? 0
                                            : (this->second < pair.second ? 1 : (this->second > pair.second ? 0 : 0))));
    }
    bool operator<=(const Pair<T1, T2>& pair) const {
        return (
            this->first < pair.first
                ? 1
                : (this->first > pair.first ? 0
                                            : (this->second < pair.second ? 1 : (this->second > pair.second ? 0 : 1))));
    }
    bool operator>(const Pair<T1, T2>& pair) const {
        return (
            this->first < pair.first
                ? 0
                : (this->first > pair.first ? 1
                                            : (this->second < pair.second ? 0 : (this->second > pair.second ? 1 : 0))));
    }
    bool operator>=(const Pair<T1, T2>& pair) const {
        return (
            this->first < pair.first
                ? 0
                : (this->first > pair.first ? 1
                                            : (this->second < pair.second ? 0 : (this->second > pair.second ? 1 : 1))));
    }
    bool operator!() const {
        return !this->first;
    }

    static void swap(Pair<T1, T2>& a, Pair<T1, T2>& b) {
        Pair<T1, T2> c(a);
        a = b;
        b = c;
    }
};


template<class T>
long int findFirst(
    const std::vector<T>& array, long int first, long int last,
    const std::function<short int(const std::vector<T>&, long int)>& determinator);

template<class T>
Pair<T, T>* makePairs(const std::initializer_list<std::initializer_list<T>>&);

template<class T>
std::ostream& operator<<(std::ostream& out, std::shared_ptr<T> ptr) {
    out << *ptr;
    return out;
}

template<class T>
FILE& operator<<(FILE& out, std::shared_ptr<T> ptr) {
    out << *ptr;
    return out;
}

template<class T1, class T2>
std::ostream& operator<<(std::ostream& out, const Pair<T1, T2>& pair) {
    out << "( " << pair.first << ", " << pair.second << " )";
    return out;
}

template<class T1, class T2>
FILE& operator<<(FILE& out, const Pair<T1, T2>& pair) {
    out << "( " << pair.first << ", " << pair.second << " )";
    return out;
}

#endif
