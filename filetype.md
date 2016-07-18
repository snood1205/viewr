# FileType
## Table Of Contents
- Types/Structs
  - [`FileType`](#FileType)
- Functions
  - `FileType *` [`file_type_new`](#file_type_new)`(char *, char *, char)`
  - `FileType *` [`detect_type`](#detect_type)`(char *)`
  - `char *` [`get_suffix`](#get_suffix)`(char *)`
  - `char` [`equals`](#equals)`(const FileType *, const FileType *)`

## Types/Structs
### `FileType`
#### Attributes
- `name` (`char[20]`) - the name of `FileType`
- `extension` (`char[10]`) - the file extension of `FileType`
- `markdown_flavor` (`char`) - if a `FileType` is a flavor of markdown.

## Functions
### `FileType * file_type_new(char *, char *, char)`
This function, is for all intents and purposes, the constructor for `FileType`.
#### Parameters:
- `name` (`char *`) - the name to set
- `extension` (`char *`) - the file extension to set
- `markdown_flavor` (`char`) - set if it is a markdown flavor.

#### Returns:
- `FileType *` - pointer to the newly constructed file type.
