#include "./PartidaMultijugador.h"
#include "./DtFechaHora.h"

PartidaMultijugador::PartidaMultijugador(float d, DtFechaHora *f, Jugador *j, bool t, Jugador** participantes, int ultimo){
        setDuracion(d);
        setFecha(f);
        setHost(j);
        setTransmicion(t);
        setParticipantes(participantes);
        setUltimo(ultimo);
    }
void PartidaMultijugador::setTransmicion(bool t){ this->transmitida=t; }
bool PartidaMultijugador::getTransmicion(){ return transmitida; }

void PartidaMultijugador::setParticipantes(Jugador** j){ this->participantes=j; }
Jugador** PartidaMultijugador::getParticipantes(){ return participantes; }

void PartidaMultijugador::setUltimo(int u){ this->ultimoParticipante=u; }
int PartidaMultijugador::getUltimo(){ return ultimoParticipante; }