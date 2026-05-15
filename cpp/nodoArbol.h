#ifndef NODOARBOL_H
#define NODOARBOL_H

#include "estudiante.h"

class NodoArbol {
public:
    Estudiante estudiante;
    NodoArbol* izquierdo;
    NodoArbol* derecho;

    // Constructor
    NodoArbol(const Estudiante& est);
};

#endif