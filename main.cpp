// #include "display.h"

// #include <QApplication>

// int main(int argc, char *argv[])
// {
//     QApplication a(argc, argv);
//     Display w;
//     w.show();
//     return a.exec();
// }


#include "cfile.h"
#include "classifier.h"
#include "display.h"

#include <QApplication>
#include <QThread>

#include <boost/thread.hpp>

#include "contactor.h"


int main(int argc, char* argv[]) {
    if (argc != 2)
        return 0;
    CFile        cfile{String(argv[1])};
    QApplication a(argc, argv);
    Display      w{cfile};
    // ;
    // boost::thread communicate{ contactor };
    // boost::
    // communicate.join();
    // QObject::connect(w.ui->plainTextEdit, &QPlainTextEdit::textChanged, Commu::sendMessagef());
    // std::future<int> future{ std::async(contactor) };
    // QObject::connect(); //Connect the signal everytime enter is pressed in terminal emulator and send the
    std::string s;
    // to the Info static class member m_message.
    w.show();
    return a.exec();
}

// int main(int argc, char** argv[]) {
//     Array<int> a{1, 2, 3, 4, 5}, b{6, 7};
//     std::cout << a << '\n' << b << "\n\n";
//     Array<int>::swap(a, b);
//     std::cout << a << '\n' << b << "\n\n";
// }


/**TODO:
 *
 * The installation of this program will be in a shell script, containing these lines:
 * git clone git://gcc.gnu.org/git/gcc.git /usr/local/CShell/libs
 * build from source,
 * (will think of this later...)
 */

// int main(int argc, char** argv) {
//     CFile file{"/home/twistingcamel/programs/kmitl/c++/cshell/main/CShell/testfile1.c"};
// }