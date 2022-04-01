/* ▪* Montero Barraza Alvaro David*
 *2BV1 Ingenieria en IA ▪*  ▪*/
#include<iostream>
#include<stdlib.h>
using namespace std;



typedef struct Nodo{
        int dato;
        Nodo *sig;
}Nodo;

void ins_listini(Nodo *lista,int dato);
void most_list(Nodo *lista);
void ins_listfin(Nodo *lista,int dato);
int sizeof_nodo(Nodo* Lista);

int main(){
    Nodo *inicio=NULL;
    int cond=0,num;
    do
    {
        cout<<"1.-insertar inicio "<<endl<<"2.-insertar fin"<<endl<<"3.-ver lista"<<endl<<"4.-salir"<<endl;
        cin>>cond;
        switch (cond)
        {
        case 1:
            cout<<"Introduce un numero"<<endl;
            cin>>num;
            ins_listini(inicio,num);
            break;
        case 2:
            cout<<"Introduce un numero"<<endl;
            cin>>num;
            ins_listfin(inicio,num);
            break;
        case 3:
            most_list(inicio);
            break;
        case 4:
            break;
        default:
            break;
        }
        
        
    } while (cond!=4);
    
    system("pause");

    return 0;
}



void ins_listini(Nodo *lista,int dato){
      Nodo *nuevo_nodo=new Nodo();//1
      nuevo_nodo->sig=NULL;//2
      nuevo_nodo->dato=dato;//3
      
      if (lista==NULL)
      {
          lista->sig=nuevo_nodo;
      }else{
          nuevo_nodo->sig=lista->sig;
          lista->sig=nuevo_nodo;
      }
      
}


void ins_listfin(Nodo *lista,int dato){
    Nodo *iterador;
    iterador=lista;
    while (iterador->sig!=NULL)
    {
        iterador=iterador->sig;
    }
    Nodo *nuevo_nodo=new Nodo();
    nuevo_nodo->sig=NULL;
    iterador->sig=nuevo_nodo;
    nuevo_nodo->dato=dato;
    
}


void most_list(Nodo *lista){
    Nodo *iterador;
    iterador=lista;
    while (iterador!=NULL)
    {
        
        iterador=iterador->sig;
    }
    cout<<endl;
}

int sizeof_nodo(Nodo* Lista){
    Nodo *iterador;
    int counter;
    iterador=Lista;
    while (iterador!=NULL)
    {
        counter++;
        iterador=iterador->sig;
    }
    return counter;
}
//crea nodo nuevo
//poner datos
//Enlace a siguiente null