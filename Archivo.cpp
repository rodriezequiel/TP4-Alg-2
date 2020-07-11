
#include "Archivo.h"
#include "Listas.h"
#include "Pelicula.h"
#include <string.h>

Archivo::Archivo(){
	abrio_vistas = true;
	abrio_no_vistas = true;
}

void Archivo::cargar(Lista<Pelicula*> &lista, ifstream* archivo_pelis){

	string separado;
	istringstream stream_actores;
	Pelicula* pelicula;

		while(!(*archivo_pelis).eof()){

			getline(*archivo_pelis, titulo);
			getline(*archivo_pelis, genero);
			getline(*archivo_pelis, puntaje);
			getline(*archivo_pelis, director);
			getline(*archivo_pelis, actores);

			stream_actores.str(actores);

			pelicula = new Pelicula (titulo, genero, stoi(puntaje), director);

			while (!stream_actores.eof()){

				stream_actores >> (separado);
				pelicula->agregar_actor(separado);
			}

			lista.insertar_dato(pelicula);

			if (!(*archivo_pelis).eof()) getline(*archivo_pelis, titulo);

			stream_actores.clear();
		}
}

void Archivo::abrir_archivos(Lista<Pelicula*> &lista, string archivo){

	ifstream archivo_pelis(archivo);

	if(archivo_pelis.fail()){
		chequear_archivo(archivo);
	} else {
		cargar(lista, &archivo_pelis);
	}
	archivo_pelis.close();
}

void Archivo::chequear_archivo(string archivo){

	if(comparar_archivos(archivo) == true){
		abrio_vistas = false;
	} else {
		abrio_no_vistas = false;
	}
}

bool Archivo::comparar_archivos(string archivo){

	unsigned i = 0;
	unsigned tam = archivo.length();
	bool coincidencia = true;

	while(i < tam && coincidencia){
		if(archivo[i] != ARCHIVO_VISTAS[i]){
			coincidencia = false;
		} else {
			i++;
		}
	}

	return coincidencia;
}

bool Archivo::obtener_abrio_vistas(){
	return abrio_vistas;
}

bool Archivo::obtener_abrio_no(){
	return abrio_no_vistas;
}

void Archivo::verificar_ex(){

	if(abrio_no_vistas == false){
		throw excepcion;
	}
}


