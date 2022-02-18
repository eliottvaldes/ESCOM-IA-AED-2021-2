/*
VALDES LUIS ELIOT FABIAN
*/

#include <stdio.h>
#include <stdbool.h>

// print animation
int sleep();
int loading()
{
    int i;
    for (int i = 0; i < 3; i++)
    {
        printf(".");
        sleep(1);
    }
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

// declare struct
struct Film
{
    // define atributes
    char name[50];
    int duration;
    char genres[50];
    char director[50];
    char clasification[50];
    int year;
};

// main function
void main()
{
    bool showMenu = true;
    // print greetings
    puts("**************************************");
    puts("Bienvenido");
    puts("**************************************");
    while (showMenu == true)
    {
        bool repeatExercise = true;
        char askForRepetition;
        int exerciseSelection;
        // print Menu
        puts("--------------------------------------");
        puts("Digita la opcion que deseas realizar:");
        puts("1.- Registrar pelicula ");
        puts("2.- Mostrar datos de la pelicula");
        puts("3.- Salir");
        puts("--------------------------------------");
        fflush(stdin);
        scanf("%d", &exerciseSelection);

        // create first film
        struct Film film_one;

        // do switch case
        switch (exerciseSelection)
        {
        case 1:
            while (repeatExercise == true)
            {
                puts("Registrar pelicula\n");
                // Start Coding

                // get data 4 struct
                puts("Ingrese los datos de la pelicula\n");
                puts("Nombre:");
                fflush(stdin);
                gets(film_one.name);

                puts("Duracion:");
                fflush(stdin);
                scanf("%d", &film_one.duration);

                puts("Genero:");
                fflush(stdin);
                gets(film_one.genres);

                puts("Director:");
                fflush(stdin);
                gets(film_one.director);

                puts("Clasificacion:");
                fflush(stdin);
                gets(film_one.clasification);

                puts("Anio:");
                fflush(stdin);
                scanf("%d", &film_one.year);

                // End of Code

                // don´t ask 4 repetition
                askForRepetition = 'n';
                repeatExercise = asking(askForRepetition, repeatExercise);
            }
            break;

        case 2:
            while (repeatExercise == true)
            {
                puts("Mostrar pelicula");
                // Start Coding
                puts("Nombre:");
                printf("%s \n\n", film_one.name);

                puts("Duracion:");
                printf("%d \n\n", film_one.duration);

                puts("Genero:");
                printf("%s \n\n", &film_one.genres);

                puts("Director:");
                fflush(stdin);
                printf("%s \n\n", &film_one.director);

                puts("Clasificacion:");
                printf("%s \n\n", &film_one.clasification);

                puts("Anio:");
                printf("%d \n\n", &film_one.year);

                // End of Code

                // Ask for confirmation
                puts("Para repetir el ejercicio digita ' y '. Para regresar al menu digita ' n '.");
                fflush(stdin);
                scanf("%c", &askForRepetition);
                repeatExercise = asking(askForRepetition, repeatExercise);
            }

            break;

        case 3:
            printf("\nSaliendo del programa ");
            loading();
            puts("\nADIOS");
            showMenu = false;
            break;

        default:
            puts("Opcion no valida");
            showMenu = true;
            break;
        }
    }
}
