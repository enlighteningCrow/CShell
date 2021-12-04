#include "component.h"

QString circle(QChar(0x2E30));
QFont   point_font{};

Component::Component(
    QWidget *parent, const std::string &name, const Array<Pair<String, size_ut>> &cols, const QPoint &location) :
    QGroupBox{QString(name.c_str()), parent},
    layout{new QVBoxLayout(this)} {
    this->setMinimumWidth(6 * name.size());
    this->setLayout(layout);
    ::point_font.setPointSize(30);
    // ::align_left_font.setAli
    // circle.resize(100);
    this->setAutoFillBackground(true);
    this->setPalette(colours);
    for (const auto &i : cols) {
        auto qhbox = new QHBoxLayout();
        auto point = new QLabel(circle, this);
        // auto button1 = new QPushButton(this);
        auto label = new QLabel(QString(i.first.c_str()), this);
        point->setFont(::point_font);
        qhbox->addWidget(point);
        label->setAlignment(Qt::Alignment::enum_type::AlignLeft | Qt::Alignment::enum_type::AlignVCenter);
        qhbox->addWidget(label);
        // QObject::connect(button1, &QPushButton::clicked, [=]() {
        //     ((QMainWindow *)(this->parent()->parent()))->statusBar()->showMessage(QString("This is pressed."));
        // });
        layout->addLayout(qhbox);
    }
    this->move(location);
}