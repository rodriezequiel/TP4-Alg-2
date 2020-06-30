
#ifndef PELICULA_H_
#define PELICULA_H_

#include "Listas.h"

using namespace std;


class Pelicula {

private:

	string titulo, genero, director;
	unsigned puntuacion;
	Lista<string*> actores;
	Lista<string*>* pun_actores;

public:

	//Pre:
	//Post:	Crea un objeto pelicula con los datos pasados por parametro.
	Pelicula(string tit, string gen, unsigned pun, string dir);

	//getters
	string obtener_titulo();
	string obtener_genero();
	string obtener_director();
	unsigned obtener_puntuacion();
	Lista<string*> obtener_actores();

	//imprime datos por pantalla.(provisorio)
	void imprimir_datos();

	//Pre:
	//Post: Agrega un actor a la lista de actores.
	void agregar_actor(string);
};

#endif /* PELICULA_H_ */
