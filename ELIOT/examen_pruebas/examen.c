/**
 * @file examen.c
 * @author VALDES LUIS ELIOT FABIAN
 * @brief aechivo que contiene examen practico de primer parcial de AED
 * @version 0.1
 * @date 2022-03-12
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <C:\Users\Eliot\Documents\ESCOM\2IV1\AED\AED-IA-ESCOM\ELIOT\examen\ejercicio1.h>

// CREAMOS PROTOTIPOS DE FUNCIONES
int time();
int *generarArrayNumerosAleatorios(int);
int *eliminarRepetidosDeArreglo(int *, int);
void mostrarDatosEnArregloRepetidos(int *, int, int);
void mostrarDatosEnArregloNoRepetidos(int *, int, int);
void ordenamientoQuickSort(int *, int, int);

// main function
void main()
{
    int opcionSalir = 4;
    int opcionSeleccionadaMenu;

    int extensionDeArreglo = 0;
    int *arrayNumerico;
    int *arrayNumericoNoRepetidos;
    int contador_eliminados;

    // print greetings
    puts("**************************************");
    puts("Bienvenido");
    puts("**************************************");

    do
    {
        opcionSeleccionadaMenu = 0;
        // print Menu
        puts("--------------------------------------");
        puts("Digita la opcion del ejercicio que deseas realizar:");
        puts("1.- Numeros aleatorios entre 200-500");
        puts("2.- OPx");
        puts("3.- OPx");
        puts("X.- Salir");
        puts("--------------------------------------");
        scanf("%d", &opcionSeleccionadaMenu);
        fflush(stdin);

        switch (opcionSeleccionadaMenu)
        {

        case 1:
            contador_eliminados = 0;
            puts("\n\t *** Has seleccionado la opcion de x ***\n ");
            // Start Coding
            puts("\nHas seleccionado la opcion de generar array de numeros aleatorios\n");
            // Start Coding

            // liberamos memoria del arreglo dinamico usando free
            free(arrayNumerico);
            free(arrayNumericoNoRepetidos);

            // pedimos la cantidad de numeros en el array
            puts("Digita la cantidad de numeros que quieres en el array");
            fflush(stdin);
            scanf("%d", &extensionDeArreglo);

            // creamos semilla para generacion de numeros random
            // usamos srand(time()); para no obtener los mismos numeros aleatorios en cada ejecucion ya que la semilla es la hora actual
            srand(time(NULL));

            // mandamos a llamar a la funcion de crear numeros de datos aleatorios
            arrayNumerico = generarArrayNumerosAleatorios(extensionDeArreglo);

            // ORDENAMOS EL ARREGLO DESDE EL INICIO USANDO QUICKSORT
            int primerElemento = 0;
            int ultimoElemento = extensionDeArreglo - 1;
            // ejecutamos funcion del ordenamiento quick sort
            ordenamientoQuickSort(arrayNumerico, primerElemento, ultimoElemento);
            // mandamos a llamar a la funcion eliminar los datos repetidos del array
            arrayNumericoNoRepetidos = eliminarRepetidosDeArreglo(arrayNumerico, extensionDeArreglo);
            contador_eliminados = contadorDeRepetidos(arrayNumerico, extensionDeArreglo);

            // Mostramos los arreglos obtenidos
            puts("\n*** El arreglo inicial es: ***\n");

            for (int i = 0; i < extensionDeArreglo; i++)
            {
                mostrarDatosEnArregloRepetidos(arrayNumerico, extensionDeArreglo, i);
            }

            puts("\n\n\n*** El arreglo sin repetidos es: ***\n");

            extensionDeArreglo = (extensionDeArreglo - contador_eliminados);
            for (int i = 0; i < extensionDeArreglo; i++)
            {
                mostrarDatosEnArregloNoRepetidos(arrayNumericoNoRepetidos, extensionDeArreglo, i);
            }

            printf("\nSe eliminaron %d elementos repetidos\n", contador_eliminados);

            puts("\n*** Fin ***\n");

            // End of Code

            break;
            // End of Code

        case 2:

            puts("\n\t *** Has seleccionado la opcion de xx ***\n ");
            // Start Coding

            // End of Code

            break;

        case 3:

            puts("\n\t *** Has seleccionado la opcion de xxx ***\n ");
            // Start Coding

            // End of Code

            break;

        case 4:
            printf("\nSALIENDO DEL PROGRAMA ");
            puts("\n *** ADIOS *** :)");
            exit(0);
            break;

        default:
            puts("Opcion no valida");
            break;
        }
    } while (opcionSeleccionadaMenu != opcionSalir);
}