/* ▪* Montero Barraza Alvaro David*
 1BM1▪* Ingenieria en IA ▪* ▪*/
 #include<stdio.h>/*   []  \n */
 #include<stdlib.h>
 #include<string.h>
 #include<time.h>


int *array=NULL;
 




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
