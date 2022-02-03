#include <stdarg.h>
#include <stdio.h>

int strsize(char* _string){
    int i = 0;
    while(_string[i] != '\0'){
        i++;
    }
    return i;
}

char* strcpy(char *_to, const char* _from){
    char* ret = _to;
    int i = 0;
    while(_from[i] != '\0'){
        _to[i] = _from[i];
        i++;
    }
    _to[i] = '\0';
    return ret;
}

char* nstrcpy(char *_to, const char* _from, int _n){ //copy starting at n from source, excluding n
    char* ret = _to;
    int i = 0;
    int n = _n+1;
    while(_from[i+n] != '\0'){
        _to[i] = _from[i+n];
        i++;
    }
    _to[i] = '\0';
    return ret;
}

char* stradd(char *_to, const char* _from){ //find the end of a string and add to the end
    char* ret = _to;
    int i = 0;
    int n = strsize(_to);
    while(_from[i] != '\0'){
        _to[i+n] = _from[i];
        i++;
    }
    _to[i+n] = '\0';
    return ret;
}

char* straddn(char *_to, const char* _from, int _n){ //find the end of a string and add to the end, stopping at n
    char* ret = _to;
    int i = 0;
    int n = strsize(_to);
    while(i < _n){
        _to[i+n] = _from[i];
        i++;
    }
    _to[i+n] = '\0';
    return ret;
}

int find_newline_index(char* _string){
    int i = 0;
    while(*(_string+i) != '\0'){
        if(*(_string+i) == '\n'){
            return i;
        }
        i++;
    }
    return -1;
}

void str_null_init(int num, ...){
    va_list valist;
    char* hold;
    va_start(valist, num);

    for (int i = 0; i < num; i++) {
        hold = va_arg(valist, char*);
        hold[0] = '\0';
    }
	
   va_end(valist);
}

//split?
/*
char* nstrncpy(char *_to, const char* _from, int _n, int _y){ //copies _y characters to a specific index _n of the string being copied to
    char* ret = _to;
    int i;
    for(i = 0; i < _y; i++){
        _to[i+_n] = _from[i];
        i++;
    }
    if(_to[i+_n] != '\0'){
        _to[i+_n] = '\0';
    }
    return ret;
}
*/
