/* ▪* Montero Barraza Alvaro David*
 *2BV1 Ingenieria en IA ▪*  ▪*/
 #include<stdio.h>/*   []  \n */
 #include<stdlib.h>
 #include<string.h>
 #include<C:\Users\Montero\Documents\AED-IA-ESCOM\ALVARO\etructura busqueda\Lib.h>


int print_struct(Tda2 *str_ar,int tam){
    for (int i = 0; i < tam; i++)
    {
        printf("Numero de cuenta: %i\n",str_ar[i].nido.num_cuenta);
        printf("Nombre: %s",str_ar[i].nido.name);
        printf("Alias: %s",str_ar[i].nido.alias);
        printf("Area: %i\n",str_ar[i].Area);
        printf("Jefe: %s",str_ar[i].jefe);
        printf("Dinero: %.2f\n",str_ar[i].nido.dinero);
        printf("Tiempo: %.2f\n",str_ar[i].tiempo);
        printf("\n\n");
    }
    

}


Tda2* reg(){
    Tda2 *str;
    char aux[5];
    int aent;
    float afl;
    str=(Tda2*)calloc(1,sizeof(Tda2));
    if (str==NULL)
    {
        perror("No hay memoria suficiente");
        system("pause");
    }
    puts("Introduce el area\n");
    scanf("%i",&aent);
    str->Area=aent;
    puts("Introduce El numero de cuenta\n");
    scanf("%i",&aent);
    str->nido.num_cuenta=aent;
    puts("\nIntroduce la cantiad de dinero\n");
    scanf("%f",&afl);
    str->nido.dinero=afl;
    puts("Introduce el nombre\n");
     fgets(aux,5,stdin);
     fgets(str->nido.name,20,stdin);
    puts("Introduce el alias\n");
    fgets(str->nido.alias,20,stdin);
    puts("Quien es tu jefe?\n");
    fgets(str->jefe,20,stdin);
    puts("Introduce el tiempo\n");
    scanf("%f",&afl);
    str->tiempo=afl;
    return str;
}


Tda2* regplus(Tda2 *struct_array,int num){
    char aux[5];
    int aint;
    float aflot;
    struct_array=(Tda2*)realloc(struct_array,(num+1)*sizeof(Tda2));
    
    
    puts("Introduce el area\n");
    scanf("%i",&aint);
    fflush(stdin);
    struct_array[num].Area=aint;
    puts("Introduce el numero de cuenta\n");
    scanf("%i",&aint);
    fflush(stdin);
    struct_array[num].nido.num_cuenta=aint;
    puts("\nIntroduce la cantiad de dinero\n");
    scanf("%f",&aflot);
    fflush(stdin);
    struct_array[num].nido.dinero=aflot;
    puts("Introduce el nombre\n");
    fgets(aux,5,stdin);
    fgets(struct_array[num].nido.name,20,stdin);
    puts("Introduce el alias\n");
    fgets(struct_array[num].nido.alias,20,stdin);
    puts("Quien es tu jefe\n");
    fgets(struct_array[num].jefe,20,stdin);
    puts("Introduce el tiempo\n");
    scanf("%f",&aflot);
    fflush(stdin);
    struct_array[num].tiempo=aflot;

    return struct_array;
 }
    

 void main(){ 
     Tda2 *struct_array=NULL;
     int opt,count=0,val,busc;
     puts("Registrar datos\n");
     struct_array=reg();
     count++;
     do
     {
         
         
         puts("1.-Registrar nueva entrada\n2.-Imprimir\n3.-Buscar\n");
         scanf("%i",&opt);
         switch (opt)
         {
         case 1:
            
               
                
                    struct_array=regplus(struct_array,count);
                    count++;
                    system("pause");
                
             break;
             case 2:
                    print_struct(struct_array,count);
                    break;

             case 3:

             break;
            case 4:
                opt=5;
            break;
         
         default:
         puts("Introuce una opcion valida");
             break;
         }
         
         
     } while (opt!=5);
     }
    
     
      
 

 