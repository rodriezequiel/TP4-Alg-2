#ifndef _MENU_H_
#define _MENU_H_

#include <iostream>
#include <string>

#include "Archivo.h"
#include "Listas.h"
#include "Pelicula.h"
#include "Recomendaciones.h"


class Menu{
private:
    Archivo archivo;
	Lista<Pelicula*> lista_no_vistas;
	Lista<Pelicula*> lista_vistas;
    Recomendaciones peliculas_recomendadas;

public:
    //Pre: -
    //Post: Constructor
    Menu();
    //
    //Post: Da inicio a la carga de las listas y ejecuta instruccicones_menu()
    void inicio();

    //Pre: -
    //Post: Bucle de menu para elegir que hace el programa
    void selector_de_caminos();

    //pre: -
    //Post: Imprime las instrucciones del menu
    void instrucciones_menu();

    //Pre: -
    //Post: Limpia la consola
    void limpiar_pantalla();

};

#endif // _MENU_H_
