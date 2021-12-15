#include "cfile.h"
#include "classifier.h"
#include "display.h"

#include <QApplication>
#include <QThread>

#include <boost/thread.hpp>

#include "contactor.h"

std::string message_receiver{""};

int main(int argc, char* argv[]) {
    if (argc != 2)
        return 0;
    CFile            cfile{String(argv[1])};
    QApplication     a(argc, argv);
    Display          w{cfile};
    std::future<int> future{std::async(contactor)};
    //     QObject::connect(ui->plainTextEdit, &QPlainTextEdit::textChanged, [this]() {
    //     Info& info = Commu::sendMessagef(ss); while(!info.isComplete()); std::cout << message_receiver <<
    //     );
    w.show();
    return a.exec();
}
