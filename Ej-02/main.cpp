#include <iostream>
#include "../Grafos/Grafo.h"

using namespace std;

int main() {
    Grafo<string> comision;

    int opcion;
    string miembro, colaborador;

    do {
        cout << "\n--- Comision de Colegio/Universidad ---\n";
        cout << "1. Agregar miembro\n";
        cout << "2. Establecer colaboracion\n";
        cout << "3. Buscar miembro\n";
        cout << "4. Eliminar miembro\n";
        cout << "5. Mostrar estructura de la comision\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese el nombre del miembro: ";
            cin >> miembro;
            comision.agregarNodo(miembro);
            break;
            case 2:
                cout << "Ingrese el nombre del miembro: ";
            cin >> miembro;
            cout << "Ingrese el nombre del colaborador: ";
            cin >> colaborador;
            comision.agregarArista(miembro, colaborador);
            break;
            case 3:
                cout << "Ingrese el nombre del miembro a buscar: ";
            cin >> miembro;
            if (comision.buscarNodo(miembro)) {
                cout << "El miembro " << miembro << " esta en la comision.\n";
            } else {
                cout << "Miembro no encontrado.\n";
            }
            break;
            case 4:
                cout << "Ingrese el nombre del miembro a eliminar: ";
            cin >> miembro;
            comision.eliminarNodo(miembro);
            break;
            case 5:
                cout << "Estructura de la comision:\n";
            comision.imprimir();
            break;
            case 6:
                cout << "Saliendo...\n";
            break;
            default:
                cout << "Opción no valida.\n";
        }
    } while (opcion != 6);

    return 0;
}
