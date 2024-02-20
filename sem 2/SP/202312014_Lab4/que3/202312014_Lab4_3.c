#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    
    char *filename = argv[1];
    
    // Create a hard link to the file
    if (link(filename, "hardlink") != 0) {
        perror("Error creating hard link");
        exit(1);
    }
    
    // Create a symbolic link to the file
    if (symlink(filename, "symlink") != 0) {
        perror("Error creating symbolic link");
        exit(1);
    }
    
    // Get the inode number for the original file, hard link, and symbolic link
    struct stat file_stat;
    if (stat(filename, &file_stat) != 0) {
        perror("Error getting file stats");
        exit(1);
    }
    ino_t orig_inode = file_stat.st_ino;
    
    if (stat("hardlink", &file_stat) != 0) {
        perror("Error getting file stats");
        exit(1);
    }
    ino_t hardlink_inode = file_stat.st_ino;
    
    if (lstat("symlink", &file_stat) != 0) {
        perror("Error getting file stats");
        exit(1);
    }
    ino_t symlink_inode = file_stat.st_ino;
    
    // Display the inode numbers
    printf("Original file inode: %lu\n", orig_inode);
    printf("Hard link inode: %lu\n", hardlink_inode);
    printf("Symbolic link inode: %lu\n", symlink_inode);
    
    return 0;
}

