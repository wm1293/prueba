#ifndef _DTFECHAHORA_H_
#define _DTFECHAHORA_H_

class DtFechaHora{
private:
    int dia, mes, anio, hora, minuto;
public:
    DtFechaHora();
    DtFechaHora(int d, int m, int a, int h, int minu);
        
    ~DtFechaHora(){}

    int getDia(); 
    int getMes(); 
    int getAnio(); 
    int getHora(); 
    int getMinuto(); 
};

#endif //_DTFECHAHORA_H_