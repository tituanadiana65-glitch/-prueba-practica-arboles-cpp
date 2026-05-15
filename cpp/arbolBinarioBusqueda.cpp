#include "ArbolBinarioBusqueda.h"
#include <queue>
#include <iostream>
#include <limits>

using namespace std;

// Constructor
ArbolBinarioBusqueda::ArbolBinarioBusqueda() {
    raiz = nullptr;
}

// Destructor
ArbolBinarioBusqueda::~ArbolBinarioBusqueda() {
    limpiarArbol(raiz);
}

// Limpiar árbol (eliminar todos los nodos)
void ArbolBinarioBusqueda::limpiarArbol(NodoArbol* nodo) {
    if (nodo != nullptr) {
        limpiarArbol(nodo->izquierdo);
        limpiarArbol(nodo->derecho);
        delete nodo;
    }
}

// Insertar recursivo
NodoArbol* ArbolBinarioBusqueda::insertarRecursivo(NodoArbol* nodo, Estudiante est) {
    if (nodo == nullptr) {
        return new NodoArbol(est);
    }
    
    if (est.getCedula() < nodo->estudiante.getCedula()) {
        nodo->izquierdo = insertarRecursivo(nodo->izquierdo, est);
    } else if (est.getCedula() > nodo->estudiante.getCedula()) {
        nodo->derecho = insertarRecursivo(nodo->derecho, est);
    } else {
        cout << "Error: Ya existe un estudiante con la cedula " << est.getCedula() << endl;
    }
    return nodo;
}

// Insertar directamente (para datos de prueba)
void ArbolBinarioBusqueda::insertarDirecto(Estudiante est) {
    raiz = insertarRecursivo(raiz, est);
}

// Insertar estudiante desde consola
void ArbolBinarioBusqueda::insertarEstudiante() {
    string cedula, apellidos, nombres, carrera, nivel;
    double nota;
    
    cout << "\n--- INSERTAR ESTUDIANTE ---" << endl;
    cout << "Cedula: ";
    cin >> cedula;
    
    // Validar cédula no vacía
    if (cedula.empty()) {
        cout << "Error: Cedula no valida." << endl;
        return;
    }
    
    cout << "Apellidos: ";
    cin.ignore();
    getline(cin, apellidos);
    
    cout << "Nombres: ";
    getline(cin, nombres);
    
    cout << "Nota final (0-10): ";
    cin >> nota;
    
    if (nota < 0 || nota > 10) {
        cout << "Error: Nota fuera de rango. Debe ser entre 0 y 10." << endl;
        return;
    }
    
    cout << "Carrera: ";
    cin.ignore();
    getline(cin, carrera);
    
    cout << "Nivel: ";
    getline(cin, nivel);
    
    Estudiante nuevo(cedula, apellidos, nombres, nota, carrera, nivel);
    raiz = insertarRecursivo(raiz, nuevo);
    cout << "Estudiante insertado correctamente." << endl;
}

// Buscar recursivo
NodoArbol* ArbolBinarioBusqueda::buscarRecursivo(NodoArbol* nodo, string cedula) {
    if (nodo == nullptr || nodo->estudiante.getCedula() == cedula) {
        return nodo;
    }
    
    if (cedula < nodo->estudiante.getCedula()) {
        return buscarRecursivo(nodo->izquierdo, cedula);
    }
    return buscarRecursivo(nodo->derecho, cedula);
}

// Buscar estudiante
void ArbolBinarioBusqueda::buscarEstudiante() {
    if (raiz == nullptr) {
        cout << "El arbol esta vacio." << endl;
        return;
    }
    
    string cedula;
    cout << "\n--- BUSCAR ESTUDIANTE ---" << endl;
    cout << "Ingrese cedula: ";
    cin >> cedula;
    
    NodoArbol* resultado = buscarRecursivo(raiz, cedula);
    if (resultado != nullptr) {
        cout << "Estudiante encontrado:" << endl;
        resultado->estudiante.mostrar();
    } else {
        cout << "Estudiante no encontrado." << endl;
    }
}

// Encontrar mínimo
NodoArbol* ArbolBinarioBusqueda::encontrarMinimo(NodoArbol* nodo) {
    while (nodo && nodo->izquierdo != nullptr) {
        nodo = nodo->izquierdo;
    }
    return nodo;
}

// Eliminar recursivo
NodoArbol* ArbolBinarioBusqueda::eliminarRecursivo(NodoArbol* nodo, string cedula) {
    if (nodo == nullptr) {
        cout << "Estudiante no encontrado." << endl;
        return nullptr;
    }
    
    if (cedula < nodo->estudiante.getCedula()) {
        nodo->izquierdo = eliminarRecursivo(nodo->izquierdo, cedula);
    } else if (cedula > nodo->estudiante.getCedula()) {
        nodo->derecho = eliminarRecursivo(nodo->derecho, cedula);
    } else {
        // Caso 1: sin hijos o un solo hijo
        if (nodo->izquierdo == nullptr) {
            NodoArbol* temp = nodo->derecho;
            delete nodo;
            cout << "Estudiante eliminado correctamente." << endl;
            return temp;
        } else if (nodo->derecho == nullptr) {
            NodoArbol* temp = nodo->izquierdo;
            delete nodo;
            cout << "Estudiante eliminado correctamente." << endl;
            return temp;
        }
        
        // Caso 2: dos hijos
        NodoArbol* temp = encontrarMinimo(nodo->derecho);
        nodo->estudiante = temp->estudiante;
        nodo->derecho = eliminarRecursivo(nodo->derecho, temp->estudiante.getCedula());
    }
    return nodo;
}

// Eliminar estudiante
void ArbolBinarioBusqueda::eliminarEstudiante() {
    if (raiz == nullptr) {
        cout << "El arbol esta vacio." << endl;
        return;
    }
    
    string cedula;
    cout << "\n--- ELIMINAR ESTUDIANTE ---" << endl;
    cout << "Ingrese cedula: ";
    cin >> cedula;
    
    raiz = eliminarRecursivo(raiz, cedula);
}

// Recorrido inorden
void ArbolBinarioBusqueda::inordenRecursivo(NodoArbol* nodo) {
    if (nodo != nullptr) {
        inordenRecursivo(nodo->izquierdo);
        nodo->estudiante.mostrar();
        inordenRecursivo(nodo->derecho);
    }
}

void ArbolBinarioBusqueda::recorridoInorden() {
    if (raiz == nullptr) {
        cout << "El arbol esta vacio." << endl;
        return;
    }
    cout << "\n--- RECORRIDO INORDEN (Ordenado por cedula) ---" << endl;
    inordenRecursivo(raiz);
}

// Recorrido preorden
void ArbolBinarioBusqueda::preordenRecursivo(NodoArbol* nodo) {
    if (nodo != nullptr) {
        nodo->estudiante.mostrar();
        preordenRecursivo(nodo->izquierdo);
        preordenRecursivo(nodo->derecho);
    }
}

void ArbolBinarioBusqueda::recorridoPreorden() {
    if (raiz == nullptr) {
        cout << "El arbol esta vacio." << endl;
        return;
    }
    cout << "\n--- RECORRIDO PREORDEN ---" << endl;
    preordenRecursivo(raiz);
}

// Recorrido postorden
void ArbolBinarioBusqueda::postordenRecursivo(NodoArbol* nodo) {
    if (nodo != nullptr) {
        postordenRecursivo(nodo->izquierdo);
        postordenRecursivo(nodo->derecho);
        nodo->estudiante.mostrar();
    }
}

void ArbolBinarioBusqueda::recorridoPostorden() {
    if (raiz == nullptr) {
        cout << "El árbol está vacío." << endl;
        return;
    }
    cout << "\n--- RECORRIDO POSTORDEN ---" << endl;
    postordenRecursivo(raiz);
}

// Recorrido por niveles BFS
void ArbolBinarioBusqueda::recorridoPorNiveles() {
    if (raiz == nullptr) {
        cout << "El arbol esta vacio." << endl;
        return;
    }
    
    cout << "\n--- RECORRIDO POR NIVELES (BFS) ---" << endl;
    queue<NodoArbol*> cola;
    cola.push(raiz);
    
    int nivel = 0;
    while (!cola.empty()) {
        int nivelSize = cola.size();
        cout << "Nivel " << nivel << ": ";
        for (int i = 0; i < nivelSize; i++) {
            NodoArbol* actual = cola.front();
            cola.pop();
            cout << actual->estudiante.getCedula() << " ";
            
            if (actual->izquierdo != nullptr) {
                cola.push(actual->izquierdo);
            }
            if (actual->derecho != nullptr) {
                cola.push(actual->derecho);
            }
        }
        cout << endl;
        nivel++;
    }
}

// Contar nodos
int ArbolBinarioBusqueda::contarNodosRecursivo(NodoArbol* nodo) {
    if (nodo == nullptr) return 0;
    return 1 + contarNodosRecursivo(nodo->izquierdo) + contarNodosRecursivo(nodo->derecho);
}

void ArbolBinarioBusqueda::contarNodos() {
    int total = contarNodosRecursivo(raiz);
    cout << "\n--- TOTAL DE ESTUDIANTES ---" << endl;
    cout << "Cantidad: " << total << endl;
}

// Calcular altura
int ArbolBinarioBusqueda::calcularAlturaRecursivo(NodoArbol* nodo) {
    if (nodo == nullptr) return -1;
    int alturaIzq = calcularAlturaRecursivo(nodo->izquierdo);
    int alturaDer = calcularAlturaRecursivo(nodo->derecho);
    return 1 + max(alturaIzq, alturaDer);
}

void ArbolBinarioBusqueda::calcularAltura() {
    int altura = calcularAlturaRecursivo(raiz);
    cout << "\n--- ALTURA DEL ARBOL ---" << endl;
    cout << "Altura: " << altura << endl;
}

// Buscar nota mayor
void ArbolBinarioBusqueda::buscarNotaMayorRecursivo(NodoArbol* nodo, Estudiante*& mayor) {
    if (nodo == nullptr) return;
    if (mayor == nullptr || nodo->estudiante.getNotaFinal() > mayor->getNotaFinal()) {
        mayor = &(nodo->estudiante);
    }
    buscarNotaMayorRecursivo(nodo->izquierdo, mayor);
    buscarNotaMayorRecursivo(nodo->derecho, mayor);
}

void ArbolBinarioBusqueda::buscarNotaMayor() {
    if (raiz == nullptr) {
        cout << "El arbol esta vacio." << endl;
        return;
    }
    
    Estudiante* mayor = nullptr;
    buscarNotaMayorRecursivo(raiz, mayor);
    
    cout << "\n--- ESTUDIANTE CON MAYOR NOTA ---" << endl;
    if (mayor != nullptr) {
        mayor->mostrar();
    }
}

// Buscar nota menor
void ArbolBinarioBusqueda::buscarNotaMenorRecursivo(NodoArbol* nodo, Estudiante*& menor) {
    if (nodo == nullptr) return;
    if (menor == nullptr || nodo->estudiante.getNotaFinal() < menor->getNotaFinal()) {
        menor = &(nodo->estudiante);
    }
    buscarNotaMenorRecursivo(nodo->izquierdo, menor);
    buscarNotaMenorRecursivo(nodo->derecho, menor);
}

void ArbolBinarioBusqueda::buscarNotaMenor() {
    if (raiz == nullptr) {
        cout << "El arbol esta vacio." << endl;
        return;
    }
    
    Estudiante* menor = nullptr;
    buscarNotaMenorRecursivo(raiz, menor);
    
    cout << "\n--- ESTUDIANTE CON MENOR NOTA ---" << endl;
    if (menor != nullptr) {
        menor->mostrar();
    }
}

// Mostrar aprobados
void ArbolBinarioBusqueda::mostrarAprobadosRecursivo(NodoArbol* nodo) {
    if (nodo != nullptr) {
        mostrarAprobadosRecursivo(nodo->izquierdo);
        if (nodo->estudiante.getNotaFinal() >= 7.0) {
            nodo->estudiante.mostrar();
        }
        mostrarAprobadosRecursivo(nodo->derecho);
    }
}

void ArbolBinarioBusqueda::mostrarAprobados() {
    if (raiz == nullptr) {
        cout << "El arbol esta vacio." << endl;
        return;
    }
    
    cout << "\n--- ESTUDIANTES APROBADOS (Nota >= 7) ---" << endl;
    mostrarAprobadosRecursivo(raiz);
}

// Mostrar reprobados
void ArbolBinarioBusqueda::mostrarReprobadosRecursivo(NodoArbol* nodo) {
    if (nodo != nullptr) {
        mostrarReprobadosRecursivo(nodo->izquierdo);
        if (nodo->estudiante.getNotaFinal() < 7.0) {
            nodo->estudiante.mostrar();
        }
        mostrarReprobadosRecursivo(nodo->derecho);
    }
}

void ArbolBinarioBusqueda::mostrarReprobados() {
    if (raiz == nullptr) {
        cout << "El arbol esta vacio." << endl;
        return;
    }
    
    cout << "\n--- ESTUDIANTES REPROBADOS (Nota < 7) ---" << endl;
    mostrarReprobadosRecursivo(raiz);
}