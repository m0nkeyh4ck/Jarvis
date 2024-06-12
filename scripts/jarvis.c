// jarvis.c
#include <stdlib.h>
#include "brain/brain.h"

int main() {
    execute_command(); // llama funcion brain 
    system("sleep 1 && wmctrl -r :ACTIVE: -b add,above");
    chat(); // funcion chat 
    return 0;
}
