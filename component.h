#include <QGroupBox>
#include <QLabel>
#include <QLayout>

#include "classifier.h"
#include "contactor.h"
#include "utils.h"

typedef long long int size_ut;

class Component : public QGroupBox {
public:
    QVBoxLayout* layout;
    QPalette     colours{Qt::white};
    Component(
        QWidget* parent, const std::string& name, const Array<Pair<String, size_ut>>& cols, const QPoint& location);
};