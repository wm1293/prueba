#include "./DtFechaHora.h"

DtFechaHora::DtFechaHora(){}

DtFechaHora::DtFechaHora(int d, int m, int a, int h, int minu){
        this->dia=d;
        this->mes=m;
        this->anio=a;
        this->hora=h;
        this->minuto=minu;
}

int DtFechaHora::getMes(){
    return this->mes;
}
int DtFechaHora::getAnio(){
    return this->anio;
}
int DtFechaHora::getDia(){
    return this->dia;
}
int DtFechaHora::getMinuto(){
    return this->minuto;
}

