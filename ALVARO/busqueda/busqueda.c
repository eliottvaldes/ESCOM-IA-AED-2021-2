/* ▪* Montero Barraza Alvaro David*
 *2BV1 Ingenieria en IA ▪*  ▪*/
 #include<stdio.h>/*   []  \n */
 #include<stdlib.h>
 #include<string.h>
 #include<C:\Users\Montero\Documents\AED-IA-ESCOM\ALVARO\busqueda\Lib.h>
 
 int indexada(int *datos,int busca,int tam){


 }
 
 int secuencial(int *datos,int busca,int tam){
     
     for (int i = 0; i < tam; i++)
     {
         if (datos[i]==busca)
         {
             return i;
         }

         
     }
     puts("Dato no encontrado");
     return -1;
     system("pause");

 }
int dato_medio(int tam,int *array,int valor){
    int medio, inf=0, sup=tam;
    while (inf<=sup)
    {
        medio=((sup-inf)/2)+inf;
        if (array[medio]==valor)
        {
            return medio;
        }
        else if(valor<array[medio]){
            sup=medio-1;
        }else{
            inf=medio+1;
        }
    }
    puts("ERROR");
    system("pause");
    return -1;
    

}

 int main(){
     int val,tam,user,cas;
     int *arreglo=NULL;
     puts("Introduce el tamaño del array\n");
     scanf("%i",&tam);
     
            array=(int*)malloc(tam*sizeof(int));
            if (arreglo==NULL)
            {
                puts("Se termino la memoria");
                return 0;
            }   
            for (int i = 0; i < tam; i++)
            {
                array[i]=rand();
            }  
     arreglo=merge(tam);
     do
     {
        puts("0.-Busqueda indexada\n1.-Busqueda binaria\n2.-Busqueda secuencial\n3.-Crear nuevo arreglo\n4.-Salir del programa");
        scanf("%i",&cas);
     switch (cas)
     {
     case 0:
             puts("Introduce el numero que quieras buscar");
     scanf("%i",&user);
     val=indexada(arreglo,user,tam);
     if(val==-1){
         return -1;
     }printf("la posicion de tu valor es %i\n",val);
     system("pause");
     break;

     case 1:

     puts("Introduce el numero que quieras buscar");
     scanf("%i",&user);
     val=dato_medio(tam,arreglo,user);
     if(val==-1){
         return -1;
     }printf("la posicion de tu valor es %i\n",val);
     system("pause");
         break;


     case 2:
     puts("Introduce el numero que quieras buscar");
     scanf("%i",&user);
        val=secuencial(arreglo,user,tam);
        if (val==-1)
        {
            return -1;
            system("pause");
        }
     printf("la posicion de tu valor es %i\n",val);
     system("pause");
     break;
     case 3:
     puts("Introduce el tamaño del array\n");
     scanf("%i",&tam);
     arreglo=merge(tam);


     break;
     case 4:
     

     break;
     
     default:
     puts("Introduce una opcion valida");
         break;
     }
     } while (cas!=4);
     
     
     
     system("pause");
     return 0;

 }