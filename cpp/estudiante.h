#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <iostream>
#include <string>
using namespace std;

class Estudiante {
private:
    string cedula;
    string apellidos;
    string nombres;
    double notaFinal;
    string carrera;
    string nivel;

public:
    // Constructores
    Estudiante();
    Estudiante(string ced, string ape, string nom, double nota, string carr, string niv);
    
    // Getters
    string getCedula() const;
    string getApellidos() const;
    string getNombres() const;
    double getNotaFinal() const;
    string getCarrera() const;
    string getNivel() const;
    
    // Setters
    void setCedula(string ced);
    void setApellidos(string ape);
    void setNombres(string nom);
    void setNotaFinal(double nota);
    void setCarrera(string carr);
    void setNivel(string niv);
    
    // Sobrecarga de operadores para comparar por cédula
    bool operator<(const Estudiante& otro) const;
    bool operator>(const Estudiante& otro) const;
    bool operator==(const Estudiante& otro) const;
    bool operator!=(const Estudiante& otro) const;
    
    // Mostrar información del estudiante
    void mostrar() const;
};

#endif