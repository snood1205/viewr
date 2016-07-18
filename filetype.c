#include "filetype.h"

typedef struct FileType
{
    ///////////////////////////////////////////////////////////////////
    // This type-struct is for FileType.                             //
    // attributes :                                                  //
    // - name (char[20]) : the name of the FileType                  //
    // - extension (char[10]) : the file extension                   //
    // - markdown_flavor (char) : if the FileType is a markdown      //
    // flavor.                                                       //
    ///////////////////////////////////////////////////////////////////

    char name[20];
    char extension[10];
    char markdown_flavor;
} FileType;

FileType *file_type_new(char *name, char *extension, char markdown_flavor) {
    ///////////////////////////////////////////////////////////////////
    // This function is, for all intents and purposes, the           //
    // constructor for FileType.                                     //
    // params:                                                       //
    // - name (char *) : the name to set                             //
    // - extension (char *) : the extension to set                   //
    // - markdown_flavor (char) : set if it is a markdown flavor     //
    // returns:                                                      //
    // - (FileType *) : pointer to newly constructed FileType        //
    ///////////////////////////////////////////////////////////////////

    FileType *a;
    if ((a = malloc(sizeof *a)) != NULL) {
        strcpy(a->name, name);
        strcpy(a->extension, extension);
        a->markdown_flavor = markdown_flavor;
    }
    return a;
}

FileType *detect_type(char *filename) {
    ///////////////////////////////////////////////////////////////////
    // This function returns a pointer to the FileType parsed from   //
    // the filename passed to the function.                          //
    // params :                                                      //
    // - filename (char *) : the file name to parse                  //
    // returns :                                                     //
    // - (FileType *) : the file type parsed                         //
    ///////////////////////////////////////////////////////////////////

    char *suffix;
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

char *get_suffix(char *filename) {
    ///////////////////////////////////////////////////////////////////
    // This function takes a file name and returns the file          //
    // extensions for the file.                                      //
    // params :                                                      //
    // - filename (char *) : the filename to parse                   //
    // returns :                                                     //
    // - (char *) : the file extension                               //
    ///////////////////////////////////////////////////////////////////

    int i, j;
    char in_suffix;
    static char a[10];
    in_suffix = 0;
    j = 0;
    for (i = 0; i < sizeof(filename) / sizeof(char); i++) {
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

char equals(const FileType *lhs, const FileType *rhs) {
    ///////////////////////////////////////////////////////////////////
    // This function equals checks if two FileTypes are shallowly    //
    // equal to each other. This means that their names are the same //
    // and that if one is a markdown flavor, so is the other. This   //
    // does not compare file extensions, and intentionally so. The   //
    // function that compares file extensions as well is             //
    // deep_equals(const FileType *, const FileType *).              //
    // params :                                                      //
    // - lhs (const FileType *) : the left hand side to compare      //
    // - rhs (const FileType *) : the right hand side to compare     //
    // returns :                                                     //
    // - (char) : 0 if they are not equal, 1 if they are equal       //
    ///////////////////////////////////////////////////////////////////

    if (lhs->markdown_flavor != rhs->markdown_flavor)
        return 0;
    if (strncmp(lhs->name, rhs->name, 50))
        return 1;
    return 0;
}

char *strip_name(char *filename) {
    int i;
    char a[sizeof(filename)];
    for (i = 0; filename[i] != '.'; i++)
        a[i] = filename[i];
    return a;
}

char *to_string(char *name, FileType *type) {
    char a[1000];
    strcat(a, name);
    strcat(a, ".");
    strcat(a, type->name);
    return a;
}