test: Maze.o Heap.o Node.o Container.o test_Maze.cpp
	g++ Maze.o Heap.o Node.o Container.o test_Maze.cpp -o test

Maze.o: Maze.h Maze.cpp
	g++ -c Maze.cpp

Heap.o: Heap.h Heap.cpp
	g++ -c Heap.cpp

Container.o: Container.h Container.cpp
	g++ -c Container.cpp

Node.o: Node.h Node.cpp
	g++ -c Node.cpp

run:
	clear
	./test
