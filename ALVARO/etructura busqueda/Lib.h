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



 Tda2* burbuja( Tda2 *str,int tam){
            
            
             Tda2 *temp;
            for (int i = 0; i < tam; i++)
            {
               for (int j = 0; j < tam-i; j++)
               {
                   if (str[j].nido.num_cuenta>str[j+1].nido.num_cuenta)
                   {
                       *temp=str[j];
                       str[j]=str[j+1];
                       str[j+1]=*temp;
                   }

               }
               
            }   
   
return str;
 }

