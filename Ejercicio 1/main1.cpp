#include "ej1.h"
#include <iostream>
#include <thread>  
#include <chrono>   

using namespace std;

int main(){
    int h = 0, m = 0, s = 0;
    bool es_am = true;

    solicitarTiempo(h, m, s, es_am);
    Tiempo t(h, m, s, es_am);

    this_thread::sleep_for(chrono::seconds(1));

    int opcion = comoVer();
    t.mostrarTiempoPorPartes(opcion);

    this_thread::sleep_for(chrono::seconds(1));

    t.tiempoEn24Horas();

    return 0;
}