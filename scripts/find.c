#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

#define MAX_PATH_LEN 1024
#define MAX_NAME_LEN 256

void buscar_elementos(const char *directory, const char *nombre);
void imprimir_archivo(const char *path);

void find_all() {
    char directory[MAX_PATH_LEN];
    char nombre[MAX_NAME_LEN];

    printf("Directorio a buscar: ");
    scanf("%s", directory);
    while (getchar() != '\n'); // Limpiar el buffer de entrada después de scanf

    printf("Nombre del elemento a buscar: ");
    scanf("%s", nombre);
    while (getchar() != '\n'); // Limpiar el buffer de entrada después de scanf

    buscar_elementos(directory, nombre);
    printf("\n");
}

void buscar_elementos(const char *directory, const char *nombre) {
    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir(directory)) != NULL) {
        while ((entry = readdir(dir)) != NULL) {
            char path[MAX_PATH_LEN];
            snprintf(path, sizeof(path), "%s/%s", directory, entry->d_name);

            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue; // Saltar las entradas de "." y ".."
            }

            if (entry->d_type == DT_DIR) {
                buscar_elementos(path, nombre); // Búsqueda recursiva en directorios
            } else if (entry->d_type == DT_REG && strcmp(entry->d_name, nombre) == 0) {
                imprimir_archivo(path); // Imprimir archivos que coincidan con el nombre
            }
        }
        closedir(dir);
    }
}

void imprimir_archivo(const char *path) {
    printf("%s\n", path);
}
