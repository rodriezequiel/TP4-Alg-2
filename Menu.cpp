#include "Menu.h"

#include <iostream>
#include <string>

#include "Archivo.h"
#include "Listas.h"
#include "Pelicula.h"
#include "Recomendaciones.h"

using namespace std;

Menu::Menu(){

    archivo.abrir_archivos(lista_no_vistas, ARCHIVO_NO_VISTAS);
    archivo.abrir_archivos(lista_vistas, ARCHIVO_VISTAS);

    if(archivo.obtener_abrio_vistas() == false){

    	peliculas_recomendadas.recomendar_por_puntaje(lista_no_vistas);
    }
    else if(archivo.obtener_abrio_vistas() == true && archivo.obtener_abrio_no() == true) {

    	peliculas_recomendadas.recomendar_peliculas(lista_vistas, lista_no_vistas);
    }
};

void Menu::inicio(){

	try {

	    archivo.verificar_ex();
	    selector_de_caminos();
	}
	catch (Excepcion_falta_no_vistas &ex){

		cout << ex.what() << endl;
	}
};

void Menu::selector_de_caminos(){

	int eleccion;
    bool esta_activo = true;

    while(esta_activo){

    	limpiar_pantalla();
    	instrucciones_menu();

    	cout << "_ ";
    	cin >> eleccion;

    	limpiar_pantalla();

    	switch(eleccion){

    		case 1:
    			cout << "Lista de peliculas vistas:\n" << endl;
                lista_vistas.listar();
                break;

            case 2:
            	cout << "Lista de peliculas no vistas:\n" << endl;
                lista_no_vistas.listar();
                break;

            case 3:
                peliculas_recomendadas.mostrar_recomendadas();
                break;

            case 0:
                esta_activo = false;
                limpiar_pantalla();
                cout << "FIN DE PROGRAMA\n\n";
                break;

            default:
                cout << "TERMINO ingresado, NO reconocido.\n\n";
                break;
    	}

    	if(esta_activo) continuar();
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
    cout<< "|   0_SALIR       Termina el programa.                                   |" <<endl;
    cout<< " ------------------------------------------------------------------------ " <<endl;
    cout<<endl;
}

void Menu::continuar(){

	string entrada;

	cout << "Para volver al menu ingrese cualquier letra y presione ENTER." << endl;

	cin >> entrada;
}

void Menu::limpiar_pantalla(){

	cout << string(50, '\n');

    #ifdef linux
        system("clear");
    #else
        system ("cls");
    #endif
}
