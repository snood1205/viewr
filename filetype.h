#ifndef FILETYPE_H
#define FILETYPE_H "filetype.h"
typedef struct FileType FileType;
FileType * file_type_new(char *, char *, char);
FileType * detect_type(char *);
char * get_suffix(char *);
#endif
