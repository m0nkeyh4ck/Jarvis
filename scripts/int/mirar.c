#include <stdio.h>
#include <unistd.h> // Para sleep
#include <string.h> // Para strcmp
#include <stdlib.h> // Para system
#include "../brain/brain.h" // Cambia esto por la ruta correcta de tu archivo de cabecera


int wait_time = 4000000; // Variable global para el tiempo de espera en microsegundos


// Función para realizar una acción basada en el comando leído
void action(char *command) {
    if (strcmp(command, "Salir") == 0 || strcmp(command, "salir") == 0 || strcmp(command, "5") == 0) {
        system("wmctrl -r :ACTIVE: -b remove,above");
		system("tput cnorm");
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

// Función para monitorear un archivo y realizar acciones basadas en su contenido
void mirar_archivo(const char *filename) {
    // Verificar si el archivo existe
    if (access(filename, F_OK) != -1) {
        // El archivo existe, vaciarlo
        vaciarArchivo(filename);
    } else {
        // El archivo no existe, crearlo
        FILE *file = fopen(filename, "w");
        if (file != NULL) {
            fclose(file);
            printf("Archivo %s creado correctamente\n", filename);
        } else {
            perror("Error al crear archivo");
            return;
        }
    }

    while(1) {
        clear_screen();
        show_menu();
        while (1) {
            // Leer el archivo
            FILE *file = fopen(filename, "r");
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
                    vaciarArchivo(filename);
                    usleep(wait_time);
                    break;
                }
            }
            // Esperar un momento antes de volver a verificar el archivo
            usleep(1000000); // 100ms
        }
    }
}
