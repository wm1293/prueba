OBJETOS	= Jugador.o Partida.o \
PartidaIndividual.o PartidaMultijugador.o \
Sistema.o Videojuego.o DtFechaHora.o\
main.o


DEF	= Jugador.h Jugador.cpp \
Partida.h Partida.cpp \
PartidaIndividual.h PartidaIndividual.cpp \
PartidaMultijugador.h PartidaMultijugador.cpp \
Sistema.h Sistema.cpp \
Videojuego.h Videojuego.cpp \
DtFechaHora.h DtFechaHora.cpp

CC = g++

OPCIONES = -std=c++11 -g -Wall -Werror

all: Compilador

Compilador: $(OBJETOS)
	$(CC) $(OBJETOS) -o Compilador

main: main.cpp Makefile ./Sistema.h
	$(CC) $(OPCIONES) main.cpp

Jugador.o: ./Jugador.h ./Jugador.cpp
	$(CC) $(OPCIONES) -c ./Jugador.cpp

Partida.o: ./Partida.h ./Partida.cpp
	$(CC) $(OPCIONES) -c ./Partida.cpp

PartidaIndividual.o: ./PartidaIndividual.h ./PartidaIndividual.cpp
	$(CC) $(OPCIONES) -c ./PartidaIndividual.cpp

PartidaMultijugador.o: ./PartidaMultijugador.h ./PartidaMultijugador.cpp
	$(CC) $(OPCIONES) -c ./PartidaMultijugador.cpp

Sistema.o: ./Sistema.h ./Sistema.cpp
	$(CC) $(OPCIONES) -c ./Sistema.cpp

Videojuego.o: ./Videojuego.h ./Videojuego.cpp
	$(CC) $(OPCIONES) -c ./Videojuego.cpp

DtFechaHora.o: ./DtFechaHora.h ./DtFechaHora.cpp
	$(CC) $(OPCIONES) -c ./DtFechaHora.cpp


clean:
	rm -rf *o main 

rebuild:
	make clean 
	make 