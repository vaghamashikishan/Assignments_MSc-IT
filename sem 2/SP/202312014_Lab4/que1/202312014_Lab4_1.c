#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

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
	
    printf("cat file.txt\n\n");
    cat("file.txt");
    printf("\n\nls .\n\n");
    ls(".");
    printf("\n\nmv file.txt newfile.txt\n\n");
    mv("file.txt", "newfile.txt");
    return 0;
}

