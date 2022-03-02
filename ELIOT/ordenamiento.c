/**
 * @file ordenamiento.c
 * @author VALDES LUIS ELIOT FABIÁN
 * @brief Archivo con algoritmos de ordenamiento
 * @version 0.1
 * @date 2022-02-27
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// print animation
int sleep();
int time();
int loading()
{
    int i;
    for (int i = 0; i < 3; i++)
    {
        printf(".");
        sleep(1);
    }
    puts("\n");
    return 0;
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

// CREAMOS PROTOTIPOS DE FUNCIONES
// generarArrayNumerosAleatorios(int, int, int);
// mostrarDatosEnArreglo(int, int);

// create random data in array
int generarArrayNumerosAleatorios(int **arrayNumerico, int extensionDeArreglo, int rangoDeArreglo)
{

    *arrayNumerico = malloc(extensionDeArreglo * sizeof(int));

    for (int i = 0; i <= extensionDeArreglo; i++)
    {
        // creamos numeros aleatorios y los vamos agregando al array
        *arrayNumerico[i] = rand() % rangoDeArreglo;
    }
}

// creamos funcion para ver los numeros aleatorios
int mostrarDatosEnArreglo(int **arrayNumerico, int extensionDeArreglo)
{
    puts("Direccion de memoria del puntero en funcion");
    printf("%p", *arrayNumerico);
    puts("");
    // si la extension es mayor que 0 significa que ya ha generado un array numerico y lo mostramos
    if (extensionDeArreglo > 0)
    {
        printf("El arreglo tiene %d elementos\n", extensionDeArreglo);

        // imprimimos los elementos del arreglo
        for (int i = 0; i < extensionDeArreglo; i++)
        {
            printf("pos %d: %d \n", i, *arrayNumerico[i]);
        }
    }
    else
    {
        puts("Aun no has generado un array aleatorio");
    }
}

// main function
void main()
{

    // excersice variables
    int extensionDeArreglo = 0;
    int rangoDeArreglo = 0;
    int *arrayNumerico;

    bool showMenu = true;
    // print greetings
    puts("**************************************");
    puts("Bienvenido");
    puts("**************************************");
    while (showMenu == true)
    {
        // menu variables
        bool repeatExercise = true;
        char askForRepetition;
        int exerciseSelection;

        // show Menu
        puts("--------------------------------------");
        puts("Digita la opcion que deseas realizar:");
        puts("1.- Generar array de numeros aleatorios");
        puts("2.- Imprimir datos");
        puts("3.- Ordenamiento por Burbuja");
        puts("4.- Ordenamiento por Insercion");
        puts("5.- Ordenamiento por Seleccion");
        puts("6.- Ordenamiento por Merge");
        puts("7.- Ordenamiento por Quick Sort");
        puts("8.- Salir");
        puts("--------------------------------------");
        fflush(stdin);
        scanf("%d", &exerciseSelection);

        switch (exerciseSelection)
        {
        case 1:
            while (repeatExercise == true)
            {
                puts("\nHas seleccionado la opcion de generar array de numeros aleatorios\n");
                // Start Coding

                // liberamos memoria del arreglo dinamico usando free
                free(arrayNumerico);

                // pedimos la cantidad de numeros en el array
                puts("Digita la cantidad de numeros que quieres en el array");
                fflush(stdin);
                scanf("%d", &extensionDeArreglo);

                // pedimos el rango para la generacion de numeros aleatorios
                puts("Digita el rango superior para los numeros del arreglo");
                fflush(stdin);
                scanf("%d", &rangoDeArreglo);

                // creamos semilla para generacion de numeros random
                // usamos srand(time()); para no obtener los mismos numeros aleatorios en cada ejecucion ya que la semilla es la hora actual
                srand(time(NULL));

                // mandamos a llamar a la funcion de crear numeros de datos aleatorios
                // generarArrayNumerosAleatorios(&arrayNumerico, extensionDeArreglo, rangoDeArreglo);
                arrayNumerico = malloc(extensionDeArreglo * sizeof(int));

                for (int i = 0; i <= extensionDeArreglo; i++)
                {
                    // creamos numeros aleatorios y los vamos agregando al array
                    arrayNumerico[i] = rand() % rangoDeArreglo;
                }

                puts("\n*** Arreglo generado exitosamente ***\n");

                // End of Code

                // Ask for confirmation
                puts("Para repetir el ejercicio digita ' y '. Para regresar al menu digita ' n '.");
                fflush(stdin);
                scanf("%c", &askForRepetition);
                repeatExercise = asking(askForRepetition, repeatExercise);
            }
            break;

        case 2:
            while (repeatExercise == true)
            {
                puts("\nHas seleccionado la opcion de imprimir datos\n");
                // Start Coding

                // ------------------------------------------------------------------
                // FORMA PARA IMPRIMIR EL ARREGLO CON UNA FUNCION APARTE
                // ------------------------------------------------------------------
                // mandamos a llamar a la funcion para mostar los datos del areglo
                // puts("Direccion de memoria del puntero GENERAL  ");
                // printf("%p", arrayNumerico);
                // puts("");
                // mostrarDatosEnArreglo(&arrayNumerico, extensionDeArreglo);

                // ------------------------------------------------------------------
                // FORMA PARA IMPRIMIR EL ARREGLO DESDE ESTE BLOQUE DE CODIGO EN EL CASE 2
                // ------------------------------------------------------------------
                // verificamos que ya existan elementos en el array numerico
                if (extensionDeArreglo > 0)
                {
                    // imprimimos los elementos del arreglo
                    for (int i = 0; i < extensionDeArreglo; i++)
                    {
                        if (i == (extensionDeArreglo - 1))
                        {
                            printf("%d. \n\n", arrayNumerico[i]);
                        }
                        else
                        {
                            printf("%d, ", arrayNumerico[i]);
                        }
                        // printf("-%p-", arrayNumerico[i]);
                        // printf(" DIR/%p/\n", arrayNumerico);
                    }
                }
                else
                {
                    puts("\n*** Aun no has generado un arreglo de numeros aleatorios *** \n");
                }

                // End of Code

                // no preguntamos para repetir el ejercicio
                repeatExercise = false;
            }

            break;

        case 3:
            while (repeatExercise == true)
            {
                puts("\nHas seleccionado ordenamiento por burbuja\n");
                // Start Coding

                // comenzamos el ordenamiento
                printf("Iniciando ordenamiento burbuja ");
                loading();
                puts("*** Ordenamiento completado ***\n");

                // End of Code

                // Ask for confirmation
                puts("Para repetir el ejercicio digita ' y '. Para regresar al menu digita ' n '.");
                fflush(stdin);
                scanf("%c", &askForRepetition);
                repeatExercise = asking(askForRepetition, repeatExercise);
            }

            break;

        case 4:
            while (repeatExercise == true)
            {
                puts("\nHas seleccionado ordenamiento por insercion\n");
                // Start Coding

                printf("Iniciando ordenamiento burbuja ");
                loading();
                puts("*** Ordenamiento completado ***\n");
                // End of Code

                // Ask for confirmation
                puts("Para repetir el ejercicio digita ' y '. Para regresar al menu digita ' n '.");
                fflush(stdin);
                scanf("%c", &askForRepetition);
                repeatExercise = asking(askForRepetition, repeatExercise);
            }

            break;

        case 5:
            while (repeatExercise == true)
            {
                puts("\nHas seleccionado ordenamiento por seleccion\n");
                // Start Coding

                printf("Iniciando ordenamiento burbuja ");
                loading();
                puts("*** Ordenamiento completado ***\n");

                // End of Code

                // Ask for confirmation
                puts("Para repetir el ejercicio digita ' y '. Para regresar al menu digita ' n '.");
                fflush(stdin);
                scanf("%c", &askForRepetition);
                repeatExercise = asking(askForRepetition, repeatExercise);
            }

            break;

        case 6:
            while (repeatExercise == true)
            {
                puts("\nHas seleccionado ordenamiento por merge\n");
                // Start Coding

                printf("Iniciando ordenamiento burbuja ");
                loading();
                puts("*** Ordenamiento completado ***\n");
                // End of Code

                // Ask for confirmation
                puts("Para repetir el ejercicio digita ' y '. Para regresar al menu digita ' n '.");
                fflush(stdin);
                scanf("%c", &askForRepetition);
                repeatExercise = asking(askForRepetition, repeatExercise);
            }

            break;

        case 7:
            while (repeatExercise == true)
            {
                puts("\nHas seleccionado ordenamiento por quick sort\n");
                // Start Coding

                printf("Iniciando ordenamiento burbuja ");
                loading();
                puts("*** Ordenamiento completado ***\n");

                // End of Code

                // Ask for confirmation
                puts("Para repetir el ejercicio digita ' y '. Para regresar al menu digita ' n '.");
                fflush(stdin);
                scanf("%c", &askForRepetition);
                repeatExercise = asking(askForRepetition, repeatExercise);
            }

            break;

        case 8:
            printf("\nSaliendo del programa ");
            loading();
            puts("\n *** ADIOS *** :)");
            showMenu = false;
            break;

        default:
            puts("Opcion no valida");
            showMenu = true;
            exerciseSelection = 0;
            break;
        }
    }
}