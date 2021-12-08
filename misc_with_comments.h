#ifndef MISC_H
#define MISC_H

// #include "stdc++.h"
#include <nlohmann/json.hpp>
#include "stdc++.h"

#include "file_io.h"


// #include "utils.h"

// Include GLEW
// #include <GL/glew.h>

// // Include GLFW
// #include <GLFW/glfw3.h>

// // Include GLM
// #include <glm/glm.hpp>
// #include <osgDB/ReadFile>
// #include <osgViewer/Viewer>
// #include <osg/Group>
// #include <osg/MatrixTransform>
// #include <osg/Matrix>
// #include <osgGA/TrackballManipulator>

//#include "display.h"

// using nm = nlohmann;
using namespace nlohmann;

// template<class T1, class T2>
// struct Pair {
// public:
//     T1 first;
//     T2 second;
//     Pair() : first{}, second{} {
//     }
//     // Pair(T1 &arg_first) : first{arg_first}, second{} {}
//     Pair(const T1& arg_first) : first{arg_first}, second{} {
//     }
//     // Pair(T1 &arg_first, T2 &arg_second) : first{arg_first}, second{arg_second} {}
//     // Pair(T1 &&arg_first, T2 &&arg_second) : first{arg_first}, second{arg_second} {}
//     // Pair(T1 arg_first, T2 arg_second) : first{arg_first}, second{arg_second} {
//     // }
//     Pair(const T1& arg_first, const T2& arg_second) : first{arg_first}, second{arg_second} {
//     }
//     // Pair(Pair<T1, T2> arg) : first{arg.first}, second{arg.second} {
//     // }
//     Pair(const Pair<T1, T2>& arg) : first{arg.first}, second{arg.second} {
//     }
//     Pair(const std::pair<T1, T2>& list) :
//         first{list.size() > 0 ? list.begin()[0] : T1{}}, second{list.size() > 1 ? list.begin()[1] : T2{}} {
//     }
//     bool operator==(const Pair<T1, T2>& pair) const {
//         return (first != pair.first ? 0 : (second != pair.second ? 0 : 1));
//     }
//     bool operator!=(const Pair<T1, T2>& pair) const {
//         return (first != pair.first ? 1 : (second != pair.second ? 1 : 0));
//     }
//     bool operator<(const Pair<T1, T2>& pair) const {
//         return (
//             first < pair.first
//                 ? 1
//                 : (first > pair.first ? 0 : (second < pair.second ? 1 : (second > pair.second ? 0 : 0))));
//     }
//     bool operator<=(const Pair<T1, T2>& pair) const {
//         return (
//             first < pair.first
//                 ? 1
//                 : (first > pair.first ? 0 : (second < pair.second ? 1 : (second > pair.second ? 0 : 1))));
//     }
//     bool operator>(const Pair<T1, T2>& pair) const {
//         return (
//             first < pair.first
//                 ? 0
//                 : (first > pair.first ? 1 : (second < pair.second ? 0 : (second > pair.second ? 1 : 0))));
//     }
//     bool operator>=(const Pair<T1, T2>& pair) const {
//         return (
//             first < pair.first
//                 ? 0
//                 : (first > pair.first ? 1 : (second < pair.second ? 0 : (second > pair.second ? 1 : 1))));
//     }
//     // operator T1() {
//     //     return first;
//     // }
//     bool operator!() const {
//         return !first;
//     }

//     static void swap(Pair<T1, T2>& a, Pair<T1, T2>& b) {
//         Pair<T1, T2> c(a);
//         a = b;
//         b = c;
//     }
// };

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
    out << "( " /* String("( ") */ << pair.first << ", " /* String(", ") */ << pair.second << " )" /* String(" )") */;
    return out;
}

template<class T1, class T2>
FILE& operator<<(FILE& out, const Pair<T1, T2>& pair) {
    out << "( " /* String("( ") */ << pair.first << ", " /* String(", ") */ << pair.second << " )" /* String(" )") */;
    return out;
}

// template<>
// FILE& operator<<(FILE& out, const Pair<T1, T2>& pair) {
//     out << "( " /* String("( ") */ << pair.first << ", " /* String(", ") */ << pair.second << " )" /* String(" )")
//     */; return out;
// }

template<class T1, class T2>
class Pair : std::pair<T1, T2> {
public:
    using std::pair<T1, T2>::pair;
    Pair() : first{}, second{} {
    }
    // Pair(T1 &arg_first) : first{arg_first}, second{} {}
    Pair(const T1& arg_first) : first{arg_first}, second{} {
    }
    // Pair(T1 &arg_first, T2 &arg_second) : first{arg_first}, second{arg_second} {}
    // Pair(T1 &&arg_first, T2 &&arg_second) : first{arg_first}, second{arg_second} {}
    // Pair(T1 arg_first, T2 arg_second) : first{arg_first}, second{arg_second} {
    // }
    Pair(const T1& arg_first, const T2& arg_second) : first{arg_first}, second{arg_second} {
    }
    // Pair(Pair<T1, T2> arg) : first{arg.first}, second{arg.second} {
    // }
    Pair(const Pair<T1, T2>& arg) : first{arg.first}, second{arg.second} {
    }
    Pair(const std::pair<T1, T2>& list) :
        first{list.size() > 0 ? list.begin()[0] : T1{}}, second{list.size() > 1 ? list.begin()[1] : T2{}} {
    }
    bool operator==(const Pair<T1, T2>& pair) const {
        return (first != pair.first ? 0 : (second != pair.second ? 0 : 1));
    }
    bool operator!=(const Pair<T1, T2>& pair) const {
        return (first != pair.first ? 1 : (second != pair.second ? 1 : 0));
    }
    bool operator<(const Pair<T1, T2>& pair) const {
        return (
            first < pair.first
                ? 1
                : (first > pair.first ? 0 : (second < pair.second ? 1 : (second > pair.second ? 0 : 0))));
    }
    bool operator<=(const Pair<T1, T2>& pair) const {
        return (
            first < pair.first
                ? 1
                : (first > pair.first ? 0 : (second < pair.second ? 1 : (second > pair.second ? 0 : 1))));
    }
    bool operator>(const Pair<T1, T2>& pair) const {
        return (
            first < pair.first
                ? 0
                : (first > pair.first ? 1 : (second < pair.second ? 0 : (second > pair.second ? 1 : 0))));
    }
    bool operator>=(const Pair<T1, T2>& pair) const {
        return (
            first < pair.first
                ? 0
                : (first > pair.first ? 1 : (second < pair.second ? 0 : (second > pair.second ? 1 : 1))));
    }
    // operator T1() {
    //     return first;
    // }
    bool operator!() const {
        return !first;
    }

    static void swap(Pair<T1, T2>& a, Pair<T1, T2>& b) {
        Pair<T1, T2> c(a);
        a = b;
        b = c;
    }
}

#endif
