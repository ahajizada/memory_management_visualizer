all: memory_management_visualizer

memory_management_visualizer: main.o MemoryManager.o
	g++ -o memory_management_visualizer main.o MemoryManager.o

main.o: main.cpp MemoryManager.h
	g++ -c main.cpp

MemoryManager.o: MemoryManager.cpp MemoryManager.h
	g++ -c MemoryManager.cpp

clean:
	rm -f *.o memory_management_visualizer
