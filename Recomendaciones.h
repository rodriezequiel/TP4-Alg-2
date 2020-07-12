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
		 * PRE: La lista de peliculas no vistas tiene que ser creada.
		 * 		Recibe un puntero a pelicula, de la lista de vistas.
		 * POST: Pasa a comparar esa peli vista con las peliculas no vistas, solo las que
		 * 		 no tienen puntuacion alta.
		 */
		void procesar_peliculas(Pelicula*, Lista<Pelicula*>&);

		/*
		 * PRE: Recibe un puntero a peli vista y no vista.
		 * POST: Compara entre esas dos pelis si tienen el mismo genero, mismo director y mismo actor,
		 * 		 si se cumple la primera y alguna de las otras dos se agrega a recomendaciones.
		 */
		void comparar_peliculas(Pelicula*, Pelicula*);

		/*
		 * PRE:-
		 * POST: Si la pelicula tiene puntuación >= 7 devuelve true, de lo contrario false.
		 */
		bool puntuacion_alta(Pelicula*);

		/*
		 * PRE:-
		 * POST: Si las peliculas tienen el mismo genero, devuelve true, de lo contrario false.
		 */
		bool comparar_genero(Pelicula*, Pelicula*);

		/*
		 * PRE:	-
		 * POST: Si las peliculas tienen el mismo director, devuelve true, de lo contrario false.
		 */
		bool comparar_directores(Pelicula*, Pelicula*);

		/*
		 * PRE:-
		 * POST: Devuelve true si almenos un actor de la pelicula vista se encuentra en una de la pelicula
		 * 		no vista.
		 */
		bool comparar_lista_actores(Pelicula* peli_vista, Pelicula* peli_no_vista );

		/*
		 * PRE: -
		 * POST: Compara si los dos actores son iguales.
		 */
		void comparar_actor(string*, Pelicula*, bool&);

		/*
		 * PRE: -
		 * POST: Lista las peliculas recomendadas.
		 */
		void mostrar_recomendadas();

		/*
		 * PRE:
		 * POST: Agrega las peliculas a recomendadas si tienen puntaje >= 7.
		 */
		void recomendar_por_puntaje(Lista<Pelicula*>&);

		/*
		 * PRE:
		 * POST: Devuelve la lista de peliculas recomendadas.
		 */
		Lista<Pelicula*> obtener_peliculas_recomendadas();
};




#endif /* RECOMENDACIONES_H_ */
