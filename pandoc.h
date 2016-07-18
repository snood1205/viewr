#ifndef PANDOC_H
#define PANDOC_H "pandoc.h"

#include "filetype.h"
#include "string.h"
#include <stdlib.h>

int convert(char *, char *);

void list_formats(void);

char valid_convert(FileType *, FileType *);

#endif
