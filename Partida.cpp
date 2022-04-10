#include "./Partida.h"

Partida::Partida(float d, DtFechaHora *f, Jugador *h){
        this->duracion=d;
        this->fecha=f;
        this->hosteador=h;
    }

void Partida::setDuracion(float d){ this->duracion=d; }
void Partida::setFecha(DtFechaHora* f) { this->fecha=f; }
void Partida::setHost(Jugador* j){ this->hosteador=j; }

float Partida::getDuracion(){ return duracion; }
DtFechaHora* Partida::getFecha(){ return fecha; }
Jugador* Partida::getHost(){ return hosteador; }