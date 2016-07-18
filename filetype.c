#include "filetype.h"

typedef struct FileType {
    char    name[20];
    char    extension[10];
    char    markdown_flavor;
} FileType;

FileType * file_type_new(char * name, char * extension, char markdown_flavor)
{
    FileType * a;
    if (a = malloc(sizeof * a) != NULL) {
        a->name = name;
        a->extension = extension;
        a->markdown_flavor = markdown_flavor;
    }
    return a;
}

FileType * detect_type(char * filename)
{
    char * suffix;
    suffix = get_suffix(filename);
    switch (suffix) {
        case "md":
        case "mdown":
        case "markdown":
            return file_type_new("Markdown", suffix, 1);
        case "textile":
            return file_type_new("Textile", suffix, 0);
        case "rst":
            return file_type_new("reStructuredText", suffix, 0);
        case "html":
        case "php":
            return file_type_new("HTML", suffix, 0);
        case "tex":
            return file_type_new("LaTeX", suffix, 0);
        case "mw":
            return file_type_new("MediaWiki", suffix, 0);
        case "tw":
            return file_type_new("TWiki", suffix, 0);
        case "hd":
            return file_type_new("Haddock", suffix, 0);
        case "opml":
            return file_type_new("OPML", suffix, 0);
        case "dbk":
            return file_type_new("DockBook", suffix, 0);
        case "odt":
        case "fodt":
            return file_type_new("OpenDocument", suffix, 0);
        case "epub":
            return file_type_new("Epub", suffix, 0);
        case "docx":
        case "doc":
            return file_type_new("Word Doc", 0);
        default:
            return file_type_new("NULL", suffix, 0);
    }
}

char * get_suffix(char * filename)
{
    int i, j;
    char in_suffix;
    char a[10];
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
    return * a;
}
