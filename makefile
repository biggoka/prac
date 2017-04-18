OBJS = main.o depend.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

main : $(OBJS)	
	$(CC) $(LFLAGS) $(OBJS) -o main
	./main

go :
	make && clear && ./main

main.o : main.cpp main.h depend.h
	$(CC) $(CFLAGS) main.cpp
