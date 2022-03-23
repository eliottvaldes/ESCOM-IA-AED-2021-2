#include <iostream>
#include <stack>

using namespace std;

int imprimirPilaFin(stack<string> pila);

int main()
{
    stack<string> pila;
    int opcionMenu;
    char palabra[20];
    do
    {

        cout << "Que desesa hacer" << endl;
        cout << "1.- Agregar una palabra al inicio" << endl;
        cout << "2.- Agregar una palabra al final" << endl;
        cout << "3.- Agregar una palabra en una posicion N" << endl;
        cout << "4.- Imprimir Inicio a Fin" << endl;
        cout << "5.- Imprimir Fin a inicio" << endl;
        cout << "6.- Eliminar al inicio" << endl;
        cout << "7.- Eliminar al final" << endl;
        cout << "8.- Eliminar una posicion N" << endl;
        cout << "9.- Salir" << endl;
        cin >> opcionMenu;
        switch (opcionMenu)
        {
        case 1:
            break;
        case 2:
            cout << "Ingrese la palabra" << endl;
            cin >> palabra;
            pila.push(palabra);
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            imprimirPilaFin(pila);
            break;
        case 9:
            cout << "Saliendo del programa" << endl;
            exit(0);
        default:
            cout << "Porfavor seleccione una opcion valida" << endl;
            break;
        }
    } while (opcionMenu != 9);
    return 0;
}

int imprimirPilaFin(stack<string> pila)
{
    int numero = 10;
    for (int i = 0; i < numero; i++)
    {
        cout << pila.top() << " ,";
        pila.pop();
    }
    cout << endl;
}