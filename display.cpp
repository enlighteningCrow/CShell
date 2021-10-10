#include "display.h"
#include "./ui_display.h"
#include <boost/thread.hpp>
#include "contactor.h"

#include <QPushButton>
#include <QVBoxLayout>

Display::Display(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::Display) {
    ui->setupUi(this);


    QVBoxLayout * lay = new QVBoxLayout(this);
    for (int i = 0; i < 30; ++i){
        QPushButton *boton = new QPushButton("this is a button");
        lay ->addWidget(boton);
        }
        ui ->scrollAreaWidgetContents_2->setLayout(lay);


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
