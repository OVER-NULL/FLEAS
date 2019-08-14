CC=g++
CARGS=-std=c++17

build:
	
	$(CC) $(CARGS) -o quark cherry.cpp -lncurses
