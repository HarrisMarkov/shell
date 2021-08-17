#A Simple Example Makefile for soshell
# 
# Alvo: Dependencias
# tab Action 1
# tab Action 2
#
#Variaveis: Compiler, compiler flags, libraries to link, name of of object files
#
CC=cc
FLAGS=-c -Wall
LIBS=-lm -pthread -lpthread
OBS=main.o execute.o parse.o help.o socpy.o warning.o warning_t.o rocket.o isjpeg.o cd.o calc.o redirects.o sols.o
 
#Alvo por defeito é o primeiro 
all :  soshell
 
main.o : shell.h main.c
	$(CC) $(FLAGS) main.c

execute.o : shell.h execute.c
	$(CC) $(FLAGS) execute.c

parse.o : shell.h parse.c
	$(CC) $(FLAGS) parse.c

help.o : shell.h help.c
	$(CC) $(FLAGS) help.c

warning.o : shell.h warning.c
	$(CC) $(FLAGS) warning.c

warning_t.o : shell.h warning_t.c
	$(CC) $(FLAGS) warning_t.c

cd.o : shell.h cd.c
	$(CC) $(FLAGS) cd.c

rocket.o : shell.h rocket.c
	$(CC) $(FLAGS) rocket.c

isjpeg.o : shell.h isjpeg.c
	$(CC) $(FLAGS) isjpeg.c

socpy.o : shell.h socpy.c
	$(CC) $(FLAGS) socpy.c

calc.o : shell.h calc.c
	$(CC) $(FLAGS) calc.c

reditects.o : shell.h reditects.c
	$(CC) $(FLAGS) reditects.c

sols.o : shell.h sols.c
	$(CC) $(FLAGS) sols.c

soshell : $(OBS)
	$(CC)  -o soshell  $(OBS) $(LIBS)

clean limpar:
	rm -f soshell *.o
	rm -f *~
	echo "Limpeza dos ficheiros exectuaveis, objectos e gedit tralha"
