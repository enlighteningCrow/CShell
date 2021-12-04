#include "misc.h"
#include <bits/stdc++.h>
#include <nlohmann/json.hpp>

// #include "piece.h"

// using nm = nlohmann;
using namespace nlohmann;


// template <class T>
// bool operator==(const Vector<T>&& vectorA, const Vector<T>&& vectorB) {
//	return ((vectorA.m_x == vectorB.m_x) && (vectorA.m_y == vectorB.m_y) && (vectorA.m_z == vectorB.m_z));
//}
//
// template <class T>
// bool Vector<T>::operator==(Vector<T> vectorA) {
//	return ((m_x == vectorA.m_x) && (m_y == vectorA.m_y) && (m_z == vectorA.m_z));
//}
//
// template <class T>
// bool Vector<T>::operator==(const Vector<T>&& vectorA) {
//	return ((m_x == vectorA.m_x) && (m_y == vectorA.m_y) && (m_z == vectorA.m_z));
//}
//
// template <class T>
// bool Vector<T>::operator<(const Vector<T>& vectorA) {
//	return ((m_x < vectorA.m_x) || (m_y < vectorA.m_y) || (m_z < vectorA.m_z));
//}
//
// template <class T>
// bool Vector<T>::operator>(const Vector<T>& vectorA) {
//	return ((m_x > vectorA.m_x) || (m_y > vectorA.m_y) || (m_z > vectorA.m_z));
//}
//
// template <class T>
// bool Vector<T>::operator<=(const Vector<T>& vectorA) {
//	return ((m_x <= vectorA.m_x) || (m_y <= vectorA.m_y) || (m_z <= vectorA.m_z));
//}
//
// template <class T>
// bool Vector<T>::operator>=(const Vector<T>& vectorA) {
//	return ((m_x >= vectorA.m_x) || (m_y >= vectorA.m_y) || (m_z >= vectorA.m_z));
//}
//
// template <class T>
// bool Vector<T>::operator==(Vector<T> vectorA) const {
//	return ((m_x == vectorA.m_x) && (m_y == vectorA.m_y) && (m_z == vectorA.m_z));
//}


/*
template<class T1, class T2>
Pair<T1, T2>::Pair() : first{}, second{} {}

template<class T1, class T2>
Pair<T1, T2>::Pair(const T1& arg_first) : first{ arg_first }, second{} {}

template<class T1, class T2>
Pair<T1, T2>::Pair(const T1& arg_first, const T2& arg_second) : first{ arg_first }, second{ arg_second } {}

template <class T1, class T2>
Pair<T1, T2>::Pair(const std::pair<T1, T2>& list) : first{ list.size() > 0 ? list.begin()[0] : T1{} }, second{
list.size() > 1 ? list.begin()[1] : T2{} } {}

template <class T>
Vector<T>::Vector(T arg_x, T arg_y, T arg_z) : m_x{ arg_x }, m_y{ arg_y }, m_z{ arg_z } {}

template <class T>
const Vector<T>& Vector<T>::operator+(const Vector<T>& vector) const {
    return Vector<T>{
        this->m_x + vector.m_x,
            this->m_y + vector.m_y,
            this->m_z + vector.m_z
    };
}

template <class T>
const Vector<T>& Vector<T>::operator-(const Vector<T>& vector) const {
    return Vector<T>{
        this->m_x - vector.m_x,
            this->m_y - vector.m_y,
            this->m_z - vector.m_z
    };
}

template <class T>
const Vector<T>& Vector<T>::operator*(const Vector<T>& vector) const {
    return Vector<T>{
        this->m_x* vector.m_x,
            this->m_y* vector.m_y,
            this->m_z* vector.m_z
    };
}

template <class T>
const Vector<T>& Vector<T>::operator/(const Vector<T>& vector) const {
    return Vector<T>{
        this->m_x / vector.m_x,
            this->m_y / vector.m_y,
            this->m_z / vector.m_z
    };
}

template <class T>
Vector<T>& Vector<T>::operator+=(const Vector<T>& vector) {
    this->m_x += vector.m_x;
    this->m_y += vector.m_y;
    this->m_z += vector.m_z;
    return (*this);
}

template <class T>
Vector<T>& Vector<T>::operator-=(const Vector<T>& vector) {
    this->m_x -= vector.m_x;
    this->m_y -= vector.m_y;
    this->m_z -= vector.m_z;
    return (*this);
}

template <class T>
Vector<T>& Vector<T>::operator*=(const Vector<T>& vector) {
    this->m_x *= vector.m_x;
    this->m_y *= vector.m_y;
    this->m_z *= vector.m_z;
    return (*this);
}

template <class T>
Vector<T>& Vector<T>::operator/=(const Vector<T>& vector) {
    this->m_x /= vector.m_x;
    this->m_y /= vector.m_y;
    this->m_z /= vector.m_z;
    return (*this);
}

template <class T>
Vector<T>&& Vector<T>::operator+(long int number) const {
    return Vector<T>{
        this->m_x + number,
            this->m_y + number,
            this->m_z + number
    };
}

template <class T>
Vector<T>&& Vector<T>::operator-(long int number) const {
    return Vector<T>{
        this->m_x - number,
            this->m_y - number,
            this->m_z - number
    };
}

template <class T>
Vector<T>&& Vector<T>::operator*(long int number) const {
    return Vector<T>{
        this->m_x* number,
            this->m_y* number,
            this->m_z* number
    };
}

template <class T>
Vector<T>&& Vector<T>::operator/(long int number) const {
    return Vector<T>{
        this->m_x / number,
            this->m_y / number,
            this->m_z / number
    };
}

template <class T>
Vector<T>& Vector<T>::operator+=(long int number) {
    this->m_x += number;
    this->m_y += number;
    this->m_z += number;
    return (*this);
}

template <class T>
Vector<T>& Vector<T>::operator-=(long int number) {
    this->m_x -= number;
    this->m_y -= number;
    this->m_z -= number;
    return (*this);
}

template <class T>
Vector<T>& Vector<T>::operator*=(long int number) {
    this->m_x *= number;
    this->m_y *= number;
    this->m_z *= number;
    return (*this);
}

template <class T>
Vector<T>& Vector<T>::operator/=(long int number) {
    this->m_x /= number;
    this->m_y /= number;
    this->m_z /= number;
    return (*this);
}

template <class T>
bool Vector<T>::operator==(const Vector<T>& vectorA) const {
    return ((m_x == vectorA.m_x) && (m_y == vectorA.m_y) && (m_z == vectorA.m_z));
    //return ((m_x == vectorA.m_x) && (m_y == vectorA.m_y) && (m_z == vectorA.m_z));
}

template <class T>
bool Vector<T>::operator<(const Vector<T>& vectorA) const {
    return (m_x == vectorA.m_x ? (m_y == vectorA.m_y ? (m_z == vectorA.m_z ? false : m_z < vectorA.m_z) : m_y <
vectorA.m_y) : m_x < vectorA.m_x);
    //return ((m_x < vectorA.m_x) || (m_y < vectorA.m_y) || (m_z < vectorA.m_z));
}

template <class T>
bool Vector<T>::operator>(const Vector<T>& vectorA) const {
    return (m_x == vectorA.m_x ? (m_y == vectorA.m_y ? (m_z == vectorA.m_z ? false : m_z > vectorA.m_z) : m_y >
vectorA.m_y) : m_x > vectorA.m_x);
    //return ((m_x > vectorA.m_x) || (m_y > vectorA.m_y) || (m_z > vectorA.m_z));
}

template <class T>
bool Vector<T>::operator<=(const Vector<T>& vectorA) const {
    return (m_x == vectorA.m_x ? (m_y == vectorA.m_y ? (m_z == vectorA.m_z ? true : m_z < vectorA.m_z) : m_y <
vectorA.m_y) : m_x < vectorA.m_x);
    //return ((m_x <= vectorA.m_x) || (m_y <= vectorA.m_y) || (m_z <= vectorA.m_z));
}

template <class T>
bool Vector<T>::operator>=(const Vector<T>& vectorA) const {
    return (m_x == vectorA.m_x ? (m_y == vectorA.m_y ? (m_z == vectorA.m_z ? true : m_z > vectorA.m_z) : m_y >
vectorA.m_y) : m_x > vectorA.m_x);
    //return ((m_x >= vectorA.m_x) || (m_y >= vectorA.m_y) || (m_z >= vectorA.m_z));
}

template <class T>
bool Vector<T>::inside(const Vector<T>& vector_a, const Vector<T>& vector_b) const {
    return !(((m_x < vector_a.m_x) || (m_y < vector_a.m_y) || (m_z < vector_a.m_z))
        || ((m_x > vector_b.m_x) || (m_y > vector_b.m_y) || (m_z > vector_b.m_z)));
}

template <class T>
T Vector<T>::volume() {
    return (this->m_x * this->m_y * this->m_z);
}

template <class T>
T& Vector<T>::x() const {
    return m_x;
}

template <class T>
T& Vector<T>::y() const {
    return m_y;
}

template <class T>
T& Vector<T>::z() const {
    return m_z;
}*/

template<class T>
long int findFirst(
    T *array, long first, long last,
    const std::function<short(T *, long)> &determinator) { // short int(*determinator)) {
    // return (((first + last) / 2) ==  - 1)findFirst()
    if (first == last) { return -1; }
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
/* template<>
long int findFirst(
    Piece *array, long first, long last,
    const std::function<short(Piece *, long)> &determinator) { // short int(*determinator)) {
    // return (((first + last) / 2) ==  - 1)findFirst()
    if (first == last) { return -1; }
    switch (determinator(array, (first + last) / 2)) {
    case 1: {
        return findFirst<Piece>(array, first, (first + last) / 2, determinator);
        break;
    }
    case -1: {
        return findFirst<Piece>(array, (first + last) / 2, last, determinator);
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
template<>
long int findFirst(
    Vector<long int> *array, long first, long last,
    const std::function<short(Vector<long int> *, long)> &determinator) { // short int(*determinator)) {
    // return (((first + last) / 2) ==  - 1)findFirst()
    if (first == last) { return -1; }
    switch (determinator(array, (first + last) / 2)) {
    case 1: {
        return findFirst<Vector<long int>>(array, first, (first + last) / 2, determinator);
        break;
    }
    case -1: {
        return findFirst<Vector<long int>>(array, (first + last) / 2, last, determinator);
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
} */

// findFirst(array, )
//	if (!determinator(array, (first + last) / 2)) {
//		return ((first + last) / 2);
//	}
// if (determinator(array, (first + last) / 2) == 1) {
//	return findFirst(array, first, (first + last) / 2);
//}
// return

template<class T>
long int findFirst(
    const std::vector<T> &array, long first, long last,
    const std::function<short(const std::vector<T> &, long int)> &determinator) { // short int(*determinator)) {
    // return (((first + last) / 2) ==  - 1)findFirst()
    if (first == last) { return -1; }
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
// template<>
// long int findFirst(
//     const std::vector<Vector<long int>> &array, long first, long last,
//     const std::function<short(const std::vector<Vector<long int>> &, long int)>
//         &determinator) { // short int(*determinator)) {
//     // return (((first + last) / 2) ==  - 1)findFirst()
//     if (first == last) { return -1; }
//     switch (determinator(array, (first + last) / 2)) {
//     case 1: {
//         return findFirst<Vector<long int>>(array, first, (first + last) / 2, determinator);
//         break;
//     }
//     case -1: {
//         return findFirst<Vector<long int>>(array, (first + last) / 2, last, determinator);
//         break;
//     }
//     case 0: {
//         return ((first + last) / 2);
//         break;
//     }
//     default: {
//         return -1;
//     }
//     }
// }

// findFirst(array, )
//	if (!determinator(array, (first + last) / 2)) {
//		return ((first + last) / 2);
//	}
// if (determinator(array, (first + last) / 2) == 1) {
//	return findFirst(array, first, (first + last) / 2);
//}
// return

// template <class T>
// Pair<T, T>* makePairs(const std::initializer_list<std::initializer_list<T>>& list) {
//	Pair<T, T>* temp{ (Pair<T, T>*)malloc(sizeof(Pair<T, T>) * list.size()) };
//	int c{ 0 };
//	const std::initializer_list<T>::iterator* b{ nullptr };
//	for (const std::initializer_list<T>& i : list) {
//		b = &i;
//		temp[c].first = (*b)[0];
//		temp[c].second = (*b)[1];
//		++c;
//	}
//	return temp;
//}
template<class T>
Pair<T, T> *makePairs(const std::initializer_list<std::initializer_list<T>> &list) {
    Pair<T, T> *                    temp{(Pair<T, T> *)malloc(sizeof(Pair<T, T>) * list.size())};
    int                             c{0};
    const std::initializer_list<T> *b{};
    // std::initializer_list<T>::iterator* c{ nullptr };
    for (const std::initializer_list<T> &i : list) {
        b              = &i;
        temp[c].first  = b->begin()[0];
        temp[c].second = b->begin()[1];
        ++c;
    }
    return temp;
}

template<>
Pair<long int, long int> *makePairs(const std::initializer_list<std::initializer_list<long int>> &list) {
    Pair<long int, long int> *temp{(Pair<long int, long int> *)malloc(sizeof(Pair<long int, long int>) * list.size())};
    int                       c{0};
    const std::initializer_list<long int> *b{};
    // std::initializer_list<long int>::iterator* c{ nullptr };
    for (const std::initializer_list<long int> &i : list) {
        b              = &i;
        temp[c].first  = b->begin()[0];
        temp[c].second = b->begin()[1];
        ++c;
    }
    return temp;
}


//
// template <class T>
// Pair<T, T>* makePairs(int num, ...) {
//	////if (num % 2) return nullptr;
//	//Pair<T, T>* temp{ (Pair<T, T>)malloc(sizeof(Pair<T, T>) * num) };
//	//const std::initializer_list<T>::iterator* b{ nullptr };
//	//va_list list;
//	//va_start(list, num);
//	//for(int i{0}; i < num; ++i){
//	//	b = &((va_arg(list, std::initializer_list<T>)).begin());
//	//	temp[i].first = (*b)[0];
//	//	temp[i].second = (*b)[1];
//	//}
//	//va_end(list);
//	//return temp;
//
//
//
//
//	//if (num % 2) return nullptr;
//	Pair<T, T>* temp{ (Pair<T, T>)malloc(sizeof(Pair<T, T>) * num) };
//	va_list list;
//	va_start(list, num);
//	for(int i{0}; i < num; ++i){
//		temp[i].first = va_arg(list, T);
//		temp[i].second = va_arg(list, T);
//	}
//	va_end(list);
//	return temp;
//}

/* Move::Move() : Pair<Vector<long int>, bool>{}, vector{first}, recursive{second} {}

Move::Move(const Vector<long int> &vector, bool recursive) :
    Pair<Vector<long int>, bool>{vector, recursive}, vector{first}, recursive{second} {}

Move::Move(const Vector<long int> &vector, bool recursive, Move *capture, short captureNext) :
    Pair<Vector<long int>, bool>{vector, recursive}, vector{first}, recursive{second},
    captureNext{captureNext}, capture{capture} {}

Move::~Move() {
    if (capture) delete capture;
}

Move &Move::operator=(const Move &move) {
    this->vector    = move.vector;
    this->recursive = move.recursive;
    return *this;
} */

//
// short compare(const Move& move_a, const Move& move_b) {
//	return (move_a.first == move_b.first ? (move_a.second == move_b.second ? 1 : -1) : 0);
//}

// short compare(const Move &move_a, const Move &move_b) {
//     return (short)(((move_a.first.m_x == move_b.first.m_x) && (move_a.first.m_y == move_b.first.m_y) &&
//     (move_a.first.m_z == move_b.first.m_z)) ? (move_a.second == move_b.second ? 1 : -1) : 0);
// }


//
// bool operator==(const Vector<long int>&& vectorA, const Vector<long int>&& vectorB) {
//	return ((vectorA.m_x == vectorB.m_x) && (vectorA.m_y == vectorB.m_y) && (vectorA.m_z == vectorB.m_z));
//}
//
// bool operator==(const Vector<long int> vectorA, const Vector<long int> vectorB) {
//	return ((vectorA.m_x == vectorB.m_x) && (vectorA.m_y == vectorB.m_y) && (vectorA.m_z == vectorB.m_z));
//}