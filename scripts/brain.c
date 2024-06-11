// brain.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "brain.h"

void execute_command(const char *command) {
    if (strcmp(command, "hola") == 0) {
        say_hello();
    } else if (strncmp(command, "ping", 4) == 0) {
        char ip[100];
        sscanf(command, "ping %s", ip);
        do_ping(ip);
    } else {
        printf("Comando desconocido: %s\n", command);
    }
}

