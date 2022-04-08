/*
======================================
 ▪* Montero Barraza Alvaro David*
    *2BV1 Ingenieria en IA ▪*  
=======================================
 */
#include<iostream>
#include<stdlib.h>
using namespace std;




typedef struct Nodo{
        int dato;
        Nodo *sig;

}Nodo;

//Prototipos de funciones
bool ins_elem(Nodo **list,int dato);
bool elim_elem(Nodo **list,int tam);
int size_que(Nodo *list);
bool most_que(Nodo *list);

int main(){
    int opt,tam=0,dato;
    Nodo *inicio;
    inicio=new Nodo();
    inicio->sig=NULL;
    do
    {   
        cout<<"1.-Insertar elemento"<<endl<<"2.-Eliminar elemento"<<endl<<"3.-Ver elementos"<<endl;
        cin>>opt;
        switch (opt)
        {
        case 1:
            cout<<"Inserta un numero"<<endl;
            cin>>dato;
            ins_elem(&inicio,dato);
            
            break;
        case 2:
            tam=size_que(inicio);
            elim_elem(&inicio,tam);
            break;
        case 3:
            most_que(inicio);
            break;
        default:
            cout<<"Introduce una opcion valida";
            break;
        }
    } while (opt!=5);
    

}

int size_que(Nodo *list){
    Nodo *iterador;
    int a;
    iterador=list->sig;
    while (iterador->sig!=NULL)
    {
        iterador=iterador->sig;
        a++;
    }
    
    return a;
}

bool ins_elem(Nodo **list,int dato){
    Nodo *new_nod;
    Nodo *iterador=(*list)->sig;
    Nodo *antes;
    
    new_nod=new Nodo();
    new_nod->sig=NULL;
    if ((*list)->sig==NULL)
    {
        (*list)->sig=new_nod;
        cout<<"Primer Numero insertado exitosamente"<<endl;
        return true;
    }
    while ((iterador->sig!=NULL) && (iterador->dato<dato))
    {
        antes=iterador;
        iterador=iterador->sig;
    }
    system("pause");
    antes->sig=new_nod;//aqui se muere el programa
    new_nod->sig=iterador;
    return true;
}


bool elim_elem(Nodo **list,int tam){
    Nodo *iterator;
    Nodo *antes;
    iterator=(*list)->sig;
    while (iterator->sig!=NULL)
    {   
        antes=iterator;
        iterator=iterator->sig;
    }
    antes->sig=NULL;
    delete iterator;
    return true;
}


bool most_que(Nodo *list){
    Nodo *iterador;
    iterador=list->sig;
    if (iterador==NULL)
    {
        cout<<"No hay elementos"<<endl;
        return false;

    }
    
    while (iterador->sig!=NULL)
    {
        cout<<iterador->dato<<"-->";
        iterador=iterador->sig;
    }
    cout<<endl;
    return true;
}

/*
================================================
===============Doble apuntador==================
================================================
int **arr=(int**)malloc(n,sizeof(int*));

for(int i;i<3,i++){
    arr[i]=(int*)malloc(n*sizeof(int))
}
*Se puede sustituir malloc con calloc*
*/