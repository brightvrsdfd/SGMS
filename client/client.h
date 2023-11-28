// client.h
#ifndef CLIENT_H
#define CLIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// 定义一些常量
#define USER_LEN 20 // 用户名长度
#define PASS_LEN 20 // 密码长度
#define FILE_LEN 20 // 文件名长度
#define PATH_LEN 100 // 路径长度
#define BUFF_LEN 256 // 缓冲区长度
#define ADMIN 0 // 管理员类型
#define TEACHER 1 // 教师类型
#define STUDENT 2 // 学生类型

// 定义一个全局变量，用来存储客户端的 socket 描述符
int sockfd;

// 定义一个全局变量，用来存储客户端的用户名
char username[USER_LEN];

// 定义一个全局变量，用来存储客户端的用户类型
int type;

// 定义一些函数原型
void login(); // 登录系统
void logout(); // 退出系统
void show_menu(); // 显示菜单
void create_user(); // 创建用户
void delete_user(); // 删除用户
void change_password(); // 修改密码
void create_folder(); // 创建文件夹
void delete_folder(); // 删除文件夹
void list_files(); // 列出目录下的文件
void create_file(); // 创建文件
void delete_file(); // 删除文件
void read_file(); // 读取文件
void write_file(); // 写入文件
void change_perm(); // 更改文件访问权限
void create_snap(); // 创建快照
void restore_snap(); // 恢复快照
void compare_snap(); // 比较快照
void send_request(char *request); // 向服务器发送请求
void receive_response(char *response); // 从服务器接收回复

#endif
