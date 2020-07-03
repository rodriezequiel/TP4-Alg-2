#include <iostream>

#include "Archivo.h"
#include "Listas.h"
#include "Pelicula.h"
#include "Recomendaciones.h"
#include "Menu.h"



int main(){

	Archivo archivo;
	Lista<Pelicula*> lista_no_vistas;
	Lista<Pelicula*> lista_vistas;

	Recomendaciones peliculas_recomendadas;
	peliculas_recomendadas.mostrar_recomendadas();

	cout <<"FIN" << endl;
	/*
	Menu menu_1;
	menu_1.selector_de_caminos();
	*/
	return 0;
};
