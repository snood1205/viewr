#include "filetype.h"
#include <stdlib.h>
#include <string.h>

typedef struct FileType {
    char    name[20];
    char    extension[10];
    char    markdown_flavor;
} FileType;

FileType * file_type_new(char * name, char * extension, char markdown_flavor)
{
    FileType * a;
    if ((a = malloc(sizeof * a)) != NULL) {
        strcpy(a->name, name);
        strcpy(a->extension, extension);
        a->markdown_flavor = markdown_flavor;
    }
    return a;
}

FileType * detect_type(char * filename)
{
    char * suffix;
    suffix = get_suffix(filename);
    if (strncmp(suffix, "md", 50)
        || strncmp(suffix, "mdown", 50)
        || strncmp(suffix, "markdown", 50))
        return file_type_new("Markdown", suffix, 1);
    if (strncmp(suffix, "textile", 50))
        return file_type_new("Textile", suffix, 0);
    if (strncmp(suffix, "rst", 50))
        return file_type_new("reStructuredText", suffix, 0);
    if (strncmp(suffix, "html", 50) || strncmp(suffix, "php", 50))
        return file_type_new("HTML", suffix, 0);
    if (strncmp(suffix, "tex", 50))
        return file_type_new("LaTeX", suffix, 0);
    if (strncmp(suffix, "mw", 50))
        return file_type_new("MediaWiki", suffix, 0);
    if (strncmp(suffix, "tw", 50))
        return file_type_new("TWiki", suffix, 0);
    if (strncmp(suffix, "hd", 50))
        return file_type_new("Haddock", suffix, 0);
    if (strncmp(suffix, "opml", 50))
        return file_type_new("OPML", suffix, 0);
    if (strncmp(suffix, "dbk", 50))
        return file_type_new("DockBook", suffix, 0);
    if (strncmp(suffix, "odt", 50) || strncmp(suffix, "fodt", 50))
        return file_type_new("OpenDocument", suffix, 0);
    if (strncmp(suffix, "epub", 50))
        return file_type_new("Epub", suffix, 0);
    if (strncmp(suffix, "docx", 50) || strncmp(suffix, "doc", 50))
        return file_type_new("Word Doc", suffix, 0);
    return file_type_new("NULL", suffix, 0);
}

char * get_suffix(char * filename)
{
    int i, j;
    char in_suffix;
    static char a[10];
    in_suffix = 0;
    j = 0;
    for (i = 0; i < sizeof(filename)/sizeof(char); i++) {
        if (in_suffix) {
            a[j] = filename[i];
            j++;
        }
        if (a[i] == '.') {
            in_suffix = 1;
        }
    }
    a[i] = '\0';
    return a;
}

char equals(const FileType * lhs, const FileType * rhs)
{
    if (lhs->markdown_flavor != rhs->markdown_flavor
        || sizeof(lhs->name) != sizeof(rhs->name))
        return 0;
    if(strncmp(lhs->name, rhs->name, 50))
        return 1;
    return 0;
}
