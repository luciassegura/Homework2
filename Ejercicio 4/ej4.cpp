#include "ej4.h"
#include <thread>  
#include <chrono>  
using namespace std;

CuentaBanco::CuentaBanco(string titular, double saldoInicial){
    titularCuenta = titular;
    balance = saldoInicial;
}

void CuentaBanco::depositar(double cantidad){
    if(cantidad > 0){
        balance += cantidad;
    }
}   

CajaDeAhorro::CajaDeAhorro(string titular, double saldoInicial)
    : CuentaBanco(titular, saldoInicial), contador_mostrarInfo(0) {}

void CajaDeAhorro::depositar(double cantidad){
    if(cantidad > 0){
        balance += cantidad;
    }
    cout << "Se depositaron $ " << cantidad << " en la caja de ahorro." << endl;
}

void CajaDeAhorro::retirar(double cantidad) {
    if(cantidad > balance){
        cout << "Fondos insuficientes en la Caja de Ahorro.\n";
    } else {
        balance -= cantidad;
        cout << "Se retiró el dinero. Le quedan: $ " << balance << " en la caja de ahorro." << endl;
    }
}

void CajaDeAhorro::mostrarInfo() const {
    contador_mostrarInfo++;
    cout << "\nTitular: " << titularCuenta << endl;
    cout << "Balance: $" << balance << endl;
    cout << "Tipo de cuenta: Caja de Ahorro" << endl;

    if(contador_mostrarInfo == 2){
        const_cast<CajaDeAhorro*>(this) -> balance -= 20;
        this_thread::sleep_for(chrono::seconds(1));
        cout << "\nSe ha cobrado una tarifa de $20 por consultar muchas veces. Le quedan: $ " << balance << " en la caja de ahorro." << endl;
    }
}

void CuentaCorriente::depositar(double cantidad){
    if(cantidad > 0){
        balance += cantidad;
    }
    cout << "Se depositaron $ " << cantidad << " en la cuenta corriente." << endl;
}

CuentaCorriente::CuentaCorriente(string titular, double saldoInicial, CajaDeAhorro* caja)
    : CuentaBanco(titular, saldoInicial), cajaAhorro(caja) {}

void CuentaCorriente::retirar(double cantidad){
    if(balance >= cantidad){
        balance -= cantidad;
        cout << "Se retiró el dinero. Le quedan: $ " << balance << " en la cuenta corriente." << endl;
    } 
    else if (cajaAhorro && cantidad <= (balance + cajaAhorro -> balance)){
        double restante = cantidad - balance;
        cout << "Fondos insuficientes en la cuenta corriente . . . Pasando a la caja de ahorro." << endl;
        balance = 0;
        cajaAhorro -> balance -= restante;
        this_thread::sleep_for(chrono::seconds(1));
        cout << "Se retiró el dinero. Le quedan: $ " << cajaAhorro -> balance << " en la caja de ahorro." << endl;
    } 
    else {
        cout << "No hay suficiente dinero en la cuenta corriente ni en la caja de ahorro." << endl;
    }
}

void CuentaCorriente::mostrarInfo() const {
    cout << "\nTitular: " << titularCuenta << endl;
    cout << "Balance: $" << balance << endl;
    cout << "Tipo de cuenta: cuenta corriente" << endl;
}
void menu() {
    CajaDeAhorro caja("María López", 250);
    CuentaCorriente corriente("María López", 100, &caja);

    int opcion = 0; 
    while(opcion != 3){
        cout << "\033[1m\n¿Con qué cuenta quiere operar?\033[0m" << endl;
        cout << "1. Caja de Ahorro" << endl;
        cout << "2. Cuenta Corriente" << endl;
        cout << "3. Salir del Banco" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            int opcion2;
            cout << "\033[1m\n¿Qué operación quiere realizar?\033[0m" << endl;
            cout << "1. Retirar dinero" << endl;
            cout << "2. Mostrar información de la cuenta" << endl;
            cout << "3. Depositar" << endl;
            cout << "Ingrese una opción: ";
            cin >> opcion2;

            if(opcion2 == 1){
                double monto;
                cout << "\nIngrese la cantidad a retirar: ";
                cin >> monto;
                caja.retirar(monto);
            } else if(opcion2 == 2){
                caja.mostrarInfo();
            } else if(opcion2 == 3){
                double monto2;
                cout << "\nIngrese la cantidad a depositar: ";
                cin >> monto2;
                caja.depositar(monto2);
            }
            break;
        }
        case 2: {
            int opcion4;
            cout << "\033[1m\n¿Qué operación quiere realizar?\033[0m" << endl;
            cout << "1. Retirar dinero" << endl;
            cout << "2. Mostrar información de la cuenta" << endl;
            cout << "3. Depositar" << endl;
            cout << "Ingrese una opción: ";
            cin >> opcion4;

            if (opcion4 == 1) {
                double monto;
                cout << "\nIngrese la cantidad a retirar: ";
                cin >> monto;
                corriente.retirar(monto);
            } else if (opcion4 == 2) {
                corriente.mostrarInfo();
            } else if(opcion4 == 3){
                double monto2;
                cout << "\nIngrese la cantidad a depositar: ";
                cin >> monto2;
                corriente.depositar(monto2);
            }
            break;
        }
        case 3:
            cout << "\nSaliendo del banco..." << endl;
            break;
        default:
            cout << "Opción no válida. Intente nuevamente.\n";
        }
    }
}
