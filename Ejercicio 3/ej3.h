#ifndef EJ3_H
#define EJ3_H

#include <iostream>
#include <complex>
#include <string>

using namespace std;

template <typename T>
class Numero {
public:
    virtual T suma(T a, T b) = 0;       // en cada instancia de T se reemplaza por el argumento del tipo corresponidiente
    virtual T resta(T a, T b) = 0;
    virtual T multiplicacion(T a, T b) = 0;

    virtual string toString(T num) const = 0;

    virtual ~Numero() {}  
};

class Entero : public Numero<int> {
public:
    int suma(int a, int b) override;
    int resta(int a, int b) override;
    int multiplicacion(int a, int b) override;

    string toString(int num) const override;
};

class Real : public Numero<double> {
public:
    double suma(double a, double b) override;
    double resta(double a, double b) override;
    double multiplicacion(double a, double b) override;

    string toString(double num) const override;
};

class Complejo {
public:
    complex<double> suma(double real1, double imag1, double real2, double imag2);
    complex<double> resta(double real1, double imag1, double real2, double imag2);
    complex<double> multiplicacion(double real1, double imag1, double real2, double imag2);

    string toString(const complex<double>& num) const;
};

#endif