// brain.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "brain.h"
#include <unistd.h> // Para sleep

char *rutaraiz = "/dev/shm/.data";
char *info_menu = "/dev/shm/.data/info_menu";
char *m = "/dev/shm/.data/info_menu/m.txt";
char *m1 = "/dev/shm/.data/info_menu/m_home.txt";
char *m2 = "/dev/shm/.data/info_menu/m2.txt";

// funion que se usa para validar que todo funiona, tambien crea lo archivos de trabajo
void validation_system_ok() {

    //oculta el cursor
    system("tput civis");
    //hace que la pantalla siempre quede delante
    system("sleep 1 && wmctrl -r :ACTIVE: -b add,above");
    
    //crea la carpera y los archivos base
    crearDirectorios(rutaraiz); //funion order folder
    crearDirectorios(info_menu); //funion order folder
     // funcion orde file
    //new_file(m1); // funcion orde file

    //printf("OK!");

}

//...........................................................................

void opt_1(){
    clear_screen();
    //printf("\n\nEste es para hackear Hack the box\n\n");
    usleep(1000000);
}

void opt_2(){
    clear_screen();
    request_and_ping();
    //printf("\n\nEste es para hackear try hck m,e\n\n");
    usleep(1000000);
}

void opt_3(){
    clear_screen();
    //printf("\n\nEste es para hackear hack my vm\n\n");
    usleep(1000000);
}

void opt_4(){
    chat_home();
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