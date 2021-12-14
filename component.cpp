#include <QEvent>
#include <QKeyEvent>
#include <QPushButton>
#include <boost/thread.hpp>

#include "cfile.h"
#include "classifier.h"
#include "component.h"
#include "contactor.h"
#include "utils.h"

#include "display.h"


QString circle(QChar(0x2E30));
QFont   point_font{};

Component::Component(
    QWidget* parent, const std::string& name, const Array<Pair<String, size_ut>>& cols, const QPoint& location) :
    QGroupBox{QString(name.c_str()), parent},
    layout{new QVBoxLayout(this)}, next{nullptr} {
    this->setMinimumWidth(6 * name.size());
    this->setLayout(layout);
    ::point_font.setPointSize(30);
    // ::align_left_font.setAli
    // circle.resize(100);
    this->setAutoFillBackground(true);
    this->setPalette(colours);
    {
        auto qhbox = new QHBoxLayout();
        auto point = new QLabel(circle, this);
        // auto button1 = new QPushButton(this);
        auto label = new QLabel(QString("in"), this);
        point->setFont(::point_font);
        qhbox->addWidget(point);
        label->setAlignment(Qt::Alignment::enum_type::AlignLeft | Qt::Alignment::enum_type::AlignVCenter);
        qhbox->addWidget(label);
        // QObject::connect(button1, &QPushButton::clicked, [=]() {
        //     ((QMainWindow *)(this->parent()->parent()))->statusBar()->showMessage(QString("This is pressed."));
        // });
        layout->addLayout(qhbox);
    }
    {
        auto qhbox = new QHBoxLayout();
        // auto button1 = new QPushButton(this);
        auto label = new QLabel(QString("out"), this);
        auto point = new QLabel(circle, this);
        point->setFont(::point_font);
        label->setAlignment(Qt::Alignment::enum_type::AlignRight | Qt::Alignment::enum_type::AlignVCenter);
        qhbox->addWidget(label);
        qhbox->addWidget(point);
        // QObject::connect(button1, &QPushButton::clicked, [=]() {
        //     ((QMainWindow *)(this->parent()->parent()))->statusBar()->showMessage(QString("This is pressed."));
        // });
        layout->addLayout(qhbox);
    }
    // for (const Pair<String, size_ut>& i : cols) {
    //     auto qhbox = new QHBoxLayout();
    //     auto point = new QLabel(circle, this);
    //     // auto button1 = new QPushButton(this);
    //     auto label = new QLabel(QString(i.first.cStr().get()), this);
    //     point->setFont(::point_font);
    //     qhbox->addWidget(point);
    //     label->setAlignment(Qt::Alignment::enum_type::AlignLeft | Qt::Alignment::enum_type::AlignVCenter);
    //     qhbox->addWidget(label);
    //     // QObject::connect(button1, &QPushButton::clicked, [=]() {
    //     //     ((QMainWindow *)(this->parent()->parent()))->statusBar()->showMessage(QString("This is pressed."));
    //     // });
    //     layout->addLayout(qhbox);
    // }
    this->move(location);
}


Component& Component::setNext(Component& next) {
    this->next = &next;
}


// TODO: finish this;
// Make a starting point, which is not used at all: (void); only used to mark
// std::list<Component*> coponentList{new Component()};