#include <iostream>
#include <stdlib.h>
using namespace std;
typedef struct nodo
{
    int valor;
    struct nodo *izquierdo = NULL;
    struct nodo *derecho = NULL;
} nodo;
nodo *CrearNodo(int);
int FindMax(struct nodo *raiz);
void AgregarNodo(nodo **, int);
void Preorden(nodo *);
void errasetree(nodo *&);
void Inorden(nodo *);
void Postorden(nodo *);
void ConPreorden(nodo *);
void ConInorden(nodo *);
void ConPostorden(nodo *);
void EliminarNodo(nodo **, int valor);
bool empty(nodo *);
int main()
{
    int cont = 1;
    nodo *raiz = NULL;
    nodo *final = NULL;
    nodo *it = NULL;
    int OpUser = 0, valor = 0;
    do
    {
        cout << "Ingrese la opcion que de desea\n1. Agregar nodo \n2. Imprimir los datos con recorrido Preorden\n3. Imprimir los datos con recorrido Inorden\n4. Imprimir los datos con recorrido Postorden\n5. Imprimir los datos con recorrido Preorden Convexo\n6. Imprimir los datos con recorrido Inorden Convexo\n7. Imprimir los datos con recorrido Postorden Convexo\n8. Eliminar nodo\n9. Salir" << endl;
        cin >> OpUser;
        switch (OpUser)
        {
        case 1:
            cout << "Ingrese el valor que se asignara al nodo" << endl;
            cin >> valor;
            AgregarNodo(&raiz, valor);
            break;
        case 2:
            Preorden(raiz);
            cout << "\n";
            break;
        case 3:
            Inorden(raiz);
            cout << "\n";
            break;
        case 4:
            Postorden(raiz);
            cout << "\n";
            break;
        case 5:
            ConPreorden(raiz);
            cout << "\n";
            break;
        case 6:
            ConInorden(raiz);
            cout << "\n";
            break;
        case 7:
            ConPostorden(raiz);
            cout << "\n";
            break;
        case 8:
            if (empty(raiz))
                cout << "\nNo hay datos en el arbol\n";
            else
            {
                cin >> valor;
                EliminarNodo(&raiz, valor);
            }
            break;
        case 9:
            cout << "arrivederci" << endl;
            errasetree(raiz);
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }
    } while (OpUser != 9);
    return 0;
}
nodo *CrearNodo(int valor)
{
    nodo *nuevo = new (nodo);
    nuevo->izquierdo = NULL;
    nuevo->derecho = NULL;
    nuevo->valor = valor;
    return nuevo;
}
void AgregarNodo(nodo **raiz, int valor)
{
    if (*raiz == NULL)
    {
        nodo *nuevo = CrearNodo(valor);
        *raiz = nuevo;
    }
    else
    {
        int r = (*raiz)->valor;
        if (r == valor)
        {
            cout << "\nValor existente\n";
        }
        else if (valor < r)
            AgregarNodo(&(*raiz)->izquierdo, valor);
        else
            AgregarNodo(&(*raiz)->derecho, valor);
    }
}
//
void Preorden(nodo *raiz)
{   //verifica que no este vacio
    if (raiz != NULL)
    {//recorido de forma recursiva, se puede visualizar con el uso de una pila 
        cout << raiz->valor << " ";
        Preorden(raiz->izquierdo);
        Preorden(raiz->derecho);
    }
}
void Inorden(nodo *raiz)
{
    if (raiz != NULL)
    {
        Inorden(raiz->izquierdo);
        cout << raiz->valor << " ";
        Inorden(raiz->derecho);
    }
}
void Postorden(nodo *raiz)
{
    if (raiz != NULL)
    {
        Postorden(raiz->izquierdo);
        Postorden(raiz->derecho);
        cout << raiz->valor << " ";
    }
}
// todos los que dicen con es de forma convexa
void ConPreorden(nodo *raiz)
{
    if (raiz != NULL)
    {
        cout << raiz->valor << " ";
        ConPreorden(raiz->derecho);
        ConPreorden(raiz->izquierdo);
    }
}
void ConInorden(nodo *raiz)
{
    if (raiz != NULL)
    {
        ConInorden(raiz->derecho);
        cout << raiz->valor << " ";
        ConInorden(raiz->izquierdo);
    }
}
void ConPostorden(nodo *raiz)
{
    if (raiz != NULL)
    {
        ConPostorden(raiz->derecho);
        ConPostorden(raiz->izquierdo);
        cout << raiz->valor << " ";
    }
}
//Deleting a node from the tree,using recursion to remove the node according to one of the given case
void EliminarNodo(nodo **raiz, int valor)
{
    if (valor > (*raiz)->valor)
        EliminarNodo(&(*raiz)->derecho, valor);
    if (valor < (*raiz)->valor)
        EliminarNodo(&(*raiz)->izquierdo, valor);
    if (valor == (*raiz)->valor)
    {   //caso 1 nodo hoja
        if ((*raiz)->derecho == NULL && (*raiz)->izquierdo == NULL)
        {
            delete (*raiz);
            (*raiz) = NULL;
        }
        else if (((*raiz)->derecho == NULL || (*raiz)->izquierdo == NULL))//caso 2 nodo padre de 1 hijo
        {
            nodo *aux;
            if ((*raiz)->derecho == NULL)
            {
                aux = (*raiz);
                (*raiz) = (*raiz)->izquierdo;
                delete aux;
            }
            else if ((*raiz)->izquierdo == NULL)
            {
                aux = (*raiz);
                (*raiz) = (*raiz)->derecho;
                delete aux;
            }
        }
        else if ((*raiz)->derecho != NULL && (*raiz)->izquierdo != NULL)//caso 3 padre de 2 hijos
        {
            int temp = FindMax((*raiz)->izquierdo);
            EliminarNodo(raiz, temp);
            (*raiz)->valor = temp;
        }
    }
}
bool empty(nodo *raiz)
{
    int cont = 0;
    nodo *it = raiz;
    if (raiz != NULL)
    {
        return false;
    }
    else
        return true;
}
void errasetree(struct nodo *&root)
{
    if (root == NULL)
        return;
    errasetree(root->izquierdo);
    errasetree(root->derecho);
    delete (root);
}
int FindMax(struct nodo *raiz)
{
    int val, izq, derecho, maximo = 0;
    if (raiz != NULL)
    {
        val = raiz->valor;
        izq = FindMax(raiz->izquierdo);
        derecho = FindMax(raiz->derecho);
        if (izq > derecho)
            maximo = izq;
        else
            maximo = derecho;
        if (val > maximo)
            maximo = val;
    }
    return maximo;
}
