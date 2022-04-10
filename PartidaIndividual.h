#ifndef _PARTIDAINDIVIDUAL_H_
#define _PARTIDAINDIVIDUAL_H_

#include "./Partida.h"
#include "./DtFechaHora.h"

class PartidaIndividual: public Partida{
private:
    bool continua; //Es continua?
public:
    PartidaIndividual();
    PartidaIndividual(float d, DtFechaHora *f, Jugador *j, bool c);
    ~PartidaIndividual();

    void setContinua(bool c);
    bool getContinua();

};

#endif