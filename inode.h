// inode.h

#ifndef INODE_H
#define INODE_H

#include "user.h"

#define MAX_FILE_NAME_LENGTH 50
#define MAX_CONTENT_LENGTH 100

typedef struct {
    char fileName[MAX_FILE_NAME_LENGTH];
    char content[MAX_CONTENT_LENGTH];
    UserType requiredRole;  // 角色要求（例如：ADMIN、TEACHER、STUDENT）
} INode;

#endif // INODE_H
