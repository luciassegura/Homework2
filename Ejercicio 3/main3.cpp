#include "ej3.h"
#include <iostream>
#include <complex>  

using namespace std;

int main() {
    Entero e;
    Real r;
    Complejo c;

    int sumaE = e.suma(3, 2);
    int restaE = e.resta(4, 5);
    int multiplicacionE = e.multiplicacion(2, 8);

    double sumaR = r.suma(3.5, 2.8); 
    double restaR = r.resta(4.6, 1.1);
    double multiplicacionR = r.multiplicacion(2.1, 3.5);

    complex<double> sumaC = c.suma(8, 1, 7, 5);
    complex<double> restaC = c.resta(3, 2, 1, -4);
    complex<double> multiplicacionC = c.multiplicacion(2, 1, 1, 5);

    cout << "\033[32m" << "\nOperaciones con enteros" << "\033[0m" << endl;
    cout << "\033[4mSuma:\033[0m 3 + 2 = " << e.toString(sumaE) << endl;
    cout << "\033[4mResta:\033[0m 4 - 5 = " << e.toString(restaE) << endl;
    cout << "\033[4mMultiplicación:\033[0m 2 * 8 = " << e.toString(multiplicacionE) << endl;

    cout << "\033[32m" << "\nOperaciones con reales" << "\033[0m" << endl;
    cout << "\033[4mSuma:\033[0m 3.5 + 2.8 = " << r.toString(sumaR) << endl;   
    cout << "\033[4mResta:\033[0m 4.6 - 1.1 = " << r.toString(restaR) << endl;   
    cout << "\033[4mMultiplicación:\033[0m 2.1 * 3.5 = " << r.toString(multiplicacionR) << endl;   

    cout << "\033[32m" << "\nOperaciones con complejos" << "\033[0m" << endl;
    cout << "\033[4mSuma:\033[0m (8 + i) + (7 + 5i) = " << c.toString(sumaC) << endl;   
    cout << "\033[4mResta:\033[0m (3 + 2i) - (1 - 4i) = " << c.toString(restaC) << endl;   
    cout << "\033[4mMultiplicación:\033[0m (2 + i) * (1 + 5i) = " << c.toString(multiplicacionC) << endl;  

    return 0;
}