#ifndef FILETYPE_H
#define FILETYPE_H "filetype.h"
#include <stdlib.h>
#include <string.h>
typedef struct FileType FileType;
FileType * file_type_new(char *, char *, char);
FileType * detect_type(char *);
char * get_suffix(char *);
char equals(const FileType *, const FileType *);
char * strip_name(char *);
char * to_string(char *, FileType *);
#endif
