#include "./Sistema.h"
#include "./Jugador.h"
#include "./Partida.h"
#include "./Videojuego.h"
#include "./DtFechaHora.h"
#include "./PartidaIndividual.h"
#include "./PartidaMultijugador.h"

Sistema::Sistema(){}

//CONTROLADOR JUGADOR
void Sistema::agregarJugador(string n, int e, string c){
    if (ultimoJug==MAX_JUGADORES){
        cout<<"Superado maximo jugadores"<<endl;
    } else{
        Jugador *aux = new Jugador(n, e, c);
        jugadores[ultimoJug]=aux;
        ultimoJug++;
    }

}

void Sistema::mostrarJugadores(){
    int aux=0;
    cout<<"***JUGADORES EN EL SISTEMA***"<<endl;
    cout<<"NOMBRE /// EDAD /// CONTRASENIA"<<endl;
    while(aux<ultimoJug){
        cout<<jugadores[aux]->getNick()<<" /// "<<jugadores[aux]->getEdad()<<" /// "<<jugadores[aux]->getContra()<<endl;
        aux++;
    }
}

bool Sistema::existeJugador(std::string n){
    int aux=0;
    bool retorno=false;
    while (aux<ultimoJug){
        if (jugadores[aux]->getNick()==n){
            retorno=true;
        }
        aux++;
    }
    return retorno;
}

Jugador* Sistema::devolverJugador(string n){
    int aux=0;
    
    while (aux<ultimoJug){
        if (jugadores[aux]->getNick()==n){
            return jugadores[aux];            
        }
        aux++;
    }
    
    return NULL;
}

//CONTROLADOR VIDEOJUEGO
void Sistema::agregarVideojuego(string n, TipoJuego g){
    if (ultimoVid==MAX_VIDEOJUEGOS){
        cout<<"Superado maximo videojuegos"<<endl;
    } else{
        Videojuego *aux = new Videojuego(n,g);
        videojuegos[ultimoVid]=aux;
        ultimoVid++;
    }
}

void Sistema::mostrarVideojuegos(){
    int aux=0;
    cout<<"***VIDEOJUEGOS EN EL SISTEMA***"<<endl;
    cout<<"NOMBRE /// GENERO"<<endl;
    while (aux<ultimoVid){
        cout<<videojuegos[aux]->getNombre()<<" /// "<<videojuegos[aux]->traducirGenero()<<endl;
        aux++;
    }
}

bool Sistema::existeVideojuego(string n){
    int aux=0;
    bool retorno=false;

    while (aux<ultimoVid){
        if (videojuegos[aux]->getNombre()==n){
            retorno=true;
        }
        aux++;
    }
    return retorno;
}

Videojuego* Sistema::devolverVideojuego(string n)
{
    int aux=0;
    
    while (aux<ultimoVid){
        if (videojuegos[aux]->getNombre()==n){
            return videojuegos[aux];
        }
        aux++;
    }

    return NULL;    
}

//CONTROLADOR PARTIDA
void Sistema::iniciarPartida(string nombreVideojuego, string nickHost, DtFechaHora *fecha){

    Jugador* auxJugadorHost = devolverJugador(nickHost);

    int aux=0;

    while(aux<ultimoVid){
        if (videojuegos[aux]->getNombre()==nombreVideojuego){
            //Situado en el videojuego

            int opcionPartida;
            cout<<"TIPO DE PARTIDA"<<endl;
            cout<<"1- Individual"<<endl;
            cout<<"2- Multijugador"<<endl;
            cout<<"Indicar: ";
            cin >> opcionPartida;

            if (opcionPartida == 1){
                //Individual
                cout<<"Es continuacion?"<<endl;
                cout<<"1- Si"<<endl;
                cout<<"2- No"<<endl;
                cout<<"Indicar: ";
                int opcionContinuacion;
                cin >> opcionContinuacion;

                bool continuacion;
                if (opcionContinuacion==1){
                    continuacion=true;
                } else {
                    continuacion=false;
                }

                PartidaIndividual *auxPartida = new PartidaIndividual(0,fecha,auxJugadorHost,continuacion);
                
                int ultimoPI = videojuegos[aux]->getUltimoPI();
                if (ultimoPI==MAX_PARTIDAS){

                    cout<<"Alcazado limite de partidas individuales"<<endl;
                } else {
                    videojuegos[aux]->agregarPartidaIndividual(auxPartida);
                }

            } else {
                //Multijugador
                cout<<"Es transmitida en vivo?"<<endl;
                cout<<"1- Si"<<endl;
                cout<<"2- No"<<endl;
                cout<<"Indicar: ";
                int opcionTransmitida;
                cin >> opcionTransmitida;

                bool transmicion;
                if (opcionTransmitida==1){
                    transmicion=true;
                } else {
                    transmicion=false;
                }

                Jugador** participantes = new Jugador*[MAX_JUGADORES];
                int ultimo=0;

                int opcionSalir=1;
                while (opcionSalir==1){
                    cout<<"Agregar participante?"<<endl;
                    cout<<"1- Si"<<endl;
                    cout<<"2- No"<<endl;
                    cout<<"Indicar: ";
                    cin >> opcionSalir;

                    if (opcionSalir==1){
                        cout<<"Indicar nickname: ";
                        cin.ignore();
                        char nombreParticipante[100];
                        cin.getline(nombreParticipante,100);

                        if (existeJugador(nombreParticipante)==false){
                            cout<<"No existe ese jugador"<<endl;
                        } else {

                            if (ultimo==MAX_JUGADORES){
                                cout<<"Alcanzado tope de participantes"<<endl;
                                opcionSalir=2;
                            } else {
                                Jugador* auxJugadorParticipante = devolverJugador(nombreParticipante);
                                participantes[ultimo]=auxJugadorParticipante;
                                ultimo++;
                            }

                        }

                    } else {
                        opcionSalir=2;
                    }

                }

                PartidaMultijugador *AuxPartida = new PartidaMultijugador(0,fecha,auxJugadorHost,transmicion,participantes,ultimo);

                int ultimoPM = videojuegos[aux]->getUltimoPM();
                if (ultimoPM==MAX_PARTIDAS){
                    cout<<"Alcanzado limite de partidas multijugador"<<endl;
                } else {
                    videojuegos[aux]->agregarPartidaMultijugador(AuxPartida);
                }
            }
        }
        aux++;
    }


}

void Sistema::mostrarPartida(string nombreVideojuego){
    int aux=0;

    while(aux<ultimoVid){
        if (videojuegos[aux]->getNombre()==nombreVideojuego){
        //Situado en el videojuego
        videojuegos[aux]->mostrarPartidas();
        }
    aux++;
    }
}