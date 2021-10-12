#ifndef DISPLAY_H
#define DISPLAY_H

#include <QMainWindow>
#include <QPainter>
#include <QPainterPath>
#include <QPushButton>
#include <QVBoxLayout>
#include <stdlib.h>
#include <stdio.h>
#include "utils.h"
#include <QObject>

QT_BEGIN_NAMESPACE
namespace Ui { class Display; }
QT_END_NAMESPACE

struct Color{
    short int rgb_r;
    short int rgb_g;
    short int rgb_b;
};

class Display : public QMainWindow
{
    Q_OBJECT

public:
    Display(QWidget *parent = nullptr);
    ~Display();

    void buttons(const Array<variable>& a, const Array<functions>& b, const Array<operators>& c, const Array<types>& d)
  {
        QPushButton ** functions = malloc(0);
        QPushButton ** varables = malloc(0);
        QPushButton ** types = malloc(0);
        QPushButton ** operators = malloc(0);

        if (a.size() != 0){
        varables = realloc(varables, sizeof(a[0])*(a.size()));
        }

        if (b.size() != 0){
        functions = realloc(functions, sizeof(b[0])*(b.size()));
        }

        if (c.size() != 0){
        types = realloc(types, sizeof(c[0])*(c.size()));
        }

        if (d.size() != 0){
        operators = realloc(operators, sizeof(d[0])*(d.size()));
        }


        for (int i = 0; i < a.size(); ++i) {
        varables[i] = addNewButton(0);
        QObject::connect(varables + i, QPushButton::clicked, nullptr, []()->void{spawn(/*TODO*/);});
        }

        for (int i = 0; i < b.size(); ++i) {
        functions[i] = addNewButton(0);
        QObject::connect(functions + i, QPushButton::clicked, nullptr, []()->void{spawn(/*TODO*/);});
        }

        for (int i = 0; i < c.size(); ++i) {
        types[i] = addNewButton(0);
        QObject::connect(types + i, QPushButton::clicked, nullptr, []()->void{spawn(/*TODO*/);});
        }

        for (int i = 0; i < d.size(); ++i) {
        operators[i] = addNewButton(0);
        QObject::connect(operators + i, QPushButton::clicked, nullptr, []()->void{spawn(/*TODO*/);});
        }


        //for (int i = 0;){

    }

    void spawn(String name, std::size_t id, int type){
        paintEvent()
    }

    QPushButton * addNewButton(short int num){
        QVBoxLayout * lay = new QVBoxLayout(this);
        QPushButton *boton;
        //for (int i = 0; i < num; ++i){
            boton = new QPushButton("this is a button");
            lay ->addWidget(boton);
            //}
            ui ->scrollAreaWidgetContents_2->setLayout(lay);
            return *boton
    }

    // private:
    Ui::Display *ui;
    void Display::paintEvent(QPaintEvent *event);

};


#endif // DISPLAY_H
