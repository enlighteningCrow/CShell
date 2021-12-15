#ifndef CFILE_H
#define CFILE_H

#include <filesystem>
#include "classifier.h"
#include "misc.h"
#include "stdc++.h"
#include "utils.h"

extern const char* staticMap(char c);

typedef Array<Pair<String, Array<Pair<String, size_ut>>>> InfoType;

String escape(const String& input);

class CFile {
public:
    Array<Classifier::Statement> statements;
    Array<String>                names;
    InfoType                     variables;
    InfoType                     functions;
    InfoType                     all;

public:
    CFile(const String& filename);
    void parse(std::fstream& file);
    void parse(FILE* file);
    /**
     * @brief
     *  Modes:
     *      0 : not in statement
     *      1 : in statement
     *      2 : in preprocessor directive
     */
    void write(FILE* file);
    void write(std::ostream& file);
};

#endif