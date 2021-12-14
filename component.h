#include <QGroupBox>
#include <QLabel>
#include <QLayout>

#include "classifier.h"
#include "contactor.h"
#include "utils.h"

typedef long long int size_ut;

// TODO: Make the below into a linked list

class Component : public QGroupBox {
public:
    QVBoxLayout*                            layout;
    QPalette                                colours{Qt::white};
    std::shared_ptr<Classifier::Expression> expr;
    // Component
    Component(
        QWidget* parent, const std::string& name, const Array<Pair<String, size_ut>>& cols, const QPoint& location);
};

extern std::list<Component> coponentList;