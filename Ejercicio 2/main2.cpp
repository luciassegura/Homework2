#include "ej2.h"

int main() {
    Curso curso1, curso2; // dos cursos disponibles
    vector<Curso*> cursos = {&curso1, &curso2};

    int curso_seleccionado;

    while (true){ // bucle hasta que el usuario elija salir
        cout << "\n--- Seleccione un curso ---" << endl;
        cout << "1. Matemática" << endl;
        cout << "2. Literatura" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> curso_seleccionado;

        if (curso_seleccionado == 3) {
            cout << "\nSaliendo del programa..." << endl;
            break;  // termina el bucle y finaliza el programa
        }

        if (curso_seleccionado >= 1 && curso_seleccionado <= 3) {
            int opcion;
            do {
                opcion = menu(*cursos[curso_seleccionado - 1]); 
            } while (opcion != 6); // se mantiene en el menú del curso hasta que el usuario elija salir
        } else {
            cout << "Opción inválida. Intente nuevamente." << endl;
        }
    }

    Curso geografia = curso1;
    cout << "\nCurso de Geografía (copia de Matemática):" << endl;
    geografia.mostrarEstudiantes();

    return 0;
}


// tipo de relacion --> agregación: el curso "tiene" al estudiante. Pero ambas clases pueden existir sin la otra.
// Curso almacena los punteros a los estudiantes, no los posee en exclusividad.