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
// main part of the program

// int main(int argc, char* argv[]) {
//     QApplication a(argc, argv);
//     Display      w;
//     // ;
//     // boost::thread communicate{ contactor };
//     // boost::
//     // communicate.join();
//     // QObject::connect(w.ui->plainTextEdit, &QPlainTextEdit::textChanged, Commu::sendMessagef());
//     // std::future<int> future{ std::async(contactor) };
//     // QObject::connect(); //Connect the signal everytime enter is pressed in terminal emulator and send the
//     std::string
//     // to the Info static class member m_message.
//     w.show();
//     return a.exec();
// }


/**TODO:
 *
 * The installation of this program will be in a shell script, containing these lines:
 * git clone git://gcc.gnu.org/git/gcc.git /usr/local/CShell/libs
 * build from source,
 * (will think of this later...)
 */

int main(int argc, char** argv) {
    CFile file{"/home/twistingcamel/programs/kmitl/c++/cshell/main/CShell/testfile1.c"};
}