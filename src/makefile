CXX = g++
CXXFLAGS = -std=c++11
RM = rm -f
OBJS = main.o tictactoe.o

all: run

main: main.o tictactoe.o
	@ $(CXX) $(CXXFLAGS) -o main main.o tictactoe.o
main.o: main.cpp tictactoe.hpp
	@ $(CXX) $(CXXFLAGS) -c main.cpp
tictactoe.o: tictactoe.cpp tictactoe.hpp
	@ $(CXX) $(CXXFLAGS) -c tictactoe.cpp
clean:
	@ $(RM) $(OBJS) main
run: main
	@ echo "Starting game..."
	@ sleep 2
	./main

.PHONY: all run
