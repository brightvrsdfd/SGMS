#include "FileSystem.h"
#include <string.h>
#include <iostream>

using namespace std;

FileSystem::FileSystem()
{
    bIsInodeFree.set();
    bIsBlockFree.set();
    bIsInodeFree.reset(0);
    bIsBlockFree.reset(0);

    memset(InodeMemory, 0, sizeof(Inode) * INODE_NUMBER);
    memset(BlockMemory, 0, sizeof(FileBlock) * BLOCK_NUMBER);
    InodeMemory[0].type = true;
}

vector<string> FileSystem::pathSplit(string path)
{
    vector<string> result;
    size_t start = path.find_first_not_of('/');

    while (start != string::npos)
    {
        size_t end = path.find_first_of('/', start);
        string token = path.substr(start, (end == string::npos) ? string::npos : end - start);

        result.push_back(token);

        start = (end == string::npos) ? string::npos : path.find_first_not_of('/', end);
    }

    return result;
}

int FileSystem::Dir2InodeID(string name, int curDirInodeIdx)
{
    if (InodeMemory[curDirInodeIdx].type == false)
        return 0;

    int curBlockIdx = InodeMemory[curDirInodeIdx].BlockID;
    DirectoryBlock *curBlock = reinterpret_cast<DirectoryBlock *>(&BlockMemory[curBlockIdx]);

    for (int i = 0; i < ENTRY_NUMBER; i++)
    {
        string fileName = string(curBlock->FileName[i]);
        if (fileName == name && curBlock->InodeID[i])
        {
            return curBlock->InodeID[i];
        }
    }

    return 0;
}

int FileSystem::Path2InodeID(vector<string> pathVec)
{
    int curDir = 0;
    for (int i = 0; i < pathVec.size() - 1; i++)
    {
        curDir = Dir2InodeID(pathVec[i], curDir);
        if (curDir == 0)
            return 0;
    }
    return curDir;
}

void FileSystem::DeleteByInode(int InodeIdx)
{
    if (InodeMemory[InodeIdx].type)
    {
        // DeleteDir_k2(InodeIdx);
        // Del Dir
        int BlockIdx = InodeMemory[InodeIdx].BlockID;
        DirectoryBlock *Block = reinterpret_cast<DirectoryBlock *>(&BlockMemory[BlockIdx]);

        for (int i = 0; i < ENTRY_NUMBER; i++)
        {
            if (Block->InodeID[i])
            {
                DeleteByInode(Block->InodeID[i]);
            }
        }

        memset(&InodeMemory[InodeIdx], 0, sizeof(Inode));
        memset(&BlockMemory[BlockIdx], 0, sizeof(DirectoryBlock));
        bIsInodeFree.set(InodeIdx);
        bIsBlockFree.set(BlockIdx);
    }
    else
    {
        // DeleteFile_k2(InodeIdx);
        // Del File
        int BlockIdx = InodeMemory[InodeIdx].BlockID;
        memset(&InodeMemory[InodeIdx], 0, sizeof(Inode));
        memset(&BlockMemory[BlockIdx], 0, sizeof(FileBlock));
        bIsInodeFree.set(InodeIdx);
        bIsBlockFree.set(BlockIdx);
    }
}

int FileSystem::Create(string path, bool type)
{
    vector<string> pathVec = pathSplit(path);
    if (pathVec.back().size() >= MAX_FILENAME_LENGTH || pathVec.back().size() == 0)
        return 0;

    int InodeIdx = Path2InodeID(pathVec);
    if (InodeIdx == 0 && pathVec.size() != 1)
        return 0;

    int BlockIdx = InodeMemory[InodeIdx].BlockID;
    DirectoryBlock *Block = reinterpret_cast<DirectoryBlock *>(&BlockMemory[BlockIdx]);

    for (int i = 0; i < ENTRY_NUMBER; i++)
    {
        string fileName = string(Block->FileName[i]);
        if (fileName == pathVec.back() && Block->InodeID[i])
        {
            return 0;
        }
    }

    int NewInodeIdx = bIsInodeFree._Find_first();
    int NewBlockIdx = bIsBlockFree._Find_first();
    if (NewInodeIdx == INODE_NUMBER || NewBlockIdx == BLOCK_NUMBER)
        return 0;

    for (int i = 0; i < ENTRY_NUMBER; i++)
    {
        if (Block->InodeID[i] == 0)
        {
            Block->InodeID[i] = NewInodeIdx;
            strcpy(Block->FileName[i], pathVec.back().data());

            bIsInodeFree.reset(NewInodeIdx);
            bIsBlockFree.reset(NewBlockIdx);

            Inode &NewInode = InodeMemory[NewInodeIdx];
            NewInode.type = type;
            NewInode.BlockID = NewBlockIdx;

            return NewInodeIdx;
        }
    }

    return 0;
}

void FileSystem::CreateDir(string path)
{
    Create(path, true);
}

void FileSystem::CreateFile(string path)
{
    Create(path, false);
}

void FileSystem::Delete(string path)
{
    vector<string> pathVec = pathSplit(path);
    int InodeIdx = Path2InodeID(pathVec);
    if (InodeIdx == 0 && pathVec.size() != 1)
        return;

    int BlockIdx = InodeMemory[InodeIdx].BlockID;
    DirectoryBlock *Block = reinterpret_cast<DirectoryBlock *>(&BlockMemory[BlockIdx]);

    int InodeIdx2 = Dir2InodeID(pathVec.back(), InodeIdx);
    if (InodeIdx2 == 0)
        return;

    DeleteByInode(InodeIdx2);
    for (int i = 0; i < ENTRY_NUMBER; i++)
    {
        string fileName = string(Block->FileName[i]);
        if (fileName == pathVec.back() && Block->InodeID[i])
        {
            Block->InodeID[i] = 0;
            memset(&(Block->FileName[i]), 0, MAX_FILENAME_LENGTH);
        }
    }
}

vector<string> FileSystem::getListVector(string path)
{
    vector<string> res;
    vector<string> pathVec = pathSplit(path);

    int BlockIdx;
    if (pathVec.size() == 0)
    {
        BlockIdx = 0;
    }
    else
    {
        int _InodeIdx = Path2InodeID(pathVec);
        if (_InodeIdx == 0 && pathVec.size() != 1)
            return res;

        int InodeIdx = Dir2InodeID(pathVec.back(), _InodeIdx);
        if (InodeIdx == 0 || InodeMemory[InodeIdx].type == false)
            return res;

        BlockIdx = InodeMemory[InodeIdx].BlockID;
    }
    DirectoryBlock *Block = reinterpret_cast<DirectoryBlock *>(&BlockMemory[BlockIdx]);

    for (int i = 0; i < ENTRY_NUMBER; i++)
    {
        if (Block->InodeID[i])
        {
            res.push_back(string(Block->FileName[i]));
        }
    }

    return res;
}

string FileSystem::getList(string path)
{
    vector<string> list = getListVector(path);
    string listString = "";
    for (int i = 0; i < list.size(); i++)
    {
       listString = listString + list[i] + "\n";
    }

    return listString;
}

string FileSystem::getListTree(std::string path){
    static int level = 0;
    string listString = "";
    vector<string> list = getListVector(path);
    for (int i = 0; i < list.size(); i++)
    {
        for (int j = 0; j < level; j++){
            listString = listString + "----";
        }
        listString = listString + list[i] + "\n";
        level++;
        string innerList = getListTree(path + "/" + list[i]);
        if (innerList != ""){
            listString = listString + innerList;
        }
        listString = listString + "\n";
        level--;
    }
    return listString;
}

void FileSystem::Copy(string sourcePath, string targetDir)
{
    vector<string> srcPath = pathSplit(sourcePath);
    int _InodeIdx = Path2InodeID(srcPath);
    if (_InodeIdx == 0 && srcPath.size() != 1) return;

    int InodeIdx = Dir2InodeID(srcPath.back(), _InodeIdx);
    if (InodeIdx == 0) return;

    string newPath = targetDir + "/" + srcPath.back();
    if (InodeMemory[InodeIdx].type)
    {
        CreateDir(newPath);
        vector<string> list = getListVector(sourcePath);
        for (int i = 0; i < list.size(); i++)
            Copy(sourcePath + "/" + list[i], newPath);
    }
    else
    {
        CreateFile(newPath);
        string content = getFileCont(sourcePath);
        WriteFile(newPath, content);
    }
}

string FileSystem::getFileCont(string path)
{
    vector<string> pathVec = pathSplit(path);
    int _InodeIdx = Path2InodeID(pathVec);
    if (_InodeIdx == 0 && pathVec.size() != 1){
        std::cout << "Invalid path" << endl;
        return "";
    }
        

    int InodeIdx = Dir2InodeID(pathVec.back(), _InodeIdx);
    if (InodeIdx == 0 || InodeMemory[InodeIdx].type){
        std::cout << "It is not a file" << endl;
        return "";
    }

    int BlockIdx = InodeMemory[InodeIdx].BlockID;
    FileBlock *Block = reinterpret_cast<FileBlock *>(&BlockMemory[BlockIdx]);

    return string(Block->Content);
}

void FileSystem::WriteFile(string path, string content)
{
    if (content.size() >= BLOCK_SIZE)
        return;

    vector<string> pathVec = pathSplit(path);
    int _InodeIdx = Path2InodeID(pathVec);
    if (_InodeIdx == 0 && pathVec.size() != 1){
        std::cout << "Invalid path" << endl;
        return;
    }

    int InodeIdx = Dir2InodeID(pathVec.back(), _InodeIdx);
    if (InodeIdx == 0 || InodeMemory[InodeIdx].type){
        std::cout << "It is not a file" << endl;
        return;
    }

    int BlockIdx = InodeMemory[InodeIdx].BlockID;
    FileBlock *Block = reinterpret_cast<FileBlock *>(&BlockMemory[BlockIdx]);

    strcpy(Block->Content, content.data());
}

string FileSystem::getFileName(string path)
{
    vector<string> pathVec = pathSplit(path);
    if (pathVec.size() == 0)
        return "";
    return pathVec.back();
}