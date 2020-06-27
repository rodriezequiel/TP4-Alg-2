
#include "Pelicula.h"

Pelicula::Pelicula(string t, string g, unsigned p, string d, Lista<string> a){

	titulo = t;
	genero = g;
	director = d;
	puntuacion = p;
	actores = a;
}

string Pelicula::obtener_titulo(){

	return this->titulo;
}

string Pelicula::obtener_director(){

	return this->director;
}

string Pelicula::obtener_genero(){

	return this->genero;
}

unsigned Pelicula::obtener_puntuacion(){

	return this->puntuacion;
}

Lista<string> Pelicula::obtener_actores(){

	return this->actores;
}

Pelicula::~Pelicula(){


}



