/**
 * @file Pila.cpp
 * @author Valdes Luis Eliot Fabián
 * @brief archivo que contiene operaciones basicas con pilas
 * @version 0.1
 * @date 2022-03-25
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <stack>

using namespace std;

stack<string> agregarPalabraAlFinal(stack<string>, stack<string>, int, string);
stack<string> agregarPalabraPosicion(stack<string>, stack<string>, int, string);
stack<string> eliminarElementoFinal(stack<string>, stack<string>, int);
stack<string> eliminarElementoPosicion(stack<string>, stack<string>, int);
int mostrarPilaFinal(stack<string>, int);
int mostrarPilaInicio(stack<string>, stack<string>, int);

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

stack<string> agregarPalabraAlFinal(stack<string> pila, stack<string> aux, int size, string tmp)
{
    for (int i = 0; i < size; i++)
    {
        aux.push(pila.top());
        pila.pop();
    }
    cout << "Digita una palabra: " << endl;
    cin >> tmp;
    pila.push(tmp);
    for (int i = 0; i < size; i++)
    {
        pila.push(aux.top());
        aux.pop();
    }
    return pila;
}

stack<string> agregarPalabraPosicion(stack<string> pila, stack<string> aux, int longitudPIla, string tmp)
{
    cout << "Posicion para comenzar a escribir la palabra: " << endl;
    int pos;
    cin >> pos;
    if (pos > longitudPIla)
    {
        cout << "Elige una posicion valida dentro del arreglo de [" << longitudPIla << "] elementos" << endl;
        return pila;
    }
    cout << "Digite la palabra" << endl;
    cin >> tmp;
    for (int i = 0; i < pos; i++)
    {
        aux.push(pila.top());
        pila.pop();
    }
    pila.push(tmp);
    for (int i = 0; i < pos; i++)
    {
        pila.push(aux.top());
        aux.pop();
    }
    return pila;
}

int mostrarPilaInicio(stack<string> pila, stack<string> aux, int longitudPIla)
{
    for (int i = 0; i < longitudPIla; i++)
    {
        aux.push(pila.top());
        pila.pop();
    }
    for (int i = 0; i < longitudPIla; i++)
    {
        cout << aux.top() << ", ";
        aux.pop();
    }
    return 0;
}

int mostrarPilaFinal(stack<string> pila, int longitudPIla)
{
    for (int i = 0; i < longitudPIla; i++)
    {
        cout << pila.top() << " ,";
        pila.pop();
    }
    cout << endl;
    return 0;
}

stack<string> eliminarElementoFinal(stack<string> pila, stack<string> aux, int longitudPIla)
{
    for (int i = 0; i < longitudPIla - 1; i++)
    {
        aux.push(pila.top());
        pila.pop();
    }
    cout << "Se ha eliminado de la lsita la palabra: " << pila.top() << endl;
    pila.pop();
    for (int i = 0; i < longitudPIla - 1; i++)
    {
        pila.push(aux.top());
        aux.pop();
    }
    return pila;
}

stack<string> eliminarElementoPosicion(stack<string> pila, stack<string> aux, int longitudPIla)
{
    int pos;
    cout << "Digita la posicion de la palabra a eliminar: ";
    cin >> pos;
    if (pos > longitudPIla)
    {
        cout << "La posicion a eliminar no es valida" << endl;
        return pila;
    }
    for (int i = 0; i < pos - 1; i++)
    {
        aux.push(pila.top());
        pila.pop();
    }
    cout << "Se ha eliminado de la lista la palabra ->" << pila.top() << endl;
    pila.pop();
    for (int i = 0; i < pos - 1; i++)
    {
        pila.push(aux.top());
        aux.pop();
    }
    return pila;
}