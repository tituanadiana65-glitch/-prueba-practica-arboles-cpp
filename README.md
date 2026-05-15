# Sistema Académico con Árbol Binario de Búsqueda

## 📖 Descripción del Proyecto

Este proyecto implementa un **Sistema Académico** para la gestión de estudiantes utilizando un **Árbol Binario de Búsqueda (ABB)** en lenguaje **C++**. El sistema permite realizar operaciones fundamentales como inserción, búsqueda, eliminación y diversos recorridos, además de consultas específicas sobre el rendimiento académico de los estudiantes.

### Solución Implementada
Se utiliza un **ABB** donde la clave de ordenamiento es la **cédula**, lo que garantiza:
- Inserción y búsqueda en **O(log n)** en promedio
- Recorrido Inorden que devuelve los estudiantes ordenados automáticamente
- Estructura dinámica que crece según necesidades

---


### Clases Principales

| Clase | Responsabilidad |
|-------|-----------------|
| `Estudiante` | Encapsula los datos del estudiante (cédula, nombres, nota, etc.) |
| `NodoArbol` | Representa un nodo del árbol con punteros izquierdo/derecho |
| `ArbolBinarioBusqueda` | Contiene toda la lógica de operaciones del ABB |

---

##  Funcionalidades

### Operaciones Básicas
| Opción | Función | Descripción |
|--------|---------|-------------|
| 1 | `insertarEstudiante()` | Agrega un nuevo estudiante al árbol |
| 2 | `buscarEstudiante()` | Busca por cédula (O(log n)) |
| 3 | `eliminarEstudiante()` | Elimina un nodo manteniendo propiedades ABB |

### Recorridos
| Opción | Recorrido | Orden de visita |
|--------|-----------|-----------------|
| 4 | **Inorden** | Izquierdo → Raíz → Derecho (devuelve datos ordenados) |
| 5 | **Preorden** | Raíz → Izquierdo → Derecho |
| 6 | **Postorden** | Izquierdo → Derecho → Raíz |
| 7 | **BFS (Niveles)** | Por niveles, usando cola |

### Consultas Estadísticas
| Opción | Función | Descripción |
|--------|---------|-------------|
| 8 | `contarNodos()` | Retorna el número total de estudiantes |
| 9 | `calcularAltura()` | Retorna la altura máxima del árbol |
| 10 | `buscarNotaMayor()` | Encuentra el estudiante con mejor nota |
| 11 | `buscarNotaMenor()` | Encuentra el estudiante con peor nota |
| 12 | `mostrarAprobados()` | Lista estudiantes con nota ≥ 7 |
| 13 | `mostrarReprobados()` | Lista estudiantes con nota < 7 |

---


---

## Estructura del Proyecto
-PRUEBA-PRACTICA-ARBOLES-.../
│
├── Capturas/
│   ├── 1_Menu.png
│   ├── 2_Insertar.png
│   ├── 3_Buscar.png
│   ├── 4_Eliminar.png
│   ├── 5_Inorder.png
│   ├── 6_Preorden.png
│   ├── 7_Postorden.png
│   ├── 8_BFS.png
│   ├── 9_Contar.png
│   ├── 10_Altura.png
│   ├── 11_MayorNota.png
│   ├── 12_MenoNota.png
│   ├── 13_Aprobados.png
│   ├── 14_Reprobados.png
│   ├── 15_Salir.png
│   ├── 16_Commint.png
│   ├── 16_EstructuraProyecto.png
│   └── 17_Ejecucion.png
│
├── cpp/
│   ├── arbolBinarioBusqueda.cpp
│   ├── arbolBinarioBusqueda.h
│   ├── estudiante.cpp
│   ├── estudiante.h
│   ├── main.cpp
│   ├── nodoArbol.cpp
│   ├── nodoArbol.h
│   └── sistema.exe
│
└── README.md

## Ejecutar
cpp
cd \cpp
g++ -std=c++11 *.cpp -o sistema.exe
 .\sistema.exe                      

