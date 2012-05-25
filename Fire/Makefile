# Makefile for CA Model-- Forest fire model
# To build program, just type 'make' in terminal
# To clean, type 'make clean'

CC		=			gcc
TAG		=			-std=c99 -o
TAGC	=			-std=c99 -c
OBJ		=			fire.o init.o prob.o update.o plot.o simulate.o

build:	$(OBJ)
	$(CC) $(OBJ) $(TAG) fire

fire.o: fire.c fire.h
	$(CC) fire.c fire.h $(TAGC) 

init.o: init.c fire.h
	$(CC) init.c fire.h $(TAGC)

prob.o: prob.c fire.h
	$(CC) prob.c fire.h $(TAGC)

update.o: update.c fire.h
	$(CC) update.c fire.h $(TAGC)
	
plot.o: plot.c fire.h
	$(CC) plot.c fire.h $(TAGC)

simulate.o: simulate.c fire.h
	$(CC) simulate.c fire.h $(TAGC)

#install:
#	mkdir Library; mv *.o fire.h.gch Library/

#clean:
#	rm -r Library fire

clean:	
	rm *.o  fire.h.gch fire
