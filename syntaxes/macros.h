// Helper macros for the C preprocessor to process my YAML
// Rule generating macros

#define VARIABLE variable.bluespec
#define NUMBER constant.numeric.bluespec
#define FUNCTION entity.name.function.bluespec
#define SYSTEM_FUNCTION support.function.bluespec

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