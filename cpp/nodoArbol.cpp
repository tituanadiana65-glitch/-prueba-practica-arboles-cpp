#include "nodoArbol.h"

// CORREGIDO: usar const& para evitar copias problemáticas
NodoArbol::NodoArbol(const Estudiante& est) : estudiante(est) {
    izquierdo = nullptr;
    derecho = nullptr;
}