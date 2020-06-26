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
		void insertar_dato(T dato_nuevo);

		//Pre: Lista creada
		//Post: Devuelve verdadero si la lista es vacia, falso de lo contrario
		bool lista_vacia();

		//Pre: Lista creada y no vacia, 0 < pos <= tam
		//Post: Libera el nodo que esta en la posicion
		void eliminar_dato(unsigned pos);

		//Pre: -
		//Post: Destruye la lista, libera memoria, elimina recursos, etc
		~Lista();
};

template<class T>
Lista<T>::Lista(){
	primero = 0;
	tam = 0;
}

template<class T>
void Lista<T>::insertar_dato(T dato_nuevo){
	Nodo<T>* nuevo_nodo = new Nodo<T>(dato_nuevo);
	Nodo<T>* aux = primero;
	if(this->lista_vacia()){
		primero = nuevo_nodo;
	} else {
		while(aux->obtener_siguiente()){
			aux = aux->obtener_siguiente();
		} aux->establecer_siguiente(nuevo_nodo);
	} tam ++;
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
	if(pos == 1 || !(primero->obtener_siguiente())){
		primero = aux->obtener_siguiente();
	} else {
		int i = 1;
		Nodo<T>* anterior;
		while(i < pos && aux->obtener_siguiente()){
			anterior = aux;
			aux = aux->obtener_siguiente();
			i++;
		} anterior->establecer_siguiente(aux->obtener_siguiente());
	} delete aux;
	tam --;
}


#endif /* LISTAS_H_ */
