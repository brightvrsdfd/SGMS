#pragma once
#include "iNode.h"

#include <string>
#include <vector>
#include <bitset>

class FileSystem
{
public:
    FileSystem();

private:
    std::vector<std::string> pathSplit(std::string path);

    int Dir2InodeID(std::string name, int DirInodeID);
    int Path2InodeID(std::vector<std::string> pathVec);

    void DeleteByInode(int InodeIdx);
    int Create(std::string path, bool type);

public:
    void CreateDir(std::string path);
    void CreateFile(std::string path);
    void Delete(std::string path);

    std::vector<std::string> getListVector(std::string path);
    std::string getList(std::string path);
    std::string getListTree(std::string path);

    std::string getFileCont(std::string path);
    std::string getFileName(std::string path);
    void WriteFile(std::string path, std::string content);

    void Copy(std::string sourcePath, std::string targetDir);

private:
    Inode InodeMemory[INODE_NUMBER];
    FileBlock BlockMemory[BLOCK_NUMBER];
    std::bitset<INODE_NUMBER> inodeFree;
    std::bitset<BLOCK_NUMBER> blockFree;
};