#include "Recomendaciones.h"

using namespace std;

void Recomendaciones::recomendar_peliculas(Lista<Pelicula*>& lista_peliculas_vistas, Lista<Pelicula*>& lista_peliculas_no_vistas){
	recomendar_por_puntaje(lista_peliculas_no_vistas);

	if(!lista_peliculas_vistas.lista_vacia()){
		for(unsigned i = 1; i <= lista_peliculas_vistas.obtener_tam(); i++){
			procesar_peliculas(lista_peliculas_vistas.obtener_dato(i),lista_peliculas_no_vistas );
		}
	}
}

void Recomendaciones::procesar_peliculas(Pelicula* peli_vista, Lista<Pelicula*>& lista_peliculas_no_vistas ){
	Pelicula* peli_no_vista;

	for(unsigned i = 1; i <= lista_peliculas_no_vistas.obtener_tam(); i++){
		peli_no_vista = lista_peliculas_no_vistas.obtener_dato(i);
		if (puntuacion_alta(peli_no_vista) == false){
			comparar_peliculas(peli_vista, lista_peliculas_no_vistas.obtener_dato(i));
		}
	}
}

void Recomendaciones::comparar_peliculas(Pelicula* peli_vista, Pelicula* peli_no_vista){
	bool mismo_genero = false;
	bool mismo_director = false;
	bool mismo_actor = false;
	mismo_genero = comparar_genero(peli_vista, peli_no_vista);
	mismo_director = comparar_directores(peli_vista, peli_no_vista);
	mismo_actor = comparar_lista_actores(peli_vista, peli_no_vista);

	if (mismo_genero == true && (mismo_director == true || mismo_actor == true)){
		 lista_peliculas_recomendadas.insertar_dato(peli_no_vista);
	}
}

bool Recomendaciones::puntuacion_alta(Pelicula* pelicula){
	return pelicula->obtener_puntuacion() >= 7;
}

bool Recomendaciones::comparar_genero(Pelicula* peli_vista, Pelicula* peli_no_vista){
	return (peli_vista->obtener_genero() == peli_no_vista->obtener_genero());
}

bool Recomendaciones::comparar_directores(Pelicula* peli_vista, Pelicula* peli_no_vista){
	return(peli_vista->obtener_director() == peli_no_vista->obtener_director());
}

bool Recomendaciones::comparar_lista_actores(Pelicula* peli_vista, Pelicula* peli_no_vista){
	bool mismo_actor = false;
	Lista<string*>* lista_actores;
	lista_actores = peli_vista->obtener_actores();
	unsigned i = 1;
	while (i <= lista_actores->obtener_tam() && mismo_actor == false){
		comparar_actor(lista_actores->obtener_dato(i), peli_no_vista, mismo_actor);
		i++;
	}
	return mismo_actor;
}

void Recomendaciones::comparar_actor(string* actor, Pelicula* peli_no_vista,  bool& mismo_actor){
	unsigned i = 1;
	string* actor2;
	Lista<string*>* lista_actores2;
	lista_actores2 = peli_no_vista->obtener_actores();

	while (i <= lista_actores2->obtener_tam() && mismo_actor == false){
		actor2 = lista_actores2->obtener_dato(i);
		if(*actor == *actor2){
			mismo_actor = true;
		}else{
			i++;
		}
	}
}

void Recomendaciones::recomendar_por_puntaje(Lista<Pelicula*>& lista_peliculas_no_vistas){
	Pelicula* peli_no_vista;

	for(unsigned i = 1; i <= lista_peliculas_no_vistas.obtener_tam(); i++){
		peli_no_vista = lista_peliculas_no_vistas.obtener_dato(i);
		if(puntuacion_alta(peli_no_vista) == true){
			lista_peliculas_recomendadas.insertar_dato(peli_no_vista);
		}
	}
}

Lista<Pelicula*> Recomendaciones::obtener_peliculas_recomendadas(){
	return this->lista_peliculas_recomendadas;
}

void Recomendaciones::mostrar_recomendadas(){
	Pelicula* peli;
	cout << "Las peliculas recomendadas son: " << endl;
	for(unsigned i = 1; i <= lista_peliculas_recomendadas.obtener_tam(); i++){
		peli = lista_peliculas_recomendadas.obtener_dato(i);
		cout << "-------------------PELICULA " << peli->obtener_titulo() << endl;
		cout << endl;
	}
}
