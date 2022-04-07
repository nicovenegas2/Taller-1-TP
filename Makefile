hello: main test

test: Maze.o Heap.o Node.o Container.o test_Maze.cpp test_Node.cpp test_Container.cpp
	g++ Maze.o Heap.o Node.o Container.o test_Maze.cpp -o test_Maze
	g++ Container.o test_Container.cpp -o test_Container
	g++ Node.o test_Node.cpp -o test_Node


runTest: test_Container test_Node test_Maze
	./test_Container
	./test_Node
	./test_Maze

main: Maze.o Heap.o Node.o Container.o main.cpp
	g++ Maze.o Heap.o Node.o Container.o main.cpp -o main

Maze.o: Maze.h Maze.cpp
	g++ -c Maze.cpp

Heap.o: Heap.h Heap.cpp
	g++ -c Heap.cpp

Container.o: Container.h Container.cpp
	g++ -c Container.cpp

Node.o: Node.h Node.cpp
	g++ -c Node.cpp

run:
	./main
