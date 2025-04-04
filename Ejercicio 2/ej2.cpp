#include "ej2.h"
#include <iostream>
#include <algorithm>
#include <memory>

using namespace std;

vector<unique_ptr<Estudiante>> lista_estudiantes;

Estudiante::Estudiante(string nombre, int legajo){      
    this -> nombre = std::move(nombre);
    this -> legajo = legajo;
}

string Estudiante::obtenerNombre() const {
    return nombre;
}

int Estudiante::obtenerLegajo() const {
    return legajo;
}

void Estudiante::agregarNota(double nota){
    notas_finales.push_back(nota);
}

double Estudiante::calcularPromedio() const {
    if (notas_finales.empty()) return 0;
    
    double suma_notas = 0;
    for (double nota : notas_finales) {         
        suma_notas += nota;
    }

    return suma_notas / notas_finales.size();
}

bool Estudiante::operator<(const Estudiante& otro) const { 
    return nombre < otro.nombre;
}

ostream& operator<<(ostream& os, const Estudiante& estudiante){
    os << "Nombre: " << estudiante.nombre << ". Legajo: " << estudiante.legajo << ". Promedio: " << estudiante.calcularPromedio() << endl;
    return os;
}

// busca si un estudiante ya existe en algún curso
Estudiante* buscarEstudianteGlobal(int legajo){
    for (const auto& estudiante : lista_estudiantes){
        if (estudiante -> obtenerLegajo() == legajo){
            return estudiante.get();
        }
    }
    return nullptr;
}

Curso::~Curso() {  
    estudiantes.clear(); 
}

Curso::Curso(const Curso& otro) {
    estudiantes = otro.estudiantes;  // copia los punteros, no los objetos
}

// Para copiar el objeto curso uso shallow copy que solo copia los punteros, no los objetos.
// No crea nuevos estudiantes, solo copia los punteros del curso original. Esto quiere decir que si modifico uno en un curso, cambia en ambos.


int Curso::cantidadEstudiantes() const {
    return estudiantes.size();
}

void Curso::agregarEstudiante(string nombre, int legajo, double nota_final) {
    if (estudiantes.size() == 20) {
        cout << "El curso está completo. No se pueden agregar más estudiantes." << endl;
        return;
    }

    // buscar si el estudiante ya existe en la lista global
    Estudiante* estudiante = buscarEstudianteGlobal(legajo);
    
    if (!estudiante) {
        // si no existe, crearlo y agregarlo a la lista global
        auto nuevo_estudiante = make_unique<Estudiante>(nombre, legajo);
        estudiante = nuevo_estudiante.get();
        lista_estudiantes.push_back(std::move(nuevo_estudiante));
    }

    estudiante -> agregarNota(nota_final);
    estudiantes.push_back(estudiante);  // guarda el puntero, no una copia

    cout << "\nEstudiante " << nombre << " agregado/a al curso con nota final: " << nota_final << endl;
}

Estudiante* Curso::buscarEstudiante(int legajo) {
    for (Estudiante* estudiante : estudiantes) {
        if (estudiante->obtenerLegajo() == legajo) {
            return estudiante;
        }
    }
    return nullptr;
}

bool Curso::eliminarEstudiante(int legajo) {
    for (auto it = estudiantes.begin(); it != estudiantes.end(); ++it) {
        if ((*it) -> obtenerLegajo() == legajo) {
            cout << "Estudiante con legajo " << legajo << " eliminado del curso." << endl;
            estudiantes.erase(it);
            return true;
        }
    }
    cout << "Estudiante con legajo " << legajo << " no encontrado en este curso." << endl;
    return false;
}

void Curso::mostrarEstudiantes() const {
    if (estudiantes.empty()) {
        cout << "\nNo hay estudiantes en el curso." << endl;
        return;
    }

    // crear una lista de punteros para ordenar sin modificar el vector original
    vector<Estudiante*> estudiantesOrdenados = estudiantes;

    sort(estudiantesOrdenados.begin(), estudiantesOrdenados.end(),
         [](const Estudiante* a, const Estudiante* b) { return *a < *b; });

    cout << "\nLista de estudiantes\n" << endl;
    for (const auto& estudiante : estudiantesOrdenados) {
        cout << *estudiante << endl;
    }
}


int menu(Curso &curso){
    int opcion;
    
    cout << "\n----- MENU -----\n";
    cout << "1. Inscribir estudiante" << endl;
    cout << "2. Desinscribir estudiante" << endl;
    cout << "3. Buscar estudiante" << endl;
    cout << "4. Ver si el curso esta completo" << endl;
    cout << "5. Mostrar estudiantes" << endl;
    cout << "6. Salir" << endl;
    cout << "Seleccione una opción: ";
    cin >> opcion;

    switch (opcion) {
        case 1: {
            string nombre;
            int legajo;
            double nota_final;

            cout << "\nIngrese el nombre del estudiante: ";
            cin.ignore();
            getline(cin, nombre);
            cout << "Ingrese el legajo: ";
            cin >> legajo;
            cout << "Ingrese la nota final: ";
            cin >> nota_final;

            curso.agregarEstudiante(nombre, legajo, nota_final);
            break;
        }
        case 2: {
            int legajo;
            cout << "\nIngrese el legajo del estudiante: ";
            cin >> legajo;
            curso.eliminarEstudiante(legajo);
            break;
        }
        case 3: {
            int legajo;
            cout << "\nIngrese el legajo del estudiante a buscar: ";
            cin >> legajo;
            
            Estudiante* estudiante = curso.buscarEstudiante(legajo);
            if (estudiante) {
                cout << "\nEl/la estudiante es: " << estudiante -> obtenerNombre() << endl;
            } else {
                cout << "\nEstudiante no encontrado." << endl;
            }
            break;
        }
        case 4: {
            if (curso.cantidadEstudiantes() == 20) {
                cout << "\nEl curso está completo." << endl;
            } else {
                cout << "\nEl curso no está completo. Tiene " << curso.cantidadEstudiantes() << " estudiantes." << endl;
            }
            break;
        }
        case 5:
            curso.mostrarEstudiantes();  
            break;
        case 6:
            cout << "\nSaliendo del curso...\n";
            break;
        default:
            cout << "\nOpción no válida. Intente de nuevo.\n";
    }
    return opcion;
}