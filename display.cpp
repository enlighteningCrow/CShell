#include "display.h"
#include "./ui_display.h"
#include <boost/thread.hpp>
#include "contactor.h"

Display::Display(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::Display) {
    ui->setupUi(this);
    // boost::thread communicate{ contactor };
    // boost::
    // communicate.join();
    QObject::connect(ui->plainTextEdit, &QPlainTextEdit::textChanged, [this](/* const QString& newValue */) { Commu::sendMessagef(ui->plainTextEdit->toPlainText().toStdString()); });



    // ui->plainTextEdit.
    // QPlainTextEdit a;
    // a.set


    //std::filesystem::path cwd = std::filesystem::current_path();
    //std::cout << "The path is at \"" << cwd << "\"\n";
    //while (true) {
    //    Commu::sendMessagef("cmake --version");
    //    std::cout << "i is now complete with the message:\t" << i << '\n';
    //}
}

Display::~Display() {
    delete ui;
}
