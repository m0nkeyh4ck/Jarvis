// jarvis.c
#include <stdlib.h>
#include "brain/brain.h"

int main() {

    //ruta a guardar la informacions
    const char *rutaraiz = "/dev/shm/.data";
    // // archivo ejec primero menu
    const char *m1 = "/dev/shm/.data/m1.txt"; 

    execute_command(m1,rutaraiz); // llama funcion brain 
    chat(m1); // funcion chat 
    return 0;
}
