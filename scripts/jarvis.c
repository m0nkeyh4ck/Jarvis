// jarvis.c
#include <stdlib.h>
#include "brain/brain.h"



int main() {
    //ruta a guardar la informacions
    const char *rutaraiz = "/dev/shm/.data";
    // // archivo ejec primero menu
    const char *m = "/dev/shm/.data/m.txt"; 
    const char *m1 = "/dev/shm/.data/m1.txt";
    const char *m2 = "/dev/shm/.data/m2.txt";


    validation_system_ok(m,rutaraiz); // llama funcion brain 
    chat(m); // funcion chat 
    return 0;
}
