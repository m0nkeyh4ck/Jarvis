#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Para unlink
#include <sys/stat.h> // Para stat

void new_file(const char *filename1) {
    // Verificar si el archivo existe
    if (access(filename1, F_OK) == -1) {
        // El archivo no existe, crearlo
        FILE *file = fopen(filename1, "w");
        if (file == NULL) {
            perror("Error al crear archivo");
            usleep(2000000);
        }
        fclose(file);
        //printf("Archivo %s creado correctamente\n", filename1);
        //usleep(2000000);
    }

    // Vaciar el archivo
    FILE *file = fopen(filename1, "w");
    if (file == NULL) {
        perror("Error al abrir archivo para escribir");
        usleep(2000000);
    }
    fclose(file);

    //printf("Archivo %s vaciado correctamente\n", filename1);
}

