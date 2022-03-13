/* ▪* Montero Barraza Alvaro David*
 1BM1▪* Ingenieria en IA ▪* ▪*/
 #include<stdio.h>/*   []  \n */
 #include<stdlib.h>
 #include<string.h>
 #include<time.h>


int *array=NULL;
int *Arrayin(int tam){
    int *array_indice=(int*)malloc(tam*sizeof(int));
    for (int i = 0; i < tam; i++)
    {
        array_indice[i]=i;
    }
    return array_indice;

}
 
int Indexada(int* arrayNum,int* arrayIn,int tam,int buscar)
{
    int pos,Aux=0,val;
    int indiceInicial=0, inicioBusqueda, finBusqueda;
    int esNumeroEnArreglo=0;

    // Si el numero que e quiere buscar es menor que el primer numero del arreglo
    //O mayor que el ultimo numero, asumimos que no se encuentra dentro de este
    if  (buscar<arrayNum[0]|buscar>arrayNum[tam])
    {
        puts("El valor introducido no se encuentra en el arreglo\n\n");
        system("pause");
        return -1;
    }
    else
    {
        for (pos=1;pos<=indiceInicial;pos++)
            if  (buscar<=arrayNum[pos])
            {
                inicioBusqueda=arrayIn[pos- 1];
                finBusqueda=arrayIn[pos];
                Aux=1;
                break;
            }
    }
    // Si no se cumplio la condicion, cambiamos el inicio y el fin
    if (Aux==0)
    {
        inicioBusqueda=arrayIn[pos-1];
        finBusqueda=tam;
    }
    // Se vuelve a hacer la busquda con nuevos valores
    for (pos=inicioBusqueda; pos <= finBusqueda; pos++)
    {
        // Se retorna el valor de la posicion, usamos busqueda secuencial buscando en el resultante
        if  (buscar==arrayNum[pos])
        {
            val=pos;
            return val;
        }
    } return -1;
    
}




void merge_sort(int *array,int p, int q, int r){
        int i,j=0,k=0;
        int n1=(q-p)+1;
        int n2=(r-q);

        


        int *L=(int*)malloc(n1*sizeof(int));
        int *R=(int*)malloc(n2*sizeof(int));

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

    return array;
}
