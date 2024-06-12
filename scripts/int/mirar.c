#include <stdio.h>
#include <unistd.h> // Para sleep
#include <string.h> // Para strcmp
#include <stdlib.h> // Para system
#include "../brain/brain.h"


#define FILENAME "mirar.txt"
int wait_time = 4000000; // Variable global para el tiempo de espera en microsegundos
// Variable para controlar el bucle


// Función para vaciar el archivo
void vaciarArchivo() {
    FILE *file = fopen(FILENAME, "w");
    fclose(file);
}

void action(char *command) {
    if (strcmp(command, "Salir") == 0 || strcmp(command, "salir") == 0 || strcmp(command, "5") == 0) {
        system("wmctrl -r :ACTIVE: -b remove,above");
        exit(EXIT_SUCCESS);
    } else if (strcmp(command, "1") == 0) {
        say_hello();
    } else if (strcmp(command, "2") == 0) {
        request_and_ping();
    } else if (strcmp(command, "3") == 0) {
        new_folder();
    } else if (strcmp(command, "4") == 0) {
        find_all();
    } else {
        printf("Comando no reconocido: %s\n", command);
    }
}

void mirar_archivo() {
    // Verificar si el archivo existe
    if (access(FILENAME, F_OK) != -1) {
        // El archivo existe, vaciarlo
        vaciarArchivo();
    } else {
        // El archivo no existe, crearlo
        FILE *file = fopen(FILENAME, "w");
        fclose(file);
    }

    while(1){
        clear_screen();
        show_menu();
        while (1) {
            // Leer el archivo
            FILE *file = fopen(FILENAME, "r");
            if (file != NULL) {
                char line[10]; // Tamaño suficiente para "si" o "no"
                // Leer una línea del archivo
                if (fgets(line, sizeof(line), file) != NULL) {
                    // Eliminar el salto de línea al final de la línea, si existe
                    line[strcspn(line, "\n")] = '\0';
                    clear_screen();
                    action(line);
                    
                    fclose(file);
                    // Vaciar el archivo después de cada ejecución
                    vaciarArchivo();
                    usleep(wait_time);
                    break;
                }
            }
            // Esperar un momento antes de volver a verificar el archivo
            usleep(1000000); // 100ms
        }
    }
}
