

#ifndef LISTA_PROVISORIA_H_
#define LISTA_PROVISORIA_H_

#include "Nodo_provisorio.h"

class Lista{

private:

	Nodo* primero;
	unsigned tam;

public:

	Lista();
	~Lista();
	bool lista_vacia();
	void insertar(Dato d, unsigned pos);
	Dato get_dato(unsigned pos);
	void elim_dato(unsigned pos);
	unsigned get_tam();
	Nodo* obtenerNodo(unsigned pos);
};

#endif /* LISTA_PROVISORIA_H_ */
