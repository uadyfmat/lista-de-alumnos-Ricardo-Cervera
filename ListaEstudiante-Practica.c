//Ricardo Antonio Cervera Chacon

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Alumno {
    char nombre[100];
    int creditos;
    int semestre;
};

typedef struct Alumno Alumno;

struct Nodo {
    Alumno dato;
    struct Nodo* siguiente;
};

typedef struct Nodo Nodo;
typedef Nodo* NodoPtr;

Alumno crearAlumno(char nombre[], int creditos, int semestre) {
    Alumno alumno;
    strcpy(alumno.nombre, nombre);
    alumno.creditos = creditos;
    alumno.semestre = semestre;
    return alumno;
}

void imprimirAlumno(Alumno alumno) {
    printf("Nombre: %s\n", alumno.nombre);
    printf("Creditos: %d\n", alumno.creditos);
    printf("Semestre Equivalente: %d\n\n", alumno.semestre);
}

NodoPtr crearNodo(Alumno alumno) {
    NodoPtr nuevoNodo = (NodoPtr)malloc(sizeof(Nodo));
    nuevoNodo->dato = alumno;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

int insertarNodoOrdenadoCreditos(NodoPtr* cabeza, NodoPtr nuevoNodo) {
    if (*cabeza == NULL || nuevoNodo->dato.creditos > (*cabeza)->dato.creditos) {
        nuevoNodo->siguiente = *cabeza;
        *cabeza = nuevoNodo;
        return 1;
    }
    
    NodoPtr actual = *cabeza;
    while (actual->siguiente != NULL && nuevoNodo->dato.creditos <= actual->siguiente->dato.creditos) {
        actual = actual->siguiente;
    }
    
    nuevoNodo->siguiente = actual->siguiente;
    actual->siguiente = nuevoNodo;
    return 1;
}

void imprimirLista(NodoPtr cabeza) {
    NodoPtr actual = cabeza;
    while (actual != NULL) {
        imprimirAlumno(actual->dato);
        actual = actual->siguiente;
    }
}

int main() {
    NodoPtr lista = NULL;

    Alumno alumno1 = crearAlumno("Roberto Solis", 120, 5);
    Alumno alumno2 = crearAlumno("Lorena Perera", 90, 4);
    Alumno alumno3 = crearAlumno("Ricardo Garcia", 150, 6);
    Alumno alumno4 = crearAlumno("Jesus Mendez", 80, 3);
    Alumno alumno5 = crearAlumno("Santiago Cervera", 110, 5);

    insertarNodoOrdenadoCreditos(&lista, crearNodo(alumno1));
    insertarNodoOrdenadoCreditos(&lista, crearNodo(alumno2));
    insertarNodoOrdenadoCreditos(&lista, crearNodo(alumno3));
    insertarNodoOrdenadoCreditos(&lista, crearNodo(alumno4));
    insertarNodoOrdenadoCreditos(&lista, crearNodo(alumno5));

    printf("Lista de alumnos:\n");
    imprimirLista(lista);

    return 0;
}