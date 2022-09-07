/**
 * @file lista_doble.cpp
 * @author valdes luis eliot fabian
 * @brief programa que contiene lista doble
 * @version 0.1
 * @date 2022-04-23
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>

using namespace std;

struct Nodo
{
    int talla;
    string marca;
    string material;
    float precio;
    Nodo *siguiente;
    Nodo *anterior;
};

ostream &operator<<(ostream &, Nodo);
void solicitarElemento(Nodo *);
void agregarInicio(Nodo **, Nodo **);
void agregarFin(Nodo **, Nodo **);
int cantidadPosicionesDisponibles(Nodo *);
void agregarPosX(Nodo **, Nodo **, int);
void imprimirInicio(Nodo *);
void imprimirFin(Nodo *);
void eliminarInicio(Nodo **, Nodo **);
void eliminarFin(Nodo **, Nodo **);
void eliminarCustom(Nodo **, Nodo **, int);

int main()
{
    Nodo *inicio = NULL;
    Nodo *final = NULL;
    int totalPosi;
    int opcionMenu;
    int opcionsalir = 9;
    do
    {

        cout << "\n======================================================" << endl;
        cout << "\tDigita la opcion que deseas llevar a cabo" << endl;
        cout << "======================================================" << endl;
        cout << "1.- Agregar una playera al inicio" << endl;
        cout << "2.- Agregar una playera al final" << endl;
        cout << "3.- Agregar una playera en una posicion X" << endl;
        cout << "4.- Imprimir lista de inicio a fin" << endl;
        cout << "5.- Imprimir lista de fin a inicio" << endl;
        cout << "6.- Eliminar al inicio" << endl;
        cout << "7.- Eliminar al final" << endl;
        cout << "8.- Eliminar una posicion X" << endl;
        cout << "9.- Salir" << endl;
        cout << "---------------------------------------------------------" << endl;
        cin >> opcionMenu;
        switch (opcionMenu)
        {
        case 1:
            agregarInicio(&inicio, &final);
            break;
        case 2:
            agregarFin(&inicio, &final);
            break;
        case 3:
            totalPosi = cantidadPosicionesDisponibles(inicio);
            agregarPosX(&inicio, &final, totalPosi);
            break;
        case 4:
            imprimirInicio(inicio);
            break;
        case 5:
            imprimirFin(final);
            break;
        case 6:
            eliminarInicio(&inicio, &final);
            break;
        case 7:
            eliminarFin(&inicio, &final);
            break;
        case 8:
            totalPosi = cantidadPosicionesDisponibles(inicio);
            eliminarCustom(&inicio, &final, totalPosi);
            break;
        case 9:
            cout << "Saliendo del programa" << endl;
            exit(0);
        default:
            cout << "Por favor selecciona una opcion valida" << endl;
            break;
        }
    } while (opcionMenu != opcionsalir);
    return 0;
}

void solicitarElemento(Nodo *temp)
{
    cout << "Digita la talla" << endl;
    cin >> temp->talla;
    cout << "Ingrese la marca" << endl;
    cin >> temp->marca;
    cout << "Ingrese el material de la playera" << endl;
    cin >> temp->material;
    cout << "Ingrese el precio de la playera" << endl;
    cin >> temp->precio;
    temp->siguiente = NULL;
    temp->anterior = NULL;
}

void agregarInicio(Nodo **inicio, Nodo **fin)
{
    Nodo *nuevo = new Nodo;
    solicitarElemento(nuevo);
    if (*inicio == NULL)
    {
        *inicio = nuevo;
        *fin = nuevo;
        cout << "\nElemento se ha registrado" << endl;
    }
    else
    {
        Nodo *iterador = *fin;
        while (iterador->anterior != NULL)
        {
            iterador = iterador->anterior;
        }
        iterador->anterior = nuevo;
        nuevo->siguiente = *inicio;
        *inicio = nuevo;
        cout << "\nElemento se ha registrado" << endl;
    }
}

void agregarFin(Nodo **inicio, Nodo **fin)
{
    Nodo *nuevo = new Nodo;
    solicitarElemento(nuevo);
    if (*fin == NULL)
    {
        *inicio = nuevo;
        *fin = nuevo;
        cout << "\nElemento se ha registrado" << endl;
    }
    else
    {
        Nodo *iterador = *inicio;
        while (iterador->siguiente != NULL)
        {
            iterador = iterador->siguiente;
        }
        iterador->siguiente = nuevo;
        nuevo->anterior = *fin;
        *fin = nuevo;
        cout << "\nElemento se ha registrado" << endl;
    }
}

int cantidadPosicionesDisponibles(Nodo *inicio)
{
    int posiciones = 1;
    if (inicio == NULL)
    {
        posiciones--;
    }
    else
    {
        Nodo *iterador = inicio;
        while (iterador != NULL)
        {
            iterador = iterador->siguiente;
            posiciones++;
        }
    }
    return posiciones;
}

void agregarPosX(Nodo **inicio, Nodo **fin, int posiciones)
{
    Nodo *nuevo = new Nodo;
    if (posiciones == 0)
    {
        cout << "lista vacia" << endl;
    }
    else
    {
        solicitarElemento(nuevo);
        int contador = 1, position, itera2pos;
        cout << "\nEn que posicion deseas agregar el elemento";
        cout << " hay " << posiciones << " disponibles" << endl;
        cin >> position;
        if (position > posiciones)
        {
            cout << "\nLa posicion excede los nodos ya creados" << endl;
        }
        else
        {
            Nodo *iterador = *inicio;
            Nodo *itera2 = *fin;
            itera2pos = posiciones - position;
            while (contador < position - 1)
            {
                iterador = iterador->siguiente;
                contador++;
            }
            contador = 1;
            while (contador < itera2pos - 1)
            {
                itera2 = itera2->siguiente;
                contador++;
            }

            nuevo->siguiente = itera2;
            itera2->anterior = nuevo;
            nuevo->anterior = iterador;
            iterador->siguiente = nuevo;
            cout << "\nElemento se ha registrado" << endl;
        }
    }
}

void imprimirInicio(Nodo *inicio)
{
    if (inicio == NULL)
    {
        cout << "\nLa inicio esta vacia" << endl;
    }
    else
    {
        Nodo *iterador = inicio;
        while (iterador != NULL)
        {
            cout << (*iterador);
            iterador = iterador->siguiente;
        }
    }
}

void imprimirFin(Nodo *fin)
{
    if (fin == NULL)
    {
        cout << "\nLa lista esta vacia" << endl;
    }
    else
    {
        Nodo *iterador = fin;
        while (iterador != NULL)
        {
            cout << (*iterador);
            iterador = iterador->anterior;
        }
    }
}

void eliminarInicio(Nodo **inicio, Nodo **fin)
{
    Nodo *aux = *inicio;
    *inicio = (*inicio)->siguiente;
    delete aux;
    Nodo *itera1 = (*fin)->anterior;
    Nodo *itera2;
    while (itera1->anterior != NULL)
    {
        itera2 = itera1;
        itera1 = itera1->anterior;
    }
    itera2->anterior = NULL;
    delete itera1;
    cout << "\nElemento eliminado" << endl;
}

void eliminarFin(Nodo **inicio, Nodo **fin)
{
    Nodo *aux = *fin;
    *fin = (*fin)->anterior;
    delete aux;
    Nodo *itera1 = (*inicio)->siguiente;
    Nodo *itera2;
    while (itera1->siguiente != NULL)
    {
        itera2 = itera1;
        itera1 = itera1->siguiente;
    }
    itera2->siguiente = NULL;
    delete itera1;
    cout << "\nElemento eliminado" << endl;
}

void eliminarCustom(Nodo **inicio, Nodo **fin, int posiciones)
{
    if (posiciones == 0)
    {
        cout << "Lista vacia" << endl;
    }
    else
    {
        int contador = 1, position;
        cout << "\nDigita el elemento de la lista quieres eliminar";
        cout << " hay " << posiciones - 1 << " disponibles" << endl;
        cin >> position;
        if (position > posiciones)
        {
            cout << "\nEl elemento no existe" << endl;
        }
        else
        {
            Nodo *itera1 = *inicio;
            Nodo *itera2 = *inicio;
            Nodo *itera3 = *fin;
            Nodo *itera4 = *fin;
            int itera3pos = posiciones - position;
            while (contador < position - 1)
            {
                itera1 = itera1->siguiente;
                contador++;
            }
            itera2 = itera1->siguiente;
            itera1->siguiente = itera1->siguiente->siguiente;
            delete itera2;

            contador = 1;
            while (contador < itera3pos - 1)
            {
                itera2 = itera3->anterior;
                contador++;
            }
            itera4 = itera3->anterior;
            itera3->anterior = itera3->anterior->anterior;
            delete itera4;
        }
    }
}

ostream &operator<<(ostream &output, Nodo estructura)
{
    output << "\n Marca: " << estructura.marca;
    output << "\n Material: " << estructura.material;
    output << "\n Talla: " << estructura.talla;
    output << "\n Precio: " << estructura.precio << endl;
    return output;
}