// Helper macros for the C preprocessor to process my YAML
// Invoke all these with parentheses around e.g. blah(IDENTIFIER_CHAR)blah
// The leading ?: on each guarantee these are non-capturing.
#define IDENTIFIER_CHAR ?:[\p{Alpha}\d\$_]
#define LOWER_IDENTIFIER ?:\b\p{Lower}(IDENTIFIER_CHAR)*
#define UPPER_IDENTIFIER ?:\b\p{Upper}(IDENTIFIER_CHAR)*
#define TYPE ?:(UPPER_IDENTIFIER)\s*#?  // excellent building block