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

 int dato_medio(int tam,Tda2 *array,int valor){
    int medio, inf=0, sup=tam+1;
    while (inf<=sup)
    {
        medio=((sup-inf)/2)+inf;
        if (array[medio].nido.num_cuenta==valor)
        {
            return medio;
        }
        else if(valor<array[medio].nido.num_cuenta){
            sup=medio-1;
        }else{
            inf=medio+1;
        }
    }
    puts("ERROR");
    system("pause");
    return -1;
 }