#include "Menu.h"

#include <iostream>
#include <string>

#include "Archivo.h"
#include "Listas.h"
#include "Pelicula.h"
#include "Recomendaciones.h"

using namespace std;

Menu::Menu(){
    archivo.cargar(lista_no_vistas, archivo);
	archivo.cargar_vistas(lista_vistas, archivo);
	peliculas_recomendadas.recomendar_peliculas(lista_vistas, lista_no_vistas);
};

void Menu::inicio(){
    selector_de_caminos();
};

void Menu::selector_de_caminos(){
    int eleccion;
    bool esta_activo = true;

    instrucciones_menu();
    cout << "_ ";
    cin >> eleccion;
    while(esta_activo){
        switch(eleccion){
            case 1:
                lista_vistas.listar();
                break;
            case 2:
                lista_no_vistas.listar();
                break;
            case 3:
                peliculas_recomendadas.mostrar_recomendadas();
                break;
            case 5:
                esta_activo = false;
                limpiar_pantalla();
                cout << "FIN DE PROGRAMA";
                break;
            case 0:
                instrucciones_menu();
                break;
            default:
                cout << "TERMINO ingresado, NO reconocido. ";
                cout << "\n\n\n\n";
                break;
    }

    cout << endl;
    cout << "_ ";
    cin >> eleccion;
    }
}

void Menu::instrucciones_menu(){
    cout<< " ----------------------------------MENU---------------------------------- " <<endl;
    cout<< "|                                                                        |" <<endl;
    cout<< "| Ingrese el NUMERO del comando a ejecutar:                              |" <<endl;
    cout<< "|                                                                        |" <<endl;
    cout<< "|   1_VISTAS      Listar las peliculas vistas.                           |" <<endl;
    cout<< "|   2_NO.VISTAS   Listar las peliculas no vistas.                        |" <<endl;
    cout<< "|   3_RECOMENDAR  Listar peliculas recomendadas.                         |" <<endl;
    cout<< "|                                                                        |" <<endl;
    cout<< "|   0_MENU        Muestra esta ventana de texto                          |" <<endl;
    cout<< "|   5_SALIR       Termina el programa.                                   |" <<endl;
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
