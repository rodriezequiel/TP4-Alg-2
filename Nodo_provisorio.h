

#ifndef NODO_PROVISORIO_H_
#define NODO_PROVISORIO_H_

#include <iostream>

using namespace std;

typedef int Dato;

class Nodo{

private:

	Dato dato;
	Nodo * psig;

public:

	Nodo(Dato d);
	~Nodo(){}
	void set_dato(Dato d);
	Dato get_dato();
	void set_siguiente(Nodo* ps);
	Nodo* get_siguiente();

};

#endif /* NODO_PROVISORIO_H_ */
