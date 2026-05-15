#include "estudiante.h"

// Constructor por defecto
Estudiante::Estudiante() {
    cedula = "";
    apellidos = "";
    nombres = "";
    notaFinal = 0.0;
    carrera = "";
    nivel = "";
}

// Constructor con parámetros
Estudiante::Estudiante(string ced, string ape, string nom, double nota, string carr, string niv) {
    cedula = ced;
    apellidos = ape;
    nombres = nom;
    notaFinal = nota;
    carrera = carr;
    nivel = niv;
}

// Constructor de copia
Estudiante::Estudiante(const Estudiante& otro) {
    cedula = otro.cedula;
    apellidos = otro.apellidos;
    nombres = otro.nombres;
    notaFinal = otro.notaFinal;
    carrera = otro.carrera;
    nivel = otro.nivel;
}

// Operador de asignación
Estudiante& Estudiante::operator=(const Estudiante& otro) {
    if (this != &otro) {
        cedula = otro.cedula;
        apellidos = otro.apellidos;
        nombres = otro.nombres;
        notaFinal = otro.notaFinal;
        carrera = otro.carrera;
        nivel = otro.nivel;
    }
    return *this;
}

// Getters
string Estudiante::getCedula() const { return cedula; }
string Estudiante::getApellidos() const { return apellidos; }
string Estudiante::getNombres() const { return nombres; }
double Estudiante::getNotaFinal() const { return notaFinal; }
string Estudiante::getCarrera() const { return carrera; }
string Estudiante::getNivel() const { return nivel; }

// Setters
void Estudiante::setCedula(string ced) { cedula = ced; }
void Estudiante::setApellidos(string ape) { apellidos = ape; }
void Estudiante::setNombres(string nom) { nombres = nom; }
void Estudiante::setNotaFinal(double nota) { notaFinal = nota; }
void Estudiante::setCarrera(string carr) { carrera = carr; }
void Estudiante::setNivel(string niv) { nivel = niv; }

// Sobrecarga de operadores
bool Estudiante::operator<(const Estudiante& otro) const {
    return cedula < otro.cedula;
}

bool Estudiante::operator>(const Estudiante& otro) const {
    return cedula > otro.cedula;
}

bool Estudiante::operator==(const Estudiante& otro) const {
    return cedula == otro.cedula;
}

bool Estudiante::operator!=(const Estudiante& otro) const {
    return cedula != otro.cedula;
}

// Mostrar información
void Estudiante::mostrar() const {
    cout << fixed << setprecision(2);
    cout << "Cedula: " << cedula << " | ";
    cout << "Apellidos: " << apellidos << " | ";
    cout << "Nombres: " << nombres << " | ";
    cout << "Nota: " << notaFinal << " | ";
    cout << "Carrera: " << carrera << " | ";
    cout << "Nivel: " << nivel << endl;
}