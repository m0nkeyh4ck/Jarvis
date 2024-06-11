#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // Para obtener la fecha y hora actual
#include "brain.h"

#define MAX_CARPETAS 10
#define MAX_NOMBRE 50
#define MAX_RUTA 100

void new_folder() {
    int cantidad;
    char nombres[MAX_CARPETAS][MAX_NOMBRE];
    char rutas[MAX_CARPETAS][MAX_RUTA];
    char eleccion[MAX_NOMBRE];

    // Pedir la cantidad de carpetas a crear
    printf("Ingrese la cantidad de carpetas a crear: ");
    scanf("%d", &cantidad);
    getchar(); // Limpiar el buffer de entrada

    // Verificar que la cantidad no exceda el límite
    if (cantidad > MAX_CARPETAS) {
        printf("Error: Demasiadas carpetas. El máximo es %d\n", MAX_CARPETAS);
        return;
    }

    // Pedir los nombres y rutas de las carpetas
    for (int i = 0; i < cantidad; i++) {
        printf("Ingrese el nombre de la carpeta %d: ", i + 1);
        fgets(nombres[i], MAX_NOMBRE, stdin);
        nombres[i][strcspn(nombres[i], "\n")] = 0; // Eliminar el salto de línea

        printf("Ingrese la ruta donde desea crear la carpeta %d (dejar vacío para /dev/shm): ", i + 1);
        fgets(rutas[i], MAX_RUTA, stdin);
        rutas[i][strcspn(rutas[i], "\n")] = 0; // Eliminar el salto de línea

        // Comprobar si la ruta está vacía
        if (strlen(rutas[i]) == 0) {
            strcpy(rutas[i], "/dev/shm"); // Si está vacía, asignar /dev/shm
        }

        // Crear la carpeta utilizando el comando mkdir
        char command[MAX_RUTA + MAX_NOMBRE + 20]; // Tamaño suficiente para contener el comando
        snprintf(command, sizeof(command), "/usr/bin/mkdir -p \"%s/%s\"", rutas[i], nombres[i]);
        system(command);
    }

    // Mostrar las carpetas creadas
    printf("\nCarpetas creadas:\n");
    for (int i = 0; i < cantidad; i++) {
        printf("%d) %s en %s\n", i + 1, nombres[i], rutas[i]);
    }

    // Preguntar si desea ir a alguna carpeta
    printf("\n¿Desea ir a alguna de estas carpetas? (si/no): ");
    fgets(eleccion, MAX_NOMBRE, stdin);
    eleccion[strcspn(eleccion, "\n")] = 0; // Eliminar el salto de línea

    if (strcmp(eleccion, "si") == 0) {
        int opcion;
        printf("Seleccione la carpeta a la que desea ir (1-%d): ", cantidad);
        scanf("%d", &opcion);
        getchar(); // Limpiar el buffer de entrada

        if (opcion >= 1 && opcion <= cantidad) {
            printf("Ha seleccionado ir a la carpeta %s en %s\n", nombres[opcion - 1], rutas[opcion - 1]);
            // Aquí puedes agregar la lógica para cambiar al directorio deseado
        } else {
            printf("Opción inválida.\n");
        }
    } else if (strcmp(eleccion, "no") == 0) {
        printf("Decidió no ir a ninguna carpeta.\n");
    } else {
        printf("Opción no reconocida.\n");
    }
}
