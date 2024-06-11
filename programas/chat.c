// chat.c
#include <stdio.h>
#include <string.h>
#include "brain.h"

void chat() {
    char input[100];

    while (1) {
        printf("¿Qué quieres hacer? (hola/ping [dirección_ip]/salir): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // Eliminar el carácter de nueva línea

        if (strcmp(input, "salir") == 0) {
            break;
        }

        execute_command(input);
    }
}
