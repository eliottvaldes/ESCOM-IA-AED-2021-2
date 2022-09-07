/**
 * @file equilibrio_de_ecuaciones_lista.cpp
 * @author Valdés Luis Eliot Fabián
 * @brief archivo con programa de l¿equilibrio de ecuaciones implementando listas
 * @version 0.1
 * @date 2022-04-25
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "equilibrio_de_ecuaciones_lista.h"

int equlibrarExpresion();

int main()
{
    int opcionUsuario;
    int opcionDeFin = 2;
    do
    {
        cout << "\n======================================================" << endl;
        cout << "\tDigita la opcion que deseas llevar a cabo" << endl;
        cout << "======================================================" << endl;
        cout << "1 .- Ingresar expresion a equilibrar" << endl;
        cout << "2 .- Salir del programa" << endl;

        cin >> opcionUsuario;

        switch (opcionUsuario)
        {

        case 1:
            equlibrarExpresion();
            break;

        case 2:
            cout << "Saliendo del programa..." << endl;
            exit(0);
            break;

        default:
            cout << "Por favor selecciona una opcion valida" << endl;
            break;
        }

    } while (opcionUsuario != opcionDeFin);

    return (0);
}

int equlibrarExpresion()
{
    Nodo *lista = NULL;
    string expresion;
    char caracter;

    cout << "Digita la expresion: " << endl;
    cin >> expresion;

    for (int i = 0; i < expresion.size(); i++)
    {
        caracter = expresion[i];

        if (caracter == '(' | caracter == '[' | caracter == '{')
        {
            lista_push(&lista, caracter);
            continue;
        }

        if (caracter == ')')
        {
            char pos = lista_top(lista);

            if (lista_empty(lista))
            {
                cout << "La expresion no esta balanceada" << endl;
                return (0);
            }
            else if (pos == '(')
            {
                lista_pop(&lista);
                continue;
            }
            else
            {
                cout << "La expresion no esta balanceada" << endl;
                return (0);
            }
        }
        else if (caracter == ']')
        {
            char pos = lista_top(lista);

            if (lista_empty(lista))
            {
                cout << "La expresion no esta balanceada" << endl;
                return (0);
            }
            else if (pos == '[')
            {
                lista_pop(&lista);
                continue;
            }
            else
            {
                cout << "La expresion no esta balanceada" << endl;
                return (0);
            }
        }
        else if (caracter == '}')
        {
            char pos = lista_top(lista);

            if (lista_empty(lista))
            {
                cout << "La expresion no esta balanceada" << endl;
                return (0);
            }
            else if (pos == '{')
            {
                lista_pop(&lista);
                continue;
            }
            else
            {
                cout << "La expresion no esta balanceada" << endl;
                return (0);
            }
        }
    }

    int tam = lista_size(lista);

    if (tam > 0)
    {
        cout << "La expresion esta balanceada adecuadamente" << endl;
    }
    else
    {
        cout << "La expresion no esta balanceada" << endl;
    }
}