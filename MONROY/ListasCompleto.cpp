/*
    Monroy Fernandez Jose Luis
    2BV1
    Inteliencia Artificial
*/

#include <iostream>

using namespace std;

struct mochila
{
    int nobolsas;
    string marca;
    string material;
    float precio;
    mochila *next;
};

ostream& operator<<(ostream &, mochila);
void agregarInicio();
void agregarFin();
void agregarCustom();
void imprimirInicio();
void imprimirFin();
void eliminarInicio();
void eliminarFin();
void eliminarCustom();

int main()
{
    mochila *inicio = NULL;
    int opcionMenu;
    do
    {

        cout << "Que desesa hacer" << endl;
        cout << "1.- Agregar una mochila al inicio" << endl;
        cout << "2.- Agregar una mochila al final" << endl;
        cout << "3.- Agregar una mochila en una posicion N" << endl;
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
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
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

ostream& operator<<(ostream &output, mochila estructura)
{
    output << "\n Marca: " << estructura.marca;
    output << "\n Material: " << estructura.material;
    output << "\n Numero de bolsas: " << estructura.nobolsas;
    output << "\n Precio: " << estructura.precio;
    return output;
}