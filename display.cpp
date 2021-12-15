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

void populateSpawningLabels(Ui::Display* ui, String name);

Display::Display(CFile& cfile, QWidget* parent) :
    QMainWindow(parent), ui(new Ui::Display), handler(), obji{m_cfile}, conh(), m_cfile{cfile} {
    ui->setupUi(this);
    handler.setUi(ui);
    obji.setUi(ui);
    conh.setUi(ui);

    obji.populateSpawningLabels();

    QObject::connect(ui->plainTextEdit, &QPlainTextEdit::textChanged, [this](/* const QString& newValue */) {
        statusBar()->showMessage(ui->plainTextEdit->toPlainText());
    });

    qApp->installEventFilter(this);
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
    case QEvent::MouseButtonRelease:
    case QEvent::MouseMove: {
        QMouseEvent& mouse(*(static_cast<QMouseEvent*>(event)));
        handler.handleUserInputs(mouse);
        if (ui->Objects->rect().contains(mouse.pos())) {
            obji.handleInput(*event);
        };
    } break;
    case QEvent::KeyPress: {
        QKeyEvent* key(static_cast<QKeyEvent*>(event));
        if (key->key() == Qt::Key_Shift) {
            handler.setShiftPressed();
        }
    } break;
    case QEvent::KeyRelease: {
        QKeyEvent* key(static_cast<QKeyEvent*>(event));
        if (key->key() == Qt::Key_Shift) {
            handler.setShiftReleased();
        }
    } break;

    default:
        break;
    }
    return false;
}
