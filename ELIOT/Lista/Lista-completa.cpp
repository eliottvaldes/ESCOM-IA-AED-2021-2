/**
 * @file Lista-completa.cpp
 * @author Valdés Luis Eliot Fabián
 * @brief archivo que contiene el programa de Lsitas completo
 * @version 0.1
 * @date 2022-04-08
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <stdlib.h>

using namespace std;

// estructura nodo
typedef struct nodo
{
    string marca;
    string modelo;
    float precio;
    int anio_de_fabricacion;

    struct nodo *siguiente = NULL;

} nodo;

// Prototipos
void agregarFinal(nodo **);
void agregarInicio(nodo **);
void agregarPosN(nodo **);
void mostrarInicio(nodo *);
void eliminarInicio(nodo **);
void eliminarFinal(nodo **);
void eliminarPosN(nodo **);
ostream &operator<<(ostream &, nodo);
istream &operator>>(istream &, nodo &);

int main()
{
    nodo *inicio = NULL;
    int seleccionUsuario;
    int opcion_salir = 8;
    do
    {
        cout << "\n\n======================================================" << endl;
        cout << "\tDigita la opcion que deseas llevar a cabo" << endl;
        cout << "======================================================" << endl;
        cout << "1.- Agregar un elemento al inicio" << endl;
        cout << "2.- Agregar un elemento al final" << endl;
        cout << "3.- Agregar una elemento en una posicion especifica N" << endl;
        cout << "4.- Imprimir de lista de elementos" << endl;
        cout << "5.- Eliminar inicio" << endl;
        cout << "6.- Eliminar final" << endl;
        cout << "7.- Eliminar elemento en una posicion especifica N" << endl;
        cout << "8.- Salir" << endl;
        cin >> seleccionUsuario;
        cout << "\n"
             << endl;

        switch (seleccionUsuario)
        {
        case 1:
            agregarInicio(&inicio);
            break;

        case 2:
            agregarFinal(&inicio);
            break;

        case 3:
            agregarPosN(&inicio);
            break;

        case 4:
            mostrarInicio(inicio);
            break;

        case 5:
            eliminarInicio(&inicio);
            break;

        case 6:
            eliminarFinal(&inicio);
            break;

        case 7:
            eliminarPosN(&inicio);
            break;

        case 8:
            cout << "\n\nSaliendo del programa..." << endl;
            exit(0);

        default:
            cout << "Opcion no valida" << endl;
            break;
        }
    } while (seleccionUsuario != opcion_salir);

    return 0;
}

void agregarInicio(nodo **inicio)
{
    cout << "\t\tDigita los datos correspondientes a un nuevo Telefono " << endl;
    if (*inicio == NULL)
    {
        nodo *nuevo = new (nodo);
        nuevo->siguiente = NULL;

        cout << "\nMarca: " << endl;
        cin >> nuevo->marca;
        cout << "\nModelo: " << endl;
        cin >> nuevo->modelo;
        cout << "\nPrecio: " << endl;
        cin >> nuevo->precio;
        cout << "\nAnio de fabricacion: " << endl;
        cin >> nuevo->anio_de_fabricacion;

        *inicio = nuevo;
    }
    else
    {
        nodo *nuevo = new (nodo);
        nuevo->siguiente = *inicio;

        cout << "\nMarca: " << endl;
        cin >> nuevo->marca;
        cout << "\nModelo: " << endl;
        cin >> nuevo->modelo;
        cout << "\nPrecio: " << endl;
        cin >> nuevo->precio;
        cout << "\nAnio de fabricacion: " << endl;
        cin >> nuevo->anio_de_fabricacion;

        *inicio = nuevo;
    }
}

void agregarFinal(nodo **inicio)
{
    cout << "\t\tDigita los datos correspondientes a un nuevo Telefono " << endl;
    if (*inicio == NULL)
    {
        nodo *nuevo = new (nodo);
        nuevo->siguiente = NULL;

        cout << "\nMarca: " << endl;
        cin >> nuevo->marca;
        cout << "\nModelo: " << endl;
        cin >> nuevo->modelo;
        cout << "\nPrecio: " << endl;
        cin >> nuevo->precio;
        cout << "\nAnio de fabricacion: " << endl;
        cin >> nuevo->anio_de_fabricacion;

        *inicio = nuevo;
    }
    else
    {
        nodo *nuevo = new (nodo);
        nodo *iterador1 = *inicio;
        nuevo->siguiente = NULL;

        cout << "\nMarca: " << endl;
        cin >> nuevo->marca;
        cout << "\nModelo: " << endl;
        cin >> nuevo->modelo;
        cout << "\nPrecio: " << endl;
        cin >> nuevo->precio;
        cout << "\nAnio de fabricacion: " << endl;
        cin >> nuevo->anio_de_fabricacion;

        while (iterador1->siguiente != NULL)
        {
            iterador1 = iterador1->siguiente;
        }
        iterador1->siguiente = nuevo;
    }
}

void agregarPosN(nodo **inicio)
{
    nodo *nuevo = new (nodo);
    nodo *iterador1 = *inicio;
    int posN = 0, contador = 1;
    nuevo->siguiente = NULL;
    cout << "\nDigita la posicion donde quieres insertar un nuevo elemento: " << endl;
    cin >> posN;
    cout << "\n\tDigita los datos correspondientes a un nuevo Telefono " << endl;
    if (posN == 1)
        agregarInicio(inicio);
    else
    {
        cout << "\nMarca: " << endl;
        cin >> nuevo->marca;
        cout << "\nModelo: " << endl;
        cin >> nuevo->modelo;
        cout << "\nPrecio: " << endl;
        cin >> nuevo->precio;
        cout << "\nAnio de fabricacion: " << endl;
        cin >> nuevo->anio_de_fabricacion;

        while (contador < posN - 1)
        {
            iterador1 = iterador1->siguiente;
            contador++;
        }
        nuevo->siguiente = iterador1->siguiente;
        iterador1->siguiente = nuevo;
    }
}

void mostrarInicio(nodo *inicio)
{
    int cont = 0;
    nodo *iterador1;
    iterador1 = inicio;
    nodo *vacio;
    if (inicio != NULL)
    {
        vacio = inicio;
        while (vacio->siguiente != NULL)
        {
            vacio = vacio->siguiente;
            cont++;
        }
        while (iterador1->siguiente != NULL)
        {
            cout << "\n\n---------------------------------------------" << endl;
            cout << "\nMarca => " << iterador1->modelo << endl;
            cout << "\nModelo => " << iterador1->marca << endl;
            cout << "\nPrecio => " << iterador1->anio_de_fabricacion << endl;
            cout << "\nAnio de fabricacion => " << iterador1->anio_de_fabricacion << endl;
            cout << "\n\n---------------------------------------------" << endl;

            iterador1 = iterador1->siguiente;
        }
        cout << "\n\n---------------------------------------------" << endl;
        cout << "Marca => " << iterador1->modelo << endl;
        cout << "\nModelo => " << iterador1->marca << endl;
        cout << "\nPrecio => " << iterador1->anio_de_fabricacion << endl;
        cout << "\nAnio de fabricacion => " << iterador1->anio_de_fabricacion << endl;
        cout << "---------------------------------------------" << endl;
    }
}

void eliminarInicio(nodo **inicio)
{
    nodo *iterador = *inicio;
    *inicio = (*inicio)->siguiente;
    delete iterador;
}

void eliminarFinal(nodo **inicio)
{
    nodo *iterador1 = *inicio;
    nodo *iterador2 = *inicio;
    int contador = 0;
    while (iterador1->siguiente != NULL)
    {
        iterador1 = iterador1->siguiente;
        contador++;
    }
    for (size_t i = 0; i < contador - 1; i++)
    {
        iterador2 = iterador2->siguiente;
    }
    delete iterador1;
    iterador2->siguiente = NULL;
}

void eliminarPosN(nodo **inicio)
{
    int posN = 0, contador = 1;
    nodo *iterador1 = *inicio;
    nodo *iterador2 = *inicio;
    cout << "\nDigita la posicion del elemento que deseas eliminar: " << endl;
    cin >> posN;
    if (posN == 1)
    {
        eliminarInicio(inicio);
    }
    else
    {
        while (contador < posN - 1)
        {
            iterador1 = iterador1->siguiente;
            contador++;
        }
        iterador2 = iterador1->siguiente;
        iterador1->siguiente = iterador1->siguiente->siguiente;

        if (iterador1 == NULL)
        {
            eliminarFinal(inicio);
        }
        else
        {
            delete iterador2;
        }
    }
}

ostream &operator<<(ostream &os, nodo est)
{
    os << "\nMarca =>" << est.marca;
    os << "\nModelo =>" << est.modelo;
    os << "\nPrecio =>" << est.precio;
    os << "\nAnio de fabricacion =>" << est.anio_de_fabricacion;
    return os;
}

istream &operator>>(istream &in, nodo &est)
{
    cin >> est.marca;
    cin >> est.modelo;
    cin >> est.precio;
    cin >> est.anio_de_fabricacion;
    return in;
}