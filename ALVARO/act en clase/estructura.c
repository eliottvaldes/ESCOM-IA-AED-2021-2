#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
    {
        char nombre[30];
        float duracion;
        char director[30];
        char clasificacion[30];
        int anio;



    }Peli;

int main(){
    
    
    int cond=0;
        Peli pelicula;
        int a;
        char aux1[30];
        do
        {
                printf("Quieres grabar pelicula(1) o mostrar(2)\n");
                scanf("%i",&a);
            switch(a)
            {

                case 1:
                 fgets(aux1,30,stdin);
            puts("Introduce elnombre de la pelicula");
            fgets(aux1,30,stdin);
            strcpy(pelicula.nombre,aux1);
            puts("introduce la duracion");
            scanf("%i",&pelicula.duracion);
            fgets(aux1,30,stdin);
            puts("Instroduce el director");
            fgets(aux1,30,stdin);
            strcpy(pelicula.director,aux1);
            puts("Introduce la clasificación");
            fgets(aux1,30,stdin);
            strcpy(pelicula.clasificacion,aux1);
            puts("Introduce el año de estreno");
            scanf("%i",&pelicula.anio);
                break;
            case 2:
                    printf("El nombre de la pelicula es: %s\n Su duracion es: %.2f\n Su director es: %s\n Su año de estreno es: %i\n Su clasificacion es: %s",pelicula.nombre,pelicula.duracion,pelicula.director,pelicula.anio,pelicula.clasificacion);

                    
                break;

            case 3:
                    puts("\ndeseas salir del programa? si=1, no=0\n");
                     scanf("%i",&cond);

            break;
            default: 
            
                puts("Escoge una opcion valida");
                break;
            }
            
            
        } while (cond==0);
        



    return 0;
}