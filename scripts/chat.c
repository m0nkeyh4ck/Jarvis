// chat.c
#include <stdio.h>
#include <string.h>
#include <unistd.h> // Para usleep()
#include <stdlib.h> // Para system()
#include "brain.h"

int wait_time = 1000000; // Variable global para el tiempo de espera en microsegundos

void clear_screen() {
    system("clear"); // Limpia la pantalla
}

void chat() {
    system("sleep 1 && wmctrl -r :ACTIVE: -b add,above");
    char input[100];

    while (1) {
        clear_screen(); // Limpiar la pantalla
        printf("Hola Monkey\n¿qué vas a hacer?\n\n");
        printf("1) Imprimir un 'Hola, mundo'\n");
        printf("2) Hacer ping a una dirección IP\n");
        printf("3) Crear carpeta\n");
        printf("4) Salir\n");
        printf("Selecciona una opción: ");
        
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // Eliminar el carácter de nueva línea
        clear_screen();
        if (strcmp(input, "4") == 0 || strcmp(input, "Salir") == 0 || strcmp(input, "salir") == 0) {
            system("wmctrl -r :ACTIVE: -b remove,above");
            break;
        } else if (strcmp(input, "1") == 0) {
            say_hello();
        } else if (strcmp(input, "2") == 0) {
            request_and_ping(); // Utiliza la nueva función para pedir la IP y hacer ping
        } else if (strcmp(input, "3") == 0){
            new_folder();
        } else {
            printf("Opción no válida. Por favor, selecciona una opción válida.\n\n");
        }
        
        usleep(wait_time); // Usar la variable de tiempo de espera
    }
}
