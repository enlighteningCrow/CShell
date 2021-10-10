#include <bits/stdc++.h>

#include "misc.h"
#include "utils.h"

class Exception : public std::exception {
    std::string message;

public:
    Exception(const char* m = "")
        : message{ m } {
    }

    virtual const char* what() const noexcept override {
        return message.c_str();
        // return "DContainer is out of bounds";
    }
};

// template <class T>
// class DContainer {
//  protected:
//   T* m_contents;
//   std::size_t m_size;
//   std::size_t m_allocated;

//  public:
//   DContainer(int size = 0)
//       : m_contents{(T*)malloc(size)}, m_size{size}, m_allocated{size} {}
//   DContainer(std::initializer_list<T> list)
//       : m_contents{(T*)malloc(list.size() * sizeof(T))}, m_size{list.size()}
//       {
//     T* ptr{m_contents};
//     for (const T& i : list) {
//       *(m_contents++) = i;
//     }
//   }
//   ~DContainer() { free(m_contents); }
//   T& operator[](std::size_t index) {
//     if (index < 0) index += m_size;
//     if (index >= m_size || index < 0) {
//       throw Exception{"DContainer is out of bounds"};
//     }
//     return *(index + m_contents);
//   }
//   DContainer<T>& push_back(const T& element) {
//     ++m_size;
//     if (m_size > m_allocated) {
//       m_contents = realloc(m_contents, (std::size_t)(m_size * 1.5 + 1));
//       m_allocated = (std::size_t)(m_size * 1.5 + 1);
//     }
//     *(m_contents + m_size - 1) = element;
//     return *this;
//   }
//   DContainer<T>& pop_back() {
//     --m_size;
//     if (m_size < (std::size_t)(m_allocated * 0.7)) {
//       m_contents = realloc(m_contents, (std::size_t)(m_size * 0.7 + 1));
//       m_allocated = (std::size_t)(m_size * 0.7 + 1);
//     }
//     return *this;
//   }
//   friend std::stringstream& operator<<(std::stringstream& ss,
//                                        DContainer<T>& dc) {
//     for (int i{0}; i < m_size; ++i) ss << dc[i];
//     return ss;
//   }
//   std::size_t size() const { return m_size; }
// };

class Classifier {
    std::vector<std::string> types;
    // std::vector<std::string>;

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
        SINGLE_QUOTE = (1ULL << 10),
        DOUBLE_QUOTE = (1ULL << 11),
        MULTIPLE = (1ULL << 12),
        OPTIONAL = (1ULL << 13),
        ASTERISK = (1ULL << 14),
        ASTERISK_OR_AMPERSAND = (1ULL << 15),
        ASSIGMENT = (1ULL << 16),
        COMMA = (1ULL << 17),
        STRUCT = (1ULL << 18),
        ENUM = (1ULL << 19),
        CASE = (1ULL << 20),
        WHOLE_STATEMENT = (1ULL << 21),
        DO = (1ULL << 22),
        WHILE = (1ULL << 23),
        FOR = (1ULL << 24),
        GOTO = (1ULL << 25),
        IF = (1ULL << 26),
        ELSE = (1ULL << 27),
        SIZEOF = (1UL << 28),
        RETURN = (1UL << 29),
        SWITCH = (1UL << 30),
        BREAK = (1UL << 31),
        TYPEDEF = (1UL << 32),
        UNION = (1UL << 33),
        QUESTION = (1UL << 34),
        QELSE = (1UL << 35),
        DOT = (1UL << 36),
        ARROW = (1UL << 37),
        COLON = (1ULL << 38),
        PREPROCESSOR_DEFINE = (1UL << 39),
        PREPROCESSOR_ELIF = (1UL << 40),
        PREPROCESSOR_ELSE = (1UL << 41),
        PREPROCESSOR_ENDIF = (1UL << 42),
        PREPROCESSOR_ERROR = (1UL << 43),
        PREPROCESSOR_IF = (1UL << 44),
        PREPROCESSOR_IFDEF = (1UL << 45),
        PREPROCESSOR_IFNDEF = (1UL << 46),
        PREPROCESSOR_INCLUDE = (1UL << 47),
        PREPROCESSOR_PRAGMA = (1UL << 48),
        PREPROCESSOR_UNDEF = (1UL << 49),
        REQUIRE_LVALUE = (1ULL << 53),
        REQUIRE_RVALUE = (1ULL << 54),
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

    struct Types {
    public:
        String type_name;
        Array<Pair<Types, String>> type_vars;
        Types(const String& name, const Array<Pair<Types, String>>& vars)
            : type_name{ name }
            , type_vars{ vars }
        {
        }
    };

    // types += Types{ "char", Array<Pair<Types, String>>(0) };

    // std::pair<std::size_t, Types>{
    Array<Types> types{ Types { "char", Array<Pair<Types, String>>(0) },
        Types { "int", Array<Pair<Types, String>>(0) },
        Types { "float", Array<Pair<Types, String>>(0) },
        Types { "double", Array<Pair<Types, String>>(0) } };

    // class Operator {
    //   std::string HOLDER123;
    // };

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
        Expression(std::string)
            : m_evaluated_type{ m_evaluated_type } {
        }
    };

    class Statement {
    protected:
        std::size_t statement_id;

    public:
        Statement(std::size_t id)
            : statement_id{ id } {
        }
    };

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
        Scope()
            : m_members{}
            , m_methods{}
            , m_objects{}
            , m_statements{}
        {
        }
        Scope(const std::vector<Statement>& statements)
            : m_members{}
            , m_methods{}
            , m_objects{}
            , m_statements{ statements }
        {
        }
        // TODO: this
        Scope& add_scope() {}
    } global{};

    // std::vector<Statement> parse(std::fstream& file) {
    //   std::stringstream ss{file};
    // }

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
   * -2, means dependent on type of variable)
   *              id of statement type Note: STypes
   * stands for Statement Types Upon seing anything with return value with
   * higher level of precedence, evaluate it first. Note: Support for
   * default-int
   */
    Array<Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>>
        statement_types{
            Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>> {
                { // Variable Declaration with initialization
                    STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL,
                    STypes::TYPE,
                    STypes::ASTERISK_OR_AMPERSAND | STypes::MULTIPLE,
                    STypes::NAME,
                    STypes::ASSIGMENT,
                    STypes::LITERAL | STypes::NAME,
                    STypes::SEMICOLON },
                Pair<std::size_t, std::size_t>(0, 0) },
            Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>> {
                { // Variable Declaration
                    STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL,
                    STypes::TYPE,
                    STypes::ASTERISK_OR_AMPERSAND | STypes::MULTIPLE,
                    STypes::NAME,
                    STypes::SEMICOLON },
                Pair<std::size_t, std::size_t>(0, 0) },
            Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>> {
                { // Variable Declaration array with initialization
                    STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL,
                    STypes::TYPE,
                    STypes::ASTERISK_OR_AMPERSAND | STypes::MULTIPLE,
                    STypes::NAME,
                    STypes::BRACE | STypes::OPEN,
                    STypes::LITERAL | STypes::NAME,
                    STypes::BRACE | STypes::CLOSE,
                    STypes::ASSIGMENT,
                    STypes::LITERAL | STypes::NAME,
                    STypes::SEMICOLON },
                Pair<std::size_t, std::size_t>(0, 0) },
            Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>> {
                { // Variable Declaration array
                    STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL,
                    STypes::TYPE,
                    STypes::ASTERISK_OR_AMPERSAND | STypes::MULTIPLE,
                    STypes::NAME,
                    STypes::BRACE | STypes::OPEN,
                    STypes::LITERAL | STypes::NAME,
                    STypes::BRACE | STypes::CLOSE,
                    STypes::SEMICOLON },
                Pair<std::size_t, std::size_t>(0, 0) },
            Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>> {
                { // Function Definition
                    STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL,
                    STypes::TYPE,
                    STypes::ASTERISK_OR_AMPERSAND | STypes::MULTIPLE,
                    STypes::NAME,
                    STypes::PARENTHESIS | STypes::OPEN,
                    STypes::TYPE | STypes::NAME | STypes::OPTIONAL,
                    STypes::COMMA | STypes::TYPE | STypes::NAME | STypes::MULTIPLE | STypes::OPTIONAL, // STypes::COMMA_TYPE_AND_NAME |
                    // STypes::OPTIONAL | STypes::MULTIPLE,
                    STypes::PARENTHESIS | STypes::CLOSE,
                    STypes::CURLY_BRACE | STypes::OPEN,
                    STypes::STATEMENT | STypes::OPTIONAL | STypes::MULTIPLE,
                    STypes::CURLY_BRACE | STypes::CLOSE },
                Pair<std::size_t, std::size_t>(0, 1) },
            Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>> {
                { // Function Declaration
                    STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL,
                    STypes::TYPE,
                    STypes::ASTERISK_OR_AMPERSAND | STypes::MULTIPLE,
                    STypes::NAME,
                    STypes::PARENTHESIS | STypes::OPEN,
                    STypes::TYPE | STypes::NAME | STypes::OPTIONAL,
                    STypes::COMMA | STypes::TYPE | STypes::NAME | STypes::MULTIPLE | STypes::OPTIONAL, // STypes::COMMA_TYPE_AND_NAME |
                    // STypes::OPTIONAL | STypes::MULTIPLE,
                    STypes::PARENTHESIS | STypes::CLOSE,
                    STypes::SEMICOLON },
                Pair<std::size_t, std::size_t>(0, 1) },
            Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>> {
                {
                    // Function Call
                    STypes::NAME,
                    STypes::PARENTHESIS | STypes::OPEN,
                    STypes::NAME | STypes::LITERAL | STypes::OPTIONAL,
                    STypes::COMMA | STypes::NAME | STypes::LITERAL | STypes::MULTIPLE | STypes::OPTIONAL, // STypes::COMMA_TYPE_AND_NAME |
                    // STypes::OPTIONAL | STypes::MULTIPLE,
                    STypes::PARENTHESIS | STypes::CLOSE,
                },
                Pair<std::size_t, std::size_t>(-1, 1) },
            Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>> {
                { // Blank statement
                    STypes::NAME | STypes::LITERAL,
                    STypes::SEMICOLON },
                Pair<std::size_t, std::size_t>(0, 1) },
            Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>> {
                { // Casting statement
                    STypes::PARENTHESIS | STypes::OPEN,
                    STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL,
                    STypes::TYPE,
                    STypes::PARENTHESIS | STypes::CLOSE,
                    STypes::NAME | STypes::LITERAL },
                Pair<std::size_t, std::size_t>(-1, 1) },
            Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>> {
                { // Type-call statement
                    STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL,
                    STypes::TYPE,
                    STypes::PARENTHESIS | STypes::OPEN,
                    STypes::NAME | STypes::LITERAL | STypes::OPTIONAL,
                    STypes::PARENTHESIS | STypes::CLOSE },
                Pair<std::size_t, std::size_t>(-1, 1) },
            Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>> {
                { // Operator both
                    STypes::NAME | STypes::LITERAL,
                    STypes::OPERATOR | STypes::BOTH,
                    STypes::NAME | STypes::LITERAL } },
            Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>> {
                { // Operator prefix
                    STypes::OPERATOR | STypes::PREFIX,
                    STypes::NAME | STypes::LITERAL } },
            Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>> {
                { // Operator postfix
                    STypes::NAME | STypes::LITERAL,
                    STypes::OPERATOR | STypes::PREFIX } },
            Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>> {
                { // Operator postfix
                    STypes::NAME | STypes::LITERAL,
                    STypes::OPERATOR | STypes::PREFIX } }
    };

    // TODO: types can also be called as functions.

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

    Map<String, std::size_t> key_expressions{
        std::initializer_list<Pair<String, std::size_t>> {
            Pair<String, std::size_t> { "auto", STypes::TYPE_MODIFIER },
            Pair<String, std::size_t> { "break", STypes::BREAK },
            Pair<String, std::size_t> { "case", STypes::CASE },
            Pair<String, std::size_t> { "char", STypes::TYPE },
            Pair<String, std::size_t> { "const", STypes::TYPE_MODIFIER },
            Pair<String, std::size_t> { "continue", STypes::WHOLE_STATEMENT },
            Pair<String, std::size_t> { "default", STypes::LABEL },
            Pair<String, std::size_t> { "do", STypes::DO },
            Pair<String, std::size_t> { "double", STypes::TYPE },
            Pair<String, std::size_t> { "else", STypes::ELSE },
            Pair<String, std::size_t> { "enum", STypes::ENUM },
            Pair<String, std::size_t> { "extern", STypes::TYPE_MODIFIER },
            Pair<String, std::size_t> { "float", STypes::TYPE },
            Pair<String, std::size_t> { "for", STypes::FOR },
            Pair<String, std::size_t> { "goto", STypes::GOTO },
            Pair<String, std::size_t> { "if", STypes::ELSE },
            Pair<String, std::size_t> { "int", STypes::TYPE },
            Pair<String, std::size_t> { "long", STypes::TYPE_MODIFIER },
            Pair<String, std::size_t> { "register", STypes::TYPE_MODIFIER },
            Pair<String, std::size_t> { "return", STypes::RETURN },
            Pair<String, std::size_t> { "short", STypes::TYPE_MODIFIER },
            Pair<String, std::size_t> { "signed", STypes::TYPE_MODIFIER },
            Pair<String, std::size_t> { "sizeof", STypes::SIZEOF },
            Pair<String, std::size_t> { "static", STypes::TYPE_MODIFIER },
            Pair<String, std::size_t> { "struct", STypes::STRUCT },
            Pair<String, std::size_t> { "switch", STypes::SWITCH },
            Pair<String, std::size_t> { "typedef", STypes::TYPEDEF },
            Pair<String, std::size_t> { "union", STypes::UNION },
            Pair<String, std::size_t> { "unsigned", STypes::TYPE_MODIFIER },
            Pair<String, std::size_t> { "void", STypes::VOID_TYPE },
            Pair<String, std::size_t> { "volatile", STypes::TYPE_MODIFIER },
            Pair<String, std::size_t> { "while", STypes::WHILE },
            Pair<String, std::size_t> { "#define", STypes::PREPROCESSOR_DEFINE },
            Pair<String, std::size_t> { "#elif", STypes::PREPROCESSOR_ELIF },
            Pair<String, std::size_t> { "#else", STypes::PREPROCESSOR_ELSE },
            Pair<String, std::size_t> { "#endif", STypes::PREPROCESSOR_ENDIF },
            Pair<String, std::size_t> { "#error", STypes::PREPROCESSOR_ERROR },
            Pair<String, std::size_t> { "#if", STypes::PREPROCESSOR_IF },
            Pair<String, std::size_t> { "#ifdef", STypes::PREPROCESSOR_IFDEF },
            Pair<String, std::size_t> { "#ifndef", STypes::PREPROCESSOR_IFNDEF },
            Pair<String, std::size_t> { "#include", STypes::PREPROCESSOR_INCLUDE },
            Pair<String, std::size_t> { "#pragma", STypes::PREPROCESSOR_PRAGMA },
            Pair<String, std::size_t> { "#undef", STypes::PREPROCESSOR_UNDEF },
            Pair<String, std::size_t> { "=", STypes::OPERATOR | STypes::BOTH },
            Pair<String, std::size_t> { "+", STypes::OPERATOR | STypes::BOTH },
            Pair<String, std::size_t> { "-",
                STypes::OPERATOR | STypes::BOTH | STypes::PREFIX },
            Pair<String, std::size_t> { "*", STypes::OPERATOR | STypes::BOTH },
            Pair<String, std::size_t> { "/", STypes::OPERATOR | STypes::BOTH },
            Pair<String, std::size_t> { "%", STypes::OPERATOR | STypes::BOTH },
            Pair<String, std::size_t> { "+=",
                STypes::OPERATOR | STypes::BOTH | STypes::REQUIRE_LVALUE },
            Pair<String, std::size_t> { "-=",
                STypes::OPERATOR | STypes::BOTH | STypes::REQUIRE_LVALUE },
            Pair<String, std::size_t> { "*=",
                STypes::OPERATOR | STypes::BOTH | STypes::REQUIRE_LVALUE },
            Pair<String, std::size_t> { "/=",
                STypes::OPERATOR | STypes::BOTH | STypes::REQUIRE_LVALUE },
            Pair<String, std::size_t> { "%=",
                STypes::OPERATOR | STypes::BOTH | STypes::REQUIRE_LVALUE },
            Pair<String, std::size_t> { ">>=",
                STypes::OPERATOR | STypes::BOTH | STypes::REQUIRE_LVALUE },
            Pair<String, std::size_t> { "<<=",
                STypes::OPERATOR | STypes::BOTH | STypes::REQUIRE_LVALUE },
            Pair<String, std::size_t> { "&=",
                STypes::OPERATOR | STypes::BOTH | STypes::REQUIRE_LVALUE },
            Pair<String, std::size_t> { "^=",
                STypes::OPERATOR | STypes::BOTH | STypes::REQUIRE_LVALUE },
            Pair<String, std::size_t> { "|=",
                STypes::OPERATOR | STypes::BOTH | STypes::REQUIRE_LVALUE },
            Pair<String, std::size_t> { "++",
                STypes::OPERATOR | STypes::PREFIX | STypes::POSTFIX },
            Pair<String, std::size_t> { "--",
                STypes::OPERATOR | STypes::PREFIX | STypes::POSTFIX },
            Pair<String, std::size_t> { "==", STypes::OPERATOR | STypes::BOTH },
            Pair<String, std::size_t> { "!=", STypes::OPERATOR | STypes::BOTH },
            Pair<String, std::size_t> { ">", STypes::OPERATOR | STypes::BOTH },
            Pair<String, std::size_t> { "<", STypes::OPERATOR | STypes::BOTH },
            Pair<String, std::size_t> { ">=",
                STypes::OPERATOR | STypes::BOTH | STypes::REQUIRE_LVALUE },
            Pair<String, std::size_t> { "<=",
                STypes::OPERATOR | STypes::BOTH | STypes::REQUIRE_LVALUE },
            Pair<String, std::size_t> { "!", STypes::OPERATOR | STypes::PREFIX },
            Pair<String, std::size_t> { "&&", STypes::OPERATOR | STypes::BOTH },
            Pair<String, std::size_t> { "||", STypes::OPERATOR | STypes::BOTH },
            Pair<String, std::size_t> { "?", STypes::OPERATOR | STypes::QUESTION },
            Pair<String, std::size_t> { ":", STypes::OPERATOR | STypes::QELSE },
            Pair<String, std::size_t> { ",", STypes::OPERATOR | STypes::COMMA },
            Pair<String, std::size_t> { "&", STypes::OPERATOR | STypes::BOTH },
            Pair<String, std::size_t> { "|", STypes::OPERATOR | STypes::BOTH },
            Pair<String, std::size_t> { "^", STypes::OPERATOR | STypes::BOTH },
            Pair<String, std::size_t> { "~", STypes::OPERATOR | STypes::PREFIX },
            Pair<String, std::size_t> { "<<", STypes::OPERATOR | STypes::BOTH },
            Pair<String, std::size_t> { ">>", STypes::OPERATOR | STypes::BOTH },
            Pair<String, std::size_t> { ".", STypes::OPERATOR | STypes::DOT },
            Pair<String, std::size_t> { "->", STypes::OPERATOR | STypes::ARROW },
            Pair<String, std::size_t> { "{", STypes::CURLY_BRACE | STypes::OPEN },
            Pair<String, std::size_t> { "}", STypes::CURLY_BRACE | STypes::CLOSE },
            Pair<String, std::size_t> { "[", STypes::BRACE | STypes::OPEN },
            Pair<String, std::size_t> { "]", STypes::BRACE | STypes::CLOSE },
            Pair<String, std::size_t> { "(", STypes::PARENTHESIS | STypes::OPEN },
            Pair<String, std::size_t> { ")", STypes::PARENTHESIS | STypes::CLOSE },
            Pair<String, std::size_t> { "'", STypes::SINGLE_QUOTE },
            Pair<String, std::size_t> { "\"", STypes::DOUBLE_QUOTE },
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
            }
    };

    // std::vector<Statement> parse(FILE* file) {
    //   DContainer<char> container{0};
    //   int c;
    //   while ((c = fgetc(file)) != EOF) {
    //     container.push_back(c);
    //   }
    //   std::stringstream ss{};
    //   ss << container;
    //   std::vector<Statement> statements;
    //   short int mode{0};
    //   bool end_of_term;
    //   /**
    //    * @brief
    //    *  Modes:
    //    *      0 : not in statement
    //    *      1 : in statement
    //    *      2 : in preprocessor directive
    //    */
    //   std::string currentTerm{""}, wholeStatement{""};
    //   for (int i{0}; i < container.size(); ++i) {
    //     switch (container[i]) {
    //       case '\n':
    //         if (mode == 2) {
    //           break;
    //         }
    //       case ' ':
    //         if (mode) {
    //           break;
    //         }
    //       case '\t':
    //         if (mode) {
    //           break;
    //         }
    //       case 'EOF':
    //         if (mode) {
    //           break;
    //         }
    //         continue;
    //       case '0' ... '9':
    //         if (currentTerm == "") case 'a' ... 'z':
    //         case 'A' ... 'Z':
    //           currentTerm += container[i];
    //       case '#':
    //         if (currentTerm == "") {
    //           mode = 2;
    //         }
    //         currentTerm += container[i];

    //       default:
    //     }
    //     if (end_of_term) {
    //       auto a = type(currentTerm);
    //       if (a ==) }
    //   }

    //   // std::stringstream ss{ file };
    // }

    // Classifier& parse(FILE* file) {
    //   String container{};
    //   int c;
    //   while ((c = fgetc(file)) != EOF) {
    //     container.push_back(c);
    //   }
    //   std::stringstream ss{};
    //   ss << container;
    //   std::vector<Statement> statements;
    //   short int mode{ 0 };
    //   bool end_of_term;
    //   /**
    //    * @brief
    //    *  Modes:
    //    *      0 : not in statement
    //    *      1 : in statement
    //    *      2 : in preprocessor directive
    //    */
    //   std::string currentTerm{ "" }, wholeStatement{ "" };
    //   for (int i{0}; i < container.size(); ++i) {
    //     switch (container[i]) {
    //       case '\n':
    //         if (mode == 2) {
    //           break;
    //         }
    //       case ' ':
    //         if (mode) {
    //           break;
    //         }
    //       case '\t':
    //         if (mode) {
    //           break;
    //         }
    //       case 'EOF':
    //         if (mode) {
    //           break;
    //         }
    //         continue;
    //       case '0' ... '9':
    //         if (currentTerm == "") case 'a' ... 'z':
    //         case 'A' ... 'Z':
    //           currentTerm += container[i];
    //       case '#':
    //         if (currentTerm == "") {
    //           mode = 2;
    //         }
    //         currentTerm += container[i];

    //       default:
    //     }
    //     if (end_of_term) {
    //       auto a = type(currentTerm);
    //       if (a ==) }
    //   }

    //   // std::stringstream ss{ file };
    // }

    Classifier& parse(FILE* file) {
        String container{};
        int c;
        std::stringstream ss{};
        ss << container;
        std::vector<Statement> statements;
        // Note: stm -> statement
        Array<Statement> stm(0);
        // Note: combined STypes
        Array<std::size_t> exp(0);
        // Note: ws -> was special, wsp -> was special prior
        bool ws{ false }, wsp{ false };
        short int mode{ 0 };
        bool end_of_term;
        std::size_t find_result{ 0UL };
        for (; (c = fgetc(file)) != EOF; wsp = ws) {
            ws = !((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
            container.push_back(c);
            if (!(ws || wsp)) {}
            else {
                if ((find_result = key_expressions.find(container)) != key_expressions.size()) {
                    exp.push_back(key_expressions(find_result).second);
                }
                //TODO: Check this with the statements map above (defining all c statements)
                if ()
                    // if (container ==) {
                    //   std::cout << container;
                    // }
            }
        }
    }
    /**
   * @brief
   *  Modes:
   *      0 : not in statement
   *      1 : in statement
   *      2 : in preprocessor directive
   */
};