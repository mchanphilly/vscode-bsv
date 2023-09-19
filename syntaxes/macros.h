// Helper macros for the C preprocessor to process my YAML
// Rule generating macros

// Leading underscore for names
#define _VARIABLE variable.bluespec
#define _NUMBER constant.numeric.bluespec
#define _FUNCTION entity.name.function.bluespec
#define _SYSTEM_FUNCTION support.function.bluespec
#define _ENUM variable.other.constant.bluespec

// Can't do this because we can't generate multiple lines.
// #define RULE(_name, _match)\
//     - name: _name \
//       match: _match

// Grammar macros
// Invoke all these with parentheses around e.g. blah(IDENTIFIER_CHAR)blah
// The leading ?: on each guarantee these are non-capturing.
#define IDENTIFIER_CHAR ?:[\p{Alpha}\d\$_]
#define LOWER_IDENTIFIER ?:\b\p{Lower}(IDENTIFIER_CHAR)*
#define UPPER_IDENTIFIER ?:\b\p{Upper}(IDENTIFIER_CHAR)*
#define TYPE ?:(UPPER_IDENTIFIER)\s*#?  // excellent building block
#define ENUM UPPER_IDENTIFIER  // exactly the same