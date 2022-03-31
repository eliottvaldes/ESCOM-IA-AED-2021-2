/* ▪* Montero Barraza Alvaro David*
 *2BV1 Ingenieria en IA ▪*  ▪*/
#include<iostream>
#include<stdlib.h>
using namespace std;



typedef struct Nodo{
        int dato;
        Nodo *sig;
}Nodo;

void ins_list(Nodo *&lista,int dato);

int main(){
    Nodo *inicio=NULL;
    int cond=0,num;
    do
    {
        cout<<"Introduce EL numero que quieras insertar"<<endl;
        cin>>num;
        ins_list(inicio,num);
        

    } while (cond==0);
    


    return 0;
}



void ins_list(Nodo *&lista,int dato){
      Nodo *nuevo_nodo=new Nodo();
      nuevo_nodo->dato=dato;
      Nodo *aux1=lista;
      Nodo *aux2;
      while (aux1!=NULL&&aux1->dato<dato)
      {
          aux2=aux1;
          aux1=aux1->sig;
      }
      if (lista==aux1)
      {
          lista=nuevo_nodo;
      }
      else{
          aux2->sig=nuevo_nodo;
      }
      nuevo_nodo->sig=aux1;
      
      cout<<"Numero "<<nuevo_nodo->dato<<" insertado correctamente"<<endl;
  
}
//crea nodo nuevo
//poner datos
//Enlace a siguiente null