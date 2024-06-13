#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Para unlink
#include <sys/stat.h> // Para stat

void vaciarArchivo(const char *filename1) {
    // Verificar si el archivo existe
    if (access(filename1, F_OK) == -1) {
        // El archivo no existe, crearlo
        FILE *file = fopen(filename1, "w");
        if (file == NULL) {
            perror("Error al crear archivo");
        }
        fclose(file);
        printf("Archivo %s creado correctamente\n", filename1);

    }

    // Vaciar el archivo
    FILE *file = fopen(filename1, "w");
    if (file == NULL) {
        perror("Error al abrir archivo para escribir");
    }
    fclose(file);

    printf("Archivo %s vaciado correctamente\n", filename1);
}

