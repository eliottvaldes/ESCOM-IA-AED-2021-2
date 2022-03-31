/*
* Juarez Jimenez Oscar Antonio
* 2BV1
* Ingenieria en Inteligencia Artificial 
* 29/03/2022
*/
#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<queue>
using namespace std;
    typedef struct
    {
    string Tipodemaderamadera;
    int patas;
    int id;
    }silla;
queue<silla> Registrofinal(queue<silla>,queue<silla>);
void RegistroPos(queue<silla>*,queue<silla>*);
silla Registro();
void imprimeIF(queue<silla>);
void imprimeFI(queue<silla>);
void eliminadatosI(queue<silla>*);
void eliminadatosP(queue<silla>*);
int main(){    
    int OpcionUser;
    int pos=0,TAM=0;
    silla lasilla;
    silla*apunta;
    queue<silla>queue1;
    queue<silla>queue2;
    queue<silla>queue3;
    do
    {
    cout<<"Ingrese la opcion que de desea\n1.Agregar silla al inicio\n2.Agregar una silla al final\n3. Agregar silla al lugar N\n4, Imprimir de inicio a fin\n5. Imprimir FIN a INICIO\n6. Eliminar al inicio\n7. Eliminar al final\n8. Eliminar posicional N\n9. Salir"<<endl;
    cout<<"Los datos que se ingresen deben estar en el siguiente orden 1.Tipo de madera2.#Patas 3.id "<<endl;
    cin>>OpcionUser;
    switch (OpcionUser)
    {
    case 2:
    // cin>>lasilla.Tipodemaderamadera;
    // cin>>lasilla.patas;
    // cin>>lasilla.id;
    // if (queue2.size()==0)
    // {   queue3.push(Registro());
    //     while (!queue3.empty())
    // {
    //     queue2.push(queue3.front());
    //     queue3.pop();
    // }}
    // else{queue3.push(lasilla); 
    //     while (!queue2.empty())
    // {   queue3.push(queue2.front());
    //     queue2.pop();}
    // while (!queue3.empty())
    // {   queue2.push(queue3.front());
    //     queue3.pop();        }
    //     }
    queue2=Registrofinal(queue2,queue3);
        break;
    case 1:
    // cin>>lasilla.Tipodemaderamadera;
    // cin>>lasilla.patas;
    // cin>>lasilla.id;
    queue2.push(Registro());
    break;
    case 3:
    cout<<"Ingrese la posicion donde la desea asignar la silla y posteriormente ingrese los datos de la silla la posicion donde la desea asignar"<<endl;
    // cin>>lasilla.Tipodemaderamadera;
    // cin>>lasilla.patas;
    // cin>>lasilla.id;
    // cin>>pos;
    // if(pos>queue2.size()||pos<0){cout<<"Erro en la poscion porfavor introdusca una poscion en el rango entre 0 y "<<queue2.size()<<endl;}
    // else{
    // while (queue2.size()>pos)
    // {
    //     queue3.push(queue2.front());
    //     queue2.pop();
    // }
    // queue3.push(Registro());
    //     while (!queue2.empty())
    // {
    //     queue3.push(queue2.front());
    //     queue2.pop();
    // }
    // while (!queue3.empty())
    // {
    //     queue2.push(queue3.front());
    //     queue3.pop();
    // }}
    RegistroPos(&queue2,&queue3);
        break;        
    case 5:
    //     while (!queue2.empty())
    // {
    //     queue3.push(queue2.front());
    //     queue1.push(queue2.front());
    //     queue2.pop();
    // }
    //     while (!queue1.empty())
    // {
    //     queue2.push(queue1.front());
    //     queue1.pop();
    // }
    // while (!queue3.empty())
    // {
        
    //     apunta=&queue3.front();
    //     cout<<apunta->Tipodemaderamadera<<endl;
    //     cout<<apunta->patas<<endl;
    //     cout<<apunta->id<<endl;
    //     queue3.pop();
    // }
    imprimeFI(queue2);
        break;
    case 4:
    // TAM=queue2.size();
    // for (size_t i=0,j= 0; i < TAM; i++){
    // for (size_t i = 0; i < TAM; i++)
    // {   queue1.push(queue2.front());
    //     queue2.pop();}
    //     while (queue1.size()-j>0)
    //     {
    //     queue2.push(queue1.front());
    //     queue1.pop();
    //     }
    //     j++;
    //     apunta=&queue2.back();
    //     cout<<apunta->Tipodemaderamadera<<endl;
    //     cout<<apunta->patas<<endl;
    //     cout<<apunta->id<<endl;
    //     if(queue1.size()!=0){while (!queue1.empty())
    //     {
    //     queue2.push(queue1.front());
    //     queue1.pop();
    //     }}}
        imprimeIF(queue2);
        break;
    case 6:
    // if(queue2.size()==0)cout<<"no hay datos que borrar"<<endl;
    // else{   
    // while (queue2.size()-1>0)
    // {
    //     queue1.push(queue2.front());
    //     queue2.pop();
    // }
    // queue2.pop();
    //     while (!queue1.empty())
    // {
    //     queue2.push(queue1.front());
    //     queue1.pop();
    // }}
    eliminadatosI(&queue2);
        break;
    case 7:
    if(queue2.size()==0)cout<<"no hay datos que borrar"<<endl;
    else queue2.pop();
        break;
    case 8:
    // if(queue2.size()==0)cout<<"no hay datos que borrar"<<endl;
    // else{
    // cout<<"Ingrese la posicion donde la desea elimiar los datos"<<endl;
    // cin>>pos;
    // if(pos>queue2.size()||pos<0){cout<<"Erro en la poscion porfavor introdusca una poscion en el rango entre 0 y "<<queue2.size()<<endl;}
    // else{
    // while (queue2.size()-1>pos)
    // {
    //     queue3.push(queue2.front());
    //     queue2.pop();
    // }
    // queue2.pop();
    // while (!queue2.empty())
    // {
    //     queue3.push(queue2.front());
    //     queue2.pop();
    // }
    // while (!queue3.empty())
    // {
    //     queue2.push(queue3.front());
    //     queue3.pop();
    // }   }
    // }
    eliminadatosP(&queue2);
    break;
    case 9:
    cout<<"Hasta luego :)"<<endl;
        break;
    default:
    cout<<"Opcion no valida"<<endl;
        break;
    }
    } while (OpcionUser!=9);
    
    return 0;
}
