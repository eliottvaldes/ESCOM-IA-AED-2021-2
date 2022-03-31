/**
 * @file cola.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <iostream>
#include <stack>

using namespace std;



int main()
{
    stack<string> pila;
    stack<string> aux_str;    
    int opcionMenu;
    int opcionSalir = 9;
    int longitudPIla;
    string palabra;
    do
    {

        cout << "Digita la opcion que desea realizar" << endl;
        cout << "1. Agregar una palabra al inicio" << endl;
        cout << "2. Agregar una palabra al final" << endl;
        cout << "3. Agregar una palabra en una posicion N" << endl;
        cout << "4. Imprimir Inicio a Fin" << endl;
        cout << "5. Imprimir Fin a inicio" << endl;
        cout << "6. Eliminar al inicio" << endl;
        cout << "7. Eliminar al final" << endl;
        cout << "8. Eliminar una posicion N" << endl;
        cout << "9. Salir" << endl;
        cin >> opcionMenu;
        switch (opcionMenu)
        {
        case 1:
            cout << "Digite una palabra: " << endl;
            cin >> palabra;
            pila.push(palabra);
            break;

        case 2:
            longitudPIla = pila.size();
            pila = agregarPalabraAlFinal(pila, aux_str, longitudPIla, palabra);
            break;

        case 3:
            longitudPIla = pila.size();
            pila = agregarPalabraPosicion(pila, aux_str, longitudPIla, palabra);
            break;

        case 4:
            longitudPIla = pila.size();
            mostrarPilaInicio(pila, aux_str, longitudPIla);
            break;

        case 5:
            longitudPIla = pila.size();
            mostrarPilaFinal(pila, longitudPIla);
            break;

        case 6:
            pila.pop();
            break;

        case 7:
            longitudPIla = pila.size();
            pila = eliminarElementoFinal(pila, aux_str, longitudPIla);
            break;

        case 8:
            longitudPIla = pila.size();
            pila = eliminarElementoPosicion(pila, aux_str, longitudPIla);
            break;

        case 9:
            cout << "Saliendo del programa..." << endl;
            exit(0);

        default:
            cout << "Selecciona una opcion valida ---" << endl;
            break;
        }
    } while (opcionMenu != opcionSalir);

    return 0;
}
