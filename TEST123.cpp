#include "utils.h"

// void doSomething(const Array<Variable>& a, const Array<Functions>& b, const Array<Operators>& c, const Array<Types>& d)
// {
//     for (int i = 0; i < abc.size(); ++i) {
//     }
// }

int main()
{
    Array<int> ar;
    Array<double> st;
    int a = 0;
    std::cout << ar.find(10);
    a = ar.find(10);
    try {
        std::cout << ar[10];
    } catch (...) {
        std::cerr << "error";
    }
    std::cout << ar.push_back(100);
    String str;
    str = "hello";
    str = "gtiy" + str;
    std::cout << str;
    str += "gtiy";
    std::cout << str;
}