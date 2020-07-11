#ifndef _MENU_H_
#define _MENU_H_

#include <iostream>
#include <string>

#include "Archivo.h"
#include "Listas.h"
#include "Pelicula.h"
#include "Recomendaciones.h"
#include "Excepcion.h"


class Menu{

private:

    Archivo archivo;
	Lista<Pelicula*> lista_no_vistas;
    Lista<Pelicula*> lista_vistas;
    Recomendaciones peliculas_recomendadas;

public:

    /*
     * PRE:: -
   	 * POST: Constructor que carga los archivos y utiliza la clase recomendaciones
   	 *		para armar las peliculas sugeridas.
   	 */
    Menu();

    /*
     * PRE: -
     * POST: Da inicio a la carga de las listas y ejecuta instrucciones_menu()
     */
    void iniciar();

    /*
     * PRE: -
     * POST: Bucle de menu para elegir que hace el programa
     */
    void seleccionar_camino();

    /*
     * PRE: -
     * POST: Imprime las instrucciones del menu
     */
    void imprimir_instrucciones();

    /*
     * PRE: -
     * POST: Limipia la pantalla
     */
    void limpiar_pantalla();

    /*
     * PRE: -
     * POST: Pregunta al usuario si quiere continuar al menu
     */
    void continuar();

    /*
     * PRE: -
     * POST: Llama a los metodos que generaran las respectivas recomendaciones
     */
    void comenzar_recomendaciones();

};

#endif // _MENU_H_
