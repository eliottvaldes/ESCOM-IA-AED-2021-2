/*
    Monroy Fernandez Jose Luis
    2BV1
    Inteliencia Artificial
*/

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<char> contenedor;
    int opcionUsuario;
    do
    {
        cout << "Elija una opcion" << endl;
        cout << "1 .- Ingresar expresion" << endl;
        cout << "2 .- Salir del programa" << endl;
        cin >> opcionUsuario;
        switch (opcionUsuario)
        {
        case 1:
            break;
        case 2:
            cout << "Saliendo del programa" << endl;
            return(0);
            break;
        default:
            cout << "Elija una opcion valida" << endl;
            break;
        }
    } while (opcionUsuario != 2);
    return(0);
}