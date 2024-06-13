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
    printf("\n\t\t\t\t\tHola Monkey\n\t\t\t\t\t¿Qué vas a hacer?\n\n");
    printf("\t\t\t\t\t1) Jugar en Hck The Box\n");
    printf("\t\t\t\t\t2) Jugar en Try Hack Me\n");
    printf("\t\t\t\t\t3) Jugar en Hack My VM\n");
    printf("\t\t\t\t\t4) Solo estar en casa\n");
    printf("\t\t\t\t\t5) Salir\n");
    
}

void chat(const char *m1){
    mirar_archivo(m1); //funcion mirar.c
}

