/* ▪* Montero Barraza Alvaro David*
 1BM1▪* Ingenieria en IA ▪* ▪*/
 #include<stdio.h>/*   []  \n */
 #include<stdlib.h>
 #include<string.h>
 #include<time.h>

int *array=NULL;
 void imp(int tam){

            printf("Orden descendente\n");
            for (int i = 0; i < tam; i++)
             {
                printf("%i\n",array[i]);
             }

 }
 int burbuja( int tam){
            free(array);
            int aux;
            array=(int*)malloc(tam*sizeof(int));
            if (array==NULL)
            {
                puts("Se termino la memoria");
                return 0;
            }   
            for (int i = 0; i < tam; i++)
            {
                array[i]=rand();
            }
            printf("numeros antes de ser ordenados\n");
            imp(tam);
            printf("\n");
             int temp;
            for (int i = 0; i < tam; i++)
            {
               for (int j = 0; j < tam-i; j++)
               {
                   if (array[j]>array[j+1])
                   {
                       temp=array[j];
                       array[j]=array[j+1];
                       array[j+1]=temp;
                   }

               }
               
            }   
            printf("Orden descendente\n");
            for (int i = 0; i < tam; i++)
            {
                printf("%i\n",array[i]);
            }
            
            

 }

 int insercion(int tam){
      free(array);
            int aux;
            array=(int*)malloc(tam*sizeof(int));
            if (array==NULL)
            {
                puts("Se termino la memoria");
                return 0;
            }   
            for (int i = 0; i < tam; i++)
            {
                array[i]=rand();
            }
            printf("numeros antes de ser ordenados\n");
            imp(tam);
            printf("\n");

            for (int i = 0; i < tam; i++)
            {
                int temp=array[i];
                int j=i;
                while (array[j-1]>temp&&j>0)
                {
                    array[j]=array[j-1];
                    j--;
                }
                array[j]=temp;
            }
            
                 printf("Orden descendente\n");
            for (int i = 0; i < tam; i++)
            {
                printf("%i\n",array[i]);
            }

 }






 int seleccion(int tam){
        int pos_menor,tmp;
     free(array);
            int aux;
            array=(int*)malloc(tam*sizeof(int));
            if (array==NULL)
            {
                puts("Se termino la memoria");
                return 0;
            }   
            for (int i = 0; i < tam; i++)
            {
                array[i]=rand();
            }
            printf("numeros antes de ser ordenados\n");
            imp(tam);
            printf("\n");


            for (int i = 0; i < tam-1; i++)
            {
                pos_menor=i;
                for (int j = i+1; j < tam; j++)
                {
                    if(array[j]<array[pos_menor]){
                        pos_menor=j;
                    }
                }
                aux=array[i];
                array[i]=array[pos_menor];
                array[pos_menor]=aux;
            }
            
printf("Orden descendente\n");
            for (int i = 0; i < tam; i++)
            {
                printf("%i\n",array[i]);
            }   


 }




void merge_sort(int *array,int p, int q, int r){
        int i,j=0,k=0;
        int n1=(q-p)+1;
        int n2=(r-q);

        


        int *L=malloc(n1*sizeof(int));
        int *R=malloc(n2*sizeof(int));

        for ( i = 0; i < n1; i++)
        {
            L[i]=*(array+p+i);
        }
        for ( i = 0; i <n2; i++)
        {
            R[i]=*(array+q+i+1);
        }
        i=0;

        for (k = p; k < r+1; k++)
        {
            if (i==n1)
            {
                *(array+k)=*(R+j);
                j=j+1;
            }else if(j==n2){
                *(array+k)=*(L+i);
                i=i+1;
            }else if(*(L+i)<=*(R+j)){
                *(array+k)=*(L+i);
                i=i+1;

            }else{
                *(array+k)=*(R+j);
                j=j+1;
            }
            

        }
        
        

}       

void mergesort(int *array,int p, int r){
    if(p<r){
            
        int q=(p+r)/2;
        mergesort(array,p,q);
        mergesort(array,q+1,r);
        
        merge_sort(array,p,q,r);
    }
    

}


int* merge(int tam){
            free(array);
            array=(int*)malloc(tam*sizeof(int));
            if (array==NULL)
            {
                puts("Se termino la memoria");
                return 0;
            }   
            for (int i = 0; i < tam; i++)
            {
                array[i]=rand();
            }  
           

            int r=(tam*sizeof(int))/sizeof(int)-1; 
            int p=0;
            
            mergesort(array,p,r);
            
            printf("Orden descendente\n");
            for (int i = 0; i < tam; i++)
             {
                printf("%i\n",*(array+i));
             }

    return *array;
}

void QuickSort(int *array, int inicio, int final) {
  int i = inicio, f = final, tmp;
  int x = array[(inicio + final) / 2];
        do {
            while(array[i] < x && f <= final) {
            i++;
            }
            while(x < array[f] && f > inicio) {
            f--;
            }
            if(i <= f) {
            tmp = array[i];
            array[i] = array[f];
            array[f] = tmp;
            i++; f--;
            }
   }         while(i <= f);

        if(inicio < f) {
          QuickSort(array,inicio,f);//algoritmo recursivo
        }

       if(i < final){
         QuickSort(array,i,final);
       }

}



int quick(int tam){
            free(array);
            int aux;
            array=(int*)malloc(tam*sizeof(int));
            if (array==NULL)
            {
                puts("Se termino la memoria");
                return 0;
            }   
            for (int i = 0; i < tam; i++)
            {
                array[i]=rand();
            }
          printf("numeros antes de ser ordenados\n");
            imp(tam);
            printf("\n");
            
            QuickSort(array,0,tam-1);
             printf("Orden descendente\n");
            for (int i = 0; i < tam; i++)
            {
                printf("%i\n",array[i]);
            }



}



