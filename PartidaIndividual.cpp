#include "./PartidaIndividual.h"

PartidaIndividual::PartidaIndividual(float d, DtFechaHora *f, Jugador *j, bool c){
        setDuracion(d);
        setFecha(f);
        setHost(j);
        setContinua(c);
}

void PartidaIndividual::setContinua(bool c){ this->continua=c; }
bool PartidaIndividual::getContinua(){ return continua; }

