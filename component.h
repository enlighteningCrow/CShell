#ifndef COMPONENT_H
#define COMPONENT_H

#include <QGroupBox>
#include <QLabel>
#include <QLayout>

#include "classifier.h"
#include "contactor.h"
#include "utils.h"

typedef long long int size_ut;

// This class emulates a linked list; the struct Iter provides capabilities for this to act as a linked list of
// Expressions
class Component : public QGroupBox {
public:
    QVBoxLayout*                            layout;
    QPalette                                colours{Qt::white};
    std::shared_ptr<Classifier::Expression> expr;
    Component(
        QWidget* parent, const std::string& name, const Array<Pair<String, size_ut>>& cols, const QPoint& location);
    Component*                    next;
    Component&                    setNext(Component& next);
    Array<Classifier::Expression> makeArray() const;

    // Note: It points to shared_ptrs, not Expressions
    struct Iter {
    public:
        using value_type        = Classifier::Expression;
        using pointer           = value_type*;
        using reference         = value_type&;
        using iterator_category = std::random_access_iterator_tag;
        using difference_type   = std::ptrdiff_t;

    protected:
        pointer    m_ptr;
        Component* actual_ptr;

    public:
        reference operator*() const {
            return *m_ptr;
        }
        pointer operator->() const {
            return m_ptr;
        }
        Iter& operator++() {
            m_ptr = actual_ptr->next->expr.get();
            return *this;
        }
        Iter operator++(int) {
            Iter tmp{actual_ptr};
            m_ptr = actual_ptr->next->expr.get();
            return tmp;
        }
        friend bool operator==(const Iter& a, const Iter& b) {
            return a.m_ptr == b.m_ptr;
        };
        friend bool operator!=(const Iter& a, const Iter& b) {
            return a.m_ptr != b.m_ptr;
        };
        Iter(Component* ptr) : m_ptr{ptr->expr.get()}, actual_ptr{ptr} {
        }
        Iter(Component& ptr) : m_ptr{ptr.expr.get()}, actual_ptr{&ptr} {
        }
        Iter(const Iter& ptr) : m_ptr{ptr.m_ptr} {
        }
    };
};

#endif// COMPONENT_H