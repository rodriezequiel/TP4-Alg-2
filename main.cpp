
#include <iostream>
#include "Archivo.h"
#include "Listas.h"
#include "Pelicula.h"
#include "Recomendaciones.h"
int main(){

	Archivo archivo;
	Lista<Pelicula*> lista_no_vistas;
	Lista<Pelicula*> lista_vistas;
	archivo.cargar(lista_no_vistas);
	archivo.cargar_vistas(lista_vistas);

	Recomendaciones peliculas_recomendadas(lista_vistas, lista_no_vistas);
	peliculas_recomendadas.recomendar_peliculas();
	peliculas_recomendadas.mostrar_recomendadas();

	cout <<"FIN" << endl;
	return 0;
}




