#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "str_lib.h"

#define READLINE_READ_SIZE 1

struct readline_s {
    int fd;
    char buf[READLINE_READ_SIZE+1];
};

int parse_line(char* _returnstring, char* _readstring, struct readline_s* _buffer);
int nullterm_read(int _fd, char* _readstring, int _size);

char *my_readline(int _fd){
    static struct readline_s buffer = {.fd = -1};
    char readstring[READLINE_READ_SIZE+2];
    char returnstring[500];
    str_null_init(2, readstring, returnstring);
    int returnsize = 0;
    int init_buffer_size = strsize(buffer.buf);
    int msg;

    if(buffer.fd != _fd){ //in case we've switched to a new filestream
        buffer.fd = _fd;
        strcpy(buffer.buf, "\0\0");
    }

    if(parse_line(returnstring, buffer.buf, &buffer) == 0){ //read our buffer
        msg = nullterm_read(_fd, readstring, READLINE_READ_SIZE);

        if(msg < 1 && init_buffer_size == 0){ //if we have reached EOF or Error, and the buffer started empty
            return NULL;
        }

        while(parse_line(returnstring, readstring, &buffer) == 0){ //read from filestream
            msg = nullterm_read(_fd, readstring, READLINE_READ_SIZE);
            if(msg == 0){
                break;
            }
        }
    }

    returnsize = strsize(returnstring);//detrmine size
    char* return_heap_string = malloc(returnsize+1); //did this so we only malloc as much space as needed.
    strcpy(return_heap_string, returnstring);
    return return_heap_string;
}

int nullterm_read(int _fd, char* _readstring, int _size){ //Because null termination is good.
    int ret = read(_fd, _readstring, _size);
    *(_readstring+ret) = '\0';
    return ret;
}

int parse_line(char* _returnstring, char* _readstring, struct readline_s* _buffer){
    int newlineindex = find_newline_index(_readstring);
    
    if(newlineindex < 0){
        stradd(_returnstring, _readstring);
        strcpy(_buffer->buf, "\0\0");
        return 0;
    } else {
        straddn(_returnstring, _readstring, newlineindex);
        nstrcpy(_buffer->buf, _readstring, newlineindex);
        return 1;
    }
}