#ifndef CFILE_H
#define CFILE_H

#include "stdc++.h"
#include <filesystem>
#include "classifier.h"
#include "misc.h"
#include "utils.h"

extern const char* staticMap(char c);

String escape(const String& input);

class CFile {
protected:
    Array<Classifier::Statement> statements;

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
};

#endif