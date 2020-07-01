/*
 * Listas.h
 *
 *  Created on: 26 jun. 2020
 *      Author: carolina
 */

#ifndef LISTAS_H_
#define LISTAS_H_

#include <iostream>
#include "Nodo.h"

template<class T>
class Lista {

	private:
		Nodo<T>* primero;
		int tam;

	public:
		//Pre: -
		//Post: Construye una lista vacia
		Lista();

		//Pre: Recibe un dato T
		//Post: Agrega un nodo a la lista e incrementa en 1 el tamaño de la misma
		void insertar_dato(T &dato_nuevo);

		//Pre: Debe existir el nodo en la posicion pos
		//Post: Devuelve el nodo en dicha posicion de la lista.
		Nodo<T>* obtener_nodo(unsigned pos);

		//Pre: Lista creada
		//Post: Devuelve verdadero si la lista es vacia, falso de lo contrario
		bool lista_vacia();

		//Pre: Lista creada y no vacia, 0 < pos <= tam
		//Post: Libera el nodo que esta en la posicion
		void eliminar_dato(unsigned pos);

		//Pre: -
		//Post: Destruye la lista, libera memoria, elimina recursos, etc
		~Lista();

		//Pre: Lista creada
		//Post: Imprime los datos de la lista
		void listar();

		void listar_actores();

		unsigned obtener_tam();

		T obtener_dato(unsigned pos);
};

template<class T>
Lista<T>::Lista(){
	primero = 0;
	tam = 0;
}

template<class T>
void Lista<T>::insertar_dato(T &dato_nuevo){

	Nodo<T>* nuevo_nodo = new Nodo<T>(dato_nuevo);

	if(this->lista_vacia()){

		primero = nuevo_nodo;

	} else {

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

	} else {
		unsigned i = 1;
		Nodo<T>* anterior;

		while(i < pos){

			anterior = aux;
			aux = aux->obtener_siguiente();
			i++;
		}

		anterior->establecer_siguiente(aux->obtener_siguiente());
	}

	delete aux;
	tam --;
}

template<class T>
void Lista<T>::listar(){
	Nodo<T>* aux = primero;
	T dato_aux;
	if(this->lista_vacia()){
		cout << "La lista esta vacia" << endl;
	} else {
		while(aux != NULL){
		dato_aux = aux->obtener_dato();
		dato_aux->imprimir_datos();
		aux = aux->obtener_siguiente();
		}
	}
}

template<class T>
void Lista<T>::listar_actores(){

	Nodo<T>* aux = primero;
	string* actor;

	if(this->lista_vacia()){

		cout << "No hay actores cargados" << endl;

	} else {

		while(aux != NULL){

			actor = aux->obtener_dato();
			cout << "\nACTOR: " << *actor << endl;
			aux = aux->obtener_siguiente();
		}
	}
}

template < class T >
unsigned Lista<T>::obtener_tam()
{
	return tam;
}

template <class T>
T Lista<T>::obtener_dato(unsigned pos)
{
	Nodo<T>* paux = obtener_nodo(pos);
	return paux -> obtener_dato();
}

#endif /* LISTAS_H_ */
