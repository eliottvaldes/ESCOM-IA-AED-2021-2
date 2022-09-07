/**
 * @file equilibrio_de_parentesis.cpp
 * @author valdés luis eliot fabián
 * @brief Programa que contiene el programa de equilibrio de parentesis
 * @version 0.1
 * @date 2022-04-25
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <stack>
using namespace std;

int equilibrarExpresion(stack<char>);

int main()
{
    stack<char> contenedor;
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
            equilibrarExpresion(contenedor);
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

int equilibrarExpresion(stack<char> pila)
{
    string expresionParaEquilibrar;
    char caracter;
    cout << "Digita la expresion" << endl;
    cin >> expresionParaEquilibrar;

    for (int i = 0; i < expresionParaEquilibrar.size(); i++)
    {
        caracter = expresionParaEquilibrar[i];

        if (caracter == '(' | caracter == '[' | caracter == '{')
        {
            pila.push(caracter);
            continue;
        }

        if (caracter == ')')
        {
            if (pila.empty())
            {
                cout << "\nLa expresion no esta balanceada" << endl;
                return (0);
            }
            else if (pila.top() == '(')
            {
                pila.pop();
                continue;
            }
            else
            {
                cout << "\nLa expresion no esta balanceada" << endl;
                continue;
            }
        }
        else if (caracter == ']')
        {
            if (pila.empty())
            {
                cout << "\nLa expresion no esta balanceada" << endl;
                return (0);
            }
            else if (pila.top() == '[')
            {
                pila.pop();
                continue;
            }
            else
            {
                cout << "\nLa expresion no esta balanceada" << endl;
                continue;
            }
        }
        else if (caracter == '}')
        {
            if (pila.empty())
            {
                cout << "\nLa expresion no esta balanceada" << endl;
                return (0);
            }
            else if (pila.top() == '{')
            {
                pila.pop();
                continue;
            }
            else
            {
                cout << "\nLa expresion no esta balanceada" << endl;
                continue;
            }
        }
    }

    if (pila.size() == 0)
    {
        cout << "La expresion esta balanceada adecuadamente" << endl;
    }
    else
    {
        cout << "\nLa expresion no esta balanceada" << endl;
    }
}