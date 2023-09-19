// Helper macros for the C preprocessor to process my YAML
// Rule generating macros

// The 11 big groups
// Leading underscore for names
#define _BLOCK_COMMENT    comment.block.bluespec

#define _NUMBER           constant.numeric.bluespec
#define _ACTION           constant.language.bluespec

#define _FUNCTION         entity.name.function.bluespec
#define _CLASS            entity.name.class.bluespec

#define _INVALID          invalid.bluespec

#define _CONTROL          keyword.control.bluespec

// no markup

#define _DIRECTIVE        meta.preprocessor.bluespec  // Works fine for Java, but not yet BSV

#define _TYPE_PRIMITIVE   storage.type.bluespec

#define _STRING_DOUBLE    string.quoted.double.bluespec

#define _SYSTEM_FUNCTION  support.function.bluespec

#define _VARIABLE         variable.bluespec
#define _ENUM             variable.other.constant.bluespec


// Can't do this because we can't generate multiple lines.
// #define RULE(_name, _match)\
//     - name: _name \
//       match: _match

// Grammar macros
// Invoke all these with parentheses around e.g. blah(IDENTIFIER_CHAR)blah
// The leading ?: on each guarantee these are non-capturing.
#define IDENTIFIER_CHAR ?:[\p{Alpha}\d\$_]
#define LOWER_IDENTIFIER ?:\b\p{Lower}(IDENTIFIER_CHAR)*\b
#define UPPER_IDENTIFIER ?:\b\p{Upper}(IDENTIFIER_CHAR)*
#define ANY_IDENTIFIER (IDENTIFIER_CHAR)+
#define ARRAY_INDEXING (\[.*\]\s*)*
#define TYPE ?:(UPPER_IDENTIFIER)\s*#?  // excellent building block
#define ENUM UPPER_IDENTIFIER  // exactly the same
#define DOT_ACCESS ((?<=\.\s*)(LOWER_IDENTIFIER))