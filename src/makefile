CXX = g++
CXXFLAGS = -std=c++11
RM = rm -f
OBJS = main.o tictactoe.o
SILENT = @

all: run

main: main.o tictactoe.o
	$(SILENT) $(CXX) $(CXXFLAGS) -o main main.o tictactoe.o
main.o: main.cpp tictactoe.hpp
	$(SILENT) $(CXX) $(CXXFLAGS) -c main.cpp
tictactoe.o: tictactoe.cpp tictactoe.hpp
	$(SILENT) $(CXX) $(CXXFLAGS) -c tictactoe.cpp
clean:
	$(SILENT) $(RM) $(OBJS) main
run: main
	$(SILENT) echo "Starting game..."
	$(SILENT) sleep 2
	./main

.PHONY: all run
