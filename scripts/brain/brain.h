#ifndef BRAIN_H
#define BRAIN_H



// de definen las funcionan  para que sean vistas desde cualquier parte
void execute_command(); // ejecuta la funcion de brain.c
void chat(); // funcion chat
void mirar_archivo(const char *filename); //funcion mirar
void clear_screen(); //funcion chat
void do_ping(const char *ip_address); // funcione ping
void request_and_ping(); // Nueva función para pedir IP y hacer ping
void say_hello(); //  funcion hola
void new_folder(); // funcion mkdir
void find_all();//  funcion find
void show_menu(); //funcion chat
void crearDirectorios(const char *ip_address);
void vaciarArchivo(const char *menu1);


#endif // BRAIN_H
