#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

#define MAX_JUGADORES 5

class Jugador{
private:
    string nickname;
    int edad;
    string contrasenia;
public:
    Jugador();
    Jugador(string nick, int e, string contra);
        
    ~Jugador();

    void setNick(string nick);
    void setEdad(int e);
    void setContra(string contra);

    string getNick();
    int getEdad();
    string getContra();
};

#endif // JUGADOR_H_INCLUDED
