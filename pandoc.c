#include "pandoc.h"
#define MAX_LEN 100

int convert(char *from, char *to) {
    ///////////////////////////////////////////////////////////////////
    // This function converts a file from one format to another.     //
    ///////////////////////////////////////////////////////////////////
    
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

void list_formats(void) {
    // TODO: Fill in array
    int i;
    char formats[MAX_LEN][40];
    for (i = 0; i < 40; i++) {
        printf("%s\n", formats[i]);
    }
}