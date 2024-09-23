#include <iostream>
#include "../Grafos/Grafo.h"

using namespace std;

int main() {
    Grafo<string> redSocial;

    int opcion;
    string persona, amigo;

    do {
        cout << "\n--- Red Social ---\n";
        cout << "1. Agregar persona\n";
        cout << "2. Agregar amistad\n";
        cout << "3. Buscar persona\n";
        cout << "4. Eliminar persona\n";
        cout << "5. Mostrar red social\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese el nombre de la persona: ";
            cin >> persona;
            try{
                redSocial.agregarNodo(persona);
            }catch(int e){
                cout << "ya existe";
            }

            break;
            case 2:
                cout << "Ingrese el nombre de la persona: ";
            cin >> persona;
            cout << "Ingrese el nombre del amigo: ";
            cin >> amigo;
            redSocial.agregarArista(persona, amigo);
            break;
            case 3:
                cout << "Ingrese el nombre de la persona a buscar: ";
            cin >> persona;
            if (redSocial.buscarNodo(persona)) {
                cout << "La persona " << persona << " está en la red social.\n";
            } else {
                cout << "Persona no encontrada.\n";
            }
            break;
            case 4:
                cout << "Ingrese el nombre de la persona a eliminar: ";
            cin >> persona;
            try{
            redSocial.eliminarNodo(persona);
            }catch(int e){
                cout << "no está";
        }
            break;
            case 5:
                cout << "Red social actual:\n";
            redSocial.imprimir();
            break;
            case 6:
                cout << "Saliendo...\n";
            break;
            default:
                cout << "Opcion no válida.\n";
        }
    } while (opcion != 6);

    return 0;
}
