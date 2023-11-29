// filesystem.h

#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "inode.h"
#include "user.h"

#define MAX_FILES 100

typedef struct {
    INode inodes[MAX_FILES];
    int inodeCount;
} FileSystem;

void initFileSystem(FileSystem* fs);
void createFile(FileSystem* fs, const char* fileName, User* user);
void deleteFile(FileSystem* fs, const char* fileName, User* user);
void writeFile(FileSystem* fs, const char* fileName, const char* content, User* user);
void readFile(FileSystem* fs, const char* fileName, char* content, User* user);
void changeFilePermission(FileSystem* fs, const char* fileName, UserType newPermission, User* user);
void listFiles(FileSystem* fs, User* user);

#endif // FILESYSTEM_H