# Simulador de Carrera de Autos en C++

NOMBRES: Lucas Méndez y Hector Díaz

Este programa simula una carrera de autos donde cada auto corre en su propio hilo (thread).


## Requisitos

- Sistema operativo Linux
- Compilador g++ (C++11).


### Cómo instalar lo necesario

1. Abrir la terminal.

2. Se tiene que ejecturar el siguiente comando para instalar `g++` si no lo tienes ya instalado:

   sudo apt update
   sudo apt install g++


## Cómo compilar el programa

1. Se abre la terminal.

2. Dirigirse al directorio donde se guardaron los archivos del programa.

3. Se escribe el comando "make" para compilar, el cual creará un archivo llamado "carrera"


## Cómo ejecutar el programa

Para correr el programa, se usa el siguiente comando:

./carrera <distancia_total> <numero_autos>


## Resultado esperado

El programa mostrará cómo avanza cada auto y el orden en que terminan la carrera.


## Cómo limpiar los archivos generados

Si se quiere borrar los archivos creados durante la compilación, se usa el comando "make clean" en la terminal
