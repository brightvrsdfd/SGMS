#include "file.h"

// open_file
// param: filename, mode
// return: pointer to the file stream, if failed, return NULL
FILE *open_file(char *filename, char *mode) {
    FILE *fp = fopen(filename, mode);
    if (fp == NULL) {
        perror("fopen");
        return NULL;
    }
    return fp;
}

// close_file
// param: file pointer
// return: void
void close_file(FILE *fp) {
    if (fp != NULL) {
        fclose(fp);
    }
}

// read_file
// param: file pointer, buffer, size
// return: 
size_t read_file(FILE *fp, char *buffer, size_t size) {
    size_t n = fread(buffer, 1, size, fp);
    if (n == 0) {
        if (ferror(fp)) {
            perror("fread");
        }
    }
    return n;
}

// 写入文件[^2^][2]
// 参数：文件指针，缓冲区，缓冲区大小
// 返回：写入的字节数，如果失败则返回0
size_t write_file(FILE *fp, char *buffer, size_t size) {
    size_t n = fwrite(buffer, 1, size, fp);
    if (n == 0) {
        if (ferror(fp)) {
            perror("fwrite");
        }
    }
    return n;
}

// 删除文件[^3^][3]
// 参数：文件名
// 返回：0表示成功，-1表示失败
int delete_file(char *filename) {
    int ret = remove(filename);
    if (ret == -1) {
        perror("remove");
    }
    return ret;
}

// 重命名文件
// 参数：旧文件名，新文件名
// 返回：0表示成功，-1表示失败
int rename_file(char *oldname, char *newname) {
    int ret = rename(oldname, newname);
    if (ret == -1) {
        perror("rename");
    }
    return ret;
}
