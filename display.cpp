// #include "display.h"
// #include "./ui_display.h"

// Display::Display(QWidget *parent)
//     : QMainWindow(parent)
//     , ui(new Ui::Display)
// {
//     ui->setupUi(this);
// }

// Display::~Display()
// {
//     delete ui;
// }

#include "display.h"
#include <QLabel>
#include <QPaintEngine>
#include <QPushButton>
#include <boost/thread.hpp>

#include "./ui_display.h"
#include "cfile.h"
#include "classifier.h"
#include "component.h"
#include "contactor.h"


// CFile(const String& filename);
// #include <QGroupBox>
// #include <QPushButton>
// #include <QVBoxLayout>
// #include <QtCore/QVariant>
// #include <QtWidgets/QApplication>
// #include <QtWidgets/QGridLayout>
// #include <QtWidgets/QGroupBox>
// #include <QtWidgets/QHBoxLayout>
// #include <QtWidgets/QLabel>
// #include <QtWidgets/QLineEdit>
// #include <QtWidgets/QMainWindow>
// #include <QtWidgets/QMenuBar>
// #include <QtWidgets/QPlainTextEdit>
// #include <QtWidgets/QPushButton>
// #include <QtWidgets/QScrollArea>
// #include <QtWidgets/QStackedWidget>
// #include <QtWidgets/QStatusBar>
// #include <QtWidgets/QTabWidget>
// #include <QtWidgets/QTextEdit>
// #include <QtWidgets/QVBoxLayout>
// #include <QtWidgets/QWidget>

void populateSpawningLabels(Ui::Display* ui, String name);

Display::Display(CFile& cfile, QWidget* parent) :
    QMainWindow(parent), ui(new Ui::Display), handler(*(ui->mainEditor)), obji{m_cfile, ui}, conh(ui), m_cfile{cfile} {
    ui->setupUi(this);
    obji.populateSpawningLabels();

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

Display::~Display() {
    delete ui;
}


bool Display::eventFilter(QObject* obj, QEvent* event) {
    if (event->type() == QEvent::MouseMove) {
        QMouseEvent* mouse(static_cast<QMouseEvent*>(event));
        mouse->pos();
    }
    switch (event->type()) {
    case QEvent::MouseButtonPress:
        // if (!currently_pressed) {
        //     if (ui->scrollArea->rect().contains(static_cast<QMouseEvent*>(event)->pos()))
        //         handleUserInputs(*(ui->scrollArea), static_cast<QMouseEvent*>(event), 1);
        // }
        // currently_pressed = true;
        // statusBar()->showMessage(QString("Currently pressed."));
        // break;
    case QEvent::MouseButtonRelease:
    // statusBar()->showMessage(QString("Currently released."));
    // break;
    case QEvent::MouseMove: {
        QMouseEvent& mouse(*(static_cast<QMouseEvent*>(event)));
        handler.handleUserInputs(mouse);
        if (ui->Objects->rect().contains(mouse.pos())) {
            obji.handleInput(mouse);
        };
    } break;
    case QEvent::KeyPress: {
        QKeyEvent* key(static_cast<QKeyEvent*>(event));
        if (key->key() == Qt::Key_Shift) {
            handler.setShiftPressed();
            // currently_pressed = false;
            // statusBar()->showMessage(QString("Currently released."));
        }
    } break;
    case QEvent::KeyRelease: {
        QKeyEvent* key(static_cast<QKeyEvent*>(event));
        if (key->key() == Qt::Key_Shift) {
            handler.setShiftReleased();
            // currently_pressed = false;
            // statusBar()->showMessage(QString("Currently released."));
        }
    } break;

    default:
        break;
    }
    return false;
}
