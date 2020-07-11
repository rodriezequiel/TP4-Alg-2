
#ifndef LISTAS_H_
#define LISTAS_H_

#include <iostream>
#include "Nodo.h"

template<class T>
class Lista {

private:

	Nodo<T>* primero;
	int tam;
	bool copia;

public:
	/*
	* PRE: -
	* POST: Construye una lista vacia
	*/
	Lista();

	/*
	* PRE: Recibe un dato T
	* POST: Agrega un nodo a la lista e incrementa en 1 el tamaño de la misma
	*/
	void insertar_dato(T &dato_nuevo);

	/*
	* PRE: Debe existir el nodo en la posicion pos
	* POST: Devuelve el nodo en dicha posicion de la lista.
	*/
	Nodo<T>* obtener_nodo(unsigned pos);

	/*
	* PRE: Lista creada
	* POST: Devuelve verdadero si la lista es vacia, falso de lo contrario
	*/
	bool lista_vacia();

	/*
	* PRE: Lista creada y no vacia, 0 < pos <= tam
	* POST: Libera el nodo que esta en la posicion
	*/
	void eliminar_dato(unsigned pos);

	/*
	* PRE: -
	* POST: Destruye la lista, libera memoria, elimina recursos, etc
	*/
	~Lista();

	/*
	* PRE: Lista creada, ademas el dato T debera tener un metodo que imprima su contenido.
	* POST: Imprime los datos de la lista
	 */
	void listar();

	/*
	 * PRE: -
	 * POST: Devuelve un unsigned
	 */
	unsigned obtener_tam();

	/*
	 * PRE: -
	 * POST: Devuelve un dato T
	 */
	T obtener_dato(unsigned pos);

	/*
	 * PRE: -
	 * POST: Establece el atributo copia en true
	 */
	void es_copia();
};

template<class T>
Lista<T>::Lista(){

	primero = 0;
	tam = 0;
	copia = false;
}

template<class T>
void Lista<T>::insertar_dato(T &dato_nuevo){

	Nodo<T>* nuevo_nodo = new Nodo<T>(dato_nuevo);

	if(this->lista_vacia()){

		primero = nuevo_nodo;
	}
	else {

		Nodo<T>* anterior = obtener_nodo(this->tam);
		anterior->establecer_siguiente(nuevo_nodo);
	} tam ++;
}

template <class T>
Nodo<T>* Lista<T>::obtener_nodo(unsigned pos){

	Nodo<T>* aux = primero;
	unsigned i = 1;

	while (i < pos){

		aux = aux->obtener_siguiente();
		i++;
	}
	return aux;
}

template<class T>
bool Lista<T>::lista_vacia(){

	return(primero == 0);
}

template<class T>
Lista<T>::~Lista(){

	while(!this->lista_vacia()){

		this->eliminar_dato(1);
	}
}

template<class T>
void Lista<T>::eliminar_dato(unsigned pos){

	Nodo<T>* aux = primero;

	if(pos == 1){

		primero = primero->obtener_siguiente();
	}
	else {
		unsigned i = 1;
		Nodo<T>* anterior;

		while(i < pos){

			anterior = aux;
			aux = aux->obtener_siguiente();
			i++;
		}

		anterior->establecer_siguiente(aux->obtener_siguiente());
	}

	if(copia) aux->cambiar_liberado();

	delete aux;
	tam --;
}

template<class T>
void Lista<T>::listar(){

	Nodo<T>* aux = primero;
	T dato_aux;

	if(this->lista_vacia()){

		cout << "La lista esta vacia" << endl;

	}
	else {
		while(aux != NULL){

		dato_aux = aux->obtener_dato();
		dato_aux->imprimir_datos();
		aux = aux->obtener_siguiente();
		}
	}
}

template < class T >
unsigned Lista<T>::obtener_tam(){

	return tam;
}

template <class T>
T Lista<T>::obtener_dato(unsigned pos){

	Nodo<T>* paux = obtener_nodo(pos);
	return paux -> obtener_dato();
}

template <class T>
void Lista<T>::es_copia(){

	copia = true;
}

#endif /* LISTAS_H_ */
