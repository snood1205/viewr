#ifndef PANDOC_H
#define PANDOC_H "pandoc.h"
int convert(char*, char*);
void list_formats(void);
char valid_convert(FileType, FileType);
#endif
