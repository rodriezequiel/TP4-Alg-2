#ifndef RECOMENDACIONES_H_
#define RECOMENDACIONES_H_

#include "Pelicula.h"
#include "Listas.h"
#include "Nodo.h"
#include "Archivo.h"

class Recomendaciones {
	private:
	Lista<Pelicula*> lista_peliculas_recomendadas;

	public:
		/*
		 * PRE: -
		 * POST: Recomienda las pelis con puntaje alto y las peliculas
		 * 		 en base a la lista de peliculas vistas va a recorrer la lista,
		 *		 y una por una las procesa.
		 */
		void recomendar_peliculas(Lista<Pelicula*>&, Lista<Pelicula*>&);

		/*
		 * PRE: Recibe una pelicula vista
		 * POST:
		 */


		void procesar_peliculas(Pelicula*, Lista<Pelicula*>&);

		void comparar_peliculas(Pelicula*, Pelicula*);

		bool puntuacion_alta(Pelicula*);

		bool comparar_genero(Pelicula*, Pelicula*);

		bool comparar_directores(Pelicula*, Pelicula*);

		bool comparar_lista_actores(Pelicula*, Pelicula* );

		void comparar_actor(string*, Pelicula*, bool&);

		void mostrar_recomendadas();

		Lista<Pelicula*> obtener_peliculas_recomendadas();

		void recomendar_por_puntaje(Lista<Pelicula*>&);

};




#endif /* RECOMENDACIONES_H_ */
