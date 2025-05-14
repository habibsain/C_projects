#include<stdio.h>
#include<stdlib.h>

char * shl_read_line(void);
char ** shl_split_line(char * line);
int shl_exec(char ** args);

// void shl_loop(void) {
//     char *line;
//     char **args;
//     int status;

//     do {
//         printf(">>>");
//         line = shl_read_line;
//         args = shl_split_line;
//         status = shl_exec(args);

//         free(line);
//         free(args);

//     } while (status);
    
// }

char * shl_read_line(void){
    int bx_size = 1024;
    char *buff = malloc(sizeof(char) * bx_size);  
    int c;
    int pos_n = 0;

    //fprintf(stderr, "read_ln: allocation error___trial\n");

    //check for memory allocation failure
    if (!buff) {
       fprintf(stderr, "read_ln: allocation error\n");
        exit(EXIT_FAILURE);
    }

    while(1) {
        c = getchar();
        if ( c == EOF || c == '\n' ) {
            buff[pos_n] = '\0';
            return buff;
        }
        else {
            buff[pos_n] = c;
        }
        pos_n++;    
    

        //reallocation of memory to buffer on exceeding existing one
        if (pos_n >= bx_size) {
            bx_size += 1024;
            buff = realloc(buff, bx_size);
            if(!buff) {
                fprintf(stderr, "read_ln: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
    }
    free(buff);
}


int main(int arc, char *argv){
    //loop command
    //shl_loop;
    //return EXIT_SUCCESS;
    char *result;
    printf("Write some characters:\n");

    result = shl_read_line();

    int i = 0;

    // while( result[i] != EOF && result[i] != '\n') {
    //     printf("%c", result[i]);
    //     i++;
    // }


    printf("Here are the characters: \n");

    printf("%s \n", result);

    free(result);
    

    return 0;
}
