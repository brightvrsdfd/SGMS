// filesystem.c

#include "filesystem.h"
#include <stdio.h>
#include <string.h>

void initFileSystem(FileSystem* fs) {
    fs->inodeCount = 0;
}

void createFile(FileSystem* fs, const char* fileName, User* user) {
    if (fs->inodeCount < MAX_FILES) {
        strncpy(fs->inodes[fs->inodeCount].fileName, fileName, MAX_FILE_NAME_LENGTH - 1);
        fs->inodes[fs->inodeCount].fileName[MAX_FILE_NAME_LENGTH - 1] = '\0';
        fs->inodes[fs->inodeCount].requiredRole = user->type;
        fs->inodeCount++;
        printf("File '%s' created.\n", fileName);
    } else {
        printf("File system full. Unable to create file '%s'.\n", fileName);
    }
}

void deleteFile(FileSystem* fs, const char* fileName, User* user) {
    int i;
    for (i = 0; i < fs->inodeCount; ++i) {
        if (strcmp(fs->inodes[i].fileName, fileName) == 0) {
            // Found the file
            if (user->type == ADMIN || user->type == fs->inodes[i].requiredRole) {
                // Only allow Admin or the required role to delete the file
                for (int j = i; j < fs->inodeCount - 1; ++j) {
                    fs->inodes[j] = fs->inodes[j + 1];
                }
                fs->inodeCount--;
                printf("File '%s' deleted.\n", fileName);
            } else {
                printf("Permission denied. User does not have the required role.\n");
            }
            return;
        }
    }
    printf("File '%s' not found.\n", fileName);
}

void writeFile(FileSystem* fs, const char* fileName, const char* content, User* user) {
    int i;
    for (i = 0; i < fs->inodeCount; ++i) {
        if (strcmp(fs->inodes[i].fileName, fileName) == 0) {
            // Found the file
            if (user->type == ADMIN || user->type == fs->inodes[i].requiredRole) {
                // Only allow Admin or the required role to write to the file
                strncpy(fs->inodes[i].content, content, MAX_CONTENT_LENGTH - 1);
                fs->inodes[i].content[MAX_CONTENT_LENGTH - 1] = '\0';
                printf("Content written to file '%s'.\n", fileName);
            } else {
                printf("Permission denied. User does not have the required role.\n");
            }
            return;
        }
    }
    printf("File '%s' not found.\n", fileName);
}

void readFile(FileSystem* fs, const char* fileName, char* content, User* user) {
    int i;
    for (i = 0; i < fs->inodeCount; ++i) {
        if (strcmp(fs->inodes[i].fileName, fileName) == 0) {
            // Found the file
            if (user->type == ADMIN || user->type == fs->inodes[i].requiredRole) {
                // Only allow Admin or the required role to read the file
                strncpy(content, fs->inodes[i].content, MAX_CONTENT_LENGTH - 1);
                content[MAX_CONTENT_LENGTH - 1] = '\0';
                printf("File '%s' content:\n%s\n", fileName, content);
            } else {
                printf("Permission denied. User does not have the required role.\n");
            }
            return;
        }
    }
    printf("File '%s' not found.\n", fileName);
}

void changeFilePermission(FileSystem* fs, const char* fileName, UserType newPermission, User* user) {
    int i;
    for (i = 0; i < fs->inodeCount; ++i) {
        if (strcmp(fs->inodes[i].fileName, fileName) == 0) {
            // Found the file
            if (user->type == ADMIN) {
                // Only allow Admin to change file permissions
                fs->inodes[i].requiredRole = newPermission;
                printf("Permission for file '%s' changed to %s.\n", fileName, UserTypeStrings[newPermission]);
            } else {
                printf("Permission denied. Only Admin can change file permissions.\n");
            }
            return;
        }
    }
    printf("File '%s' not found.\n", fileName);
}

void listFiles(FileSystem* fs, User* user) {
    printf("Listing files:\n");
    for (int i = 0; i < fs->inodeCount; ++i) {
        if (user->type == ADMIN || user->type == fs->inodes[i].requiredRole) {
            printf("%s\n", fs->inodes[i].fileName);
        }
    }
}
