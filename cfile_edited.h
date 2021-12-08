#include "stdc++.h"
#include <filesystem>
#include "classifier.h"
#include "misc.h"
#include "utils.h"

const char* staticMap(char c) {
    switch (c) {
    case '\a':
        return "\\a";
    case '\b':
        return "\\b";
    case '\t':
        return "\\t";
    case '\n':
        return "\\n";
    case '\v':
        return "\\v";
    case '\f':
        return "\\f";
    case '\r':
        return "\\r";

    case '\"':
        return "\\\"";
    case '\'':
        return "\\\'";
    case '\?':
        return "\\\?";
    case '\\':
        return "\\\\";
    }
    return nullptr;
}

String escape(const String& input) {
    std::stringstream ss;
    for (char c : input) {
        const char* str = staticMap(c);
        if (str) {
            ss << str;
        }
        else if (!isprint(static_cast<unsigned char>(c))) {
            ss << "\\u" << std::hex << std::setfill('0') << std::setw(4)
               << (static_cast<unsigned int>(static_cast<unsigned char>(c)));
        }
        else {
            ss << c;
        }
    }
    return ss.str().c_str();
}

class CFile {
protected:
    Array<Classifier::Statement> statements;

public:
    CFile(const String& filename) {
        if (!(std::filesystem::exists(filename.cStr().get()))) {
            *stdout << "File does not exist.\n";
        }
        else {
            // FILE* file{fopen(filename.cStr().get(), "")};
            // parse(file);
            // fclose(file);
            std::fstream file(filename.cStr().get(), std::fstream::in);
            parse(file);
        }
    }
    void parse(std::fstream& file) {
        Array<Pair<String, Array<Pair<size_ut, size_ut>>>> container{};
        String                                             str{};
        int                                                c;
        // std::stringstream                                  ss{};
        // ss << container;
        Array<Classifier::Statement>                       stm{};
        Array<size_ut>                                     exp{};
        bool                                               ws{false}, wsp{false};
        short int                                          mode{0};
        bool                                               end_of_term;
        size_ut                                            find_result{0LL};
        Array<Pair<String, Array<Pair<size_ut, size_ut>>>> parsed_results{};
        str << file;
        std::cout << escape(str) << '\n';
        std::cout.flush();
        String_view sv{str};
        sv.setView(0, 0);
        bool           wasChar{false}, isChar{false};
        Array<String>  keys{Classifier::key_expressions_const.keys()};
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
            std::cout << "\"\n" << escape(String(sv)) << "\n\"\n\n";
            std::cout.flush();
            isAn = isAlnum(sv[sv.size() - 1]);
            // Restart:
            if (wasAn && isAn)
                continue;
            if (inString) {
                if (indFB(0) == '\"' && indFB(1) != '\\')
                    parsed_results.push_back(Pair<String, Array<Pair<size_ut, size_ut>>>{
                        String(sv), {Pair<size_ut, size_ut>(Classifier::STypes::LITERAL, 0)}});
                sv.truncFront(sv.size());
                inString = false;
            }
            else if (inChar) {
                if (indFB(0) == '\'' && indFB(1) != '\\') {
                    parsed_results.push_back(Pair<String, Array<Pair<size_ut, size_ut>>>{
                        String(sv), {Pair<size_ut, size_ut>(Classifier::STypes::LITERAL, 0)}});
                    sv.truncFront(sv.size());
                    inChar = false;
                }
            }
            else if (inNum) {
                sv.truncBack(1);
                parsed_results.push_back(Pair<String, Array<Pair<size_ut, size_ut>>>{
                    String(sv), {Pair<size_ut, size_ut>(Classifier::STypes::LITERAL, 0)}});
                sv.truncFront(sv.size());
                isAn  = true;
                inNum = false;
                --i;
            }
            else if (inName) {
                sv.truncBack(1);
                parsed_results.push_back(Pair<String, Array<Pair<size_ut, size_ut>>>{
                    String(sv), {Pair<size_ut, size_ut>(Classifier::STypes::NAME, 0)}});
                sv.truncFront(sv.size());
                isAn   = true;
                inName = false;
                --i;
            }
            else if (inComment) {
                if (indFB(0) == '\n' && indFB(1) != '\\') {
                    sv.truncFront(sv.size());
                    inComment = false;
                }
            }
            else {
                switch (sv[-1]) {
                case '#':
                    inComment = true;
                    continue;
                case '\'':
                    inChar = true;
                    continue;
                case '\"':
                    inString = true;
                    continue;
                case ' ':
                case '\t':
                case '\n':
                    sv.truncFront(1);
                    continue;
                }
                if (isNumber(sv[-1]))
                    inNum = true;
                else {

                    fi_tmp.clear();
                    bool found(false);
                    for (std::size_t i{0}; i < keys.size(); ++i) {
                        if (isFirst) {
                            if (sv.match_starting(keys[i]))
                                fi_tmp.push_back(i);
                            continue;
                        }
                        if (found_indexes.find(i) == found_indexes.size())
                            continue;
                        if (sv.match_starting(keys[i]))
                            fi_tmp.push_back(i);
                    }
                    isFirst = false;
                    if (!found_indexes.size()) {
                        bool pushed_back(false);
                        for (std::size_t i{0}; i < found_indexes.size(); ++i) {
                            if (sv == keys[found_indexes[i]]) {
                                parsed_results.push_back(Classifier::key_expressions_const(found_indexes[i]));
                                break;
                            }
                        }
                        if (!pushed_back) {
                            if (isAlphabet(sv[-1])) {
                                inName = true;
                                // goto Restart;
                                // sv.truncBack(1);
                            }
                            else {

                                *stderr << "Error: Unrecognized symbol \"" << sv << ".\n";
                            }
                        }
                        else if (found_indexes.size() == 1) {
                            parsed_results.push_back(Classifier::key_expressions_const(found_indexes[0]));
                            isFirst = true;
                            found_indexes.clear();
                        }
                        else {
                            found_indexes = fi_tmp;
                        }
                    }
                }
            }
            std::cout << parsed_results;
            std::cout.flush();
            Classifier::check(parsed_results, statements);

#undef indFB
        }
        void parse(FILE * file) {
            Array<Pair<String, Array<Pair<size_ut, size_ut>>>> container{};
            String                                             str{};
            int                                                c;
            std::stringstream                                  ss{};
            ss << container;
            Array<Classifier::Statement>                       stm{};
            Array<size_ut>                                     exp{};
            bool                                               ws{false}, wsp{false};
            short int                                          mode{0};
            bool                                               end_of_term;
            size_ut                                            find_result{0LL};
            Array<Pair<String, Array<Pair<size_ut, size_ut>>>> parsed_results{};
            str << *file;
            String_view sv{str};
            sv.setView(0, 0);
            bool           wasChar{false}, isChar{false};
            Array<String>  keys{Classifier::key_expressions_const.keys()};
            Array<size_ut> inserted_indexes{};
            size_ut        ind;
            Bitset<>       bs(str.size(), 0);
            size_ut        matched_index{-1};
            bool           wasAn{false}, isAn{false}, inString{false}, inChar{false}, inNum{false}, inName{false},
                inComment{false};
            // Note: stands for indexes from back

            // For lines 1484:
            Array<size_t> found_indexes{}, fi_tmp{};

            bool isFirst(true);

#define indFB(arg) sv[sv.size() - (arg + 1)]
            for (std::size_t i(0); i < str.size(); ++i, wasAn = isAn) {
                sv.extendBack(1);
                isAn = isAlnum(sv[sv.size() - 1]);
                if (wasAn && isAn)
                    continue;
                if (inString) {
                    if (indFB(0) == '\"' && indFB(1) != '\\')
                        parsed_results.push_back(Pair<String, Array<Pair<size_ut, size_ut>>>{
                            String(sv), {Pair<size_ut, size_ut>(Classifier::STypes::LITERAL, 0)}});
                    sv.truncFront(sv.size());
                    inString = false;
                }
                else if (inChar) {
                    if (indFB(0) == '\'' && indFB(1) != '\\') {
                        parsed_results.push_back(Pair<String, Array<Pair<size_ut, size_ut>>>{
                            String(sv), {Pair<size_ut, size_ut>(Classifier::STypes::LITERAL, 0)}});
                        sv.truncFront(sv.size());
                        inChar = false;
                    }
                }
                else if (inNum) {
                    sv.truncBack(1);
                    parsed_results.push_back(Pair<String, Array<Pair<size_ut, size_ut>>>{
                        String(sv), {Pair<size_ut, size_ut>(Classifier::STypes::LITERAL, 0)}});
                    sv.truncFront(sv.size());
                    isAn  = true;
                    inNum = false;
                    --i;
                }
                else if (inName) {
                    sv.truncBack(1);
                    parsed_results.push_back(Pair<String, Array<Pair<size_ut, size_ut>>>{
                        String(sv), {Pair<size_ut, size_ut>(Classifier::STypes::LITERAL, 0)}});
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
                }
                else {
                    switch (sv[-1]) {
                    case '#':
                        inComment = true;
                        continue;
                    case '\'':
                        inChar = true;
                        continue;
                    case '\"':
                        inString = true;
                        continue;
                    case ' ':
                    case '\t':
                    case '\n':
                        sv.truncFront(1);
                        continue;
                    }
                    if (isNumber(sv[-1]))
                        inNum = true;
                    else if (isAlphabet(sv[-1]))
                        inName = true;

                    else {

                        fi_tmp.clear();
                        for (std::size_t i{0}; i < keys.size(); ++i) {
                            if (isFirst) {
                                if (sv.match_starting(keys[i]))
                                    fi_tmp.push_back(i);
                                continue;
                            }
                            if (found_indexes.find(i) == found_indexes.size())
                                continue;
                            if (sv.match_starting(keys[i]))
                                fi_tmp.push_back(i);
                        }
                        isFirst = false;
                        if (!found_indexes.size()) {
                            bool pushed_back(false);
                            for (std::size_t i{0}; i < found_indexes.size(); ++i) {
                                if (sv == keys[found_indexes[i]]) {
                                    parsed_results.push_back(Classifier::key_expressions_const(found_indexes[i]));
                                    break;
                                }
                            }
                            if (!pushed_back)
                                *stderr << "Error: Unrecognized symbol \"" << sv << ".\n";
                        }
                        else if (found_indexes.size() == 1) {
                            parsed_results.push_back(Classifier::key_expressions_const(found_indexes[0]));
                            isFirst = true;
                            found_indexes.clear();
                        }
                        else {
                            found_indexes = fi_tmp;
                        }
                    }
                }
            }
            std::cout << parsed_results;
            Classifier::check(parsed_results, statements);

#undef indFB
        }
        /**
         * @brief
         *  Modes:
         *      0 : not in statement
         *      1 : in statement
         *      2 : in preprocessor directive
         */
        void write(FILE * file) {
            for (Classifier::Statement& i : statements) {
                *file << i;
            }
        }
    };