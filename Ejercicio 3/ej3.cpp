#include "ej3.h"
#include <iomanip>
#include <sstream>

using namespace std;

int Entero::suma(int a, int b) {
    return a + b;
}

int Entero::resta(int a, int b) {
    return a - b;
}

int Entero::multiplicacion(int a, int b) {
    return a * b;
}

string Entero::toString(int num) const {
    return to_string(num);
}

double Real::suma(double a, double b) {
    return a + b;
}

double Real::resta(double a, double b) {
    return a - b;
}

double Real::multiplicacion(double a, double b) {
    return a * b;
}

string Real::toString(double num) const {
    ostringstream oss;
    oss << fixed << setprecision(2) << num;

    string result = oss.str();

    return result;
}

complex<double> Complejo::suma(double real1, double imag1, double real2, double imag2) {
    return complex<double>(real1, imag1) + complex<double>(real2, imag2);
}

complex<double> Complejo::resta(double real1, double imag1, double real2, double imag2) {
    return complex<double>(real1, imag1) - complex<double>(real2, imag2);
}

complex<double> Complejo::multiplicacion(double real1, double imag1, double real2, double imag2) {
    return complex<double>(real1, imag1) * complex<double>(real2, imag2);
}

string Complejo::toString(const complex<double>& num) const {
    ostringstream oss;

    oss << num.real() << " + " << num.imag() << "i";
    
    return oss.str();
}