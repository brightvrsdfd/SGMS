// user.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "user.h"

// 创建用户
User* createUser(const char* username, const char* password, UserType type) {
    User* user = malloc(sizeof(User));
    if (user != NULL) {
        strncpy(user->username, username, MAX_USERNAME_LENGTH - 1);
        user->username[MAX_USERNAME_LENGTH - 1] = '\0'; // 确保以 null 结尾
        strncpy(user->password, password, MAX_PASSWORD_LENGTH - 1);
        user->password[MAX_PASSWORD_LENGTH - 1] = '\0';
        user->type = type;
        // 初始化其他用户信息
    }
    return user;
}

// 删除用户
void deleteUser(User* user) {
    if (user != NULL) {
        free(user);
    }
}

// 修改用户密码
void modifyUser(User* user, const char* newPassword) {
    if (user != NULL) {
        strncpy(user->password, newPassword, MAX_PASSWORD_LENGTH - 1);
        user->password[MAX_PASSWORD_LENGTH - 1] = '\0';
    }
}

const char* UserTypeStrings[] = {"ADMIN", "TEACHER", "STUDENT"};

// 打印用户信息
void printUserInfo(User* user) {
    if (user != NULL) {
        printf("Username: %s\n", user->username);
        printf("User Type: %s\n", UserTypeStrings[user->type]);
        // 打印其他用户信息
    }
}

// 用户身份验证
int authenticateUser(User* user, const char* enteredPassword) {
    return (strcmp(user->password, enteredPassword) == 0);
}
