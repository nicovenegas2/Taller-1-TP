test: Maze.o test_Maze.cpp
	g++ Maze.o test_Maze.cpp -o test

Maze.o: Maze.h Maze.cpp
	g++ -c Maze.cpp

run:
	./test
