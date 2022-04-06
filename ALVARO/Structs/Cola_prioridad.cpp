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
bool ins_elem(Nodo *list,int tam,int dato);
bool elim_elem(Nodo *list,int tam);
int size_que(Nodo *list);

int main(){
    int opt,tam,dato;
    Nodo *inicio;
    inicio=new Nodo();
    do
    {   
        cout<<"1.-Insertar elemento"<<endl<<"2.-Eliminar elemento"<<endl<<"3.-Ver elementos";
        switch (opt)
        {
        case 1:
            cout<<"Inserta un numero";
            cin>>dato;
            tam=size_que(inicio);
            ins_elem(inicio,tam,dato);
            
            break;
        
        default:
            break;
        }
    } while (opt!=5);
    

}

int size_que(Nodo *list){
    Nodo *iterador;
    int a;
    iterador=list;
    while (iterador->sig!=NULL)
    {
        iterador=iterador->sig;
        a++;
    }
    
    return a;
}

bool ins_elem(Nodo *list,int tam,int dato){
    Nodo *new_nod;
    new_nod=new Nodo();
    if (list==NULL)
    {
        list->sig=new_nod;
        return true;
    }
    

}


bool elim_elem(Nodo *list,int tam){
    Nodo *iterator;
    Nodo *antes;
    iterator=list->sig;
    while (iterator->sig!=NULL)
    {   
        antes=iterator;
        iterator=iterator->sig;
    }
    antes->sig=NULL;
    delete iterator;
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