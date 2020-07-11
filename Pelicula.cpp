
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


Lista<string*>* Pelicula::obtener_actores(){

	return this->pun_actores;
}

void Pelicula::imprimir_datos(){

	cout << "Titulo: " << titulo << endl;
	cout << "Genero: " << genero << endl;
	cout << "Director: " << director << endl;
	cout << "Puntuacion: " << puntuacion << endl;
	cout << "Actores: ";

	for(unsigned i=1; i<=pun_actores->obtener_tam(); i++){

		cout << *(pun_actores->obtener_dato(i)) << " ";
	}

	cout << endl << endl;
}



