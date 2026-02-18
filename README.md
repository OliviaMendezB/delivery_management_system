# Delivery Management System – Prototipo de Furgonetas y Paquetes

## Descripción del proyecto

Este proyecto simula un sistema de gestión de entregas de una empresa de transporte urgente de paquetería.
El sistema gestiona:
- Una lista de paquetes con identificador, código postal de destino y estado de carga.
- Un conjunto de furgonetas (hasta 10) con capacidad máxima de 8 paquetes cada una.
- La carga automática de paquetes en furgonetas según su destino.
- La recogida manual de paquetes que no pudieron ser cargados en furgonetas.
- Persistencia de los datos usando archivos de texto para paquetes y códigos postales.
- El prototipo respeta restricciones de capacidad y código postal, mostrando la información actualizada tras cada acción.

## Funcionalidades implementadas

- Carga de paquetes desde archivo (paquetes.txt) con hasta 50 paquetes por día.
- Carga de furgonetas y códigos postales desde archivo (codigos.txt), inicializando listas de paquetes vacías.
- Visualización de paquetes y furgonetas en cualquier momento.
- Asignación automática de paquetes a furgonetas según el código postal y la disponibilidad de espacio.
- Búsqueda eficiente de furgonetas mediante búsqueda binaria por código postal.
- Recogida manual de paquetes no cargados, manteniendo el orden de la lista de paquetes.
- Gestión de memoria dinámica para listas de paquetes cargados en furgonetas, evitando fugas de memoria.

## Estructura del proyecto

packages.h / packages.cpp : Definición de tPackage y tPackages. Gestión de paquetes y lista de paquetes.

vans.h / vans.cpp : Definición de tVan, tLoaded y tVans. Gestión de furgonetas y paquetes cargados.

main.cpp : Flujo principal de ejecución - carga de datos, asignación de paquetes, visualización y recogida manual.

paquetes.txt : Archivo de entrada con los paquetes.

codigos.txt : Archivo de entrada con los códigos postales asignados a las furgonetas.

## Mejoras implementadas respecto a la plantilla base

- Gestión dinámica de memoria para las listas de paquetes en furgonetas.
- Búsqueda eficiente de furgonetas mediante búsqueda binaria.
- Separación de funcionalidades en módulos (Packages y Vans) para modularidad y escalabilidad.
- Manejo de recogida manual de paquetes no cargados manteniendo el orden original de la lista.
- Persistencia de datos desde archivos, permitiendo reinicios sin pérdida de información.

## Habilidades demostradas
- Programación orientada a objetos en C++ y uso de constructores, destructores y punteros.
- Manejo de arrays estáticos y dinámicos, así como memoria dinámica segura.
- Modularización y separación de headers y código fuente.
- Implementación de algoritmos de búsqueda y carga eficiente de datos.
- Gestión de persistencia de datos mediante archivos de texto.
