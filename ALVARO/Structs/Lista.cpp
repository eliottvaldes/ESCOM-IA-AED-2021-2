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
void ins_listpos(Nodo *lista,int dato, int pos);
int sizeof_nodo(Nodo* Lista);
void elim_ini(Nodo *lista);
void elim_fin(Nodo *Lista);
void elim_pos(Nodo *Lista,int pos);

int main(){
    Nodo *inicio=NULL;
    inicio=new Nodo();
    int cond=0,num,tam,pos;
    do
    {
        cout<<endl<<"introduce la opción deseada"<<endl<<"1.-Agregar datos a inicio"<<endl<<"2.-Agregar datos fin"<<endl<<"3.-Agregar datos pos N"<<endl<<"4.-Imprimir inicio a fin"<<endl<<"5.-Elimina al inicio"<<endl<<"6.-Elimina al final"<<endl<<"7.-Elimina en posicion"<<endl<<"8.-Salir"<<endl;
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
            tam=sizeof_nodo(inicio);
            cout<<"hay "<<tam<<" posiciones"<<endl<<"Introduce la posicion que quieres cambiar"<<endl;
            cin>>pos;
            if (pos>tam||tam<0)
            {
                cout<<"Introduce una opcion valida";
                break;
            }
            
            cout<<"Introduce un numero"<<endl;
            cin>>num;
            
            
            ins_listpos(inicio,num,pos);
            break;
        case 4:
            system("cls");
            most_list(inicio);
            break;
        case 5:
            elim_ini(inicio);
            break;
        case 6:
            elim_fin(inicio);
            break;
        case 7:
            tam=sizeof_nodo(inicio);
            cout<<"hay "<<tam<<" posiciones"<<endl<<"Introduce la posicion que quieres cambiar"<<endl;
            cin>>pos;
            if (pos>tam||tam<0)
            {
                cout<<"Introduce una opcion valida";
                break;
            }
            elim_pos(inicio,pos);

            break;
        case 8:
            break;
        default:
            break;
        }
        
        
    } while (cond!=8);
    
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
    while (iterador->sig!=NULL)
    {
        iterador=iterador->sig;
        cout<<iterador->dato<<"-->";
    }
    cout<<endl;
}

int sizeof_nodo(Nodo* Lista){
    Nodo *iterador;
    int counter=0;
    iterador=Lista;
    while (iterador->sig!=NULL)
    {
        counter++;
        iterador=iterador->sig;
    }
    return counter;
}


void ins_listpos(Nodo *lista,int dato, int pos){
    Nodo *iterador;
    iterador=lista;
    for (int i = 0; i < pos-1; i++)
    {
        iterador=iterador->sig;
    }
    Nodo *nuevo_nodo=new Nodo();
    nuevo_nodo->dato=dato;
    nuevo_nodo->sig=iterador->sig;
    iterador->sig=nuevo_nodo;
}


void elim_ini(Nodo *lista){
    Nodo *aux;
    Nodo *aux2;
    aux=lista->sig;
    aux2=aux->sig;
    lista->sig=aux2;
    delete aux;


}


void elim_fin(Nodo *Lista){
    Nodo *iterador;
    Nodo *antes;
    iterador=Lista->sig;
    while (iterador->sig!=NULL)
    {   
        antes=iterador;
        iterador=iterador->sig;

    }
    antes->sig=NULL;
    delete iterador;
}


void elim_pos(Nodo *Lista,int pos){
    Nodo *iterador;
    Nodo *Antes=new Nodo();
    iterador=Lista;
    for (int i = 0; i < pos; i++)
    {   
        Antes=iterador;
        iterador=iterador->sig;
    }
    Nodo *aux=new Nodo();
    if(iterador->sig==NULL){
        Antes->sig=NULL;
        delete iterador;
    }else{
        Antes->sig=iterador->sig;
        delete iterador;
    }
    

    

}