//#include "stdc++.h"
#include "stdc++.h"

#include "misc.h"
#include "utils.h"

// #include ""

class Exception : public std::exception {
    std::string message;

public:
    Exception(const char *m = "") : message{m} {}

    virtual const char *what() const noexcept override {
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
    class Word {
    public:
        String name;
        Word(const String &str) : name(str) {}
    };
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
        OPERATOR      = (1ULL << 0),
        NAME          = (1ULL << 1),
        TYPE          = (1ULL << 2),
        VOID_TYPE     = (1ULL << 3),
        TYPE_MODIFIER = (1ULL << 4),
        LABEL         = (1ULL << 5),
        STATEMENT     = (1ULL << 6),
        PARENTHESIS   = (1ULL << 7),
        CURLY_BRACE   = (1ULL << 8),
        BRACE         = (1ULL << 9),
        SINGLE_QUOTE  = (1ULL << 10),
        DOUBLE_QUOTE  = (1ULL << 11),
        MULTIPLE      = (1ULL << 12),
        OPTIONAL      = (1ULL << 13),
        ASTERISK      = (1ULL << 14),
        // TODO: Fix all the below:
        AMPERSAND             = (1ULL << 15),
        ASTERISK_OR_AMPERSAND = (1ULL << 15),
        ASSIGMENT             = (1ULL << 16),
        COMMA                 = (1ULL << 17),
        STRUCT                = (1ULL << 18),
        ENUM                  = (1ULL << 19),
        UNION                 = (1ULL << 20),
        CASE                  = (1ULL << 21),
        WHOLE_STATEMENT       = (1ULL << 22),
        DO                    = (1ULL << 23),
        WHILE                 = (1ULL << 24),
        FOR                   = (1ULL << 25),
        GOTO                  = (1ULL << 26),
        IF                    = (1ULL << 27),
        ELSE                  = (1ULL << 28),
        SIZEOF                = (1ULL << 29),
        RETURN                = (1ULL << 30),
        SWITCH                = (1ULL << 31),
        BREAK                 = (1ULL << 32),
        TYPEDEF               = (1ULL << 33),
        QUESTION              = (1ULL << 34),
        QELSE                 = (1ULL << 35),
        DOT                   = (1ULL << 36),
        ARROW                 = (1ULL << 37),
        COLON                 = (1ULL << 38),
        PREPROCESSOR_DEFINE   = (1ULL << 39),
        PREPROCESSOR_ELIF     = (1ULL << 40),
        PREPROCESSOR_ELSE     = (1ULL << 41),
        PREPROCESSOR_ENDIF    = (1ULL << 42),
        PREPROCESSOR_ERROR    = (1ULL << 43),
        PREPROCESSOR_IF       = (1ULL << 44),
        PREPROCESSOR_IFDEF    = (1ULL << 45),
        PREPROCESSOR_IFNDEF   = (1ULL << 46),
        PREPROCESSOR_INCLUDE  = (1ULL << 47),
        PREPROCESSOR_PRAGMA   = (1ULL << 48),
        PREPROCESSOR_UNDEF    = (1ULL << 49),
        CONTAINS_PRECEDENCE   = (1ULL << 50),
        CONTAINS_PRECEDENCE   = (1ULL << 51),
        CONTAINS_PRECEDENCE   = (1ULL << 52),
        REQUIRE_LVALUE        = (1ULL << 53),
        REQUIRE_RVALUE        = (1ULL << 54),
        SEMICOLON             = (1ULL << 55),
        LITERAL               = (1ULL << 56),
        COMMA_AND_NAME        = (1ULL << 57),
        COMMA_TYPE_AND_NAME   = (1ULL << 58),
        PREFIX                = (1ULL << 59),
        POSTFIX               = (1ULL << 60),
        BOTH                  = (1ULL << 61),
        OPEN                  = (1ULL << 62),
        CLOSE                 = (1ULL << 63),
    };

    // Map<std::size_t, std::size_t>
    Map<String, std::size_t> key_expressions{
        std::initializer_list<Pair<String, std::size_t>> {
            Pair<String, std::size_t>{"=", 0ULL},
                Pair<String, std::size_t>{"+", 0ULL},
                Pair<String, std::size_t>{"-", 0ULL},
                Pair<String, std::size_t>{"*", 0ULL},
                Pair<String, std::size_t>{"/", 0ULL},
                Pair<String, std::size_t>{"%", 0ULL},
                Pair<String, std::size_t>{"+=", 0ULL},
                Pair<String, std::size_t>{"-=", 0ULL},
                Pair<String, std::size_t>{"*=", 0ULL},
                Pair<String, std::size_t>{"/=", 0ULL},
                Pair<String, std::size_t>{"%=", 0ULL},
                Pair<String, std::size_t>{">>=", 0ULL},
                Pair<String, std::size_t>{"<<=", 0ULL},
                Pair<String, std::size_t>{"&=", 0ULL},
                Pair<String, std::size_t>{"^=", 0ULL},
                Pair<String, std::size_t>{"|=", 0ULL},
                Pair<String, std::size_t>{"++", 0ULL},
                Pair<String, std::size_t>{"--", 0ULL},
                Pair<String, std::size_t>{"==", 0ULL},
                Pair<String, std::size_t>{"!=", 0ULL},
                Pair<String, std::size_t>{">", 0ULL},
                Pair<String, std::size_t>{"<", 0ULL},
                Pair<String, std::size_t>{">=", 0ULL},
                Pair<String, std::size_t>{"<=", 0ULL},
                Pair<String, std::size_t>{"!", 0ULL},
                Pair<String, std::size_t>{"&&", 0ULL},
                Pair<String, std::size_t>{"||", 0ULL},
                Pair<String, std::size_t>{"?", 0ULL},
                Pair<String, std::size_t>{":", 0ULL},
                Pair<String, std::size_t>{"&", 0ULL},
                Pair<String, std::size_t>{"|", 0ULL},
                Pair<String, std::size_t>{"^", 0ULL},
                Pair<String, std::size_t>{"~", 0ULL},
                Pair<String, std::size_t>{"<<", 0ULL},
                Pair<String, std::size_t>{">>", 0ULL},
                Pair<String, std::size_t>{".", 0ULL},
                Pair<String, std::size_t>{"->", 0ULL},
                Pair<String, std::size_t>{"{", 0ULL},
                Pair<String, std::size_t>{"}", 0ULL},
                Pair<String, std::size_t>{"[", 0ULL},
                Pair<String, std::size_t>{"]", 0ULL},
                Pair<String, std::size_t>{"(", 0ULL},
                Pair<String, std::size_t>{")", 0ULL},
                Pair<String, std::size_t>{"'", 0ULL},
                Pair<String, std::size_t>{"\"", 0ULL},
                Pair<String, std::size_t>{",", 0ULL},
        }
    }

                inline bool checkIs(std::size_t a, std::size_t b) {
                return a & b;
            }

            enum JunctionMode {
                IN    = (1ULL << 0),
                AFTER = (1ULL << 1),
            };

            class Types : Word {
            public:
                // String type_name;
                Array<Pair<Types, String>> type_vars;
                Types(const String &name, const Array<Pair<Types, String>> &vars)
                    // : type_name { name }
                    :
                    Word{name},
                    type_vars{vars} {}
            };

            // types += Types{ "char", Array<Pair<Types, String>>(0) };

            // std::pair<std::size_t, Types>{
            Array<Types> types{
                Types{"char", Array<Pair<Types, String>>(0)}, Types{"int", Array<Pair<Types, String>>(0)},
                Types{"float", Array<Pair<Types, String>>(0)}, Types{"double", Array<Pair<Types, String>>(0)}};

            // class Operator {
            //   std::string HOLDER123;
            // };

            class Variable : Word {
            public:
                Types m_type;
                Variable(const Types &type, const String &name) : Word{name}, m_type{type} {}
                // String name;
            };

            class Function : Word {
            public:
                // String name;
                Types m_type;
                // String m_return_type;
                std::vector<String> m_param_types;
                Function(const Types &type, const String &name) : Word{name}, m_type{type}, m_param_types{} {}
                Function(const Types &type, const String &name, const std::vector<String> &params) :
                    Word{name}, m_type{type}, m_param_types{params} {}
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

            class Statement {
            protected:
                std::size_t statement_id;

            public:
                Statement(std::size_t id) : statement_id{id} {}
            };

            class Scope {
                std::vector<Scope *> m_nested_namespaces;

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
                Types                 m_type;
                std::vector<Variable> m_members;
                std::vector<Function> m_methods;
                // Stands for class/struct/enum names.
                std::vector<std::string>                  m_types;
                std::map<std::string, std::vector<Scope>> m_objects;
                std::vector<Statement>                    m_statements;

            public:
                Scope() : m_members{}, m_methods{}, m_objects{}, m_statements{} {}
                Scope(const std::vector<Statement> &statements) :
                    m_members{}, m_methods{}, m_objects{}, m_statements{statements} {}
                // TODO: this
                Scope &add_scope() {}
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
             *              -2, means dependent on type of variable, 1 means returns a type, 0 means no return, 2 means
             * literal) id of statement type Note: STypes stands for Statement Types Upon seing anything with return
             * value with higher level of precedence, evaluate it first. Note: Support for default-int
             *
             *
             *
             *
             *  NOTE!!!!!!!!!!!!!:
             *      THe second one in the Pair is the precedence (all are different) (higher means gets parsed first)
             */

            // enum Returns {
            //
            // }

            Array<Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>> statement_types_inversed{
                Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>{
                    {// Blank statement
                     STypes::NAME | STypes::LITERAL, STypes::SEMICOLON},
                    Pair<std::size_t, std::size_t>(STypes::NONE, 0)},
                Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>{
                    {// Variable Declaration with initialization
                     STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL, STypes::TYPE,
                     STypes::ASTERISK_OR_AMPERSAND | STypes::MULTIPLE, STypes::NAME, STypes::ASSIGMENT,
                     STypes::LITERAL | STypes::NAME, STypes::SEMICOLON},
                    Pair<std::size_t, std::size_t>(STypes::NONE, 1)},
                Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>{
                    {// Variable Declaration
                     STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL, STypes::TYPE,
                     STypes::ASTERISK_OR_AMPERSAND | STypes::MULTIPLE, STypes::NAME, STypes::SEMICOLON},
                    Pair<std::size_t, std::size_t>(STypes::NONE, 2)},
                Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>{
                    {// Variable Declaration array with initialization
                     STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL, STypes::TYPE,
                     STypes::ASTERISK_OR_AMPERSAND | STypes::MULTIPLE, STypes::NAME, STypes::BRACE | STypes::OPEN,
                     STypes::LITERAL | STypes::NAME, STypes::BRACE | STypes::CLOSE, STypes::ASSIGMENT,
                     STypes::LITERAL | STypes::NAME, STypes::SEMICOLON},
                    Pair<std::size_t, std::size_t>(STypes::NONE, 3)},
                Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>{
                    {// Variable Declaration array
                     STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL, STypes::TYPE,
                     STypes::ASTERISK_OR_AMPERSAND | STypes::MULTIPLE, STypes::NAME, STypes::BRACE | STypes::OPEN,
                     STypes::LITERAL | STypes::NAME, STypes::BRACE | STypes::CLOSE, STypes::SEMICOLON},
                    Pair<std::size_t, std::size_t>(STypes::NONE, 4)},
                Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>{
                    {// Function Definition
                     STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL, STypes::TYPE,
                     STypes::ASTERISK_OR_AMPERSAND | STypes::MULTIPLE, STypes::NAME, STypes::PARENTHESIS | STypes::OPEN,
                     STypes::TYPE | STypes::NAME | STypes::OPTIONAL,
                     STypes::COMMA | STypes::TYPE | STypes::NAME | STypes::MULTIPLE |
                         STypes::OPTIONAL, // STypes::COMMA_TYPE_AND_NAME |
                                           // STypes::OPTIONAL | STypes::MULTIPLE,
                     STypes::PARENTHESIS | STypes::CLOSE, STypes::CURLY_BRACE | STypes::OPEN,
                     STypes::STATEMENT | STypes::OPTIONAL | STypes::MULTIPLE, STypes::CURLY_BRACE | STypes::CLOSE},
                    Pair<std::size_t, std::size_t>(STypes::NONE, 6)},
                Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>{
                    {// Function Declaration
                     STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL, STypes::TYPE,
                     STypes::ASTERISK_OR_AMPERSAND | STypes::MULTIPLE, STypes::NAME, STypes::PARENTHESIS | STypes::OPEN,
                     STypes::TYPE | STypes::NAME | STypes::OPTIONAL,
                     STypes::COMMA | STypes::TYPE | STypes::NAME | STypes::MULTIPLE |
                         STypes::OPTIONAL, // STypes::COMMA_TYPE_AND_NAME |
                                           // STypes::OPTIONAL | STypes::MULTIPLE,
                     STypes::PARENTHESIS | STypes::CLOSE, STypes::SEMICOLON},
                    Pair<std::size_t, std::size_t>(STypes::NONE, 7)},
                Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>{
                    {
                        // Initializer list
                        STypes::CURLY_BRACE | STypes::OPEN,
                        STypes::LITERAL | STypes::MULTIPLE | STypes::OPTIONAL,
                        // STypes::TYPE,
                        // STypes::ASTERISK_OR_AMPERSAND | STypes::MULTIPLE,
                        // STypes::NAME,
                        // STypes::LITERAL | STypes::NAME,
                        STypes::COMMA | STypes::LITERAL | STypes::MULTIPLE | STypes::OPTIONAL,
                        STypes::CURLY_BRACE | STypes::CLOSE,
                    },
                    Pair<std::size_t, std::size_t>(STypes::LITERAL, 16)},
                Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>{
                    {// Operator postfix
                     STypes::NAME | STypes::LITERAL, STypes::OPERATOR | STypes::PREFIX},
                    Pair<std::size_t, std::size_t>(-1, 18)},
                Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>{
                    {// Operator prefix
                     STypes::OPERATOR | STypes::PREFIX, STypes::NAME | STypes::LITERAL},
                    Pair<std::size_t, std::size_t>(-1, 19)},
                Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>{
                    {// Operator both
                     STypes::NAME | STypes::LITERAL, STypes::OPERATOR | STypes::BOTH, STypes::NAME | STypes::LITERAL},
                    Pair<std::size_t, std::size_t>(-1, 20)},
                Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>{
                    {// Type-call statement
                     STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL, STypes::TYPE,
                     STypes::PARENTHESIS | STypes::OPEN, STypes::NAME | STypes::LITERAL | STypes::OPTIONAL,
                     STypes::PARENTHESIS | STypes::CLOSE},
                    Pair<std::size_t, std::size_t>(-1, 21)},
                Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>{
                    {// Casting statement
                     STypes::PARENTHESIS | STypes::OPEN, STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL,
                     STypes::TYPE, STypes::PARENTHESIS | STypes::CLOSE, STypes::NAME | STypes::LITERAL},
                    Pair<std::size_t, std::size_t>(-1, 22)},
                Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>{
                    {// Parentheses
                     //  STypes::NAME | STypes::LITERAL, STypes::OPERATOR | STypes::PREFIX
                     STypes::PARENTHESIS | STypes::OPEN, STypes::LITERAL | STypes::NAME,
                     STypes::PARENTHESIS | STypes::CLOSE},
                    Pair<std::size_t, std::size_t>(-1, 23)},
                Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>{
                    {
                        // Function Call
                        STypes::NAME,
                        STypes::PARENTHESIS | STypes::OPEN,
                        STypes::NAME | STypes::LITERAL | STypes::OPTIONAL,
                        STypes::COMMA | STypes::NAME | STypes::LITERAL | STypes::MULTIPLE |
                            STypes::OPTIONAL, // STypes::COMMA_TYPE_AND_NAME |
                                              // STypes::OPTIONAL | STypes::MULTIPLE,
                        STypes::PARENTHESIS | STypes::CLOSE,
                    },
                    Pair<std::size_t, std::size_t>(-1, 24)},
                Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>{
                    {// Type name
                     STypes::STRUCT | STypes::ENUM | STypes::UNION, STypes::NAME},
                    Pair<std::size_t, std::size_t>(STypes::TYPE, 25)},
                // Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>> {
                //     { // Operator postfix
                //         STypes::NAME | STypes::LITERAL,
                //         STypes::OPERATOR | STypes::PREFIX } }
            };

            Array<Pair<Array<Pair<Array<std::size_t>, std::size_t>>, Pair<std::size_t, std::size_t>>>
                statement_types_arrays{
                    Pair<Array<Pair<Array<std::size_t>, std::size_t>>, Pair<std::size_t, std::size_t>>{
                        {// Type name
                         Pair<Array<std::size_t>, std::size_t>{
                             {STypes::TYPE_MODIFIER}, STypes::MULTIPLE | STypes::OPTIONAL},
                         Pair<Array<std::size_t>, std::size_t>{
                             {STypes::STRUCT | STypes::ENUM | STypes::UNION}, STypes::OPTIONAL},
                         Pair<Array<std::size_t>, std::size_t>{{STypes::NAME}, STypes::NONE},
                         Pair<Array<std::size_t>, std::size_t>{
                             {STypes::AMPERSAND | STypes::ASTERISK}, STypes::OPTIONAL | STypes::MULTIPLE}},
                        Pair<std::size_t, std::size_t>(STypes::TYPE, 25)},

                    // TODO: Copy the format of the above to below ones.
                    Pair<Array<Pair<Array<std::size_t>, std::size_t>>, Pair<std::size_t, std::size_t>>{
                        {
                            // Function Call
                            Pair<Array<std::size_t>, std::size_t>{{STypes::NAME}, STypes::NONE},
                            Pair<Array<std::size_t>, std::size_t>{{STypes::PARENTHESIS}, STypes::OPEN},
                            Pair<Array<std::size_t>, std::size_t>{{STypes::NAME | STypes::LITERAL}, STypes::OPTIONAL},
                            Pair<Array<std::size_t>, std::size_t>{
                                {STypes::COMMA, STypes::NAME | STypes::LITERAL},
                                STypes::MULTIPLE | STypes::OPTIONAL}, // STypes::COMMA_TYPE_AND_NAME |
                                                                      // STypes::OPTIONAL | STypes::MULTIPLE,
                            Pair<Array<std::size_t>, std::size_t>{{STypes::PARENTHESIS}, STypes::CLOSE},
                        },
                        Pair<std::size_t, std::size_t>(-1, 24)},
                    Pair<Array<Pair<Array<std::size_t>, std::size_t>>, Pair<std::size_t, std::size_t>>{
                        {
                            // Function Call
                            Pair<Array<std::size_t>, std::size_t>{
                                {STypes::AMPERSAND | STypes::ASTERISK}, STypes::OPTIONAL | STypes::MULTIPLE},
                            Pair<Array<std::size_t>, std::size_t>{{STypes::NAME}, STypes::NONE},
                            // Pair<Array<std::size_t>, std::size_t>{{STypes::PARENTHESIS}, STypes::OPEN},
                            // Pair<Array<std::size_t>, std::size_t>{{STypes::NAME | STypes::LITERAL},
                            // STypes::OPTIONAL}, Pair<Array<std::size_t>, std::size_t>{
                            //{STypes::COMMA, STypes::NAME | STypes::LITERAL},
                            // STypes::MULTIPLE | STypes::OPTIONAL}, // STypes::COMMA_TYPE_AND_NAME |
                            //// STypes::OPTIONAL | STypes::MULTIPLE,
                            // Pair<Array<std::size_t>, std::size_t>{{STypes::PARENTHESIS}, STypes::CLOSE},
                        },
                        Pair<std::size_t, std::size_t>(-1, 23)},
                    Pair<Array<Pair<Array<std::size_t>, std::size_t>>, Pair<std::size_t, std::size_t>>{
                        {// Casting statement
                         Pair<Array<std::size_t>, std::size_t>{{STypes::PARENTHESIS}, STypes::OPEN},
                         Pair<Array<std::size_t>, std::size_t>{
                             {STypes::TYPE_MODIFIER}, STypes::MULTIPLE | STypes::OPTIONAL},
                         Pair<Array<std::size_t>, std::size_t>{{STypes::TYPE}, STypes::NONE},
                         Pair<Array<std::size_t>, std::size_t>{{STypes::PARENTHESIS}, STypes::CLOSE},
                         Pair<Array<std::size_t>, std::size_t>{{STypes::NAME | STypes::LITERAL}, STypes::NONE}},
                        Pair<std::size_t, std::size_t>(-1, 22)},
                    Pair<Array<Pair<Array<std::size_t>, std::size_t>>, Pair<std::size_t, std::size_t>>{
                        {// Type-call statement
                         Pair<Array<std::size_t>, std::size_t>{
                             {STypes::TYPE_MODIFIER}, STypes::MULTIPLE | STypes::OPTIONAL},
                         Pair<Array<std::size_t>, std::size_t>{{STypes::TYPE}, STypes::NONE},
                         Pair<Array<std::size_t>, std::size_t>{{STypes::PARENTHESIS}, STypes::OPEN},
                         Pair<Array<std::size_t>, std::size_t>{{STypes::NAME | STypes::LITERAL}, STypes::OPTIONAL},
                         Pair<Array<std::size_t>, std::size_t>{{STypes::PARENTHESIS}, STypes::CLOSE}},
                        Pair<std::size_t, std::size_t>(-1, 21)},
                    Pair<Array<Pair<Array<std::size_t>, std::size_t>>, Pair<std::size_t, std::size_t>>{
                        {// Operator both
                         Pair<Array<std::size_t>, std::size_t>{{STypes::NAME | STypes::LITERAL}, STypes::NONE},
                         Pair<Array<std::size_t>, std::size_t>{{STypes::OPERATOR}, STypes::BOTH},
                         Pair<Array<std::size_t>, std::size_t>{{STypes::NAME | STypes::LITERAL}, STypes::NONE}},
                        Pair<std::size_t, std::size_t>(-1, 20)},
                    Pair<Array<Pair<Array<std::size_t>, std::size_t>>, Pair<std::size_t, std::size_t>>{
                        {// Operator prefix
                         Pair<Array<std::size_t>, std::size_t>{{STypes::OPERATOR}, STypes::PREFIX},
                         Pair<Array<std::size_t>, std::size_t>{{STypes::NAME | STypes::LITERAL}, STypes::NONE}},
                        Pair<std::size_t, std::size_t>(-1, 19)},
                    Pair<Array<Pair<Array<std::size_t>, std::size_t>>, Pair<std::size_t, std::size_t>>{
                        {// Operator postfix
                         Pair<Array<std::size_t>, std::size_t>{{STypes::NAME | STypes::LITERAL}, STypes::NONE},
                         Pair<Array<std::size_t>, std::size_t>{{STypes::OPERATOR}, STypes::PREFIX}},
                        Pair<std::size_t, std::size_t>(-1, 18)},
                    Pair<Array<Pair<Array<std::size_t>, std::size_t>>, Pair<std::size_t, std::size_t>>{
                        {// Reference/Pointer prefix
                         Pair<Array<std::size_t>, std::size_t>{{STypes::ASTERISK | STypes::AMPERSAND}, STypes::NONE},
                         Pair<Array<std::size_t>, std::size_t>{{STypes::NAME}, STypes::NONE}},
                        Pair<std::size_t, std::size_t>(-1, 17)},
                    Pair<Array<Pair<Array<std::size_t>, std::size_t>>, Pair<std::size_t, std::size_t>>{
                        {
                            // Initializer list
                            Pair<Array<std::size_t>, std::size_t>{{STypes::CURLY_BRACE}, STypes::OPEN},
                            Pair<Array<std::size_t>, std::size_t>{{STypes::LITERAL}, STypes::OPTIONAL},
                            // STypes::TYPE,
                            // STypes::ASTERISK_OR_AMPERSAND | STypes::MULTIPLE,
                            // STypes::NAME,
                            // STypes::LITERAL | STypes::NAME,
                            Pair<Array<std::size_t>, std::size_t>{
                                {STypes::COMMA, STypes::LITERAL}, STypes::MULTIPLE | STypes::OPTIONAL},
                            Pair<Array<std::size_t>, std::size_t>{{STypes::CURLY_BRACE}, STypes::CLOSE},
                        },
                        Pair<std::size_t, std::size_t>(STypes::LITERAL, 16)},

                    // TODO: Remove the ASTERISK and AMPERSANDs from the things, since they are now part of the first
                    // one.
                    // TODO: Also check the semicolons
                    Pair<Array<Pair<Array<std::size_t>, std::size_t>>, Pair<std::size_t, std::size_t>>{
                        {// Function Declaration
                         // Pair<Array<std::size_t>, std::size_t>{{STypes::TYPE_MODIFIER}, STypes::MULTIPLE |
                         // STypes::OPTIONAL},
                         Pair<Array<std::size_t>, std::size_t>{{STypes::TYPE}, STypes::NONE},
                         // Pair<Array<std::size_t>, std::size_t>{
                         //{STypes::ASTERISK | STypes::AMPERSAND}, STypes::MULTIPLE | STypes::OPTIONAL},
                         Pair<Array<std::size_t>, std::size_t>{{STypes::NAME}, STypes::NONE},
                         Pair<Array<std::size_t>, std::size_t>{{STypes::PARENTHESIS}, STypes::OPEN},
                         Pair<Array<std::size_t>, std::size_t>{{STypes::TYPE, STypes::NAME}, STypes::OPTIONAL},
                         Pair<Array<std::size_t>, std::size_t>{
                             {STypes::COMMA, STypes::TYPE, STypes::NAME}, STypes::MULTIPLE | STypes::OPTIONAL},
                         // STypes::COMMA_TYPE_AND_NAME |
                         // STypes::OPTIONAL | STypes::MULTIPLE,
                         Pair<Array<std::size_t>, std::size_t>{{STypes::PARENTHESIS}, STypes::CLOSE},
                         Pair<Array<std::size_t>, std::size_t>{{STypes::SEMICOLON}, STypes::NONE}},
                        Pair<std::size_t, std::size_t>(STypes::NONE, 7)},
                    // TODO: Continue making them pairs from here on.
                    Pair<Array<Pair<Array<std::size_t>, std::size_t>>, Pair<std::size_t, std::size_t>>{
                        {// Function Definition
                         // Pair<Array<std::size_t>, std::size_t>{{STypes::TYPE_MODIFIER}, STypes::MULTIPLE |
                         // STypes::OPTIONAL},
                         Pair<Array<std::size_t>, std::size_t>{{STypes::TYPE}, STypes::NONE},
                         // Pair<Array<std::size_t>, std::size_t>{{STypes::ASTERISK | STypes::AMPERSAND},
                         // STypes::MULTIPLE},
                         Pair<Array<std::size_t>, std::size_t>{{STypes::NAME}, STypes::NONE},
                         Pair<Array<std::size_t>, std::size_t>{{STypes::PARENTHESIS}, STypes::OPEN},
                         Pair<Array<std::size_t>, std::size_t>{{STypes::TYPE, STypes::NAME}, STypes::OPTIONAL},
                         Pair<Array<std::size_t>, std::size_t>{
                             {STypes::COMMA, STypes::TYPE, STypes::NAME}, STypes::MULTIPLE | STypes::OPTIONAL},
                         // STypes::COMMA_TYPE_AND_NAME |                                                       //
                         // STypes::OPTIONAL | STypes::MULTIPLE,
                         Pair<Array<std::size_t>, std::size_t>{{STypes::PARENTHESIS}, STypes::CLOSE},
                         Pair<Array<std::size_t>, std::size_t>{{STypes::CURLY_BRACE}, STypes::OPEN},
                         Pair<Array<std::size_t>, std::size_t>{
                             {STypes::STATEMENT}, STypes::OPTIONAL | STypes::MULTIPLE},
                         Pair<Array<std::size_t>, std::size_t>{{STypes::CURLY_BRACE}, STypes::CLOSE}},
                        Pair<std::size_t, std::size_t>(STypes::NONE, 6)},
                    Pair<Array<Pair<Array<std::size_t>, std::size_t>>, Pair<std::size_t, std::size_t>>{
                        {// Parentheses
                         //  STypes::NAME | STypes::LITERAL, STypes::OPERATOR | STypes::PREFIX
                         Pair<Array<std::size_t>, std::size_t>{{STypes::PARENTHESIS}, STypes::OPEN},
                         Pair<Array<std::size_t>, std::size_t>{{STypes::LITERAL | STypes::NAME}, STypes::NONE},
                         Pair<Array<std::size_t>, std::size_t>{{STypes::PARENTHESIS}, STypes::CLOSE}},
                        Pair<std::size_t, std::size_t>(-1, 5)},
                    Pair<Array<Pair<Array<std::size_t>, std::size_t>>, Pair<std::size_t, std::size_t>>{
                        {// Variable Declaration array
                         // Pair<Array<std::size_t>, std::size_t>{{STypes::TYPE_MODIFIER}, STypes::MULTIPLE |
                         // STypes::OPTIONAL},
                         Pair<Array<std::size_t>, std::size_t>{{STypes::TYPE}, STypes::NONE},
                         // Pair<Array<std::size_t>, std::size_t>{{STypes::ASTERISK_OR_AMPERSAND}, STypes::MULTIPLE},
                         Pair<Array<std::size_t>, std::size_t>{{STypes::NAME}, STypes::NONE},
                         Pair<Array<std::size_t>, std::size_t>{{STypes::BRACE}, STypes::OPEN},
                         Pair<Array<std::size_t>, std::size_t>{{STypes::LITERAL | STypes::NAME}, STypes::NONE},
                         Pair<Array<std::size_t>, std::size_t>{{STypes::BRACE}, STypes::CLOSE},
                         Pair<Array<std::size_t>, std::size_t>{{STypes::SEMICOLON}, STypes::NONE}},
                        Pair<std::size_t, std::size_t>(STypes::NONE, 4)},
                    Pair<Array<Pair<Array<std::size_t>, std::size_t>>, Pair<std::size_t, std::size_t>>{
                        {// Variable Declaration array with initialization
                         // Pair<Array<std::size_t>, std::size_t>{{STypes::TYPE_MODIFIER}, STypes::MULTIPLE |
                         // STypes::OPTIONAL},
                         Pair<Array<std::size_t>, std::size_t>{{STypes::TYPE}, STypes::NONE},
                         // Pair<Array<std::size_t>, std::size_t>{
                         //{STypes::ASTERISK | STypes::AMPERSAND}, STypes::OPTIONAL | STypes::MULTIPLE},
                         Pair<Array<std::size_t>, std::size_t>{{STypes::NAME}, STypes::NONE},
                         Pair<Array<std::size_t>, std::size_t>{{STypes::BRACE}, STypes::OPEN},
                         Pair<Array<std::size_t>, std::size_t>{{STypes::LITERAL | STypes::NAME}, STypes::NONE},
                         Pair<Array<std::size_t>, std::size_t>{{STypes::BRACE}, STypes::CLOSE},
                         Pair<Array<std::size_t>, std::size_t>{{STypes::ASSIGMENT}, STypes::NONE},
                         Pair<Array<std::size_t>, std::size_t>{{STypes::LITERAL | STypes::NAME}, STypes::NONE},
                         Pair<Array<std::size_t>, std::size_t>{{STypes::SEMICOLON}, STypes::NONE}},
                        Pair<std::size_t, std::size_t>(STypes::NONE, 3)},
                    Pair<Array<Pair<Array<std::size_t>, std::size_t>>, Pair<std::size_t, std::size_t>>{
                        {// Variable Declaration
                         //  STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL,
                         Pair<Array<std::size_t>, std::size_t>{{STypes::TYPE}, STypes::NONE},
                         // STypes::ASTERISK_OR_AMPERSAND | STypes::MULTIPLE,
                         Pair<Array<std::size_t>, std::size_t>{{STypes::NAME}, STypes::NONE},
                         Pair<Array<std::size_t>, std::size_t>{{STypes::COMMA, STypes::NAME}, STypes::NONE},
                         Pair<Array<std::size_t>, std::size_t>{{STypes::SEMICOLON}, STypes::NONE}},
                        Pair<std::size_t, std::size_t>(STypes::NONE, 2)},
                    Pair<Array<Pair<Array<std::size_t>, std::size_t>>, Pair<std::size_t, std::size_t>>{
                        {// Variable Declaration with initialization
                         // STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL,
                         Pair<Array<std::size_t>, std::size_t>{{STypes::TYPE}, STypes::NONE},
                         // STypes::ASTERISK_OR_AMPERSAND | STypes::MULTIPLE,
                         Pair<Array<std::size_t>, std::size_t>{{STypes::NAME}, STypes::NONE},
                         Pair<Array<std::size_t>, std::size_t>{{STypes::ASSIGMENT}, STypes::NONE},
                         Pair<Array<std::size_t>, std::size_t>{{STypes::LITERAL | STypes::NAME}, STypes::NONE},
                         Pair<Array<std::size_t>, std::size_t>{{STypes::SEMICOLON}, STypes::NONE}},
                        Pair<std::size_t, std::size_t>(STypes::NONE, 1)},
                    Pair<Array<Pair<Array<std::size_t>, std::size_t>>, Pair<std::size_t, std::size_t>>{
                        {// Blank statement
                         Pair<Array<std::size_t>, std::size_t>{{STypes::NAME | STypes::LITERAL}, STypes::NONE},
                         Pair<Array<std::size_t>, std::size_t>{{STypes::SEMICOLON}, STypes::NONE}},
                        Pair<std::size_t, std::size_t>(STypes::NONE, 0)}
                    // Pair<Array<Pair<Array<std::size_t>, std::size_t>>, Pair<std::size_t, std::size_t>> {
                    //     { // Operator postfix
                    //         STypes::NAME | STypes::LITERAL,
                    //         STypes::OPERATOR | STypes::PREFIX } }
                };

            Array<Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>> statement_types{
                Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>{
                    {// Type name
                     STypes::STRUCT | STypes::ENUM | STypes::UNION, STypes::NAME},
                    Pair<std::size_t, std::size_t>(STypes::TYPE, 25)},
                Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>{
                    {
                        // Function Call
                        STypes::NAME,
                        STypes::PARENTHESIS | STypes::OPEN,
                        STypes::NAME | STypes::LITERAL | STypes::OPTIONAL,
                        STypes::COMMA | STypes::NAME | STypes::LITERAL | STypes::MULTIPLE |
                            STypes::OPTIONAL, // STypes::COMMA_TYPE_AND_NAME |
                                              // STypes::OPTIONAL | STypes::MULTIPLE,
                        STypes::PARENTHESIS | STypes::CLOSE,
                    },
                    Pair<std::size_t, std::size_t>(-1, 24)},
                Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>{
                    {// Parentheses
                     //  STypes::NAME | STypes::LITERAL, STypes::OPERATOR | STypes::PREFIX
                     STypes::PARENTHESIS | STypes::OPEN, STypes::LITERAL | STypes::NAME,
                     STypes::PARENTHESIS | STypes::CLOSE},
                    Pair<std::size_t, std::size_t>(-1, 23)},
                Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>{
                    {// Casting statement
                     STypes::PARENTHESIS | STypes::OPEN, STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL,
                     STypes::TYPE, STypes::PARENTHESIS | STypes::CLOSE, STypes::NAME | STypes::LITERAL},
                    Pair<std::size_t, std::size_t>(-1, 22)},
                Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>{
                    {// Type-call statement
                     STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL, STypes::TYPE,
                     STypes::PARENTHESIS | STypes::OPEN, STypes::NAME | STypes::LITERAL | STypes::OPTIONAL,
                     STypes::PARENTHESIS | STypes::CLOSE},
                    Pair<std::size_t, std::size_t>(-1, 21)},
                Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>{
                    {// Operator both
                     STypes::NAME | STypes::LITERAL, STypes::OPERATOR | STypes::BOTH, STypes::NAME | STypes::LITERAL},
                    Pair<std::size_t, std::size_t>(-1, 20)},
                Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>{
                    {// Operator prefix
                     STypes::OPERATOR | STypes::PREFIX, STypes::NAME | STypes::LITERAL},
                    Pair<std::size_t, std::size_t>(-1, 19)},
                Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>{
                    {// Operator postfix
                     STypes::NAME | STypes::LITERAL, STypes::OPERATOR | STypes::PREFIX},
                    Pair<std::size_t, std::size_t>(-1, 18)},
                Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>{
                    {
                        // Initializer list
                        STypes::CURLY_BRACE | STypes::OPEN,
                        STypes::LITERAL | STypes::MULTIPLE | STypes::OPTIONAL,
                        // STypes::TYPE,
                        // STypes::ASTERISK_OR_AMPERSAND | STypes::MULTIPLE,
                        // STypes::NAME,
                        // STypes::LITERAL | STypes::NAME,
                        STypes::COMMA | STypes::LITERAL | STypes::MULTIPLE | STypes::OPTIONAL,
                        STypes::CURLY_BRACE | STypes::CLOSE,
                    },
                    Pair<std::size_t, std::size_t>(STypes::LITERAL, 16)},
                Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>{
                    {// Function Declaration
                     STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL, STypes::TYPE,
                     STypes::ASTERISK_OR_AMPERSAND | STypes::MULTIPLE, STypes::NAME, STypes::PARENTHESIS | STypes::OPEN,
                     STypes::TYPE | STypes::NAME | STypes::OPTIONAL,
                     STypes::COMMA | STypes::TYPE | STypes::NAME | STypes::MULTIPLE |
                         STypes::OPTIONAL, // STypes::COMMA_TYPE_AND_NAME |
                                           // STypes::OPTIONAL | STypes::MULTIPLE,
                     STypes::PARENTHESIS | STypes::CLOSE, STypes::SEMICOLON},
                    Pair<std::size_t, std::size_t>(STypes::NONE, 7)},
                Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>{
                    {// Function Definition
                     STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL, STypes::TYPE,
                     STypes::ASTERISK_OR_AMPERSAND | STypes::MULTIPLE, STypes::NAME, STypes::PARENTHESIS | STypes::OPEN,
                     STypes::TYPE | STypes::NAME | STypes::OPTIONAL,
                     STypes::COMMA | STypes::TYPE | STypes::NAME | STypes::MULTIPLE |
                         STypes::OPTIONAL, // STypes::COMMA_TYPE_AND_NAME |
                                           // STypes::OPTIONAL | STypes::MULTIPLE,
                     STypes::PARENTHESIS | STypes::CLOSE, STypes::CURLY_BRACE | STypes::OPEN,
                     STypes::STATEMENT | STypes::OPTIONAL | STypes::MULTIPLE, STypes::CURLY_BRACE | STypes::CLOSE},
                    Pair<std::size_t, std::size_t>(STypes::NONE, 6)},
                Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>{
                    {// Variable Declaration array
                     STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL, STypes::TYPE,
                     STypes::ASTERISK_OR_AMPERSAND | STypes::MULTIPLE, STypes::NAME, STypes::BRACE | STypes::OPEN,
                     STypes::LITERAL | STypes::NAME, STypes::BRACE | STypes::CLOSE, STypes::SEMICOLON},
                    Pair<std::size_t, std::size_t>(STypes::NONE, 4)},
                Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>{
                    {// Variable Declaration array with initialization
                     STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL, STypes::TYPE,
                     STypes::ASTERISK_OR_AMPERSAND | STypes::MULTIPLE, STypes::NAME, STypes::BRACE | STypes::OPEN,
                     STypes::LITERAL | STypes::NAME, STypes::BRACE | STypes::CLOSE, STypes::ASSIGMENT,
                     STypes::LITERAL | STypes::NAME, STypes::SEMICOLON},
                    Pair<std::size_t, std::size_t>(STypes::NONE, 3)},
                Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>{
                    {// Variable Declaration
                     STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL, STypes::TYPE,
                     STypes::ASTERISK_OR_AMPERSAND | STypes::MULTIPLE, STypes::NAME, STypes::SEMICOLON},
                    Pair<std::size_t, std::size_t>(STypes::NONE, 2)},
                Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>{
                    {// Variable Declaration with initialization
                     STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL, STypes::TYPE,
                     STypes::ASTERISK_OR_AMPERSAND | STypes::MULTIPLE, STypes::NAME, STypes::ASSIGMENT,
                     STypes::LITERAL | STypes::NAME, STypes::SEMICOLON},
                    Pair<std::size_t, std::size_t>(STypes::NONE, 1)},
                Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>>{
                    {// Blank statement
                     STypes::NAME | STypes::LITERAL, STypes::SEMICOLON},
                    Pair<std::size_t, std::size_t>(STypes::NONE, 0)},
                // Pair<Array<std::size_t>, Pair<std::size_t, std::size_t>> {
                //     { // Operator postfix
                //         STypes::NAME | STypes::LITERAL,
                //         STypes::OPERATOR | STypes::PREFIX } }
            };


            // TODO: qsort this from greatest precedence (greatest number) to least

            // TODO: types can also be called as functions.

            Array<Pair<String, std::size_t>> type_modifier_order{
                Pair<String, std::size_t>("auto", 0),     Pair<String, std::size_t>("static", 0),
                Pair<String, std::size_t>("extern", 0),   Pair<String, std::size_t>("register", 0),
                Pair<String, std::size_t>("const", 1),    Pair<String, std::size_t>("long", -1),
                Pair<String, std::size_t>("short", -2),   Pair<String, std::size_t>("signed", 3),
                Pair<String, std::size_t>("unsigned", 3),
            };

            Array<Pair<Pair<std::size_t, std::size_t>, JunctionMode>> location_specifics{
                Pair<Pair<std::size_t, std::size_t>, JunctionMode>(
                    Pair<std::size_t, std::size_t>(STypes::ELSE, STypes::IF), JunctionMode::AFTER),
                Pair<Pair<std::size_t, std::size_t>, JunctionMode>(
                    Pair<std::size_t, std::size_t>(STypes::CASE, STypes::SWITCH), JunctionMode::IN),
                Pair<Pair<std::size_t, std::size_t>, JunctionMode>(
                    Pair<std::size_t, std::size_t>(STypes::BREAK, STypes::SWITCH), JunctionMode::IN),
            };

            Map<String, std::size_t> key_expressions{std::initializer_list<Pair<String, std::size_t>>{
                Pair<String, std::size_t>{"auto", STypes::TYPE_MODIFIER},
                Pair<String, std::size_t>{"break", STypes::BREAK},
                Pair<String, std::size_t>{"case", STypes::CASE},
                Pair<String, std::size_t>{"char", STypes::TYPE},
                Pair<String, std::size_t>{"const", STypes::TYPE_MODIFIER},
                Pair<String, std::size_t>{"continue", STypes::WHOLE_STATEMENT},
                Pair<String, std::size_t>{"default", STypes::LABEL},
                Pair<String, std::size_t>{"do", STypes::DO},
                Pair<String, std::size_t>{"double", STypes::TYPE},
                Pair<String, std::size_t>{"else", STypes::ELSE},
                Pair<String, std::size_t>{"enum", STypes::ENUM},
                Pair<String, std::size_t>{"extern", STypes::TYPE_MODIFIER},
                Pair<String, std::size_t>{"float", STypes::TYPE},
                Pair<String, std::size_t>{"for", STypes::FOR},
                Pair<String, std::size_t>{"goto", STypes::GOTO},
                Pair<String, std::size_t>{"if", STypes::ELSE},
                Pair<String, std::size_t>{"int", STypes::TYPE},
                Pair<String, std::size_t>{"long", STypes::TYPE_MODIFIER | STypes::TYPE},
                Pair<String, std::size_t>{"register", STypes::TYPE_MODIFIER},
                Pair<String, std::size_t>{"return", STypes::RETURN},
                Pair<String, std::size_t>{"short", STypes::TYPE_MODIFIER | STypes::TYPE},
                Pair<String, std::size_t>{"signed", STypes::TYPE_MODIFIER},
                Pair<String, std::size_t>{"sizeof", STypes::SIZEOF},
                Pair<String, std::size_t>{"static", STypes::TYPE_MODIFIER},
                Pair<String, std::size_t>{"struct", STypes::STRUCT},
                Pair<String, std::size_t>{"switch", STypes::SWITCH},
                Pair<String, std::size_t>{"typedef", STypes::TYPEDEF},
                Pair<String, std::size_t>{"union", STypes::UNION},
                Pair<String, std::size_t>{"unsigned", STypes::TYPE_MODIFIER},
                Pair<String, std::size_t>{"void", STypes::VOID_TYPE},
                Pair<String, std::size_t>{"volatile", STypes::TYPE_MODIFIER},
                Pair<String, std::size_t>{"while", STypes::WHILE},
                Pair<String, std::size_t>{"#define", STypes::PREPROCESSOR_DEFINE},
                Pair<String, std::size_t>{"#elif", STypes::PREPROCESSOR_ELIF},
                Pair<String, std::size_t>{"#else", STypes::PREPROCESSOR_ELSE},
                Pair<String, std::size_t>{"#endif", STypes::PREPROCESSOR_ENDIF},
                Pair<String, std::size_t>{"#error", STypes::PREPROCESSOR_ERROR},
                Pair<String, std::size_t>{"#if", STypes::PREPROCESSOR_IF},
                Pair<String, std::size_t>{"#ifdef", STypes::PREPROCESSOR_IFDEF},
                Pair<String, std::size_t>{"#ifndef", STypes::PREPROCESSOR_IFNDEF},
                Pair<String, std::size_t>{"#include", STypes::PREPROCESSOR_INCLUDE},
                Pair<String, std::size_t>{"#pragma", STypes::PREPROCESSOR_PRAGMA},
                Pair<String, std::size_t>{"#undef", STypes::PREPROCESSOR_UNDEF},
                Pair<String, std::size_t>{"=", STypes::OPERATOR | STypes::BOTH},
                Pair<String, std::size_t>{"+", STypes::OPERATOR | STypes::BOTH},
                Pair<String, std::size_t>{"-", STypes::OPERATOR | STypes::BOTH | STypes::PREFIX},
                Pair<String, std::size_t>{"*", STypes::OPERATOR | STypes::BOTH | STypes::ASTERISK},
                Pair<String, std::size_t>{"/", STypes::OPERATOR | STypes::BOTH},
                Pair<String, std::size_t>{"%", STypes::OPERATOR | STypes::BOTH},
                Pair<String, std::size_t>{"+=", STypes::OPERATOR | STypes::BOTH | STypes::REQUIRE_LVALUE},
                Pair<String, std::size_t>{"-=", STypes::OPERATOR | STypes::BOTH | STypes::REQUIRE_LVALUE},
                Pair<String, std::size_t>{"*=", STypes::OPERATOR | STypes::BOTH | STypes::REQUIRE_LVALUE},
                Pair<String, std::size_t>{"/=", STypes::OPERATOR | STypes::BOTH | STypes::REQUIRE_LVALUE},
                Pair<String, std::size_t>{"%=", STypes::OPERATOR | STypes::BOTH | STypes::REQUIRE_LVALUE},
                Pair<String, std::size_t>{">>=", STypes::OPERATOR | STypes::BOTH | STypes::REQUIRE_LVALUE},
                Pair<String, std::size_t>{"<<=", STypes::OPERATOR | STypes::BOTH | STypes::REQUIRE_LVALUE},
                Pair<String, std::size_t>{"&=", STypes::OPERATOR | STypes::BOTH | STypes::REQUIRE_LVALUE},
                Pair<String, std::size_t>{"^=", STypes::OPERATOR | STypes::BOTH | STypes::REQUIRE_LVALUE},
                Pair<String, std::size_t>{"|=", STypes::OPERATOR | STypes::BOTH | STypes::REQUIRE_LVALUE},
                Pair<String, std::size_t>{"++", STypes::OPERATOR | STypes::PREFIX | STypes::POSTFIX},
                Pair<String, std::size_t>{"--", STypes::OPERATOR | STypes::PREFIX | STypes::POSTFIX},
                Pair<String, std::size_t>{"==", STypes::OPERATOR | STypes::BOTH},
                Pair<String, std::size_t>{"!=", STypes::OPERATOR | STypes::BOTH},
                Pair<String, std::size_t>{">", STypes::OPERATOR | STypes::BOTH},
                Pair<String, std::size_t>{"<", STypes::OPERATOR | STypes::BOTH},
                Pair<String, std::size_t>{">=", STypes::OPERATOR | STypes::BOTH | STypes::REQUIRE_LVALUE},
                Pair<String, std::size_t>{"<=", STypes::OPERATOR | STypes::BOTH | STypes::REQUIRE_LVALUE},
                Pair<String, std::size_t>{"!", STypes::OPERATOR | STypes::PREFIX},
                Pair<String, std::size_t>{"&&", STypes::OPERATOR | STypes::BOTH},
                Pair<String, std::size_t>{"||", STypes::OPERATOR | STypes::BOTH},
                Pair<String, std::size_t>{"?", STypes::OPERATOR | STypes::QUESTION},
                Pair<String, std::size_t>{":", STypes::OPERATOR | STypes::QELSE},
                Pair<String, std::size_t>{",", STypes::OPERATOR | STypes::COMMA},
                Pair<String, std::size_t>{"&", STypes::OPERATOR | STypes::BOTH | STypes::AMPERSAND},
                Pair<String, std::size_t>{"|", STypes::OPERATOR | STypes::BOTH},
                Pair<String, std::size_t>{"^", STypes::OPERATOR | STypes::BOTH},
                Pair<String, std::size_t>{"~", STypes::OPERATOR | STypes::PREFIX},
                Pair<String, std::size_t>{"<<", STypes::OPERATOR | STypes::BOTH},
                Pair<String, std::size_t>{">>", STypes::OPERATOR | STypes::BOTH},
                Pair<String, std::size_t>{".", STypes::OPERATOR | STypes::DOT},
                Pair<String, std::size_t>{"->", STypes::OPERATOR | STypes::ARROW},
                Pair<String, std::size_t>{"{", STypes::CURLY_BRACE | STypes::OPEN},
                Pair<String, std::size_t>{"}", STypes::CURLY_BRACE | STypes::CLOSE},
                Pair<String, std::size_t>{"[", STypes::BRACE | STypes::OPEN},
                Pair<String, std::size_t>{"]", STypes::BRACE | STypes::CLOSE},
                Pair<String, std::size_t>{"(", STypes::PARENTHESIS | STypes::OPEN},
                Pair<String, std::size_t>{")", STypes::PARENTHESIS | STypes::CLOSE},
                Pair<String, std::size_t>{"'", STypes::SINGLE_QUOTE},
                Pair<String, std::size_t>{"\"", STypes::DOUBLE_QUOTE},
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
            }};

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

            // TODO: do the todo on 413, and for this, check directly for each one in precedence, and change the array a
            // to become the result of the change. Maybe recursive on things like functions, since they need expressions
            // in the block.

            //

            // bool compatible(Array<std::size_t>& a, Array<) {
            //     if()
            //     ;
            // }

#define checkBit(a, b) (a & (1ULL << b))
#define setBit(a, b) (a |= (1ULL << b))
#define resetBit(a, b) (a &= ~(1ULL << b))
#define set(a) (a |= std::numeric_limits<std::size_t>::max())
#define reset(a) (a &= 0ULL)


#define checkIs(a, b) (a & b)

            /**
             * @brief
             * this func checks if the group of STypes combinations can fit into the combination in b;
             * eg.) a = FuncName, ParenOpen, STypes::Literal, STypes::Comma, STypes::Literal, ParenClose, ; b =
             * STypes::Literal | STypes::Comma, STypes::MULTIPLE, STypes::OPTIONAL
             */
            // TOOD: if mode is 1, then also add the things parsed into the
            // @brief:
            //  the return of matchExact:
            //      0: not matched
            //     -1: matched so far but not complete
            //      1: matched and completed

            short int matchExact(
                const Array<std::size_t> &a, /*  std::size_t foptions, */ std::size_t index1, std::size_t index2
                /*,bool mode /*0 is test mode, 1 is accept mode*/) {
#define sta(param) statement_types_arrays[index1].first[index2].first[param]
#define sts statement_types_arrays[index1].first[index2].first.size()
#define foptions statement_types_arrays[index1].first[index2].second
                for (std::size_t i{0}; i < sts; ++i) {
                    if (sta(i) & a[i]) {
                        if ((a[i] & STypes::OPERATOR) || (a[i] & STypes::OPEN) || (a[i] & STypes::CLOSE)) {
                            if ((foptions & a[i])) {
                                // if (mode)
                                continue;
                            }
                            return 0;
                        }
                        continue;
                    }
                    return 0;
                }
                // TODO: make it return 1 when the thing is not complete but accepted so far, but if it completes the
                // whole thing in index2, return 2 instead
                return 1;
#undef foptions
#undef sts
#undef sta
            }


            // the variable a is the whole statement, and the index is which of the statement_types_arrays to try to
            // match.
            bool checkArr(const Array<std::size_t> &a, std::size_t index) {
#define arr statement_types_arrays[index].first
                // auto& arr{statement_types_arrays[index]};
                short int          tmp{0};
                Array<std::size_t> tmp_arr{};
                std::size_t        offset{0};
                int                j_was = 0;
                // TODO: The j might not be direct loops of the i, maybe make it so tha tj retains its value after each
                // loop for (int i{0}; i < arr.size(); ++i, offset = 0) {
                //     for (int j{j_was}; j < arr[i].first.size(); ++j) {
                for (int j{j_was}, i{0}; ((j < arr[i].first.size()) && (i < arr.size())); ++j, ++i, offset = 0) {
                    tmp_arr.push_back(a[j]);
                    tmp = matchExact(tmp_arr, index, i);
                    if (tmp > 0) {
                        tmp_arr.clear();
                        continue;
                    }
                    if (tmp) {
                        --i;
                        continue;
                    }
                    for (int k{i}; (k < arr.size()) && (arr[k].second & STypes::OPTIONAL); ++k) {
                        if (matchExact(tmp_arr, index, k)) {
                            i = k - 1;
                            j -= tmp_arr.size();
                            tmp_arr.clear();
                            // break;
                            goto next_loop;
                        }
                        // else if (!matchExact(tmp_arr, index, k)) {
                        //
                        // }
                    }
                    if (arr[i - 1].second & STypes::MULTIPLE) {
                        if (matchExact(tmp_arr, index, --i)) { goto next_loop; }
                    }
                    return false;

#if 0
                // if(arr.first[i].first[j] == )

                // The match Exact should return a value depending on whether the whole thing is completed or just still valid so far.
                while (matchExact(a[j], index, i) == 1) { ++j; }
                //TODO: figure out how to weave in the below to the above while making j increasing, but also checking for the OPTIONAL and MULTIPLE flags. 
                //if (matchExact(a[j], index, i)) { continue; }
                for (int k{j}; k < arr[i].first.size(); ++k) {
                    if (arr[k].second & STypes::OPTIONAL)
                        if(matchExact(a[k], index, i)) {
                            
                        }


                        --offset;

                    // TODO: continue this:
                }
#endif
                next_loop:;
                }
                return true;
                // failure:;

                // if (b & STypes::OPERATOR) {
                // if (b & STypes::BOTH) {

                //}
                //}
                //}
#undef arr
            }
            // the variable a is the whole statement, and the index is which of the statement_types_arrays to try to
            // match.
            short int parseArray(const Array<std::size_t> &a, std::size_t index) {
#define arr statement_types_arrays[index].first
                short int          tmp{0};
                Array<std::size_t> tmp_arr{};
                std::size_t        offset{0};
                // int                j_was = 0;
                // TODO: The j might not be direct loops of the i, maybe make it so tha tj retains its value after each
                // loop
                for (int j{0}, i{0}; ((j < arr[i].first.size()) && (i < arr.size())); ++j, ++i, offset = 0) {
                    tmp_arr.push_back(a[j]);
                    tmp = matchExact(tmp_arr, index, i);
                    if (tmp > 0) {
                        tmp_arr.clear();
                        continue;
                    }
                    if (tmp) {
                        --i;
                        continue;
                    }
                    for (int k{i}; (k < arr.size()) && (arr[k].second & STypes::OPTIONAL); ++k) {
                        if (matchExact(tmp_arr, index, k)) {
                            i = k - 1;
                            j -= tmp_arr.size();
                            tmp_arr.clear();
                            // break;
                            goto next_loop;
                        }
                    }
                    if (arr[i - 1].second & STypes::MULTIPLE) {
                        if (matchExact(tmp_arr, index, --i)) { goto next_loop; }
                    }
                    return -1;
                next_loop:;
                }
                return j;
#undef arr
            }


            /**
             * @brief
             * the parameter a is the list of the things in the parsed statement.
             */

            bool check(Array<std::size_t> & a) {

                // Array<String> things{};
                // // std::bitset<17> bitset;
                // std::size_t bits{0ULL};
                // // bitset = std::num;
                // // bitset.set();
                // // bitset = 0ULL;
                // for (int i{0}; i < statement_types_arrays.size(); ++i) {
                //     for (int j{0}; j < statement_types_arrays[i].first.size(); ++j) {
                //         // if (!(bits & (1ULL << j))) {
                //         if (!checkBit(bits, j)) {
                // 	for (int k{0}; k < a.size(); ++k) {
                // 		if(statement_types_arrays.)
                // 			for(int l{0}; l < (a.size() - k) - 1; ++l) {
                // 			}
                // 	}

                //             // if ((a[j] & statement_types_arrays[i].first[j]) && bitset[j]) {
                //             if (a[j] & statement_types_arrays[i].first[j]) {
                //                 // things.push_back()
                //             }
                //         }
                //         else {
                //             bits |= (1 << j);
                //         }

                //         // else if (statement_types_arrays[i].first[j] & STypes::MULTIPLE) {
                //         // }
                //         // else if (statement_types_arrays[i].first[j] & STypes::OPTIONAL) {
                //         // }
                //         // statement_types_arrays[i].first[j]
                //     }
                // }
                /* for (int i{0}; i < statement_types_arrays.size(); ++i) {
                    for (int j{0}; j < a.size(); ++j) {
                        for (int k{j}; k < (a.size() - j); ++k) {
                            if (a[k] != statement_types_arrays[i].first[k]) break;
                            if ((k + 1) == statement_types_arrays[i].first.size()) {
                                a.replace(statement_types_arrays[i].second.first, j, k + 1);
                                break;
                            }
                        }
                    }
                }
                return; */


                /* for (int i{0}; i < statement_types_arrays.size(); ++i) {
                    for (int j{0}; j < a.size(); ++j) {
                        for (int k{j}; k < (a.size() - j); ++k) {
                            if (a[k] != statement_types_arrays[i].first[k]) break;
                            if ((k + 1) == statement_types_arrays[i].first.size()) {
                                a.replace(statement_types_arrays[i].second.first, j, k + 1);
                                break;
                            }
                        }
                    }
                }
                return; */

                Array<std::size_t> tmp_arr{};

                for (bool changed{true}; changed; changed = false) {

                    for (int i{0}, increment{0}; i < statement_types_arrays.size(); i += increment) {
                        // tmp_arr.clear();
                        tmp_arr = a;
                        for (int j{0}; j < a.size(); ++j, tmp_arr.pop_front(increment)) {
                            // tmp_arr.push_back(a[i]);
                            increment = parseArray(tmp_arr, i);
                            if (increment < 0) {
                                increment = 1;
                                continue;
                            }
                            a.replace(statement_types_arrays[i].second.first, i, i + increment);

                            *this.

                            // tmp_arr.pop_front(increment);

                            // for (int j{0}; j <)
                        }
                    }
                }
            }

            Expression generate(Array<std::size_t> a) {
                for (int i{0}; i < statement_types_arrays.size(); ++i) {
                    for (int j{0}; j < statement_types_arrays[i].first.size(); ++j) {
                        if (a[j] & statement_types_arrays[i].first[j]) {}
                        else if (statement_types_arrays[i].first[j] & STypes::MULTIPLE) {
                        }
                        else if (statement_types_arrays[i].first[j] & STypes::OPTIONAL) {
                        }
                        // statement_types_arrays[i].first[j]
                    }
                }
            }
            // TODO: use the regex library instead of manual parsing.
            Classifier &parse(FILE * file) {
                String            container{};
                int               c;
                std::stringstream ss{};
                ss << container;
                std::vector<Statement> statements;
                // Note: stm -> statement
                Array<Statement> stm(0);
                // Note: combined STypes
                Array<std::size_t> exp(0);
                // Note: ws -> was special, wsp -> was special prior
                bool        ws{false}, wsp{false};
                short int   mode{0};
                bool        end_of_term;
                std::size_t find_result{0UL};
                for (; (c = fgetc(file)) != EOF; wsp = ws) {
                    ws = !((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
                    container.push_back(c);
                    if (!(ws || wsp)) {}
                    else {
                        if ((find_result = key_expressions.find(container)) != key_expressions.size()) {
                            exp.push_back(key_expressions(find_result).second);
                        }
                        // TODO: Check this with the statements map above (defining all c statements)
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
