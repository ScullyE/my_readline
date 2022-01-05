#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define READLINE_READ_SIZE 40

char *my_readline(int _fd);

int main(){ //main prints up to 10 lines of a provided file, see readline function below
    const char* filename = "testfile.txt";
    int fd = open(filename, O_RDONLY);
    char* printstring = NULL;

    for(int i = 0; i < 10; i++){
        printstring = my_readline(fd);

        if(printstring == NULL){
            printf("Error!\n");
            break;
        }

        if(*printstring != '\0'){
            printf("%s\n", printstring);
        }
        
        free(printstring);
    }

    close(fd);

    return 0;
}

char *my_readline(int _fd){
    char* line = malloc(READLINE_READ_SIZE+1);
    char c;
    int msg;
    int count = 0;
    while((msg = read(_fd, &c, 1)) != 0 && c != '\n'){
        
        if (msg == -1){
            return NULL;
        }

        if(count < READLINE_READ_SIZE){
            *(line+count) = c;
            count++;
        }
    }

    *(line+count) = '\0';

    return line;
}