// ping.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h> // Incluir errno.h para strerror
#include "../brain/brain.h"

void do_ping(const char *ip_address) {
    
        // Crear el comando de ping
    char command[100];
    snprintf(command, sizeof(command), "/usr/bin/ping -c 1 %s", ip_address);

    // Imprimir un mensaje indicando que se está realizando el ping
    printf("Haciendo ping a %s...\n", ip_address);
    
    // Abrir un canal de lectura para el comando ping
    FILE *ping_output = popen(command, "r");
    printf("\n\n"); // Salto de línea
    
    // Ejecutar el comando ping y obtener el resultado
    // imprime el comando ping
    //int result = system(command);
    //printf("\n"); // Salto de línea

    // Manejar el error si el comando ping falla
    if (ping_output == NULL) {
        printf("Error al ejecutar el comando: %s\n", strerror(errno));
        return;
    }

    // Variables para almacenar la salida del comando ping y el valor TTL
    char output_line[100];
    int ttl_value = 0;

    // Leer la salida del comando ping línea por línea
    while (fgets(output_line, sizeof(output_line), ping_output) != NULL) {
        // Buscar la cadena "ttl=" en la línea actual
        if (strstr(output_line, "ttl=") != NULL) {
            // Si se encuentra, extraer el valor TTL
            char *ttl_ptr = strstr(output_line, "ttl=");
            if (sscanf(ttl_ptr, "ttl=%d", &ttl_value) == 1) {
                // Imprimir el valor TTL
                printf("Valor TTL: %d\n", ttl_value);

                // Determinar el sistema operativo basado en el TTL
                if ((ttl_value >= 60 && ttl_value <= 64) || (ttl_value >= 120 && ttl_value <= 127)) {
                    printf("Sistema operativo: Linux\n");
                } else {
                    printf("Sistema operativo: Windows\n");
                }
            }
        
            //manda el comando a la consola
            system("xterm -geometry 114x35+1230+190 -e 'echo "";ifconfig enp0s3;sleep 4'");
            break; // Salir del bucle después de encontrar el TTL
        }
    }

    // Cerrar el canal de lectura
    pclose(ping_output);
}

void request_and_ping() {
    char ip_address[16];
    printf("Introduce la dirección IP: ");
    fgets(ip_address, sizeof(ip_address), stdin);
    ip_address[strcspn(ip_address, "\n")] = 0; // Eliminar el carácter de nueva línea
    do_ping(ip_address);
}





