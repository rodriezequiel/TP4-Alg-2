
#include "Lista_provisoria.h"

Lista::Lista(){

	primero = 0;
	tam = 0;
}

Lista::~Lista(){

	while(!(this->lista_vacia())){

		this->elim_dato(1);
	}
}

bool Lista::lista_vacia(){

	return(primero==0);
}

void Lista::insertar(Dato d){

	insertar(d, get_tam());
}

void Lista::insertar(Dato d, unsigned pos){

	Nodo* pnodo = new Nodo(d);

	if (pos==1){

		pnodo->set_siguiente(primero);
		primero=pnodo;

	} else{

		Nodo* anterior = obtenerNodo(pos-1);
		pnodo->set_siguiente(anterior->get_siguiente());
		anterior->set_siguiente(pnodo);

	}
	this->tam++;
}

Dato Lista::get_dato(unsigned pos){

	Nodo* paux = primero;
	unsigned i = 1;

	while (i < pos && (paux->get_siguiente())){

		paux = paux->get_siguiente();
		i++;
	}

	return paux->get_dato();
}

void Lista::elim_dato(unsigned pos){

	Nodo* paux = primero;

	if (pos==1 || !(primero->get_siguiente())){

		primero = paux->get_siguiente();

	} else{

		unsigned i = 1;
		Nodo* pant;

		while (i < pos && paux->get_siguiente()){

			pant = paux;
			paux = paux->get_siguiente();
			i++;
		}

		pant->set_siguiente(paux->get_siguiente());
	}

	delete paux;
	tam--;
}

unsigned Lista::get_tam(){
	return tam;
}

Nodo* Lista::obtenerNodo(unsigned pos){

	Nodo* aux = primero;
	unsigned i = 1;

	while (i<pos){

		aux = aux->get_siguiente();
		i++;
	}
	return aux;
}




