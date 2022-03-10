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

// creamos nuestras estructuras
typedef struct infoDireccion
{
    char calle[40];
    char numero[5];
    char estado[40];
    char codigoPostal[6];

} Direccion;

// estructura general
typedef struct infousuario
{
    char nombre[40];
    char apellido[40];
    char telefono[15];
    Direccion dir;
} Usuario;

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

// CREAMOS PROTOTIPOS DE FUNCIONES
// void registrarUsuario(Usuario *usr);
// void mostrarUsuario(Usuario usr);

void registrarUsuario(Usuario *usr, int contadorDeEstructuras)
{
    // Obtenemos los datos del usuario
    puts("\tIngresa los datos del usuario =>");
    puts("\n---------------------------------------------\n");
    puts("Nombre: ");
    fgets(usr->nombre, sizeof(usr->nombre), stdin);
    puts("Apellido: ");
    fgets(usr->apellido, sizeof(usr->apellido), stdin);
    puts("Telefono: ");
    fgets(usr->telefono, sizeof(usr->telefono), stdin);
    puts("Direccion calle: ");
    fgets(usr->dir.calle, sizeof(usr->dir.calle), stdin);
    puts("Direccion numero: ");
    fgets(usr->dir.numero, sizeof(usr->dir.numero), stdin);
    puts("Direccion estado: ");
    fgets(usr->dir.estado, sizeof(usr->dir.estado), stdin);
    puts("Direccion codigo postal: ");
    fgets(usr->dir.codigoPostal, sizeof(usr->dir.codigoPostal), stdin);
    puts("\n---------------------------------------------\n");    
};

void mostrarUsuario(Usuario usr, int contadorDeEstructuras)
{
    for (int i = 0; i < contadorDeEstructuras; i++)
    {
        printf("\nNombre: \t %s", usr.nombre);
        printf("\nApellido: \t %s", usr.apellido);
        printf("\nTelefono: \t %s", usr.telefono);
        printf("\nDireccion calle: \t %s", usr.dir.calle);
        printf("\nDireccion numero: \t %s", usr.dir.numero);
        printf("\nDireccion estado: \t %s", usr.dir.estado);
        printf("\nDireccion codigo postal: \t %s", usr.dir.codigoPostal);
        puts("\n---------------------------------------------\n");
    }
}

// main function
void main()
{

    Usuario *usr = (Usuario*)malloc(50 * sizeof(Usuario));

    // variables de menu
    int opcionSalir = 3;
    int opcionSeleccionMenu;
    int contadorDeEstructuras = 0;

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

            registrarUsuario(usr, contadorDeEstructuras);
            contadorDeEstructuras++;
            // printf("\n\n\tHay %d Estructuras \n\n", contadorDeEstructuras);
            // End of Code

            break;

        case 2:

            puts("\n\t *** Has seleccionado la opcion para mostrar los datos de la estructura ***\n ");
            // Start Coding
            mostrarUsuario(*usr, contadorDeEstructuras);
            // End of Code

            break;

        case 3:
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

    free(usr);
}
