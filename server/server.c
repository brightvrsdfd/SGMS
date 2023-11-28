// server.c
#include "server.h"

int main(int argc, char *argv[])
{
    // 检查命令行参数是否正确
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
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
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(atoi(argv[1]));

    // 绑定 socket 到地址和端口
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(3);
    }

    // 监听 socket
    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(4);
    }

    // 接受客户端的连接请求
    struct sockaddr_in cli_addr;
    socklen_t cli_len = sizeof(cli_addr);
    int newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &cli_len);
    if (newsockfd < 0) {
        perror("accept");
        exit(5);
    }

    // 从客户端接收消息
    char buffer[256];
    memset(buffer, 0, sizeof(buffer));
    int n = read(newsockfd, buffer, 255);
    if (n < 0) {
        perror("read");
        exit(6);
    }

    // 打印客户端的消息
    printf("Received message from client: %s\n", buffer);

    // 向客户端发送回复
    n = write(newsockfd, "Hello, client!", 15);
    if (n < 0) {
        perror("write");
        exit(7);
    }

    // 关闭 socket
    close(newsockfd);
    close(sockfd);

    return 0;
}
