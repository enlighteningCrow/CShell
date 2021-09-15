#include <bits/stdc++.h>
int hello() {
    std::cout.tie(nullptr);

    while (1) {
        for (char* a{ stdout->_IO_buf_base }; a < stdout->_IO_buf_end; ++a) {
            std::cout << '\n';
            std::cout << *a;
            std::cout << '\n';
        }
    }
    return 1;
}
int print() {
    std::cout.tie(nullptr);

    while (1) {
        std::cout << "hello";
    }
    return 1;
}

int main() {
    std::future<int> futurep{ std::async(print) };
    std::future<int> futureh{ std::async(hello) };
}