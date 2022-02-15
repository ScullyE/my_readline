
#include "lib/my_readline.h"

int main(){ //main prints up to 10 lines of a provided file
    const char* filename = "tests/testfile.txt";
    int fd = open(filename, O_RDONLY);
    char* printstring = NULL;
    
    for(int i = 0; i < 100; i++){
        printstring = my_readline(fd);

        if(printstring == NULL){
            printf("EOF or error!\n");
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