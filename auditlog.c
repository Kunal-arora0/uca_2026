#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[]){

    int fd;
    mode_t filePerms;
    char ch;
    int line = 1;

    if(argc < 2){
        printf("Usage ->\n");
        printf("./auditlog --add \"message\"\n");
        printf("./auditlog --view\n");
        return 0;
    }

    if(strcmp(argv[1], "--add") == 0){

        if(argc != 3){
            printf("Enter a message.\n");
            return 0;
        }

        filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

        fd = open("audit.log", O_CREAT | O_WRONLY | O_APPEND, filePerms);

        if(fd == -1){
            printf("Unable to open file.\n");
            exit(-1);
        }

        write(fd, argv[2], strlen(argv[2]));
        write(fd, "\n", 1);

        close(fd);
    }

    else if(strcmp(argv[1], "--view") == 0){

        fd = open("audit.log", O_RDONLY);

        if(fd == -1){
            printf("File not found.\n");
            exit(-1);
        }

        printf("%d: ", line);
        fflush(stdout);

        while(read(fd, &ch, 1) > 0){

            write(1, &ch, 1);

            if(ch == '\n'){
                if(read(fd, &ch, 1) > 0){
                    line++;
                    printf("%d: ", line);
                    fflush(stdout);
                    write(1, &ch, 1);
                }
            }
        }

        close(fd);
    }

    else{
        printf("Wrong command.\n");
    }

    return 0;
}
