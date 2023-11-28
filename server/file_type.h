// file_type.h
// Author: Bing
// Version: 1.0
// Modification history:
// 2023-11-28 Create file

// Prevent header file from being included multiple times
#ifndef FILE_TYPE_H
#define FILE_TYPE_H

// Include header file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define file structure
typedef struct file {
    char name[20]; // File name
    long size; // File size
    char *content; // File content
    struct file *next; // Next file
} file_t;

// End header file protection
#endif
