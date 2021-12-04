//#include <bits/stdc++.h>
#include "stdc++.h"

#include "array_view.h"
#include "dynamic_bitset.h"
#include "misc.h"
#include "utils.h"


typedef long long int size_ut;

class Exception : public std::exception {
    std::string message;

public:
    Exception(const char *m = "") : message{m} {}

    virtual const char *what() const noexcept override { return message.c_str(); }
};

class Classifier {
    std::vector<std::string> types;
    class Word {
    public:
        String  name;
        size_ut line_number;
        Word(String &&str, size_ut line) : name(str), line_number(line) {}
    };
    enum STypes {
        NONE                  = (0LL),
        OPERATOR              = (1LL << 0),
        NAME                  = (1LL << 1),
        TYPE                  = (1LL << 2),
        VOID_TYPE             = (1LL << 3),
        TYPE_MODIFIER         = (1LL << 4),
        LABEL                 = (1LL << 5),
        STATEMENT             = (1LL << 6),
        PARENTHESIS           = (1LL << 7),
        CURLY_BRACE           = (1LL << 8),
        BRACE                 = (1LL << 9),
        SINGLE_QUOTE          = (1LL << 10),
        DOUBLE_QUOTE          = (1LL << 11),
        MULTIPLE              = (1LL << 12),
        OPTIONAL              = (1LL << 13),
        ASTERISK              = (1LL << 14),
        AMPERSAND             = (1LL << 15),
        ASTERISK_OR_AMPERSAND = (1LL << 15),
        ASSIGNMENT            = (1LL << 16),
        COMMA                 = (1LL << 17),
        STRUCT                = (1LL << 18),
        ENUM                  = (1LL << 19),
        UNION                 = (1LL << 20),
        CASE                  = (1LL << 21),
        WHOLE_STATEMENT       = (1LL << 22),
        DO                    = (1LL << 23),
        WHILE                 = (1LL << 24),
        FOR                   = (1LL << 25),
        GOTO                  = (1LL << 26),
        IF                    = (1LL << 27),
        ELSE                  = (1LL << 28),
        SIZEOF                = (1LL << 29),
        RETURN                = (1LL << 30),
        SWITCH                = (1LL << 31),
        BREAK                 = (1LL << 32),
        TYPEDEF               = (1LL << 33),
        QUESTION              = (1LL << 34),
        QELSE                 = (1LL << 35),
        DOT                   = (1LL << 36),
        ARROW                 = (1LL << 37),
        COLON                 = (1LL << 38),
        PREPROCESSOR_DEFINE   = (1LL << 39),
        PREPROCESSOR_ELIF     = (1LL << 40),
        PREPROCESSOR_ELSE     = (1LL << 41),
        PREPROCESSOR_ENDIF    = (1LL << 42),
        PREPROCESSOR_ERROR    = (1LL << 43),
        PREPROCESSOR_IF       = (1LL << 44),
        PREPROCESSOR_IFDEF    = (1LL << 45),
        PREPROCESSOR_IFNDEF   = (1LL << 46),
        PREPROCESSOR_INCLUDE  = (1LL << 47),
        PREPROCESSOR_PRAGMA   = (1LL << 48),
        PREPROCESSOR_UNDEF    = (1LL << 49),
        CONTAINS_PRECEDENCE   = (1LL << 50),
        /* CONTAINS_PRECEDENCE   = (1LL << 51),
        CONTAINS_PRECEDENCE   = (1LL << 52), */
        REQUIRE_LVALUE      = (1LL << 53),
        REQUIRE_RVALUE      = (1LL << 54),
        SEMICOLON           = (1LL << 55),
        LITERAL             = (1LL << 56),
        COMMA_AND_NAME      = (1LL << 57),
        COMMA_TYPE_AND_NAME = (1LL << 58),
        PREFIX              = (1LL << 59),
        POSTFIX             = (1LL << 60),
        BOTH                = (1LL << 61),
        OPEN                = (1LL << 62),
        CLOSE               = (1LL << 63),
    };

    Map<String, size_ut> key_expressions_precedences{std::initializer_list<Pair<String, size_ut>>{
        Pair<String, size_ut>{"=", 0LL},   Pair<String, size_ut>{"+", 0LL},  Pair<String, size_ut>{"-", 0LL},
        Pair<String, size_ut>{"*", 0LL},   Pair<String, size_ut>{"/", 0LL},  Pair<String, size_ut>{"%", 0LL},
        Pair<String, size_ut>{"+=", 0LL},  Pair<String, size_ut>{"-=", 0LL}, Pair<String, size_ut>{"*=", 0LL},
        Pair<String, size_ut>{"/=", 0LL},  Pair<String, size_ut>{"%=", 0LL}, Pair<String, size_ut>{">>=", 0LL},
        Pair<String, size_ut>{"<<=", 0LL}, Pair<String, size_ut>{"&=", 0LL}, Pair<String, size_ut>{"^=", 0LL},
        Pair<String, size_ut>{"|=", 0LL},  Pair<String, size_ut>{"++", 0LL}, Pair<String, size_ut>{"--", 0LL},
        Pair<String, size_ut>{"==", 0LL},  Pair<String, size_ut>{"!=", 0LL}, Pair<String, size_ut>{">", 0LL},
        Pair<String, size_ut>{"<", 0LL},   Pair<String, size_ut>{">=", 0LL}, Pair<String, size_ut>{"<=", 0LL},
        Pair<String, size_ut>{"!", 0LL},   Pair<String, size_ut>{"&&", 0LL}, Pair<String, size_ut>{"||", 0LL},
        Pair<String, size_ut>{"?", 0LL},   Pair<String, size_ut>{":", 0LL},  Pair<String, size_ut>{"&", 0LL},
        Pair<String, size_ut>{"|", 0LL},   Pair<String, size_ut>{"^", 0LL},  Pair<String, size_ut>{"~", 0LL},
        Pair<String, size_ut>{"<<", 0LL},  Pair<String, size_ut>{">>", 0LL}, Pair<String, size_ut>{".", 0LL},
        Pair<String, size_ut>{"->", 0LL},  Pair<String, size_ut>{"{", 0LL},  Pair<String, size_ut>{"}", 0LL},
        Pair<String, size_ut>{"[", 0LL},   Pair<String, size_ut>{"]", 0LL},  Pair<String, size_ut>{"(", 0LL},
        Pair<String, size_ut>{")", 0LL},   Pair<String, size_ut>{"'", 0LL},  Pair<String, size_ut>{"\"", 0LL},
        Pair<String, size_ut>{",", 0LL},
    }};

    inline bool checkIs(size_ut a, size_ut b) { return a & b; }

    enum JunctionMode {
        IN    = (1LL << 0),
        AFTER = (1LL << 1),
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

    Array<Types> types{
        Types{"char", Array<Pair<Types, String>>(0)}, Types{"int", Array<Pair<Types, String>>(0)},
        Types{"float", Array<Pair<Types, String>>(0)}, Types{"double", Array<Pair<Types, String>>(0)}};

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


    // class Expression;

    class Expression {
        bool m_has_parent;
        bool m_in_paren;


    public:
        union ExpressionStr {
            std::shared_ptr<Expression> ex;
            String                      str;
            // ExpressionStr(const Expression &exp) : ex(exp) {}
            ExpressionStr(const std::shared_ptr<Expression> &exp) : ex(exp) {}
            ExpressionStr(const String &string) : str(string) {}
            ExpressionStr(const ExpressionStr &exp) : str(exp.str) {}
            ~ExpressionStr() {}
        };
        // Types m_evaluated_type;
        //
        // TODO: true -> use the Expression (means is parent Node)

        Array<Pair<ExpressionStr, bool>> subs;


        Expression() : m_has_parent{false}, m_in_paren{false}, subs() {}
        Expression(const Expression &exp) :
            m_has_parent{exp.m_has_parent}, m_in_paren{exp.m_in_paren}, subs(exp.subs) {}
        /**
         *
         *TODO!!!!:
         * @brief Construct a new Expression object
         *The following function does not actually work, fix this class to use Expression pointers instead, use
         *std::shared_ptr to handle them
         *
         * @param ex
         */
        Expression(Array<Pair<ExpressionStr, bool>> &&ex) : subs(ex) {
            for (size_ut i{0}; i < ex.size(); ++i) {
                if (ex[i].second) { ((Expression *)(&(ex[i].first)))->m_has_parent = true; }
            }
        }
        Expression &push_back(Pair<ExpressionStr, bool> &&ex) {
            if (ex.second) { ex.first.ex->m_has_parent = true; }
            subs.push_back(ex);
            return *this;
        }
        Expression &insert(Pair<ExpressionStr, bool> &&ex, size_ut index) {
            if (ex.second) { ((Expression *)(&(ex.first)))->m_has_parent = true; }
            subs.insert(ex, index);
            return *this;
        }

        Expression &pop_back() {
            if (!subs.size()) *stderr << "Expression already empty.\n";
            if (subs[subs.size() - 1].second) {
                ((Expression *)(&(subs[subs.size() - 1].first)))->m_has_parent = false;
            }
            subs.pop_back();
            return *this;
        }
        Expression &remove(size_ut index) {
            if (index >= subs.size()) *stderr << "Out of range.\n";
            if (subs[index].second) { ((Expression *)(&(subs[index].first)))->m_has_parent = false; }
            // subs.insert(ex, index);
            subs.remove(index, index + 1);
            return *this;
        }


        ExpressionStr &operator[](size_ut index) { return subs[index].first; }
        Expression &   operator=(const Expression &exp) {
            m_has_parent = exp.m_has_parent;
            m_in_paren   = exp.m_in_paren;
            subs         = exp.subs;
            return *this;
        }
        Expression &operator=(const Array<Pair<ExpressionStr, bool>> &ex) {
            for (size_ut i{0}; i < ex.size(); ++i) {
                if (ex[i].second) { ex[i].first.ex->m_has_parent = true; }
            }
            return *this;
        }
        bool &       isExpression(size_ut index) const { return subs[index].second; }
        Expression * indexAsExp(size_ut index) const { return (Expression *)(&(subs[index].first)); }
        String *     indexAsStr(size_ut index) const { return (String *)(&(subs[index].first)); }
        friend FILE &operator<<(FILE &out, const Expression &exp) {
            for (size_ut i{0}; i < exp.subs.size(); ++i) {
                if (exp.isExpression(i)) { out << *exp.indexAsExp(i); }
                else {
                    out << *exp.indexAsStr(i);
                }
            }
        }

        Expression &swap(Expression &b) {
            std::swap(this->m_has_parent, b.m_has_parent);
            std::swap(this->m_in_paren, b.m_in_paren);
            ::swap<Pair<ExpressionStr, bool>>(this->subs, b.subs);
        }


        FILE &write(FILE &out, const Expression &exp /* , bool in_paren = false */) {
            if (m_in_paren) out << '(';
            for (size_ut i{0}; i < exp.subs.size(); ++i) {
                if (exp.isExpression(i)) { out << *exp.indexAsExp(i); }
                else {
                    out << *exp.indexAsStr(i);
                }
            }
            if (m_in_paren) out << ')';
            return out;
        }
    };


    class Statement {
    protected:
    public:
        Expression node;
        Statement() : node() {}
        friend FILE &operator<<(FILE &out, const Statement &st) { out << st.node; }
        Statement &  operator=(const Statement &st) {
            node = st.node;
            return *this;
        }
    };


    // class Scope {
    //     std::vector<Scope *> m_nested_namespaces;

    // public:
    //     enum Types {
    //         CLASS,
    //         STRUCT,
    //         UNION,
    //         NAMESPACE,
    //         FILE,
    //         EXTERNAL,
    //     };

    // protected:
    //     Types                 m_type;
    //     std::vector<Variable> m_members;
    //     std::vector<Function> m_methods;
    //     // Stands for class/struct/enum names.
    //     std::vector<std::string>                  m_types;
    //     std::map<std::string, std::vector<Scope>> m_objects;
    //     std::vector<Statement>                    m_statements;

    // public:
    //     Scope() : m_members{}, m_methods{}, m_objects{}, m_statements{} {}
    //     Scope(const std::vector<Statement> &statements) :
    //         m_members{}, m_methods{}, m_objects{}, m_statements{statements} {}
    //     // TODO: this
    //     Scope &add_scope() {}
    // } global{};

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

    Array<Pair<Array<size_ut>, Pair<size_ut, size_ut>>> statement_types_inversed{
        Pair<Array<size_ut>, Pair<size_ut, size_ut>>{
            {// Blank statement
             STypes::NAME | STypes::LITERAL, STypes::SEMICOLON},
            Pair<size_ut, size_ut>(STypes::NONE, 0)},
        Pair<Array<size_ut>, Pair<size_ut, size_ut>>{
            {// Variable Declaration with initialization
             STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL, STypes::TYPE,
             STypes::ASTERISK_OR_AMPERSAND | STypes::MULTIPLE, STypes::NAME, STypes::ASSIGNMENT,
             STypes::LITERAL | STypes::NAME, STypes::SEMICOLON},
            Pair<size_ut, size_ut>(STypes::NONE, 1)},
        Pair<Array<size_ut>, Pair<size_ut, size_ut>>{
            {// Variable Declaration
             STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL, STypes::TYPE,
             STypes::ASTERISK_OR_AMPERSAND | STypes::MULTIPLE, STypes::NAME, STypes::SEMICOLON},
            Pair<size_ut, size_ut>(STypes::NONE, 2)},
        Pair<Array<size_ut>, Pair<size_ut, size_ut>>{
            {// Variable Declaration array with initialization
             STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL, STypes::TYPE,
             STypes::ASTERISK_OR_AMPERSAND | STypes::MULTIPLE, STypes::NAME, STypes::BRACE | STypes::OPEN,
             STypes::LITERAL | STypes::NAME, STypes::BRACE | STypes::CLOSE, STypes::ASSIGNMENT,
             STypes::LITERAL | STypes::NAME, STypes::SEMICOLON},
            Pair<size_ut, size_ut>(STypes::NONE, 3)},
        Pair<Array<size_ut>, Pair<size_ut, size_ut>>{
            {// Variable Declaration array
             STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL, STypes::TYPE,
             STypes::ASTERISK_OR_AMPERSAND | STypes::MULTIPLE, STypes::NAME, STypes::BRACE | STypes::OPEN,
             STypes::LITERAL | STypes::NAME, STypes::BRACE | STypes::CLOSE, STypes::SEMICOLON},
            Pair<size_ut, size_ut>(STypes::NONE, 4)},
        Pair<Array<size_ut>, Pair<size_ut, size_ut>>{
            {// Function Definition
             STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL, STypes::TYPE,
             STypes::ASTERISK_OR_AMPERSAND | STypes::MULTIPLE, STypes::NAME, STypes::PARENTHESIS | STypes::OPEN,
             STypes::TYPE | STypes::NAME | STypes::OPTIONAL,
             STypes::COMMA | STypes::TYPE | STypes::NAME | STypes::MULTIPLE |
                 STypes::OPTIONAL, // STypes::COMMA_TYPE_AND_NAME |
                                   // STypes::OPTIONAL | STypes::MULTIPLE,
             STypes::PARENTHESIS | STypes::CLOSE, STypes::CURLY_BRACE | STypes::OPEN,
             STypes::STATEMENT | STypes::OPTIONAL | STypes::MULTIPLE, STypes::CURLY_BRACE | STypes::CLOSE},
            Pair<size_ut, size_ut>(STypes::NONE, 6)},
        Pair<Array<size_ut>, Pair<size_ut, size_ut>>{
            {// Function Declaration
             STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL, STypes::TYPE,
             STypes::ASTERISK_OR_AMPERSAND | STypes::MULTIPLE, STypes::NAME, STypes::PARENTHESIS | STypes::OPEN,
             STypes::TYPE | STypes::NAME | STypes::OPTIONAL,
             STypes::COMMA | STypes::TYPE | STypes::NAME | STypes::MULTIPLE |
                 STypes::OPTIONAL, // STypes::COMMA_TYPE_AND_NAME |
                                   // STypes::OPTIONAL | STypes::MULTIPLE,
             STypes::PARENTHESIS | STypes::CLOSE, STypes::SEMICOLON},
            Pair<size_ut, size_ut>(STypes::NONE, 7)},
        Pair<Array<size_ut>, Pair<size_ut, size_ut>>{
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
            Pair<size_ut, size_ut>(STypes::LITERAL, 16)},
        Pair<Array<size_ut>, Pair<size_ut, size_ut>>{
            {// Operator postfix
             STypes::NAME | STypes::LITERAL, STypes::OPERATOR | STypes::PREFIX},
            Pair<size_ut, size_ut>(-1, 18)},
        Pair<Array<size_ut>, Pair<size_ut, size_ut>>{
            {// Operator prefix
             STypes::OPERATOR | STypes::PREFIX, STypes::NAME | STypes::LITERAL},
            Pair<size_ut, size_ut>(-1, 19)},
        Pair<Array<size_ut>, Pair<size_ut, size_ut>>{
            {// Operator both
             STypes::NAME | STypes::LITERAL, STypes::OPERATOR | STypes::BOTH, STypes::NAME | STypes::LITERAL},
            Pair<size_ut, size_ut>(-1, 20)},
        Pair<Array<size_ut>, Pair<size_ut, size_ut>>{
            {// Type-call statement
             STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL, STypes::TYPE,
             STypes::PARENTHESIS | STypes::OPEN, STypes::NAME | STypes::LITERAL | STypes::OPTIONAL,
             STypes::PARENTHESIS | STypes::CLOSE},
            Pair<size_ut, size_ut>(-1, 21)},
        Pair<Array<size_ut>, Pair<size_ut, size_ut>>{
            {// Casting statement
             STypes::PARENTHESIS | STypes::OPEN, STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL,
             STypes::TYPE, STypes::PARENTHESIS | STypes::CLOSE, STypes::NAME | STypes::LITERAL},
            Pair<size_ut, size_ut>(-1, 22)},
        Pair<Array<size_ut>, Pair<size_ut, size_ut>>{
            {// Parentheses
             //  STypes::NAME | STypes::LITERAL, STypes::OPERATOR | STypes::PREFIX
             STypes::PARENTHESIS | STypes::OPEN, STypes::LITERAL | STypes::NAME, STypes::PARENTHESIS | STypes::CLOSE},
            Pair<size_ut, size_ut>(-1, 23)},
        Pair<Array<size_ut>, Pair<size_ut, size_ut>>{
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
            Pair<size_ut, size_ut>(-1, 24)},
        Pair<Array<size_ut>, Pair<size_ut, size_ut>>{
            {// Type name
             STypes::STRUCT | STypes::ENUM | STypes::UNION, STypes::NAME},
            Pair<size_ut, size_ut>(STypes::TYPE, 25)},
    };

    Array<Pair<Array<Pair<Array<size_ut>, size_ut>>, Pair<size_ut, size_ut>>> statement_types_arrays{
        Pair<Array<Pair<Array<size_ut>, size_ut>>, Pair<size_ut, size_ut>>{
            {// Type name
             Pair<Array<size_ut>, size_ut>{{STypes::TYPE_MODIFIER}, STypes::MULTIPLE | STypes::OPTIONAL},
             Pair<Array<size_ut>, size_ut>{{STypes::STRUCT | STypes::ENUM | STypes::UNION}, STypes::OPTIONAL},
             Pair<Array<size_ut>, size_ut>{{STypes::NAME}, STypes::NONE},
             Pair<Array<size_ut>, size_ut>{
                 {STypes::AMPERSAND | STypes::ASTERISK}, STypes::OPTIONAL | STypes::MULTIPLE}},
            Pair<size_ut, size_ut>(STypes::TYPE, 25)},

        // TODO: Copy the format of the above to below ones.
        Pair<Array<Pair<Array<size_ut>, size_ut>>, Pair<size_ut, size_ut>>{
            {
                // Function Call
                Pair<Array<size_ut>, size_ut>{{STypes::NAME}, STypes::NONE},
                Pair<Array<size_ut>, size_ut>{{STypes::PARENTHESIS}, STypes::OPEN},
                Pair<Array<size_ut>, size_ut>{{STypes::NAME | STypes::LITERAL}, STypes::OPTIONAL},
                Pair<Array<size_ut>, size_ut>{
                    {STypes::COMMA, STypes::NAME | STypes::LITERAL},
                    STypes::MULTIPLE | STypes::OPTIONAL}, // STypes::COMMA_TYPE_AND_NAME |
                                                          // STypes::OPTIONAL | STypes::MULTIPLE,
                Pair<Array<size_ut>, size_ut>{{STypes::PARENTHESIS}, STypes::CLOSE},
            },
            Pair<size_ut, size_ut>(-1, 24)},
        Pair<Array<Pair<Array<size_ut>, size_ut>>, Pair<size_ut, size_ut>>{
            {
                // Function Call
                Pair<Array<size_ut>, size_ut>{
                    {STypes::AMPERSAND | STypes::ASTERISK}, STypes::OPTIONAL | STypes::MULTIPLE},
                Pair<Array<size_ut>, size_ut>{{STypes::NAME}, STypes::NONE},
                // Pair<Array<size_ut>, size_ut>{{STypes::PARENTHESIS}, STypes::OPEN},
                // Pair<Array<size_ut>, size_ut>{{STypes::NAME | STypes::LITERAL},
                // STypes::OPTIONAL}, Pair<Array<size_ut>, size_ut>{
                //{STypes::COMMA, STypes::NAME | STypes::LITERAL},
                // STypes::MULTIPLE | STypes::OPTIONAL}, // STypes::COMMA_TYPE_AND_NAME |
                //// STypes::OPTIONAL | STypes::MULTIPLE,
                // Pair<Array<size_ut>, size_ut>{{STypes::PARENTHESIS}, STypes::CLOSE},
            },
            Pair<size_ut, size_ut>(-1, 23)},
        Pair<Array<Pair<Array<size_ut>, size_ut>>, Pair<size_ut, size_ut>>{
            {// Casting statement
             Pair<Array<size_ut>, size_ut>{{STypes::PARENTHESIS}, STypes::OPEN},
             Pair<Array<size_ut>, size_ut>{{STypes::TYPE_MODIFIER}, STypes::MULTIPLE | STypes::OPTIONAL},
             Pair<Array<size_ut>, size_ut>{{STypes::TYPE}, STypes::NONE},
             Pair<Array<size_ut>, size_ut>{{STypes::PARENTHESIS}, STypes::CLOSE},
             Pair<Array<size_ut>, size_ut>{{STypes::NAME | STypes::LITERAL}, STypes::NONE}},
            Pair<size_ut, size_ut>(-1, 22)},
        Pair<Array<Pair<Array<size_ut>, size_ut>>, Pair<size_ut, size_ut>>{
            {// Type-call statement
             Pair<Array<size_ut>, size_ut>{{STypes::TYPE_MODIFIER}, STypes::MULTIPLE | STypes::OPTIONAL},
             Pair<Array<size_ut>, size_ut>{{STypes::TYPE}, STypes::NONE},
             Pair<Array<size_ut>, size_ut>{{STypes::PARENTHESIS}, STypes::OPEN},
             Pair<Array<size_ut>, size_ut>{{STypes::NAME | STypes::LITERAL}, STypes::OPTIONAL},
             Pair<Array<size_ut>, size_ut>{{STypes::PARENTHESIS}, STypes::CLOSE}},
            Pair<size_ut, size_ut>(-1, 21)},
        Pair<Array<Pair<Array<size_ut>, size_ut>>, Pair<size_ut, size_ut>>{
            {// Operator both
             Pair<Array<size_ut>, size_ut>{{STypes::NAME | STypes::LITERAL}, STypes::NONE},
             Pair<Array<size_ut>, size_ut>{{STypes::OPERATOR}, STypes::BOTH},
             Pair<Array<size_ut>, size_ut>{{STypes::NAME | STypes::LITERAL}, STypes::NONE}},
            Pair<size_ut, size_ut>(-1, 20)},
        Pair<Array<Pair<Array<size_ut>, size_ut>>, Pair<size_ut, size_ut>>{
            {// Operator prefix
             Pair<Array<size_ut>, size_ut>{{STypes::OPERATOR}, STypes::PREFIX},
             Pair<Array<size_ut>, size_ut>{{STypes::NAME | STypes::LITERAL}, STypes::NONE}},
            Pair<size_ut, size_ut>(-1, 19)},
        Pair<Array<Pair<Array<size_ut>, size_ut>>, Pair<size_ut, size_ut>>{
            {// Operator postfix
             Pair<Array<size_ut>, size_ut>{{STypes::NAME | STypes::LITERAL}, STypes::NONE},
             Pair<Array<size_ut>, size_ut>{{STypes::OPERATOR}, STypes::PREFIX}},
            Pair<size_ut, size_ut>(-1, 18)},
        Pair<Array<Pair<Array<size_ut>, size_ut>>, Pair<size_ut, size_ut>>{
            {// Reference/Pointer prefix
             Pair<Array<size_ut>, size_ut>{{STypes::ASTERISK | STypes::AMPERSAND}, STypes::NONE},
             Pair<Array<size_ut>, size_ut>{{STypes::NAME}, STypes::NONE}},
            Pair<size_ut, size_ut>(-1, 17)},
        Pair<Array<Pair<Array<size_ut>, size_ut>>, Pair<size_ut, size_ut>>{
            {
                // Initializer list
                Pair<Array<size_ut>, size_ut>{{STypes::CURLY_BRACE}, STypes::OPEN},
                Pair<Array<size_ut>, size_ut>{{STypes::LITERAL}, STypes::OPTIONAL},
                // STypes::TYPE,
                // STypes::ASTERISK_OR_AMPERSAND | STypes::MULTIPLE,
                // STypes::NAME,
                // STypes::LITERAL | STypes::NAME,
                Pair<Array<size_ut>, size_ut>{{STypes::COMMA, STypes::LITERAL}, STypes::MULTIPLE | STypes::OPTIONAL},
                Pair<Array<size_ut>, size_ut>{{STypes::CURLY_BRACE}, STypes::CLOSE},
            },
            Pair<size_ut, size_ut>(STypes::LITERAL, 16)},

        // TODO: Remove the ASTERISK and AMPERSANDs from the things, since they are now part of the first
        // one.
        // TODO: Also check the semicolons
        Pair<Array<Pair<Array<size_ut>, size_ut>>, Pair<size_ut, size_ut>>{
            {// Function Declaration
             // Pair<Array<size_ut>, size_ut>{{STypes::TYPE_MODIFIER}, STypes::MULTIPLE |
             // STypes::OPTIONAL},
             Pair<Array<size_ut>, size_ut>{{STypes::TYPE}, STypes::NONE},
             // Pair<Array<size_ut>, size_ut>{
             //{STypes::ASTERISK | STypes::AMPERSAND}, STypes::MULTIPLE | STypes::OPTIONAL},
             Pair<Array<size_ut>, size_ut>{{STypes::NAME}, STypes::NONE},
             Pair<Array<size_ut>, size_ut>{{STypes::PARENTHESIS}, STypes::OPEN},
             Pair<Array<size_ut>, size_ut>{{STypes::TYPE, STypes::NAME}, STypes::OPTIONAL},
             Pair<Array<size_ut>, size_ut>{
                 {STypes::COMMA, STypes::TYPE, STypes::NAME}, STypes::MULTIPLE | STypes::OPTIONAL},
             // STypes::COMMA_TYPE_AND_NAME |
             // STypes::OPTIONAL | STypes::MULTIPLE,
             Pair<Array<size_ut>, size_ut>{{STypes::PARENTHESIS}, STypes::CLOSE},
             Pair<Array<size_ut>, size_ut>{{STypes::SEMICOLON}, STypes::NONE}},
            Pair<size_ut, size_ut>(STypes::NONE, 7)},
        // TODO: Continue making them pairs from here on.
        Pair<Array<Pair<Array<size_ut>, size_ut>>, Pair<size_ut, size_ut>>{
            {// Function Definition
             // Pair<Array<size_ut>, size_ut>{{STypes::TYPE_MODIFIER}, STypes::MULTIPLE |
             // STypes::OPTIONAL},
             Pair<Array<size_ut>, size_ut>{{STypes::TYPE}, STypes::NONE},
             // Pair<Array<size_ut>, size_ut>{{STypes::ASTERISK | STypes::AMPERSAND},
             // STypes::MULTIPLE},
             Pair<Array<size_ut>, size_ut>{{STypes::NAME}, STypes::NONE},
             Pair<Array<size_ut>, size_ut>{{STypes::PARENTHESIS}, STypes::OPEN},
             Pair<Array<size_ut>, size_ut>{{STypes::TYPE, STypes::NAME}, STypes::OPTIONAL},
             Pair<Array<size_ut>, size_ut>{
                 {STypes::COMMA, STypes::TYPE, STypes::NAME}, STypes::MULTIPLE | STypes::OPTIONAL},
             // STypes::COMMA_TYPE_AND_NAME |                                                       //
             // STypes::OPTIONAL | STypes::MULTIPLE,
             Pair<Array<size_ut>, size_ut>{{STypes::PARENTHESIS}, STypes::CLOSE},
             Pair<Array<size_ut>, size_ut>{{STypes::CURLY_BRACE}, STypes::OPEN},
             Pair<Array<size_ut>, size_ut>{{STypes::STATEMENT}, STypes::OPTIONAL | STypes::MULTIPLE},
             Pair<Array<size_ut>, size_ut>{{STypes::CURLY_BRACE}, STypes::CLOSE}},
            Pair<size_ut, size_ut>(STypes::NONE, 6)},
        Pair<Array<Pair<Array<size_ut>, size_ut>>, Pair<size_ut, size_ut>>{
            {// Parentheses
             //  STypes::NAME | STypes::LITERAL, STypes::OPERATOR | STypes::PREFIX
             Pair<Array<size_ut>, size_ut>{{STypes::PARENTHESIS}, STypes::OPEN},
             Pair<Array<size_ut>, size_ut>{{STypes::LITERAL | STypes::NAME}, STypes::NONE},
             Pair<Array<size_ut>, size_ut>{{STypes::PARENTHESIS}, STypes::CLOSE}},
            Pair<size_ut, size_ut>(-1, 5)},
        Pair<Array<Pair<Array<size_ut>, size_ut>>, Pair<size_ut, size_ut>>{
            {// Variable Declaration array
             // Pair<Array<size_ut>, size_ut>{{STypes::TYPE_MODIFIER}, STypes::MULTIPLE |
             // STypes::OPTIONAL},
             Pair<Array<size_ut>, size_ut>{{STypes::TYPE}, STypes::NONE},
             // Pair<Array<size_ut>, size_ut>{{STypes::ASTERISK_OR_AMPERSAND}, STypes::MULTIPLE},
             Pair<Array<size_ut>, size_ut>{{STypes::NAME}, STypes::NONE},
             Pair<Array<size_ut>, size_ut>{{STypes::BRACE}, STypes::OPEN},
             Pair<Array<size_ut>, size_ut>{{STypes::LITERAL | STypes::NAME}, STypes::NONE},
             Pair<Array<size_ut>, size_ut>{{STypes::BRACE}, STypes::CLOSE},
             Pair<Array<size_ut>, size_ut>{{STypes::SEMICOLON}, STypes::NONE}},
            Pair<size_ut, size_ut>(STypes::NONE, 4)},
        Pair<Array<Pair<Array<size_ut>, size_ut>>, Pair<size_ut, size_ut>>{
            {// Variable Declaration array with initialization
             // Pair<Array<size_ut>, size_ut>{{STypes::TYPE_MODIFIER}, STypes::MULTIPLE |
             // STypes::OPTIONAL},
             Pair<Array<size_ut>, size_ut>{{STypes::TYPE}, STypes::NONE},
             // Pair<Array<size_ut>, size_ut>{
             //{STypes::ASTERISK | STypes::AMPERSAND}, STypes::OPTIONAL | STypes::MULTIPLE},
             Pair<Array<size_ut>, size_ut>{{STypes::NAME}, STypes::NONE},
             Pair<Array<size_ut>, size_ut>{{STypes::BRACE}, STypes::OPEN},
             Pair<Array<size_ut>, size_ut>{{STypes::LITERAL | STypes::NAME}, STypes::NONE},
             Pair<Array<size_ut>, size_ut>{{STypes::BRACE}, STypes::CLOSE},
             Pair<Array<size_ut>, size_ut>{{STypes::ASSIGNMENT}, STypes::NONE},
             Pair<Array<size_ut>, size_ut>{{STypes::LITERAL | STypes::NAME}, STypes::NONE},
             Pair<Array<size_ut>, size_ut>{{STypes::SEMICOLON}, STypes::NONE}},
            Pair<size_ut, size_ut>(STypes::NONE, 3)},
        Pair<Array<Pair<Array<size_ut>, size_ut>>, Pair<size_ut, size_ut>>{
            {// Variable Declaration
             //  STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL,
             Pair<Array<size_ut>, size_ut>{{STypes::TYPE}, STypes::NONE},
             // STypes::ASTERISK_OR_AMPERSAND | STypes::MULTIPLE,
             Pair<Array<size_ut>, size_ut>{{STypes::NAME}, STypes::NONE},
             Pair<Array<size_ut>, size_ut>{{STypes::COMMA, STypes::NAME}, STypes::NONE},
             Pair<Array<size_ut>, size_ut>{{STypes::SEMICOLON}, STypes::NONE}},
            Pair<size_ut, size_ut>(STypes::NONE, 2)},
        Pair<Array<Pair<Array<size_ut>, size_ut>>, Pair<size_ut, size_ut>>{
            {// Variable Declaration with initialization
             // STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL,
             Pair<Array<size_ut>, size_ut>{{STypes::TYPE}, STypes::NONE},
             // STypes::ASTERISK_OR_AMPERSAND | STypes::MULTIPLE,
             Pair<Array<size_ut>, size_ut>{{STypes::NAME}, STypes::NONE},
             Pair<Array<size_ut>, size_ut>{{STypes::ASSIGNMENT}, STypes::NONE},
             Pair<Array<size_ut>, size_ut>{{STypes::LITERAL | STypes::NAME}, STypes::NONE},
             Pair<Array<size_ut>, size_ut>{{STypes::SEMICOLON}, STypes::NONE}},
            Pair<size_ut, size_ut>(STypes::NONE, 1)},
        Pair<Array<Pair<Array<size_ut>, size_ut>>, Pair<size_ut, size_ut>>{
            {// Blank statement
             Pair<Array<size_ut>, size_ut>{{STypes::NAME | STypes::LITERAL}, STypes::NONE},
             Pair<Array<size_ut>, size_ut>{{STypes::SEMICOLON}, STypes::NONE}},
            Pair<size_ut, size_ut>(STypes::NONE, 0)}
        // Pair<Array<Pair<Array<size_ut>, size_ut>>, Pair<size_ut, size_ut>> {
        //     { // Operator postfix
        //         STypes::NAME | STypes::LITERAL,
        //         STypes::OPERATOR | STypes::PREFIX } }
    };

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
                STypes::COMMA | STypes::NAME | STypes::LITERAL | STypes::MULTIPLE |
                    STypes::OPTIONAL, // STypes::COMMA_TYPE_AND_NAME |
                                      // STypes::OPTIONAL | STypes::MULTIPLE,
                STypes::PARENTHESIS | STypes::CLOSE,
            },
            Pair<size_ut, size_ut>(-1, 24)},
        Pair<Array<size_ut>, Pair<size_ut, size_ut>>{
            {// Parentheses
             //  STypes::NAME | STypes::LITERAL, STypes::OPERATOR | STypes::PREFIX
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
                // STypes::TYPE,
                // STypes::ASTERISK_OR_AMPERSAND | STypes::MULTIPLE,
                // STypes::NAME,
                // STypes::LITERAL | STypes::NAME,
                STypes::COMMA | STypes::LITERAL | STypes::MULTIPLE | STypes::OPTIONAL,
                STypes::CURLY_BRACE | STypes::CLOSE,
            },
            Pair<size_ut, size_ut>(STypes::LITERAL, 16)},
        Pair<Array<size_ut>, Pair<size_ut, size_ut>>{
            {// Function Declaration
             STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL, STypes::TYPE,
             STypes::ASTERISK_OR_AMPERSAND | STypes::MULTIPLE, STypes::NAME, STypes::PARENTHESIS | STypes::OPEN,
             STypes::TYPE | STypes::NAME | STypes::OPTIONAL,
             STypes::COMMA | STypes::TYPE | STypes::NAME | STypes::MULTIPLE |
                 STypes::OPTIONAL, // STypes::COMMA_TYPE_AND_NAME |
                                   // STypes::OPTIONAL | STypes::MULTIPLE,
             STypes::PARENTHESIS | STypes::CLOSE, STypes::SEMICOLON},
            Pair<size_ut, size_ut>(STypes::NONE, 7)},
        Pair<Array<size_ut>, Pair<size_ut, size_ut>>{
            {// Function Definition
             STypes::TYPE_MODIFIER | STypes::MULTIPLE | STypes::OPTIONAL, STypes::TYPE,
             STypes::ASTERISK_OR_AMPERSAND | STypes::MULTIPLE, STypes::NAME, STypes::PARENTHESIS | STypes::OPEN,
             STypes::TYPE | STypes::NAME | STypes::OPTIONAL,
             STypes::COMMA | STypes::TYPE | STypes::NAME | STypes::MULTIPLE |
                 STypes::OPTIONAL, // STypes::COMMA_TYPE_AND_NAME |
                                   // STypes::OPTIONAL | STypes::MULTIPLE,
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
        // Pair<Array<size_ut>, Pair<size_ut, size_ut>> {
        //     { // Operator postfix
        //         STypes::NAME | STypes::LITERAL,
        //         STypes::OPERATOR | STypes::PREFIX } }
    };


    // TODO: qsort this from greatest precedence (greatest number) to least

    // TODO: types can also be called as functions.

    Array<Pair<String, size_ut>> type_modifier_order{
        Pair<String, size_ut>("auto", 0),     Pair<String, size_ut>("static", 0), Pair<String, size_ut>("extern", 0),
        Pair<String, size_ut>("register", 0), Pair<String, size_ut>("const", 1),  Pair<String, size_ut>("long", -1),
        Pair<String, size_ut>("short", -2),   Pair<String, size_ut>("signed", 3), Pair<String, size_ut>("unsigned", 3),
    };
    /*
                Array<Pair<Pair<size_ut, size_ut>, JunctionMode>> location_specifics{
                    Pair<Pair<size_ut, size_ut>, JunctionMode>(
                        Pair<size_ut, size_ut>(STypes::ELSE, STypes::IF), JunctionMode::AFTER),
                    Pair<Pair<size_ut, size_ut>, JunctionMode>(
                        Pair<size_ut, size_ut>(STypes::CASE, STypes::SWITCH), JunctionMode::IN),
                    Pair<Pair<size_ut, size_ut>, JunctionMode>(
                        Pair<size_ut, size_ut>(STypes::BREAK, STypes::SWITCH), JunctionMode::IN),
                }; */

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
        Pair<String, Array<Pair<size_ut, size_ut>>>{"typedef", {Pair<size_ut, size_ut>(STypes::TYPEDEF, 0)}},
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
        Pair<String, Array<Pair<size_ut, size_ut>>>{"=", {Pair<size_ut, size_ut>(STypes::OPERATOR | STypes::BOTH, 14)}},
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
        // TODO: Not so sure about putting space here after new and delete
    }};

    const Map<String, Array<Pair<size_ut, size_ut>>> key_expressions_const = key_expressions;

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

    // bool compatible(Array<size_ut>& a, Array<) {
    //     if()
    //     ;
    // }

#define checkBit(a, b) (a & (1LL << b))
#define setBit(a, b) (a |= (1LL << b))
#define resetBit(a, b) (a &= ~(1LL << b))
#define set(a) (a |= std::numeric_limits<size_ut>::max())
#define reset(a) (a &= 0LL)


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
        const Array<size_ut> &a, /*  size_ut foptions, */ size_ut index1, size_ut index2
        /*,bool mode /*0 is test mode, 1 is accept mode*/) {
#define sta(param) statement_types_arrays[index1].first[index2].first[param]
#define sts statement_types_arrays[index1].first[index2].first.size()
#define foptions statement_types_arrays[index1].first[index2].second
        for (size_ut i{0}; i < sts; ++i) {
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
    short int matchExact(
        const Array_view<Pair<String, Array<Pair<size_ut, size_ut>>>> &a, size_ut precedence,
        /*  size_ut foptions, */ size_ut index1, size_ut index2
        /*,bool mode /*0 is test mode, 1 is accept mode*/) {
#define sta(param) statement_types_arrays[index1].first[index2].first[param]
#define sts statement_types_arrays[index1].first[index2].first.size()
#define foptions statement_types_arrays[index1].first[index2].second
#define ainfof (i, i0) a[i].second[i0].first
#define ainfos (i, i0) a[i].second[i0].second
        for (size_ut i{0}; i < sts; ++i) {
            // TODO!: Finish this
            for (size_ut i0{0}; i < a[i].second.size(); ++i) {
                if (sta(i) & ainfof(i, i0)) {
                    if ((ainfof(i, i0) & STypes::PARENTHESIS) || (ainfof(i, i0) & STypes::BRACE) ||
                        (ainfof(i, i0) & STypes::CURLY_BRACE) || (ainfof(i, i0) & STypes::OPERATOR)) {
                        if ((foptions & ainfof(i, i0))) {
                            if (ainfof(i, i0) & STypes::OPERATOR) {
                                if (ainfos(i, i0) == precedence) { continue; }
                                return 0;
                            }
                            continue;
                        }
                        return 0;
                    }
                    continue;
                }
            }
            // TODO!: If the thing is not over yet but matched so far, return -1; if over and all matched, return 1; if
            if (sts == i + 1) return 1;
        }
        return -1;
#undef ainfos
#undef ainfof
#undef foptions
#undef sts
#undef sta
    }


    bool checkArr(const Array<size_ut> &a, size_ut index) {
#define arr statement_types_arrays[index].first
        short int      tmp{0};
        Array<size_ut> tmp_arr{};
        size_ut        offset{0};
        int            j_was = 0;
        // TODO: The j might not be direct loops of the i, maybe make it so tha tj retains its value after each
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
            }
            if (arr[i - 1].second & STypes::MULTIPLE) {
                if (matchExact(tmp_arr, index, --i)) { goto next_loop; }
            }
            return false;

        next_loop:;
        }
        return true;
#undef arr
    }


    short int parseArray(const Array<size_ut> &a, size_ut index) {
#define arr statement_types_arrays[index].first
        short int      tmp{0};
        Array<size_ut> tmp_arr{};
        size_ut        offset{0};
        // TODO: The j might not be direct loops of the i, maybe make it so tha tj retains its value after each
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


    short int parseArray(
        const Array_view<Pair<String, Array<Pair<size_ut, size_ut>>>> &a, size_ut index,
        size_ut operator_precedence_level = 0LL) {


        // TODO: fix this operator_precedence_level (put the precedence level of the operators if the Array contains

#define arr statement_types_arrays[index].first
        short int                                               tmp{0};
        Array_view<Pair<String, Array<Pair<size_ut, size_ut>>>> arr_view{a};
        size_ut                                                 offset{0};
        // TODO: The j might not be direct loops of the i, maybe make it so tha tj retains its value after each

        size_ut start{0}, end{1};

        arr_view.setViewEnd(0);
        for (size_ut i{0}; ((end < arr[i].first.size()) && (i < arr.size())); ++end, ++i, offset = 0) {
        no_increment:
            arr_view.setViewStart(start);
            arr_view.setViewEnd(end);
            tmp = matchExact(arr_view, operator_precedence_level, index, i);
            if (tmp > 0) {
                start = arr_view.end();
                arr_view.setViewStart(start);
                continue;
            }
            if (tmp) {
                --i;
                continue;
            }
            for (int k{i}; (k < arr.size()) && (arr[k].second & STypes::OPTIONAL); ++k) {
                if (matchExact(arr_view, operator_precedence_level, index, k)) {
                    i = k - 1;

                    end = arr_view.start();
                    arr_view.setViewEnd(end);

                    goto next_loop;
                }
            }
            if (arr[i - 1].second & STypes::MULTIPLE) {
                if (matchExact(arr_view, operator_precedence_level, index, --i)) { goto next_loop; }
            }
            return -1;
        next_loop:;
        }
        return end;
#undef arr
    }


    /**
     * @brief
     * the parameter a is the list of the things in the parsed statement.
     */

    bool check(Array<Pair<String, Array<Pair<size_ut, size_ut>>>> &a, Array<Statement> &arr_statements) {
        Array_view<Pair<String, Array<Pair<size_ut, size_ut>>>> arr_view{a};

        Statement                                 statement1{};
        Map<size_ut, std::shared_ptr<Expression>> mapc{}, mapb{};
        for (bool changed{true}, just_changed{false}, changed_back{false}; changed; changed = false) {
            /** TODO: TODO: TODO::: FIX THESE BELOW STUFFFF!!!!!!!!!
             * TODO: Also these notes from the notepad:
             *make function for Map class -> can search for keys starting with something.


            when the checkArr(the new one) replaces, continue that loop, then make it run again with the same i, and
            then make it start from i = 0 onwards.
            */

            for (size_ut i{0}, increment{0}, inc{0}; i < statement_types_arrays.size(); i += inc) {
                goto start_of_loop;
            restart_loop:
                i = 0;
            start_of_loop:

                // TODO!!!!!!!!!!!!!!:
                // the statement below does not work if i is already on the last one, make it check before the condition
                // check from the for loop itself.
                inc = 1;
                for (size_ut j{0}, holder{0}; j < a.size();
                     ++j /* j += !just_changed */, arr_view.truncFront(increment), holder = 0) {
                    // TODO!:
                    /*
                    Make the checkArr to support using STypes::Statement, maybe by replacing all sub arrays until
                     they are all STypes::Statement. Update the parser to make Array<Pair<String,
                    Array<Pair<size_ut, size_ut>>>>, then send it to the bool check(Array<Pair<size_ut,
                    size_ut>, ...), while changing its parameter and working as well.
                    */

                    // for (size_ut holder{0}; holder < 15; ++i) {
                    for (size_ut holder{0}; holder < 15; ++holder) {

                        // TODO!: Update this parseArray, so it receives Array<Pair<String, Array<Pair<size_ut,
                        // size_ut>>>> instead, but ignores the String part (param[i].first) in the checking
                        // process. Also make it parse the Arrays properly, instead of one-by-one like now
                        // also make the left-to-right and right-to-left operator precedences work.
                        // TODO!:
                        // Make a copy of a with a different type; instead of taking like the thing parsed from the main
                        // map, just use Array<size_ut> or something similar instead
                        increment = parseArray(arr_view, i, 0LL);

                        if (increment < 0) {
                            increment = 1;
                            goto next_sub;
                        }

                        // TODO!: Make an Array_view of whatever to add with (the things that are about to get replaced)
                        {
                            // TODO!: Reduce the values of the keys in mapb according to how many items in the Array<> a
                            // are replaced.
                            for (size_ut j{0}; j < mapb.size(); ++j) { mapc.insert(mapb(j)); }
                            ::swap(mapc, mapb);
                            mapc.clear();
                            Array<Pair<Expression::ExpressionStr, bool>> arr{};
                            for (size_ut j{i}; j < i + increment; ++j) {
                                size_ut index{mapb.find(j)};
                                /**
                                 * @brief
                                 * Note:
                                 * If the string is empty, that means it should also be in the map1 already, so no need
                                 * to check for both, just one is enough
                                 *
                                 */
                                if ((index != mapb.size())) {
                                    arr.push_back(Pair<Expression::ExpressionStr, bool>(
                                        Expression::ExpressionStr(mapb(index).second), 1));
                                    mapb.Array::remove(index, index + 1);
                                    // TODO!: Get the Expression pointer, then make it part of the new parent
                                }
                                else {
                                    // TODO!: Get the String, then make an Expression with it in the constructor
                                    arr.push_back(Pair<Expression::ExpressionStr, bool>(
                                        Expression::ExpressionStr(arr_view[j].first), 0));
                                }
                            }
                            mapc.insert(Pair<size_ut, std::shared_ptr<Expression>>(
                                i, std::make_shared<Expression>(new Expression)));
                            *(mapc[(size_ut)i].second) = arr;

                            Pair<String, Array<Pair<size_ut, size_ut>>> temp(
                                String(""),
                                {Pair<size_ut, size_ut>(
                                    statement_types_arrays[i].second.first,
                                    /* (size_ut)STypes::NONE */ (size_ut)0UL)});
                            a.replace(temp, i, i + increment);
                        }

                        // TODO!: Change this statement below:
                        just_changed = true;
                        inc          = 0;

                    next_sub:

                        if (!holder) {
                            size_ut sum{0};
                            for (size_ut k{0}; k < statement_types_arrays[i].first.size(); ++k) {
                                for (size_ut l{0}; l < statement_types_arrays[i].first[k].first.size(); ++l) {
                                    if (statement_types_arrays[i].first[k].first[l] & STypes::OPERATOR) { ++k; }
                                }
                            }
                            if (!sum) break;
                            // TODO: implement arr so can get Array from Array_view, and from then search for any
                            // operators, if there is, then don't break.
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
    }


    // Expression generate(Array<size_ut> a) {
    //     for (int i{0}; i < statement_types_arrays.size(); ++i) {
    //         for (int j{0}; j < statement_types_arrays[i].first.size(); ++j) {
    //             if (a[j] & statement_types_arrays[i].first[j]) {}
    //             else if (statement_types_arrays[i].first[j] & STypes::MULTIPLE) {
    //             }
    //             else if (statement_types_arrays[i].first[j] & STypes::OPTIONAL) {
    //             }
    //         }
    //     }
    // }

    // TODO: use the regex library instead of manual parsing.
    // TODO: also make sure that the += and + do not get confused.
#undef set
    Classifier &parse(FILE *file) {
        Array<Pair<String, Array<Pair<size_ut, size_ut>>>> container{};
        String                                             str{};
        int                                                c;
        std::stringstream                                  ss{};
        ss << container;
        Array<Statement>                                   stm(0);
        Array<size_ut>                                     exp(0);
        bool                                               ws{false}, wsp{false};
        short int                                          mode{0};
        bool                                               end_of_term;
        size_ut                                            find_result{0UL};
        Array<Pair<String, Array<Pair<size_ut, size_ut>>>> parsed_results{};
        str << *file;
        String_view sv{str};
        sv.setView(0, 0);
        bool           wasChar{false}, isChar{false};
        Array<String>  keys{key_expressions_const.keys()};
        Array<size_ut> inserted_indexes{};
        size_ut        ind;
        Bitset<>       bs(str.size(), 0);
        size_ut        matched_index{-1};
        bool wasAn{false}, isAn{false}, inString{false}, inChar{false}, inNum{false}, inName{false}, inComment{false};
        // Note: stands for indexes from back

        // For lines 1484:
        Array<size_t> found_indexes{}, fi_tmp{};

        bool isFirst(true);

#define indFB(arg) sv[sv.size() - (arg + 1)]
        for (std::size_t i(0); i < str.size(); ++i, wasAn = isAn) {
            sv.extendBack(1);
            isAn = isAlnum(sv[sv.size() - 1]);
            if (wasAn && isAn) continue;
            if (inString) {
                if (indFB(0) == '\"' && indFB(1) != '\\')
                    parsed_results.push_back(Pair<String, Array<Pair<size_ut, size_ut>>>{
                        String(sv), {Pair<size_ut, size_ut>(STypes::LITERAL, 0)}});
                sv.truncFront(sv.size());
                inString = false;
            }
            else if (inChar) {
                if (indFB(0) == '\'' && indFB(1) != '\\') {
                    parsed_results.push_back(Pair<String, Array<Pair<size_ut, size_ut>>>{
                        String(sv), {Pair<size_ut, size_ut>(STypes::LITERAL, 0)}});
                    sv.truncFront(sv.size());
                    inChar = false;
                }
            }
            else if (inNum) {
                sv.truncBack(1);
                parsed_results.push_back(Pair<String, Array<Pair<size_ut, size_ut>>>{
                    String(sv), {Pair<size_ut, size_ut>(STypes::LITERAL, 0)}});
                // sv.extendBack(1);
                sv.truncFront(sv.size());
                isAn  = true;
                inNum = false;
                --i;
                // parsed_results.push_back(Pair < String, )
            }
            else if (inName) {
                sv.truncBack(1);
                parsed_results.push_back(Pair<String, Array<Pair<size_ut, size_ut>>>{
                    String(sv), {Pair<size_ut, size_ut>(STypes::LITERAL, 0)}});
                // sv.extendBack(1);
                sv.truncFront(sv.size());
                isAn  = true;
                inNum = false;
                --i;
            }
            else if (inComment) {
                if (indFB(0) == '\n' && indFB(1) != '\\') {
                    sv.truncFront(sv.size());
                    inComment = false;
                }
                // if()\
                asjdifojasdofijasdoijfoisjf\
                asdfoi
            }
            else {
                // TODO: qsort the key_expressions first before assigning it to the const copy of it.
                switch (sv[-1]) {
                case '#': inComment = true; continue;
                case '\'': inChar = true; continue;
                case '\"': inString = true; continue;
                case ' ':
                case '\t':
                case '\n': sv.truncFront(1); continue;
                }
                // if (sv[-1] == '#')
                //     inComment = true;
                // else if (sv[-1] == '\'')
                //     inChar = true;
                // else if (sv[-1] == '\"')
                //     inString = true;
                // else if (sv[-1] == ' ' || sv[-1] == '\t' || sv[-1] ==)
                if (isNumber(sv[-1]))
                    inNum = true;
                else if (isAlphabet(sv[-1]))
                    inName = true;

                else {

                    // std::size_t index{0};
                    // fi_tmp = found_indexes;
                    fi_tmp.clear();
                    for (std::size_t i{0}; i < keys.size(); ++i) {
                        if (isFirst) {
                            if (sv.match_starting(keys[i])) fi_tmp.push_back(i);
                            continue;
                        }
                        if (found_indexes.find(i) == found_indexes.size()) continue;
                        if (sv.match_starting(keys[i])) fi_tmp.push_back(i);
                        // if(found_indexes.size() > 2)
                        // index = sv.find(keys[i]);
                        // sv == sv;
                        // if (index != sv.find)
                        //     ;
                    }
                    isFirst = false;
                    if (!found_indexes.size()) {
                        bool pushed_back(false);
                        for (std::size_t i{0}; i < found_indexes.size(); ++i) {
                            if (sv == keys[found_indexes[i]]) {
                                parsed_results.push_back(key_expressions_const(found_indexes[i]));
                                break;
                            }
                        }
                        if (!pushed_back) *stderr << "Error: Unrecognized symbol \"" << sv << ".\n";
                    }
                    else if (found_indexes.size() == 1) {
                        parsed_results.push_back(key_expressions_const(found_indexes[0]));
                        isFirst = true;
                        found_indexes.clear();
                    }
                    else {
                        found_indexes = fi_tmp;
                    }
                    // // TODO: continue the above.
                    // TODO: Debug it until it works. Make a writer that covers things in parentheses if out of order.
                    // Make sure right-to-left precedences work as expected.
                }


                // TODO: Finish this: make it find and make sure only one match or less is found. If one found,
                // place and continue. If 0 found, back and if one found from then, place and continue. If more
                // than one found, throw exception.
                // keys[i].find(sv);
            }
            // for ()
            //     ;
            // if () {}
        }
        check(parsed_results, statements);
    }
    Array<Statement> statements;
    /**
     * @brief
     *  Modes:
     *      0 : not in statement
     *      1 : in statement
     *      2 : in preprocessor directive
     */
    Classifier &write(FILE *file) {
        for (size_ut i{0}; i < statements.size(); ++i) { *file << statements[i]; }
        return *this;
    }
};
