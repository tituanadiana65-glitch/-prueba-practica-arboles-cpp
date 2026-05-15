#ifndef ARBOLBINARIOBUSQUEDA_H
#define ARBOLBINARIOBUSQUEDA_H

#include "NodoArbol.h"

class ArbolBinarioBusqueda {
private:
    NodoArbol* raiz;

    // Métodos privados recursivos
    NodoArbol* insertarRecursivo(NodoArbol* nodo, Estudiante est);
    NodoArbol* buscarRecursivo(NodoArbol* nodo, string cedula);
    NodoArbol* encontrarMinimo(NodoArbol* nodo);
    NodoArbol* eliminarRecursivo(NodoArbol* nodo, string cedula);
    
    void inordenRecursivo(NodoArbol* nodo);
    void preordenRecursivo(NodoArbol* nodo);
    void postordenRecursivo(NodoArbol* nodo);
    
    int contarNodosRecursivo(NodoArbol* nodo);
    int calcularAlturaRecursivo(NodoArbol* nodo);
    
    void buscarNotaMayorRecursivo(NodoArbol* nodo, Estudiante*& mayor);
    void buscarNotaMenorRecursivo(NodoArbol* nodo, Estudiante*& menor);
    
    void mostrarAprobadosRecursivo(NodoArbol* nodo);
    void mostrarReprobadosRecursivo(NodoArbol* nodo);

public:
    // Constructor y destructor
    ArbolBinarioBusqueda();
    ~ArbolBinarioBusqueda();
    
    // Métodos públicos
    void insertarEstudiante();
    void buscarEstudiante();
    void eliminarEstudiante();
    
    void recorridoInorden();
    void recorridoPreorden();
    void recorridoPostorden();
    void recorridoPorNiveles();
    
    void contarNodos();
    void calcularAltura();
    
    void buscarNotaMayor();
    void buscarNotaMenor();
    
    void mostrarAprobados();
    void mostrarReprobados();
    
    // Método para limpiar el árbol
    void limpiarArbol(NodoArbol* nodo);
    
    // Método para insertar directamente (para datos de prueba)
    void insertarDirecto(Estudiante est);
};

#endif