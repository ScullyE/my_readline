
#ifndef LIB_STR_H
#define LIB_STR_H
    char* strcpy(char *_to, const char* _from);
    char* stradd(char *_to, const char* _from);
    char* straddn(char *_to, const char* _from, int _n);
    char* nstrcpy(char *_to, const char* _from, int _n);
    int strsize(char* _string);
    int find_newline_index(char* _string);
    void str_null_init(int num, ...);
#endif

