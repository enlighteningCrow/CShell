#include "utils.h"

#include <pstreams/pstream.h>
#include "cfile.h"
#include "classifier.h"
#include "misc.h"

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

CFile::CFile(const String& filename) {
    std::filesystem::path path(filename.cStr().get());
    if (!(std::filesystem::exists(path))) {
        *stdout << "File does not exist.\n";
    }
    else {
        std::fstream file(path.c_str(), std::fstream::in);
        parse(file);
    }
}

void CFile::parse(std::fstream& file) {
    String                                             previous_string;
    Array<Pair<String, Array<Pair<size_ut, size_ut>>>> container{};
    String                                             str{};
    int                                                c;
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
    // Note: was/is An : was/is Alphanumeric
    bool wasAn{false}, isAn{false}, inString{false}, inChar{false}, inNum{false}, inName{false}, inComment{false},
        inWord{false}, inSymbol{false};
    // Note: stands for indexes from back

    // For lines 1484:
    Array<size_t> found_indexes_previous{}, found_indexes_current{};

    bool isFirst(true), inNothing(true);
    previous_string = "";

#define indFB(arg) sv[sv.size() - (arg + 1)]
    for (std::size_t i(0); sv.remainingBack(); ++i, wasAn = isAn, previous_string = sv.str()) {
        sv.extendBack(1);
        std::cout << "\"\n" << escape(String(sv)) << "\n\"\n\n";
        std::cout.flush();
        isAn   = isAlnum(sv[sv.size() - 1]);
        auto s = sv.str().toStdString();
        if (wasAn && isAn)
            continue;
        if (inString) {
            if (indFB(0) == '\"' && indFB(1) != '\\') {
                parsed_results.push_back(Pair<String, Array<Pair<size_ut, size_ut>>>{
                    String(sv), {Pair<size_ut, size_ut>(Classifier::STypes::LITERAL, 0)}});
                sv.truncFront(sv.size());
                inString  = false;
                inNothing = true;
            }
            continue;
        }
        else if (inChar) {
            if (indFB(0) == '\'' && indFB(1) != '\\') {
                parsed_results.push_back(Pair<String, Array<Pair<size_ut, size_ut>>>{
                    String(sv), {Pair<size_ut, size_ut>(Classifier::STypes::LITERAL, 0)}});
                sv.truncFront(sv.size());
                inChar    = false;
                inNothing = true;
            }
            continue;
        }
        else if (inNum) {
            sv.truncBack(1);
            parsed_results.push_back(Pair<String, Array<Pair<size_ut, size_ut>>>{
                String(sv), {Pair<size_ut, size_ut>(Classifier::STypes::LITERAL, 0)}});
            sv.truncFront(sv.size());
            isAn      = true;
            inNum     = false;
            inNothing = true;
            --i;
            continue;
        }
        else if (inName) {
            sv.truncBack(1);
            s = sv.str().toStdString();
            if (sv == "typedef") {
                while (sv[-1] != ';') {
                    sv.extendBack(1);
                    s = sv.str().toStdString();
                }
                for (size_ut i{1};; ++i) {
                    if (sv[-i] == ' ') {
                        sv.truncFront(sv.size() - i + 1);
                        sv.truncBack(1);
                        s = sv.str().toStdString();
                        break;
                    }
                }
                Classifier::key_expressions_const.insert(
                    Pair<String, ExpressionType>(String(sv), {Pair<size_ut, size_ut>(Classifier::STypes::TYPE, 0)}));
                keys = Classifier::key_expressions_const.keys();
            }
            else {
                parsed_results.push_back(Pair<String, Array<Pair<size_ut, size_ut>>>{
                    String(sv), {Pair<size_ut, size_ut>(Classifier::STypes::NAME, 0)}});
                all.push_back(Pair<String, Array<Pair<String, size_ut>>>(String(sv), Classifier::STypes::NAME));
            }
            sv.truncFront(sv.size());
            isAn      = true;
            inName    = false;
            inNothing = true;
            --i;
            continue;
        }
        else if (inComment) {
            if (indFB(0) == '\n' && indFB(1) != '\\') {
                sv.truncFront(sv.size());
                inComment = false;
                inNothing = true;
                continue;
            }
        }
        else if (inWord) {
            sv.truncBack(1);
            found_indexes_current.clear();
            s = sv.str().toStdString();
            for (std::size_t i{0}; i < keys.size(); ++i) {
                if (sv == keys[i])
                    found_indexes_current.push_back(i);
            }
            if (!found_indexes_current.size()) {
                inName = true;
                inWord = false;
                continue;
            }
            else if (found_indexes_current.size() == 1) {
                std::cout << "\"\n" << sv << "\n\"";
                parsed_results.push_back(Classifier::key_expressions_const(found_indexes_current[0]));
                sv.truncFront(sv.size());
                inWord    = false;
                isFirst   = true;
                inNothing = true;
                continue;
            }
        }
        else {
            if (inNothing) {
                switch (sv[-1]) {
                case '#':
                case '/':
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
                default:
                    break;
                }
            }
            inNothing = false;
            if (isNumber(sv[-1]))
                inNum = true;
            else if (isAlphabet(sv[0])) {
                inWord = true;
                continue;
            }
            else {
                inSymbol = true;
            }
        }
        if (inSymbol) {
            found_indexes_current.clear();
            if (isFirst) {
                found_indexes_previous.clear();
                for (std::size_t i{0}; i < keys.size(); ++i) {
                    if (sv.match_starting(keys[i]))
                        found_indexes_current.push_back(i);
                }
            }
            else {
                for (std::size_t i{0}; i < keys.size(); ++i) {
                    if (found_indexes_previous.find(i) == found_indexes_previous.size())
                        continue;
                    if (sv.match_starting(keys[i]))
                        found_indexes_current.push_back(i);
                }
            }
            isFirst = false;
            if (!found_indexes_current.size()) {
                bool pushed_back(false);
                for (std::size_t i{0}; i < found_indexes_previous.size(); ++i) {
                    if (previous_string == keys[found_indexes_previous[i]]) {
                        pushed_back = true;
                        parsed_results.push_back(Classifier::key_expressions_const(found_indexes_previous[i]));
                        sv.truncBack(1);
                        sv.truncFront(sv.size());
                        inSymbol  = false;
                        isFirst   = true;
                        inNothing = true;
                        break;
                    }
                }
                if (!pushed_back) {
                    *stderr << "Error: Unrecognized symbol \"" << sv << "\".\n";
                }
            }
            else if (found_indexes_current.size() == 1) {
                std::cout << "\"\n" << sv << "\n\"";
                parsed_results.push_back(Classifier::key_expressions_const(found_indexes_current[0]));
                sv.truncFront(sv.size());
                inSymbol  = false;
                isFirst   = true;
                inNothing = true;
                found_indexes_previous.clear();
            }
            else {
                found_indexes_previous = found_indexes_current;
            }
        }
    }
    std::cout << parsed_results;
    std::cout.flush();
    Classifier::check(parsed_results, statements, *this);
    std::cout << '\n' << statements << std::endl;
    std::cout << "it is done DEBUG";

#undef indFB
    std::ofstream ff{
        "/home/twistingcamel/programs/kmitl/c++/cshell/main/CShell/testoutputfile.c", std::ofstream::trunc};
    std::cout << "\n\n\n";
    write(ff);
}

/**
 * @brief
 *  Modes:
 *      0 : not in statement
 *      1 : in statement
 *      2 : in preprocessor directive
 */
void CFile::write(FILE* file) {
    for (Classifier::Statement& i : statements) {
        *file << i;
    }
}

void CFile::write(std::ostream& file) {
    for (Classifier::Statement& i : statements) {
        i.write(file);
        // file << i;
    }
    file.flush();
}