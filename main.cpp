#include "MemoryManager.h"

int main() {
    MemoryManager memoryManager;

    int choice;
    while (true) {
        std::cout << "\nMemory Management Visualizer\n";
        std::cout << "1. Allocate Memory\n";
        std::cout << "2. Deallocate Memory\n";
        std::cout << "3. Display Memory\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            int size;
            std::string type;
            std::cout << "Enter memory size: ";
            std::cin >> size;
            std::cout << "Enter memory type (Heap/Stack): ";
            std::cin >> type;
            memoryManager.allocate(size, type);
        } else if (choice == 2) {
            int id;
            std::string type;
            std::cout << "Enter block ID: ";
            std::cin >> id;
            std::cout << "Enter memory type (Heap/Stack): ";
            std::cin >> type;
            memoryManager.deallocate(id, type);
        } else if (choice == 3) {
            memoryManager.displayMemory();
        } else if (choice == 4) {
            break;
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
