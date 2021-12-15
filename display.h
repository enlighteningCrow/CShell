#ifndef DISPLAY_H
#define DISPLAY_H

#include <QEvent>
#include <QFrame>
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
    ScrollAreaHandler() :
        m_currently_pressed{false}, m_current_button_is_right{false}, m_ui{nullptr}, m_scr{nullptr}, m_selected{},
        m_previous_mouse_pos{0, 0}, m_previous_mouse_click_pos{0, 0}, m_passed_threshold{false}, threshold{15},
        is_in_select_mode{false}, is_in_move_mode{false} {
    }
    void setUi(Ui::Display* ui) {
        m_ui = ui;
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
        // // TODO: Look out for when the m_ui (for not only this class) is not yet initialized.
        m_scr = m_ui->mainEditor;
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
                            }
                            else {
                                is_in_move_mode = true;
                            }
                        }
                    }
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

class SpawningLabel : public QFrame {
protected:
    QLabel*                                    m_label;
    Pair<String, Array<Pair<String, size_ut>>> m_data;

public:
    SpawningLabel(String str, QWidget* wid) :
        QFrame(wid), m_label{new QLabel(QString(str.cStr().get()), this)}, m_data{} {
        auto* i = new QVBoxLayout{this};
        i->addWidget(m_label);
    }
    SpawningLabel(QString str, QWidget* wid) : QFrame(wid), m_label(new QLabel(str, this)), m_data{} {
        auto* i = new QVBoxLayout{this};
        i->addWidget(m_label);
    }
    SpawningLabel(String str) : QFrame(), m_label(new QLabel(QString(str.cStr().get()), this)), m_data{} {
        auto* i = new QVBoxLayout{this};
        i->addWidget(m_label);
    }
    SpawningLabel(QString str) : QFrame(), m_label(new QLabel(str, this)), m_data{} {
        auto* i = new QVBoxLayout{this};
        i->addWidget(m_label);
    }
    friend class ObjectInfo;
};

class ObjectInfo {
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
    Ui::Display*                                              m_ui;

    InfoType variables;
    InfoType functions;
    InfoType types;
    InfoType operators;
    InfoType misc;

    QTabWidget* tabs;

    bool           is_pressed;
    SpawningLabel* currently_pressed;

public:
    ObjectInfo(CFile& cfile) :
        is_pressed{false}, m_ui{nullptr}, tabs{nullptr}, currently_pressed{

                                                             nullptr} {
        for (auto& i : Classifier::key_expressions_const) {
            if ((i.second[0].first & Classifier::STypes::TYPE) ||
                (i.second[0].first & Classifier::STypes::TYPE_MODIFIER)) {
                types.push_back(Pair<String, Array<Pair<String, size_ut>>>(i.first, 0 /* i.second[0].first */));
            }
            else if ((i.second[0].first & Classifier::STypes::OPERATOR)) {
                for (std::size_t j{0}; j < i.second.size(); ++j) {
                    operators.push_back(Pair<String, Array<Pair<String, size_ut>>>(i.first, 2));
                }
            }
            else {
                misc.push_back(Pair<String, Array<Pair<String, size_ut>>>(i.first, 0));
            }
        }
        variables = cfile.all;
        functions = cfile.functions;
    }
    void setUi(Ui::Display* ui) {
        m_ui = ui;
        tabs = ui->Objects;
    }
    void spawnComponent(SpawningLabel& label, const QPoint& pos) {
        QLabel* label_9;
        label_9 = new QLabel(m_ui->mainEditorW);
        label_9->setObjectName(QString("label_9"));
        label_9->setGeometry(QRect(30, -30, 861, 101));
        label_9->setText(QCoreApplication::translate("Display", "Hellos, Hellos, Hellos, Hellos", nullptr));
    }
    void handleInput(QEvent& event) {
        if (!is_pressed) {
            if (event.type() == QEvent::MouseButtonPress) {
                for (auto& i :
                     static_cast<QScrollArea*>(m_ui->Objects->currentWidget()->children()[1])->widget()->children()) {
                    std::cout << i->objectName().toStdString() << std::endl;
                    std::string name = i->objectName().toStdString();
                    if (name[name.size() - 1] == 'L')
                        continue;
                    SpawningLabel& wid = *(static_cast<SpawningLabel*>(i));

                    if (wid.frameRect().contains(static_cast<QMouseEvent*>(&event)->pos())) {
                        is_pressed        = true;
                        currently_pressed = &wid;
                        break;
                    }
                }
            }
        }
        else {
            if (event.type() == QEvent::MouseButtonRelease) {
                if (is_pressed && currently_pressed) {
                    is_pressed = false;
                    if (m_ui->mainEditor->rect().contains(static_cast<QMouseEvent*>(&event)->pos())) {
                        spawnComponent(*currently_pressed, static_cast<QMouseEvent*>(&event)->pos());
                    }
                    currently_pressed = nullptr;
                }
            }
        }
    }

    void populateSpawningLabels() {
        std::size_t counter{0};
        {
            InfoType& i{variables};
            for (Pair<String, Array<Pair<String, size_ut>>>& j : i) {
                SpawningLabel* spl = new SpawningLabel(
                    j.first, static_cast<QScrollArea*>(m_ui->Objects->widget(counter)->children()[1])->widget());
                spl->setObjectName(QString(j.first.cStr().get()));
                static_cast<QScrollArea*>(m_ui->Objects->widget(counter)->children()[1])
                    ->widget()
                    ->layout()
                    ->addWidget(spl);
            }
            ++counter;
        }
        {
            InfoType& i{functions};
            for (Pair<String, Array<Pair<String, size_ut>>>& j : i) {
                SpawningLabel* spl = new SpawningLabel(
                    j.first, static_cast<QScrollArea*>(m_ui->Objects->widget(counter)->children()[1])->widget());
                spl->setObjectName(QString(j.first.cStr().get()));
                static_cast<QScrollArea*>(m_ui->Objects->widget(counter)->children()[1])
                    ->widget()
                    ->layout()
                    ->addWidget(spl);
            }
            ++counter;
        }
        {
            InfoType& i{types};
            for (Pair<String, Array<Pair<String, size_ut>>>& j : i) {
                SpawningLabel* spl = new SpawningLabel(
                    j.first, static_cast<QScrollArea*>(m_ui->Objects->widget(counter)->children()[1])->widget());
                spl->setObjectName(QString(j.first.cStr().get()));
                static_cast<QScrollArea*>(m_ui->Objects->widget(counter)->children()[1])
                    ->widget()
                    ->layout()
                    ->addWidget(spl);
            }
            ++counter;
        }
        {
            InfoType& i{operators};
            for (Pair<String, Array<Pair<String, size_ut>>>& j : i) {
                SpawningLabel* spl = new SpawningLabel(
                    j.first, static_cast<QScrollArea*>(m_ui->Objects->widget(counter)->children()[1])->widget());
                spl->setObjectName(QString(j.first.cStr().get()));
                static_cast<QScrollArea*>(m_ui->Objects->widget(counter)->children()[1])
                    ->widget()
                    ->layout()
                    ->addWidget(spl);
            }
            ++counter;
        }
        {
            InfoType& i{misc};
            for (Pair<String, Array<Pair<String, size_ut>>>& j : i) {
                SpawningLabel* spl = new SpawningLabel(
                    j.first, static_cast<QScrollArea*>(m_ui->Objects->widget(counter)->children()[1])->widget());
                spl->setObjectName(QString(j.first.cStr().get()));
                static_cast<QScrollArea*>(m_ui->Objects->widget(counter)->children()[1])
                    ->widget()
                    ->layout()
                    ->addWidget(spl);
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
                        }
                    }
                }
            }
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
                            }
                        }
                    }
                }
            }
        }
    }
    ConnectionHandler() : m_ui{nullptr}, shift_pressed{false}, first{nullptr}, clicked_in{false} {
    }
    void setUi(Ui::Display* ui) {
        m_ui = ui;
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
