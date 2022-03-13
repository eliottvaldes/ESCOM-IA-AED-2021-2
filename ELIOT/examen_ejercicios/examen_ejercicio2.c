/**
 * @file examen.c
 * @author VALDES LUIS ELIOT FABIAN
 * @brief archivo que contiene EJERCICIO 1 del examen practico de primer parcial de AED
 * @version 0.1
 * @date 2022-03-12
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int time();

// CREAMOS PROTOTIPOS DE FUNCIONES
int *generarArrayPalabrasAleatorios(int, int);
int *generarArrayIndices(int, int);
void mostrarDatosEnArreglo(int *, int, int);
bool verificarExistenciaDeArreglo(int);
void ordenamientoQuickSort(int *, int, int);
int busquedaSecuencial(int *, int, int);
int busquedaBinaria(int *, int, int);
int busquedaIndexada(int *, int *, int, int);

// funcion para creacion de palabras aleatorios
int *generarArrayPalabrasAleatorios(char archivo)
{

    int *arrayPalabras = malloc(500 * sizeof(int));

    int c, n = 0;
    FILE *ptrArchivo;

    if ((ptrArchivo = fopen(archivo, "rt")) == NULL)
    {
        puts("\nLo sentimos, no se puede abrir al archivo 'palabras.txt' por alguna razon.\n");
    }
    else
    {
        while ((c = fgetc(ptrArchivo)) != EOF)
        {
            if (c == '\n')
            {

                // agregamos al arreglo de palabras
                arrayPalabras[n] = archivo;

                n++;
                puts("\n");
            }
            else
            {
                putchar(c);
            }
        }

        printf("El archivo \'%s\' \n tiene %d lineas \n", archivo, n);
        fclose(ptrArchivo);
    }

  
    return arrayPalabras;
}

// int *generarArrayIndices(int extensionDeArreglo)
// {
//     int *arrayIndices = malloc(extensionDeArreglo * sizeof(int));

//     for (int i = 0; i <= extensionDeArreglo; i++)
//     {
//         // creamos palabras aleatorios y los vamos agregando al array
//         arrayIndices[i] = i;
//     }

//     return arrayIndices;
// }

// funcion para ver los palabras aleatorios
void mostrarDatosEnArreglo(int *arrayPalabras, int extensionDeArreglo, int i)
{
    if (i == (extensionDeArreglo - 1))
    {
        printf("%d. \n\n", arrayPalabras[i]);
    }
    else
    {
        printf("%d, ", arrayPalabras[i]);
    }
}

// funcion para verificar existencia de arreglo
bool verificarExistenciaDeArreglo(int extensionDeArreglo)
{
    if (extensionDeArreglo > 0)
    {
        return true;
    }
    else
    {
        puts("\n+-+-+-+ Aun no has generado un arreglo de palabras aleatorios. Genera uno para poder realizar la accion +-+-+-+ \n");
    }

    return false;
}

// funcion para ordenamiento de Quick Sort
void ordenamientoQuickSort(int *arrayPalabras, int primerElemento, int ultimoElemento)
{
    // asignamos la posicion de inicio y la final con la que se va a iterar el ciclo
    int posicionInicio = primerElemento;
    int posicionFinal = ultimoElemento;
    // variable para intercambios
    int tmp;
    // variable para obtener el valor medio
    int valorIntermedio = arrayPalabras[(primerElemento + ultimoElemento) / 2];
    // usamos do-while para iniciar con una ejecucion antes de parar si es el caso
    do
    {
        // recorremos el numerico solo si el valor de la pos i es menor a x y el f es <= a final
        // f <= final se va a cumplir siempre en la primer iteracion
        while ((arrayPalabras[posicionInicio] < valorIntermedio) && (posicionFinal <= ultimoElemento))
        {
            // incrementamos el contador de inicio
            posicionInicio++;
        }
        while ((valorIntermedio < arrayPalabras[posicionFinal]) && (posicionFinal > primerElemento))
        {
            // decrementamos el contador de final
            posicionFinal--;
        }
        // hacemos la comparacion para intercambiar lso valores en caso de ser necesario
        if (posicionInicio <= posicionFinal)
        {
            // hacemos el intercambio SWAP
            tmp = arrayPalabras[posicionInicio];
            arrayPalabras[posicionInicio] = arrayPalabras[posicionFinal];
            arrayPalabras[posicionFinal] = tmp;
            // incrementamos inicio y decrementamos el final
            posicionInicio++;
            posicionFinal--;
        }
    } while (posicionInicio <= posicionFinal); // evaluamos el do para ver si se repite o no

    // hacemos la comparacion para ver que aprametros le pasamos a nuestra misma funcion
    if (primerElemento < posicionFinal)
    {
        // usamos la recursividad para que se siga ejecutando el ordenamiento cambiando la variable del final
        ordenamientoQuickSort(arrayPalabras, primerElemento, posicionFinal);
    }
    // hacemos la comparacion para ver que aprametros le pasamos a nuestra misma funcion
    if (posicionInicio < ultimoElemento)
    {
        // usamos la recursividad para que se siga ejecutando el ordenamiento cambiando la variable del inicio
        ordenamientoQuickSort(arrayPalabras, posicionInicio, ultimoElemento);
    }
}

// funcion para pedirle al usuario u numero a buscar
int pedirNumeroABuscar()
{

    int numeroABuscar = 0;

    // pedimos la cantidad de palabras en el array
    puts("Digita el numero que quieres buscar en el arreglo: ");
    scanf("%d", &numeroABuscar);
    fflush(stdin);
    puts("");

    return numeroABuscar;
}

// funcion para busqueda secuencial
int busquedaSecuencial(int *arrayPalabras, int extensionDeArreglo, int numeroABuscar)
{
    for (int i = 0; i < extensionDeArreglo; i++)
    {
        if (arrayPalabras[i] == numeroABuscar)
        {
            printf("Se ha encontrado el valor a buscar (%d) en la posicion [%d] del arreglo\n\n", arrayPalabras[i], i + 1);
            return 1;
        }
    }
    puts("El valor a buscar no se encontro dentro del arreglo numerico\n\n");
    return 0;
}

// funcion para busqueda Binaria
int busquedaBinaria(int *arrayPalabras, int extensionDeArreglo, int numeroABuscar)
{

    int inf = 0;
    int sup = (extensionDeArreglo - 1);
    while (inf <= sup)
    {
        // obtenemos el elemento central
        int centro = ((sup - inf) / 2) + inf;
        // si el elemento a buscar es el numero del centro lo mostramos y terminamos el ciclo
        if (arrayPalabras[centro] == numeroABuscar)
        {
            printf("Se ha encontrado el valor a buscar (%d) en la posicion [%d] del arreglo\n\n", arrayPalabras[centro], centro + 1);
            return 1;
        }
        else
        {
            if (numeroABuscar < arrayPalabras[centro])
            {
                sup = centro - 1;
            }
            else
            {
                inf = centro + 1;
            }
        }
    }

    puts("El valor a buscar no se encontro dentro del arreglo numerico\n\n");
    return 0;
}

// funcion para Busqueda Indexada
int busquedaIndexada(int *arrayPalabras, int *arrayIndices, int extensionDeArreglo, int numeroABuscar)
{
    int posEnArray, numAuxiliar = 0;
    int indiceInicial = 0, inicioBusqueda, finBusqueda;
    bool esNumeroEnArreglo = false;

    // en caso de que el numero a buscar sea menor que el de la pos[o] del array mostramos que no se encontro y nos evitamos buscar
    if (numeroABuscar < arrayPalabras[0])
    {
        puts("El valor a buscar no se encontro dentro del arreglo numerico\n\n");
        return 0;
    }
    else
    {
        for (posEnArray = 1; posEnArray <= indiceInicial; posEnArray++)
            if (numeroABuscar <= arrayPalabras[posEnArray])
            {
                inicioBusqueda = arrayIndices[posEnArray - 1];
                finBusqueda = arrayIndices[posEnArray];
                numAuxiliar = 1;
                break;
            }
    }
    // en caso de que no haya coincidencia reasignados el inicio y final de la busqueda
    if (numAuxiliar == 0)
    {
        inicioBusqueda = arrayIndices[posEnArray - 1];
        finBusqueda = extensionDeArreglo;
    }
    // volvemos a  hacer la busqueda con los valores reasignados
    for (posEnArray = inicioBusqueda; posEnArray <= finBusqueda; posEnArray++)
    {
        // verificamos coincidencia
        if (numeroABuscar == arrayPalabras[posEnArray])
        {
            esNumeroEnArreglo = true;
            break;
        }
    }
    // volvemos a verificar si el numero se ha encontrado
    if (esNumeroEnArreglo == true)
    {
        printf("Se ha encontrado el valor a buscar (%d) en la posicion [%d] del arreglo\n\n", numeroABuscar, posEnArray);
    }
    else
    {
        puts("El valor a buscar no se encontro dentro del arreglo numerico\n\n");
    }
}

// main function
void main()
{

    // variables de ejercicio
    int extensionDeArreglo = 0;
    int rangoDeArreglo = 0;
    int *arrayPalabras;
    int *arrayIndices;
    int numeroABuscar = 0;
    bool esArregloExistente;

    int c, n;
    FILE *ptrArchivo;
    char archivo[500] = "palabras.txt";

    // variables de menu
    int opcionSeleccionMenu;
    bool mostrarMenu = true;

    // print greetings
    puts("**************************************");
    puts("Bienvenido");
    puts("**************************************");
    do
    {
        opcionSeleccionMenu = 0;
        // show Menu
        puts("--------------------------------------");
        puts("Digita la opcion que deseas realizar:");
        puts("1.- Obtener palabras del archivo palabras.txt");
        puts("2.- Ver palabras en archivo palabras.txt");
        puts("3.- Busqueda secuencial");
        puts("4.- Busqueda binaria");
        puts("5.- Busqueda indexada");
        puts("6.- Salir");
        puts("--------------------------------------");
        scanf("%d", &opcionSeleccionMenu);
        fflush(stdin);

        switch (opcionSeleccionMenu)
        {
        case 1:

            puts("\n\t*** Has seleccionado la opcion de generar array de palabras aleatorios ***\n");

            arrayPalabras = generarArrayPalabrasAleatorios(archivo);
            // Start Coding

            // if ((ptrArchivo = fopen(archivo, "rt")) == NULL)
            // {
            //     puts("\nLo sentimos, no se puede abrir al archivo 'palabras.txt' por alguna razon.\n");
            // }
            // else
            // {
            //     while ((c = fgetc(ptrArchivo)) != EOF)
            //     {
            //         if (c == '\n')
            //         {
            //             n++;
            //             puts("\n");
            //         }
            //         else
            //         {
            //             putchar(c);
            //         }
            //     }

            //     printf("El archivo \'%s\' \n tiene %d lineas \n", archivo, n);
            //     fclose(ptrArchivo);
            // }

            // puts("\n*** Se obtuvieron las palabras exitosamente ***\n");

            // // liberamos memoria del arreglo dinamico usando free
            // free(arrayPalabras);

            // // pedimos la cantidad de palabras en el array
            // puts("Digita la cantidad de palabras que hay en el archivo: ");
            // scanf("%d", &extensionDeArreglo);
            // fflush(stdin);

            // // mandamos a llamar a la funcion de crear palabras de datos aleatorios
            arrayPalabras = generarArrayPalabrasAleatorios(extensionDeArreglo);

            // // mandamos a llamar a la funcion para crear el arreglo de indices del array numerico
            // arrayIndices = generarArrayIndices(extensionDeArreglo, rangoDeArreglo);

            // // verificamos que ya haya creado un arreglo previamente para poder ordenarlo
            // if (extensionDeArreglo > 0)
            // {
            //     // ORDENAMOS EL ARREGLO DESDE EL INICIO USANDO QUICKSORT
            //     int primerElemento = 0;
            //     int ultimoElemento = extensionDeArreglo - 1;
            //     // ejecutamos funcion del ordenamiento quick sort
            //     ordenamientoQuickSort(arrayPalabras, primerElemento, ultimoElemento);
            // }

            // End of Code

            break;

        case 2:

            // Start Coding

            // verificamos que el usuario ya haya creado un arredo de datos numericos aleatorios
            esArregloExistente = verificarExistenciaDeArreglo(extensionDeArreglo);
            if (esArregloExistente == true)
            {
                // mostramos mensaje de opcion
                puts("\n\t*** Has seleccionado la opcion de imprimir datos ***\n");

                puts("El array numerico aleatorio tiene los siguientes datos:\n");

                // ciclo para imprimir los valores del array
                for (int i = 0; i < extensionDeArreglo; i++)
                {
                    mostrarDatosEnArreglo(arrayPalabras, extensionDeArreglo, i);
                }
            }

            // End of Code

            break;

        case 3:

            // Start Coding

            // verificamos que el usuario ya haya creado un arredo de datos numericos aleatorios
            esArregloExistente = verificarExistenciaDeArreglo(extensionDeArreglo);
            if (esArregloExistente == true)
            {
                // mostramos mensaje de opcion
                puts("\n\t*** Has seleccionado Busqueda Secuencial ***\n");

                // ejecutamos funcion para pedirle a usuario un nuemro
                numeroABuscar = pedirNumeroABuscar();

                // ejecutamos la funcion para la busqueda secuencial
                busquedaSecuencial(arrayPalabras, extensionDeArreglo, numeroABuscar);

                puts("*** Busqueda completa ***\n");
            }
            // End of Code

            break;

        case 4:

            // Start Coding

            // verificamos que el usuario ya haya creado un arredo de datos numericos aleatorios
            esArregloExistente = verificarExistenciaDeArreglo(extensionDeArreglo);
            if (esArregloExistente == true)
            {
                // mostramos mensaje de opcion
                puts("\n\t*** Has seleccionado Busqueda Binaria ***\n");

                // ejecutamos funcion para pedirle a usuario un nuemro
                numeroABuscar = pedirNumeroABuscar();

                // ejecutamos la funcion para la busqueda binaria
                busquedaBinaria(arrayPalabras, extensionDeArreglo, numeroABuscar);

                puts("*** Busqueda completa ***\n");
            }

            // End of Code

            break;
        case 5:

            // Start Coding

            // verificamos que el usuario ya haya creado un arredo de datos numericos aleatorios
            esArregloExistente = verificarExistenciaDeArreglo(extensionDeArreglo);
            if (esArregloExistente == true)
            {
                // mostramos mensaje de opcion
                puts("\n\t*** Has seleccionado Busqueda Indexada ***\n");

                // ejecutamos funcion para pedirle a usuario un nuemro
                numeroABuscar = pedirNumeroABuscar();

                // ejecutamos la funcion para la busqueda binaria
                busquedaIndexada(arrayPalabras, arrayIndices, extensionDeArreglo, numeroABuscar);

                puts("*** Busqueda completa ***\n");
            }

            // End of Code

            break;

        case 6:
            printf("\nSALIENDO DEL PROGRAMA ");
            puts("\n *** ADIOS *** :)");
            mostrarMenu = false;
            break;

        default:
            puts("Opcion no valida");
            break;
        }
    } while (mostrarMenu == true);
}