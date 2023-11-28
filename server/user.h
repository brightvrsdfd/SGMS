// user.h
// Author: Bing
// Version: 1.0
// Modification history:
// 2023-11-28 Create file

// Prevent header file from being included multiple times
#ifndef USER_H
#define USER_H

// Include header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user_type.h"
#include "file_type.h"

// Declare user list as a global variable
extern user_t *user_list;

// Declare functions
int validate_user(char *username, char *password);
int add_user(char *username, char *password);
int delete_user(char *username);
user_t *find_user(char *username);
user_t *find_prev_user(char *username);
int modify_user(char *username, char *new_password);
int display_user(char *username);

// End header file protection
#endif
