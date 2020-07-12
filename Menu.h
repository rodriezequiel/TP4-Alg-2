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

    void seleccionar_camino();
    void imprimir_instrucciones();
    void limpiar_pantalla();
    void continuar();
    void comenzar_recomendaciones();

public:

    /*
     * PRE:: -
   	 * POST: Constructor que carga los archivos y utiliza la clase recomendaciones
   	 *		para armar las peliculas sugeridas.
   	 */
    Menu();

    /*
     * PRE: -
     * POST: Da inicio a la carga de las listas
     */
    void iniciar();

};

#endif // _MENU_H_
