// chat.c
#include <stdio.h>
#include <string.h>
#include <unistd.h> // Para usleep()
#include <stdlib.h> // Para system()
#include "../brain/brain.h"


//funcion menu en el sistema
void show_menu_home() {
    printf("\n\t\t\t\t\tHola Monkey\n\t\t\t\t\t¿Qué vas a hacer?\n\n");
    printf("\t\t\t\t\t1) Imprime hola mundo\n");
    printf("\t\t\t\t\t2) hacer ping\n");
    printf("\t\t\t\t\t3) crear carpetas\n");
    printf("\t\t\t\t\t4) Buscar\n");
    printf("\t\t\t\t\t5) Salir\n");
}

void chat_home(){
    while(1) {
        clear_screen();
        show_menu_home();
        new_file(m);
        mirar_archivo(m); //funcion mirar.c
    }
}

