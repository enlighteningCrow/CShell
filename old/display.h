#ifndef DISPLAY_H
#define DISPLAY_H

#include <QMainWindow>
#include <QObject>
#include <QPainter>
#include <QPainterPath>
#include <QPushButton>
#include <QVBoxLayout>
#include <stdio.h>
#include <stdlib.h>
#include "./ui_display.h"
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
class Display : public QMainWindow {
    Q_OBJECT

public:
    Display(QWidget *parent = nullptr);
    ~Display();
    bool         eventFilter(QObject *obj, QEvent *event);
    Ui::Display *ui;
};


#endif // DISPLAY_H
