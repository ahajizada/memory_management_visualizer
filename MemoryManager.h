#ifndef MEMORYMANAGER_H
#define MEMORYMANAGER_H

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

class MemoryBlock {
public:
    int id;
    int size;
    bool isAllocated;
    std::string type; 

    MemoryBlock(int id, int size, bool isAllocated, const std::string& type);
};

class MemoryManager {
private:
    std::vector<MemoryBlock> heap;
    std::vector<MemoryBlock> stack;
    int blockCounter;

public:
    MemoryManager();
    void allocate(int size, const std::string& type);
    void deallocate(int id, const std::string& type);
    void displayMemory();
};

#endif
