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

    std::map<std::string, std::string> operators{
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
    std::vector<std::string> type_modifiers{
        "",
        "*",
        "&",
        "()"
    };
    std::vector<std::string> order{
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
    wchar_t a;
    // std::string<
    std::string getReturnType(std::string operator_1, std::string type_1, std::string type_2 = "") {
        std::vector<std::string>::iterator a{ std::find(order.begin(), order.end(), type_1) }, b{ std::find(order.begin(), order.end(), type_2) };
        return a > b ? *a : *b;

    }
};



class Operator {
    std::string
};

class Variable {
    std::string name;
    std::string m_type;
};

class Expression {
    bool m_contains_variable;
    Operator m_operator;
    Variable* m_variable;
    Expression* m_variable_primary;
    Expression* m_variable_secondary;
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

class Statement {
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
     *  v : value
     *  p : template (used like c)
     *  c : function-like (c)all
     *      has to be followed by parentheses which contain:
     *          what is expected like (t)ypes, (n)ames, etc.
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
     *TODO:add for ones that don't need semicolon (s)
     */
    std::map<std::string, std::string> key{
        std::pair<std::string, std::string> {"alignas", "c(n@i#)xbd(v|c|s)"},
        std::pair<std::string, std::string> {"alignof", "c(t)"},
        std::pair<std::string, std::string> {"and", "ob"},
        std::pair<std::string, std::string> {"and_eq", "ob"},
        std::pair<std::string, std::string> {"asm", "ob"},
        std::pair<std::string, std::string> {"auto", "t"},
        std::pair<std::string, std::string> {"bitand", "ob"},
        std::pair<std::string, std::string> {"bitor", "ob"},
        std::pair<std::string, std::string> {"bool", "t"},
        std::pair<std::string, std::string> {"break", "sxi(_for_|_while_|_do_|_switch_)"},
        std::pair<std::string, std::string> {"case", "lxi_switch_"},
        std::pair<std::string, std::string> {"catch", "bxa"},
        std::pair<std::string, std::string> {"char", "t"},
        std::pair<std::string, std::string> {"char8_t", "t"},
        std::pair<std::string, std::string> {"char16_t", "t"},
        std::pair<std::string, std::string> {"char32_t", "t"},
        std::pair<std::string, std::string> {"class", "z"},
        std::pair<std::string, std::string> {"compl", "oe"},
        // std::pair<std::string, std::string> {"concept", ""},
        std::pair<std::string, std::string> {"const", "xbt"},
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
        std::pair<std::string, std::string> {"long", "t"},
        std::pair<std::string, std::string> {"mutable", ""},
        std::pair<std::string, std::string> {"namespace", "(xbb)|(xa_using_)"},
        std::pair<std::string, std::string> {"new", "xbt"},


        //TODO:continue here!!!


                std::pair<std::string, std::string> {"noexcept", ""},
                std::pair<std::string, std::string> {"not", ""},
                std::pair<std::string, std::string> {"not_eq", ""},
                std::pair<std::string, std::string> {"nullptr", ""},
                std::pair<std::string, std::string> {"operator", ""},
                std::pair<std::string, std::string> {"or", ""},
                std::pair<std::string, std::string> {"or_eq", ""},
                std::pair<std::string, std::string> {"private", ""},
                std::pair<std::string, std::string> {"protected", ""},
                std::pair<std::string, std::string> {"public", ""},
                std::pair<std::string, std::string> {"register", ""},
                std::pair<std::string, std::string> {"reinterpret_cast", ""},
                std::pair<std::string, std::string> {"requires", ""},
                std::pair<std::string, std::string> {"return", ""},
                std::pair<std::string, std::string> {"short", ""},
                std::pair<std::string, std::string> {"signed", ""},
                std::pair<std::string, std::string> {"sizeof", ""},
                std::pair<std::string, std::string> {"static", ""},
                std::pair<std::string, std::string> {"static_assert", ""},
                std::pair<std::string, std::string> {"static_cast", ""},
                std::pair<std::string, std::string> {"struct", ""},
                std::pair<std::string, std::string> {"switch", ""},
                std::pair<std::string, std::string> {"template", ""},
                std::pair<std::string, std::string> {"this", ""},
                std::pair<std::string, std::string> {"thread_local", ""},
                std::pair<std::string, std::string> {"throw", ""},
                std::pair<std::string, std::string> {"true", ""},
                std::pair<std::string, std::string> {"try", ""},
                std::pair<std::string, std::string> {"typedef", ""},
                std::pair<std::string, std::string> {"typeid", ""},
                std::pair<std::string, std::string> {"typename", ""},
                std::pair<std::string, std::string> {"union", ""},
                std::pair<std::string, std::string> {"unsigned", ""},
                std::pair<std::string, std::string> {"using", ""},
                std::pair<std::string, std::string> {"virtual", ""},
                std::pair<std::string, std::string> {"void", ""},
                std::pair<std::string, std::string> {"volatile", ""},
                std::pair<std::string, std::string> {"wchar_t", ""},
                std::pair<std::string, std::string> {"while", ""},
                std::pair<std::string, std::string> {"xor", ""},
                std::pair<std::string, std::string> {"xor_eq", ""},
    }
};