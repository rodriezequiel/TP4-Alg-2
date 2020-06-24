
#include "Nodo_provisorio.h"

Nodo::Nodo(Dato d){

	dato = d;
	psig = 0;
}

Dato Nodo::get_dato(){
	return dato;
}

void Nodo::set_dato (Dato d){
	dato = d;
}

void Nodo::set_siguiente(Nodo *ps){
	psig = ps;
}

Nodo * Nodo::get_siguiente(){
	return psig;
}
