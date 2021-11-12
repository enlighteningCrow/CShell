#include "file_io.h"

FILE &operator<<(FILE &out, const char *ch) {
    fputs(ch, &out);
    return out;
}

FILE &operator<<(FILE &out, char c) {
    fputc(c, &out);
    return out;
}

FILE &operator<<(FILE &out, int ch) {
    fprintf(&out, "%d", ch);
    return out;
}

FILE &operator<<(FILE &out, unsigned int ch) {
    fprintf(&out, "%u", ch);
    return out;
}

FILE &operator<<(FILE &out, float ch) {
    fprintf(&out, "%f", ch);
    return out;
}

FILE &operator<<(FILE &out, double ch) {
    fprintf(&out, "%lf", ch);
    return out;
}

FILE &operator<<(FILE &out, long double ch) {
    fprintf(&out, "%Lf", ch);
    return out;
}

FILE &operator<<(FILE &out, short int ch) {
    fprintf(&out, "%hd", ch);
    return out;
}

FILE &operator<<(FILE &out, unsigned short int ch) {
    fprintf(&out, "%hu", ch);
    return out;
}

FILE &operator<<(FILE &out, long int ch) {
    fprintf(&out, "%ld", ch);
    return out;
}

FILE &operator<<(FILE &out, unsigned long int ch) {
    fprintf(&out, "%lu", ch);
    return out;
}

FILE &operator<<(FILE &out, long long int ch) {
    fprintf(&out, "%lld", ch);
    return out;
}

FILE &operator<<(FILE &out, unsigned long long int ch) {
    fprintf(&out, "%llu", ch);
    return out;
}


/* _IO_FILE &operator<<(_IO_FILE &out, const char *ch) {
    fputs(ch, &out);
    return out;
}

_IO_FILE &operator<<(_IO_FILE &out, char c) {
    fputc(c, &out);
    return out;
}

_IO_FILE &operator<<(_IO_FILE &out, int ch) {
    fprintf(&out, "%d", ch);
    return out;
}

_IO_FILE &operator<<(_IO_FILE &out, unsigned int ch) {
    fprintf(&out, "%u", ch);
    return out;
}

_IO_FILE &operator<<(_IO_FILE &out, float ch) {
    fprintf(&out, "%f", ch);
    return out;
}

_IO_FILE &operator<<(_IO_FILE &out, double ch) {
    fprintf(&out, "%lf", ch);
    return out;
}

_IO_FILE &operator<<(_IO_FILE &out, long double ch) {
    fprintf(&out, "%Lf", ch);
    return out;
}

_IO_FILE &operator<<(_IO_FILE &out, short int ch) {
    fprintf(&out, "%hd", ch);
    return out;
}

_IO_FILE &operator<<(_IO_FILE &out, unsigned short int ch) {
    fprintf(&out, "%hu", ch);
    return out;
}

_IO_FILE &operator<<(_IO_FILE &out, long int ch) {
    fprintf(&out, "%ld", ch);
    return out;
}

_IO_FILE &operator<<(_IO_FILE &out, unsigned long int ch) {
    fprintf(&out, "%lu", ch);
    return out;
}

_IO_FILE &operator<<(_IO_FILE &out, long long int ch) {
    fprintf(&out, "%lld", ch);
    return out;
}

_IO_FILE &operator<<(_IO_FILE &out, unsigned long long int ch) {
    fprintf(&out, "%llu", ch);
    return out;
} */

// int main(void) { *stdout << "HELLOSSSSS"; }