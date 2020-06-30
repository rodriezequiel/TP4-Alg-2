
#include "Pelicula.h"

Pelicula::Pelicula(string t, string g, unsigned p, string d){

	titulo = t;
	genero = g;
	director = d;
	puntuacion = p;
	pun_actores= &actores;
}

void Pelicula::agregar_actor(string actor){

	string * puntero = new string(actor);

	actores.insertar_dato(puntero);
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

void Pelicula::imprimir_datos(){

	cout << titulo << endl;
	cout << genero << endl;
	cout << director << endl;
	cout << puntuacion << endl;
	pun_actores->listar_actores();
}



