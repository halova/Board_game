CC = g++
CFLAGS = -Wall -g
VPATH = SRC INCLUDE
all:
    $(CC) $(CFLAGS) -o main {FinalProject.cpp}
run:
    ./main
