#include "./Sistema.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>

using namespace std;

/*
1- Calculo de darTotalHorasParticipantes().
+++Individual: calculo comun
+++Multijugador: calculo comun * participantes
2- Detalle: ver fecha y formato (especialmente year)
3-
*** *** ***
OPERACIONES
1- COMPLETAMENTE IMPLEMENTADA
2- COMPLETAMENTE IMPLEMENTADA
3- Cumple su funcion pero no devuelve Dt ni el int.
4- Cumple su funcion pero no devuelve Dt ni el int. Falta datTotalHorasParticipantes(). Falta diferenciacion.
5- Cumple su funcion pero no devuelve Dt ni el int.
6- COMPLETAMENTE IMPLEMENTADA
*/
void agregarJugador(string,int,string);
void agregarVideojuego(string ,TipoJuego);

int main()
{
    
    Sistema *s = new Sistema();
    int opcion=1;

    //s->agregarJugador ('pipo', 10, 'contra1'); 
    s->agregarJugador("dany",41,"123");   
    s->agregarJugador("pipo2",20,"contra2");
    s->agregarJugador("pipo3",30,"contra3");
    s->agregarVideojuego("fifa",DEPORTE);
    

    while (opcion!=0){
        cout<<"***OPCIONES***"<<endl;
        cout<<"1- Agregar jugador"<<endl;
        cout<<"2- Agregar videojuego"<<endl;
        cout<<"3- Mostrar jugadores"<<endl;
        cout<<"4- Mostrar videojuegos"<<endl;
        cout<<"5- Mostrar partidas"<<endl;
        cout<<"6- Iniciar partida"<<endl;
        cout<<"0- Salir"<<endl;
        cout<<"Seleccionar: ";
        cin >> opcion;
        system("clear");

        switch (opcion){
        case 1: { //AGREGAR JUGADOR
            string nick;
            int edad;
            string contra;

            cout<<"Nickname: ";
            cin.ignore();
            getline(cin, nick);

            cout<<"Edad: ";
            cin >> edad;

            cout<<"Contrasenia: ";
            cin.ignore();
            getline(cin,contra);

            if (s->existeJugador(nick)==false){
                s->agregarJugador(nick,edad,contra);
            } else {
                try{
                    throw invalid_argument("El jugador ya se encuentra registrado");
                } catch(const invalid_argument &ia){
                    cerr << "Invalid argument: " << ia.what() << endl;
                }
            }

        break;}

        case 2: { //AGREGAR VIDEOJUEGO
            string nombre;
            TipoJuego genero;

            cout<<"Nombre: ";
            cin.ignore();
            getline(cin, nombre);

            cout<<"Generos en el sistema:"<<endl;
            cout<<"0- Accion"<<endl;
            cout<<"1- Aventura"<<endl;
            cout<<"2- Deporte"<<endl;
            cout<<"3- Otro"<<endl;
            cout<<"Indique genero: ";
            int opcionGenero;
            cin >> opcionGenero;

            switch (opcionGenero){
            case 0:
                genero=ACCION;
            case 1:
                genero=AVENTURA;
            case 2:
                genero=DEPORTE;
            case 3:
                genero=OTRO;
            }

            if (s->existeVideojuego(nombre)==false){
                s->agregarVideojuego(nombre, genero);
            } else {
                try{
                    throw invalid_argument("El videojuego ya se encuentra registrado");
                } catch(const invalid_argument &ia){
                    cerr << "Invalid argument: " << ia.what() << endl;
                }
            }

        break;}

        case 3: { //MOSTRAR JUGADORES
            s->mostrarJugadores();
        break;}

        case 4: { //MOSTRAR VIDEOJUEGOS
            s->mostrarVideojuegos();
        break;}

        case 5: { //MOSTRAR PARTIDA
            //string nombre;
            //cout<<"Nombre: ";
            //cin.ignore();
            //getline(cin, nombre);
            //s->mostrarPartida(nombre);

            cout<<"Ingresar videojuego: ";
            cin.ignore();
            char nombreVideojuego[100];
            cin.getline(nombreVideojuego,100);

            if (s->existeVideojuego(nombreVideojuego)==false){
                try{
                    throw invalid_argument("El videojuego no existe");
                } catch(const invalid_argument &ia){
                    cerr << "Invalid argument: " << ia.what() << endl;
                }
            } else {
                s->mostrarPartida(nombreVideojuego);

            }

        break;}

        case 6: { //INICIAR PARTIDA
            cout<<"Ingresar videojuego: ";
            cin.ignore();
            char nombreVideojuego[100];
            cin.getline(nombreVideojuego,100);

            if (s->existeVideojuego(nombreVideojuego)==false){
                try{
                    throw invalid_argument("No existe ese videojuego");
                } catch(const invalid_argument &ia){
                    cerr << "Invalid argument: " << ia.what() << endl;
                }
            } else {
                cout<<"Indicar jugador iniciador: ";
                //LA COMPROBACION NO FUNCIONA CON STRING
                char nickHost[100];
                cin.getline(nickHost,100);

                if (s->existeJugador(nickHost)==false){
                    try{
                        throw invalid_argument("No existe ese jugador");
                    } catch(const invalid_argument &ia){
                        cerr << "Invalid argument: " << ia.what() << endl;
                    }
                } else {
                    auto t= time(nullptr); //Auxiliar para obtener la fecha y hora del sistema
                    auto tm=*localtime(&t); //Guarda fecha y hora
                    DtFechaHora *fecha= new DtFechaHora(tm.tm_mday,tm.tm_mon,tm.tm_year,tm.tm_hour,tm.tm_min); //Convierte localtime a DtFechaHora
                    s->iniciarPartida(nombreVideojuego,nickHost,fecha);

                }

            }



        break;}

        case 0: { //SALIR

        break;}

        default: {
            cout<<"Seleccionar opcion valida"<<endl;
        break;}

        }


    }
    return 0;
}
