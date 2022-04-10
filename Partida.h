#ifndef _PARTIDA_H_
#define _PARTIDA_H_

#include "Jugador.h"
#include "./DtFechaHora.h"
#include <iostream>
#include <string>
using namespace std;

#define MAX_PARTIDAS 5

class Partida {
private:
    float duracion;
    DtFechaHora *fecha;
    Jugador* hosteador;

public:
    Partida();
    Partida(float d, DtFechaHora *f, Jugador *h);
        
    ~Partida();

    void setDuracion(float d);
    void setFecha(DtFechaHora* f);
    void setHost(Jugador* j);

    float getDuracion();
    DtFechaHora* getFecha();
    Jugador* getHost();


};

#endif // PARTIDA_H_
