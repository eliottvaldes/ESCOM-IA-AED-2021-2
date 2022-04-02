// // #include <stdio.h>
// // int main(int argc, char **argv)
// // {
// //     typedef struct
// //     {
// //         char *firstName;
// //         char *lastName;
// //         int rollNumber;

// //     } STUDENT;

// //     int numStudents = 2;
// //     int x;
// //     STUDENT *students = malloc(numStudents * sizeof *students);

// //     for (x = 0; x < numStudents; x++)
// //     {
// //         students[x].firstName = (char *)malloc(sizeof(char *));

// //         printf("Enter first name :");
// //         scanf("%s", students[x].firstName);
// //         students[x].lastName = (char *)malloc(sizeof(char *));
// //         printf("Enter last name :");
// //         scanf("%s", students[x].lastName);
// //         printf("Enter roll number  :");
// //         scanf("%d", &students[x].rollNumber);
// //     }

// //     for (x = 0; x < numStudents; x++)
// //         printf("First Name: %s, Last Name: %s, Roll number: %d\n", students[x].firstName, students[x].lastName, students[x].rollNumber);

// //     return (0);
// // }

// /**
//  * @file menu sin repeticion con repeticion interna en cada ejercicio
//  * @author VALDES LUIS ELIOT FABIAN
//  * @brief plantilla de codigo de menu para ejercicios con repeticion interna
//  * @version 0.1
//  * @date 2022-03-03
//  *
//  * @copyright Copyright (c) 2022
//  *
//  */

// #include <stdio.h>
// #include <stdbool.h>
// #include <stdlib.h>

// // print animation
// int sleep();
// void loading()
// {
//     printf("[");
//     for (int i = 0; i < 3; i++)
//     {
//         printf("#");
//         // usar si no se quiere mostrar la animacion
//         // sleep(1 / 2);
//         sleep(1);
//     }
//     printf("]");
// }
// // ask for confirmation
// bool asking()
// {

//     char askForRepetition = 'y';
//     bool esRepetido = true;

//     puts("\nPara repetir el ejercicio digita ' y '. Para regresar al menu digita ' n '.");
//     scanf("%c", &askForRepetition);
//     fflush(stdin);

//     if (askForRepetition == 'y')
//     {
//         esRepetido = true;
//     }
//     else if (askForRepetition == 'n')
//     {
//         esRepetido = false;
//     }
//     else
//     {
//         printf("\nOpcion no valida, regresando a menu principal ");
//         loading();
//         puts("\n\n");
//         esRepetido = false;
//     }
//     return esRepetido;
// }

// typedef struct
// {
//     char *firstName;
//     char *lastName;
//     int rollNumber;

// } STUDENT;

// typedef struct
// {
//     char *calle[40];
//     char *numero[5];
//     char *estado[40];
//     char *codigoPostal[6];

// } DIRECCION;

// // estructura genera
// typedef struct
// {
//     char *nombre[40];
//     char *apellido[40];
//     char *telefono[15];
//     DIRECCION *direccion;
// } USUARIO;

// int registrarUsuario(USUARIO *usr, int contadorDeEstructuras)
// {
//     puts("\tIngresa los datos del usuario =>");
//     puts("\n---------------------------------------------\n");
//     puts("Nombre: ");
//     scanf("%s", usr[contadorDeEstructuras].nombre);
//     puts("Apellido: ");
//     scanf("%s", usr[contadorDeEstructuras].apellido);
//     puts("Telefono: ");
//     scanf("%s", usr[contadorDeEstructuras].telefono);
//     puts("Direccion calle: ");
//     scanf("%s", usr[contadorDeEstructuras].direccion->calle);
//     puts("Direccion numero: ");
//     scanf("%s", usr[contadorDeEstructuras].direccion->numero);
//     puts("Direccion estado: ");
//     scanf("%s", usr[contadorDeEstructuras].direccion->estado);
//     puts("Direccion codigo postal: ");
//     scanf("%s", usr[contadorDeEstructuras].direccion->codigoPostal);
//     puts("\n---------------------------------------------\n");

//     return contadorDeEstructuras++;
// };

// void mostrarDatos(USUARIO *usr, int contadorDeEstructuras)
// {
//     for (int i = 0; i < contadorDeEstructuras; i++)
//     {

//         printf("\nNombre: \t %s", usr[contadorDeEstructuras].nombre);
//         printf("\nApellido: \t %s", usr[contadorDeEstructuras].apellido);
//         printf("\nTelefono: \t %s", usr[contadorDeEstructuras].telefono);
//         printf("\nDireccion calle: \t %s", usr[contadorDeEstructuras].direccion->calle);
//         printf("\nDireccion numero: \t %s", usr[contadorDeEstructuras].direccion->numero);
//         printf("\nDireccion estado: \t %s", usr[contadorDeEstructuras].direccion->estado);
//         printf("\nDireccion codigo postal: \t %s", usr[contadorDeEstructuras].direccion->codigoPostal);
//         puts("\n---------------------------------------------\n");
//     }
// }

// // main function
// void main()
// {
//     int opcionSalir = 4;
//     int opcionSeleccionadaMenu;
//     bool esEjercicioRepetido;

//     int contadorDeEstructuras = 0;
//     int y;
//     USUARIO *usr = malloc(50 * (sizeof *usr));

//     // print greetings
//     puts("**************************************");
//     puts("Bienvenido");
//     puts("**************************************");

//     do
//     {
//         opcionSeleccionadaMenu = 0;
//         esEjercicioRepetido = true;
//         // print Menu
//         puts("--------------------------------------");
//         puts("Digita la opcion que deseas realizar:");
//         puts("1.- registrar");
//         puts("2.- ver");
//         puts("3.- OPx");
//         puts("4.- Salir");
//         puts("--------------------------------------");
//         scanf("%d", &opcionSeleccionadaMenu);
//         fflush(stdin);

//         switch (opcionSeleccionadaMenu)
//         {

//         case 1:
//             while (esEjercicioRepetido == true)
//             {
//                 puts("\n\t *** Has seleccionado la opcion de x ***\n ");
//                 // Start Coding
//                 // int cantidadEstructuras = 50;

//                 contadorDeEstructuras = registrarUsuario(usr, contadorDeEstructuras);

//                 // End of Code

//                 // Ask for confirmation
//                 esEjercicioRepetido = asking();
//             }
//             break;

//         case 2:
//             while (esEjercicioRepetido == true)
//             {
//                 puts("\n\t *** Has seleccionado la opcion de xx ***\n ");
//                 // Start Coding
//                 mostrarDatos(usr, contadorDeEstructuras);
//                 // End of Code

//                 // Ask for confirmation
//                 esEjercicioRepetido = asking();
//             }

//             break;

//         case 3:
//             while (esEjercicioRepetido == true)
//             {
//                 puts("\n\t *** Has seleccionado la opcion de xxx ***\n ");
//                 // Start Coding

//                 // End of Code

//                 // Ask for confirmation
//                 esEjercicioRepetido = asking();
//             }

//             break;

//         case 4:
//             printf("\nSaliendo del programa :)");
//             loading();
//             exit(0);
//             break;

//         default:
//             puts("Opcion no valida");
//             break;
//         }
//     } while (opcionSeleccionadaMenu != opcionSalir);
// }

// C program for Indexed Sequential Search
#include <stdio.h>
#include <stdlib.h>

void busquedaIndexada(int arregloNumerico[], int n, int numeroABuscar)
{
    int arrayNumerico[20], indices[20], temp, i, set = 0;
    int j = 0, ind = 0, start, end;
    for (i = 0; i < n; i += 3)
    {

        // Storing element
        arrayNumerico[ind] = arregloNumerico[i];

        // Storing the index
        indices[ind] = i;
        ind++;
    }
    if (numeroABuscar < arrayNumerico[0])
    {
        printf("Not found");
        exit(0);
    }
    else
    {
        for (i = 1; i <= ind; i++)
            if (numeroABuscar <= arrayNumerico[i])
            {
                start = indices[i - 1];
                end = indices[i];
                set = 1;
                break;
            }
    }
    if (set == 0)
    {
        start = indices[i - 1];
        end = n;
    }
    for (i = start; i <= end; i++)
    {
        if (numeroABuscar == arregloNumerico[i])
        {
            j = 1;
            break;
        }
    }
    if (j == 1)
    {
        printf("Found at index %d", i);
    }
    else
    {
        printf("Not found");
    }
}

// Driver code
void main()
{

    int arregloNumerico[] = {6, 7, 8, 9, 10};
    int n = sizeof(arregloNumerico) / sizeof(arregloNumerico[0]);

    printf("\n\n\t NUMERO N => %d \n\n", n);
    // Element to search
    int numeroABuscar = 8;
    busquedaIndexada(arregloNumerico, n, numeroABuscar);
}