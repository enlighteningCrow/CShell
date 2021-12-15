#include "misc.h"
#include <nlohmann/json.hpp>
#include "stdc++.h"

using namespace nlohmann;


template<class T>
long int findFirst(T* array, long first, long last, const std::function<short(T*, long)>& determinator) {
    if (first == last) {
        return -1;
    }
    switch (determinator(array, (first + last) / 2)) {
    case 1: {
        return findFirst<T>(array, first, (first + last) / 2, determinator);
        break;
    }
    case -1: {
        return findFirst<T>(array, (first + last) / 2, last, determinator);
        break;
    }
    case 0: {
        return ((first + last) / 2);
        break;
    }
    default: {
        return -1;
    }
    }
}

template<class T>
long int findFirst(
    const std::vector<T>& array, long first, long last,
    const std::function<short(const std::vector<T>&, long int)>& determinator) {
    if (first == last) {
        return -1;
    }
    switch (determinator(array, (first + last) / 2)) {
    case 1: {
        return findFirst<T>(array, first, (first + last) / 2, determinator);
        break;
    }
    case -1: {
        return findFirst<T>(array, (first + last) / 2, last, determinator);
        break;
    }
    case 0: {
        return ((first + last) / 2);
        break;
    }
    default: {
        return -1;
    }
    }
}
template<class T>
Pair<T, T>* makePairs(const std::initializer_list<std::initializer_list<T>>& list) {
    Pair<T, T>*                     temp{(Pair<T, T>*)malloc(sizeof(Pair<T, T>) * list.size())};
    int                             c{0};
    const std::initializer_list<T>* b{};
    for (const std::initializer_list<T>& i : list) {
        b              = &i;
        temp[c].first  = b->begin()[0];
        temp[c].second = b->begin()[1];
        ++c;
    }
    return temp;
}

template<>
Pair<long int, long int>* makePairs(const std::initializer_list<std::initializer_list<long int>>& list) {
    Pair<long int, long int>* temp{(Pair<long int, long int>*)malloc(sizeof(Pair<long int, long int>) * list.size())};
    int                       c{0};
    const std::initializer_list<long int>* b{};
    for (const std::initializer_list<long int>& i : list) {
        b              = &i;
        temp[c].first  = b->begin()[0];
        temp[c].second = b->begin()[1];
        ++c;
    }
    return temp;
}
