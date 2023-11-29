// user_test.c

#include <stdio.h>
#include "user.h"

int main() {
    // 创建管理员
    User* admin = createUser("admin", "adminpass", ADMIN);
    printUserInfo(admin);

    // 创建教师
    User* teacher = createUser("teacher1", "teacherpass", TEACHER);
    printUserInfo(teacher);

    // 创建学生
    User* student = createUser("student1", "studentpass", STUDENT);
    printUserInfo(student);

    // 修改密码
    modifyUser(student, "newpass");
    printUserInfo(student);

    // 用户身份验证测试
    if (authenticateUser(student, "wrongpass")) {
        printf("Authentication failed!\n");
    } else {
        printf("Authentication successful!\n");
    }

    // 错误处理测试：尝试创建用户时内存分配失败
    User* invalidUser = createUser("invalid", "invalidpass", ADMIN);
    if (invalidUser == NULL) {
        printf("Error handling test passed: Unable to create user.\n");
    }

    // 用户类型字符串输出测试
    printf("\nUser type string output test:\n");
    for (int i = ADMIN; i <= STUDENT; ++i) {
        User* tempUser = createUser("temp", "temppass", i);
        printf("User type: %s\n", UserTypeStrings[tempUser->type]);
        deleteUser(tempUser);
    }

    // 释放内存
    deleteUser(admin);
    deleteUser(teacher);
    deleteUser(student);

    return 0;
}

// gcc -o user_test user.c user_test.c