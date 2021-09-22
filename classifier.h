#include <bits/stdc++.h>

std::vector<std::string> types;
std::vector<std::string>;

class Types {

    /**
     * @brief
     * The values in the map are codes:
     * e : pr(e)fix
     * o : p(o)stfix
     * b : (b)oth
     * i : (i)nsertable
     * t : ei(t)her
     */
public:
    static std::map<std::string, std::string> operators{
        std::pair<std::string, std::string> {"=", "b"},
        std::pair<std::string, std::string> {"+", "b"},
        std::pair<std::string, std::string> {"-", "b"},
        std::pair<std::string, std::string> {"*", "b"},
        std::pair<std::string, std::string> {"/", "b"},
        std::pair<std::string, std::string> {"%", "b"},
        std::pair<std::string, std::string> {"+=", "b"},
        std::pair<std::string, std::string> {"-=", "b"},
        std::pair<std::string, std::string> {"*=", "b"},
        std::pair<std::string, std::string> {"/=", "b"},
        std::pair<std::string, std::string> {"%=", "b"},
        std::pair<std::string, std::string> {">>=", "b"},
        std::pair<std::string, std::string> {"<<=", "b"},
        std::pair<std::string, std::string> {"&=", "b"},
        std::pair<std::string, std::string> {"^=", "b"},
        std::pair<std::string, std::string> {"|=", "b"},
        std::pair<std::string, std::string> {"++", "t"},
        // std::pair<std::string, std::string> {"++E", "e"},
        // std::pair<std::string, std::string> {"++O", "o"},
        std::pair<std::string, std::string> {"--", "t"},
        // std::pair<std::string, std::string> {"--E", "e"},
        // std::pair<std::string, std::string> {"--O", "o"},
        std::pair<std::string, std::string> {"==", "b"},
        std::pair<std::string, std::string> {"!=", "b"},
        std::pair<std::string, std::string> {">", "b"},
        std::pair<std::string, std::string> {"<", "b"},
        std::pair<std::string, std::string> {">=", "b"},
        std::pair<std::string, std::string> {"<=", "b"},
        std::pair<std::string, std::string> {"!", "e"},
        std::pair<std::string, std::string> {"&&", "b"},
        std::pair<std::string, std::string> {"||", "b"},
        std::pair<std::string, std::string> {"?", "b"},
        std::pair<std::string, std::string> {":", "b"},
        std::pair<std::string, std::string> {",", "b"},
        std::pair<std::string, std::string> {"&", "b"},
        std::pair<std::string, std::string> {"|", "b"},
        std::pair<std::string, std::string> {"^", "b"},
        std::pair<std::string, std::string> {"~", "e"},
        std::pair<std::string, std::string> {"<<", "b"},
        std::pair<std::string, std::string> {">>", "b"},
        std::pair<std::string, std::string> {"()__CAST__", "ei"},
        std::pair<std::string, std::string> {"::", "b"},
        std::pair<std::string, std::string> {"()", "oi"},
        std::pair<std::string, std::string> {"[]", "oi"},
        std::pair<std::string, std::string> {".", "b"},
        std::pair<std::string, std::string> {"->", "b"},
        std::pair<std::string, std::string> {"&__PTR__", "e"},
        std::pair<std::string, std::string> {"*__PTR__", "e"},


        //TODO: Not so sure about putting space here after new and delete
        std::pair<std::string, std::string> {"new ", "e"},
        std::pair<std::string, std::string> {"delete ", "e"},
        std::pair<std::string, std::string> {"sizeof()", "ei"},

    };
    static std::vector<std::string> type_modifiers{
        "",
        "*",
        "&",
        "()"
    };
    static std::vector<std::string> order{
        "void",
        "bool",
        "char",
        "wchar_t",
        "short int",
        "int"
        "long int",
        "long long int",
        "float"
        "double"
        "long double"
    };
    // wchar_t a;
    // std::string<
    static std::string getReturnType(std::string operator_1, std::string type_1, std::string type_2 = "") {
        std::vector<std::string>::iterator a{ std::find(order.begin(), order.end(), type_1) }, b{ std::find(order.begin(), order.end(), type_2) };
        return a > b ? *a : *b;
    }
protected:
    std::string m_type;
public:
    const std::string& get_type() const {
        return m_type;
    }
    bool operator==(const Types& type) const {
        return type.m_type == m_type;
    }
};



class Operator {
    std::string
};

class Variable {
    std::string name;
    std::string m_type;
};

class Function {
    std::string name;
    std::string m_type;
    std::string m_return_type;
    std::vector<std::string> m_param_types;
};

// class Expression {
//     bool m_contains_variable;
//     Operator m_operator;
//     Variable* m_variable;
//     Expression* m_variable_primary;
//     Expression* m_variable_secondary;
// };

class Expression {
    // bool m_contains_variable;
    // Operator m_operator;
    // Variable* m_variable;
    // Expression* m_variable_primary;
    // Expression* m_variable_secondary;
    Types m_evaluated_type;
    Expression(std::string) : m_evaluated_type{ m_evaluated_type } {}
};

// class Alias {
//     std::vector<std::vector<std::string>> m_alias;
//     Alias() : m_alias{
//         {""}
//     } {}
//     std::string checkAlias(std::string) {
//         std::vector<std::string> aliases;
//     }
// }
















/**
 *  @brief
 *
 *  The values in the map are codes for what is expected:
 *  Other names are referenced by _$(NAME)_
 *  Use parentheses with conjunctions (| is or; & is and; ^ is xor)
 *  t : (t)ype
 *  d : (d)eclaration (in conjunction with:)
 *      c : class
 *      s : struct
 *      v : variable
 *      f : function
 *      p : template
 *      // (of class, struct, variable, etc.)
 *  n : (n)ame
 *  o : (o)perator (needs to be used in conjunction with below:)
 *      e : pr(e)fix
 *      o : p(o)stfix
 *      b : (b)oth
 *      i : (i)nsertable
 *      t : ei(t)her
 *  x : e(x)pectances (needs to be used in conjunction with below:)
 *      //a : (a)bove
 *      //b : (b)elow
 *      a : (a)fter
 *      b : (b)efore
 *
 *      i : (i)nside block following
 *      c : (c)ontains
 *      then followed by
 *  //p : loo(p)
 *  //w : s(w)itch
 *  //q : case
 *  //r : t(r)y
 *  l : (l)abels
 *  b : (b)lock
 *  z : name then block
 *  f : function definition
 *  w : for loop
 *  s : no (s)emicolon
 *  v : value (followed by parentheses indicating its type):
 *          b stands for boolean;
 *          i stands for integer;
 *          l stands for long integer;
 *          ll stands for long long integer;
 *          s stands for short integer;
 *          c stands for character;
 *          f stands for float;
 *          d stands for double;
 *          ld stands for long double;
 *          * (after a type) stands for pointer;
 *          (T(n)) stands for template: T(0) == T(0) but might not be == to T(1) ();
 *  e : expression
 *  p : template (used like c)
 *  c : function-like (c)all
 *      has to be followed by parentheses which contain:
 *          what is expected like (t)ypes, (n)ames, etc.
 *
 *          i stands for integer;
 *          l stands for long integer;
 *          ll stands for long long integer;
 *          s stands for short integer;
 *          c stands for character;
 *          f stands for float;
 *          d stands for double;
 *          ld stands for long double;
 *
 *          prefix (u) stands for unsigned
 *          * (after a type) stands for pointer;
 *          * (after a type) stands for pointer;
 *          (T(n)) stands for template: T(0) == T(0) but might not be == to T(1) ();
 *
 *          Note: names also include literal values
 *          and use || for separating param sets
 *          and use && for separating each inside the param set
 *          // and use $c/T? for template parameters with c params
 *          such as (t&&t) for something that receieves 2 types
 *          or (n@i#&&n@d#) for something that receieves 2 types
 *          or (n@i/c#&&n@0=#) for something that receieves (int, int) or (char, char)
 *          or (n@2i/d#&&n@f/2=#) for something that receieves (int, float) or (int, int), (double, double)
 *          or (n@0T0#&&n@0=#&&n@i/d/ud/uc#) for something that receieves (T0, T0, int), (T0, T0, double), (T0, T0, unsigned double), (T0, T0, unsigned char)
 *          or (n@0T0#&&n@0T1#&&n@i/d/ud/uc#) for something that receieves (T0, T1, int), (T0, T1, double), (T0, T1, unsigned double), (T0, T1, unsigned char)
 *          TODO:CAUTION : check if all of them are 0; if all are zero, it receives nothing
 *
 *  s : (s)elf (alone)
 *  r : p(r)eprocessor directive
 *  _sth_%b means inside the block of sth
 *  ^ is an escape sequence, so ^_ means just _, so not confused with _$(name)_
 *TODO:add for ones that don't need semicolon (s)
    */
std::map<std::string, std::string> key_cpp{
    std::pair<std::string, std::string> {"alignas", "c(n@i#)xbd(v|c|s)"},
    std::pair<std::string, std::string> {"alignof", "c(t)v(ul)"},
    std::pair<std::string, std::string> {"and", "ob"},
    std::pair<std::string, std::string> {"and_eq", "ob"},
    std::pair<std::string, std::string> {"asm", "ob"},
    std::pair<std::string, std::string> {"auto", "t"},
    std::pair<std::string, std::string> {"bitand", "ob"},
    std::pair<std::string, std::string> {"bitor", "ob"},
    std::pair<std::string, std::string> {"bool", "t"},
    std::pair<std::string, std::string> {"break", "sxi(_for_|_while_|_do_|_switch_)"},
    std::pair<std::string, std::string> {"case", "lxi_switch_"},
    std::pair<std::string, std::string> {"catch", "xa_throw%b_d(f)"},
    std::pair<std::string, std::string> {"char", "t"},
    std::pair<std::string, std::string> {"char8_t", "t"},
    std::pair<std::string, std::string> {"char16_t", "t"},
    std::pair<std::string, std::string> {"char32_t", "t"},
    std::pair<std::string, std::string> {"class", "z|txid(p)"},
    std::pair<std::string, std::string> {"compl", "oe"},
    // std::pair<std::string, std::string> {"concept", ""},
    std::pair<std::string, std::string> {"const", "x(bt|i(_class_|_struct_)&id(f)|at)"},
    std::pair<std::string, std::string> {"consteval", "xbd(f)"},
    std::pair<std::string, std::string> {"constexpr", "xbt"},
    std::pair<std::string, std::string> {"constinit", "xbt"},
    std::pair<std::string, std::string> {"const_cast", "p(t)c(n@T0#)"},
    std::pair<std::string, std::string> {"continue", "sxi(_for_|_while_|_do_)"},
    // std::pair<std::string, std::string> {"co_await", ""},
    // std::pair<std::string, std::string> {"co_return", ""},
    // std::pair<std::string, std::string> {"co_yield", ""},
    std::pair<std::string, std::string> {"decltype", "tc(n@T0#)"},
    std::pair<std::string, std::string> {"default", "(lxi_switch_)|(vc(@#))"},
    std::pair<std::string, std::string> {"delete", "xbn"},
    std::pair<std::string, std::string> {"do", "xbb"},
    std::pair<std::string, std::string> {"double", "t"},
    std::pair<std::string, std::string> {"dynamic_cast", "p(t)c(n@T0#)"},
    std::pair<std::string, std::string> {"else", "xa(_if_b)"},
    std::pair<std::string, std::string> {"enum", "b"},
    std::pair<std::string, std::string> {"explicit", "xbd(v)"},
    std::pair<std::string, std::string> {"export", "xb(_module_|d(f))"},
    std::pair<std::string, std::string> {"extern", "xbd(v)"},
    std::pair<std::string, std::string> {"false", "v"},
    std::pair<std::string, std::string> {"float", "t"},
    std::pair<std::string, std::string> {"for", "wb"},
    std::pair<std::string, std::string> {"friend", "xi(_class_|_struct_)xbd(v|f)"},
    std::pair<std::string, std::string> {"goto", "xbn"},
    std::pair<std::string, std::string> {"if", "c(n@b#)b"},
    std::pair<std::string, std::string> {"inline", "xbd(f)"},
    std::pair<std::string, std::string> {"int", "t"},
    std::pair<std::string, std::string> {"long", "(t|xbt)"},
    std::pair<std::string, std::string> {"mutable", ""},
    std::pair<std::string, std::string> {"namespace", "(xbb)|(xa_using_)"},
    std::pair<std::string, std::string> {"new", "xbt"},


    //TODO:continue here!!!;


    std::pair<std::string, std::string> {"noexcept", "xid(f)"},
    std::pair<std::string, std::string> {"not", "oe"},
    std::pair<std::string, std::string> {"not_eq", "ob"},
    std::pair<std::string, std::string> {"nullptr", "v"},
    std::pair<std::string, std::string> {"operator", "(xbod(f))|(xbodf(c())|(xb_new_)|(xb_delete_)"},
    std::pair<std::string, std::string> {"or", "ob"},
    std::pair<std::string, std::string> {"or_eq", "ob"},
    std::pair<std::string, std::string> {"private", "lxi(_class_|_struct_)"},
    std::pair<std::string, std::string> {"protected", "lxi(_class_|_struct_)"},
    std::pair<std::string, std::string> {"public", "lxi(_class_|_struct_)"},
    // std::pair<std::string, std::string> {"register", ""}, NOT AVAILABLE IN C++20
    std::pair<std::string, std::string> {"reinterpret_cast", "p(t)c(n@T0#)"},
    // std::pair<std::string, std::string> {"requires", ""},
    std::pair<std::string, std::string> {"return", "xif"},
    std::pair<std::string, std::string> {"short", "(t|xbt)"},
    std::pair<std::string, std::string> {"signed", "xbt"},
    std::pair<std::string, std::string> {"sizeof", "vc(t|n@T0#)"},
    std::pair<std::string, std::string> {"static", "xbd(v|f)"},
    std::pair<std::string, std::string> {"static_assert", "c(n@T0#&&n@T1#)"},
    std::pair<std::string, std::string> {"static_cast", "p(t)c(n@T0#)"},
    std::pair<std::string, std::string> {"struct", "z"},
    std::pair<std::string, std::string> {"switch", "xbb"},
    std::pair<std::string, std::string> {"template", "p($)b"},
    std::pair<std::string, std::string> {"this", "vx(i(_class_|_struct_)&i(f))"},
    std::pair<std::string, std::string> {"thread_local", "xbd(v)"},
    std::pair<std::string, std::string> {"throw", "xbe"},
    std::pair<std::string, std::string> {"true", "v"},
    std::pair<std::string, std::string> {"try", "b"},
    std::pair<std::string, std::string> {"typedef", "xbtn"},
    std::pair<std::string, std::string> {"typeid", "v(_std::size^_t_)c(@T0#)"},
    std::pair<std::string, std::string> {"typename", "txid(p)"},
    std::pair<std::string, std::string> {"union", "z"},
    std::pair<std::string, std::string> {"unsigned", "xbt"},
    std::pair<std::string, std::string> {"using", "(xb_namespace_n)|(xbn_=_n)"},
    std::pair<std::string, std::string> {"virtual", "(xi(_class_|_struct_))&(xbd(f))"},
    std::pair<std::string, std::string> {"void", "t"},
    std::pair<std::string, std::string> {"volatile", ""},
    std::pair<std::string, std::string> {"wchar_t", "t"},
    std::pair<std::string, std::string> {"while", "c(n@b#)b"},
    std::pair<std::string, std::string> {"xor", "ob"},
    std::pair<std::string, std::string> {"xor_eq", "ob"},
    std::pair<std::string, std::string> {"#assert", "r(1/2)"},
    std::pair<std::string, std::string> {"#define", "r(1/2)"},
    std::pair<std::string, std::string> {"#elif", "rv(b)"},
    std::pair<std::string, std::string> {"#else", "r0"},
    std::pair<std::string, std::string> {"#endif", "r0"},
    std::pair<std::string, std::string> {"#error", "rv(c*)"},
    std::pair<std::string, std::string> {"#ident", "rv(c*)"},
    std::pair<std::string, std::string> {"#if", "rv(b)"},
    std::pair<std::string, std::string> {"#ifdef", "rn"},
    std::pair<std::string, std::string> {"#ifndef", "rn"},
    std::pair<std::string, std::string> {"#import", "(r_<_n_>_)|(r_\"_n_\"_)"},
    std::pair<std::string, std::string> {"#include", "(r_<_n_>_)|(r_\"_n_\"_)"},
    std::pair<std::string, std::string> {"#include_next", "(r_<_n_>_)|(r_\"_n_\"_)"},
    std::pair<std::string, std::string> {"#line", "r(1/2)"},
    std::pair<std::string, std::string> {"#pragma", "r_once_"},
    std::pair<std::string, std::string> {"#sccs", "rv(c*)"},
    std::pair<std::string, std::string> {"#unassert", "r1"},
    std::pair<std::string, std::string> {"#undef", "rn"},
    std::pair<std::string, std::string> {"#warning", "rv(c*)"},
};


std::map<std::string, std::string> key{
    // std::pair<std::string, std::string> {"alignas", "c(n@i#)xbd(v|c|s)"},
    // std::pair<std::string, std::string> {"alignof", "c(t)v(ul)"},
    std::pair<std::string, std::string> {"and", "ob"},
    std::pair<std::string, std::string> {"and_eq", "ob"},
    // std::pair<std::string, std::string> {"asm", "ob"},
    std::pair<std::string, std::string> {"auto", "t"},
    std::pair<std::string, std::string> {"bitand", "ob"},
    std::pair<std::string, std::string> {"bitor", "ob"},
    std::pair<std::string, std::string> {"bool", "t"},
    std::pair<std::string, std::string> {"break", "sxi(_for_|_while_|_do_|_switch_)"},
    std::pair<std::string, std::string> {"case", "lxi_switch_"},
    std::pair<std::string, std::string> {"catch", "xa_throw%b_d(f)"},
    std::pair<std::string, std::string> {"char", "t"},
    std::pair<std::string, std::string> {"char8_t", "t"},
    std::pair<std::string, std::string> {"char16_t", "t"},
    std::pair<std::string, std::string> {"char32_t", "t"},
    std::pair<std::string, std::string> {"class", "z|txid(p)"},
    std::pair<std::string, std::string> {"compl", "oe"},
    // std::pair<std::string, std::string> {"concept", ""},
    std::pair<std::string, std::string> {"const", "x(bt|i(_class_|_struct_)&id(f)|at)"},
    std::pair<std::string, std::string> {"consteval", "xbd(f)"},
    std::pair<std::string, std::string> {"constexpr", "xbt"},
    std::pair<std::string, std::string> {"constinit", "xbt"},
    std::pair<std::string, std::string> {"const_cast", "p(t)c(n@T0#)"},
    std::pair<std::string, std::string> {"continue", "sxi(_for_|_while_|_do_)"},
    // std::pair<std::string, std::string> {"co_await", ""},
    // std::pair<std::string, std::string> {"co_return", ""},
    // std::pair<std::string, std::string> {"co_yield", ""},
    std::pair<std::string, std::string> {"decltype", "tc(n@T0#)"},
    std::pair<std::string, std::string> {"default", "(lxi_switch_)|(vc(@#))"},
    std::pair<std::string, std::string> {"delete", "xbn"},
    std::pair<std::string, std::string> {"do", "xbb"},
    std::pair<std::string, std::string> {"double", "t"},
    std::pair<std::string, std::string> {"dynamic_cast", "p(t)c(n@T0#)"},
    std::pair<std::string, std::string> {"else", "xa(_if_b)"},
    std::pair<std::string, std::string> {"enum", "b"},
    std::pair<std::string, std::string> {"explicit", "xbd(v)"},
    std::pair<std::string, std::string> {"export", "xb(_module_|d(f))"},
    std::pair<std::string, std::string> {"extern", "xbd(v)"},
    std::pair<std::string, std::string> {"false", "v"},
    std::pair<std::string, std::string> {"float", "t"},
    std::pair<std::string, std::string> {"for", "wb"},
    std::pair<std::string, std::string> {"friend", "xi(_class_|_struct_)xbd(v|f)"},
    std::pair<std::string, std::string> {"goto", "xbn"},
    std::pair<std::string, std::string> {"if", "c(n@b#)b"},
    std::pair<std::string, std::string> {"inline", "xbd(f)"},
    std::pair<std::string, std::string> {"int", "t"},
    std::pair<std::string, std::string> {"long", "(t|xbt)"},
    std::pair<std::string, std::string> {"mutable", ""},
    std::pair<std::string, std::string> {"namespace", "(xbb)|(xa_using_)"},
    std::pair<std::string, std::string> {"new", "xbt"},


    //TODO:continue here!!!;


    std::pair<std::string, std::string> {"noexcept", "xid(f)"},
    std::pair<std::string, std::string> {"not", "oe"},
    std::pair<std::string, std::string> {"not_eq", "ob"},
    std::pair<std::string, std::string> {"nullptr", "v"},
    std::pair<std::string, std::string> {"operator", "(xbod(f))|(xbodf(c())|(xb_new_)|(xb_delete_)"},
    std::pair<std::string, std::string> {"or", "ob"},
    std::pair<std::string, std::string> {"or_eq", "ob"},
    std::pair<std::string, std::string> {"private", "lxi(_class_|_struct_)"},
    std::pair<std::string, std::string> {"protected", "lxi(_class_|_struct_)"},
    std::pair<std::string, std::string> {"public", "lxi(_class_|_struct_)"},
    // std::pair<std::string, std::string> {"register", ""}, NOT AVAILABLE IN C++20
    std::pair<std::string, std::string> {"reinterpret_cast", "p(t)c(n@T0#)"},
    // std::pair<std::string, std::string> {"requires", ""},
    std::pair<std::string, std::string> {"return", "xif"},
    std::pair<std::string, std::string> {"short", "(t|xbt)"},
    std::pair<std::string, std::string> {"signed", "xbt"},
    std::pair<std::string, std::string> {"sizeof", "vc(t|n@T0#)"},
    std::pair<std::string, std::string> {"static", "xbd(v|f)"},
    std::pair<std::string, std::string> {"static_assert", "c(n@T0#&&n@T1#)"},
    std::pair<std::string, std::string> {"static_cast", "p(t)c(n@T0#)"},
    std::pair<std::string, std::string> {"struct", "z"},
    std::pair<std::string, std::string> {"switch", "xbb"},
    std::pair<std::string, std::string> {"template", "p($)b"},
    std::pair<std::string, std::string> {"this", "vx(i(_class_|_struct_)&i(f))"},
    std::pair<std::string, std::string> {"thread_local", "xbd(v)"},
    std::pair<std::string, std::string> {"throw", "xbe"},
    std::pair<std::string, std::string> {"true", "v"},
    std::pair<std::string, std::string> {"try", "b"},
    std::pair<std::string, std::string> {"typedef", "xbtn"},
    std::pair<std::string, std::string> {"typeid", "v(_std::size^_t_)c(@T0#)"},
    std::pair<std::string, std::string> {"typename", "txid(p)"},
    std::pair<std::string, std::string> {"union", "z"},
    std::pair<std::string, std::string> {"unsigned", "xbt"},
    std::pair<std::string, std::string> {"using", "(xb_namespace_n)|(xbn_=_n)"},
    std::pair<std::string, std::string> {"virtual", "(xi(_class_|_struct_))&(xbd(f))"},
    std::pair<std::string, std::string> {"void", "t"},
    std::pair<std::string, std::string> {"volatile", ""},
    std::pair<std::string, std::string> {"wchar_t", "t"},
    std::pair<std::string, std::string> {"while", "c(n@b#)b"},
    std::pair<std::string, std::string> {"xor", "ob"},
    std::pair<std::string, std::string> {"xor_eq", "ob"},
    std::pair<std::string, std::string> {"#assert", "r(1/2)"},
    std::pair<std::string, std::string> {"#define", "r(1/2)"},
    std::pair<std::string, std::string> {"#elif", "rv(b)"},
    std::pair<std::string, std::string> {"#else", "r0"},
    std::pair<std::string, std::string> {"#endif", "r0"},
    std::pair<std::string, std::string> {"#error", "rv(c*)"},
    std::pair<std::string, std::string> {"#ident", "rv(c*)"},
    std::pair<std::string, std::string> {"#if", "rv(b)"},
    std::pair<std::string, std::string> {"#ifdef", "rn"},
    std::pair<std::string, std::string> {"#ifndef", "rn"},
    std::pair<std::string, std::string> {"#import", "(r_<_n_>_)|(r_\"_n_\"_)"},
    std::pair<std::string, std::string> {"#include", "(r_<_n_>_)|(r_\"_n_\"_)"},
    std::pair<std::string, std::string> {"#include_next", "(r_<_n_>_)|(r_\"_n_\"_)"},
    std::pair<std::string, std::string> {"#line", "r(1/2)"},
    std::pair<std::string, std::string> {"#pragma", "r_once_"},
    std::pair<std::string, std::string> {"#sccs", "rv(c*)"},
    std::pair<std::string, std::string> {"#unassert", "r1"},
    std::pair<std::string, std::string> {"#undef", "rn"},
    std::pair<std::string, std::string> {"#warning", "rv(c*)"},
};










class Statement {
public:
    enum Types {
        NONE = 0,
        CLASS_DECLARATION = 1,
        PREPROCESSOR_DIRECTIVE = 2,
        VARIABLE_DECLARATION = 4,
        VARIABLE_INITIALIZATION_COPY = 8,
        VARIABLE_INITIALIZATION_DIRECT = 16,
        VARIABLE_INITIALIZATION_UNIFORM = 32,
        FUNCTION_DECLARATION = 64,
        FUNCTION_DEFINITION = 128,
        FUNCTION_CALL = 256,
        NORMAL = 512,
        KEYWORD = 1024,
        OPERATOR = 2048,
        NAME = 4096,
    };
    enum Modes {
        PREFIX = 8192,
        POSTFIX = 16384,
        BOTH = 32768,
    }

    /**
     * TODO: Make a function for parsing
     *TODO: Add parentheses after each v()
     *
     */
};

// class File {
//    
// }




class Scope {
    std::vector<Scope*> m_nested_namespaces;
public:
    enum Types {
        CLASS,
        STRUCT,
        UNION,
        NAMESPACE,
        FILE,
        EXTERNAL,
    };
protected:
    Types m_type;
    std::vector<Variable> m_members;
    std::vector<Function> m_methods;
    //Stands for class/struct/enum names.
    std::vector<std::string> m_types;
    std::map<std::string, std::vector<Scope>> m_objects;
    std::vector<Statement> m_statements;
public:
    Scope() : m_members{}, m_methods{}, m_objects{}, m_statements{} {}
    Scope(const std::vector<Statement>& statements) : m_members{}, m_methods{}, m_objects{}, m_statements{ statements } {}
    //TODO: this
    Scope& add_scope() {}
} /* global{} */;

std::vector<Statement> parse(std::fstream& file) {
    std::stringstream ss{ file };
}

class Exception : public std::exception {
    std::string message;
public:
    Exception(const char* m = "") : message{ m } {}

    virtual const char* what() const noexcept override {
        return message.c_str();
        // return "DContainer is out of bounds";
    }
};

template<class T>
class DContainer {
protected:
    T* m_contents;
    std::size_t m_size;
    std::size_t m_allocated;
public:
    DContainer(int size = 0) : m_contents{ (T*)malloc(size) }, m_size{ size }, m_allocated{ size } {}
    DContainer(std::initializer_list<T> list) : m_contents{ (T*)malloc(list.size() * sizeof(T)) }, m_size{ list.size() } {
        T* ptr{ m_contents };
        for (const T& i : list) {
            *(m_contents++) = i;
        }
    }
    ~DContainer() {
        free(m_contents);
    }
    T& operator[] (std::size_t index) {
        if (index < 0) index += m_size;
        if (index >= m_size || index < 0) {
            throw Exception{ "DContainer is out of bounds" };
        }
        return *(index + m_contents);
    }
    DContainer<T>& push_back(const T& element) {
        ++m_size;
        if (m_size > m_allocated) {
            m_contents = realloc(m_contents, (std::size_t)(m_size * 1.5 + 1));
            m_allocated = (std::size_t)(m_size * 1.5 + 1);
        }
        *(m_contents + m_size - 1) = element;
        return *this;
    }
    DContainer<T>& pop_back() {
        --m_size;
        if (m_size < (std::size_t)(m_allocated * 0.7)) {
            m_contents = realloc(m_contents, (std::size_t)(m_size * 0.7 + 1));
            m_allocated = (std::size_t)(m_size * 0.7 + 1);
        }
        return *this;
    }
    friend std::stringstream& operator<< (std::stringstream& ss, DContainer<T>& dc) {
        for (int i{ 0 }; i < m_size; ++i) ss << dc[i];
        return ss;
    }
    std::size_t size() const {
        return m_size;
    }
};

struct Expectance {
public:
    Statement::Types type;
    //Contains all the possible ones, 
    // std::vector<std::vector<Statement::Types>> expectances;
    std::vector<std::vector<Statement::Types>> expectances;
    //TODO:Note: junction: true is conjunction, while false is disjunction
    std::vector<bool> junction;
    Expectance(int tp = Statement::Types::NAME, Statement::Types tp0 = Statement::Types::NAME) : type{ Statement::Types::NONE }, expectances{} {
        if (tp & Statement::Types::OPERATOR) {
            expectances.resize(1);
            if (tp & Statement::Modes::BOTH) {
                expectances[0].push_back(Statement::Types::NAME);
                expectances[0].push_back(Statement::Types::OPERATOR);
                expectances[0].push_back(Statement::Types::NAME);
            }
            else if (tp & Statement::Modes::PREFIX) {
                expectances[0].push_back(Statement::Types::OPERATOR);
                expectances[0].push_back(Statement::Types::NAME);
            }
            else if (tp & Statement::Modes::POSTFIX) {
                expectances[0].push_back(Statement::Types::NAME);
                expectances[0].push_back(Statement::Types::OPERATOR);
            }
        }
        else if (tp & Statement::Types::PREPROCESSOR_DIRECTIVE) {
            expectances.resize(1);
            expectances[0].push_back(Statement::Types::PREPROCESSOR_DIRECTIVE);
        }
        else if (tp&)



            expectances[0].push_back();
    }

};

void read_keyword_expression(bool first = true, int& i) {
    int paren{ 0 };
    bool closed{ false };
    std::string current_string{ "" };
    char first;
    int counter{ 0 };
    for (int i{ 0 }; i < (*iter).second.size(); ++i, counter = (counter && !paren) ? counter - 1 : counter) {
        switch ((*iter).second[i]) {
        case '(':
            ++paren;
            closed = false;
            current_string += '(';
            break;
        case ')':
            --paren;
            closed = true;
            current_string += ')';
            break;
        case 't':
        case 'n':
        case 'l':
        case 'b':
        case 'z':
        case 'f':
        case 'w':
        case 's':
        case 'e':
        case 'p':
        case 's':
        case 'r':





        case 'd':
        case 'o':
        case 'x':
        case 'v':
        case 'c':


        }
        if (paren < 0) throw "did not expect closing parenthesis. \n";
        if (!counter || closed) {

        }
    }
}

// class Queue {

// };

class Counter {
public:
    std::size_t size, allocated;
    bool closed;
    short int* current, parenthesis_layers;
    std::vector<std::string> message;
    Counter() : size{ 0 }, allocated{ 0 }, current{ (short int*)(malloc(sizeof(short int) * size)) }, parenthesis_layers{ 0 }, closed{ false } {}
    operator bool() {
        return size == 0 ? false : (!current[size - 1]);
    }
    Counter& addCounter(short int counter = 1) {
        short int* holder{ current };
        if (allocated == size) {
            if ((current = (short int*)realloc(current, (++size, ++allocated))) == NULL) {
                current = holder;
                --size;
                throw "Cannot allocate more. ";
            }
        }
        else ++size;
        current[size - 1] = counter;
    }
    Counter& openParenthesis(char layers = 1) {
        parenthesis_layers += layers;
        closed = false;
        return *this;
    }
    Counter& closeParenthesis(char layers = 1) {
        if (layers > parenthesis_layers) throw "Closing too many parentheses. ";
        parenthesis_layers -= layers;
        closed = true;
        return *this;
    }
    Counter& operator--() {
        while (!current[size - 1]) {
            --size;
        }
        --current[size - 1];
        closed = false;
        return *this;
    }
};

Expectance type(std::string s) {
    std::map<std::string, std::string>::iterator iter;
    Expectance e;
    if ((iter = key.find(s)) != key.end()) {
        if (std::distance(iter, key.find("#assert")) > 0) {
            int paren{ 0 };
            bool closed{ false }, is_v{ false };
            std::string current_string{ "" };
            char first;
            bool is_first{ true };
            int counter{ 0 };
            Counter ct{};
            for (int i{ 0 }; i < (*iter).second.size(); ++i, counter = (counter && !paren) ? counter - 1 : counter) {
                switch ((*iter).second[i]) {
                case '(':
                    ++paren;
                    closed = false;
                    current_string += '(';
                    ct.openParenthesis();
                    break;
                case ')':
                    --paren;
                    closed = true;
                    current_string += ')';
                    ct.closeParenthesis();
                    break;
                case 'o':
                    if (is_first) {
                        switch ((*iter).second[i + 1]) {
                        case 'e':
                            Expectance ep{ Statement::Types::OPERATOR | Statement::Modes::PREFIX };
                            break;
                        case 'o':
                            Expectance ep{ Statement::Types::OPERATOR | Statement::Modes::POSTFIX };
                            break;
                        case 'b':
                            Expectance ep{ Statement::Types::OPERATOR | Statement::Modes::BOTH };
                            break;

                        };
                    }
                    ep.expectances.push_back;
                    ep.expectances[0].push_back("");
                    switch ((*iter).second[1]) {
                        ca
                    };
                }


        case 'v':
            if (!counter)
        case 'd':
        case 'o':
        case 'c':
        case 'x':






        case 't':
        case 'n':
        case 'l':
        case 'b':
        case 'z':
        case 'f':
        case 'w':
        case 's':
        case 'e':
        case 'p':
        case 's':
        case 'r':







            }
            --ct;

            if (paren < 0) throw "did not expect closing parenthesis. \n";
            if (!counter || closed) {

            }
            closed = false;
            is_first = false;
        }
    }
    else {
        return Statement::Types::PREPROCESSOR_DIRECTIVE;
    }
    return Statement::Types::KEYWORD;
}
if (Types::operators.find(s) != Types::operator.end()) {
    return Statement::Types::OPERATOR;
}
// if (std::find(Types::order.begin(), Types::order.end(), s) != Types::order.end()) {
//     return Statement::Types::TYPE;
// }
return Statement::Types::NAME;
}

std::vector<Statement> parse(FILE* file) {
    DContainer<char> container{ 0 };
    int c;
    while ((c = fgetc(file)) != EOF) {
        container.push_back(c);
    }
    std::stringstream ss{};
    ss << container;
    std::vector<Statement> statements;
    short int mode{ 0 };
    bool end_of_term;
    /**
     * @brief
     *  Modes:
     *      0 : not in statement
     *      1 : in statement
     *      2 : in preprocessor directive
     */
    std::string currentTerm{ "" }, wholeStatement{ "" };
    for (int i{ 0 }; i < container.size(); ++i) {

        switch (container[i]) {
        case '\n':
            if (mode == 2) {

                break;
            }
        case ' ':
            if (mode) {
                break;
            }
        case '\t':
            if (mode) {
                break;
            }
        case 'EOF':
            if (mode) {
                break;
            }
            continue;
        case '0' ... '9':
            if (currentTerm == "")
        case 'a' ... 'z':
        case 'A' ... 'Z':
            currentTerm += container[i];
        case '#':
            if (currentTerm == "") {
                mode = 2;
            }
            currentTerm += container[i];



        default:

        }
        if (end_of_term) {
            auto a = type(currentTerm);
            if (a == )
        }
    }



    // std::stringstream ss{ file };

}

