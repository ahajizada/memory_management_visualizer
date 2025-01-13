#include "MemoryManager.h"

MemoryBlock::MemoryBlock(int id, int size, bool isAllocated, const std::string& type)
    : id(id), size(size), isAllocated(isAllocated), type(type) {}

MemoryManager::MemoryManager() : blockCounter(1) {}

void MemoryManager::allocate(int size, const std::string& type) {
    if (type == "Heap") {
        heap.push_back(MemoryBlock(blockCounter++, size, true, type));
    } else if (type == "Stack") {
        stack.push_back(MemoryBlock(blockCounter++, size, true, type));
    } else {
        std::cout << "Invalid memory type. Choose 'Heap' or 'Stack'.\n";
        return;
    }
    std::cout << "Allocated " << size << " units in " << type << ".\n";
}

void MemoryManager::deallocate(int id, const std::string& type) {
    std::vector<MemoryBlock>* memory = (type == "Heap") ? &heap : &stack;
    for (auto& block : *memory) {
        if (block.id == id && block.isAllocated) {
            block.isAllocated = false;
            std::cout << "Deallocated block " << id << " from " << type << ".\n";
            return;
        }
    }
    std::cout << "Block " << id << " not found in " << type << ".\n";
}

void MemoryManager::displayMemory() {
    std::cout << "\nMemory Visualization:\n";
    std::cout << "Heap:\n";
    for (const auto& block : heap) {
        std::cout << "Block " << block.id << " | Size: " << block.size 
                  << " | " << (block.isAllocated ? "Allocated" : "Free") << "\n";
    }

    std::cout << "\nStack:\n";
    for (const auto& block : stack) {
        std::cout << "Block " << block.id << " | Size: " << block.size 
                  << " | " << (block.isAllocated ? "Allocated" : "Free") << "\n";
    }
}
