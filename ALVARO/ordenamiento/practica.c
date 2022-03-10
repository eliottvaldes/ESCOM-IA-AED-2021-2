/* ▪* Montero Barraza Alvaro David*
 *2BV1 Ingenieria en IA ▪*  ▪*/
 #include<stdio.h>/*   []  \n */
 #include<stdlib.h>
 #include<string.h>
 #include<C:\Users\Montero\Desktop\ESCOM\2BV1\Estructura\p1\ordenamiento\Lib.h>
    


 void main(){
     int cond=0,opt,tam;
     do
     {
         printf("Que opcion eliges:\n1.-Ver arreglo\n2.-burbuja\n3.-Insercion\n4.-Seleccion\n5.-Mergesort\n6.-Quicksort\n");
        scanf("%i",&opt);
         switch (opt)
         {
         case 1:
           imp(tam);
             break;
             
         case 2:
          printf("De que tamano es tu arreglo\n");
            scanf("%i",&tam);
             burbuja(tam);
             break;
         case 3:
          printf("De que tamano es tu arreglo\n");
            scanf("%i",&tam);
            insercion(tam);
             break;
         case 4:
          printf("De que tamano es tu arreglo\n");
            scanf("%i",&tam);
            seleccion(tam);
             break;
         case 5:
          printf("De que tamano es tu arreglo\n");
            scanf("%i",&tam);
            merge(tam);
             break;
         case 6:
          printf("De que tamano es tu arreglo\n");
            scanf("%i",&tam);
            quick(tam);
             break;
         
         default: printf("Introduce una opcion valida\n");
            
             break;
         }






         printf("\nQuieres seguir en el programa? 0=si, 1=no\n");
         scanf("%i",&cond);
     } while (cond==0);
     



 }