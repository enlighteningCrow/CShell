#include "display.h"
#include "./ui_display.h"
#include <boost/thread.hpp>
#include "contactor.h"

Display::Display(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::Display) {
    ui->setupUi(this);
    boost::thread communicate{ contactor };
    // boost::
    // communicate.join();
    QObject::connect(ui->plainTextEdit, &QPlainTextEdit::textChanged, [=](/* const QString& newValue */) { Commu::sendMessagef(ui->plainTextEdit->toPlainText().toStdString()); });
}

Display::~Display() {
    delete ui;
}
