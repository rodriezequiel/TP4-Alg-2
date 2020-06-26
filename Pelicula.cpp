
#include "Pelicula.h"

void Pelicula::asignar_titulo(string t){

	titulo = t;
}

void Pelicula::asignar_director(string d){

	director = d;
}

void Pelicula::asignar_genero(string g){

	genero = g;
}

void Pelicula::asignar_puntuacion(unsigned p){

	puntuacion = p;
}

void Pelicula::asignar_actor(string a){

	actores->insertar(a);
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

Lista* Pelicula::obtener_actores(){

	return this->actores;
}

Pelicula::~Pelicula(){

	delete actores;
}



