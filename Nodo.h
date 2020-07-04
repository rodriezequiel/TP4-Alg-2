/*
 * Nodo.h
 *
 *  Created on: 26 jun. 2020
 *      Author: carolina
 */

#ifndef NODO_H_
#define NODO_H_

#include <iostream>

using namespace std;

template<class T>

class Nodo {

	private:
		T dato;
		Nodo<T>* psig;
		bool liberado;

	public:
		//Pre: Recibe un dato T
		//Crea un nodo con el dato que recibe e inicializa siguiente en NULL
		Nodo(T dato_nuevo);

		//Pre: Existe el nodo
		//Post: Devuelve un dato T
		T obtener_dato();

		//Pre: Existe el nodo
		//Post: Devuelve el puntero al siguiente nodo, si es el ultimo devuelve NULL
		Nodo<T>* obtener_siguiente();

		//Pre: -
		//Post: El puntero al siguiente nodo apuntara a psig
		void establecer_siguiente(Nodo<T>* psig);

		//Pre: -
		//Post: Le otorga un valor al atributo dato
		void establecer_dato(T dato_nuevo);

		void cambiar_liberado();

		~Nodo();

};

template<class T>
T Nodo<T>::obtener_dato(){
	return dato;
}

template<class T>
void Nodo<T>::establecer_siguiente(Nodo<T>* psig){
	this->psig = psig;
}

template<class T>
Nodo<T>* Nodo<T>::obtener_siguiente(){
	return this->psig;
}

template<class T>
Nodo<T>::Nodo(T dato_nuevo){
	dato = dato_nuevo;
	this->psig = NULL;
	liberado = false;
}

template <class T>
void Nodo<T>::cambiar_liberado(){

	if(this->liberado==false){
		this->liberado = true;
	} else this->liberado = false;
}

template<class T>
Nodo<T>::~Nodo(){

	if (liberado==false){
		delete dato;
		liberado = true;
	}
}

template<class T>
void Nodo<T>::establecer_dato(T dato_nuevo){
	dato = dato_nuevo;
}

#endif /* NODO_H_ */
