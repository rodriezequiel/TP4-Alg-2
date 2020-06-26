
#ifndef PELICULA_H_
#define PELICULA_H_

#include "Lista_provisoria.h"

using namespace std;

class Pelicula {

private:

	string titulo, genero, director;
	unsigned puntuacion;
	Lista* actores;

public:

	//setters y getters
	void asignar_titulo(string);
	void asignar_genero(string);
	void asignar_director(string);
	void asignar_puntuacion(unsigned);
	void asignar_actor(string);

	string obtener_titulo();
	string obtener_genero();
	string obtener_director();
	unsigned obtener_puntuacion();
	Lista* obtener_actores();

	~Pelicula();
};

#endif /* PELICULA_H_ */
