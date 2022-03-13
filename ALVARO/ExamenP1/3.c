/* ▪* Montero Barraza Alvaro David*
 *2BV1 Ingenieria en IA ▪*  ▪*/
 #include<stdio.h>/*   []  \n */
 #include<stdlib.h>
 #include<string.h>

typedef struct{
        int dia;
        int mes;
        int anio;
}Fecha;

typedef struct{
    char nombre[20];
    char apellido[20];
    char Sapellido[20]; 
}Autor;

typedef struct{
    Fecha momento;
    Autor name;
    char titulo[30];
    char genero[20];//Estructuras anidadas
}Libro;


int buscar_lib(Libro *lib,int tam){//Busqueda secuencial con el apellido del autor
    char busc[20];
    int cuenta=0;
    
    puts("Introduce el apellido del autor");
    scanf("%s",&busc);
    int len=strlen(busc);
    for (int i = 0; i < len; i++)
     {
         for (int j = 0; j < 20; j++)
         {
             if (lib[i].name.apellido[j]==busc[j])
                 {
                 cuenta++;
                 }else{
                       j=20;
             }
             
         }
             if(cuenta==len){
                 return i;
         }
         
     }
     puts("Dato no encontrado");
     return -1;


}

int print_struct(int i,Libro *lectura){//impresion de la estructura
    
    printf("Tu libro es: %s",lectura[i].titulo);
        printf("Genero: %s",lectura[i].genero);
        printf("Su autor es %s %s %s\n",lectura[i].name.nombre,lectura[i].name.apellido,lectura[i].name.Sapellido);
        printf("Fecha: %i/%i/%i\n",lectura[i].momento.dia, lectura[i].momento.mes, lectura[i].momento.anio);
    

}

int main(){
    
    Libro *lectura;
    int opt,len;
    char aux[20];

    puts("Cuantos libros quieres registrar(1-5)\n");
    scanf("%i",&opt);
    
    lectura=(Libro*)malloc(opt*sizeof(Libro));//Se inicia el arreglo con memoria dinamica
    printf("*********************\n");
    puts("Registro de libros\n");
    printf("*********************\n");
    for (int i = 0; i < opt; i++)
    {
        
        puts("Introduce el titulo\n");
        
        fgets(aux,20,stdin);
        fgets(lectura[i].titulo,20,stdin);
        puts("Introduce el genero\n");
        fgets(lectura[i].genero,20,stdin);
        puts("Introduce el nombre del autor\n");
        scanf("%s",&lectura[i].name.nombre);
        puts("Introduce su primer apellido\n");
        scanf("%s",&lectura[i].name.apellido);
        puts("introduce su segundo apellido\n");
        scanf("%s",&lectura[i].name.Sapellido);
        puts("Introduce el dia\n");
        scanf("%i",&lectura[i].momento.dia);
        puts("Introduce el mes\n");
        scanf("%i",&lectura[i].momento.mes);
        puts("Introduce el anio\n");
        scanf("%i",&lectura[i].momento.anio);
    }
    for (int i = 0; i < opt; i++)
    {
        print_struct(i,lectura);
    }
    puts("Quieres buscar un libro?1.-si 0.-no");
    scanf("%i",&len);
    if (len==1)
    {
        len=buscar_lib(lectura,opt);
        if (len==-1)
        {
            system("pause");
            return -1;
        }
        
        puts("El libro que buscas es:");
        print_struct(len,lectura);
    }
    

    system("Pause");

    return 0;
}