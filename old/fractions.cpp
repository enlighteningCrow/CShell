// #include "stdc++.h"
// #include <cmath>

// long long int gcd(long long int a, long long int b) {
//     return (b ? gcd(b, a % b) : a);
// }

// long long int lcm(long long int a, long long int b) {
//     return ((a / gcd(a, b)) * b);
// }
// class Fraction {
//     long long int m_numerator;
//     long long int m_denominator;
// public:
//     Fraction(long long int numerator = 0, long long int denominator = 1) {
//         long long int m_gcd{ gcd(numerator, denominator) };
//         this->m_numerator = numerator / m_gcd;
//         this->m_denominator = denominator / m_gcd;
//     }
//     long long int numerator() const {
//         return m_numerator;
//     }
//     long long int denominator() const {
//         return m_denominator;
//     }
//     Fraction reciprocal() const {
//         return Fraction{ m_denominator, m_numerator };
//     }
//     // Fraction operator+(const Fraction& b) const {
//         // long long int m_lcm{ lcm(m_denominator, b.m_denominator) };
//         // return Fraction{ m_numerator * (m_lcm / m_denominator) + b.m_numerator * (m_lcm / b.m_denominator), m_lcm };
//     // }
//     // Fraction operator-(const Fraction& b) const {
//         // long long int m_lcm{ lcm(m_denominator, b.m_denominator) };
//         // return Fraction{ m_numerator * (m_lcm / m_denominator) - b.m_numerator * (m_lcm / b.m_denominator), m_lcm };
//     // }
//     // Fraction operator*(const Fraction& b) const {
//         // long long int m_num{ m_numerator * b.m_numerator };
//         // long long int m_den{ m_denominator * b.m_denominator };
//         // long long int m_gcd{ gcd(m_num, m_den) };
//         // return Fraction{ m_num / m_gcd, m_den / m_gcd };
//     // }
//     // Fraction operator/(const Fraction& b) const {
//         // return (*this) * Fraction { b.m_denominator / b.m_numerator };
//     // }
//     friend std::ostream& operator<< (std::ostream& out, const Fraction& frac) {
//         out << frac.m_numerator << " / " << frac.m_denominator;
//         return out;
//     }
//     friend Fraction operator+(const Fraction& a, const Fraction& b);
//     friend Fraction operator-(const Fraction& a, const Fraction& b);
//     friend Fraction operator*(const Fraction& a, const Fraction& b);
//     friend Fraction operator/(const Fraction& a, const Fraction& b);
// };

// Fraction operator+(const Fraction& a, const Fraction& b) {
//     long long int m_lcm{ lcm(a.m_denominator, b.m_denominator) };
//     return Fraction{ a.m_numerator * (m_lcm / a.m_denominator) + b.m_numerator * (m_lcm / b.m_denominator), m_lcm };
// }

// Fraction operator-(const Fraction& a, const Fraction& b) {
//     long long int m_lcm{ lcm(a.m_denominator, b.m_denominator) };
//     return Fraction{ a.m_numerator * (m_lcm / a.m_denominator) - b.m_numerator * (m_lcm / b.m_denominator), m_lcm };
// }

// Fraction operator*(const Fraction& a, const Fraction& b) {
//     long long int m_num{ a.m_numerator * b.m_numerator };
//     long long int m_den{ a.m_denominator * b.m_denominator };
//     long long int m_gcd{ gcd(m_num, m_den) };
//     return Fraction{ m_num / m_gcd, m_den / m_gcd };
// }

// Fraction operator/(const Fraction& a, const Fraction& b) {
//     return a * Fraction{ b.m_denominator, b.m_numerator };
// }

// // template<class T>
// // Fraction&& operator+(const Fraction& a, T& b) {
// //     return Fraction{ a.numerator() + b, a.denominator() };
// // }

// int main() {
//     Fraction a{ 100, 15 };
//     Fraction b{ 238, 12 };
//     // std::cout << a << std::endl << gcd(238, 12) << '\t' << b << std::endl;
//     std::cout << 2 / b << std::endl << gcd(124, 3408) << std::endl;
// }


#include "stdc++.h"
#include <sys/inotify.h>
#include <pstreams/pstream.h>

// int main() {
//     // int fd{ inotify_init() };
//     // inotify_add_watch(fd, "")
//     // system("inotify textsFromStdinFromPython.txt");
//     // system("./printer >> ./set4no3");//textsFromStdinFromPython.txt
//     // run a process and create a streambuf that reads its stdout and stderr
//     redi::pstream proc{ "python", redi::pstreams::pstdout | redi::pstreams::pstderr | redi::pstreams::pstdin };
//     // proc << "Hellos. \n";
//     // proc.write("Hellos. ", 100);
//     // redi::ipstream proc("python", redi::pstreams::pstdout | redi::pstreams::pstderr);
//     // for (int i{ 0 }; i < 25; ++i) {
//         // proc << "Hellos";
//     // }
//     // proc << EOF;
//     std::string line;
//     // read child's stdout
//     while (std::getline(proc.out(), line))
//         std::cout << "stdout: " << line << '\n';
//     // if reading stdout stopped at EOF then reset the state:
//     if (proc.eof() && proc.fail())
//         proc.clear();
//     // read child's stderr
//     while (std::getline(proc.err(), line))
//         std::cout << "stderr: " << line << '\n';
// }

// using std::cout;
// using std::endl;
// using std::string;


// int main() {
//     cout << "start" << endl;
//     redi::pstream proc("./echoer");
//     // proc << "a = []\n";

//     for (int i{ 0 }; i < 100; ++i) {
//         // (cout << "a[" << i << "] = " << i << "\n").flush();
//         // (proc << "a.append(" << i << ")\n")/* .flush() */;
//         proc.write("392\n", 4)/* .flush() */;
//     }
//     (proc << "print(a)\n").flush();
//     string line;
//     getline(proc.out(), line);
//     cout << line << endl;
//     (proc << "exit()\n").flush();
//     // proc.write("foo", 10000).flush();

//     cout << "end" << endl;
//     return 0;
// }

// using redi::pstreams;
// using redi::pstream;
// using redi::ipstream;

// int main() {
//     // const pstreams::pmode mode = pstreams::pstdout | pstreams::pstderr;
//     pstream child("stdbuf --output=0 bash"/* "export PATH=\"/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:$PATH\";unbuffer bash" *//* , mode */);
//     char buf[1024];
//     for (int i{ 0 };i < 1024; ++i) {
//         buf[i] = 0;
//     }
//     std::streamsize n;
//     std::string a;
//     std::string cDir;
//     bool finished[2] = { false, false };
//     child << ("");
//     while (!finished[0] || !finished[1]) {
//         child << "echo $PWD" << std::endl;
//         // child >> cDir;
//         std::getline(child.out(), cDir);
//         std::cout << ":" << cDir << "$\t";
//         std::getline(std::cin, a);
//         a += '\n';
//         std::cout << "Sending out: " << a << ". \n";
//         child.write(a.c_str(), a.size()).flush();
//         // (child << a << '\n').flush();
//         // (child << a << '\n').flush();
//         // (child << "echo hello\n").flush();
//         // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//         usleep(100000);
//         if (!finished[0]) {
//             while ((n = child.err().readsome(buf, sizeof(buf))) > 0)
//                 std::cerr.write(buf, n);
//             if (child.eof()) {
//                 finished[0] = true;
//                 if (!finished[1])
//                     child.clear();
//             }
//         }

//         if (!finished[1]) {
//             while ((n = child.out().readsome(buf, sizeof(buf))) > 0)
//                 std::cout.write(buf, n).flush();
//             if (child.eof()) {
//                 finished[1] = true;
//                 if (!finished[0])
//                     child.clear();
//             }
//         }
//     }

// }

using redi::pstreams;
using redi::pstream;
using redi::ipstream;

#include <boost/thread.hpp>

struct Info {
public:
    std::string message_out;
    std::string message_err;
    std::string path;
    bool terminated;
    bool isComplete() {
        return (((message_out != "") || (message_err != "")) && (path != ""));
    }
    void clear() {
        message_out = "";
        message_err = "";
        path = "";
    }
};

class Commu {
protected:
    static bool m_changed;
    static std::string m_message;
    static Info m_info;
public:
    Commu() {}
    // Commu() : m_message{ "" }, m_changed{ false } {}
    // Commu(std::string message) : m_message{ message }, m_changed{ true } {}
    static Info& info() {
        return m_info;
    }
    operator bool() {
        return m_changed;
    }
    static bool hasChanged() {
        return m_changed;
    }
    static Info& sendMessagef(const std::string& message) {
        m_changed = true;
        m_message = message;
        // boost::thread thread1{}
        while (!m_info.isComplete()) {
            usleep(10000);
        }
        /**
         * @brief
         * Main process should handle this termination (if unexpected).
         */
         // if (m_info.terminated) {
             // 
         // }
        return m_info;
    }
    static void setMessage(const std::string& message) {
        m_changed = true;
        m_message = message;
        return;
    }
    static std::string& getMessage() {
        m_changed = false;
        return m_message;
    }
};

bool Commu::m_changed{ false };
std::string Commu::m_message{ "" };
Info Commu::m_info{ "" };

// Commu communicator1{};

int contactor() {
    // const pstreams::pmode mode = pstreams::pstdout | pstreams::pstderr;
    static pstream child("stdbuf --output=0 bash"/* "export PATH=\"/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:$PATH\";unbuffer bash" *//* , mode */);
    char buf[1024];
    for (int i{ 0 };i < 1024; ++i) {
        buf[i] = 0;
    }
    std::streamsize n;
    std::string a;
    std::string cDir;
    std::stringstream ss;
    bool finished[2] = { false, false };
    child << ("");
    while (!finished[0] || !finished[1]) {
        while (!Commu::hasChanged()) {
            usleep(10000);
        }
        Commu::info().clear();
        child << "echo $PWD" << std::endl;
        std::getline(child.out(), cDir);
        Commu::info().path = ":" + cDir + "$\t";
        // std::cout << ":" << cDir << "$\t";
        std::getline(std::cin, a);
        a += '\n';
        // std::cout << "Sending out: " << a << ". \n";
        child.write(a.c_str(), a.size()).flush();
        usleep(100000);
        if (!finished[0]) {
            while ((n = child.err().readsome(buf, sizeof(buf))) > 0) {
                // ss.write(buf, n);
                // Commu::info().message_err += ss.str();
                // ss.clear();
                Commu::info().message_err += buf;
                // std::cerr.write(buf, n);
            }
            if (child.eof()) {
                finished[0] = true;
                if (!finished[1])
                    child.clear();
            }
        }

        if (!finished[1]) {
            while ((n = child.out().readsome(buf, sizeof(buf))) > 0) {
                // ss.write(buf, n);
                // Commu::info().message_out += ss.str();
                // ss.clear();
                Commu::info().message_out += buf;
                // std::cout.write(buf, n).flush();
            }
            if (child.eof()) {
                finished[1] = true;
                if (!finished[0])
                    child.clear();
            }
        }
    }
    Commu::info().terminated = true;
}