#include "utils.h"
#include "array_view.h"
#include "stdc++.h"


bool isAlnum(char c) {
    return ((c <= 'Z' && c >= 'A') || (c <= 'z' && c >= 'a') || (c <= '9' && c >= '0'));
}
bool isAlphabet(char c) {
    return ((c <= 'Z' && c >= 'A') || (c <= 'z' && c >= 'a'));
}
bool isNumber(char c) {
    return (c <= '9' && c >= '0');
}

String::String(const String_view& arr) : Array<char>() {
    this->std::vector<char>::insert(end(), arr.arr().begin() + arr.start(), arr.arr().begin() + arr.end());
}

size_ut String::find(String_view& target) {
    find(String(target));
}