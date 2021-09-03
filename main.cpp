#include "display.h"

#include <QApplication>
#include <QThread>

#include <boost/thread.hpp>

#include "contactor.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Display w;
    // ;
    boost::thread communicate{ contactor };
    // boost::
    // communicate.join();
    // QObject::connect(w.ui->plainTextEdit, &QPlainTextEdit::textChanged, Commu::sendMessagef());
    // QObject::connect(); //Connect the signal everytime enter is pressed in terminal emulator and send the std::string to the Info static class member m_message. 
    w.show();
    return a.exec();
}
