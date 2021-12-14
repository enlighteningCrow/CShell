// #ifndef DISPLAY_H
// #define DISPLAY_H

// #include <QMainWindow>

// QT_BEGIN_NAMESPACE
// namespace Ui { class Display; }
// QT_END_NAMESPACE

// class Display : public QMainWindow
// {
//     Q_OBJECT

// public:
//     Display(QWidget *parent = nullptr);
//     ~Display();

// private:
//     Ui::Display *ui;
// };
// #endif // DISPLAY_H

#ifndef DISPLAY_H
#define DISPLAY_H

#include <QEvent>
#include <QGroupBox>
#include <QLabel>
#include <QMainWindow>
#include <QMouseEvent>
#include <QObject>
#include <QPaintEngine>
#include <QPainter>
#include <QPainterPath>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>
#include <stdio.h>
#include <stdlib.h>
#include "./ui_display.h"
#include "cfile.h"
#include "classifier.h"
#include "component.h"
#include "contactor.h"
#include "utils.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class Display;
}
QT_END_NAMESPACE

struct Color {
    short int rgb_r;
    short int rgb_g;
    short int rgb_b;
};

// class Display : public QMainWindow {
//     Q_OBJECT

// public:
//     Display(QWidget *parent = nullptr);
//     ~Display();

//     // void buttons(const Array<variable>& a, const Array<functions>& b, const Array<operators>& c, const
//     Array<types>&
//     // d)   {
// #define TMP_HOLDER int
//     void buttons(
//         const Array<TMP_HOLDER> &a, const Array<TMP_HOLDER> &b, const Array<TMP_HOLDER> &c,
//         const Array<TMP_HOLDER> &d) {
// #undef TMP_HOLDER
//         QPushButton **functions = (QPushButton **)malloc(0);
//         QPushButton **varables  = (QPushButton **)malloc(0);
//         QPushButton **types     = (QPushButton **)malloc(0);
//         QPushButton **operators = (QPushButton **)malloc(0);

//         // if (a.size() != 0) { varables = (QPushButton **)realloc(varables, sizeof(a[0]) * (a.size())); }

//         // if (b.size() != 0) { functions = (QPushButton **)realloc(functions, sizeof(b[0]) * (b.size())); }

//         // if (c.size() != 0) { types = (QPushButton **)realloc(types, sizeof(c[0]) * (c.size())); }

//         // if (d.size() != 0) { operators = (QPushButton **)realloc(operators, sizeof(d[0]) * (d.size())); }


//         // for (int i = 0; i < a.size(); ++i) {
//         //     varables[i] = addNewButton(0);
//         //     QObject::connect(*(varables + i), &QPushButton::clicked, nullptr, [this]() -> void {
//         //         spawn(/*TODO*/ "PUT THE CORRECT STRING HERE", 0ULL, 0);
//         //     });
//         // }

//         // for (int i = 0; i < b.size(); ++i) {
//         //     functions[i] = addNewButton(0);
//         //     QObject::connect(*(functions + i), &QPushButton::clicked, nullptr, [this]() -> void {
//         //         spawn(/*TODO*/ "PUT THE CORRECT STRING HERE", 0ULL, 0);
//         //     });
//         // }

//         // for (int i = 0; i < c.size(); ++i) {
//         //     types[i] = addNewButton(0);
//         //     QObject::connect(*(types + i), &QPushButton::clicked, nullptr, [this]() -> void {
//         //         spawn(/*TODO*/ "PUT THE CORRECT STRING HERE", 0ULL, 0);
//         //     });
//         // }

//         // for (int i = 0; i < d.size(); ++i) {
//         //     operators[i] = addNewButton(0);
//         //     QObject::connect(*(operators + i), &QPushButton::clicked, nullptr, [this]() -> void {
//         //         spawn(/*TODO*/ "PUT THE CORRECT STRING HERE", 0ULL, 0);
//         //     });
//         // }


//         // for (int i = 0;){
//     }

//     // void spawn(String name, std::size_t id, int type) {
//     //     // TODO: Continue this thing down here:
//     //     // paintEvent()
//     // }

//     bool eventFilter(QObject *obj, QEvent *event);

//     // QPushButton *addNewButton(short int num) {
//     //     QVBoxLayout *lay = new QVBoxLayout(this);
//     //     QPushButton *boton;
//     //     // for (int i = 0; i < num; ++i){
//     //     boton = new QPushButton("this is a button");
//     //     lay->addWidget(boton);
//     //     //}
//     //     ui->scrollAreaWidgetContents_2->setLayout(lay);
//     //     // return *boton
//     //     return boton;
//     // }

//     // private:
//     Ui::Display *ui;
//     // void         Display::paintEvent(QPaintEvent *event);

//     // void paintEvent(QPaintEvent *event);
//     // void paintEvent(Color color, double x, double y, double width, double height);
// };

class CFile;


class ScrollAreaHandler {
protected:
    bool         is_in_shift;
    int          threshold;
    bool         m_currently_pressed;
    bool         m_current_button_is_right;
    bool         m_passed_threshold;
    bool         is_in_select_mode;
    bool         is_in_move_mode;
    Ui::Display* m_ui;
    QScrollArea* m_scr;
    QObjectList  m_selected;
    QPoint       m_previous_mouse_pos;
    QPoint       m_previous_mouse_click_pos;

public:
    ScrollAreaHandler(QScrollArea& scr) :
        m_currently_pressed{false}, m_current_button_is_right{false}, m_scr{&scr}, m_selected{},
        m_previous_mouse_pos{0, 0}, m_previous_mouse_click_pos{0, 0}, m_passed_threshold{false}, threshold{15},
        is_in_select_mode{false}, is_in_move_mode{false} {
    }
    ScrollAreaHandler(Ui::Display* ui) :
        m_currently_pressed{false}, m_current_button_is_right{false}, m_ui{ui}, m_scr{nullptr}, m_selected{},
        m_previous_mouse_pos{0, 0}, m_previous_mouse_click_pos{0, 0}, m_passed_threshold{false}, threshold{15},
        is_in_select_mode{false}, is_in_move_mode{false} {
    }
    void setShiftPressed() {
        is_in_shift = true;
    }
    void setShiftReleased() {
        is_in_shift = false;
    }
    void selectArea(const QRect& rect) {
        m_selected.clear();
        for (auto& obj : m_scr->children()) {
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
        for (QObject* i : m_scr->children()) {
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
        for (QObject* i : m_scr->children()) {
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
        // TODO: Look out for when the m_ui (for not only this class) is not yet initialized.
        m_scr = ui->mainEditor;
        if (is_in_shift) {
            if ((!(m_scr->rect().contains(event.pos()))) && (!m_currently_pressed)) {
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
                    // for (auto* i : m_scr->children()) {
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
};


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
    SpawningLabel(String str, QWidget* wid) : QLabel(QString(str.cStr().get()), wid), m_data{} {
    }
    SpawningLabel(QString str, QWidget* wid) : QLabel(str, wid), m_data{} {
    }
    SpawningLabel(String str) : QLabel(QString(str.cStr().get())), m_data{} {
    }
    SpawningLabel(QString str) : QLabel(str), m_data{} {
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
        /* QTabWidget{ui->layoutWidget},  */ is_pressed{false}, m_ui{ui}, tabs{*(ui->Objects)}, currently_pressed{

                                                                                                    nullptr} {
        // this->setObjectName(QString("Objects"));
        for (auto& i : Classifier::key_expressions_const) {
            if ((i.second[0].first & Classifier::STypes::TYPE) ||
                (i.second[0].first & Classifier::STypes::TYPE_MODIFIER)) {
                types.push_back(Pair<String, Array<Pair<String, size_ut>>>(i.first, 0 /* i.second[0].first */));
            }
            else if (
                // (i.second[j].first & Classifier::STypes::TYPE) ||
                (i.second[0].first & Classifier::STypes::OPERATOR)) {
                for (std::size_t j{0}; j < i.second.size(); ++j) {
                    operators.push_back(Pair<String, Array<Pair<String, size_ut>>>(
                        i.first, 2 /* i.second[0].first */ /* i.second[j].first */));
                }
            }
            else {
                misc.push_back(Pair<String, Array<Pair<String, size_ut>>>(i.first, 0 /* i.second[0].first */));
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
        // populateSpawningLabels();
    }
    void spawnComponent(SpawningLabel& label, const QPoint& pos) {
        auto* a = new Component(m_ui->mainEditor, label.m_data.first.toStdString(), label.m_data.second, pos);


        // if (ui->Objects->currentWidget()->children()) {
        // }
    }
    void handleInput(QMouseEvent& event) {
        if (!is_pressed) {
            if (event.type() == QEvent::MouseButtonPress) {
                // tabs.currentWidget()

                // for (auto& i : tabs.currentWidget()->children()) {
                for (auto& i : static_cast<QScrollArea*>(tabs.currentWidget()->children()[1])->layout()->children()) {

                    // std::cout << static_cast<QScrollArea*>(tabs.currentWidget()->children()[1])->layout();
                    // ->objectName().toStdString()
                    // << std::endl;
                    // auto* lab{new QLabel()};
                    // static_cast<QVBoxLayout*>(tabs.currentWidget()->children()[1])->addWidget(lab);
                    // std::cout << static_cast<QLabel*>(
                    //                  static_cast<QVBoxLayout*>(tabs.currentWidget()->children()[0])->children()[0])
                    //                  ->objectName()
                    //                  .toStdString()
                    //           << std::endl;
                    SpawningLabel& wid = *(static_cast<SpawningLabel*>(i));
                    // TODO: Make a class inheriting from QLabel and make it contain all the information inside
                    // it.
                    if (wid.rect().contains(event.pos())) {
                        is_pressed        = true;
                        currently_pressed = &wid;
                    }
                }
                // std::cout << std::endl;
            }
        }
        else {
            if (event.type() == QEvent::MouseButtonRelease) {
                if (is_pressed && currently_pressed) {
                    is_pressed = false;
                    spawnComponent(*currently_pressed, event.pos());
                }
                // spawnComponent(*currently_pressed, event.pos());
            }
        }
    }

    void populateSpawningLabels() {
        std::size_t counter{0};
        // QString     temp("hellos");
        // // QLabel      label1{};
        // QLabel& label1 = *(new QLabel());
        // label1.setText(temp);
        // label1.;
        // label1.
        // SpawningLabel lab2(QString("hellos"));
        // variables, functions, types, operators, misc;
        {
            InfoType& i{variables};
            for (Pair<String, Array<Pair<String, size_ut>>>& j : i) {
                // static_cast<QScrollArea*>(tabs.widget(counter)->children()[1])->widget()->layout();
                // std::cout << tabs.widget(counter) /* ->children()[1] */->objectName().toStdString() << std::endl;
                // std::cout << m_ui->Objects->widget(counter) /* ->children()[1] */->objectName().toStdString()
                //           << std::endl;

                std::cout << static_cast<QScrollArea*>(m_ui->Objects->widget(counter)->children()[1])
                                 ->widget()
                                 ->layout()
                                 ->objectName()
                                 .toStdString()
                          << std::endl;
                SpawningLabel* spl = new SpawningLabel(j.first, nullptr);
                static_cast<QScrollArea*>(m_ui->Objects->widget(counter)->children()[1])
                    ->widget()
                    ->layout()
                    ->addWidget(spl);
                // m_ui->saVariablesCL->addWidget(spl);

                // static_cast<QScrollArea*>(m_ui->Objects->currentWidget()->children()[1])->layout()->addWidget(spl);
                // ui->mainEditor->layout()->addWidget(spl);
            }
            ++counter;
        }
        {
            InfoType& i{functions};
            for (Pair<String, Array<Pair<String, size_ut>>>& j : i) {
                SpawningLabel* spl = new SpawningLabel(
                    j.first, static_cast<QScrollArea*>(m_ui->Objects->widget(counter)->children()[1])->widget());
                static_cast<QScrollArea*>(m_ui->Objects->widget(counter)->children()[1])
                    ->widget()
                    ->layout()
                    ->addWidget(spl);
                // static_cast<QScrollArea*>(m_ui->Objects->currentWidget()->children()[1])->layout()->addWidget(spl);
                // ui->mainEditor->layout()->addWidget(spl);
            }
            ++counter;
        }
        {
            InfoType& i{types};
            for (Pair<String, Array<Pair<String, size_ut>>>& j : i) {
                SpawningLabel* spl = new SpawningLabel(
                    j.first, static_cast<QScrollArea*>(m_ui->Objects->widget(counter)->children()[1])->widget());
                static_cast<QScrollArea*>(m_ui->Objects->widget(counter)->children()[1])
                    ->widget()
                    ->layout()
                    ->addWidget(spl);
                // static_cast<QScrollArea*>(m_ui->Objects->currentWidget()->children()[1])->layout()->addWidget(spl);
                // ui->mainEditor->layout()->addWidget(spl);
            }
            ++counter;
        }
        {
            InfoType& i{operators};
            for (Pair<String, Array<Pair<String, size_ut>>>& j : i) {
                SpawningLabel* spl = new SpawningLabel(
                    j.first, static_cast<QScrollArea*>(m_ui->Objects->widget(counter)->children()[1])->widget());
                static_cast<QScrollArea*>(m_ui->Objects->widget(counter)->children()[1])
                    ->widget()
                    ->layout()
                    ->addWidget(spl);
                // static_cast<QScrollArea*>(m_ui->Objects->currentWidget()->children()[1])->layout()->addWidget(spl);
                // ui->mainEditor->layout()->addWidget(spl);
            }
            ++counter;
        }
        {
            InfoType& i{misc};
            for (Pair<String, Array<Pair<String, size_ut>>>& j : i) {
                SpawningLabel* spl = new SpawningLabel(
                    j.first, static_cast<QScrollArea*>(m_ui->Objects->widget(counter)->children()[1])->widget());
                static_cast<QScrollArea*>(m_ui->Objects->widget(counter)->children()[1])
                    ->widget()
                    ->layout()
                    ->addWidget(spl);
                // static_cast<QScrollArea*>(m_ui->Objects->currentWidget()->children()[1])->layout()->addWidget(spl);
                // ui->mainEditor->layout()->addWidget(spl);
            }
            ++counter;
        }
    }
};

class ConnectionHandler {
    Ui::Display* m_ui;
    bool         shift_pressed;
    Component*   first;
    bool         clicked_in;
    // QPainter     painter;

public:
    void handleConnection(QEvent* event) {
        if (event->type() == QEvent::KeyPress) {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Shift) {
                shift_pressed = true;
            }
        }
        else if (event->type() == QEvent::KeyRelease) {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Shift) {
                shift_pressed = false;
            }
        }
        else if (event->type() == QEvent::MouseButtonPress) {
            if (shift_pressed) {
                QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
                if (mouseEvent->button() == Qt::MouseButton::LeftButton) {
                    // Note: this for loop finds the Component that was clicked on.
                    for (QObject* i : m_ui->mainEditor->children()) {
                        Component* comp = static_cast<Component*>(i);
                        if (comp->rect().contains(mouseEvent->pos())) {
                            if (static_cast<QLabel*>(
                                    static_cast<QHBoxLayout*>(comp->layout->children()[0])->children()[0])
                                    ->rect()
                                    .contains(mouseEvent->pos())) {
                                clicked_in = true;
                                first      = comp;
                                break;
                            }
                            else if (static_cast<QLabel*>(
                                         static_cast<QHBoxLayout*>(comp->layout->children()[1])->children()[1])
                                         ->rect()
                                         .contains(mouseEvent->pos())) {
                                clicked_in = false;
                                first      = comp;
                                break;
                            }
                            // if (first == nullptr) {
                            //     first = comp;
                            //     clicked_in = true;
                            // }
                            // else {
                            //     first->connect(comp);
                            //     first = nullptr;
                            //     clicked_in = false;
                            // }
                        }
                    }
                }
            }
            // if (mouseEvent->)
        }
        else if (event->type() == QEvent::MouseButtonRelease) {
            if (first) {
                if (shift_pressed) {
                    QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
                    if (mouseEvent->button() == Qt::MouseButton::LeftButton) {
                        // Note: this for loop finds the Component that was clicked on.
                        for (QObject* i : m_ui->mainEditor->children()) {
                            Component* comp = static_cast<Component*>(i);
                            if (comp->rect().contains(mouseEvent->pos())) {
                                if (static_cast<QLabel*>(
                                        static_cast<QHBoxLayout*>(comp->layout->children()[0])->children()[0])
                                        ->rect()
                                        .contains(mouseEvent->pos())) {
                                    if (!clicked_in) {
                                        comp->setNext(*first);
                                        clicked_in = false;
                                        first      = nullptr;
                                        break;
                                    }
                                    // clicked_in = true;
                                    // first      = comp;
                                }
                                else if (static_cast<QLabel*>(
                                             static_cast<QHBoxLayout*>(comp->layout->children()[1])->children()[1])
                                             ->rect()
                                             .contains(mouseEvent->pos())) {
                                    if (clicked_in) {
                                        first->setNext(*comp);
                                        clicked_in = false;
                                        first      = nullptr;
                                        break;
                                    }
                                }
                                // if (first == nullptr) {
                                //     first = comp;
                                //     clicked_in = true;
                                // }
                                // else {
                                //     first->connect(comp);
                                //     first = nullptr;
                                //     clicked_in = false;
                                // }
                            }
                        }
                    }
                }
            }
            // if (mouseEvent->)
        }
        // QPoint point()
        // m_ui->mainEditor->paintEngine()->drawLines()
        // painter.eraseRect(m_ui->mainEditor->rect());
        // m_ui->mainEditor->repaint();
        // painter.setPen(QPen(Qt::green, 2));
        // for (QObject* i : m_ui->mainEditor->children()) {
        //     Component* comp = static_cast<Component*>(i);
        //     if (comp->next) {
        //         painter.drawLine(
        //             (static_cast<QLabel*>(static_cast<QHBoxLayout*>(comp->layout->children()[0])->children()[0])
        //                  ->pos()),
        //             (static_cast<QLabel*>(static_cast<QHBoxLayout*>(comp->next->layout->children()[1])->children()[1])
        //                  ->pos()));
        //         //
        //         (static_cast<QLabel*>(static_cast<QHBoxLayout*>(comp->layout->children()[0])->children()[0])->pos())
        //         // ->pos();
        //     }
        // }
    }
    ConnectionHandler(Ui::Display* ui) :
        m_ui{ui}, shift_pressed{false}, first{nullptr}, clicked_in{false} /* , painter(ui->mainEditor) */ {
    }
};


class Display : public QMainWindow {
    Q_OBJECT

public:
    Ui::Display*      ui;
    CFile&            m_cfile;
    ScrollAreaHandler handler;
    ObjectInfo        obji;
    ConnectionHandler conh;
    Display(CFile& cfile, QWidget* parent = nullptr);
    ~Display();
    bool eventFilter(QObject* obj, QEvent* event);
};


#endif// DISPLAY_H
