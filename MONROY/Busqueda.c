/*
Monroy Fernandez Jose Luis
2BV1
Inteligencia Artificial
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimirDatos(int *, int);
void ordenarDatos(int *, int);
int busquedaSecuencial(int *, int, int);
int busquedaBinaria(int *, int, int);

void imprimirDatos(int *cadenaNum, int extension)
{
    for (int i = 0; i < extension - 1; i++)
    {
        printf("%d ,", cadenaNum[i]);
    }
    printf("%d.", cadenaNum[extension]);
}

void ordenarDatos(int *cadenaNum, int limite)
{
    for (int i = 0; i < limite; i++)
    {
        int position = i;
        for (int j = i + 1; j < limite; j++)
        {
            if (cadenaNum[position] > cadenaNum[j])
            {
                position = j;
            }
        }
        // Swap
        int temp = cadenaNum[position];
        cadenaNum[position] = cadenaNum[i];
        cadenaNum[i] = temp;
    }
}
int busquedaSecuencial(int *arreglo, int longitud, int numeroBusqueda)
{
    for (int i = 0; i < longitud; i++)
    {
        if (arreglo[i] == numeroBusqueda)
        {
            printf("El numero %d esta en la posicion numero %d del arreglo", numeroBusqueda, i + 1);
            return 1;
        }
    }
    printf("El numero %d no se encuentra el la ultimo arreglo registrado", numeroBusqueda);
    return 0;
}

int busquedaBinaria(int *arreglo, int longitud, int numeroBusqueda)
{
    int min = 0;
    int max = (longitud - 1);
    while (min <= max)
    {
        int middle = ((max - min) / 2) + min;
        if (arreglo[middle] == numeroBusqueda)
        {
            printf("El numero %d esta en la posicion numero %d del arreglo", numeroBusqueda, middle + 1);
            return 1;
        }
        else
        {
            if (numeroBusqueda < arreglo[middle])
            {
                max = middle - 1;
            }
            else
            {
                min = middle + 1;
            }
        }
    }
    printf("El numero %d no se encuentra el la ultimo arreglo registrado", numeroBusqueda);
    return 0;
}

void main()
{
    // Var for ask
    int opcionUsuario, numeroBusqueda;
    // Var for Random array
    int range, caract;
    int *cadenaNum;
    do
    {
        printf("\n\n");
        printf("-----------------------------------------");
        puts("\nSeleccione una opcion");
        puts("1.- Generar datos");
        puts("2.- Imprimir la ultima cadena registrada");
        puts("3.- Buscar numero con Secuencial");
        puts("4.- Buscar numero con Binaria");
        puts("5.- Salir del programa");
        fflush(stdin);
        scanf("%d", &opcionUsuario);
        switch (opcionUsuario)
        {
        case 1:
            // Random Numbers
            // Clear memory
            free(cadenaNum);
            puts("Porfavor digite cuantos digitos habra en la cadena");
            scanf("%d", &caract);
            fflush(stdin);
            puts("Porfavor digite el limite del rango para obtener los numeros aleatorios");
            scanf("%d", &range);
            fflush(stdin);
            // Random Seed
            srand(time(NULL));
            cadenaNum = malloc(caract * sizeof(int));
            // Save numbers
            for (int i = 0; i <= caract; i++)
            {
                cadenaNum[i] = rand() % range + 1;
            }
            ordenarDatos(cadenaNum, caract);
            // Print array
            printf("Cadena Generada con exito");
            break;
        case 2:
            printf("El ultimo arreglo en memoria es:\n");
            imprimirDatos(cadenaNum, caract);
            break;
        case 3:
            puts("Porfavor digite el numero que desea buscar");
            scanf("%d", &numeroBusqueda);
            fflush(stdin);
            busquedaSecuencial(cadenaNum, caract, numeroBusqueda);
            break;
        case 4:
            puts("Porfavor digite el numero a buscar");
            scanf("%d", &numeroBusqueda);
            fflush(stdin);
            busquedaBinaria(cadenaNum, caract, numeroBusqueda);
            break;
        case 5:
            printf("Saliendo del programa");
            exit(0);
            break;
        default:
            printf("Porfavor digite una opción valida");
            break;
        }

    } while (opcionUsuario != 5);
}