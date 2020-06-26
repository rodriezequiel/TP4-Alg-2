
#ifndef PELICULA_H_
#define PELICULA_H_

#include "Lista_provisoria.h"
#include "Listas.h"

using namespace std;


class Pelicula {

private:

	string titulo, genero, director;
	unsigned puntuacion;
	Lista<string>* actores;

public:

	//setters y getters
	void asignar_titulo(string);
	void asignar_genero(string);
	void asignar_director(string);
	void asignar_puntuacion(unsigned);
	//void asignar_actor(string);

	string obtener_titulo();
	string obtener_genero();
	string obtener_director();
	unsigned obtener_puntuacion();
	Lista<string>* obtener_actores();

	~Pelicula();
};

#endif /* PELICULA_H_ */
