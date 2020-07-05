#include <iostream>

#include "Archivo.h"
#include "Listas.h"
#include "Pelicula.h"
#include "Recomendaciones.h"
#include "Menu.h"
#include "Excepcion.h"



int main(){

		Archivo archivo;
		Lista<Pelicula*> lista_no_vistas;
		Lista<Pelicula*> lista_vistas;
		archivo.abrir_archivos(lista_no_vistas, ARCHIVO_NO_VISTAS);
		archivo.abrir_archivos(lista_vistas, ARCHIVO_VISTAS);

		if(archivo.obtener_abrio_vistas() == false){
			Recomendaciones peliculas_recomendadas;
			peliculas_recomendadas.recomendar_por_puntaje(lista_no_vistas);
			peliculas_recomendadas.mostrar_recomendadas();
		}
		else if(archivo.obtener_abrio_vistas() == true && archivo.obtener_abrio_no() == true) {
			Recomendaciones peliculas_recomendadas;
			peliculas_recomendadas.recomendar_peliculas(lista_vistas, lista_no_vistas);
			peliculas_recomendadas.mostrar_recomendadas();
		}

		try {
			archivo.verificar_ex();
		}
		catch (Excepcion &ex){
			cout << ex.what() << endl;
		}

	return 0;
};
