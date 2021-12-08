#include "stdc++.h"

// // int8_t sth(int8_t a, int8_t b) { return a + b; }
// char sth(char a, char b) { return a + b; }
// // int16_t sth(int16_t a, int16_t b) { return a + b; }
// short int sth(short int a, short int b) { return a + b; }
// // int32_t sth(int32_t a, int32_t b) { return a + b; }
// int sth(int a, int b) { return a + b; }
// long int sth(long int a, long int b) { return a + b; }
// // int64_t sth(int64_t a, int64_t b) { return a + b; }
// long long int sth(long long int a, long long int b) { return a + b; }

// template<typename T>
// T sth(T a, T b) { return a + b; }
// long long int sth(long long int a, long long int b) { return a + b; }
char sth(char a, char b) { return a + b; }

int main(int, char**) {
    int a, b{ 100 };
    short int c, d{ 50 };
    long int e, f{ 150 };
    long long int g, h{ 200 };
    std::cout << sizeof(sth(a, b)) << std::endl << sizeof(sth(c, d)) << std::endl << sizeof(sth(e, f)) << std::endl << sizeof(sth(g, h)) << std::endl;
}