#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "brain.h"
#include <dirent.h> // Cabecera para utilizar DIR y struct dirent
#include <unistd.h> // Cabecera para utilizar closedir
#include <string.h> // Cabecera para utilizar strcmp

// Resto del código...


// Función para eliminar un directorio y su contenido recursivamente
int eliminarDirectorioRecursivo(const char *path) {
    
    
    DIR *dir = opendir(path);
    struct dirent *entry;

    //valida si se puede abrir el directorio
    if (dir == NULL) {
        perror("Error al abrir directorio");
        return 0; // Fracaso
    }


    while ((entry = readdir(dir)) != NULL) {
        // Ignorar las entradas "." y ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char filePath[1024];
        snprintf(filePath, sizeof(filePath), "%s/%s", path, entry->d_name);

        // Si es un directorio, eliminarlo recursivamente
        if (entry->d_type == DT_DIR) {
            eliminarDirectorioRecursivo(filePath);
        } else {
            // Si es un archivo, eliminarlo
            if (remove(filePath) != 0) {
                perror("Error al eliminar archivo");
                closedir(dir);
                return 0; // Fracaso
            }
        }
    }

    closedir(dir);

    // Una vez que el directorio esté vacío, eliminarlo
    if (rmdir(path) != 0) {
        perror("Error al eliminar el directorio");
        return 0; // Fracaso
    }

    return 1; // Éxito
}

// Función para crear un directorio
int crearDirectorio(const char *path) {
    struct stat st;
    // Verificar si el directorio ya existe
    if (stat(path, &st) == 0) {
        // Si existe, eliminar su contenido y luego eliminar el directorio
        if (!eliminarDirectorioRecursivo(path)) {
            return 0; // Fracaso
        }
        printf("Directorio existente eliminado: %s\n", path);
    }

    // Crear el directorio
    int status = mkdir(path, 0777); // 0777 para otorgar permisos de lectura, escritura y ejecución
    if (status == 0) {
        printf("Directorio creado correctamente: %s\n", path);
        return 1; // Éxito
    } else {
        perror("Error al crear directorio");
        return 0; // Fracaso
    }
}

// Función para crear directorios con subdirectorios
void crearDirectorios(const char *directorioRaiz) {
    // Crear el directorio raíz
    crearDirectorio(directorioRaiz);   
}


