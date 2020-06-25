
#include "Pelicula.h"

void Pelicula::set_titulo(string t){

	titulo = t;
}

void Pelicula::set_director(string d){

	director = d;
}

void Pelicula::set_genero(string g){

	genero = g;
}

void Pelicula::set_puntuacion(unsigned p){

	puntuacion = p;
}

void Pelicula::set_actor(string a){

	actores.insertar(a);
}

string Pelicula::get_titulo(){

	return this->titulo;
}

string Pelicula::get_director(){

	return this->director;
}

string Pelicula::get_genero(){

	return this->genero;
}

unsigned Pelicula::get_puntuacion(){

	return this->puntuacion;
}

Lista Pelicula::get_actores(){

	return this->actores;
}




