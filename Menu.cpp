#include "Menu.h"

#include <iostream>
#include <string>

#include "Archivo.h"
#include "Listas.h"
#include "Pelicula.h"
#include "Recomendaciones.h"

using namespace std;

Menu::Menu(){
    archivo.cargar(lista_no_vistas);
	archivo.cargar_vistas(lista_vistas);
	peliculas_recomendadas.recomendar_peliculas(lista_vistas, lista_no_vistas);
};

void Menu::inicio(){
    selector_de_caminos();
};

void Menu::selector_de_caminos(){
    string eleccion;
    bool esta_activo = true;

    instrucciones_menu();
    cout << "_ ";
    cin >> eleccion;
    while(esta_activo){

        if(eleccion == "VISTAS"){
            lista_vistas.listar();

        }else{
            if(eleccion == "NO.VISTAS"){
                lista_no_vistas.listar();

                }else{
                    if(eleccion == "RECOMENDAR"){
                        peliculas_recomendadas.mostrar_recomendadas();

                    }else{
                        if(eleccion == "SALIR"){
                            esta_activo = false;
                            limpiar_pantalla();
                            cout << "FIN DE PROGRAMA";

                            }else{
                                if(eleccion == "MENU"){
                                    instrucciones_menu();
                                }else{
                                cout << "TERMINO ingresado, NO reconocido. ";
                                cout << "\n\n\n\n";
                                }
                            }
                    }
            }
        }
    cout << endl;
    cout << "_ ";
    cin >> eleccion;
    }
}

void Menu::instrucciones_menu(){
    cout<< " ----------------------------------MENU---------------------------------- " <<endl;
    cout<< "|                                                                        |" <<endl;
    cout<< "| Ingrese UNO de los siguientes TERMINOS en mayusculas:                  |" <<endl;
    cout<< "|                                                                        |" <<endl;
    cout<< "|   VISTAS      Listar las peliculas vistas.                             |" <<endl;
    cout<< "|   NO.VISTAS   Listar las peliculas no vistas.                          |" <<endl;
    cout<< "|   RECOMENDAR  Listar peliculas recomendadas.                           |" <<endl;
    cout<< "|                                                                        |" <<endl;
    cout<< "|   MENU        Muestra esta ventana de texto                            |" <<endl;
    cout<< "|   SALIR       Termina el programa.                                     |" <<endl;
    cout<< " ------------------------------------------------------------------------ " <<endl;
    cout<<endl;
}

void Menu::limpiar_pantalla(){
    cout << string(50, '\n');
    /*
    #ifdef linux
        system("clear");
    #else
        system ("cls");
    #endif
    */
}
