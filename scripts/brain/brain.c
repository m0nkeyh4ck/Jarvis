// brain.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "brain.h"
#include <unistd.h> // Para sleep


// funion que se usa para validar que todo funiona, tambien crea lo archivos de trabajo
void validation_system_ok(const char *filename1, const char *rutaraiz) {

    //oculta el cursor
    system("tput civis");
    //hace que la pantalla siempre quede delante
    system("sleep 1 && wmctrl -r :ACTIVE: -b add,above");
    

    //crea la carpera y los archivos base
    crearDirectorios(rutaraiz); //funion order folder
    new_file(filename1); // funcion orde file

    printf("OK!");
}

//...........................................................................

void opt_1(){
    clear_screen();
    printf("\n\nEste es para hackear Hack the box\n\n");
    usleep(1000000);
}

void opt_2(){
    clear_screen();
    printf("\n\nEste es para hackear try hck m,e\n\n");
    usleep(1000000);
}

void opt_3(){
    clear_screen();
    printf("\n\nEste es para hackear hack my vm\n\n");
    usleep(1000000);
}

void opt_4(){
    printf("Comando no reconocido: 4");
}

void opt_salir(){
    system("wmctrl -r :ACTIVE: -b remove,above");
	system("tput cnorm");
    exit(EXIT_SUCCESS);
}




// Función para realizar una acción basada en el comando leído
void action(char *command) {
    if (strcmp(command, "Salir") == 0 || strcmp(command, "salir") == 0 || strcmp(command, "5") == 0) {
        opt_salir();
    } else if (strcmp(command, "1") == 0) {
        opt_1();
    } else if (strcmp(command, "2") == 0) {
        opt_2();
    } else if (strcmp(command, "3") == 0) {
        opt_3();
    } else if (strcmp(command, "4") == 0) {
        opt_4();
    } else {
        printf("Comando no reconocido: %s\n", command);
    }
}