
#ifndef ARCHIVO_H_
#define ARCHIVO_H_

#include <fstream>

using namespace std;

const string ARCHIVO_VISTAS = "peliculas_vistas.txt";
const string ARCHIVO_NO_VISTAS = "peliculas_no_vistas.txt";

class Archivo {

private:

	ifstream archivo_vistas;
	ifstream archivo_no_vistas;


public:

	void cargar_vistas();
	void cargar_no_vistas();


};

#endif /* ARCHIVO_H_ */
