/**
 * @file ej_estructura_anidada.c
 * @author eliottvaldes@hotmail.com
 * @brief archivo que contiene
 * @version 0.1
 * @date 2022-03-03
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>

// estructura anidada
typedef struct infoDireccion
{
    char calle[40];
    int numero;
    char estado[40];
    char codpost[6];

} direccion;

// estructura general
typedef struct infousuario
{
    char nombre[40];
    char apellido[40];
    direccion dir;
    char telefono[15];
} usuario;

void main()
{

    // agregamos los datos usando hardcoding :((
    usuario eliot = {
        "Eliot",
        "Valdes",
        {"Avenida Siempre Viva", 2045, "Mexico", "09620"},
        "223-645-2019"};

    // mostramos los datos
    printf("Usuario: %s %s\n", eliot.apellido, eliot.nombre);
    printf("Direccian: %s %d\nEstado: %s\n", eliot.dir.calle, eliot.dir.numero, eliot.dir.estado);
    printf("Codigo postal:%s\n", eliot.dir.codpost);
}