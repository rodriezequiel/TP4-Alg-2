
#include "Pelicula.h"

Pelicula::Pelicula(string t, string g, unsigned p, string d, Lista<string>* actores){

	titulo = t;
	genero = g;
	director = d;
	puntuacion = p;
	this->actores = actores;
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
/*
Lista<string> Pelicula::obtener_actores(){

	return this->actores;
}
*/
Pelicula::~Pelicula(){
}

void Pelicula::imprimir_datos(){
	cout << titulo << endl;
	cout << genero << endl;
	cout << director << endl;
	cout << puntuacion << endl;
	this->actores->listar();
}



