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
    void CreateDirectory(std::string path);
    void CreateFile(std::string path);
    void Delete(std::string path);

    std::vector<std::string> List(std::string path);
    void ListTree(std::string path);

    void Copy(std::string sourcePath, std::string targetDir);

    std::string ReadFile(std::string path);
    void WriteFile(std::string path, std::string content);

    std::string GetFileName(std::string path);

private:
    Inode InodeMemory[INODE_NUMBER];
    FileBlock BlockMemory[BLOCK_NUMBER];
    std::bitset<INODE_NUMBER> bIsInodeFree;
    std::bitset<BLOCK_NUMBER> bIsBlockFree;
};
