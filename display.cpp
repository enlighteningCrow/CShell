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
#include <boost/thread.hpp>
#include "./ui_display.h"
#include "contactor.h"


#include <QGroupBox>
#include <QPushButton>
#include <QVBoxLayout>

Display::Display(QWidget* parent) : QMainWindow(parent), ui(new Ui::Display) {
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

Display::~Display() {
    delete ui;
}

class ScrollAreaHandler {
protected:
    bool         currently_pressed;
    bool         current_button_is_right;
    QScrollArea& m_scr;
    QObjectList  m_selected;
    QPoint       m_previous_mouse_pos;

public:
    ScrollAreaHandler(QScrollArea& scr) :
        currently_pressed{false}, current_button_is_right{false}, m_scr{scr}, m_selected{}, m_previous_mouse_pos{0, 0} {
    }
    void handleUserInputs(QMouseEvent& event) {
        if (!(m_scr.rect().contains(event.pos()))) {
            currently_pressed = (event.type() == QEvent::MouseButtonPress);
            return;
        }
        short int mode;
        switch (event.type()) {
        case QEvent::MouseButtonPress:
            mode = 0;
            break;
        case QEvent::MouseButtonRelease:
            mode = 1;
            break;
        case QEvent::MouseMove:
            mode = 2;
            break;
        default:
            break;
        }
        bool is_right_button{event.button() == Qt::RightButton};
        // TODO: And not yet released here
        if (currently_pressed) {
            if (current_button_is_right) {
                QPoint delta_pos{event.pos() - m_previous_mouse_pos};
                for (QObject* i : m_scr.children()) {
                    QGroupBox* ptr{static_cast<QGroupBox*>(i)};
                    ptr->move(ptr->pos() + delta_pos);
                }
            }
            if (m_selected.size()) {
            }

            // handleUserInputs(*(ui->scrollArea), static_cast<QMouseEvent*>(event), 1);

            for (auto* i : m_scr.children()) {
                QGroupBox* ptr = static_cast<QGroupBox*>(i);
                ptr->rect().contains(QPoint(0, 0));
            }
        }
        currently_pressed       = (bool)(mode);
        current_button_is_right = is_right_button;
        m_previous_mouse_pos    = event.pos();
    }
};

bool Display::eventFilter(QObject* obj, QEvent* event) {
    static ScrollAreaHandler handler{*(ui->scrollArea)};
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
    case QEvent::MouseMove:
        handler.handleUserInputs(*static_cast<QMouseEvent*>(event));
    default:
        break;
    }
    return false;
}
