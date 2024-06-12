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
    printf("1) Jugar en Hck The Box\n");
    printf("2) Jugar en Try Hack Me\n");
    printf("3) Jugar en Hack My VM\n");
    printf("4) Solo estar en casa\n");
    printf("5) Salir\n");
    
}

void chat(){
    mirar_archivo(); //funcion mirar.c
}

