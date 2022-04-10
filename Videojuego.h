#ifndef VIDEOJUEGO_H_INCLUDED
#define VIDEOJUEGO_H_INCLUDED
#include "Partida.h"
#include "PartidaIndividual.h"
#include "PartidaMultijugador.h"

#include <iostream>
#include <string>
using namespace std;

#define MAX_VIDEOJUEGOS 5

enum TipoJuego{
    ACCION,
    AVENTURA,
    DEPORTE,
    OTRO
};

class Videojuego{
private:
    string nombre;
    TipoJuego genero;
    PartidaIndividual** pI = new PartidaIndividual*[MAX_PARTIDAS];
    int ultimoPI=0;
    PartidaMultijugador** pM = new PartidaMultijugador*[MAX_PARTIDAS];
    int ultimoPM=0;

public:
    Videojuego(){}
    Videojuego(string n, TipoJuego g){
        setNombre(n);
        setGenero(g);
    }
    ~Videojuego();

    void setNombre(string n);
    void setGenero(TipoJuego g);
    void setUltimoPI(int i);
    void setUltimoPM(int i);

    string getNombre();
    TipoJuego getGenero();

    int getUltimoPI();
    int getUltimoPM();

    string traducirGenero();

    void agregarPartidaIndividual(PartidaIndividual* p);
    void agregarPartidaMultijugador(PartidaMultijugador *p);

    void mostrarPartidas();

};

#endif // VIDEOJUEGO_H_INCLUDED
