/**
 * @file estructuras.c
 * @author VALDES LUIS ELIOT FABIAN
 * @brief archivo con programa de generacion, edicion y busqueda de estructuras anidadas
 * @version 0.1
 * @date 2022-03-03
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// print animation
int sleep();
void loading()
{
    printf("[");
    for (int i = 0; i < 3; i++)
    {
        printf("#");
        // usar si no se quiere mostrar la animacion
        // sleep(1 / 2);
        sleep(1);
    }
    printf("]");
}


// main function
void main()
{
    // variables de menu
    int opcionSalir = 4;
    int opcionSeleccionMenu;

    // print greetings
    puts("**************************************");
    puts("Bienvenido");
    puts("**************************************");

    do
    {
        opcionSeleccionMenu = 0;
        // print Menu
        puts("--------------------------------------");
        puts("Digita la opcion que deseas realizar:");
        puts("1.- Registrar datos en estructura");
        puts("2.- Mostrar datos de estructura");
        puts("3.- Buscar datos en estructura");
        puts("4.- Salir");
        puts("--------------------------------------");
        scanf("%d", &opcionSeleccionMenu);
        fflush(stdin);

        switch (opcionSeleccionMenu)
        {

        case 1:

            puts("\n\t *** Has seleccionado la opcion para registrar datos en estructura ***\n ");
            // Start Coding

            // End of Code

            break;

        case 2:

            puts("\n\t *** Has seleccionado la opcion para mostrar los datos de la estructura ***\n ");
            // Start Coding

            // End of Code

            break;

        case 3:

            puts("\n\t *** Has seleccionado la opcion de buscar datos en la estructura ***\n ");
            // Start Coding

            // End of Code

            break;

        case 4:
            printf("\nSALIENDO DEL PROGRAMA ");
            loading();
            puts("\n\n *** ADIOS *** :)\n ");
            exit(0);
            break;

        default:
            puts("Opcion no valida");
            break;
        }
    } while (opcionSeleccionMenu != opcionSalir);
}