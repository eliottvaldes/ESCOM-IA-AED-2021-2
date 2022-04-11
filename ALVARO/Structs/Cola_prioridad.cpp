/*
======================================
 ▪* Montero Barraza Alvaro David*
    *2BV1 Ingenieria en IA ▪*  
=======================================
 */
#include<iostream>
#include<stdlib.h>
#include<queue>
using namespace std;




typedef struct Nodo{
        int dato;
        Nodo *sig;

}Nodo;

//Prototipos de funciones
bool ins_elem();
bool elim_elem();

bool most_que();

int main(){
    int opt,tam=0,dato;
    do
    {   
        cout<<"1.-Insertar elemento"<<endl<<"2.-Eliminar elemento"<<endl<<"3.-Ver elementos"<<endl;
        cin>>opt;
        switch (opt)
        {
        case 1:
            cout<<"Inserta un numero"<<endl;
            cin>>dato;
            
            
            break;
        case 2:
            
            break;
        case 3:
           
            break;
        default:
            cout<<"Introduce una opcion valida";
            break;
        }
    } while (opt!=5);
    

}



bool ins_elem(){
   
}


bool elim_elem(){
   
}


bool most_que(){
   
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