#include "./Videojuego.h"

void Videojuego::mostrarPartidas(){
    cout<<"***PARTIDAS***"<<endl;
        //LISTAR PARTIDAS INDIVIDUALES
        int aux=0;

        while (aux<ultimoPI){
            cout<<"Individual: "<<pI[aux]->getDuracion()<<endl;
            cout<<"Fecha: "<<pI[aux]->getFecha()->getDia()<<"/"<<pI[aux]->getFecha()->getMes()<<"/"<<pI[aux]->getFecha()->getAnio()<<" "<<pI[aux]->getFecha()->getHora()<<":"<<pI[aux]->getFecha()->getMinuto()<<endl;
            cout<<"Host: "<<pI[aux]->getHost()->getNick()<<endl;
            cout<<endl;
            aux++;
        }

        //LISTAR PARTIDAS MULTIJUGADOR
        int aux2=0;

        while (aux2<ultimoPM){
            cout<<"Multijugador: "<<pM[aux2]->getDuracion()<<endl;
            cout<<"Fecha: "<<pM[aux2]->getFecha()->getDia()<<"/"<<pM[aux2]->getFecha()->getMes()<<"/"<<pM[aux2]->getFecha()->getAnio()<<" "<<pM[aux2]->getFecha()->getHora()<<":"<<pM[aux2]->getFecha()->getMinuto()<<endl;
            cout<<"Host: "<<pM[aux2]->getHost()->getNick()<<endl;

            Jugador** auxParticipantes = pM[aux2]->getParticipantes();
            int auxUltimoParticipantes = pM[aux2]->getUltimo();

            int aux3=0;
            cout<<"Participantes:"<<endl;
            while (aux3<auxUltimoParticipantes){
                cout<<auxParticipantes[aux3]->getNick()<<" /// "<<auxParticipantes[aux3]->getEdad()<<" /// "<<auxParticipantes[aux3]->getContra()<<endl;
                aux3++;
            }
            cout<<endl;
            aux2++;

        }
}
void Videojuego::setNombre(string n){ this->nombre=n; }
void Videojuego::setGenero(TipoJuego g){ this->genero=g; }

string Videojuego::getNombre(){ return nombre; }
TipoJuego Videojuego::getGenero(){ return genero; }

void Videojuego::setUltimoPI(int i){ this->ultimoPI=i; }
void Videojuego::setUltimoPM(int i){ this->ultimoPM=i; }

int Videojuego::getUltimoPI(){ return ultimoPI; }
int Videojuego::getUltimoPM(){ return ultimoPM; }

string Videojuego::traducirGenero(){
    switch(this->getGenero()){
        case 0:
            return "ACCION";
        case 1:
            return "AVENTURA";
        case 2:
            return "DEPORTE";
        case 3:
            return "OTRO";
    }
    return NULL;
}

void Videojuego::agregarPartidaIndividual(PartidaIndividual* p){
    pI[ultimoPI]=p;
    ultimoPI++;
}

void Videojuego::agregarPartidaMultijugador(PartidaMultijugador *p){
    pM[ultimoPM]=p;
    ultimoPM++;
}