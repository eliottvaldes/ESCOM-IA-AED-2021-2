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
        sleep(1 / 2);
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

/*
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
// creamos funcion swap para intercambio de valores
void swap(int *posj, int *posj1)
{
    int *posTemporal;

    free(posTemporal);

    posTemporal = malloc(2 * sizeof(int));

    *posTemporal = *posj;
    *posj = *posj1;
    *posj1 = *posTemporal;
}

// funcion para buscar el valor menor
int BuscaMenor(int *arrayNumerico, int tam, int inicio)
{
    int posicion, menor;

    menor = arrayNumerico[inicio];
    posicion = inicio;

    // recorremos lista buscando al elemento menor
    for (int i = (inicio + 1); i < tam; i++)
    {
        // comparamos si el dato en la pos i < menor
        if (arrayNumerico[i] < menor)
        {
            menor = arrayNumerico[i];
            posicion = i;
        }
    }

    return posicion;
}
*/

// main function
void main()
{

    // excersice variables
    int extensionDeArreglo = 0;
    int rangoDeArreglo = 0;
    int *arrayNumerico;
    bool showMenu = true;
    int valorTemporal;
    int temp;
    int j;

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
                repeatExercise = false;
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

                // mostramos mensaje
                puts("Iniciando ordenamiento burbuja ");
                loading();

                // comenzamos el ordenamiento burbuja
                // recorremos el arreglo
                for (int i = 0; i < extensionDeArreglo; i++)
                {
                    // recorremos los elementos x veces en el arreglo - i
                    for (int j = 0; j < (extensionDeArreglo - i); j++)
                    {
                        // hacemos la comparacion
                        if (arrayNumerico[j] > arrayNumerico[j + 1])
                        {
                            // hacemos el intercambio de valores
                            temp = arrayNumerico[j];
                            arrayNumerico[j] = arrayNumerico[j + 1];
                            arrayNumerico[j + 1] = temp;
                        }
                    }
                }
                // fin de ordenamiento burbuja

                puts("*** Ordenamiento completado ***\n");

                // End of Code
                repeatExercise = false;
            }

            break;

        case 4:
            while (repeatExercise == true)
            {
                puts("\nHas seleccionado ordenamiento por insercion\n");
                // Start Coding

                printf("Iniciando ordenamiento insercion ");
                loading();

                // iniciamos el ordenamiento por insercion
                for (int i = 0; i < extensionDeArreglo; i++)
                {

                    temp = arrayNumerico[i];
                    j = (i - 1);
                    while ((arrayNumerico[j] > temp) && (j >= 0))
                    {
                        arrayNumerico[j + 1] = arrayNumerico[j];
                        j--;
                    }
                    arrayNumerico[j + 1] = temp;
                }

                puts("*** Ordenamiento completado ***\n");
                // End of Code

                // Ask for confirmation
                repeatExercise = false;
            }

            break;

        case 5:
            while (repeatExercise == true)
            {
                puts("\nHas seleccionado ordenamiento por seleccion\n");
                // Start Coding

                printf("Iniciando ordenamiento seleccion ");
                loading();

                // iniciando algoritmo de ordenamiento por seleccion
                for (int i = 0; i < extensionDeArreglo; i++)
                {
                    int pos_menor = i;
                    // buscamos el valor menor
                    for (int j = i + 1; j < extensionDeArreglo; j++)
                    {
                        // comparamos el valor de la pos j  para ver si es menor
                        if (arrayNumerico[j] < arrayNumerico[pos_menor])
                        {
                            // cambiamos la pos_menor por el valor menor que es j
                            pos_menor = j;
                        }
                    }
                    // realizamos el cambio de valores
                    temp = arrayNumerico[pos_menor];
                    arrayNumerico[pos_menor] = arrayNumerico[i];
                    arrayNumerico[i] = temp;
                }

                // for (int i = 0; i < (extensionDeArreglo -1); i++)
                // {
                //     // obtenemos el dato menor de la lista desde el indice i
                //     int pos_menor = BuscaMenor(arrayNumerico, extensionDeArreglo, i);
                //     // intercambiamos datos
                //     temp = arrayNumerico[i];
                //     arrayNumerico[i] = pos_menor;
                //     arrayNumerico[pos_menor] = temp;

                // }

                puts("*** Ordenamiento completado ***\n");

                // End of Code

                // Ask for confirmation
                repeatExercise = false;
            }

            break;

        case 6:
            while (repeatExercise == true)
            {
                puts("\nHas seleccionado ordenamiento por merge\n");
                // Start Coding

                printf("Iniciando ordenamiento merge ");
                loading();

                // iniciamos codigo para el algoritmo de Merge

                puts("*** Ordenamiento completado ***\n");
                // End of Code

                // Ask for confirmation
                repeatExercise = false;
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