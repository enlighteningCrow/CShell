// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int main(int argc, char* argv[]) {

//     typedef const char* cdefghijklmnopqrstuvwxyz;

//     char                     str[100] = "Hello World!";
//     cdefghijklmnopqrstuvwxyz str2     = "from str's";
//     cdefghijklmnopqrstuvwxyz str3     = strcat(str, str2);
//     fprintf(stdout, "Hellos from:\n\ts1:\t%s\n\ts2:\t%s\n\tstrcat:\t%s\n", str, str2, str3);
//     1;
// }

// #include <stdio.h>
// #include <string.h>

// int main(int argc, char* argv[]) {

//     // char a[100] = "Hello World!";
//     printf("%s", a);
// }

#include "utils.h"

#include "utils.cpp"

char a[10]  = "nooooooo";
char b[330] = "d";


int main() {
    Array<int> a{1, 2, 3, 4, 5};
    Array<int> b{5, 6, 7};
    Array<int>::swap(a, b);
    return 0;
}