#include "ArbolBinarioBusqueda.h"
#include <iostream>
#include <limits>

using namespace std;

void mostrarMenu() {
    cout << "\n========================================" << endl;
    cout << "   SISTEMA ACADEMICO - ARBOL BINARIO" << endl;
    cout << "========================================" << endl;
    cout << "1. Insertar estudiante" << endl;
    cout << "2. Buscar estudiante por cedula" << endl;
    cout << "3. Eliminar estudiante" << endl;
    cout << "4. Recorrido Inorden" << endl;
    cout << "5. Recorrido Preorden" << endl;
    cout << "6. Recorrido Postorden" << endl;
    cout << "7. Recorrido por niveles BFS" << endl;
    cout << "8. Contar estudiantes" << endl;
    cout << "9. Calcular altura del arbol" << endl;
    cout << "10. Mostrar estudiante con mayor nota" << endl;
    cout << "11. Mostrar estudiante con menor nota" << endl;
    cout << "12. Mostrar estudiantes aprobados" << endl;
    cout << "13. Mostrar estudiantes reprobados" << endl;
    cout << "14. Salir" << endl;
    cout << "========================================" << endl;
    cout << "Opcion: ";
}

int main() {
    ArbolBinarioBusqueda arbol;
    int opcion;
    
    
    
    do {
        mostrarMenu();
        cin >> opcion;
        
        // Limpiar buffer de entrada
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Opcion invalida. Ingrese un numero." << endl;
            continue;
        }
        
        switch(opcion) {
            case 1:
                arbol.insertarEstudiante();
                break;
            case 2:
                arbol.buscarEstudiante();
                break;
            case 3:
                arbol.eliminarEstudiante();
                break;
            case 4:
                arbol.recorridoInorden();
                break;
            case 5:
                arbol.recorridoPreorden();
                break;
            case 6:
                arbol.recorridoPostorden();
                break;
            case 7:
                arbol.recorridoPorNiveles();
                break;
            case 8:
                arbol.contarNodos();
                break;
            case 9:
                arbol.calcularAltura();
                break;
            case 10:
                arbol.buscarNotaMayor();
                break;
            case 11:
                arbol.buscarNotaMenor();
                break;
            case 12:
                arbol.mostrarAprobados();
                break;
            case 13:
                arbol.mostrarReprobados();
                break;
            case 14:
                cout << "\nSaliendo del sistema... ¡Hasta luego!" << endl;
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
        }
    } while(opcion != 14);
    
    return 0;
}