#include "expression.h"
#include "classifier.h"

bool checkAllSimplePrecedence(const Classifier::Expression& exp, short int precedence) {
    bool found_precedence{false};
    for (size_t i{0}; i < exp.subs.size(); ++i) {
        if (exp.isExpression(i)) {
            if (!checkAllSimplePrecedence(*exp.indexAsExp(i), precedence))
                return false;
        }
        else {
            for (std::size_t i{0}; i < exp.size(); ++i) {
                for (const auto& j : exp.indexAsStr(i).second) {
                    if ((j.first & Classifier::STypes::LITERAL) || (j.first & Classifier::STypes::NAME)) {
                        continue;
                    }
                    else if (j.first & Classifier::STypes::OPERATOR) {
                        if (j.second == precedence) {
                            found_precedence = true;
                            continue;
                        }
                        else {
                            return false;
                        }
                    }
                    else {
                        return false;
                    }
                }
            }
        }
    }
    return found_precedence;
}

void transformPrecedences(Classifier::Expression& expr) {
    if (expr.subs.size() < 3)
        return;
    if (expr.subs[-2].second)
        return;
    if (!(expr.subs[-3].second))
        return;
    if ((*(expr.subs[-3].first.ex)).size() != 3)
        return;
    if ((*(expr.subs[-3].first.ex)).subs[2].second)
        return;
    size_ut precedence_found{0LL};
    for (const Pair<size_ut, size_ut>& i : (*(expr.subs[-3].first.ex))[2].str.second) {
        switch (i.second) {
        case 0:
            continue;
        case 2:
        case 14:
            precedence_found = i.second;
            break;
        default:
            return;
        }
        break;
    }
    if (!precedence_found)
        return;

    size_ut precedence_found1{0LL};
    for (const Pair<size_ut, size_ut>& i : expr[-3].str.second) {
        switch (i.second) {
        case 0:
            continue;
        case 2:
        case 14:
            precedence_found1 = i.second;
            break;
        default:
            return;
        }
        break;
    }

    if (precedence_found != precedence_found1) {
        return;
    }

    Pair<Classifier::Expression::ExpressionStr, bool>::swap(expr.subs[-1], expr.subs[-3]);
    Pair<Classifier::Expression::ExpressionStr, bool>::swap(
        expr.subs[-1].first.ex->subs[-1], expr.subs[-1].first.ex->subs[-3]);
    Pair<Classifier::Expression::ExpressionStr, bool>::swap(expr.subs[-1].first.ex->subs[-1], expr.subs[-3]);
    return;
}