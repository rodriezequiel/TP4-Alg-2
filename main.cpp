
#include <iostream>
#include "Archivo.h"
#include "Listas.h"
#include "Pelicula.h"

int main(){

	Archivo archivo;
	Lista<Pelicula*> lista_no_vistas;

	archivo.cargar_no_vistas(lista_no_vistas);
	lista_no_vistas.listar();

	return 0;
}




