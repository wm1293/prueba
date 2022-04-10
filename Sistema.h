#ifndef _SISTEMA_H_
#define _SISTEMA_H_
#include "Jugador.h"
#include "Partida.h"
#include "Videojuego.h"
#include <iostream>
#include <string>



using namespace std;
class Jugador;

class Sistema {
private:
    Jugador** jugadores = new Jugador*[MAX_JUGADORES];
    
    int ultimoJug=0;
    

    Videojuego** videojuegos = new Videojuego*[MAX_VIDEOJUEGOS];
    
    int ultimoVid=0;
public:
     Sistema();
    ~Sistema();

    //CONTROLADOR JUGADOR
    void agregarJugador(string n, int e, string c);
    void mostrarJugadores();
    bool existeJugador(string n);
    Jugador* devolverJugador(string n);

    //CONTROLADOR VIDEOJUEGO
    void agregarVideojuego(string n, TipoJuego g);
    void mostrarVideojuegos();
    bool existeVideojuego(string n);
    Videojuego* devolverVideojuego(string n);

    //CONTROLADOR PARTIDA
    void iniciarPartida(string nombreVideojuego, string nickHost, DtFechaHora *fecha);
    void mostrarPartida(string nombreVideojuego);
};

#endif // _SISTEMA_H_
