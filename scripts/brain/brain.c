// brain.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "brain.h"




void execute_command(const char *filename1, const char *rutaraiz) {

    //oculta el cursor
    system("tput civis");
    //hace que la pantalla siempre quede delante
    system("sleep 1 && wmctrl -r :ACTIVE: -b add,above");
    

    crearDirectorios(rutaraiz); //funion order folder
    vaciarArchivo(filename1); // funcion orde file



    printf("OK!");
}
