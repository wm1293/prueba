#ifndef _PARTIDAMULTIJUGADOR_H_
#define _PARTIDAMULTIJUGADOR_H_

#include "./Partida.h"
#include "./DtFechaHora.h"

class PartidaMultijugador: public Partida{
private:
    bool transmitida; //Es transmitida en vivo?
    Jugador** participantes= new Jugador*[MAX_JUGADORES];
    int ultimoParticipante=0;
public:
    PartidaMultijugador();
    PartidaMultijugador(float d, DtFechaHora *f, Jugador *j, bool t, Jugador** participantes, int ultimo);
       
    ~PartidaMultijugador();

    void setTransmicion(bool t);
    bool getTransmicion();

    void setParticipantes(Jugador** j);
    Jugador** getParticipantes();

    void setUltimo(int u);
    int getUltimo();

};

#endif