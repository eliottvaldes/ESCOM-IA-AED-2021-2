#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


// funcion para creacion de numeros aleatorios
int *generarArrayNumerosAleatorios(int extensionDeArreglo)
{

    int *arrayNumerico = malloc(extensionDeArreglo * sizeof(int));

    for (int i = 0; i <= extensionDeArreglo; i++)
    {
        // creamos numeros aleatorios  con rango de 200 a 500 y los vamos agregando al array
        arrayNumerico[i] = (rand() % (500 - 200)) + 200;
    }

    return arrayNumerico;
}

int *eliminarRepetidosDeArreglo(int *arrayNumerico, int extensionDeArreglo)
{

    int *arrayNumericoNoRepetidos = malloc(extensionDeArreglo * sizeof(int));

    int contador_eliminados = 0;
    int contador_agrgados = 0;

    // buscamos los no repetidos
    for (int i = 0; i < extensionDeArreglo; i++)
    {
        // usamos i>0 para evitar un error con el indice 0
        if (i > 0)
        {
            // verificamos si NO son iguales los numeros
            if (arrayNumerico[i - 1] != arrayNumerico[i])
            {
                // si NO coinciden los agregamos al nuevo arreglo
                // ponemos i-1 porque no inicia en 0, inicia en 1 la comparacion
                arrayNumericoNoRepetidos[contador_agrgados] = arrayNumerico[i];
                // incrementamos el contador de agregados
                contador_agrgados++;
            }
            else
            {
                contador_eliminados++;
            }
        }
        else
        {
            arrayNumericoNoRepetidos[contador_agrgados] = arrayNumerico[i];
            // incrementamos el contador de agregados
            contador_agrgados++;
        }
    }

    return arrayNumericoNoRepetidos;
}

int contadorDeRepetidos(int *arrayNumerico, int extensionDeArreglo)
{

    int contador_eliminados = 0;

    // buscamos los no repetidos
    for (int i = 0; i < extensionDeArreglo; i++)
    {
        // usamos i>0 para evitar un error con el indice 0
        // verificamos si NO son iguales los numeros
        if (arrayNumerico[i - 1] == arrayNumerico[i])
        {
            // incrementamos el contador de agregados
            contador_eliminados++;
        }
    }

    return contador_eliminados;
}

// funcion para ver los numeros aleatorios
void mostrarDatosEnArregloRepetidos(int *arrayNumerico, int extensionDeArreglo, int i)
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

// funcion para ver los numeros aleatorios
void mostrarDatosEnArregloNoRepetidos(int *arrayNumericoOrdenado, int extensionDeArreglo, int i)
{
    if (i == (extensionDeArreglo - 1))
    {
        printf("%d. \n\n", arrayNumericoOrdenado[i]);
    }
    else
    {
        printf("%d, ", arrayNumericoOrdenado[i]);
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
