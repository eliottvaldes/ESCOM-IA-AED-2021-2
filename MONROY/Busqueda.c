/*
Monroy Fernández José Luis
2BV1
Inteligencia artificial
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    int opcionUsuario;
    int Range, Caract;
    int *CadenaNum;
    do
    {
        puts("Seleccione una opcion");
        puts("1.-Generar datos");
        puts("2.-Imprimir la ultima cadena registrada");
        puts("3.- Ordenar datos con Bubble");
        puts("4.- Ordenar datos con Insercion");
        puts("5.- Ordenar datos con Selection");
        puts("6.- Ordenar datos con Merge");
        puts("7.- Ordenar datos con Quick");
        puts("8.- Salir del programa");
        fflush(stdin);
        scanf("%d", &opcionUsuario);
        switch (opcionUsuario)
        {
        case 1:
            // Random Numbers
            // Clear memory
            free(CadenaNum);
            // Random Seed
            srand(time(NULL));
            puts("Porfavor digite cuantos digitos habra en la cadena");
            scanf("%d", &Caract);
            puts("Porfavor digite el limite del rango para obtener los numeros aleatorios");
            scanf("%d", &Range);
            // Dinamic memory reservation
            CadenaNum = malloc(Caract * sizeof(int));
            // Save numbers
            for (int i = 0; i < Caract; i++)
            {
                CadenaNum[i] = rand() % Range;
            }
            break;
        case 2:
            // Print String
            puts("La utima serie registrada es:");
            printf("[");
            for (int i = 0; i < Caract; i++)
            {
                printf("%d, ", CadenaNum[i]);
            }
            printf("]");
            break;
        case 3:
            // BUbble
            for (int i = 0; i < Caract; i++)
            {
                for (int j = 0; j < Caract - i; j++)
                {
                    if (CadenaNum[j] > CadenaNum[j + 1])
                    {
                        int temp = CadenaNum[j];
                        CadenaNum[j] = CadenaNum[j + 1];
                        CadenaNum[j + 1] = temp;
                    }
                }
            }
            break;
        case 4:
            // Insercion
            int j, temp;
            for (int i = 0; i < 4; i++)
            {
                j = i;
                temp = CadenaNum[i];
                while ((j > 0) && (temp < CadenaNum[j - 1]))
                {
                    CadenaNum[j] = CadenaNum[j - 1];
                    j--;
                }
                CadenaNum[j] = temp;
            }
            break;
        case 5:
            break;
        default:
            // End Of The Program
            puts("Fin del programa");
            break;
        }
    } while (opcionUsuario != 8);
}