//
// Created by Matias on 23-Sep-24.
//


#include <iostream>
#include <string>
#include "Grafos/Grafo.h" // Asegúrate de incluir tu archivo de definición de la clase Grafo

using namespace std;

int main() {
    Grafo<string> sistemaRutas;
    int opcion;
    string estacion1, estacion2;

    do {
        cout << "1. Agregar estacion\n";
        cout << "2. Agregar ruta\n";
        cout << "3. Eliminar estacion\n";
        cout << "4. Eliminar ruta\n";
        cout << "5. Consultar conectividad\n";
        cout << "6. Verificar existencia de estacion\n";
        cout << "7. Imprimir mapa de rutas\n";
        cout << "0. Salir\n";
        cout << "Elija una opcion: ";

        cin >> opcion;
        cin.clear(); // Limpia el estado de error
        cin.ignore(); // Ignora el resto de la línea

        switch (opcion) {
            case 1:
                cout << "Ingrese el nombre de la estacion: ";

                getline(cin, estacion1);

                sistemaRutas.agregarNodo(estacion1);
                break;

            case 2:
                cout << "Ingrese la estacion de origen: ";
                getline(cin, estacion1);
                cout << "Ingrese la estacion de destino: ";
                getline(cin, estacion2);
                sistemaRutas.agregarArista(estacion1, estacion2);
                break;

            case 3:
                cout << "Ingrese el nombre de la estacion a eliminar: ";
                getline(cin, estacion1);
                sistemaRutas.eliminarNodo(estacion1);
                break;

            case 4:
                cout << "Ingrese la estacion de origen: ";
                getline(cin, estacion1);
                cout << "Ingrese la estacion de destino: ";
                getline(cin, estacion2);
                sistemaRutas.eliminarArista(estacion1, estacion2);
                break;

            case 5:
                cout << "Ingrese la estacion de origen: ";
                getline(cin, estacion1);
                cout << "Ingrese la estacion de destino: ";
                getline(cin, estacion2);
                if (sistemaRutas.estanConectados(estacion1, estacion2)) {
                    cout << "Las estaciones estan conectadas.\n";
                } else {
                    cout << "Las estaciones NO estan conectadas.\n";
                }
                break;

            case 6:
                cout << "Ingrese el nombre de la estación a verificar: ";
                getline(cin, estacion1);
                if (sistemaRutas.buscarNodo(estacion1)) {
                    cout << "La estacion existe.\n";
                } else {
                    cout << "La estacion NO existe.\n";
                }
                break;

            case 7:
                cout << "Mapa de rutas:\n";
                sistemaRutas.imprimir();
                break;

            case 0:
                cout << "Saliendo del sistema.\n";
                break;

            default:
                cout << "Opcion no valida, intente de nuevo.\n";
                break;
        }
    } while (opcion != 0);

    return 0;
}
