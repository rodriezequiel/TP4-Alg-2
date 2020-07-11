/*
 * Excepcion.h
 *
 *  Created on: 5 jul. 2020
 *      Author: carolina
 */

#ifndef EXCEPCION_H_
#define EXCEPCION_H_

#include <iostream>
#include <exception>

using namespace std;

class Excepcion_falta_no_vistas : public exception {

public:

	virtual const char* what() const throw(){
		return "No existe el archivo peliculas no vistas";
	}
};

#endif /* EXCEPCION_H_ */
