// server.h
#ifndef SERVER_H
#define SERVER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

// 定义一些常量
#define MAX_USER 100 // 最大用户数
#define MAX_FILE 100 // 最大文件数
#define MAX_BLOCK 10 // 最大文件块数
#define MAX_SNAP 10 // 最大快照数
#define BLOCK_SIZE 1024 // 文件块大小
#define USER_LEN 20 // 用户名长度
#define PASS_LEN 20 // 密码长度
#define FILE_LEN 20 // 文件名长度
#define PATH_LEN 100 // 路径长度
#define BUFF_LEN 256 // 缓冲区长度
#define ADMIN 0 // 管理员类型
#define TEACHER 1 // 教师类型
#define STUDENT 2 // 学生类型

// 定义一个用户结构体
typedef struct user {
    char username[USER_LEN]; // 用户名
    char password[PASS_LEN]; // 密码
    int type; // 用户类型
    int online; // 是否在线
    int sockfd; // socket 描述符
} user_t;

// 定义一个文件结构体
typedef struct file {
    char filename[FILE_LEN]; // 文件名
    int owner; // 文件所有者
    int group; // 文件所属组
    int perm; // 文件访问权限
    int size; // 文件大小
    int blocks[MAX_BLOCK]; // 文件块索引
} file_t;

// 定义一个快照结构体
typedef struct snap {
    char name[FILE_LEN]; // 快照名
    int time; // 快照时间
    int files[MAX_FILE]; // 快照文件索引
} snap_t;

// 定义一个全局变量，用来存储用户信息
user_t users[MAX_USER];

// 定义一个全局变量，用来存储文件信息
file_t files[MAX_FILE];

// 定义一个全局变量，用来存储快照信息
snap_t snaps[MAX_SNAP];

// 定义一个全局变量，用来存储文件块
char blocks[MAX_FILE * MAX_BLOCK][BLOCK_SIZE];

// 定义一些函数原型
void *handle_client(void *arg); // 处理客户端的请求
int create_user(char *username, char *password, int type); // 创建用户
int delete_user(char *username); // 删除用户
int change_password(char *username, char *old_password, char *new_password); // 修改密码
int verify_user(char *username, char *password); // 验证用户
int create_folder(char *path, int owner, int group, int perm); // 创建文件夹
int delete_folder(char *path, int user); // 删除文件夹
int list_files(char *path, int user, char *buffer); // 列出目录下的文件
int create_file(char *path, int owner, int group, int perm); // 创建文件
int delete_file(char *path, int user); // 删除文件
int read_file(char *path, int user, char *buffer); // 读取文件
int write_file(char *path, int user, char *buffer); // 写入文件
int change_perm(char *path, int user, int perm); // 更改文件访问权限
int create_snap(char *name); // 创建快照
int restore_snap(char *name); // 恢复快照
int compare_snap(char *name1, char *name2, char *buffer); // 比较快照

#endif
