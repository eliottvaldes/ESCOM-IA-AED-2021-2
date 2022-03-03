/**
 * @file busqueda.c
 * @author VALDES LUIS ELIOT FABIAN
 * @brief Programa que contiene algoritmos de busqueda
 * @version 0.1
 * @date 2022-03-02
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
void animacion()
{
    printf("[");
    for (int i = 0; i < 5; i++)
    {
        printf("#");
        sleep(1);
    }
    printf("]");
    puts("\n");
}

// CREAMOS PROTOTIPOS DE FUNCIONES
int *generarArrayNumerosAleatorios(int, int);
void mostrarDatosEnArreglo(int *, int, int);
void ordenamientoQuickSort(int *, int, int);
int busquedaSecuencial(int *, int, int);

// funcion para creacion de numeros aleatorios
int *generarArrayNumerosAleatorios(int extensionDeArreglo, int rangoDeArreglo)
{

    int *arrayNumerico = malloc(extensionDeArreglo * sizeof(int));

    for (int i = 0; i <= extensionDeArreglo; i++)
    {
        // creamos numeros aleatorios y los vamos agregando al array
        arrayNumerico[i] = rand() % rangoDeArreglo;
    }

    return arrayNumerico;
}

// funcion para ver los numeros aleatorios
void mostrarDatosEnArreglo(int *arrayNumerico, int extensionDeArreglo, int i)
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

// funcion para ordenamiento de Quick Sort
void ordenamientoQuickSort(int *arrayNumerico, int primerElemento, int ultimoElemento)
{
    // asignamos la posicion de inicio y la final con la que se va a iterar el ciclo
    int posicionInicio = primerElemento;
    int posicionFinal = ultimoElemento;
    // variable para intercambios
    int tmp;
    // variable para obtener el valor medio
    int valorIntermedio = arrayNumerico[(primerElemento + ultimoElemento) / 2];
    // usamos do-while para iniciar con una ejecucion antes de parar si es el caso
    do
    {
        // recorremos el numerico solo si el valor de la pos i es menor a x y el f es <= a final
        // f <= final se va a cumplir siempre en la primer iteracion
        while ((arrayNumerico[posicionInicio] < valorIntermedio) && (posicionFinal <= ultimoElemento))
        {
            // incrementamos el contador de inicio
            posicionInicio++;
        }
        while ((valorIntermedio < arrayNumerico[posicionFinal]) && (posicionFinal > primerElemento))
        {
            // decrementamos el contador de final
            posicionFinal--;
        }
        // hacemos la comparacion para intercambiar lso valores en caso de ser necesario
        if (posicionInicio <= posicionFinal)
        {
            // hacemos el intercambio SWAP
            tmp = arrayNumerico[posicionInicio];
            arrayNumerico[posicionInicio] = arrayNumerico[posicionFinal];
            arrayNumerico[posicionFinal] = tmp;
            // incrementamos inicio y decrementamos el final
            posicionInicio++;
            posicionFinal--;
        }
    } while (posicionInicio <= posicionFinal); // evaluamos el do para ver si se repite o no

    // hacemos la comparacion para ver que aprametros le pasamos a nuestra misma funcion
    if (primerElemento < posicionFinal)
    {
        // usamos la recursividad para que se siga ejecutando el ordenamiento cambiando la variable del final
        ordenamientoQuickSort(arrayNumerico, primerElemento, posicionFinal);
    }
    // hacemos la comparacion para ver que aprametros le pasamos a nuestra misma funcion
    if (posicionInicio < ultimoElemento)
    {
        // usamos la recursividad para que se siga ejecutando el ordenamiento cambiando la variable del inicio
        ordenamientoQuickSort(arrayNumerico, posicionInicio, ultimoElemento);
    }
}

// funcion para pedirle al usuario u numero a buscar
int pedirNumeroABuscar()
{

    int numeroABuscar = 0;

    // pedimos la cantidad de numeros en el array
    puts("Digita el numero que quieres buscar en el arreglo");
    fflush(stdin);
    scanf("%d", &numeroABuscar);
    fflush(stdin);
    puts("");

    return numeroABuscar;
}

// funcion para busqueda secuencial
int busquedaSecuencial(int *arrayNumerico, int extensionDeArreglo, int numeroABuscar)
{
    for (int i = 0; i < extensionDeArreglo; i++)
    {
        if (arrayNumerico[i] == numeroABuscar)
        {
            printf("Se ha encontrado el numero a buscar (%d) en la posicion [%d] del arreglo\n\n", arrayNumerico[i], i + 1);
            return 1;
        }
    }
    puts("El numero a buscar no se encontro dentro del arreglo numerico\n\n");
    return 0;
}

// funcion para busqueda Binaria
int busquedaBinaria(int *arrayNumerico, int extensionDeArreglo, int numeroABuscar)
{

    int inf = 0;
    int sup = (extensionDeArreglo - 1);
    while (inf <= sup)
    {
        // obtenemos el elemento central
        int centro = ((sup - inf) / 2) + inf;
        // si el elemento a buscar es el numero del centro lo mostramos y terminamos el ciclo
        if (arrayNumerico[centro] == numeroABuscar)
        {
            printf("Se ha encontrado el numero a buscar (%d) en la posicion [%d] del arreglo\n\n", arrayNumerico[centro], centro + 1);
            return 1;
        }
        else
        {
            if (numeroABuscar < arrayNumerico[centro])
            {
                sup = centro - 1;
            }
            else
            {
                inf = centro + 1;
            }
        }
    }

    puts("El numero a buscar no se encontro dentro del arreglo numerico\n\n");
    return 0;
}

// main function
void main()
{

    // excersice variables
    int extensionDeArreglo = 0;
    int rangoDeArreglo = 0;
    int *arrayNumerico;
    bool showMenu = true;
    int numeroABuscar = 0;

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
        puts("3.- Busqueda secuencial");
        puts("4.- Busqueda binaria");
        puts("5.- Salir");
        puts("--------------------------------------");
        fflush(stdin);
        scanf("%d", &exerciseSelection);

        switch (exerciseSelection)
        {
        case 1:

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
            fflush(stdin);

            // creamos semilla para generacion de numeros random
            // usamos srand(time()); para no obtener los mismos numeros aleatorios en cada ejecucion ya que la semilla es la hora actual
            srand(time(NULL));

            // mandamos a llamar a la funcion de crear numeros de datos aleatorios
            arrayNumerico = generarArrayNumerosAleatorios(extensionDeArreglo, rangoDeArreglo);

            // verificamos que ya haya creado un arreglo previamente para poder ordenarlo
            if (extensionDeArreglo > 0)
            {
                // ORDENAMOS EL ARREGLO DESDE EL INICIO USANDO QUICKSORT
                int primerElemento = 0;
                int ultimoElemento = extensionDeArreglo - 1;
                // ejecutamos funcion del ordenamiento quick sort
                ordenamientoQuickSort(arrayNumerico, primerElemento, ultimoElemento);
            }

            // mostramos mensaje de exito
            puts("\n*** Arreglo generado exitosamente ***\n");

            // End of Code

            break;

        case 2:

            puts("\nHas seleccionado la opcion de imprimir datos\n");
            // Start Coding

            // verificamos que el usuario ya haya creado un arredo de datos numericos aleatorios
            if (extensionDeArreglo > 0)
            {
                for (int i = 0; i < extensionDeArreglo; i++)
                {
                    mostrarDatosEnArreglo(arrayNumerico, extensionDeArreglo, i);
                }
            }
            else
            {
                puts("\n*** Aun no has generado un arreglo de numeros aleatorios *** \n");
            }

            // End of Code

            break;

        case 3:

            puts("\nHas seleccionado Busqueda Secuencial\n");
            // Start Coding

            // ejecutamos funcion para pedirle a usuario un nuemro
            numeroABuscar = pedirNumeroABuscar();

            // mostramos mensaje
            printf("Iniciando busqueda secuencial ");
            animacion();

            // ejecutamos la funcion para la busqueda secuencial
            busquedaSecuencial(arrayNumerico, extensionDeArreglo, numeroABuscar);

            puts("*** Busqueda completa ***\n");

            // End of Code

            break;

        case 4:

            puts("\nHas seleccionado Busqueda Binaria\n");
            // Start Coding

            // ejecutamos funcion para pedirle a usuario un nuemro
            numeroABuscar = pedirNumeroABuscar();

            printf("Iniciando busqueda binaria ");
            animacion();

            // ejecutamos la funcion para la busqueda binaria
            busquedaBinaria(arrayNumerico, extensionDeArreglo, numeroABuscar);

            puts("*** Busqueda completa ***\n");

            // End of Code

            break;

        case 5:
            printf("\nSaliendo del programa ");
            animacion();
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