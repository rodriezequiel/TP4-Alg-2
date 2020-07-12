#ifndef RECOMENDACIONES_H_
#define RECOMENDACIONES_H_

#include "Pelicula.h"
#include "Listas.h"
#include "Nodo.h"
#include "Archivo.h"

class Recomendaciones {

private:

	Lista<Pelicula*> lista_peliculas_recomendadas;

	bool comparar_genero(Pelicula*, Pelicula*);
	bool comparar_directores(Pelicula*, Pelicula*);
	bool comparar_lista_actores(Pelicula* peli_vista, Pelicula* peli_no_vista );
	void comparar_actor(string*, Pelicula*, bool&);
	void procesar_peliculas(Pelicula*, Lista<Pelicula*>&);
	void comparar_peliculas(Pelicula*, Pelicula*);
	bool puntuacion_alta(Pelicula*);

public:
		/*
		 * PRE: -
		 * POST: Crea un objeto recomendaciones seteando la lista-peliculas-recomendadas
		 * 		 como copia.
		 */
		Recomendaciones();

		/*
		 * PRE: -
		 * POST: Recomienda las pelis con puntaje alto y
		 * 		 en base a la lista de peliculas vistas va a recorrer esa lista,
		 *		 y una por una las procesa.
		 */
		void recomendar_peliculas(Lista<Pelicula*>&, Lista<Pelicula*>&);

		/*
		 * PRE: Deben haberse cargado peliculas en recomendadas
		 * POST: Imprime las peliculas recomendadas.
		 */
		void mostrar_recomendadas();

		/*
		 * PRE: La lista debe tener peliculas cargadas
		 * POST: Agrega las peliculas a recomendadas si tienen puntaje >= 7.
		 */
		void recomendar_por_puntaje(Lista<Pelicula*>&);

		/*
		 * PRE: -
		 * POST: Devuelve la lista de peliculas recomendadas.
		 */
		Lista<Pelicula*> obtener_peliculas_recomendadas();
};




#endif /* RECOMENDACIONES_H_ */
