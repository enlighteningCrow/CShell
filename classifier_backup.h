#include <bits/stdc++.h>

#include "misc.h"
#include "utils.h"

std::vector<std::string> types;
std::vector<std::string>;

enum STypes {
  NONE = 0ULL,
  // CLASS_DECLARATION = (1 << 0),
  // PREPROCESSOR_DIRECTIVE = (1 << 1),
  // VARIABLE_DECLARATION = (1 << 2),
  // VARIABLE_INITIALIZATION_COPY = (1 << 3),
  // VARIABLE_INITIALIZATION_DIRECT = (1 << 4),
  // VARIABLE_INITIALIZATION_UNIFORM = (1 << 5),
  // FUNCTION_DECLARATION = (1 << 6),
  // FUNCTION_DEFINITION = (1 << 7),
  // FUNCTION_CALL = (1 << 8),
  // NORMAL = (1 << 9),
  // KEYWORD = (1 << 10),
  OPERATOR = (1ULL << 0),
  NAME = (1ULL << 1),
  TYPE = (1ULL << 2),
  VOID_TYPE = (1ULL << 3),
  TYPE_MODIFIER = (1ULL << 4),
  LABEL = (1ULL << 5),
  STATEMENT = (1ULL << 6),
  PARENTHESIS = (1ULL << 7),
  CURLY_BRACE = (1ULL << 8),
  BRACE = (1ULL << 9),
  MULTIPLE = (1ULL << 10),
  OPTIONAL = (1ULL << 11),
  ASTERISK = (1ULL << 12),
  ASTERISK_OR_AMPERSAND = (1ULL << 12),
  ASSIGMENT = (1ULL << 13),
  COMMA = (1ULL << 14),
  STRUCT = (1ULL << 15),
  ENUM = (1ULL << 16),
  CASE = (1ULL << 17),
  WHOLE_STATEMENT = (1ULL << 18),
  DO = (1ULL << 19),
  WHILE = (1ULL << 20),
  FOR = (1ULL << 21),
  GOTO = (1ULL << 22),
  IF = (1ULL << 23),
  ELSE = (1ULL << 24),
  SIZEOF = (1UL << 25),
  RETURN = (1UL << 26),
  SWITCH = (1UL << 27),
  BREAK = (1UL << 28),
  TYPEDEF = (1UL << 29),
  UNION = (1UL << 30),
  QUESTION = (1UL << 31),
  QELSE = (1UL << 32),
  DOT = (1UL << 33),
  ARROW = (1UL << 34),
  COLON = (1ULL << 35),
  PREPROCESSOR_DEFINE = (1UL << 36),
  PREPROCESSOR_ELIF = (1UL << 37),
  PREPROCESSOR_ELSE = (1UL << 38),
  PREPROCESSOR_ENDIF = (1UL << 39),
  PREPROCESSOR_ERROR = (1UL << 40),
  PREPROCESSOR_IF = (1UL << 41),
  PREPROCESSOR_IFDEF = (1UL << 42),
  PREPROCESSOR_IFNDEF = (1UL << 43),
  PREPROCESSOR_INCLUDE = (1UL << 44),
  PREPROCESSOR_PRAGMA = (1UL << 45),
  PREPROCESSOR_UNDEF = (1UL << 46),
  REQUIRE_LVALUE = (1ULL << 54),
  SEMICOLON = (1ULL << 55),
  LITERAL = (1ULL << 56),
  COMMA_AND_NAME = (1ULL << 57),
  COMMA_TYPE_AND_NAME = (1ULL << 58),
  PREFIX = (1ULL << 59),
  POSTFIX = (1ULL << 60),
  BOTH = (1ULL << 61),
  OPEN = (1ULL << 62),
  CLOSE = (1ULL << 63),
};

enum JunctionMode {
  IN = (1ULL << 0),
  AFTER = (1ULL << 1),
};

// enum STypes {
//     NONE = 0,
//     CLASS_DECLARATION = (1 << 0),
//     PREPROCESSOR_DIRECTIVE = (1 << 1),
//     VARIABLE_DECLARATION = (1 << 2),
//     VARIABLE_INITIALIZATION_COPY = (1 << 3),
//     VARIABLE_INITIALIZATION_DIRECT = (1 << 4),
//     VARIABLE_INITIALIZATION_UNIFORM = (1 << 5),
//     FUNCTION_DECLARATION = (1 << 6),
//     FUNCTION_DEFINITION = (1 << 7),
//     FUNCTION_CALL = (1 << 8),
//     NORMAL = (1 << 9),
//     KEYWORD = (1 << 10),
//     OPERATOR = (1 << 11),
//     NAME = (1 << 12),
//     TYPE = (1 << 13),
//     TYPE_MODIFIER = (1 << 14),
//     LABEL = (1 << 15),
//     STATEMENT = (1 << 16),
//     PARENTHESIS = (1 << 17),
//     CURLY_BRACE = (1 << 18),
//     BRACE = (1 << 19),
//     MULTIPLE = (1 << 20),
//     OPTIONAL = (1 << 21),
//     ASTERISK_OR_AMPERSAND = (1 << 22),
//     COMMA = (1 << 23),
//     COMMA_AND_NAME = (1 << 25),
//     COMMA_TYPE_AND_NAME = (1 << 26),
//     PREFIX = (1 << 27),
//     POSTFIX = (1 << 28),
//     BOTH = (1 << 29),
//     OPEN = (1 << 30),
//     CLOSE = (1 << 31),
// };
struct Types {
 public:
  String type_name;
  Array<Pair<Types, String>> type_vars;
  Types(const String& name, const Array<Pair<Types, String>>& vars)
      : type_name{name}, type_vars{vars} {}
};

// types += Types{ "char", Array<Pair<Types, String>>(0) };

// std::pair<std::size_t, Types>{
Array<Types> types{Types{"char", Array<Pair<Types, String>>(0)},
                   Types{"int", Array<Pair<Types, String>>(0)},
                   Types{"float", Array<Pair<Types, String>>(0)},
                   Types{"double", Array<Pair<Types, String>>(0)}};

class Types_bck {
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
      std::pair<std::string, std::string>{"=", "b"},
      std::pair<std::string, std::string>{"+", "b"},
      std::pair<std::string, std::string>{"-", "b"},
      std::pair<std::string, std::string>{"*", "b"},
      std::pair<std::string, std::string>{"/", "b"},
      std::pair<std::string, std::string>{"%", "b"},
      std::pair<std::string, std::string>{"+=", "b"},
      std::pair<std::string, std::string>{"-=", "b"},
      std::pair<std::string, std::string>{"*=", "b"},
      std::pair<std::string, std::string>{"/=", "b"},
      std::pair<std::string, std::string>{"%=", "b"},
      std::pair<std::string, std::string>{">>=", "b"},
      std::pair<std::string, std::string>{"<<=", "b"},
      std::pair<std::string, std::string>{"&=", "b"},
      std::pair<std::string, std::string>{"^=", "b"},
      std::pair<std::string, std::string>{"|=", "b"},
      std::pair<std::string, std::string>{"++", "t"},
      // std::pair<std::string, std::string> {"++E", "e"},
      // std::pair<std::string, std::string> {"++O", "o"},
      std::pair<std::string, std::string>{"--", "t"},
      // std::pair<std::string, std::string> {"--E", "e"},
      // std::pair<std::string, std::string> {"--O", "o"},
      std::pair<std::string, std::string>{"==", "b"},
      std::pair<std::string, std::string>{"!=", "b"},
      std::pair<std::string, std::string>{">", "b"},
      std::pair<std::string, std::string>{"<", "b"},
      std::pair<std::string, std::string>{">=", "b"},
      std::pair<std::string, std::string>{"<=", "b"},
      std::pair<std::string, std::string>{"!", "e"},
      std::pair<std::string, std::string>{"&&", "b"},
      std::pair<std::string, std::string>{"||", "b"},
      std::pair<std::string, std::string>{"?", "b"},
      std::pair<std::string, std::string>{":", "b"},
      std::pair<std::string, std::string>{",", "b"},
      std::pair<std::string, std::string>{"&", "b"},
      std::pair<std::string, std::string>{"|", "b"},
      std::pair<std::string, std::string>{"^", "b"},
      std::pair<std::string, std::string>{"~", "e"},
      std::pair<std::string, std::string>{"<<", "b"},
      std::pair<std::string, std::string>{">>", "b"},
      std::pair<std::string, std::string>{"()__CAST__", "ei"},
      std::pair<std::string, std::string>{"::", "b"},
      std::pair<std::string, std::string>{"()", "oi"},
      std::pair<std::string, std::string>{"[]", "oi"},
      std::pair<std::string, std::string>{".", "b"},
      std::pair<std::string, std::string>{"->", "b"},
      std::pair<std::string, std::string>{"&__PTR__", "e"},
      std::pair<std::string, std::string>{"*__PTR__", "e"},

      // TODO: Not so sure about putting space here after new and delete
      std::pair<std::string, std::string>{"new ", "e"},
      std::pair<std::string, std::string>{"delete ", "e"},
      std::pair<std::string, std::string>{"sizeof()", "ei"},

  };
  static std::vector<std::string> type_modifiers{"", "*", "&", "()"};
  static std::vector<std::string> order{"void",
                                        "bool",
                                        "char",
                                        "wchar_t",
                                        "short int",
                                        "int"
                                        "long int",
                                        "long long int",
                                        "float"
                                        "double"
                                        "long double"};
  // wchar_t a;
  // std::string<
  static std::string getReturnType(std::string operator_1, std::string type_1,
                                   std::string type_2 = "") {
    std::vector<std::string>::iterator a{
        std::find(order.begin(), order.end(), type_1)},
        b{std::find(order.begin(), order.end(), type_2)};
    return a > b ? *a : *b;
  }

 protected:
  std::string m_type;

 public:
  const std::string& get_type() const { return m_type; }
  bool operator==(const Types_bck& type) const { return type.m_type == m_type; }
};

class Operator {
  std::string HOLDER123;
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
  Expression(std::string) : m_evaluated_type{m_evaluated_type} {}
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
 *          (T(n)) stands for template: T(0) == T(0) but might not be == to T(1)
 *(); e : expression p : template (used like c) c : function-like (c)all has to
 *be followed by parentheses which contain: what is expected like (t)ypes,
 *(n)ames, etc.
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
 *          (T(n)) stands for template: T(0) == T(0) but might not be == to T(1)
 *();
 *
 *          Note: names also include literal values
 *          and use || for separating param sets
 *          and use && for separating each inside the param set
 *          // and use $c/T? for template parameters with c params
 *          such as (t&&t) for something that receieves 2 types
 *          or (n@i#&&n@d#) for something that receieves 2 types
 *          or (n@i/c#&&n@0=#) for something that receieves (int, int) or (char,
 *char) or (n@2i/d#&&n@f/2=#) for something that receieves (int, float) or (int,
 *int), (double, double) or (n@0T0#&&n@0=#&&n@i/d/ud/uc#) for something that
 *receieves (T0, T0, int), (T0, T0, double), (T0, T0, unsigned double), (T0, T0,
 *unsigned char) or (n@0T0#&&n@0T1#&&n@i/d/ud/uc#) for something that receieves
 *(T0, T1, int), (T0, T1, double), (T0, T1, unsigned double), (T0, T1, unsigned
 *char)
 *          TODO:CAUTION : check if all of them are 0; if all are zero, it
 *receives nothing
 *
 *  s : (s)elf (alone)
 *  r : p(r)eprocessor directive
 *  _sth_%b means inside the block of sth
 *  ^ is an escape sequence, so ^_ means just _, so not confused with _$(name)_
 *TODO:add for ones that don't need semicolon (s)
 */
std::map<std::string, std::string> key_cpp{
    std::pair<std::string, std::string>{"alignas", "c(n@i#)xbd(v|c|s)"},
    std::pair<std::string, std::string>{"alignof", "c(t)v(ul)"},
    std::pair<std::string, std::string>{"and", "ob"},
    std::pair<std::string, std::string>{"and_eq", "ob"},
    std::pair<std::string, std::string>{"asm", "ob"},
    std::pair<std::string, std::string>{"auto", "t"},
    std::pair<std::string, std::string>{"bitand", "ob"},
    std::pair<std::string, std::string>{"bitor", "ob"},
    std::pair<std::string, std::string>{"bool", "t"},
    std::pair<std::string, std::string>{"break",
                                        "sxi(_for_|_while_|_do_|_switch_)"},
    std::pair<std::string, std::string>{"case", "lxi_switch_"},
    std::pair<std::string, std::string>{"catch", "xa_throw%b_d(f)"},
    std::pair<std::string, std::string>{"char", "t"},
    std::pair<std::string, std::string>{"char8_t", "t"},
    std::pair<std::string, std::string>{"char16_t", "t"},
    std::pair<std::string, std::string>{"char32_t", "t"},
    std::pair<std::string, std::string>{"class", "z|txid(p)"},
    std::pair<std::string, std::string>{"compl", "oe"},
    // std::pair<std::string, std::string> {"concept", ""},
    std::pair<std::string, std::string>{"const",
                                        "x(bt|i(_class_|_struct_)&id(f)|at)"},
    std::pair<std::string, std::string>{"consteval", "xbd(f)"},
    std::pair<std::string, std::string>{"constexpr", "xbt"},
    std::pair<std::string, std::string>{"constinit", "xbt"},
    std::pair<std::string, std::string>{"const_cast", "p(t)c(n@T0#)"},
    std::pair<std::string, std::string>{"continue", "sxi(_for_|_while_|_do_)"},
    // std::pair<std::string, std::string> {"co_await", ""},
    // std::pair<std::string, std::string> {"co_return", ""},
    // std::pair<std::string, std::string> {"co_yield", ""},
    std::pair<std::string, std::string>{"decltype", "tc(n@T0#)"},
    std::pair<std::string, std::string>{"default", "(lxi_switch_)|(vc(@#))"},
    std::pair<std::string, std::string>{"delete", "xbn"},
    std::pair<std::string, std::string>{"do", "xbb"},
    std::pair<std::string, std::string>{"double", "t"},
    std::pair<std::string, std::string>{"dynamic_cast", "p(t)c(n@T0#)"},
    std::pair<std::string, std::string>{"else", "xa(_if_b)"},
    std::pair<std::string, std::string>{"enum", "b"},
    std::pair<std::string, std::string>{"explicit", "xbd(v)"},
    std::pair<std::string, std::string>{"export", "xb(_module_|d(f))"},
    std::pair<std::string, std::string>{"extern", "xbd(v)"},
    std::pair<std::string, std::string>{"false", "v"},
    std::pair<std::string, std::string>{"float", "t"},
    std::pair<std::string, std::string>{"for", "wb"},
    std::pair<std::string, std::string>{"friend",
                                        "xi(_class_|_struct_)xbd(v|f)"},
    std::pair<std::string, std::string>{"goto", "xbn"},
    std::pair<std::string, std::string>{"if", "c(n@b#)b"},
    std::pair<std::string, std::string>{"inline", "xbd(f)"},
    std::pair<std::string, std::string>{"int", "t"},
    std::pair<std::string, std::string>{"long", "(t|xbt)"},
    std::pair<std::string, std::string>{"mutable", ""},
    std::pair<std::string, std::string>{"namespace", "(xbb)|(xa_using_)"},
    std::pair<std::string, std::string>{"new", "xbt"},

    // TODO:continue here!!!;

    std::pair<std::string, std::string>{"noexcept", "xid(f)"},
    std::pair<std::string, std::string>{"not", "oe"},
    std::pair<std::string, std::string>{"not_eq", "ob"},
    std::pair<std::string, std::string>{"nullptr", "v"},
    std::pair<std::string, std::string>{
        "operator", "(xbod(f))|(xbodf(c())|(xb_new_)|(xb_delete_)"},
    std::pair<std::string, std::string>{"or", "ob"},
    std::pair<std::string, std::string>{"or_eq", "ob"},
    std::pair<std::string, std::string>{"private", "lxi(_class_|_struct_)"},
    std::pair<std::string, std::string>{"protected", "lxi(_class_|_struct_)"},
    std::pair<std::string, std::string>{"public", "lxi(_class_|_struct_)"},
    // std::pair<std::string, std::string> {"register", ""}, NOT AVAILABLE IN
    // C++20
    std::pair<std::string, std::string>{"reinterpret_cast", "p(t)c(n@T0#)"},
    // std::pair<std::string, std::string> {"requires", ""},
    std::pair<std::string, std::string>{"return", "xif"},
    std::pair<std::string, std::string>{"short", "(t|xbt)"},
    std::pair<std::string, std::string>{"signed", "xbt"},
    std::pair<std::string, std::string>{"sizeof", "vc(t|n@T0#)"},
    std::pair<std::string, std::string>{"static", "xbd(v|f)"},
    std::pair<std::string, std::string>{"static_assert", "c(n@T0#&&n@T1#)"},
    std::pair<std::string, std::string>{"static_cast", "p(t)c(n@T0#)"},
    std::pair<std::string, std::string>{"struct", "z"},
    std::pair<std::string, std::string>{"switch", "xbb"},
    std::pair<std::string, std::string>{"template", "p($)b"},
    std::pair<std::string, std::string>{"this", "vx(i(_class_|_struct_)&i(f))"},
    std::pair<std::string, std::string>{"thread_local", "xbd(v)"},
    std::pair<std::string, std::string>{"throw", "xbe"},
    std::pair<std::string, std::string>{"true", "v"},
    std::pair<std::string, std::string>{"try", "b"},
    std::pair<std::string, std::string>{"typedef", "xbtn"},
    std::pair<std::string, std::string>{"typeid", "v(_std::size^_t_)c(@T0#)"},
    std::pair<std::string, std::string>{"typename", "txid(p)"},
    std::pair<std::string, std::string>{"union", "z"},
    std::pair<std::string, std::string>{"unsigned", "xbt"},
    std::pair<std::string, std::string>{"using", "(xb_namespace_n)|(xbn_=_n)"},
    std::pair<std::string, std::string>{"virtual",
                                        "(xi(_class_|_struct_))&(xbd(f))"},
    std::pair<std::string, std::string>{"void", "t"},
    std::pair<std::string, std::string>{"volatile", ""},
    std::pair<std::string, std::string>{"wchar_t", "t"},
    std::pair<std::string, std::string>{"while", "c(n@b#)b"},
    std::pair<std::string, std::string>{"xor", "ob"},
    std::pair<std::string, std::string>{"xor_eq", "ob"},
    std::pair<std::string, std::string>{"#assert", "r(1/2)"},
    std::pair<std::string, std::string>{"#define", "r(1/2)"},
    std::pair<std::string, std::string>{"#elif", "rv(b)"},
    std::pair<std::string, std::string>{"#else", "r0"},
    std::pair<std::string, std::string>{"#endif", "r0"},
    std::pair<std::string, std::string>{"#error", "rv(c*)"},
    std::pair<std::string, std::string>{"#ident", "rv(c*)"},
    std::pair<std::string, std::string>{"#if", "rv(b)"},
    std::pair<std::string, std::string>{"#ifdef", "rn"},
    std::pair<std::string, std::string>{"#ifndef", "rn"},
    std::pair<std::string, std::string>{"#import", "(r_<_n_>_)|(r_\"_n_\"_)"},
    std::pair<std::string, std::string>{"#include", "(r_<_n_>_)|(r_\"_n_\"_)"},
    std::pair<std::string, std::string>{"#include_next",
                                        "(r_<_n_>_)|(r_\"_n_\"_)"},
    std::pair<std::string, std::string>{"#line", "r(1/2)"},
    std::pair<std::string, std::string>{"#pragma", "r_once_"},
    std::pair<std::string, std::string>{"#sccs", "rv(c*)"},
    std::pair<std::string, std::string>{"#unassert", "r1"},
    std::pair<std::string, std::string>{"#undef", "rn"},
    std::pair<std::string, std::string>{"#warning", "rv(c*)"},
};

std::map<std::string, std::string> key_mixed{
    // std::pair<std::string, std::string> {"alignas", "c(n@i#)xbd(v|c|s)"},
    // std::pair<std::string, std::string> {"alignof", "c(t)v(ul)"},
    std::pair<std::string, std::string>{"and", "ob"},
    std::pair<std::string, std::string>{"and_eq", "ob"},
    // std::pair<std::string, std::string> {"asm", "ob"},
    std::pair<std::string, std::string>{"auto", "t"},
    std::pair<std::string, std::string>{"bitand", "ob"},
    std::pair<std::string, std::string>{"bitor", "ob"},
    std::pair<std::string, std::string>{"bool", "t"},
    std::pair<std::string, std::string>{"break",
                                        "sxi(_for_|_while_|_do_|_switch_)"},
    std::pair<std::string, std::string>{"case", "lxi_switch_"},
    std::pair<std::string, std::string>{"catch", "xa_throw%b_d(f)"},
    std::pair<std::string, std::string>{"char", "t"},
    std::pair<std::string, std::string>{"char8_t", "t"},
    std::pair<std::string, std::string>{"char16_t", "t"},
    std::pair<std::string, std::string>{"char32_t", "t"},
    std::pair<std::string, std::string>{"class", "z|txid(p)"},
    std::pair<std::string, std::string>{"compl", "oe"},
    // std::pair<std::string, std::string> {"concept", ""},
    std::pair<std::string, std::string>{"const",
                                        "x(bt|i(_class_|_struct_)&id(f)|at)"},
    std::pair<std::string, std::string>{"consteval", "xbd(f)"},
    std::pair<std::string, std::string>{"constexpr", "xbt"},
    std::pair<std::string, std::string>{"constinit", "xbt"},
    std::pair<std::string, std::string>{"const_cast", "p(t)c(n@T0#)"},
    std::pair<std::string, std::string>{"continue", "sxi(_for_|_while_|_do_)"},
    // std::pair<std::string, std::string> {"co_await", ""},
    // std::pair<std::string, std::string> {"co_return", ""},
    // std::pair<std::string, std::string> {"co_yield", ""},
    std::pair<std::string, std::string>{"decltype", "tc(n@T0#)"},
    std::pair<std::string, std::string>{"default", "(lxi_switch_)|(vc(@#))"},
    std::pair<std::string, std::string>{"delete", "xbn"},
    std::pair<std::string, std::string>{"do", "xbb"},
    std::pair<std::string, std::string>{"double", "t"},
    std::pair<std::string, std::string>{"dynamic_cast", "p(t)c(n@T0#)"},
    std::pair<std::string, std::string>{"else", "xa(_if_b)"},
    std::pair<std::string, std::string>{"enum", "b"},
    std::pair<std::string, std::string>{"explicit", "xbd(v)"},
    std::pair<std::string, std::string>{"export", "xb(_module_|d(f))"},
    std::pair<std::string, std::string>{"extern", "xbd(v)"},
    std::pair<std::string, std::string>{"false", "v"},
    std::pair<std::string, std::string>{"float", "t"},
    std::pair<std::string, std::string>{"for", "wb"},
    std::pair<std::string, std::string>{"friend",
                                        "xi(_class_|_struct_)xbd(v|f)"},
    std::pair<std::string, std::string>{"goto", "xbn"},
    std::pair<std::string, std::string>{"if", "c(n@b#)b"},
    std::pair<std::string, std::string>{"inline", "xbd(f)"},
    std::pair<std::string, std::string>{"int", "t"},
    std::pair<std::string, std::string>{"long", "(t|xbt)"},
    std::pair<std::string, std::string>{"mutable", ""},
    std::pair<std::string, std::string>{"namespace", "(xbb)|(xa_using_)"},
    std::pair<std::string, std::string>{"new", "xbt"},

    // TODO:continue here!!!;

    std::pair<std::string, std::string>{"noexcept", "xid(f)"},
    std::pair<std::string, std::string>{"not", "oe"},
    std::pair<std::string, std::string>{"not_eq", "ob"},
    std::pair<std::string, std::string>{"nullptr", "v"},
    std::pair<std::string, std::string>{
        "operator", "(xbod(f))|(xbodf(c())|(xb_new_)|(xb_delete_)"},
    std::pair<std::string, std::string>{"or", "ob"},
    std::pair<std::string, std::string>{"or_eq", "ob"},
    std::pair<std::string, std::string>{"private", "lxi(_class_|_struct_)"},
    std::pair<std::string, std::string>{"protected", "lxi(_class_|_struct_)"},
    std::pair<std::string, std::string>{"public", "lxi(_class_|_struct_)"},
    // std::pair<std::string, std::string> {"register", ""}, NOT AVAILABLE IN
    // C++20
    std::pair<std::string, std::string>{"reinterpret_cast", "p(t)c(n@T0#)"},
    // std::pair<std::string, std::string> {"requires", ""},
    std::pair<std::string, std::string>{"return", "xif"},
    std::pair<std::string, std::string>{"short", "(t|xbt)"},
    std::pair<std::string, std::string>{"signed", "xbt"},
    std::pair<std::string, std::string>{"sizeof", "vc(t|n@T0#)"},
    std::pair<std::string, std::string>{"static", "xbd(v|f)"},
    std::pair<std::string, std::string>{"static_assert", "c(n@T0#&&n@T1#)"},
    std::pair<std::string, std::string>{"static_cast", "p(t)c(n@T0#)"},
    std::pair<std::string, std::string>{"struct", "z"},
    std::pair<std::string, std::string>{"switch", "xbb"},
    std::pair<std::string, std::string>{"template", "p($)b"},
    std::pair<std::string, std::string>{"this", "vx(i(_class_|_struct_)&i(f))"},
    std::pair<std::string, std::string>{"thread_local", "xbd(v)"},
    std::pair<std::string, std::string>{"throw", "xbe"},
    std::pair<std::string, std::string>{"true", "v"},
    std::pair<std::string, std::string>{"try", "b"},
    std::pair<std::string, std::string>{"typedef", "xbtn"},
    std::pair<std::string, std::string>{"typeid", "v(_std::size^_t_)c(@T0#)"},
    std::pair<std::string, std::string>{"typename", "txid(p)"},
    std::pair<std::string, std::string>{"union", "z"},
    std::pair<std::string, std::string>{"unsigned", "xbt"},
    std::pair<std::string, std::string>{"using", "(xb_namespace_n)|(xbn_=_n)"},
    std::pair<std::string, std::string>{"virtual",
                                        "(xi(_class_|_struct_))&(xbd(f))"},
    std::pair<std::string, std::string>{"void", "t"},
    std::pair<std::string, std::string>{"volatile", ""},
    std::pair<std::string, std::string>{"wchar_t", "t"},
    std::pair<std::string, std::string>{"while", "c(n@b#)b"},
    std::pair<std::string, std::string>{"xor", "ob"},
    std::pair<std::string, std::string>{"xor_eq", "ob"},
    std::pair<std::string, std::string>{"#assert", "r(1/2)"},
    std::pair<std::string, std::string>{"#define", "r(1/2)"},
    std::pair<std::string, std::string>{"#elif", "rv(b)"},
    std::pair<std::string, std::string>{"#else", "r0"},
    std::pair<std::string, std::string>{"#endif", "r0"},
    std::pair<std::string, std::string>{"#error", "rv(c*)"},
    std::pair<std::string, std::string>{"#ident", "rv(c*)"},
    std::pair<std::string, std::string>{"#if", "rv(b)"},
    std::pair<std::string, std::string>{"#ifdef", "rn"},
    std::pair<std::string, std::string>{"#ifndef", "rn"},
    std::pair<std::string, std::string>{"#import", "(r_<_n_>_)|(r_\"_n_\"_)"},
    std::pair<std::string, std::string>{"#include", "(r_<_n_>_)|(r_\"_n_\"_)"},
    std::pair<std::string, std::string>{"#include_next",
                                        "(r_<_n_>_)|(r_\"_n_\"_)"},
    std::pair<std::string, std::string>{"#line", "r(1/2)"},
    std::pair<std::string, std::string>{"#pragma", "r_once_"},
    std::pair<std::string, std::string>{"#sccs", "rv(c*)"},
    std::pair<std::string, std::string>{"#unassert", "r1"},
    std::pair<std::string, std::string>{"#undef", "rn"},
    std::pair<std::string, std::string>{"#warning", "rv(c*)"},
};

std::map<std::string, std::string> key{
    // std::pair<std::string, std::string> {"alignas", "c(n@i#)xbd(v|c|s)"},
    // std::pair<std::string, std::string> {"alignof", "c(t)v(ul)"},
    // std::pair<std::string, std::string> {"and", "ob"},
    // std::pair<std::string, std::string> {"and_eq", "ob"},
    // std::pair<std::string, std::string> {"asm", "ob"},
    std::pair<std::string, std::string>{"auto", "xbt"},
    // std::pair<std::string, std::string> {"bitand", "ob"},
    // std::pair<std::string, std::string> {"bitor", "ob"},
    // std::pair<std::string, std::string> {"bool", "t"},
    std::pair<std::string, std::string>{"break",
                                        "sxi(_for_|_while_|_do_|_switch_)"},
    std::pair<std::string, std::string>{"case", "lxi_switch_"},
    // std::pair<std::string, std::string> {"catch", "xa_throw%b_d(f)"},
    std::pair<std::string, std::string>{"char", "t"},
    // std::pair<std::string, std::string> {"char8_t", "t"},
    // std::pair<std::string, std::string> {"char16_t", "t"},
    // std::pair<std::string, std::string> {"char32_t", "t"},
    // std::pair<std::string, std::string> {"class", "z|txid(p)"},
    // std::pair<std::string, std::string> {"compl", "oe"},
    // std::pair<std::string, std::string> {"concept", ""},
    std::pair<std::string, std::string>{"const", "x(bt|at|it)"},
    // std::pair<std::string, std::string> {"consteval", "xbd(f)"},
    // std::pair<std::string, std::string> {"constexpr", "xbt"},
    // std::pair<std::string, std::string> {"constinit", "xbt"},
    // std::pair<std::string, std::string> {"const_cast", "p(t)c(n@T0#)"},
    std::pair<std::string, std::string>{"continue", "sxi(_for_|_while_|_do_)"},
    // std::pair<std::string, std::string> {"co_await", ""},
    // std::pair<std::string, std::string> {"co_return", ""},
    // std::pair<std::string, std::string> {"co_yield", ""},
    // std::pair<std::string, std::string> {"decltype", "tc(n@T0#)"},
    std::pair<std::string, std::string>{"default", "lxi_switch_"},
    // std::pair<std::string, std::string> {"delete", "xbn"},
    std::pair<std::string, std::string>{"do", "xbb"},
    std::pair<std::string, std::string>{"double", "t"},
    // std::pair<std::string, std::string> {"dynamic_cast", "p(t)c(n@T0#)"},
    std::pair<std::string, std::string>{"else", "xa(_if_b)"},
    std::pair<std::string, std::string>{"enum", "b"},
    // std::pair<std::string, std::string> {"explicit", "xbd(v)"},
    // std::pair<std::string, std::string> {"export", "xb(_module_|d(f))"},
    std::pair<std::string, std::string>{"extern", "xbd(v)"},
    // std::pair<std::string, std::string> {"false", "v"},
    std::pair<std::string, std::string>{"float", "t"},
    std::pair<std::string, std::string>{"for", "wb"},
    // std::pair<std::string, std::string> {"friend",
    // "xi(_class_|_struct_)xbd(v|f)"},
    std::pair<std::string, std::string>{"goto", "xbn"},
    std::pair<std::string, std::string>{"if", "c(n@b#)b"},
    // std::pair<std::string, std::string> {"inline", "xbd(f)"},
    std::pair<std::string, std::string>{"int", "t"},
    std::pair<std::string, std::string>{"long", "(t|xbt)"},
    // std::pair<std::string, std::string> {"mutable", ""},
    // std::pair<std::string, std::string> {"namespace", "(xbb)|(xa_using_)"},
    // std::pair<std::string, std::string> {"new", "xbt"},

    // TODO:continue here!!!;

    // std::pair<std::string, std::string> {"noexcept", "xid(f)"},
    // std::pair<std::string, std::string> {"not", "oe"},
    // std::pair<std::string, std::string> {"not_eq", "ob"},
    // std::pair<std::string, std::string> {"nullptr", "v"},
    // std::pair<std::string, std::string> {"operator",
    // "(xbod(f))|(xbodf(c())|(xb_new_)|(xb_delete_)"},
    // std::pair<std::string, std::string> {"or", "ob"},
    // std::pair<std::string, std::string> {"or_eq", "ob"},
    // std::pair<std::string, std::string> {"private", "lxi(_class_|_struct_)"},
    // std::pair<std::string, std::string> {"protected",
    // "lxi(_class_|_struct_)"},
    // std::pair<std::string, std::string> {"public", "lxi(_class_|_struct_)"},
    std::pair<std::string, std::string>{"register", "xbt"},
    // std::pair<std::string, std::string> {"reinterpret_cast", "p(t)c(n@T0#)"},
    // std::pair<std::string, std::string> {"requires", ""},
    std::pair<std::string, std::string>{"return", "xif"},
    std::pair<std::string, std::string>{"short", "t|xbt"},
    std::pair<std::string, std::string>{"signed", "xbt"},
    std::pair<std::string, std::string>{"sizeof", "vc(t|n@T0#)"},
    std::pair<std::string, std::string>{"static", "xbd(v)"},
    // std::pair<std::string, std::string> {"static_assert", "c(n@T0#&&n@T1#)"},
    // std::pair<std::string, std::string> {"static_cast", "p(t)c(n@T0#)"},
    std::pair<std::string, std::string>{"struct", "z"},
    std::pair<std::string, std::string>{"switch", "xbb"},
    // std::pair<std::string, std::string> {"template", "p($)b"},
    // std::pair<std::string, std::string> {"this",
    // "vx(i(_class_|_struct_)&i(f))"},
    // std::pair<std::string, std::string> {"thread_local", "xbd(v)"},
    // std::pair<std::string, std::string> {"throw", "xbe"},
    // std::pair<std::string, std::string> {"true", "v"},
    // std::pair<std::string, std::string> {"try", "b"},
    std::pair<std::string, std::string>{"typedef", "xbtn"},
    // std::pair<std::string, std::string> {"typeid",
    // "v(_std::size^_t_)c(@T0#)"},
    // std::pair<std::string, std::string> {"typename", "txid(p)"},
    std::pair<std::string, std::string>{"union", "z"},
    std::pair<std::string, std::string>{"unsigned", "xbt"},
    // std::pair<std::string, std::string> {"using",
    // "(xb_namespace_n)|(xbn_=_n)"},
    // std::pair<std::string, std::string> {"virtual",
    // "(xi(_class_|_struct_))&(xbd(f))"},
    std::pair<std::string, std::string>{"void", "t"},
    std::pair<std::string, std::string>{"volatile", ""},
    // std::pair<std::string, std::string> {"wchar_t", "t"},
    std::pair<std::string, std::string>{"while", "c(n@b#)b|xbb"},
    // std::pair<std::string, std::string> {"xor", "ob"},
    // std::pair<std::string, std::string> {"xor_eq", "ob"},
    // std::pair<std::string, std::string> {"#assert", "r(1/2)"},
    std::pair<std::string, std::string>{"#define", "r(1/2)"},
    std::pair<std::string, std::string>{"#elif", "rv(b)"},
    std::pair<std::string, std::string>{"#else", "r0"},
    std::pair<std::string, std::string>{"#endif", "r0"},
    std::pair<std::string, std::string>{"#error", "rv(c*)"},
    // std::pair<std::string, std::string> {"#ident", "rv(c*)"},
    std::pair<std::string, std::string>{"#if", "rv(b)"},
    std::pair<std::string, std::string>{"#ifdef", "rn"},
    std::pair<std::string, std::string>{"#ifndef", "rn"},
    // std::pair<std::string, std::string> {"#import",
    // "(r_<_n_>_)|(r_\"_n_\"_)"},
    std::pair<std::string, std::string>{"#include", "r_<_n_>_|r_\"_n_\"_"},
    // std::pair<std::string, std::string> {"#include_next",
    // "(r_<_n_>_)|(r_\"_n_\"_)"},
    // std::pair<std::string, std::string> {"#line", "r(1/2)"},
    std::pair<std::string, std::string>{"#pragma", "r_once_"},
    // std::pair<std::string, std::string> {"#sccs", "rv(c*)"},
    // std::pair<std::string, std::string> {"#unassert", "r1"},
    std::pair<std::string, std::string>{"#undef", "rn"},
    // std::pair<std::string, std::string> {"#warning", "rv(c*)"},
};

std::map<std::string, std::string> key_expressions{
    std::pair<std::string, std::string>{"auto", "xbt"},
    std::pair<std::string, std::string>{"break",
                                        "sxi(_for_|_while_|_do_|_switch_)"},
    std::pair<std::string, std::string>{"case", "lxi_switch_"},
    std::pair<std::string, std::string>{"char", "t"},
    std::pair<std::string, std::string>{"const", "x(bt|at|it)"},
    std::pair<std::string, std::string>{"continue", "sxi(_for_|_while_|_do_)"},
    std::pair<std::string, std::string>{"default", "lxi_switch_"},
    std::pair<std::string, std::string>{"do", "xbb"},
    std::pair<std::string, std::string>{"double", "t"},
    std::pair<std::string, std::string>{"else", "xa(_if_b)"},
    std::pair<std::string, std::string>{"enum", "b"},
    std::pair<std::string, std::string>{"extern", "xbd(v)"},
    std::pair<std::string, std::string>{"float", "t"},
    std::pair<std::string, std::string>{"for", "wb"},
    std::pair<std::string, std::string>{"goto", "xbn"},
    std::pair<std::string, std::string>{"if", "c(n@b#)b"},
    std::pair<std::string, std::string>{"int", "t"},
    std::pair<std::string, std::string>{"long", "(t|xbt)"},
    std::pair<std::string, std::string>{"register", "xbt"},
    std::pair<std::string, std::string>{"return", "xif"},
    std::pair<std::string, std::string>{"short", "t|xbt"},
    std::pair<std::string, std::string>{"signed", "xbt"},
    std::pair<std::string, std::string>{"sizeof", "vc(t|n@T0#)"},
    std::pair<std::string, std::string>{"static", "xbd(v)"},
    std::pair<std::string, std::string>{"struct", "z"},
    std::pair<std::string, std::string>{"switch", "xbb"},
    std::pair<std::string, std::string>{"typedef", "xbtn"},
    std::pair<std::string, std::string>{"union", "z"},
    std::pair<std::string, std::string>{"unsigned", "xbt"},
    std::pair<std::string, std::string>{"void", "t"},
    std::pair<std::string, std::string>{"volatile", ""},
    std::pair<std::string, std::string>{"while", "c(n@b#)b|xbb"},
    std::pair<std::string, std::string>{"#define", "r(1/2)"},
    std::pair<std::string, std::string>{"#elif", "rv(b)"},
    std::pair<std::string, std::string>{"#else", "r0"},
    std::pair<std::string, std::string>{"#endif", "r0"},
    std::pair<std::string, std::string>{"#error", "rv(c*)"},
    std::pair<std::string, std::string>{"#if", "rv(b)"},
    std::pair<std::string, std::string>{"#ifdef", "rn"},
    std::pair<std::string, std::string>{"#ifndef", "rn"},
    std::pair<std::string, std::string>{"#include", "r_<_n_>_|r_\"_n_\"_"},
    std::pair<std::string, std::string>{"#pragma", "r_once_"},
    std::pair<std::string, std::string>{"#undef", "rn"},
};

class Statement {
 public:
  enum Types {
    NONE = 0,
    CLASS_DECLARATION = (1 << 0),
    PREPROCESSOR_DIRECTIVE = (1 << 1),
    VARIABLE_DECLARATION = (1 << 2),
    VARIABLE_INITIALIZATION_COPY = (1 << 3),
    VARIABLE_INITIALIZATION_DIRECT = (1 << 4),
    VARIABLE_INITIALIZATION_UNIFORM = (1 << 5),
    FUNCTION_DECLARATION = (1 << 6),
    FUNCTION_DEFINITION = (1 << 7),
    FUNCTION_CALL = (1 << 8),
    NORMAL = (1 << 9),
    KEYWORD = (1 << 10),
    OPERATOR = (1 << 11),
    NAME = (1 << 12),
    TYPE = (1 << 13),
    TYPE_MODIFIER = (1 << 14),
    LABEL = (1 << 15),
    STATEMENT = (1 << 16),
    PARENTHESIS = (1 << 17),
    CURLY_BRACE = (1 << 18),
    BRACE = (1 << 19),
    MULTIPLE = (1 << 20),
    OPTIONAL = (1 << 21),
    ASTERISK_OR_AMPERSAND = (1 << 22),
    OPEN = (1 << 30),
    CLOSE = (1 << 31),
  };
  enum Modes {
    PREFIX = 8192,
    POSTFIX = 16384,
    BOTH = 32768,
  };
  enum Enclosure {
    PARENTHESIS = (1 << 0),
    CURLY_BRACE = (1 << 1),
    BRACE = (1 << 2),
    OPEN = (1 << 30),
    CLOSE = (1 << 31),
  } enum Count {
    MULTIPLE,
    OPTIONAL
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
  // Stands for class/struct/enum names.
  std::vector<std::string> m_types;
  std::map<std::string, std::vector<Scope>> m_objects;
  std::vector<Statement> m_statements;

 public:
  Scope() : m_members{}, m_methods{}, m_objects{}, m_statements{} {}
  Scope(const std::vector<Statement>& statements)
      : m_members{}, m_methods{}, m_objects{}, m_statements{statements} {}
  // TODO: this
  Scope& add_scope() {}
} /* global{} */;

std::vector<Statement> parse(std::fstream& file) { std::stringstream ss{file}; }

class Exception : public std::exception {
  std::string message;

 public:
  Exception(const char* m = "") : message{m} {}

  virtual const char* what() const noexcept override {
    return message.c_str();
    // return "DContainer is out of bounds";
  }
};

template <class T>
class DContainer {
 protected:
  T* m_contents;
  std::size_t m_size;
  std::size_t m_allocated;

 public:
  DContainer(int size = 0)
      : m_contents{(T*)malloc(size)}, m_size{size}, m_allocated{size} {}
  DContainer(std::initializer_list<T> list)
      : m_contents{(T*)malloc(list.size() * sizeof(T))}, m_size{list.size()} {
    T* ptr{m_contents};
    for (const T& i : list) {
      *(m_contents++) = i;
    }
  }
  ~DContainer() { free(m_contents); }
  T& operator[](std::size_t index) {
    if (index < 0) index += m_size;
    if (index >= m_size || index < 0) {
      throw Exception{"DContainer is out of bounds"};
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
  friend std::stringstream& operator<<(std::stringstream& ss,
                                       DContainer<T>& dc) {
    for (int i{0}; i < m_size; ++i) ss << dc[i];
    return ss;
  }
  std::size_t size() const { return m_size; }
};

#ifdef 0

struct Expectance {
 public:
  Statement::Types type;
  // Contains all the possible ones,
  // std::vector<std::vector<Statement::Types>> expectances;
  std::vector<std::vector<Statement::Types>> expectances;
  // TODO:Note: junction: true is conjunction, while false is disjunction
  std::vector<bool> junction;
  Expectance(int tp = Statement::Types::NAME,
             Statement::Types tp0 = Statement::Types::NAME)
      : type{Statement::Types::NONE}, expectances{} {
    if (tp & Statement::Types::OPERATOR) {
      expectances.resize(1);
      if (tp & Statement::Modes::BOTH) {
        expectances[0].push_back(Statement::Types::NAME);
        expectances[0].push_back(Statement::Types::OPERATOR);
        expectances[0].push_back(Statement::Types::NAME);
      } else if (tp & Statement::Modes::PREFIX) {
        expectances[0].push_back(Statement::Types::OPERATOR);
        expectances[0].push_back(Statement::Types::NAME);
      } else if (tp & Statement::Modes::POSTFIX) {
        expectances[0].push_back(Statement::Types::NAME);
        expectances[0].push_back(Statement::Types::OPERATOR);
      }
    } else if (tp & Statement::Types::PREPROCESSOR_DIRECTIVE) {
      expectances.resize(1);
      expectances[0].push_back(Statement::Types::PREPROCESSOR_DIRECTIVE);
    } else if (tp&)

      expectances[0].push_back();
  }
};

void read_keyword_expression(bool first = true, int& i) {
  int paren{0};
  bool closed{false};
  std::string current_string{""};
  char first;
  int counter{0};
  for (int i{0}; i < (*iter).second.size();
       ++i, counter = (counter && !paren) ? counter - 1 : counter) {
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
  short int *current, parenthesis_layers;
  std::vector<std::string> message;
  Counter()
      : size{0},
        allocated{0},
        current{(short int*)(malloc(sizeof(short int) * size))},
        parenthesis_layers{0},
        closed{false} {}
  operator bool() { return size == 0 ? false : (!current[size - 1]); }
  Counter& addCounter(short int counter = 1) {
    short int* holder{current};
    if (allocated == size) {
      if ((current = (short int*)realloc(current, (++size, ++allocated))) ==
          NULL) {
        current = holder;
        --size;
        throw "Cannot allocate more. ";
      }
    } else
      ++size;
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
      int paren{0};
      bool closed{false}, is_v{false};
      std::string current_string{""};
      char first;
      bool is_first{true};
      int counter{0};
      Counter ct{};
      for (int i{0}; i < (*iter).second.size();
           ++i, counter = (counter && !paren) ? counter - 1 : counter) {
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
              Expectance ep{Statement::Types::OPERATOR |
                            Statement::Modes::PREFIX};
              switch ((*iter).second[i + 1]) {
                case 'e':
                  ep = Expectance{Statement::Types::OPERATOR |
                                  Statement::Modes::PREFIX};
                  break;
                case 'o':
                  ep = Expectance{Statement::Types::OPERATOR |
                                  Statement::Modes::POSTFIX};
                  break;
                case 'b':
                  ep = Expectance{Statement::Types::OPERATOR |
                                  Statement::Modes::BOTH};
                  break;
              };
            }
            ep.expectances.push_back;
            ep.expectances[0].push_back("");
            switch ((*iter).second[1]) { ca };
        }

        case 'v':
          if (!counter) case 'd':
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
  } else {
    return Statement::Types::PREPROCESSOR_DIRECTIVE;
  }
  return Statement::Types::KEYWORD;
}

#endif
// if (Types::operators.find(s) != Types::operator.end()) {
//     return Statement::Types::OPERATOR;
// }
// // if (std::find(Types::order.begin(), Types::order.end(), s) !=
// Types::order.end()) {
// //     return Statement::Types::TYPE;
// // }
// return Statement::Types::NAME;
// }

// using namespace STypes;
/**
 * @brief
 *  Array of:
 *      Pairs that contain:
 *          Array of things expected
 *          Pair of:
 *              evaluated type (if -1, means dependent on type of function; if
 * -2, means dependent on type of variable) id of statement type Note: STypes
 * stands for Statement Types Upon seing anything with return value with higher
 * level of precedence, evaluate it first. Note: Support for default-int
 */
Array<Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>> statement_types{
    Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>{
        {// Variable Declaration with initialization
         STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL,
         STypes::TYPE, STypes::ASTERISK_OR_AMPERSAND | STypes::MULTIPLE,
         STypes::NAME, STypes::ASSIGMENT, STypes::LITERAL | STypes::NAME,
         STypes::SEMICOLON},
        Pair<std::size_t, std::size_t>(0, 0)},
    Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>{
        {// Variable Declaration
         STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL,
         STypes::TYPE, STypes::ASTERISK_OR_AMPERSAND | STypes::MULTIPLE,
         STypes::NAME, STypes::SEMICOLON},
        Pair<std::size_t, std::size_t>(0, 0)},
    Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>{
        {// Variable Declaration array with initialization
         STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL,
         STypes::TYPE, STypes::ASTERISK_OR_AMPERSAND | STypes::MULTIPLE,
         STypes::NAME, STypes::BRACE | STypes::OPEN,
         STypes::LITERAL | STypes::NAME, STypes::BRACE | STypes::CLOSE,
         STypes::ASSIGMENT, STypes::LITERAL | STypes::NAME, STypes::SEMICOLON},
        Pair<std::size_t, std::size_t>(0, 0)},
    Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>{
        {// Variable Declaration array
         STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL,
         STypes::TYPE, STypes::ASTERISK_OR_AMPERSAND | STypes::MULTIPLE,
         STypes::NAME, STypes::BRACE | STypes::OPEN,
         STypes::LITERAL | STypes::NAME, STypes::BRACE | STypes::CLOSE,
         STypes::SEMICOLON},
        Pair<std::size_t, std::size_t>(0, 0)},
    Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>{
        {// Function Definition
         STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL,
         STypes::TYPE, STypes::ASTERISK_OR_AMPERSAND | STypes::MULTIPLE,
         STypes::NAME, STypes::PARENTHESIS | STypes::OPEN,
         STypes::TYPE | STypes::NAME | STypes::OPTIONAL,
         STypes::COMMA | STypes::TYPE | STypes::NAME | STypes::MULTIPLE |
             STypes::OPTIONAL,  // STypes::COMMA_TYPE_AND_NAME |
                                // STypes::OPTIONAL | STypes::MULTIPLE,
         STypes::PARENTHESIS | STypes::CLOSE,
         STypes::CURLY_BRACE | STypes::OPEN,
         STypes::STATEMENT | STypes::OPTIONAL | STypes::MULTIPLE,
         STypes::CURLY_BRACE | STypes::CLOSE},
        Pair<std::size_t, std::size_t>(0, 1)},
    Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>{
        {// Function Declaration
         STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL,
         STypes::TYPE, STypes::ASTERISK_OR_AMPERSAND | STypes::MULTIPLE,
         STypes::NAME, STypes::PARENTHESIS | STypes::OPEN,
         STypes::TYPE | STypes::NAME | STypes::OPTIONAL,
         STypes::COMMA | STypes::TYPE | STypes::NAME | STypes::MULTIPLE |
             STypes::OPTIONAL,  // STypes::COMMA_TYPE_AND_NAME |
                                // STypes::OPTIONAL | STypes::MULTIPLE,
         STypes::PARENTHESIS | STypes::CLOSE, STypes::SEMICOLON},
        Pair<std::size_t, std::size_t>(0, 1)},
    Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>{
        {
            // Function Call
            STypes::NAME,
            STypes::PARENTHESIS | STypes::OPEN,
            STypes::NAME | STypes::LITERAL | STypes::OPTIONAL,
            STypes::COMMA | STypes::NAME | STypes::LITERAL | STypes::MULTIPLE |
                STypes::OPTIONAL,  // STypes::COMMA_TYPE_AND_NAME |
                                   // STypes::OPTIONAL | STypes::MULTIPLE,
            STypes::PARENTHESIS | STypes::CLOSE,
        },
        Pair<std::size_t, std::size_t>(-1, 1)},
    Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>{
        {// Blank statement
         STypes::NAME | STypes::LITERAL, STypes::SEMICOLON},
        Pair<std::size_t, std::size_t>(0, 1)},
    Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>{
        {// Casting statement
         STypes::PARENTHESIS | STypes::OPEN,
         STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL,
         STypes::TYPE, STypes::PARENTHESIS | STypes::CLOSE,
         STypes::NAME | STypes::LITERAL},
        Pair<std::size_t, std::size_t>(-1, 1)},
    Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>{
        {// Type-call statement
         STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL,
         STypes::TYPE, STypes::PARENTHESIS | STypes::OPEN,
         STypes::NAME | STypes::LITERAL | STypes::OPTIONAL,
         STypes::PARENTHESIS | STypes::CLOSE},
        Pair<std::size_t, std::size_t>(-1, 1)},
    Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>{
        {// Operator both
         STypes::NAME | STypes::LITERAL, STypes::OPERATOR | STypes::BOTH,
         STypes::NAME | STypes::LITERAL}},
    Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>{
        {// Operator prefix
         STypes::OPERATOR | STypes::PREFIX, STypes::NAME | STypes::LITERAL}},
    Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>{
        {// Operator postfix
         STypes::NAME | STypes::LITERAL, STypes::OPERATOR | STypes::PREFIX}},
    Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>{
        {// Operator postfix
         STypes::NAME | STypes::LITERAL, STypes::OPERATOR | STypes::PREFIX}}
};


#ifdef 0

Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>{
    {// Function Declaration
     STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL, STypes::TYPE,
     STypes::NAME, STypes::PARENTHESIS | STypes::OPEN,
     STypes::TYPE | STypes::NAME | STypes::OPTIONAL,
     STypes::COMMA | STypes::TYPE | STypes::NAME | STypes::MULTIPLE |
         STypes::OPTIONAL,  // STypes::COMMA_TYPE_AND_NAME | STypes::OPTIONAL |
                            // STypes::MULTIPLE,
     STypes::PARENTHESIS | STypes::CLOSE, STypes::CURLY_BRACE | STypes::OPEN,
     STypes::STATEMENT | STypes::OPTIONAL | STypes::MULTIPLE,
     STypes::CURLY_BRACE | STypes::CLOSE},
    Pair<std::size_t, std::size_t>(0, 1)

},
    Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>{
        {// Blank statement
         STypes::NAME | STypes::LITERAL, STypes::SEMICOLON},
        Pair<std::size_t, std::size_t>(0, 1)},

    {// Function Declaration
     STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL,
     STypes::TYPE,
     STypes::NAME,
     STypes::PARENTHESIS | STypes::OPEN,
     STypes::TYPE | STypes::OPTIONAL,
     STypes::NAME | STypes::OPTIONAL,
     STypes::COMMA_TYPE_AND_NAME | STypes::OPTIONAL | STypes::MULTIPLE,
     STypes::PARENTHESIS | STypes::CLOSE,
     STYpes::} {
  // Function Declaration
  STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL, STypes::TYPE,
      STypes::NAME, STypes::PARENTHESIS | STypes::OPEN,
}

#endif

// TODO: types can also be called as functions.

// std::map<std::string, std::vector<Expectance>> key_expressions_bck{
//     std::pair<std::string, std::vector<Expectance>> {"auto",
//     {Expectance{Statement::Types::TYPE_MODIFIER}}}, std::pair<std::string,
//     std::vector<Expectance>> {"break",
//     {Expectance{Statement::Types::STATEMENT}}}, std::pair<std::string,
//     std::vector<Expectance>> {"case", "lxi_switch_"}, std::pair<std::string,
//     std::vector<Expectance>> {"char", "t"}, std::pair<std::string,
//     std::vector<Expectance>> {"const", "x(bt|at|it)"}, std::pair<std::string,
//     std::vector<Expectance>> {"continue", "sxi(_for_|_while_|_do_)"},
//     std::pair<std::string, std::vector<Expectance>> {"default",
//     "lxi_switch_"}, std::pair<std::string, std::vector<Expectance>> {"do",
//     "xbb"}, std::pair<std::string, std::vector<Expectance>> {"double", "t"},
//     std::pair<std::string, std::vector<Expectance>> {"else", "xa(_if_b)"},
//     std::pair<std::string, std::vector<Expectance>> {"enum", "b"},
//     std::pair<std::string, std::vector<Expectance>> {"extern", "xbd(v)"},
//     std::pair<std::string, std::vector<Expectance>> {"float", "t"},
//     std::pair<std::string, std::vector<Expectance>> {"for", "wb"},
//     std::pair<std::string, std::vector<Expectance>> {"goto", "xbn"},
//     std::pair<std::string, std::vector<Expectance>> {"if", "c(n@b#)b"},
//     std::pair<std::string, std::vector<Expectance>> {"int", "t"},
//     std::pair<std::string, std::vector<Expectance>> {"long", "(t|xbt)"},
//     std::pair<std::string, std::vector<Expectance>> {"register", "xbt"},
//     std::pair<std::string, std::vector<Expectance>> {"return", "xif"},
//     std::pair<std::string, std::vector<Expectance>> {"short", "t|xbt"},
//     std::pair<std::string, std::vector<Expectance>> {"signed", "xbt"},
//     std::pair<std::string, std::vector<Expectance>> {"sizeof",
//     "vc(t|n@T0#)"}, std::pair<std::string, std::vector<Expectance>>
//     {"static", "xbd(v)"}, std::pair<std::string, std::vector<Expectance>>
//     {"struct", "z"}, std::pair<std::string, std::vector<Expectance>>
//     {"switch", "xbb"}, std::pair<std::string, std::vector<Expectance>>
//     {"typedef", "xbtn"}, std::pair<std::string, std::vector<Expectance>>
//     {"union", "z"}, std::pair<std::string, std::vector<Expectance>>
//     {"unsigned", "xbt"}, std::pair<std::string, std::vector<Expectance>>
//     {"void", "t"}, std::pair<std::string, std::vector<Expectance>>
//     {"volatile", ""}, std::pair<std::string, std::vector<Expectance>>
//     {"while", "c(n@b#)b|xbb"}, std::pair<std::string,
//     std::vector<Expectance>> {"#define", "r(1/2)"}, std::pair<std::string,
//     std::vector<Expectance>> {"#elif", "rv(b)"}, std::pair<std::string,
//     std::vector<Expectance>> {"#else", "r0"}, std::pair<std::string,
//     std::vector<Expectance>> {"#endif", "r0"}, std::pair<std::string,
//     std::vector<Expectance>> {"#error", "rv(c*)"}, std::pair<std::string,
//     std::vector<Expectance>> {"#if", "rv(b)"}, std::pair<std::string,
//     std::vector<Expectance>> {"#ifdef", "rn"}, std::pair<std::string,
//     std::vector<Expectance>> {"#ifndef", "rn"}, std::pair<std::string,
//     std::vector<Expectance>> {"#include", "r_<_n_>_|r_\"_n_\"_"},
//     std::pair<std::string, std::vector<Expectance>> {"#pragma", "r_once_"},
//     std::pair<std::string, std::vector<Expectance>> {"#undef", "rn"},

//     std::pair<std::string, std::string> {"=", "b"},
//     std::pair<std::string, std::string> {"+", "b"},
//     std::pair<std::string, std::string> {"-", "b"},
//     std::pair<std::string, std::string> {"*", "b"},
//     std::pair<std::string, std::string> {"/", "b"},
//     std::pair<std::string, std::string> {"%", "b"},
//     std::pair<std::string, std::string> {"+=", "b"},
//     std::pair<std::string, std::string> {"-=", "b"},
//     std::pair<std::string, std::string> {"*=", "b"},
//     std::pair<std::string, std::string> {"/=", "b"},
//     std::pair<std::string, std::string> {"%=", "b"},
//     std::pair<std::string, std::string> {">>=", "b"},
//     std::pair<std::string, std::string> {"<<=", "b"},
//     std::pair<std::string, std::string> {"&=", "b"},
//     std::pair<std::string, std::string> {"^=", "b"},
//     std::pair<std::string, std::string> {"|=", "b"},
//     std::pair<std::string, std::string> {"++", "t"},
//     // std::pair<std::string, std::string> {"++E", "e"},
//     // std::pair<std::string, std::string> {"++O", "o"},
//     std::pair<std::string, std::string> {"--", "t"},
//     // std::pair<std::string, std::string> {"--E", "e"},
//     // std::pair<std::string, std::string> {"--O", "o"},
//     std::pair<std::string, std::string> {"==", "b"},
//     std::pair<std::string, std::string> {"!=", "b"},
//     std::pair<std::string, std::string> {">", "b"},
//     std::pair<std::string, std::string> {"<", "b"},
//     std::pair<std::string, std::string> {">=", "b"},
//     std::pair<std::string, std::string> {"<=", "b"},
//     std::pair<std::string, std::string> {"!", "e"},
//     std::pair<std::string, std::string> {"&&", "b"},
//     std::pair<std::string, std::string> {"||", "b"},
//     std::pair<std::string, std::string> {"?", "b"},
//     std::pair<std::string, std::string> {":", "b"},
//     std::pair<std::string, std::string> {",", "b"},
//     std::pair<std::string, std::string> {"&", "b"},
//     std::pair<std::string, std::string> {"|", "b"},
//     std::pair<std::string, std::string> {"^", "b"},
//     std::pair<std::string, std::string> {"~", "e"},
//     std::pair<std::string, std::string> {"<<", "b"},
//     std::pair<std::string, std::string> {">>", "b"},
//     std::pair<std::string, std::string> {"()__CAST__", "ei"},
//     std::pair<std::string, std::string> {"::", "b"},
//     std::pair<std::string, std::string> {"()", "oi"},
//     std::pair<std::string, std::string> {"[]", "oi"},
//     std::pair<std::string, std::string> {".", "b"},
//     std::pair<std::string, std::string> {"->", "b"},
//     std::pair<std::string, std::string> {"&__PTR__", "e"},
//     std::pair<std::string, std::string> {"*__PTR__", "e"},

//     //TODO: Not so sure about putting space here after new and delete
//     std::pair<std::string, std::string> {"new ", "e"},
//     std::pair<std::string, std::string> {"delete ", "e"},
//     std::pair<std::string, std::string> {"sizeof()", "ei"},
// };

/**
 *
 * @brief
 *  Contains:
 *      Array of:
 *          Pair of:
 *              SString containing name and order number
 *  Note: if smae number > once, invalid
 *  Note: if -1 or -2, check for type being modified, and check below for how
 * many possible: if -1 check index 0: if type is (id for int), 2 allowed, if
 * type is (id for double), 1 allowed, if other, 0 allowed if -2 check index 1:
 *          if type is (id for int), 2 allowed, if type is (id for double), 1
 * allowed, if other, 0 allowed -1 and -2 are incompatible.
 */
Array<Pair<String, std::size_t>> type_modifier_order{
    Pair<String, std::size_t>("auto", 0),
    Pair<String, std::size_t>("static", 0),
    Pair<String, std::size_t>("extern", 0),
    Pair<String, std::size_t>("register", 0),
    Pair<String, std::size_t>("const", 1),
    Pair<String, std::size_t>("long", -1),
    Pair<String, std::size_t>("short", -2),
    Pair<String, std::size_t>("signed", 3),
    Pair<String, std::size_t>("unsigned", 3),
};

// Array<Pair<String, std::size_t>> keyword_callable_params{
//     Pair<String, std::size_t>()
// }

// Array<Pair<String, std::size_t>> location_specifics{
Array<Pair<Pair<std::size_t, std::size_t>, JunctionMode>> location_specifics{
    Pair<Pair<std::size_t, std::size_t>, JunctionMode>(
        Pair<std::size_t, std::size_t>(STypes::ELSE, STypes::IF),
        JunctionMode::AFTER),
    Pair<Pair<std::size_t, std::size_t>, JunctionMode>(
        Pair<std::size_t, std::size_t>(STypes::CASE, STypes::SWITCH),
        JunctionMode::IN),
    Pair<Pair<std::size_t, std::size_t>, JunctionMode>(
        Pair<std::size_t, std::size_t>(STypes::BREAK, STypes::SWITCH),
        JunctionMode::IN),
};
// Array<Pair

// std::map<std::string, std::vector<Expectance>> key_expressions{
std::map<std::string, std::size_t> key_expressions{
    std::pair<std::string, std::size_t>{"auto", STypes::TYPE_MODIFIER},
    std::pair<std::string, std::size_t>{"break", STypes::BREAK},
    std::pair<std::string, std::size_t>{"case", STypes::CASE},
    std::pair<std::string, std::size_t>{"char", STypes::TYPE},
    std::pair<std::string, std::size_t>{"const", STypes::TYPE_MODIFIER},
    std::pair<std::string, std::size_t>{"continue", STypes::WHOLE_STATEMENT},
    std::pair<std::string, std::size_t>{"default", STypes::LABEL},
    std::pair<std::string, std::size_t>{"do", STypes::DO},
    std::pair<std::string, std::size_t>{"double", STypes::TYPE},
    std::pair<std::string, std::size_t>{"else", STypes::ELSE},
    std::pair<std::string, std::size_t>{"enum", STypes::ENUM},
    std::pair<std::string, std::size_t>{"extern", STypes::TYPE_MODIFIER},
    std::pair<std::string, std::size_t>{"float", STypes::TYPE},
    std::pair<std::string, std::size_t>{"for", STypes::FOR},
    std::pair<std::string, std::size_t>{"goto", STypes::GOTO},
    std::pair<std::string, std::size_t>{"if", STypes::ELSE},
    std::pair<std::string, std::size_t>{"int", STypes::TYPE},
    std::pair<std::string, std::size_t>{"long", STypes::TYPE_MODIFIER},
    std::pair<std::string, std::size_t>{"register", STypes::TYPE_MODIFIER},
    std::pair<std::string, std::size_t>{"return", STypes::RETURN},
    std::pair<std::string, std::size_t>{"short", STypes::TYPE_MODIFIER},
    std::pair<std::string, std::size_t>{"signed", STypes::TYPE_MODIFIER},
    std::pair<std::string, std::size_t>{"sizeof", STypes::SIZEOF},
    std::pair<std::string, std::size_t>{"static", STypes::TYPE_MODIFIER},
    std::pair<std::string, std::size_t>{"struct", STypes::STRUCT},
    std::pair<std::string, std::size_t>{"switch", STypes::SWITCH},
    std::pair<std::string, std::size_t>{"typedef", STypes::TYPEDEF},
    std::pair<std::string, std::size_t>{"union", STypes::UNION},
    std::pair<std::string, std::size_t>{"unsigned", STypes::TYPE_MODIFIER},
    std::pair<std::string, std::size_t>{"void", STypes::VOID_TYPE},
    std::pair<std::string, std::size_t>{"volatile", STypes::TYPE_MODIFIER},
    std::pair<std::string, std::size_t>{"while", STypes::WHILE},
    std::pair<std::string, std::size_t>{"#define", STypes::PREPROCESSOR_DEFINE},
    std::pair<std::string, std::size_t>{"#elif", STypes::PREPROCESSOR_ELIF},
    std::pair<std::string, std::size_t>{"#else", STypes::PREPROCESSOR_ELSE},
    std::pair<std::string, std::size_t>{"#endif", STypes::PREPROCESSOR_ENDIF},
    std::pair<std::string, std::size_t>{"#error", STypes::PREPROCESSOR_ERROR},
    std::pair<std::string, std::size_t>{"#if", STypes::PREPROCESSOR_IF},
    std::pair<std::string, std::size_t>{"#ifdef", STypes::PREPROCESSOR_IFDEF},
    std::pair<std::string, std::size_t>{"#ifndef", STypes::PREPROCESSOR_IFNDEF},
    std::pair<std::string, std::size_t>{"#include",
                                        STypes::PREPROCESSOR_INCLUDE},
    std::pair<std::string, std::size_t>{"#pragma", STypes::PREPROCESSOR_PRAGMA},
    std::pair<std::string, std::size_t>{"#undef", STypes::PREPROCESSOR_UNDEF},

    std::pair<std::string, std::size_t>{"=", STypes::OPERATOR | STypes::BOTH},
    std::pair<std::string, std::size_t>{"+", STypes::OPERATOR | STypes::BOTH},
    std::pair<std::string, std::size_t>{
        "-", STypes::OPERATOR | STypes::BOTH | STypes::PREFIX},
    std::pair<std::string, std::size_t>{"*", STypes::OPERATOR | STypes::BOTH},
    std::pair<std::string, std::size_t>{"/", STypes::OPERATOR | STypes::BOTH},
    std::pair<std::string, std::size_t>{"%", STypes::OPERATOR | STypes::BOTH},
    std::pair<std::string, std::size_t>{
        "+=", STypes::OPERATOR | STypes::BOTH | STypes::REQUIRE_LVALUE},
    std::pair<std::string, std::size_t>{
        "-=", STypes::OPERATOR | STypes::BOTH | STypes::REQUIRE_LVALUE},
    std::pair<std::string, std::size_t>{
        "*=", STypes::OPERATOR | STypes::BOTH | STypes::REQUIRE_LVALUE},
    std::pair<std::string, std::size_t>{
        "/=", STypes::OPERATOR | STypes::BOTH | STypes::REQUIRE_LVALUE},
    std::pair<std::string, std::size_t>{
        "%=", STypes::OPERATOR | STypes::BOTH | STypes::REQUIRE_LVALUE},
    std::pair<std::string, std::size_t>{
        ">>=", STypes::OPERATOR | STypes::BOTH | STypes::REQUIRE_LVALUE},
    std::pair<std::string, std::size_t>{
        "<<=", STypes::OPERATOR | STypes::BOTH | STypes::REQUIRE_LVALUE},
    std::pair<std::string, std::size_t>{
        "&=", STypes::OPERATOR | STypes::BOTH | STypes::REQUIRE_LVALUE},
    std::pair<std::string, std::size_t>{
        "^=", STypes::OPERATOR | STypes::BOTH | STypes::REQUIRE_LVALUE},
    std::pair<std::string, std::size_t>{
        "|=", STypes::OPERATOR | STypes::BOTH | STypes::REQUIRE_LVALUE},
    std::pair<std::string, std::size_t>{
        "++", STypes::OPERATOR | STypes::PREFIX | STypes::POSTFIX},
    std::pair<std::string, std::size_t>{
        "--", STypes::OPERATOR | STypes::PREFIX | STypes::POSTFIX},
    std::pair<std::string, std::size_t>{"==", STypes::OPERATOR | STypes::BOTH},
    std::pair<std::string, std::size_t>{"!=", STypes::OPERATOR | STypes::BOTH},
    std::pair<std::string, std::size_t>{">", STypes::OPERATOR | STypes::BOTH},
    std::pair<std::string, std::size_t>{"<", STypes::OPERATOR | STypes::BOTH},
    std::pair<std::string, std::size_t>{
        ">=", STypes::OPERATOR | STypes::BOTH | STypes::REQUIRE_LVALUE},
    std::pair<std::string, std::size_t>{
        "<=", STypes::OPERATOR | STypes::BOTH | STypes::REQUIRE_LVALUE},
    std::pair<std::string, std::size_t>{"!", STypes::OPERATOR | STypes::PREFIX},
    std::pair<std::string, std::size_t>{"&&", STypes::OPERATOR | STypes::BOTH},
    std::pair<std::string, std::size_t>{"||", STypes::OPERATOR | STypes::BOTH},
    std::pair<std::string, std::size_t>{"?",
                                        STypes::OPERATOR | STypes::QUESTION},
    std::pair<std::string, std::size_t>{":", STypes::OPERATOR | STypes::QELSE},
    std::pair<std::string, std::size_t>{",", STypes::OPERATOR | STypes::COMMA},
    std::pair<std::string, std::size_t>{"&", STypes::OPERATOR | STypes::BOTH},
    std::pair<std::string, std::size_t>{"|", STypes::OPERATOR | STypes::BOTH},
    std::pair<std::string, std::size_t>{"^", STypes::OPERATOR | STypes::BOTH},
    std::pair<std::string, std::size_t>{"~", STypes::OPERATOR | STypes::PREFIX},
    std::pair<std::string, std::size_t>{"<<", STypes::OPERATOR | STypes::BOTH},
    std::pair<std::string, std::size_t>{">>", STypes::OPERATOR | STypes::BOTH},
    std::pair<std::string, std::size_t>{".", STypes::OPERATOR | STypes::DOT},
    std::pair<std::string, std::size_t>{"->", STypes::OPERATOR | STypes::ARROW},
    // std::pair<std::string, std::string> {"++E", "e"},
    // std::pair<std::string, std::string> {"++O", "o"},
    // std::pair<std::string, std::string> {"--E", "e"},
    // std::pair<std::string, std::string> {"--O", "o"},
    // std::pair<std::string, std::string> {"()__CAST__", "ei"},
    // std::pair<std::string, std::string> {"::", "b"},
    // std::pair<std::string, std::string> {"()", "oi"},
    // std::pair<std::string, std::string> {"()", "oi"},
    // std::pair<std::string, std::string> {"[]", "oi"},
    // std::pair<std::string, std::string> {"&__PTR__", "e"},
    // std::pair<std::string, std::string> {"*__PTR__", "e"},

    // TODO: Not so sure about putting space here after new and delete
    // std::pair<std::string, std::string> {"new ", "e"},
    // std::pair<std::string, std::string> {"delete ", "e"},
    // std::pair<std::string, std::string> {"sizeof()", "ei"},
};

std::vector<Statement> parse(FILE* file) {
  DContainer<char> container{0};
  int c;
  while ((c = fgetc(file)) != EOF) {
    container.push_back(c);
  }
  std::stringstream ss{};
  ss << container;
  std::vector<Statement> statements;
  short int mode{0};
  bool end_of_term;
  /**
   * @brief
   *  Modes:
   *      0 : not in statement
   *      1 : in statement
   *      2 : in preprocessor directive
   */
  std::string currentTerm{""}, wholeStatement{""};
  for (int i{0}; i < container.size(); ++i) {
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
        if (currentTerm == "") case 'a' ... 'z':
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
      if (a ==) }
  }

  // std::stringstream ss{ file };
}


