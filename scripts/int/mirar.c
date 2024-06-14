#include <stdio.h>
#include <unistd.h> // Para sleep
#include <string.h> // Para strcmp
#include <termios.h>
#include "../brain/brain.h" // Cambia esto por la ruta correcta de tu archivo de cabecera
#include <fcntl.h> // Para fcntl y las constantes relacionadas con los modos de apertura de archivos



int wait_time = 4000000; // Variable global para el tiempo de espera en microsegundos
int wait_time2 = 1000000;
// Función para monitorear un archivo y realizar acciones basadas en su contenido

// Función para verificar si se ha presionado una tecla
int kbhit(void) {
    struct termios oldt, newt;
    int ch;
    int oldf;

    // Obtener la configuración actual de la terminal
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // Desactivar el modo canónico y el eco de entrada
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK); // Establecer el modo de lectura no bloqueante

    // Leer un carácter de la entrada estándar
    ch = getchar();

    // Restaurar la configuración de la terminal
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    // Si se ha leído un carácter, devolver 1 (verdadero)
    if(ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    // Si no se ha leído ningún carácter, devolver 0 (falso)
    return 0;
}

// Función para monitorear el archivo y realizar acciones
void mirar_archivo(char *filename) {
    while (!kbhit()) { // Verificar si se ha presionado una tecla para salir
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
            fclose(file);
        }
        // Esperar un momento antes de volver a verificar el archivo
        usleep(wait_time2); // 100ms
    }
}



// void mirar_archivo( char *filename) {
//     while (1) {
//         // Leer el archivo
//         FILE *file = fopen(filename, "r");
//         if (file != NULL) {
//             char line[10]; // Tamaño suficiente para "si" o "no"
//             // Leer una línea del archivo
//             if (fgets(line, sizeof(line), file) != NULL) {
//                 // Eliminar el salto de línea al final de la línea, si existe
//                 line[strcspn(line, "\n")] = '\0';
//                 clear_screen();
//                 action(line);
//                 fclose(file);
//                 // Vaciar el archivo después de cada ejecución
//                 new_file(filename);
//                 usleep(wait_time);
//                 break;
//             }
//         }
//         // Esperar un momento antes de volver a verificar el archivo
//         usleep(wait_time2); // 100ms
//     }
// }


