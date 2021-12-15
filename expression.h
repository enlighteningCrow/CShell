#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "classifier.h"

using namespace Classifier;

// Note: casp stands for check_all_simple_precedence
bool checkAllSimplePrecedence(const Expression& exp, short int precedence);

void transformPrecedences(Expression& expr);

#endif// EXPRESSION_H