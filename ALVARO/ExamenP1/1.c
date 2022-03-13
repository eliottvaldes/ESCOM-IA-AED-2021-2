/* ▪* Montero Barraza Alvaro David*
 *2BV1 Ingenieria en IA ▪*  ▪*/
 #include<stdio.h>/*   []  \n */
 #include<stdlib.h>
 #include<string.h>

 
 int *generar_arr(int* array,int tam){
     for (int i = 0; i < tam; i++)
     {
         array[i]=rand()%200+300;
     }
     
     return array;
 }
 int imp_arr(int tam,int *array){

     for (int i = 0; i < tam; i++)
     {
         printf("%i\n",array[i]);
     }
     
 }


 int rep(int tam,int*array){
     int cuenta=0;
     int i;
        for (i = 0; i < tam; i++)
        {
            for (int j = 0; j < tam; j++)
            {
                if (j==i)
                {
                    
                }else if (array[i]==array[j])
                { 
                    cuenta++;
                }
                
            }
            
        }
        
        return cuenta;
 }



 int *nuevo_arr(int *array,int tam,int menos){
     int *arr;
     arr=(int*)malloc((tam-menos)*sizeof(int));
    for (int k = 0; k < tam; k++)
    {
        for (int i = 0; i < tam-1; i++)
        {
            for (int j = 0; j < tam; j++)
            {
                if (array[i]==array[j]&&array[i]!=array[i])
                {
                    arr[k]=array[i];
                }
                else{
                    arr[k]=array[k];
                }
            }
            
        }
    }
    
     

     return arr;
 }



 void main(){
     int tam,repetidos;
     int *array;
     int *array2;
     printf("De que tamano quieres que sea el arreglo?\n");
     scanf("%i",&tam);
     array=(int*)malloc(tam*sizeof(int));
     array=generar_arr(array,tam);
     puts("El primer array es:\n");
     imp_arr(tam,array);
     repetidos=rep(tam,array);
     array2=nuevo_arr(array,tam,repetidos);
     printf("Hay %i elementos repetidos\n",repetidos);
     imp_arr(tam-repetidos,array2);
     
    

    system("pause");
 }

 