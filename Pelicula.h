
#ifndef PELICULA_H_
#define PELICULA_H_

#include "Listas.h"

using namespace std;


class Pelicula {

private:

	string titulo, genero, director;
	unsigned puntuacion;
	Lista<string>* actores;

public:

	//Pre:
	//Post:	Crea un objeto pelicula con los datos pasados por parametro.
	Pelicula(string tit, string gen, unsigned pun, string dir, Lista<string>* actores);

	//getters
	string obtener_titulo();
	string obtener_genero();
	string obtener_director();
	unsigned obtener_puntuacion();
	Lista<string> obtener_actores();
	void imprimir_datos();

	Pelicula(){};
	~Pelicula();
};

#endif /* PELICULA_H_ */
