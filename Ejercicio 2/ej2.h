#ifndef EJ2_H
#define EJ2_H

#include <vector>
#include <memory>
#include <iostream>
#include <algorithm>

using namespace std;

class Estudiante {
private:
    string nombre;
    int legajo;
    vector<double> notas_finales;

public:
    Estudiante(string nombre, int legajo);
    void agregarNota(double nota);            
    double calcularPromedio() const; 
    int obtenerLegajo() const;  
    string obtenerNombre() const; 

    // operador '<' para ordenar por nombre
    bool operator<(const Estudiante& otro) const;

    // sobrecarga de '<<' para imprimir estudiantes
    friend ostream& operator<<(ostream& os, const Estudiante& est);
};

extern vector<unique_ptr<Estudiante>> lista_estudiantes;

Estudiante* buscarEstudianteGlobal(int legajo);

class Curso {
private:
    vector<Estudiante*> estudiantes;

public:
    Curso() = default;
    Curso(const Curso& otro); // constructor de copia
    ~Curso(); // destructor para liberar memoria

    void agregarEstudiante(string nombre, int legajo, double nota_final);
    Estudiante* buscarEstudiante(int legajo);
    bool eliminarEstudiante(int legajo);
    void mostrarEstudiantes() const;
    int cantidadEstudiantes() const;
};

int menu(Curso &curso);

#endif