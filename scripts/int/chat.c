// chat.c
#include <stdio.h>
#include <string.h>
#include <unistd.h> // Para usleep()
#include <stdlib.h> // Para system()
#include "../brain/brain.h"


void clear_screen() {
    system("clear"); // Limpia la pantalla
}

//funcion menu en el sistema
void show_menu() {
    printf("\nHola Monkey\n¿Qué vas a hacer?\n\n");
    printf("1) Imprimir un 'Hola, mundo'\n");
    printf("2) Hacer ping a una dirección IP\n");
    printf("3) Crear carpeta\n");
    printf("4) Buscar\n");
    printf("5) Salir\n");
}

void chat(){
    mirar_archivo();
}

