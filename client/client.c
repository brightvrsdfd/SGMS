// client.c
#include "client.h"

int main(int argc, char *argv[])
{
    // 检查命令行参数是否正确
    if (argc != 3) {
        printf("Usage: %s <server_ip> <server_port>\n", argv[0]);
        exit(1);
    }

    // 创建一个 socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(2);
    }

    // 设置 socket 的地址和端口
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    // 连接到服务器
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(3);
    }

    // 向服务器发送消息
    int n = write(sockfd, "Hello, server!", 15);
    if (n < 0) {
        perror("write");
        exit(4);
    }

    // 从服务器接收回复
    char buffer[256];
    memset(buffer, 0, sizeof(buffer));
    n = read(sockfd, buffer, 255);
    if (n < 0) {
        perror("read");
        exit(5);
    }

    // 打印服务器的回复
    printf("Received message from server: %s\n", buffer);

    // 关闭 socket
    close(sockfd);

    return 0;
}
