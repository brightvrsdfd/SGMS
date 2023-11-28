#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *open_file(char *filename, char *mode);
void close_file(FILE *fp);
size_t read_file(FILE *fp, char *buffer, size_t size);
size_t write_file(FILE *fp, char *buffer, size_t size);
int delete_file(char *filename);
int rename_file(char *oldname, char *newname);

#endif