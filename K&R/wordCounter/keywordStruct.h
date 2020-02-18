
#define NKEYS (sizeof keytab / sizeof(struct key))

struct key
{
    char* word;
    int count;
}keytab[] = {
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    "do", 0,
    "double", 0,
    "else", 0,
    "float", 0,
    "for", 0,
    "if", 0,
    "int", 0,
    "long", 0,
    "return", 0,
    "sizeof", 0,
    "struct", 0,
    "typedef", 0,
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0
};
