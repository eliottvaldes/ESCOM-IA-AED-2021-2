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
    inicio=new Nodo();
    int cond=0,num;
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
            system("cls");
            most_list(inicio);
            break;
        case 4:
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