// filesystem_test.c

#include <stdio.h>
#include "filesystem.h"
#include "user.h"

int main() {
    // 创建用户
    User* admin = createUser("admin", "adminpass", ADMIN);
    User* teacher = createUser("teacher", "teacherpass", TEACHER);
    User* student = createUser("student", "studentpass", STUDENT);

    // 初始化文件系统
    FileSystem fs;
    initFileSystem(&fs);

    // 创建文件
    createFile(&fs, "file1.txt", admin);
    createFile(&fs, "file2.txt", teacher);
    createFile(&fs, "file3.txt", student);

    // 列出文件
    printf("Files accessible to Admin:\n");
    listFiles(&fs, admin);

    printf("Files accessible to Teacher:\n");
    listFiles(&fs, teacher);

    printf("Files accessible to Student:\n");
    listFiles(&fs, student);

    // 读取文件
    char content[MAX_CONTENT_LENGTH];
    readFile(&fs, "file1.txt", content, admin);
    readFile(&fs, "file2.txt", content, teacher);
    readFile(&fs, "file3.txt", content, student);

    // 写入文件
    writeFile(&fs, "file1.txt", "New content for file1.", admin);
    readFile(&fs, "file1.txt", content, admin);

    // 更改文件权限
    changeFilePermission(&fs, "file1.txt", STUDENT, admin);
    listFiles(&fs, student);

    // 删除文件
    deleteFile(&fs, "file1.txt", admin);
    listFiles(&fs, admin);

    // 释放内存
    deleteUser(admin);
    deleteUser(teacher);
    deleteUser(student);

    return 0;
}
// gcc -c user.c -o user.o
// gcc -c filesystem.c -o filesystem.o
// gcc -o filesystem_test filesystem_test.c user.o filesystem.o