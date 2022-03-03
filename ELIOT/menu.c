/**
 * @file archivo
 * @author VALDES LUIS ELIOT FABIAN
 * @brief
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
    for (int i = 0; i < 5; i++)
    {
        printf("#");
        sleep(1);
    }
    printf("]");
}
// ask for confirmation
bool asking(char askForRepetition, bool repeatExercise)
{
    if (askForRepetition == 'y')
    {
        repeatExercise = true;
    }
    else if (askForRepetition == 'n')
    {
        repeatExercise = false;
    }
    else
    {
        printf("\nOpcion no valida, regresando a menu principal ");
        loading();
        puts("\n\n");
        repeatExercise = false;
    }
    return repeatExercise;
}

// main function
void main()
{
    int opcionSalir = 4;
    int exerciseSelection = 1;
    bool repeatExercise = true;
    char askForRepetition = 'y';

    // print greetings
    puts("**************************************");
    puts("Bienvenido");
    puts("**************************************");

    while (exerciseSelection != opcionSalir)
    {

        // print Menu
        puts("--------------------------------------");
        puts("Digita la opcion que deseas realizar:");
        puts("1.- ");
        puts("2.- ");
        puts("3.- ");
        puts("X.- Salir");
        puts("--------------------------------------");
        scanf("%d", &exerciseSelection);
        fflush(stdin);

        switch (exerciseSelection)
        {

        case 1:
            while (repeatExercise == true)
            {
                puts("Has seleccionado el ejercicio 1");
                // Start Coding

                // End of Code

                // Ask for confirmation
                puts("Para repetir el ejercicio digita ' y '. Para regresar al menu digita ' n '.");
                scanf("%c", &askForRepetition);
                fflush(stdin);
                repeatExercise = asking(askForRepetition, repeatExercise);
            }
            break;

        case 2:
            while (repeatExercise == true)
            {
                puts("Has seleccionado el ejercicio 2");
                // Start Coding

                // End of Code

                // Ask for confirmation
                puts("Para repetir el ejercicio digita ' y '. Para regresar al menu digita ' n '.");
                scanf("%c", &askForRepetition);
                fflush(stdin);
                repeatExercise = asking(askForRepetition, repeatExercise);
            }

            break;

        case 3:
            while (repeatExercise == true)
            {
                puts("Has seleccionado el ejercicio 3");
                // Start Coding

                // End of Code

                // Ask for confirmation
                puts("Para repetir el ejercicio digita ' y '. Para regresar al menu digita ' n '.");
                scanf("%c", &askForRepetition);
                fflush(stdin);
                repeatExercise = asking(askForRepetition, repeatExercise);
            }

            break;

        case 4:
            printf("\nSaliendo del programa ");
            loading();
            exit(0);
            break;

        default:
            puts("Opcion no valida");
            break;
        }
    }
}