
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

	/*
	 * PRE: Recibe variables de tipo string y unsigned
	 * POST: Crea el objeto pelicula
	 */
	Pelicula(string tit, string gen, unsigned pun, string dir);

	/*
	 * PRE: Existe el objeto pelicula
	 * POST: Devuelve un string
	 */
	string obtener_titulo();

	/*
	 * PRE: Existe el objeto pelicula
	 * POST: Devuelve un string
	 */
	string obtener_genero();

	/*
	 * PRE: Existe el objeto pelicula
	 * POST: Devuelve un string
	 */
	string obtener_director();

	/*
	 * PRE: Existe el objeto pelicula
	 * POST: Devuelve un unsigned
	 */
	unsigned obtener_puntuacion();

	/*
	 * PRE: Existe el objeto pelicula
	 * POST: Devuelve un puntero de tipo Lista<string*>*
	 */
	Lista<string*>* obtener_actores();

	/*
	 * PRE: -
	 * POST: Imprime por pantalla los atributos del objeto Pelicula
	 */
	void imprimir_datos();

	/*
	 * PRE: Recibe un string
	 * POST: Llama al metodo necesario para agregar un actor a la lista de actores
	 */
	void agregar_actor(string);

	/*
	 * PRE:-
	 * POST: Imprime todos los actores de la pelicula.
	 */
	void listar_actores();
};

#endif /* PELICULA_H_ */
