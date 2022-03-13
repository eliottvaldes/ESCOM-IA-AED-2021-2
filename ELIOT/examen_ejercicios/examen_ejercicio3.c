/**
 * @file examen.c
 * @author VALDES LUIS ELIOT FABIAN
 * @brief archivo que contiene EJERCICIO 3 del examen practico de primer parcial de AED
 * @version 0.1
 * @date 2022-03-12
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// creamos nuestras estructuras

typedef struct
{
    char apellidoPaterno[20];
    char apellidoMaterno[20];
    char nombre[20];
} AUTOR;

typedef struct
{
    char dia;
    char mes[12];
    char anio;
} FECHA;

typedef struct
{
    AUTOR libro;
    FECHA fechaPublicacion;
    char nombre[20];
    char editorial[20];
} LIBRO;

// CREAMOS PROTOTIPOS DE FUNCIONES
LIBRO registrarNuevoLibro();
void ordenarDatos(int *, int);

// funcion para registrar libro en estructura
LIBRO registrarNuevoLibro()
{
    LIBRO nuevo;
    // pedimos los datos
    puts("\n *** Digita los daots del libro a registrar *** \n");
    puts("Titulo");
    scanf("%s", &nuevo.nombre);
    fflush(stdin);
    puts("Nombre del Autor");
    scanf("%s", &nuevo.libro.nombre);
    fflush(stdin);
    puts("Apellido paterno del autor");
    scanf("%s", &nuevo.libro.apellidoPaterno);
    puts("Apellido materno del autor");
    scanf("%s", &nuevo.libro.apellidoMaterno);
    fflush(stdin);
    puts("Editorial");
    scanf("%s", &nuevo.editorial);
    fflush(stdin);
    puts("Dia de publicacion");
    scanf("%d", &nuevo.fechaPublicacion.dia);
    fflush(stdin);
    puts("Mes de publicacion");
    scanf("%s", &nuevo.fechaPublicacion.mes);
    fflush(stdin);
    puts("Anio de publicacion");
    scanf("%d", &nuevo.fechaPublicacion.anio);

    // regresamos los datos guardados en el nuevo libro
    return nuevo;
}

// main function
void main()
{

    // variables de menu
    int opcionSalir = 3;
    int opcionSeleccionMenu;
    int contadorDeEstructuras = 0;

    int opcionMenu;
    int cantidadDeLibros = 0;
    LIBRO id[500];

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
        puts("3.- Salir");
        puts("--------------------------------------");
        scanf("%d", &opcionSeleccionMenu);
        fflush(stdin);

        switch (opcionSeleccionMenu)
        {

        case 1:

            puts("\n\t *** Has seleccionado la opcion para registrar datos en estructura ***\n ");

            // Start Coding

            id[cantidadDeLibros] = registrarNuevoLibro(cantidadDeLibros);
            cantidadDeLibros++;

            // End of Code

            break;

        case 2:

            puts("\n\t *** Has seleccionado la opcion para mostrar los datos de la estructura ***\n ");
            // Start Coding
            puts("El ultimo libro que se ha registrado es:");
            printf("\n\tLibro: %d\n", id[cantidadDeLibros - 1].nombre);
            printf("\n\tAutor: %s %s %s", id[cantidadDeLibros - 1].libro.nombre, id[cantidadDeLibros - 1].libro.apellidoPaterno, id[cantidadDeLibros - 1].libro.apellidoMaterno);
            printf("\n\tEditorial: %s\n", id[cantidadDeLibros - 1].editorial);
            printf("\n\tPublicado el: %s / %s / %s\n", id[cantidadDeLibros - 1].fechaPublicacion.dia, id[cantidadDeLibros - 1].fechaPublicacion.mes, id[cantidadDeLibros - 1].fechaPublicacion.anio);

            break;
            // End of Code

            break;

        case 3:
            printf("\nSALIENDO DEL PROGRAMA ");
            puts("\n\n *** ADIOS *** :)\n ");
            exit(0);
            break;

        default:
            puts("Opcion no valida");
            break;
        }
    } while (opcionSeleccionMenu != opcionSalir);
}
