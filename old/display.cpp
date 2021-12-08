#include "display.h"
#include <boost/thread.hpp>
#include "./ui_display.h"
#include "contactor.h"


#include <QPushButton>
#include <QVBoxLayout>

Display::Display(QWidget *parent) : QMainWindow(parent), ui(new Ui::Display) {
    ui->setupUi(this);

    // QVBoxLayout *lay    = new QVBoxLayout(this);
    // QPushButton *boton1 = new QPushButton("button1");

    // lay->addWidget(boton1);
    // ui->scrollAreaWidgetContents_2->setLayout(lay);


    // boost::thread communicate{ contactor };
    // boost::
    // communicate.join();
    QObject::connect(ui->plainTextEdit, &QPlainTextEdit::textChanged, [this](/* const QString& newValue */) {
        statusBar()->showMessage(ui->plainTextEdit->toPlainText());
        // Commu::sendMessagef(ui->plainTextEdit->toPlainText().toStdString());
    });

    qApp->installEventFilter(this);


    // ui->plainTextEdit.
    // QPlainTextEdit a;
    // a.set


    // std::filesystem::path cwd = std::filesystem::current_path();
    // std::cout << "The path is at \"" << cwd << "\"\n";
    // while (true) {
    //    Commu::sendMessagef("cmake --version");
    //    std::cout << "i is now complete with the message:\t" << i << '\n';
    //}
}

Display::~Display() { delete ui; }


bool Display::eventFilter(QObject *obj, QEvent *event) {
    if (event->type() == QEvent::MouseMove) {
        QMouseEvent *mouse(static_cast<QMouseEvent *>(event));
        mouse->pos();
    }
    switch (event->type()) {
    case QEvent::MouseButtonPress: statusBar()->showMessage(QString("Currently pressed.")); break;
    case QEvent::MouseButtonRelease: statusBar()->showMessage(QString("Currently released.")); break;
    default: break;
    }
    return false;
}

void handleUserInputs(QScrollArea &scr) {
    for (auto &i : scr.children()) { i-> }
}