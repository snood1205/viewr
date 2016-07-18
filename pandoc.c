#include "pandoc.h"

int convert(char *from, char *to) {
    FileType *a, *b;
    char call[200];
    strcpy(call, "pandoc ");
    a = detect_type(from);
    b = detect_type(to);
    if (valid_convert(a, b)) {
        strcat(call, "-s ");
        strcat(call, strip_name(from));
        strcat(call, " -o ");
        strcat(call, to_string(to, b));
        return system(call);
    }
    return 1;
}

char valid_convert(FileType *from, FileType *to) {
    if (equals(from, to))
        return 0;
    return 1;
}
