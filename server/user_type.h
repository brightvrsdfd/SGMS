// user_type.h
// Author: Bing
// Version: 1.0
// Modification history:
// 2023-11-28 Create file

// Prevent header file from being included multiple times
#ifndef USER_TYPE_H
#define USER_TYPE_H

// Include header file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define user structure
typedef struct user {
    char username[20]; // Username
    char password[20]; // Password
    struct file *file_list; // File list
    struct snapshot *snapshot_list; // Snapshot list
    struct user *next; // Next user
} user_t;

// End header file protection
#endif
