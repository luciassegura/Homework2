#include "ej1.h"
#include <iostream>
#include <iomanip>

using namespace std;

Tiempo::Tiempo(int h, int m, int s, bool am) {
    horas = h;
    minutos = m;
    segundos = s;
    es_am = am; // true = a.m., false = p.m.
}

void solicitarTiempo(int &h, int &m, int &s, bool &es_am) {
    int opcion;
    string formato_str;

    cout << "\033[31m" << "\n¿Qué valores desea ingresar?\n" << "\033[0m";
    cout << "\n1. Ningún parámetro\n";
    cout << "2. Solo la hora\n";
    cout << "3. Solo la hora y minutos\n";
    cout << "4. Hora, minutos y segundos con formato\n";
    cout << "\nIngrese una opción: ";
    cin >> opcion;

    switch (opcion) {
        case 1:
            break;
        case 2:
            cout << "Ingrese la hora: ";
            cin >> h;
            while (h < 1 || h > 12) {
                cout << "Valor fuera de rango. Vuelva a ingresar la hora (1-12): ";
                cin >> h;
            }
            break;
        case 3:
            cout << "Ingrese la hora: ";
            cin >> h;
            cout << "Ingrese los minutos: ";
            cin >> m;
            while (h < 1 || h > 12 || m < 0 || m > 59) {
                cout << "Algún valor está fuera de rango. Vuelva a completarlos.\n";
                cout << "Ingrese la hora (1-12): ";
                cin >> h;
                cout << "Ingrese los minutos (0-59): ";
                cin >> m;
            }
            break;
        case 4:
            cout << "Ingrese la hora: ";
            cin >> h;
            cout << "Ingrese los minutos: ";
            cin >> m;
            cout << "Ingrese los segundos: ";
            cin >> s;
            while (h < 1 || h > 12 || m < 0 || m > 59 || s < 0 || s > 59) {
                cout << "Algún valor está fuera de rango. Vuelva a completarlos.\n";
                cout << "Ingrese la hora (1-12): ";
                cin >> h;
                cout << "Ingrese los minutos (0-59): ";
                cin >> m;
                cout << "Ingrese los segundos (0-59): ";
                cin >> s;
            }
            cout << "Ingrese el formato (AM / PM): ";
            cin >> formato_str;

            if (formato_str == "AM" || formato_str == "am") {
                es_am = true;
            } else if (formato_str == "PM" || formato_str == "pm") {
                es_am = false;
            } else {
                cout << "Formato no válido. Se usará AM por defecto.\n";
                es_am = true;
            }
            break;
        default:
            cout << "Opción no válida. Se usará el tiempo por defecto.\n";
            h = 0; m = 0; s = 0; es_am = true;
            break;
    }
}

int comoVer(){
    int opcion;
    cout << "\033[31m" << "\n¿Cómo desea ver la hora?" << "\033[0m" << endl;
    cout << "\n1. Solo la hora" << endl;
    cout << "2. Solo los minutos" << endl;
    cout << "3. Solo los segundos" << endl;
    cout << "4. Todo el formato" << endl;
    cout << "\nIngrese una opción: ";
    cin >> opcion;

    return opcion;
}

void Tiempo::mostrarTiempoPorPartes(int opcion) const {
    switch (opcion) {
        case 1:
            cout << setw(2) << setfill('0') << horas << "h" << endl;
            break;
        case 2:
            cout << setw(2) << setfill('0') << minutos << "m" << endl;
            break;
        case 3:
            cout << setw(2) << setfill('0') << segundos << "s" << endl;
            break;
        case 4:
            cout << setw(2) << setfill('0') << horas << "h, "
            << setw(2) << setfill('0') << minutos << "m, "
            << setw(2) << setfill('0') << segundos << "s "
            << (es_am ? "a.m." : "p.m.") << endl;
            break;
        default:
            cout << "Opción no válida." << endl;
            break;
    }
}

void Tiempo::tiempoEn24Horas() const {
    cout  << "\033[36m" << "\nHora en formato 24 horas: " << "\033[0m";
    
    int horas_24 = horas; 

    if (es_am == false && horas != 12) {  
        horas_24 += 12;  // convertir PM a formato 24 horas 
    } 
    else if (es_am == true && horas == 12) {  
        horas_24 = 0;  // convertir 12 AM a 00 horas
    }

    cout << setw(2) << setfill('0') << horas_24 << ":"
         << setw(2) << setfill('0') << minutos << ":"
         << setw(2) << setfill('0') << segundos << "\n" << endl;
}