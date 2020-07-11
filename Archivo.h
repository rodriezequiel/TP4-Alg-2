
#ifndef ARCHIVO_H_
#define ARCHIVO_H_

#include <fstream>
#include <iostream>
#include <sstream>

#include "Pelicula.h"
#include "Excepcion.h"

using namespace std;

const string ARCHIVO_VISTAS = "peliculas_vistas.txt";
const string ARCHIVO_NO_VISTAS = "peliculas_no_vistas.txt";

class Archivo {

private:

	string titulo, genero, director, puntaje, actores;
	bool abrio_vistas;
	bool abrio_no_vistas;
	Excepcion excepcion;

public:

	/*
	 * PRE: -
	 * POST: Construye un objeto de tipo Archivo
	 */
	Archivo();

	/*
	 * PRE: Recibe un puntero a una lista y un archivo de texto
	 * POST: Carga correctamente los datos leidos del archivo de texto a la lista correspondiente
	 */
	void cargar_listas(Lista<Pelicula*> &lista, ifstream* archivo);

	/*
	 * PRE: Recibe un puntero a una lista y un string
	 * POST: Cierra los archivos correctamente
	 */
	void abrir_archivos(Lista<Pelicula*> & lista, string archivo);

	/*
	 * PRE: Recibe un string
	 * POST: Establece true o false al atributo correspondiente
	 */
	void chequear_archivo(string archivo);

	/*
	* PRE: Recibe un string
	* POST: Devuelve true y el string ingresado es igual a ARCHIVO_VISTAS, false en caso contrario
	*/
	bool comparar_archivos(string archivo);

	/*
	* PRE: -
	* POST: Devuelve un booleano
	*/
	bool obtener_abrio_vistas();

	/*
	* PRE: -
	* POST: Devuelve un booleano
	*/
	bool obtener_abrio_no();

	/*
	* PRE: Existe el objeto
	* POST: Destruye el objeto
	*/
	void verificar_ex();
};

#endif /* ARCHIVO_H_ */
