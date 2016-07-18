#include "filetype.h"

typedef struct FileType {
    char    name[5];
    char     markdown_flavor;
} FileType;

FileType * file_type_new(char * name, char markdown_flavor)
{
    FileType * a;
    if (a = malloc(sizeof * a) != NULL) {
        a->name = name;
        a->markdown_flavor = markdown_flavor;
    }
    return a;
}
/*
. It can read Markdown, Textile, reStructuredText, HTML, LaTeX, MediaWiki markup, TWiki markup, Haddock markup, OPML, Emacs Org mode, DocBook, txt2tags, EPUB, ODT and Word docx; and it can write plain text, Markdown, CommonMark, PHP Markdown Extra, GitHub-Flavored Markdown, MultiMarkdown, reStructuredText, XHTML, HTML5, LaTeX (including beamer slide shows), ConTeXt, RTF, OPML, DocBook, OpenDocument, ODT, Word docx, GNU Texinfo, MediaWiki markup, DokuWiki markup, ZimWiki markup, Haddock markup, EPUB (v2 or v3), FictionBook2, Textile, groff man pages, Emacs Org mode, AsciiDoc, InDesign ICML, TEI Simple, and Slidy, Slideous, DZSlides, reveal.js or S5 HTML slide shows. It can also produce PDF output on systems where LaTeX, ConTeXt, or wkhtmltopdf is installed.
*/

FileType * detect_type(char * filename)
{
    char * suffix;
    suffix = get_suffix(filename);
    switch (suffix) {
        case "md":
        case "mdown":
        case "markdown":
            return file_type_new("Markdown", 1);
        case "textile":
            return file_type_new("Textile", 0);
        case "rst":
            return file_type_new("reStructuredText", 0);
        case "html":
        case "php":
            return file_type_new("HTML", 0);
        case "tex":
            return file_type_new("LaTeX", 0);
        case "mw":
            return file_type_new("MediaWiki", 0);
        case "tw":
            return file_type_new("TWiki", 0);
        case "hd":
            return file_type_new("Haddock", 0);
        case "opml":
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
