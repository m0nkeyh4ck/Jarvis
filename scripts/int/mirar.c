#include <stdio.h>
#include <unistd.h> // Para sleep
#include <string.h> // Para strcmp
#include "../brain/brain.h" // Cambia esto por la ruta correcta de tu archivo de cabecera


int wait_time = 4000000; // Variable global para el tiempo de espera en microsegundos
int wait_time2 = 1000000;
// Función para monitorear un archivo y realizar acciones basadas en su contenido
void mirar_archivo(const char *filename) {
   
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
                new_file(filename);
                usleep(wait_time);
                break;
            }
        }
        // Esperar un momento antes de volver a verificar el archivo
        usleep(wait_time2); // 100ms
    }
    
}
