#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "classifier.h"

// Note: casp stands for check_all_simple_precedence
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
                        // TODO: Check for the precedence level here, if true then carry on. If false then exit
                        // immediately by return false.
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
            ExpressionType;
            // TODO: Find whether
        }
        // found_precedence = // TODO: check this
    }
    return found_precedence;
}

// void swap(ExpressionStr Classifier::Ex)

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
            // break;
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
    // return;


    size_ut precedence_found1{0LL};
    for (const Pair<size_ut, size_ut>& i : expr[-3].str.second) {
        switch (i.second) {
        case 0:
            continue;
            // break;
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

    swap(expr.subs[-1], expr.subs[-3]);
    swap(expr.subs[-1].first.ex->subs[-1], expr.subs[-1].first.ex->subs[-3]);
    swap(expr.subs[-1].first.ex->subs[-1], expr.subs[-3]);
    return;


    // expr.subs


    // TODO: Do the swapping here. Checking is done.
    // expr[-1] = expr[]


    // if (expr[-2].)
}

// bool checkAllSimplePrecedence(
//     const Classifier::Expression::ExpressionStr& expstr, bool isExpression, short int precedence) {
//     if (isExpression) {
//         Classifier::Expression& exp = *(expstr.ex);
//         bool                    found_precedence{false};
//         for (size_t i{0}; i < exp.subs.size(); ++i) {
//             if (exp.isExpression(i)) {
//                 if (!checkAllSimplePrecedence(*exp.indexAsExp(i), precedence))
//                     return false;
//             }
//             else {
//                 for (std::size_t i{0}; i < exp.size(); ++i) {
//                     for (const auto& j : exp.indexAsStr(i).second) {
//                         if ((j.first & Classifier::STypes::LITERAL) || (j.first & Classifier::STypes::NAME))
//                         {
//                             continue;
//                         }
//                         else if (j.first & Classifier::STypes::OPERATOR) {
//                             // TODO: Check for the precedence level here, if true then carry on. If false
//                             then exit
//                             // immediately by return false.
//                             if (j.second == precedence) {
//                                 found_precedence = true;
//                                 continue;
//                             }
//                             else {
//                                 return false;
//                             }
//                         }
//                         else {
//                             return false;
//                         }
//                     }
//                 }
//                 ExpressionType;
//                 // TODO: Find whether
//             }
//             // found_precedence = // TODO: check this
//         }
//         return found_precedence;
//     }

// }

#endif