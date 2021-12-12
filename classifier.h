#ifndef CLASSIFIER_H
#define CLASSIFIER_H

#include "stdc++.h"

#include "array_view.h"
// #include "cfile.h"
#include "dynamic_bitset.h"
#include "utils.h"

class CFile;

typedef Array<Pair<size_ut, size_ut>> ExpressionType;
typedef long long int                 size_ut;

namespace Classifier {
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
        REQUIRE_LVALUE        = (1LL << 53),
        REQUIRE_RVALUE        = (1LL << 54),
        SEMICOLON             = (1LL << 55),
        LITERAL               = (1LL << 56),
        COMMA_AND_NAME        = (1LL << 57),
        COMMA_TYPE_AND_NAME   = (1LL << 58),
        PREFIX                = (1LL << 59),
        POSTFIX               = (1LL << 60),
        BOTH                  = (1LL << 61),
        OPEN                  = (1LL << 62),
        CLOSE                 = (1LL << 63),
    };

    inline bool checkIs(size_ut a, size_ut b) {
        return a & b;
    }
    class Expression {
        bool m_has_parent;
        bool m_in_paren;


    public:
        struct ExpressionStr {
            std::shared_ptr<Expression>  ex;
            Pair<String, ExpressionType> str;
            ExpressionStr(const std::shared_ptr<Expression>& exp) : ex(exp), str() {
            }
            ExpressionStr(const Pair<String, ExpressionType>& string) : ex(nullptr), str(string) {
            }
            ExpressionStr(const ExpressionStr& exp) : ex(exp.ex), str(exp.str) {
            }
            ~ExpressionStr() {
            }

            // friend FILE& operator<<(FILE& out, const ExpressionStr& exp) {
            //     if (exp.ex.get() == nullptr) {
            //         out << exp.str;
            //     }
            // }


            friend FILE& operator<<(FILE& out, const ExpressionStr& exp) {
                if (exp.ex.get() == nullptr) {
                    out << exp.str;
                }
                out << *(exp.ex);
                return out;
            }
            friend std::ostream& operator<<(std::ostream& out, const ExpressionStr& exp) {
                if (exp.ex.get() == nullptr) {
                    out << exp.str;
                }
                out << *(exp.ex);
                return out;
            }


            bool operator==(const ExpressionStr& exp) const {
                return (ex == exp.ex) && (str == exp.str);
            }
            bool operator!=(const ExpressionStr& exp) const {
                return (ex != exp.ex) || (str != exp.str);
            }
            bool operator<(const ExpressionStr& exp) const {
                return (ex.get() < exp.ex.get() ? true : (ex.get() > exp.ex.get() ? false : (str < exp.str)));
            }
            bool operator>(const ExpressionStr& exp) const {
                return (ex.get() > exp.ex.get() ? true : (ex.get() < exp.ex.get() ? false : (str > exp.str)));
            }
            bool operator<=(const ExpressionStr& exp) const {
                return (ex.get() < exp.ex.get() ? true : (ex.get() > exp.ex.get() ? false : (str <= exp.str)));
            }
            bool operator>=(const ExpressionStr& exp) const {
                return (ex.get() > exp.ex.get() ? true : (ex.get() < exp.ex.get() ? false : (str >= exp.str)));
            }
        };

        /**
         * @brief
         * Note: The bool stands for whether the first object in the pair is a expression or a Pair<String,
         * ExpressionType>
         *      true: Expression; false: Pair<String, ExpressionType>
         *
         */

        Array<Pair<ExpressionStr, bool>> subs;


        Expression() : m_has_parent{false}, m_in_paren{false}, subs() {
        }
        Expression(const Expression& exp) : m_has_parent{exp.m_has_parent}, m_in_paren{exp.m_in_paren}, subs(exp.subs) {
        }
        Expression(const Expression* exp) :
            m_has_parent{exp->m_has_parent}, m_in_paren{exp->m_in_paren}, subs(exp->subs) {
        }
        // Expression(const Array<Pair<ExpressionStr, bool>>& ex) : subs(ex) {
        //     for (size_ut i{0}; i < ex.size(); ++i) {
        //         if (ex[i].second) {
        //             ((Expression*)(&(ex[i].first)))->m_has_parent = true;
        //         }
        //     }
        // }
        std::size_t size() const {
            return subs.size();
        }
        Expression& push_back(Pair<ExpressionStr, bool> ex) {
            if (ex.second) {
                ex.first.ex->m_has_parent = true;
            }
            subs.push_back(ex);
            return *this;
        }
        Expression& insert(Pair<ExpressionStr, bool> ex, size_ut index) {
            if (ex.second) {
                ((Expression*)(&(ex.first)))->m_has_parent = true;
            }
            subs.insert(ex, index);
            return *this;
        }

        Expression& pop_back() {
            if (!subs.size())
                *stderr << "Expression already empty.\n";
            if (subs[subs.size() - 1].second) {
                ((Expression*)(&(subs[subs.size() - 1].first)))->m_has_parent = false;
            }
            subs.pop_back();
            return *this;
        }
        Expression& remove(size_ut index) {
            if (index >= subs.size())
                *stderr << "Out of range.\n";
            if (subs[index].second) {
                ((Expression*)(&(subs[index].first)))->m_has_parent = false;
            }
            subs.remove(index, index + 1);
            return *this;
        }


        ExpressionStr& operator[](size_ut index) {
            return subs[index].first;
        }
        Expression& operator=(const Expression& exp) {
            m_has_parent = exp.m_has_parent;
            m_in_paren   = exp.m_in_paren;
            subs         = exp.subs;
            return *this;
        }
        Expression& operator=(const Array<Pair<ExpressionStr, bool>>& ex) {
            for (size_ut i{0}; i < ex.size(); ++i) {
                if (ex[i].second) {
                    ex[i].first.ex->m_has_parent = true;
                }
            }
            return *this;
        }
        bool operator==(const Expression& exp) const {
            return subs == exp.subs;
        }
        bool operator!=(const Expression& exp) const {
            return subs != exp.subs;
        }
        bool operator<(const Expression& exp) const {
            return subs < exp.subs;
        }
        bool operator>(const Expression& exp) const {
            return subs > exp.subs;
        }
        bool operator<=(const Expression& exp) const {
            return subs <= exp.subs;
        }
        bool operator>=(const Expression& exp) const {
            return subs >= exp.subs;
        }
        bool isExpression(size_ut index) const {
            return subs[index].second;
        }
        std::shared_ptr<Expression> indexAsExp(size_ut index) const {
            return (subs[index].first).ex;
        }
        const Pair<String, ExpressionType>& indexAsStr(size_ut index) const {
            return (subs[index].first).str;
        }

    protected:
        friend void _print(FILE& out, const Expression& exp) {
            for (size_ut i{0}; i < exp.subs.size(); ++i) {
                if (exp.isExpression(i)) {
                    // operator<<(out, exp.indexAsExp(i).operator*());
                    out << *(exp.indexAsExp(i));
                }
                else {
                    out << exp.indexAsStr(i) << ' ';
                }
            }
        }
        friend void _print(std::ostream& out, const Expression& exp) {
            for (size_ut i{0}; i < exp.subs.size(); ++i) {
                if (exp.isExpression(i)) {
                    // operator<<(out, exp.indexAsExp(i).operator*());
                    out << *(exp.indexAsExp(i));
                }
                else {
                    out << exp.indexAsStr(i) << ' ';
                    // out << "\" " << exp.indexAsStr(i) << " \"" << ' ';
                }
            }
        }

    public:
        friend FILE& operator<<(FILE& out, const Expression& exp) {
            // for (size_ut i{0}; i < exp.subs.size(); ++i) {
            //     if (exp.isExpression(i)) {
            //         // operator<<(out, exp.indexAsExp(i).operator*());
            //         // out << *exp.indexAsExp(i);
            //     }
            //     else {
            //         out << exp.indexAsStr(i);
            //     }
            // }

            _print(out, exp);
            return out;
        }
        friend std::ostream& operator<<(std::ostream& out, const Expression& exp) {
            // for (size_ut i{0}; i < exp.subs.size(); ++i) {
            _print(out, exp);
            return out;
        }

        Expression& swap(Expression& b) {
            std::swap(this->m_has_parent, b.m_has_parent);
            std::swap(this->m_in_paren, b.m_in_paren);
            Array<Pair<ExpressionStr, bool>>::swap(this->subs, b.subs);
            return *this;
        }


        FILE& write(FILE& out, const Expression& exp /* , bool in_paren = false */) {
            if (m_in_paren)
                out << '(';
            for (size_ut i{0}; i < exp.subs.size(); ++i) {
                if (exp.isExpression(i)) {
                    out << *(exp.indexAsExp(i));
                }
                else {
                    out << exp.indexAsStr(i);
                }
            }
            if (m_in_paren)
                out << ')';
            return out;
        }
    };


    class Statement {
    protected:
    public:
        Expression node;
        Statement() : node() {
        }
        friend FILE& operator<<(FILE& out, const Statement& st) {
            out << st.node;
            return out;
        }

        friend std::ostream& operator<<(std::ostream& out, const Statement& st) {
            out << st.node;
            return out;
        }
        Statement& operator=(const Statement& st) {
            node = st.node;
            return *this;
        }
        bool operator==(const Statement& st) const {
            return node == st.node;
        }
        bool operator!=(const Statement& st) const {
            return node != st.node;
        }
        bool operator<(const Statement& st) const {
            return node < st.node;
        }
        bool operator>(const Statement& st) const {
            return node > st.node;
        }
        bool operator<=(const Statement& st) const {
            return node <= st.node;
        }
        bool operator>=(const Statement& st) const {
            return node >= st.node;
        }
    };

    /**
     * @brief
     *  Array of:
     *      Pairs that contain:
     *          Array of things expected
     *          Pair of:
     *              |CHANGED|
     *              evaluated type (if -1, means dependent on type of function; if
     *              -2, means dependent on type of variable, 1 means returns a type, 0 means no return, 2 means
     *              literal)
     *              |/CHANGED|
     *              |NEW|
     *              evaluated type (Use the STypes enum that it should represent.)
     *              |/NEW|
     * id of statement type Note: STypes stands for Statement Types Upon seing anything with return
     * value with higher level of precedence, evaluate it first. Note: Support for default-int
     *
     *
     *
     *
     *  NOTE:
     *      The second one in the Pair is the precedence (all are different) (higher means gets parsed first)
     */

    extern Array<Pair<Array<Pair<Array<size_ut>, size_ut>>, Pair<size_ut, size_ut>>> statement_types_arrays;
    extern Array<Pair<Array<size_ut>, Pair<size_ut, size_ut>>>                       statement_types;
    extern Array<Pair<String, size_ut>>                                              type_modifier_order;
    extern Map<String, Array<Pair<size_ut, size_ut>>>                                key_expressions;

    typedef Pair<String, ExpressionType>* ExpTypePtr;


    int                                               compare(const void* a, const void* b);
    extern Map<String, Array<Pair<size_ut, size_ut>>> key_expressions_const;

    /**
     * @brief
     * this func checks if the group of STypes combinations can fit into the combination in b;
     * eg.) a = FuncName, ParenOpen, STypes::Literal, STypes::Comma, STypes::Literal, ParenClose, ; b =
     * STypes::Literal | STypes::Comma, STypes::MULTIPLE, STypes::OPTIONAL
       if mode is 1, then also add the things parsed into the
       @brief:
        the return of matchExact:
            0: not matched
           -1: matched so far but not complete
            1: matched and completed
     */

    // short int matchExact(
    //     const Array_view<Pair<String, Array<Pair<size_ut, size_ut>>>>& a, size_ut precedence, size_ut index1,
    //     size_ut index2);
    // short int parseArray(
    //     const Array_view<Pair<String, Array<Pair<size_ut, size_ut>>>>& a, size_ut index,
    //     size_ut operator_precedence_level = 0LL);
    short int parseArray(
        Array<Pair<String, Array<Pair<size_ut, size_ut>>>>& a, size_ut index,
        size_ut operator_precedence_level /*  = 0LL */, CFile& cfile);
    std::tuple<short int, size_ut> matchExact(
        const Array_view<Pair<String, Array<Pair<size_ut, size_ut>>>>& a, size_ut precedence, size_ut index1,
        /* size_ut index2,  */ CFile& cfile);
    /**
     * @brief
     * the parameter a is the list of the things in the parsed statement.
     */

    bool check(Array<Pair<String, Array<Pair<size_ut, size_ut>>>>& a, Array<Statement>& arr_statements, CFile& cfile);

#undef set
};// namespace Classifier

#endif// CLASSIFIER_H