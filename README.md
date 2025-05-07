# Comparación de Algoritmos de Ordenamiento y Búsqueda en C++

Este proyecto implementa y compara distintos métodos de ordenamiento y búsqueda en C++, con el objetivo de analizar su rendimiento en diferentes contextos de tamaño de datos.

## Descripción del Proyecto

Se implementaron tres algoritmos de ordenamiento:

- **Intercambio (Swap Sort)**
- **Burbuja (Bubble Sort)**
- **Merge Sort**

Así como dos métodos de búsqueda:

- **Búsqueda Secuencial**
- **Búsqueda Binaria**

Los algoritmos fueron aplicados sobre tres grupos de datos de distintos tamaños. Los valores fueron leídos desde archivos y almacenados en vectores para posteriormente ser ordenados utilizando cada uno de los métodos. 

## Objetivo

Comparar el rendimiento de los algoritmos en función de:

- **Tiempo de ejecución**
- **Complejidad algorítmica esperada**

## Metodología

1. Se generaron o utilizaron archivos con datos numericos aleatorios de entrada de tres tamaños diferentes (pequeño, mediano y grande).
2. Cada conjunto de datos fue leído y almacenado en vectores.
3. Se aplicaron los tres métodos de ordenamiento a cada conjunto.
4. Se midió el tiempo de ejecución utilizando funciones de temporización en C++.
5. Posteriormente, se aplicaron los métodos de búsqueda (secuencial y binaria) sobre los vectores ordenados.
6. Se analizaron los resultados obtenidos y se compararon con la complejidad teórica de cada algoritmo.

## Resultados Esperados

- **Bubble Sort** y **Intercambio** presentan una complejidad de \( O(n^2) \), lo que se refleja en un desempeño pobre en conjuntos grandes.
- **Merge Sort** tiene una complejidad de \( O(n \log n) \), por lo tanto, mostró mejor rendimiento especialmente en los vectores más grandes.
- La **búsqueda binaria**, con complejidad \( O(\log n) \), fue notablemente más rápida que la **búsqueda secuencial** \( O(n) \), pero requiere que el vector esté previamente ordenado.

## Tecnologías Utilizadas

- Lenguaje: **C++**
- E/S de archivos estándar
- Medición de tiempo con `chrono`

## Instrucciones de Ejecución

Para compilar y ejecutar el archivo principal `main.cpp` ubicado en la carpeta `/src`, sigue estos pasos desde la terminal:

1. **Compilar el programa:**

```bash
g++ ./src/main.cpp
```

## Autor

Elaborado por **Miguel Pérez**



Fecha de realización: 14/09/2023
