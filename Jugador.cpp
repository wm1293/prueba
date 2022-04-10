#include "./Jugador.h"

Jugador::Jugador(){

}

Jugador::Jugador(string nick, int e, string contra){
    this->nickname = nick;
    this->edad = e;
    this->contrasenia = contra;
}

void Jugador::setNick(string nick){ this->nickname=nick; }
void Jugador::setEdad(int e){ this->edad=e; }
void Jugador::setContra(string contra){ this->contrasenia=contra; }

string Jugador::getNick(){ 
    return this->nickname; 
}
int Jugador::getEdad(){ 
    return this->edad; 
}
string Jugador::getContra(){ 
    return this->contrasenia;
}
