/* ▪* Montero Barraza Alvaro David*
 *2BV1 Ingenieria en IA ▪*  ▪*/
#include<iostream>
#include<stdlib.h>
using namespace std;



typedef struct Nodo{
        int dato;
        Nodo *sig;
}Nodo;



int main(){
    Nodo *inicio;
    Nodo *collect;
    Nodo *aux1,*aux2;
    inicio->sig=NULL;
    int cond=0;
    do
    {
        if (inicio==NULL)
        {
            collect=(Nodo*)calloc(1,sizeof(Nodo));
            collect->sig=NULL;
            collect->dato=15;
            inicio->sig=collect;
        }
        

    } while (cond==0);
    


    return 0;
}
//crea nodo nuevo
//poner datos
//Enlace a siguiente null