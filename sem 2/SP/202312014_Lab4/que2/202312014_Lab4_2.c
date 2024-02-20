#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS 10

void cat(char *filename) {
    FILE *fp;
    char c;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Unable to open file.\n");
        exit(0);
    }
    while ((c = fgetc(fp)) != EOF)
        printf("%c", c);
    fclose(fp);
}

void ls(char *directory) {
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(directory)) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0)
                continue;
            printf("%s\n", ent->d_name);
        }
        closedir(dir);
    } else {
        printf("Unable to open directory.\n");
        exit(0);
    }    
}

void mv(char *source, char *destination) {
    int status = rename(source, destination);
    if (status == 0)
        printf("File moved successfully.\n");
    else
        printf("Error: Unable to move file.\n");
}

int main() {
    char command[MAX_COMMAND_LENGTH];
    char *args[MAX_ARGS];
    char *token;
    int i, num_args;
    // char *username = getenv("USER");
    char *username = "student";
    char hostname[MAX_COMMAND_LENGTH];
    gethostname(hostname, MAX_COMMAND_LENGTH);

    while (1) {
        printf("myshell@%s@%s$ ", username, hostname);
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        num_args = 0;
        token = strtok(command, " \n");
        while (token != NULL && num_args < MAX_ARGS) {
            args[num_args] = token;
            num_args++;
            token = strtok(NULL, " \n");
        }
        if (num_args == 0)
            continue;
        if (strcmp(args[0], "cat") == 0 && num_args == 2)
            cat(args[1]);
        else if (strcmp(args[0], "ls") == 0 && num_args == 2)
            ls(args[1]);
        else if (strcmp(args[0], "mv") == 0 && num_args == 3)
            mv(args[1], args[2]);
        else if (strcmp(args[0], "exit") == 0)
            exit(0);
        else
            printf("Invalid command.\n");
    }

    return 0;
}

