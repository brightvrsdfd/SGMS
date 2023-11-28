// snapshot.h
// Author: Bing
// Version: 1.0
// Modification history:
// 2023-11-28 Create file

// Prevent header file from being included multiple times
#ifndef SNAPSHOT_H
#define SNAPSHOT_H

// Include header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user_type.h"
#include "file_type.h"

// Define snapshot structure
typedef struct snapshot {
    char name[20]; // Snapshot name
    struct file *file_list; // File list
    struct snapshot *next; // Next snapshot
} snapshot_t;

// Declare functions
int create_snapshot(user_t *user, char *snapshot_name);
int delete_snapshot(user_t *user, char *snapshot_name);
snapshot_t *find_snapshot(user_t *user, char *snapshot_name);
snapshot_t *find_prev_snapshot(user_t *user, char *snapshot_name);
int restore_snapshot(user_t *user, char *snapshot_name);
int display_snapshot(user_t *user, char *snapshot_name);

// End header file protection
#endif