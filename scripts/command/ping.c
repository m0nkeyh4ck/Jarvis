// ping.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h> // Incluir errno.h para strerror
#include "../brain/brain.h"

void do_ping(const char *ip_address) {
    char command[100];
    snprintf(command, sizeof(command), "/usr/bin/ping -c 1 %s", ip_address);

    printf("Haciendo ping a %s...\n", ip_address);
    FILE *ping_output = popen(command, "r"); // Abrir un canal de lectura para el comando ping
    printf("\n\n");
    int result = system(command);
    printf("\n");

    if (ping_output == NULL) {
        printf("Error al ejecutar el comando: %s\n", strerror(errno)); // Manejar el error si el comando falla
        return;
    }

    char output_line[100];
    int ttl_value = 0;

    while (fgets(output_line, sizeof(output_line), ping_output) != NULL) {
        if (strstr(output_line, "ttl=") != NULL) {
            char *ttl_ptr = strstr(output_line, "ttl=");
            if (sscanf(ttl_ptr, "ttl=%d", &ttl_value) == 1) {
                printf("Valor TTL: %d\n", ttl_value);

                // Evaluar si el TTL indica Linux o Windows
                if ((ttl_value >= 60 && ttl_value <= 64) || (ttl_value >= 120 && ttl_value <= 127)) {
                    printf("Sistema operativo: Linux\n");
                } else {
                    printf("Sistema operativo: Windows\n");
                }
            }
            break; // Salir del bucle después de encontrar el TTL
        }
    }

    pclose(ping_output); // Cerrar el canal de lectura
}

void request_and_ping() {
    char ip_address[16];
    printf("Introduce la dirección IP: ");
    fgets(ip_address, sizeof(ip_address), stdin);
    ip_address[strcspn(ip_address, "\n")] = 0; // Eliminar el carácter de nueva línea
    do_ping(ip_address);
}
