// ping.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "brain.h"

void do_ping(const char *ip_address) {
    char command[100];
    snprintf(command, sizeof(command), "/usr/bin/ping -c 1 %s", ip_address);

    printf("Haciendo ping a %s...\n", ip_address);
    int result = system(command);

    if (result == -1) {
        printf("Error al ejecutar el comando: %s\n", strerror(errno));
    }
}

void request_and_ping() {
    char ip_address[16];
    printf("Introduce la dirección IP: ");
    fgets(ip_address, sizeof(ip_address), stdin);
    ip_address[strcspn(ip_address, "\n")] = 0; // Eliminar el carácter de nueva línea
    do_ping(ip_address);
}
