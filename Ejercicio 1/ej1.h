#ifndef EJ1_H
#define EJ1_H

class Tiempo {
public:
    Tiempo(int h, int m, int s, bool am);
    void mostrarTiempoPorPartes(int opcion) const;
    void tiempoEn24Horas() const;
    
private:
    int horas, minutos, segundos;
    bool es_am;
};

void solicitarTiempo(int &h, int &m, int &s, bool &es_am);
int comoVer();

#endif