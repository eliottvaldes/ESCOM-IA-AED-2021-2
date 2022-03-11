/* ▪* Montero Barraza Alvaro David*
 1BM1▪* Ingenieria en IA ▪* ▪*/
 #include<stdio.h>/*   []  \n */
 #include<stdlib.h>
 #include<string.h>
 #include<time.h>


int *array=NULL;

 
typedef struct
{
    int num_cuenta;
    char name[20];
    char alias[20];
    float dinero;

}Tda1;
typedef struct
{
    int Area;
    char jefe[20];
    float tiempo;
    Tda1 nido; 
}Tda2;

Tda2 *struct_array;




int secuencial(Tda2 *datos,int busca,int tam){
     
     for (int i = 0; i < tam; i++)
     {
         if (datos[i].nido.num_cuenta==busca)
         {
             return i;
         }

         
     }
     puts("Dato no encontrado");
     return -1;
     system("pause");

 }
