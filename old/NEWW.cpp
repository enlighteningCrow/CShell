#include "contactor.h"
#include <filesystem>

int main() {
    std::future<int> future{ std::async(contactor) };
    Info& info{ Commu::info() };
    std::filesystem::path cwd = std::filesystem::current_path();
    std::cout << "The path is at \"" << cwd << "\"\n";
    bool first{ 1 };
    // while (true) {
    std::vector<std::string> commands{ "ls -a", "cmake --version", /* "apt search boost",  */"gcc --version", "g++ --version", "gcc-10 --version", "g++-10 --version", "clang --version", "python", "print(\"Hello World\")" };
    // std::vector<std::string> commands{ /* "ls -a",  */"python" , "a = 0", "print(a)" };
    // std::vector<std::string> commands{ "ls -a", "gcc" };
    for (std::string& i : commands) {
        usleep(100000);
        Commu::sendMessagef(i);

        // std::cout.tie(nullptr);
        // stdout->_IO_buf_base;
        // stdout->_IO_buf_end;

        first = 0;
        // info.complete = false;
        // while (!i.complete) {
            // ;
        // }
        // i.complete = false;
        // std::cout << "i is now complete with the message:\t" << Commu::info() << '\n';
    }
    std::cout << "i is now complete with the message:\t" << info << '\n';
    // future.get();
}

// #include "stdc++.h"

// int main() {
//     int a, b, c;
//     std::cin >> a >> b;
//     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//     std::cin >> c;
// }