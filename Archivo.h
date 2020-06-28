
#ifndef ARCHIVO_H_
#define ARCHIVO_H_

#include <fstream>
#include <iostream>
#include <sstream>

#include "Pelicula.h"

using namespace std;

const string ARCHIVO_VISTAS = "peliculas_vistas.txt";
const string ARCHIVO_NO_VISTAS = "peliculas_no_vistas.txt";

class Archivo {

private:

	ifstream archivo_vistas;
	ifstream archivo_no_vistas;
	string titulo, genero, director, puntaje, actores;


public:

	Archivo();
	void cargar_vistas(Lista<Pelicula> &);
	void cargar_no_vistas(Lista<Pelicula*> &);
	~Archivo();
};

#endif /* ARCHIVO_H_ */
