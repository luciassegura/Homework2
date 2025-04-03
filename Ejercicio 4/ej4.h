#ifndef EJ4_H
#define EJ4_H

#include <iostream>
#include <string>

using namespace std;

class CajaDeAhorro; // declaración para usarla en friend

class CuentaBanco {
    public:
        CuentaBanco(string titular, double saldoInicial); // constructor

        virtual void depositar(double cantidad) = 0;
        virtual void retirar(double cantidad) = 0;
        virtual void mostrarInfo() const = 0;

        virtual ~CuentaBanco() {}  // destructor virtual

    protected:              // para poder acceder desde la clase derivada
        double balance;
        string titularCuenta;
};

class CajaDeAhorro : public CuentaBanco {
    public:
        CajaDeAhorro(string titular, double saldoInicial);

        void depositar(double cantidad) override;
        void retirar(double cantidad) override;
        void mostrarInfo() const override;

    private:
        // double balance; 
        mutable int contador_mostrarInfo;
        friend class CuentaCorriente;           // cuenta corriente tiene acceso a los private y protected de caja de ahorro
};

class CuentaCorriente : public CuentaBanco {
    public:
        CuentaCorriente(string titular, double saldoInicial, CajaDeAhorro* caja);

        void depositar(double cantidad) override;
        void retirar(double cantidad) override;
        void mostrarInfo() const override;

    private:
        // double balance;
        CajaDeAhorro* cajaAhorro;           // cuenta corriente tiene acceso a los private y protected de caja de ahorro
};

void menu();

#endif

// En las tres clases retirar() y mostrarInfo() son públicos porque deben poder ser llamados fuera de la clase
// En la clase Banco son además virtuales porque deben ser sobrescritos en las clases derivadas.

// En la clase Banco, balance y titularCuenta son protegidos porque se tiene que poder acceder desde las clases derivadas.

// Los demás atributos de las clases derivadas son privados porque solo son necesarios en esas clases.