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

Display::Display(CFile& cfile, QWidget* parent) : QMainWindow(parent), ui(new Ui::Display), m_cfile{cfile} {
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
    int          threshold;
    bool         m_currently_pressed;
    bool         m_current_button_is_right;
    bool         m_passed_threshold;
    bool         is_in_select_mode;
    bool         is_in_move_mode;
    QScrollArea& m_scr;
    QObjectList  m_selected;
    QPoint       m_previous_mouse_pos;
    QPoint       m_previous_mouse_click_pos;

public:
    ScrollAreaHandler(QScrollArea& scr) :
        m_currently_pressed{false}, m_current_button_is_right{false}, m_scr{scr}, m_selected{},
        m_previous_mouse_pos{0, 0}, m_previous_mouse_click_pos{0, 0}, m_passed_threshold{false}, threshold{15},
        is_in_select_mode{false}, is_in_move_mode{false} {
    }
    void selectArea(const QRect& rect) {
        m_selected.clear();
        for (auto& obj : m_scr.children()) {
            QGroupBox& box{*(static_cast<QGroupBox*>(obj))};
            if (box.geometry().intersects(rect)) {
                m_selected.push_back(obj);
            }
        }
    }
    void clearSelect() {
        m_selected.clear();
    }
    void move(const QPoint& delta_pos) {
        for (QObject* i : m_scr.children()) {
            QGroupBox* ptr{static_cast<QGroupBox*>(i)};
            ptr->move(ptr->pos() + delta_pos);
        }
    }
    void move(const QObjectList& list, const QPoint& delta_pos) {
        for (QObject* i : list) {
            QGroupBox* ptr{static_cast<QGroupBox*>(i)};
            ptr->move(ptr->pos() + delta_pos);
        }
    }
    bool overlapsAny(const QRect& rect) {
        for (QObject* i : m_scr.children()) {
            QGroupBox* ptr{static_cast<QGroupBox*>(i)};
            if (ptr->geometry().intersects(rect)) {
                return true;
            }
        }
    }
    bool overlapsAny(const QObjectList& list, const QRect& rect) {
        for (QObject* i : list) {
            QGroupBox* ptr{static_cast<QGroupBox*>(i)};
            if (ptr->geometry().intersects(rect)) {
                return true;
            }
        }
    }
    void handleUserInputs(QMouseEvent& event) {
        if ((!(m_scr.rect().contains(event.pos()))) && (!m_currently_pressed)) {
            m_currently_pressed = (event.type() == QEvent::MouseButtonPress);
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
        // TODO: And not yet released here
        if (mode == 1) {
            if (m_current_button_is_right == (event.button() == Qt::RightButton)) {
                m_current_button_is_right = false;
                m_currently_pressed       = false;
                if (is_in_select_mode) {
                    selectArea(QRect(
                        m_previous_mouse_click_pos.x(), m_previous_mouse_click_pos.y(), event.pos().x(),
                        event.pos().y()));
                    is_in_select_mode = false;
                }
                is_in_move_mode    = false;
                m_passed_threshold = false;
            }
        }
        else if (m_currently_pressed) {
            if (m_current_button_is_right) {
                if (m_passed_threshold) {
                    move(event.pos() - m_previous_mouse_pos);
                }
                else if ((event.pos() - m_previous_mouse_click_pos).manhattanLength() > threshold) {
                    m_passed_threshold = true;
                    move(event.pos() - m_previous_mouse_click_pos);
                }
            }
            else {
                if (is_in_select_mode) {
                    return;
                }
                else if (is_in_move_mode) {
                    move(m_selected, event.pos() - m_previous_mouse_pos);
                }
                else {
                    if ((event.pos() - m_previous_mouse_click_pos).manhattanLength() > threshold) {
                        if (overlapsAny(m_selected, QRect(m_previous_mouse_click_pos, event.pos()))) {
                            is_in_select_mode = true;
                            // selectArea(QRect(m_previous_mouse_click_pos, event.pos()));
                        }
                        else {
                            is_in_move_mode = true;
                            // move(event.pos() - m_previous_mouse_click_pos);
                        }
                    }
                }
                // QGroupBox* ptr{nullptr};
                // for (auto* i : m_scr.children()) {
                //     // QGroupBox* ptr = static_cast<QGroupBox*>(i);
                //     // ptr = static_cast<QGroupBox*>(i);
                //     if ((static_cast<QGroupBox*>(i))->rect().contains(QPoint(0, 0))) {
                //         ptr = static_cast<QGroupBox*>(i);
                //         break;
                //     }
                //     // ptr = nullptr;
                // }
                // if (ptr) {
                // }
                // if (overlapsAny())


                //     if (m_selected.size()) {
                //     }

                // handleUserInputs(*(ui->scrollArea), static_cast<QMouseEvent*>(event), 1);
            }
        }
        else if (mode == 0) {
            m_previous_mouse_click_pos = event.pos();
            m_currently_pressed        = true;
            bool is_right_button{event.button() == Qt::RightButton};
            m_current_button_is_right = is_right_button;
        }
        m_previous_mouse_pos = event.pos();
    }
}
// }
;

class ObjectInfo;

class SpawningLabel : public QLabel {
protected:
    // Pair < String, Array<Pair<String, size_ut>> m_data
    Pair<String, Array<Pair<String, size_ut>>> m_data;

public:
    SpawningLabel(const decltype(m_data)& info) : QLabel(), m_data{info} {
    }
    SpawningLabel(const decltype(m_data)& info, QString str) : QLabel(str), m_data{info} {
    }
    friend class ObjectInfo;
};

class ObjectInfo /* : public QTabWidget */ {
protected:
    /**
     * @brief
     * Array containing:
     *      A pair of:
     *          Name of the object
     *          Array of:
     *              Pair of:
     *                  Name of each of the parameters
     *                  Type of each of the parameters (in STypes)
     *
     */
    typedef Array<Pair<String, Array<Pair<String, size_ut>>>> InfoType;
    // std::tuple<InfoType, InfoType, InfoType, InfoType>
    Ui::Display* m_ui;

    InfoType variables;
    InfoType functions;
    InfoType types;
    InfoType operators;
    InfoType misc;

    QTabWidget& tabs;

    // QWidget Variables;
    // QWidget Functions;
    // QWidget Types;
    // QWidget Operators;
    // QWidget Misc;

    // Array<Pair<QWidget*, QVBoxLayout*>> tabs;

    bool           is_pressed;
    SpawningLabel* currently_pressed;

public:
    ObjectInfo(CFile& cfile, Ui::Display* ui) :
        /* QTabWidget{ui->layoutWidget},  */ is_pressed{false}, m_ui{ui}, tabs{*(ui->Objects)} {
        // this->setObjectName(QString("Objects"));
        for (auto& i : Classifier::key_expressions_const) {
            if ((i.second[0].first & Classifier::STypes::TYPE) ||
                (i.second[0].first & Classifier::STypes::TYPE_MODIFIER)) {
                types.push_back(Pair<String, Array<Pair<String, size_ut>>>(i.first, i.second[0].first));
            }
            else if (
                // (i.second[j].first & Classifier::STypes::TYPE) ||
                (i.second[0].first & Classifier::STypes::OPERATOR)) {
                for (std::size_t j{0}; j < i.second.size(); ++j) {
                    operators.push_back(Pair<String, Array<Pair<String, size_ut>>>(i.first, i.second[j].first));
                }
            }
            else {
                misc.push_back(Pair<String, Array<Pair<String, size_ut>>>(i.first, i.second[0].first));
            }
            // if()
            // for (std::size_t j{0}; j < i.second.size(); ++j) {
            //     if ((i.second[j].first & Classifier::STypes::TYPE) ||
            //         (i.second[j].first & Classifier::STypes::TYPE_MODIFIER)) {
            //         // i.second[j].first;
            //     }
            // }
        }
        variables = cfile.all;
        functions = cfile.functions;

        // Pair<QWidget*, QVBoxLayout*> pairs;
        // QWidget*     tabname;
        // QVBoxLayout* layout;
        // QScrollArea* scrollArea;
        // QVBoxLayout* layout2;


        // for (short int i{0}; i < 5; ++i) {
        //     tabname    = new QWidget();
        //     layout     = new QVBoxLayout(pairs.first);
        //     scrollArea = new QScrollArea(tabname);


        //     tabs.emplace_back();
        // }
        // ui->
    }
    void spawnComponent(SpawningLabel& label, const QPoint& pos) {
        auto* a = new Component(m_ui->mainEditor, label.m_data.first.toStdString(), label.m_data.second, pos);


        // if (ui->Objects->currentWidget()->children()) {
        // }
    }
    void handleInput(QMouseEvent& event) {
        if (!is_pressed) {
            if (event.type() == QEvent::MouseButtonPress) {
                for (auto& i : tabs.children()) {
                    SpawningLabel& wid = *(static_cast<SpawningLabel*>(i));
                    // TODO: Make a class inheriting from QLabel and make it contain all the information inside it.
                    if (wid.rect().contains(event.pos())) {
                        is_pressed        = true;
                        currently_pressed = &wid;
                    }
                }
            }
        }
        else {
            if (event.type() == QEvent::MouseButtonRelease) {
                spawnComponent(*currently_pressed, event.pos());
            }
        }
    }
};


bool Display::eventFilter(QObject* obj, QEvent* event) {
    static ScrollAreaHandler handler{*(ui->mainEditor)};
    static ObjectInfo        obji{m_cfile, ui};
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
    default:
        break;
    }
    return false;
}
