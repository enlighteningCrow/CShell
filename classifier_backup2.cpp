#include "classifier.h"
#include <bits/stdc++.h>
#include "cfile.h"
#include "expression.h"


// int main_process() {
//     Scope global{};
//     global.
// }

namespace Classifier {

    Array<Pair<Array<Pair<Array<size_ut>, size_ut>>, Pair<size_ut, size_ut>>> statement_types_arrays{
        Pair<Array<Pair<Array<size_ut>, size_ut>>, Pair<size_ut, size_ut>>{
            {// Type name
             Pair<Array<size_ut>, size_ut>{{STypes::TYPE_MODIFIER}, STypes::MULTIPLE | STypes::OPTIONAL},
             Pair<Array<size_ut>, size_ut>{{STypes::STRUCT | STypes::ENUM | STypes::UNION}, STypes::OPTIONAL},
             Pair<Array<size_ut>, size_ut>{{STypes::NAME}, STypes::NONE},
             Pair<Array<size_ut>, size_ut>{
                 {STypes::AMPERSAND | STypes::ASTERISK}, STypes::OPTIONAL | STypes::MULTIPLE}},
            Pair<size_ut, size_ut>(STypes::TYPE, 25)},

        Pair<Array<Pair<Array<size_ut>, size_ut>>, Pair<size_ut, size_ut>>{
            {
                // Function Call
                Pair<Array<size_ut>, size_ut>{{STypes::NAME}, STypes::NONE},
                Pair<Array<size_ut>, size_ut>{{STypes::PARENTHESIS}, STypes::OPEN},
                Pair<Array<size_ut>, size_ut>{{STypes::NAME | STypes::LITERAL}, STypes::OPTIONAL},
                Pair<Array<size_ut>, size_ut>{
                    {STypes::COMMA, STypes::NAME | STypes::LITERAL}, STypes::MULTIPLE | STypes::OPTIONAL},
                Pair<Array<size_ut>, size_ut>{{STypes::PARENTHESIS}, STypes::CLOSE},
            },
            Pair<size_ut, size_ut>(STypes::LITERAL | STypes::NAME, 24)},
        Pair<Array<Pair<Array<size_ut>, size_ut>>, Pair<size_ut, size_ut>>{
            {
                // Dereferencing/Address operator
                Pair<Array<size_ut>, size_ut>{
                    {STypes::AMPERSAND | STypes::ASTERISK}, /* STypes::OPTIONAL |  */ STypes::MULTIPLE},
                Pair<Array<size_ut>, size_ut>{{STypes::NAME}, STypes::NONE},
            },
            Pair<size_ut, size_ut>(STypes::LITERAL | STypes::NAME, 23)},
        Pair<Array<Pair<Array<size_ut>, size_ut>>, Pair<size_ut, size_ut>>{
            {// Casting statement
             Pair<Array<size_ut>, size_ut>{{STypes::PARENTHESIS}, STypes::OPEN},
             Pair<Array<size_ut>, size_ut>{{STypes::TYPE_MODIFIER}, STypes::MULTIPLE | STypes::OPTIONAL},
             Pair<Array<size_ut>, size_ut>{{STypes::TYPE}, STypes::NONE},
             Pair<Array<size_ut>, size_ut>{{STypes::PARENTHESIS}, STypes::CLOSE},
             Pair<Array<size_ut>, size_ut>{{STypes::NAME | STypes::LITERAL}, STypes::NONE}},
            Pair<size_ut, size_ut>(STypes::LITERAL | STypes::NAME, 22)},
        Pair<Array<Pair<Array<size_ut>, size_ut>>, Pair<size_ut, size_ut>>{
            {// Type-call statement
             Pair<Array<size_ut>, size_ut>{{STypes::TYPE_MODIFIER}, STypes::MULTIPLE | STypes::OPTIONAL},
             Pair<Array<size_ut>, size_ut>{{STypes::TYPE}, STypes::NONE},
             Pair<Array<size_ut>, size_ut>{{STypes::PARENTHESIS}, STypes::OPEN},
             Pair<Array<size_ut>, size_ut>{{STypes::NAME | STypes::LITERAL}, STypes::OPTIONAL},
             Pair<Array<size_ut>, size_ut>{{STypes::PARENTHESIS}, STypes::CLOSE}},
            Pair<size_ut, size_ut>(STypes::LITERAL | STypes::NAME, 21)},
        Pair<Array<Pair<Array<size_ut>, size_ut>>, Pair<size_ut, size_ut>>{
            {// Operator both
             Pair<Array<size_ut>, size_ut>{{STypes::NAME | STypes::LITERAL}, STypes::NONE},
             Pair<Array<size_ut>, size_ut>{{STypes::OPERATOR}, STypes::BOTH},
             Pair<Array<size_ut>, size_ut>{{STypes::NAME | STypes::LITERAL}, STypes::NONE}},
            Pair<size_ut, size_ut>(STypes::LITERAL | STypes::NAME, 20)},
        Pair<Array<Pair<Array<size_ut>, size_ut>>, Pair<size_ut, size_ut>>{
            {// Operator prefix
             Pair<Array<size_ut>, size_ut>{{STypes::OPERATOR}, STypes::PREFIX},
             Pair<Array<size_ut>, size_ut>{{STypes::NAME | STypes::LITERAL}, STypes::NONE}},
            Pair<size_ut, size_ut>(STypes::LITERAL | STypes::NAME, 19)},
        Pair<Array<Pair<Array<size_ut>, size_ut>>, Pair<size_ut, size_ut>>{
            {// Operator postfix
             Pair<Array<size_ut>, size_ut>{{STypes::NAME | STypes::LITERAL}, STypes::NONE},
             Pair<Array<size_ut>, size_ut>{{STypes::OPERATOR}, STypes::PREFIX}},
            Pair<size_ut, size_ut>(STypes::LITERAL | STypes::NAME, 18)},
        Pair<Array<Pair<Array<size_ut>, size_ut>>, Pair<size_ut, size_ut>>{
            {// Reference/Pointer prefix
             Pair<Array<size_ut>, size_ut>{{STypes::ASTERISK | STypes::AMPERSAND}, STypes::NONE},
             Pair<Array<size_ut>, size_ut>{{STypes::NAME}, STypes::NONE}},
            Pair<size_ut, size_ut>(STypes::LITERAL | STypes::NAME, 17)},
        Pair<Array<Pair<Array<size_ut>, size_ut>>, Pair<size_ut, size_ut>>{
            {
                // Initializer list
                Pair<Array<size_ut>, size_ut>{{STypes::CURLY_BRACE}, STypes::OPEN},
                Pair<Array<size_ut>, size_ut>{{STypes::LITERAL}, STypes::OPTIONAL},
                Pair<Array<size_ut>, size_ut>{{STypes::COMMA, STypes::LITERAL}, STypes::MULTIPLE | STypes::OPTIONAL},
                Pair<Array<size_ut>, size_ut>{{STypes::CURLY_BRACE}, STypes::CLOSE},
            },
            Pair<size_ut, size_ut>(STypes::LITERAL, 16)},

        Pair<Array<Pair<Array<size_ut>, size_ut>>, Pair<size_ut, size_ut>>{
            {// Function Declaration
             Pair<Array<size_ut>, size_ut>{{STypes::TYPE}, STypes::NONE},
             Pair<Array<size_ut>, size_ut>{{STypes::NAME}, STypes::NONE},
             Pair<Array<size_ut>, size_ut>{{STypes::PARENTHESIS}, STypes::OPEN},
             Pair<Array<size_ut>, size_ut>{{STypes::TYPE, STypes::NAME}, STypes::OPTIONAL},
             Pair<Array<size_ut>, size_ut>{
                 {STypes::COMMA, STypes::TYPE, STypes::NAME}, STypes::MULTIPLE | STypes::OPTIONAL},
             Pair<Array<size_ut>, size_ut>{{STypes::PARENTHESIS}, STypes::CLOSE},
             Pair<Array<size_ut>, size_ut>{{STypes::SEMICOLON}, STypes::NONE}},
            Pair<size_ut, size_ut>(STypes::STATEMENT, 7)},
        Pair<Array<Pair<Array<size_ut>, size_ut>>, Pair<size_ut, size_ut>>{
            {// Function Definition
             Pair<Array<size_ut>, size_ut>{{STypes::TYPE}, STypes::NONE},
             Pair<Array<size_ut>, size_ut>{{STypes::NAME}, STypes::NONE},
             Pair<Array<size_ut>, size_ut>{{STypes::PARENTHESIS}, STypes::OPEN},
             Pair<Array<size_ut>, size_ut>{{STypes::TYPE, STypes::NAME}, STypes::OPTIONAL},
             Pair<Array<size_ut>, size_ut>{
                 {STypes::COMMA, STypes::TYPE, STypes::NAME}, STypes::MULTIPLE | STypes::OPTIONAL},
             Pair<Array<size_ut>, size_ut>{{STypes::PARENTHESIS}, STypes::CLOSE},
             Pair<Array<size_ut>, size_ut>{{STypes::CURLY_BRACE}, STypes::OPEN},
             Pair<Array<size_ut>, size_ut>{{STypes::STATEMENT}, STypes::OPTIONAL | STypes::MULTIPLE},
             Pair<Array<size_ut>, size_ut>{{STypes::CURLY_BRACE}, STypes::CLOSE}},
            Pair<size_ut, size_ut>(STypes::STATEMENT, 6)},
        Pair<Array<Pair<Array<size_ut>, size_ut>>, Pair<size_ut, size_ut>>{
            {// Parentheses
             Pair<Array<size_ut>, size_ut>{{STypes::PARENTHESIS}, STypes::OPEN},
             Pair<Array<size_ut>, size_ut>{{STypes::LITERAL | STypes::NAME}, STypes::NONE},
             Pair<Array<size_ut>, size_ut>{{STypes::PARENTHESIS}, STypes::CLOSE}},
            Pair<size_ut, size_ut>(STypes::LITERAL | STypes::NAME, 5)},
        Pair<Array<Pair<Array<size_ut>, size_ut>>, Pair<size_ut, size_ut>>{
            {// Variable Declaration array
             Pair<Array<size_ut>, size_ut>{{STypes::TYPE}, STypes::NONE},
             Pair<Array<size_ut>, size_ut>{{STypes::NAME}, STypes::NONE},
             Pair<Array<size_ut>, size_ut>{{STypes::BRACE}, STypes::OPEN},
             Pair<Array<size_ut>, size_ut>{{STypes::LITERAL | STypes::NAME}, STypes::NONE},
             Pair<Array<size_ut>, size_ut>{{STypes::BRACE}, STypes::CLOSE},
             Pair<Array<size_ut>, size_ut>{{STypes::SEMICOLON}, STypes::NONE}},
            Pair<size_ut, size_ut>(STypes::STATEMENT, 4)},
        Pair<Array<Pair<Array<size_ut>, size_ut>>, Pair<size_ut, size_ut>>{
            {// Variable Declaration array with initialization
             Pair<Array<size_ut>, size_ut>{{STypes::TYPE}, STypes::NONE},
             Pair<Array<size_ut>, size_ut>{{STypes::NAME}, STypes::NONE},
             Pair<Array<size_ut>, size_ut>{{STypes::BRACE}, STypes::OPEN},
             Pair<Array<size_ut>, size_ut>{{STypes::LITERAL | STypes::NAME}, STypes::NONE},
             Pair<Array<size_ut>, size_ut>{{STypes::BRACE}, STypes::CLOSE},
             Pair<Array<size_ut>, size_ut>{{STypes::ASSIGNMENT}, STypes::NONE},
             Pair<Array<size_ut>, size_ut>{{STypes::LITERAL | STypes::NAME}, STypes::NONE},
             Pair<Array<size_ut>, size_ut>{{STypes::SEMICOLON}, STypes::NONE}},
            Pair<size_ut, size_ut>(STypes::STATEMENT, 3)},
        Pair<Array<Pair<Array<size_ut>, size_ut>>, Pair<size_ut, size_ut>>{
            {// Variable Declaration
             Pair<Array<size_ut>, size_ut>{{STypes::TYPE}, STypes::NONE},
             Pair<Array<size_ut>, size_ut>{{STypes::NAME}, STypes::NONE},
             Pair<Array<size_ut>, size_ut>{{STypes::COMMA, STypes::NAME}, STypes::NONE},
             Pair<Array<size_ut>, size_ut>{{STypes::SEMICOLON}, STypes::NONE}},
            Pair<size_ut, size_ut>(STypes::STATEMENT, 2)},
        Pair<Array<Pair<Array<size_ut>, size_ut>>, Pair<size_ut, size_ut>>{
            {// Variable Declaration with initialization
             Pair<Array<size_ut>, size_ut>{{STypes::TYPE}, STypes::NONE},
             Pair<Array<size_ut>, size_ut>{{STypes::NAME}, STypes::NONE},
             Pair<Array<size_ut>, size_ut>{{STypes::ASSIGNMENT}, STypes::NONE},
             Pair<Array<size_ut>, size_ut>{{STypes::LITERAL | STypes::NAME}, STypes::NONE},
             Pair<Array<size_ut>, size_ut>{{STypes::SEMICOLON}, STypes::NONE}},
            Pair<size_ut, size_ut>(STypes::STATEMENT, 1)},
        Pair<Array<Pair<Array<size_ut>, size_ut>>, Pair<size_ut, size_ut>>{
            {// Blank statement
             //  Pair<Array<size_ut>, size_ut>{{STypes::NAME | STypes::LITERAL}, STypes::NONE},
             Pair<Array<size_ut>, size_ut>{{STypes::NAME | STypes::LITERAL}, STypes::OPTIONAL},
             Pair<Array<size_ut>, size_ut>{{STypes::SEMICOLON}, STypes::NONE}},
            Pair<size_ut, size_ut>(STypes::STATEMENT, 0)}};

    Array<Pair<Array<size_ut>, Pair<size_ut, size_ut>>> statement_types{
        Pair<Array<size_ut>, Pair<size_ut, size_ut>>{
            {// Type name
             STypes::STRUCT | STypes::ENUM | STypes::UNION, STypes::NAME},
            Pair<size_ut, size_ut>(STypes::TYPE, 25)},
        Pair<Array<size_ut>, Pair<size_ut, size_ut>>{
            {
                // Function Call
                STypes::NAME,
                STypes::PARENTHESIS | STypes::OPEN,
                STypes::NAME | STypes::LITERAL | STypes::OPTIONAL,
                STypes::COMMA | STypes::NAME | STypes::LITERAL | STypes::MULTIPLE | STypes::OPTIONAL,
                STypes::PARENTHESIS | STypes::CLOSE,
            },
            Pair<size_ut, size_ut>(-1, 24)},
        Pair<Array<size_ut>, Pair<size_ut, size_ut>>{
            {// Parentheses
             STypes::PARENTHESIS | STypes::OPEN, STypes::LITERAL | STypes::NAME, STypes::PARENTHESIS | STypes::CLOSE},
            Pair<size_ut, size_ut>(-1, 23)},
        Pair<Array<size_ut>, Pair<size_ut, size_ut>>{
            {// Casting statement
             STypes::PARENTHESIS | STypes::OPEN, STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL,
             STypes::TYPE, STypes::PARENTHESIS | STypes::CLOSE, STypes::NAME | STypes::LITERAL},
            Pair<size_ut, size_ut>(-1, 22)},
        Pair<Array<size_ut>, Pair<size_ut, size_ut>>{
            {// Type-call statement
             STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL, STypes::TYPE,
             STypes::PARENTHESIS | STypes::OPEN, STypes::NAME | STypes::LITERAL | STypes::OPTIONAL,
             STypes::PARENTHESIS | STypes::CLOSE},
            Pair<size_ut, size_ut>(-1, 21)},
        Pair<Array<size_ut>, Pair<size_ut, size_ut>>{
            {// Operator both
             STypes::NAME | STypes::LITERAL, STypes::OPERATOR | STypes::BOTH, STypes::NAME | STypes::LITERAL},
            Pair<size_ut, size_ut>(-1, 20)},
        Pair<Array<size_ut>, Pair<size_ut, size_ut>>{
            {// Operator prefix
             STypes::OPERATOR | STypes::PREFIX, STypes::NAME | STypes::LITERAL},
            Pair<size_ut, size_ut>(-1, 19)},
        Pair<Array<size_ut>, Pair<size_ut, size_ut>>{
            {// Operator postfix
             STypes::NAME | STypes::LITERAL, STypes::OPERATOR | STypes::PREFIX},
            Pair<size_ut, size_ut>(-1, 18)},
        Pair<Array<size_ut>, Pair<size_ut, size_ut>>{
            {
                // Initializer list
                STypes::CURLY_BRACE | STypes::OPEN,
                STypes::LITERAL | STypes::MULTIPLE | STypes::OPTIONAL,
                STypes::COMMA | STypes::LITERAL | STypes::MULTIPLE | STypes::OPTIONAL,
                STypes::CURLY_BRACE | STypes::CLOSE,
            },
            Pair<size_ut, size_ut>(STypes::LITERAL, 16)},
        Pair<Array<size_ut>, Pair<size_ut, size_ut>>{
            {// Function Declaration
             STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL, STypes::TYPE,
             STypes::ASTERISK_OR_AMPERSAND | STypes::MULTIPLE, STypes::NAME, STypes::PARENTHESIS | STypes::OPEN,
             STypes::TYPE | STypes::NAME | STypes::OPTIONAL,
             STypes::COMMA | STypes::TYPE | STypes::NAME | STypes::MULTIPLE | STypes::OPTIONAL,
             STypes::PARENTHESIS | STypes::CLOSE, STypes::SEMICOLON},
            Pair<size_ut, size_ut>(STypes::NONE, 7)},
        Pair<Array<size_ut>, Pair<size_ut, size_ut>>{
            {// Function Definition
             STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL, STypes::TYPE,
             STypes::ASTERISK_OR_AMPERSAND | STypes::MULTIPLE, STypes::NAME, STypes::PARENTHESIS | STypes::OPEN,
             STypes::TYPE | STypes::NAME | STypes::OPTIONAL,
             STypes::COMMA | STypes::TYPE | STypes::NAME | STypes::MULTIPLE | STypes::OPTIONAL,
             STypes::PARENTHESIS | STypes::CLOSE, STypes::CURLY_BRACE | STypes::OPEN,
             STypes::STATEMENT | STypes::OPTIONAL | STypes::MULTIPLE, STypes::CURLY_BRACE | STypes::CLOSE},
            Pair<size_ut, size_ut>(STypes::NONE, 6)},
        Pair<Array<size_ut>, Pair<size_ut, size_ut>>{
            {// Variable Declaration array
             STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL, STypes::TYPE,
             STypes::ASTERISK_OR_AMPERSAND | STypes::MULTIPLE, STypes::NAME, STypes::BRACE | STypes::OPEN,
             STypes::LITERAL | STypes::NAME, STypes::BRACE | STypes::CLOSE, STypes::SEMICOLON},
            Pair<size_ut, size_ut>(STypes::NONE, 4)},
        Pair<Array<size_ut>, Pair<size_ut, size_ut>>{
            {// Variable Declaration array with initialization
             STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL, STypes::TYPE,
             STypes::ASTERISK_OR_AMPERSAND | STypes::MULTIPLE, STypes::NAME, STypes::BRACE | STypes::OPEN,
             STypes::LITERAL | STypes::NAME, STypes::BRACE | STypes::CLOSE, STypes::ASSIGNMENT,
             STypes::LITERAL | STypes::NAME, STypes::SEMICOLON},
            Pair<size_ut, size_ut>(STypes::NONE, 3)},
        Pair<Array<size_ut>, Pair<size_ut, size_ut>>{
            {// Variable Declaration
             STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL, STypes::TYPE,
             STypes::ASTERISK_OR_AMPERSAND | STypes::MULTIPLE, STypes::NAME, STypes::SEMICOLON},
            Pair<size_ut, size_ut>(STypes::NONE, 2)},
        Pair<Array<size_ut>, Pair<size_ut, size_ut>>{
            {// Variable Declaration with initialization
             STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL, STypes::TYPE,
             STypes::ASTERISK_OR_AMPERSAND | STypes::MULTIPLE, STypes::NAME, STypes::ASSIGNMENT,
             STypes::LITERAL | STypes::NAME, STypes::SEMICOLON},
            Pair<size_ut, size_ut>(STypes::NONE, 1)},
        Pair<Array<size_ut>, Pair<size_ut, size_ut>>{
            {// Blank statement
             STypes::NAME | STypes::LITERAL, STypes::SEMICOLON},
            Pair<size_ut, size_ut>(STypes::NONE, 0)},
    };

    Array<Pair<String, size_ut>> type_modifier_order{
        Pair<String, size_ut>("auto", 0),     Pair<String, size_ut>("static", 0), Pair<String, size_ut>("extern", 0),
        Pair<String, size_ut>("register", 0), Pair<String, size_ut>("const", 1),  Pair<String, size_ut>("long", -1),
        Pair<String, size_ut>("short", -2),   Pair<String, size_ut>("signed", 3), Pair<String, size_ut>("unsigned", 3),
    };

    Map<String, Array<Pair<size_ut, size_ut>>> key_expressions{std::initializer_list<
        Pair<String, Array<Pair<size_ut, size_ut>>>>{
        Pair<String, Array<Pair<size_ut, size_ut>>>{"auto", {Pair<size_ut, size_ut>(STypes::TYPE_MODIFIER, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{"break", {Pair<size_ut, size_ut>(STypes::BREAK, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{"case", {Pair<size_ut, size_ut>(STypes::CASE, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{"char", {Pair<size_ut, size_ut>(STypes::TYPE, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{"const", {Pair<size_ut, size_ut>(STypes::TYPE_MODIFIER, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{"continue", {Pair<size_ut, size_ut>(STypes::WHOLE_STATEMENT, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{"default", {Pair<size_ut, size_ut>(STypes::LABEL, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{"do", {Pair<size_ut, size_ut>(STypes::DO, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{"double", {Pair<size_ut, size_ut>(STypes::TYPE, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{"else", {Pair<size_ut, size_ut>(STypes::ELSE, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{"enum", {Pair<size_ut, size_ut>(STypes::ENUM, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{"extern", {Pair<size_ut, size_ut>(STypes::TYPE_MODIFIER, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{"float", {Pair<size_ut, size_ut>(STypes::TYPE, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{"for", {Pair<size_ut, size_ut>(STypes::FOR, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{"goto", {Pair<size_ut, size_ut>(STypes::GOTO, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{"if", {Pair<size_ut, size_ut>(STypes::ELSE, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{"int", {Pair<size_ut, size_ut>(STypes::TYPE, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{
            "long", {Pair<size_ut, size_ut>(STypes::TYPE_MODIFIER | STypes::TYPE, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{"register", {Pair<size_ut, size_ut>(STypes::TYPE_MODIFIER, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{"return", {Pair<size_ut, size_ut>(STypes::RETURN, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{
            "short", {Pair<size_ut, size_ut>(STypes::TYPE_MODIFIER | STypes::TYPE, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{"signed", {Pair<size_ut, size_ut>(STypes::TYPE_MODIFIER, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{"sizeof", {Pair<size_ut, size_ut>(STypes::SIZEOF, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{"static", {Pair<size_ut, size_ut>(STypes::TYPE_MODIFIER, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{"struct", {Pair<size_ut, size_ut>(STypes::STRUCT, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{"switch", {Pair<size_ut, size_ut>(STypes::SWITCH, 0)}},
        // Note: typedef will be handled externally
        // Pair<String, Array<Pair<size_ut, size_ut>>>{"typedef", {Pair<size_ut, size_ut>(STypes::TYPEDEF, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{"union", {Pair<size_ut, size_ut>(STypes::UNION, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{"unsigned", {Pair<size_ut, size_ut>(STypes::TYPE_MODIFIER, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{"void", {Pair<size_ut, size_ut>(STypes::VOID_TYPE, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{"volatile", {Pair<size_ut, size_ut>(STypes::TYPE_MODIFIER, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{"while", {Pair<size_ut, size_ut>(STypes::WHILE, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{
            "#define", {Pair<size_ut, size_ut>(STypes::PREPROCESSOR_DEFINE, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{"#elif", {Pair<size_ut, size_ut>(STypes::PREPROCESSOR_ELIF, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{"#else", {Pair<size_ut, size_ut>(STypes::PREPROCESSOR_ELSE, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{"#endif", {Pair<size_ut, size_ut>(STypes::PREPROCESSOR_ENDIF, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{"#error", {Pair<size_ut, size_ut>(STypes::PREPROCESSOR_ERROR, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{"#if", {Pair<size_ut, size_ut>(STypes::PREPROCESSOR_IF, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{"#ifdef", {Pair<size_ut, size_ut>(STypes::PREPROCESSOR_IFDEF, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{
            "#ifndef", {Pair<size_ut, size_ut>(STypes::PREPROCESSOR_IFNDEF, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{
            "#include", {Pair<size_ut, size_ut>(STypes::PREPROCESSOR_INCLUDE, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{
            "#pragma", {Pair<size_ut, size_ut>(STypes::PREPROCESSOR_PRAGMA, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{"#undef", {Pair<size_ut, size_ut>(STypes::PREPROCESSOR_UNDEF, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{
            "=",
            {Pair<size_ut, size_ut>(STypes::OPERATOR | STypes::BOTH, 14),
             Pair<size_ut, size_ut>(STypes::ASSIGNMENT, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{
            "+",
            {Pair<size_ut, size_ut>(STypes::OPERATOR | STypes::BOTH, 4),
             Pair<size_ut, size_ut>(STypes::OPERATOR | STypes::PREFIX, 2)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{
            "-",
            {Pair<size_ut, size_ut>(STypes::OPERATOR | STypes::BOTH, 4),
             Pair<size_ut, size_ut>(STypes::OPERATOR | STypes::PREFIX, 2)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{
            "*",
            {Pair<size_ut, size_ut>(STypes::OPERATOR | STypes::BOTH | STypes::ASTERISK, 3),
             Pair<size_ut, size_ut>(STypes::OPERATOR | STypes::PREFIX | STypes::ASTERISK, 2)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{"/", {Pair<size_ut, size_ut>(STypes::OPERATOR | STypes::BOTH, 3)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{"%", {Pair<size_ut, size_ut>(STypes::OPERATOR | STypes::BOTH, 3)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{
            "+=", {Pair<size_ut, size_ut>(STypes::OPERATOR | STypes::BOTH | STypes::REQUIRE_LVALUE, 14)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{
            "-=", {Pair<size_ut, size_ut>(STypes::OPERATOR | STypes::BOTH | STypes::REQUIRE_LVALUE, 14)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{
            "*=", {Pair<size_ut, size_ut>(STypes::OPERATOR | STypes::BOTH | STypes::REQUIRE_LVALUE, 14)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{
            "/=", {Pair<size_ut, size_ut>(STypes::OPERATOR | STypes::BOTH | STypes::REQUIRE_LVALUE, 14)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{
            "%=", {Pair<size_ut, size_ut>(STypes::OPERATOR | STypes::BOTH | STypes::REQUIRE_LVALUE, 14)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{
            ">>=", {Pair<size_ut, size_ut>(STypes::OPERATOR | STypes::BOTH | STypes::REQUIRE_LVALUE, 14)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{
            "<<=", {Pair<size_ut, size_ut>(STypes::OPERATOR | STypes::BOTH | STypes::REQUIRE_LVALUE, 14)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{
            "&=", {Pair<size_ut, size_ut>(STypes::OPERATOR | STypes::BOTH | STypes::REQUIRE_LVALUE, 14)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{
            "^=", {Pair<size_ut, size_ut>(STypes::OPERATOR | STypes::BOTH | STypes::REQUIRE_LVALUE, 14)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{
            "|=", {Pair<size_ut, size_ut>(STypes::OPERATOR | STypes::BOTH | STypes::REQUIRE_LVALUE, 14)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{
            "++",
            {Pair<size_ut, size_ut>(STypes::OPERATOR | STypes::PREFIX, 2),
             Pair<size_ut, size_ut>(STypes::OPERATOR | STypes::POSTFIX, 1)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{
            "--",
            {Pair<size_ut, size_ut>(STypes::OPERATOR | STypes::PREFIX, 2),
             Pair<size_ut, size_ut>(STypes::OPERATOR | STypes::POSTFIX, 1)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{"==", {Pair<size_ut, size_ut>(STypes::OPERATOR | STypes::BOTH, 7)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{"!=", {Pair<size_ut, size_ut>(STypes::OPERATOR | STypes::BOTH, 7)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{">", {Pair<size_ut, size_ut>(STypes::OPERATOR | STypes::BOTH, 6)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{"<", {Pair<size_ut, size_ut>(STypes::OPERATOR | STypes::BOTH, 6)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{
            ">=", {Pair<size_ut, size_ut>(STypes::OPERATOR | STypes::BOTH | STypes::REQUIRE_LVALUE, 6)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{
            "<=", {Pair<size_ut, size_ut>(STypes::OPERATOR | STypes::BOTH | STypes::REQUIRE_LVALUE, 6)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{
            "!", {Pair<size_ut, size_ut>(STypes::OPERATOR | STypes::PREFIX, 2)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{
            "&&", {Pair<size_ut, size_ut>(STypes::OPERATOR | STypes::BOTH, 11)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{
            "||", {Pair<size_ut, size_ut>(STypes::OPERATOR | STypes::BOTH, 12)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{
            "?", {Pair<size_ut, size_ut>(STypes::OPERATOR | STypes::QUESTION, 13)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{
            ":", {Pair<size_ut, size_ut>(STypes::OPERATOR | STypes::QELSE, 13)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{
            ",", {Pair<size_ut, size_ut>(STypes::OPERATOR | STypes::COMMA, 15)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{
            "&",
            {Pair<size_ut, size_ut>(STypes::OPERATOR | STypes::PREFIX | STypes::AMPERSAND, 2),
             Pair<size_ut, size_ut>(STypes::OPERATOR | STypes::BOTH | STypes::AMPERSAND, 8)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{"|", {Pair<size_ut, size_ut>(STypes::OPERATOR | STypes::BOTH, 10)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{"^", {Pair<size_ut, size_ut>(STypes::OPERATOR | STypes::BOTH, 9)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{
            "~", {Pair<size_ut, size_ut>(STypes::OPERATOR | STypes::PREFIX, 2)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{"<<", {Pair<size_ut, size_ut>(STypes::OPERATOR | STypes::BOTH, 5)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{">>", {Pair<size_ut, size_ut>(STypes::OPERATOR | STypes::BOTH, 5)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{".", {Pair<size_ut, size_ut>(STypes::OPERATOR | STypes::DOT, 1)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{
            "->", {Pair<size_ut, size_ut>(STypes::OPERATOR | STypes::ARROW, 1)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{
            "{", {Pair<size_ut, size_ut>(STypes::CURLY_BRACE | STypes::OPEN, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{
            "}", {Pair<size_ut, size_ut>(STypes::CURLY_BRACE | STypes::CLOSE, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{"[", {Pair<size_ut, size_ut>(STypes::BRACE | STypes::OPEN, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{"]", {Pair<size_ut, size_ut>(STypes::BRACE | STypes::CLOSE, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{
            "(", {Pair<size_ut, size_ut>(STypes::PARENTHESIS | STypes::OPEN, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{
            ")", {Pair<size_ut, size_ut>(STypes::PARENTHESIS | STypes::CLOSE, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{"'", {Pair<size_ut, size_ut>(STypes::SINGLE_QUOTE, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{"\"", {Pair<size_ut, size_ut>(STypes::DOUBLE_QUOTE, 0)}},
        Pair<String, Array<Pair<size_ut, size_ut>>>{";", {Pair<size_ut, size_ut>(STypes::SEMICOLON, 0)}},
    }};


    int compare(const void* a, const void* b) {

        return ((ExpTypePtr)(a))->second[0].second < ((ExpTypePtr)(b))->second[0].second;
    }

    Map<String, Array<Pair<size_ut, size_ut>>> key_expressions_const =
        ([](Map<String, Array<Pair<size_ut, size_ut>>>& exp) -> Map<String, Array<Pair<size_ut, size_ut>>> {
            qsort(&(exp(0)), exp.size(), sizeof(exp(0)), compare);
            return exp;
        }(key_expressions));


#define checkBit(a, b) (a & (1LL << b))
#define setBit(a, b) (a |= (1LL << b))
#define resetBit(a, b) (a &= ~(1LL << b))
#define setSize_ut(a) (a |= ~0LL)
#define resetSize_ut(a) (a &= 0LL)


#define checkIs(a, b) (a & b)

    /**
     * @brief
     * this func checks if the group of STypes combinations can fit into the combination in b;
     * eg.) a = FuncName, ParenOpen, STypes::Literal, STypes::Comma, STypes::Literal, ParenClose, ; b =
     * STypes::Literal | STypes::Comma, STypes::MULTIPLE, STypes::OPTIONAL
    //    if mode is 1, then also add the things parsed into the
       @brief:
        the return of matchExact:
            0: not matched
           -1: matched so far but not complete
            1: matched and completed
     */

    std::tuple<short int, size_ut> matchExact(
        const Array_view<Pair<String, Array<Pair<size_ut, size_ut>>>>& a, size_ut precedence, size_ut index1,
        /* size_ut index2,  */ CFile& cfile) {
        static size_ut last_index{0};
        last_index = index1;
        bool success{false};
        // statement_types_arrays[index1].second.second == 3;
        size_ut index_of_failure{0};
        // Note: this is to count the amount of STypes::MULTIPLE used, specifically for when making functions.
        std::size_t   multiple_count{0};
        Array<String> param_names{};
        String        name;
        size_ut       index2{0};
        Array         arr_version_of_a{a.getArray()};
#define sta(param) statement_types_arrays[index1].first[index2].first[param]
#define sts statement_types_arrays[index1].first[index2].first.size()
#define stt statement_types_arrays[index1].second
#define foptions statement_types_arrays[index1].first[index2].second
#define ainfof(i, i0) a[i].second[i0].first
#define ainfos(i, i0) a[i].second[i0].second
        // for (size_ut i{0}; (i < a.size());) {
        {
            size_ut i{0};

            // for (size_ut k{0}; k < statement_types_arrays[index1].first.size(); ++k) {
            for (index2 = 0; (index2 < statement_types_arrays[index1].first.size()) && (i < a.size()); ++index2) {
            retry:
                success = false;
                // i1 keeps track of the innermost STypes array.
                for (size_ut i1{0}; (i1 < sts) && (i < a.size()); ++i1, ++i) {
                    // i0 keeps track of which option from the corresponding identifier is being used
                    for (size_ut i0{0}; i0 < a[i].second.size(); ++i0) {
                        if (sta(i1) & ainfof(i, i0)) {
                            if ((ainfof(i, i0) & STypes::PARENTHESIS) || (ainfof(i, i0) & STypes::BRACE) ||
                                (ainfof(i, i0) & STypes::CURLY_BRACE) || (ainfof(i, i0) & STypes::OPERATOR)) {
                                if ((foptions & ainfof(i, i0))) {
                                    if (ainfof(i, i0) & STypes::OPERATOR) {
                                        if (ainfos(i, i0) == precedence) {
                                            success = true;
                                            goto successful;
                                            // continue;
                                        }
                                        // index_of_failure = i;
                                        success = false;
                                        continue;
                                        // goto unsuccessful;
                                        // return std::make_tuple<short int, size_ut>(0, (size_ut)(foptions));
                                    }
                                    success = true;
                                    goto successful;
                                    // continue;
                                }
                                // goto unsuccessful;
                                // index_of_failure = i;
                                success = false;
                                continue;
                                // return std::make_tuple<short int, size_ut>(0, (size_ut)(foptions));
                            }
                            if (stt.second == 7) {
                                if (index2 == 4) {
                                    if (i1 == 2) {
                                        param_names.push_back(a[i].first);
                                    }
                                }
                                else if (index2 == 3) {
                                    if (i1 == 1) {
                                        // para
                                        param_names.push_back(a[i].first);
                                    }
                                }
                                else if (index2 == 1) {
                                    name = a[i].first;
                                }
                            }
                            else if (stt.second == 6) {
                                if (index2 == 4) {
                                    if (i1 == 2) {
                                        param_names.push_back(a[i].first);
                                    }
                                }
                                else if (index2 == 3) {
                                    if (i1 == 1) {
                                        // para
                                        param_names.push_back(a[i].first);
                                    }
                                }
                                else if (index2 == 1) {
                                    name = a[i].first;
                                }
                                // if (index2 == 4) {
                                // ;
                                // }
                            }
                            success = true;
                            goto successful;
                            // continue;
                        }
                    }
                    if (!success) {
                        // unsuccessful:
                        if (index2) {
                            if (statement_types_arrays[index1].first[index2 - 1].second & STypes::MULTIPLE) {
                                for (size_ut i0{0}; i0 < a[i].second.size(); ++i0) {
                                    if (sta(0) & ainfof(i, i0)) {
                                        --index2;
                                        goto retry;
                                        // goto matched;
                                    }
                                }

                                // matched:
                                // if (--index2)
                            }
                        }
                        if (foptions & STypes::OPTIONAL) {
                            ++index2;
                            goto retry;
                            // for(size_ut i0)
                        }
                        return std::make_tuple<short int, size_ut>(0, 0LL);
                    }
                successful:;
                }
            }
            // return 1;
            // Note: in this case, the second return value is the amount of excess things in the a.
            if (statement_types_arrays[index1].first.size() == index2) {
                size_ut counter{0};
                bool    counter_found{false};
                while (counter < cfile.all.size()) {
                    if (cfile.all[counter].first == name) {
                        counter_found = true;
                        break;
                    }
                    ++counter;
                }
                if (stt.second == 7 || stt.second == 6) {
                    cfile.functions.push_back(cfile.all[counter]);
                    // for (std::size_t k{0}; k < multiple_count; ++k) {
                    for (String& k : param_names) {
                        cfile.functions[-1].second.push_back(Pair<String, size_ut>(k, 0));
                    }
                    // }
                    // cfile.functions[-1].second.
                }
                return std::make_tuple<short int, size_ut>(1, a.size() - i);
            }
        }
        // return -1;
        return std::make_tuple<short int, size_ut>(-1, 0LL);
#undef ainfos
#undef ainfof
#undef foptions
#undef stt
#undef sts
#undef sta
    }

    /**
     * @brief
     *
     * @param a
     * @param index
     * @param operator_precedence_level
     * @return short int
     * Note:
     *  The return value is
     *      -1: not matched
     *      >0: amount of increment needed to go from start to end
     */

    short int parseArray(
        Array<Pair<String, Array<Pair<size_ut, size_ut>>>>& a, size_ut index, size_ut operator_precedence_level,
        CFile& cfile) {

        // #define arr statement_types_arrays[index].first
        Array<Pair<Array<size_ut>, size_ut>>&                   arr{statement_types_arrays[index].first};
        short int                                               tmp{0};
        Array_view<Pair<String, Array<Pair<size_ut, size_ut>>>> arr_view{a};
        size_ut                                                 offset{0};
        size_ut                                                 start{0}, end{1};
        std::tuple<short int, size_ut>                          tup_current, tup_previous;


        // arr_view.setViewEnd(0);

        // for (size_ut i{0}; ((end <= arr[i].first.size()) && (i < arr.size())); ++end, ++i, offset = 0) {
        // for (size_ut i{0}; (i < arr.size()); ++i, offset = 0) {

        // for (size_ut end{1}, j{0}; (end < a.size()) && (j < arr[index].first.size()); ++end) {
        //     // no_increment:
        //     // for(size_ut )
        //     arr_view.setViewStart(start);
        //     arr_view.setViewEnd(end);
        //     // for (size_ut j{0}; j <= arr[index].first.size(); ++j) {
        //     // tmp = matchExact(arr_view, operator_precedence_level, index, index);
        //     // }
        //     tup_current = matchExact(arr_view, operator_precedence_level, index, j);
        //     tmp         = std::get<0>(tup_current);
        //     if (tmp > 0) {
        //         // if(std::get<1>(tup_current)) {
        //         //     arr_view.truncBack(st)
        //         // }
        //         // arr_view.truncBack(std::get<1>(tup_current));
        //         end -= std::get<1>(tup_current);
        //         arr_view.setViewEnd(end);
        //         start = arr_view.end();
        //         arr_view.setViewStart(start);
        //         ++j;
        //         goto next_loop;
        //         // continue;
        //     }
        //     else if (tmp) {
        //         goto next_loop;

        //         // goto no_increment;
        //         // --index;
        //         // continue;
        //     }
        //     // else {
        //     //     return -1;
        //     // }
        //     return -1;
        // next_loop:;
        // }

        for (size_ut end{a.size()}; end <= a.size(); /*  ++end */) {
            // no_increment:
            // for(size_ut )
            // arr_view.setViewStart(start);
            // arr_view.setViewEnd(end);
            // for (size_ut j{0}; j <= arr[index].first.size(); ++j) {
            // tmp = matchExact(arr_view, operator_precedence_level, index, index);
            // }
            tup_current = matchExact(arr_view, operator_precedence_level, index /* , j */, cfile);
            tmp         = std::get<0>(tup_current);
            if (tmp > 0) {
                // if(std::get<1>(tup_current)) {
                //     arr_view.truncBack(st)
                // }
                // arr_view.truncBack(std::get<1>(tup_current));

                end -= std::get<1>(tup_current);
                arr_view.setViewEnd(end);
                start = arr_view.end();
                arr_view.setViewStart(start);

                // ++j;
                // goto next_loop;
                return end;
                // continue;
            }
            // else if (tmp) {
            //     goto next_loop;

            //     // goto no_increment;
            //     // --index;
            //     // continue;
            // }

            // else {
            //     return -1;
            // }
            return -1;
        next_loop:;
        }

        return end;
        // #undef arr
        // }
    }

    // TODO: Everything is remade, but not yet debugged for the final iteration; test the whole process for more complex
    // c source codes.

    bool check(Array<Pair<String, Array<Pair<size_ut, size_ut>>>>& a, Array<Statement>& arr_statements, CFile& cfile) {
        Array_view<Pair<String, Array<Pair<size_ut, size_ut>>>> arr_view{a};
        arr_statements.push_back(Statement{});

        // Statement statement1{};
        Statement& statement1{arr_statements[-1]};
        // Note: mapc: map_current, mapb: mar_before
        Map<size_ut, std::shared_ptr<Expression>> mapc{}, mapb{};

        Pair<String, ExpressionType> fill_value("", ExpressionType{Pair<size_ut, size_ut>(0LL, 0LL)});
        for (bool changed{true}, just_changed{false}, changed_back{false}; changed; changed = false) {
            /**
             * Note: when the checkArr(the new one) replaces, continue that loop, then make it run again with the
             * same i, and then make it start from i = 0 onwards.
             */
            // Note: i here is the indexes covered by arr_view
            for (size_ut i{0}, increment{0}, inc{0}; i < statement_types_arrays.size();
                 i += inc, arr_view.extendFront(), arr_view.extendBack()) {
                goto start_of_loop;
            restart_loop:
                i = 0;
            start_of_loop:
                inc = 1;
                for (size_ut j{0}, precedence_level{0}; j < a.size();
                     ++j, arr_view.truncFrontIgnore(increment, fill_value), precedence_level = 0) {
                    // arr_view;
                    // arr_view.arr();
                    auto arr_version_of_arr_view = arr_view.getArray();
                    // auto s = arr_view.

                    for (precedence_level = 0; precedence_level < 15; ++precedence_level) {

                        // Note: Updated this parseArray, so it receives Array<Pair<String, Array<Pair<size_ut,
                        // size_ut>>>> instead, but ignores the String part (param[i].first) in the checking
                        // process. But instead with precedences.

                        Array<Pair<String, ExpressionType>> ignored_cut{arr_view.cutIgnored(fill_value)};
                        // Array_view<Pair<String, ExpressionType>>(ignored_cut)

                        // Note: i here is the type of statement that will be tried masking.
                        increment = parseArray(ignored_cut, statement_type_no, precedence_level, cfile);

                        if (increment < 0) {
                            increment = 1;
                            goto next_sub;
                        }

                        // TODO: Not sure if this thing below works or not.
                        // increment += (decltype(arr_view)(arr_view, 0, increment.size() - ignored_cut.size());
                        // std::size_t counter{0};

                        {

                            // Note: This for loop checks for the real number of increment, including blanks ignored
                            // by the parseArray.
                            std::size_t counter{0};
                            for (std::size_t cnt{0}; cnt < increment; ++counter) {
                                if (ignored_cut[counter] != fill_value) {
                                    ++cnt;
                                    // continue;

                                    // decltype(ignored_cut[0])& a = ignored_cut[0];
                                }
                            }

                            increment = counter;
                            // }

                            // Note: the mapb and mapc contain the things that are already parsed, waiting to be
                            // turned into an Expression.
                            // {
                            for (size_ut j{0}; j < mapb.size(); ++j) {
                                mapc.insert(mapb(j));
                            }
                            Map<size_ut, std::shared_ptr<Classifier::Expression>>::swap(mapc, mapb);
                            mapc.clear();
                            Array<Pair<Expression::ExpressionStr, bool>> arr{};

                            size_ut        found_index{0};
                            Array<size_ut> found_indexes;
                            // Note: cnt stands for counter
                            // Note: this for loop puts all the indexes of things between the range parsed by the
                            // most recent parseArray to check if the mapb contains anything between the range
                            // parsed by the parseArray function.
                            for (size_ut cnt{i}; cnt < i + increment;) {
                                if ((found_index = mapb.find(cnt)) < i + increment) {
                                    if (found_index == mapb.size()) {
                                        ++cnt;
                                        continue;
                                    }
                                    found_indexes.push_back(found_index);
                                    cnt = found_index + 1;
                                    continue;
                                }
                            }

                            if (found_indexes.size()) {
                                // TODO: Check how this identifier "value" is used
                                Pair<size_ut, std::shared_ptr<Expression>> value{i, std::make_shared<Expression>()};
                                found_indexes.sort();
                                std::size_t index_at{0};
#define iter found_indexes[index_at]
                                for (size_ut i0{i}; i0 < i + increment; ++i0) {
                                    if (i0 == iter) {
                                        mapb(iter);
                                        mapb(iter).second;
                                        Expression::ExpressionStr(mapb(iter).second);
                                        Pair<Expression::ExpressionStr, bool>(
                                            Expression::ExpressionStr(mapb(iter).second), 1);
                                        value.second->push_back(
                                            Pair<Expression::ExpressionStr, bool>(mapb(iter).second, 1));
                                        ++index_at;
                                        ::transformPrecedences((*(value.second)));
                                    }
                                    else if (arr_view[i0] != fill_value) {
                                        value.second->push_back(Pair<Expression::ExpressionStr, bool>(arr_view[i0], 0));
                                        ::transformPrecedences((*(value.second)));
                                    }
                                }
#undef iter

                                mapb.replace(value, found_indexes[0], found_indexes[-1] + 1);
                            }
                            else {
                                // TODO: The errors seem to lead here. Fix this.
                                mapc.insert(Pair<size_ut, std::shared_ptr<Expression>>{
                                    statement_type_no, std::make_shared<Expression>()});
                                *(mapc[(size_ut)(statement_type_no)].second) = arr;
                            }

                            Pair<String, Array<Pair<size_ut, size_ut>>> temp(
                                String(""),
                                {Pair<size_ut, size_ut>(
                                    statement_types_arrays[statement_type_no].second.first, (size_ut)0LL)});
                            a.fill(fill_value, i, i + increment);
                            a[i] = temp;
                        }

                        just_changed = true;
                        inc          = 0;

                    next_sub:

                        /**
                         * @brief
                         * if precedence_level is 0 (so that this is only looped once) and none of the things in the
                         * current statement type selected has operators, break from this loop.
                         *
                         */
                        // std::cout << mapc << std::endl;
                        if (!precedence_level) {
                            size_ut sum{0};
                            for (size_ut k{0}; k < statement_types_arrays[statement_type_no].first.size(); ++k) {
                                for (size_ut l{0}; l < statement_types_arrays[statement_type_no].first[k].first.size();
                                     ++l) {
                                    if (statement_types_arrays[statement_type_no].first[k].first[l] &
                                        STypes::OPERATOR) {
                                        ++sum;
                                    }
                                }
                            }
                            if (!sum)
                                break;
                        }
                    }
                }
                if (changed_back && !just_changed) {
                    changed_back = just_changed;
                    just_changed = false;
                    goto restart_loop;
                }
                changed_back = just_changed;
                just_changed = false;
            }
        }
        return true;
    }
}// namespace Classifier