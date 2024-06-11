// chat.c
#include <stdio.h>
#include <string.h>
#include <unistd.h> // Para usleep()
#include <stdlib.h> // Para system()
#include "brain.h"

void clear_screen() {
    system("clear"); // Limpia la pantalla
}

void chat() {
    system("sleep 1 && wmctrl -r :ACTIVE: -b add,above");
    char input[100];

    while (1) {
        clear_screen(); // Limpiar la pantalla
        printf("Hola Chucho, ¿qué deseas hacer hoy?\n");
        printf("1) Imprimir un 'Hola, mundo'\n");
        printf("2) Hacer ping a una dirección IP\n");
        printf("3) Salir\n");
        printf("Selecciona una opción: ");
        
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // Eliminar el carácter de nueva línea
        clear_screen();
        if (strcmp(input, "3") == 0 || strcmp(input, "Salir") == 0 || strcmp(input, "salir") == 0) {
            system("wmctrl -r :ACTIVE: -b remove,above");
			system("exit");
            break;
        }

        if (strcmp(input, "1") == 0) {
            say_hello();
        } else if (strcmp(input, "2") == 0) {
            char ip_address[16];
            printf("Introduce la dirección IP: ");
            fgets(ip_address, sizeof(ip_address), stdin);
            ip_address[strcspn(ip_address, "\n")] = 0; // Eliminar el carácter de nueva línea
            do_ping(ip_address);
        } else {
            printf("Opción no válida. Por favor, selecciona una opción válida.\n\n");
        }
        
        usleep(3000000); // Esperar 2 segundos
    }
}
