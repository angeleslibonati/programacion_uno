#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int opcionMenuPrincipal ()
{
    int opcion = 0;

    printf("1- Clientes\n");
    printf("2- Cuenta\n");
    printf("3- Movimiento\n");
    printf("4- Salir\n");

    scanf("%d", &opcion);

    system("cls");

    return opcion;
}

void menuPrincipal ()
{
    int opcion = opcionMenuPrincipal();

    switch (opcion)
    {
    case 1:

        printf("CLIENTES\n");
        //LLAMA FUNCION DEL MENU CLIENTE.
        subMenu();
        break;

    case 2:

        printf("CUENTA\n");
        //LLAMA FUNCION DEL MENU CUENTA.
        subMenu();
        break;

    case 3:
        printf("MOVIMIENTO\n");
        //LLAMA FUNCION DEL MENU MOVIMIENTO.
        subMenu();
        break;

    case 4:

        printf("Muchas Gracias.\n");
        break;

    default:

        printf("No podemos procesar la opcion ingresada.\n");
    }
}

int opcionesSubMenu ()
{
    int opcion = 0;

    printf("1- Alta\n");
    printf("2- Baja\n");
    printf("3- Modificacion\n");
    printf("4- Consultar\n");
    printf("5- Listado\n");
    printf("6- Volver Atras\n");

    scanf("%d", &opcion);

    system("cls");

    return opcion;
}

void subMenu ()
{
    int opcion = opcionesSubMenu();

    switch (opcion)
    {
    case 1:

        printf("ALTA\n");
        //Funcion de alta
        break;

    case 2:

        printf("BAJA\n");
        //funcion de baja
        break;

    case 3:
        printf("MODIFICACION\n");
        //Funcion de modificacion
        break;

    case 4:

        printf("CONSULTA\n");
        //funcion de consulta
        break;

    case 5:

        printf("LISTADO\n");
        if (opcion)
        //funcion de listado
        break;

    default:

        printf("No podemos procesar la opcion ingresada.\n");
    }

}

