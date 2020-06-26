
#include "Archivo.h"
#include "Listas.h"
#include "Pelicula.h"


Archivo::Archivo(){

	archivo_vistas.open(ARCHIVO_VISTAS);
	archivo_no_vistas.open(ARCHIVO_NO_VISTAS);
}

Archivo::~Archivo(){

	archivo_vistas.close();
	archivo_no_vistas.close();
}

template<class T>
void Archivo::cargar_no_vistas(Lista<Pelicula> &lista_no_vistas){

	string entrada, separado;
	istringstream stream_actores;

	if (!archivo_no_vistas.fail()){

		while(!archivo_no_vistas.eof()){

			getline(archivo_no_vistas, entrada);
			pelicula.asignar_titulo(entrada);
			getline(archivo_no_vistas, entrada);
			pelicula.asignar_genero(entrada);
			getline(archivo_no_vistas, entrada);
			pelicula.asignar_puntuacion(stoi(entrada));
			getline(archivo_no_vistas, entrada);
			pelicula.asignar_director(entrada);
			getline(archivo_no_vistas, entrada);

			stream_actores.str(entrada);

			while (!stream_actores.eof()){

				stream_actores >> separado;
				pelicula.asignar_actor(separado);
			}


			if (!archivo_no_vistas.eof()) getline(archivo_no_vistas, entrada);

		}
	}
}
