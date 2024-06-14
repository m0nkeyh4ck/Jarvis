#ifndef BRAIN_H
#define BRAIN_H

//declarar las variables glopbales (rutas)
extern char *rutaraiz, *info_menu, *m, *m1, *m2;


// de definen las funcionan  para que sean vistas desde cualquier parte
void validation_system_ok(); // ejecuta la funcion de brain.c
void chat(); // funcion chat
void chat_home();// chat menu home
void mirar_archivo(char *filename); //funcion mirar
void clear_screen(); //funcion chat
void do_ping(const char *ip_address); // funcione ping
void request_and_ping(); // Nueva función para pedir IP y hacer ping
void say_hello(); //  funcion hola
void new_folder(); // funcion mkdir
void find_all();//  funcion find
void show_menu(); //funcion chat
void crearDirectorios(const char *ip_address);
void new_file(const char *menu1);
void action(char *command); //chat.c


#endif // BRAIN_H
