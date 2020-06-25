
#ifndef PELICULA_H_
#define PELICULA_H_

#include "Lista_provisoria.h"

using namespace std;

class Pelicula {

private:

	string titulo, genero, director;
	unsigned puntuacion;
	Lista actores;

public:

	//setters y getters
	void set_titulo(string);
	void set_genero(string);
	void set_director(string);
	void set_puntuacion(unsigned);
	void set_actor(string);

	string get_titulo();
	string get_genero();
	string get_director();
	unsigned get_puntuacion();
	Lista get_actores();
};

#endif /* PELICULA_H_ */
