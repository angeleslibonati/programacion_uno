#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include <string.h>
#include <time.h>
#include <conio.h>
#include "mockCliente.h"
#include "domicilio.h"
#include "mockDomicilio.h"

#define DIM 100
#define AR_CLIENTE

//Cargar un cliente
stCliente cargaCliente()
{
    stCliente a;

    printf("\nIngrese el ID: ");
    scanf("%d", &a.id);
    printf("\nIngrese el numero del Cliente: ");
    scanf("%d", &a.nroCliente);
    printf("\nIngrese el Nombre: ");
    fflush(stdin);
    gets(a.nombre);
    printf("\nIngrese el Apellido: ");
    fflush(stdin);
    gets(a.apellido);
    printf("\nIngrese el DNI: ");
    fflush(stdin);
    gets(a.dni);
    printf("\nIngrese el EMAIL: ");
    fflush(stdin);
    gets(a.email);
    a.domicilio = cargaUnDomicilio();
    printf("\nIngrese el Telefono: ");
    fflush(stdin);
    gets(a.telefono);

    return a;
}
//Muestra de un cliente
void muestraCliente(stCliente a)
{
    printf("\nID:...................: %d", a.id);
    printf("\nNroCliente:...........: %d", a.nroCliente);
    printf("\nNombre:...............: %s", a.nombre);
    printf("\nApellido:.............: %s", a.apellido);
    printf("\nDNI:..................: %s", a.dni);
    printf("\nEMAIL:................: %s", a.email);
    printf("\nTelefono:.............: %s", a.telefono);
    muestraUnDomicilio(a.domicilio);
    printf("\n============================================");
}


//Cargas el archivo con clientes randoms segun la cantidad pasada por parametro
void cargaArchivoClientesRandoms(char nombreArchivo[], int cantidad)
{
    FILE* archi = fopen(nombreArchivo, "ab");
    stCliente cliente;
    int i = 0;
    if(archi)
    {
        while(i<cantidad)
        {
            cliente = getClienteRandom(archi);
            fwrite(&cliente, sizeof(stCliente), 1, archi);
            i++;
        }
        fclose(archi);
    }
}

//Mostras el archivo con clientes random de la funcion anterior
void muestraArchivoClientes(char nombreArchivo[])
{
    stCliente cliente;
    FILE* archi = fopen(nombreArchivo, "rb");
    if(archi)
    {
        while(fread(&cliente, sizeof(stCliente), 1, archi)>0)
        {
            muestraCliente(cliente);
        }
        fclose(archi);
    }
}

//Cuenta la cantidad de cliente que hay en un arreglo
//tamaño de estructura es sizeof(stCliente)
int cuentaRegistroArchivo(char nombreArchivo[], int tamEstructura)
{
    FILE* archi = fopen(nombreArchivo, "rb");
    int total = 0;
    if(archi)
    {
        fseek(archi, 0,SEEK_END);
        total = ftell(archi) / tamEstructura;
        fclose(archi);
    }
    return total;
}


//void muestraMenuClientes()
//{
//    printf("\nMenu Clientes: ");
//    printf("\n1 - Listado de clientes");
//    printf("\n2 - Consultar un cliente");
//    printf("\n3 - Dar de alta un cliente nuevo");
//    printf("\n4 - Dar de baja un cliente existente");
//    printf("\n5 - Modificar un cliente existente");
//    printf("\n\n\n");
//    printf("ESC para salir o cualquier tecla para continuar");
//}
//
//switch(opcion)
//{
//case 49:
//    system("cls");
//    muestraMenuClientes();
//
//    opcion = getch();
//
//    switch(opcion)
//    {
//    case 49:
//        system("cls");
//        printf("\nLISTADO DE CLIENTES: ");
//        muestraArchivoClientes(AR_CLIENTE);
//        getch();
//        break;
//    case 50:
//        system("cls");
//        printf("Ingrese el numero del cliente a consultar:");
//        scanf("%i", &dato);
//        while(verificaNroCliente(AR_CLIENTE, dato) == 0)
//        {
//            printf("El cliente no existe, intente de nuevo:");
//            scanf("%i", &dato);
//        }
//        consultaCliente(AR_CLIENTE, dato);
//        getch();
//        break;
//    case 51:
//        system("cls");
//        altaCliente(AR_CLIENTE);
//        system("cls");
//        printf("Cliente dado de alta satisfactoriamente!!!");
//        getch();
//        break;
//    case 52:
//        system("cls");
//        printf("Ingrese el numero del cliente a dar de baja:");
//        scanf("%i", &dato);
//        while(verificaNroCliente(AR_CLIENTE, dato) == 0)
//        {
//            printf("El cliente no existe, intente de nuevo:");
//            scanf("%i", &dato);
//        }
//        bajaCliente(AR_CLIENTE, dato);
//        system("cls");
//        printf("Cliente dado de baja satisfactoriamente!!!");
//        getch();
//        break;
//    case 53:
//        system("cls");
//        printf("Ingrese el numero del cliente a modificar:");
//        scanf("%i", &dato);
//        while(verificaNroCliente(AR_CLIENTE, dato) == 0)
//        {
//            printf("El cliente no existe, intente de nuevo:");
//            scanf("%i", &dato);
//        }
//        modificaCliente(AR_CLIENTE, dato);
//        system("cls");
//        printf("Cliente modificado satisfactoriamente!!!");
//        getch();
//        break;
//    }
//    break;
//
//}

//Carga un cliente al archivo por teclado
void altaCliente(char archivo[])
{
    FILE* archi = fopen(archivo, "ab");
    stCliente a;
    if(archi)
    {
        a = cargaCliente();
        fwrite(&a, sizeof(stCliente), 1, archi);
        fclose(archi);
    }
}


//Da de baja al cliente cambiando su valor de eliminado por 1
void bajaCliente(char archivo[], int numCliente)
{
    FILE* archi = fopen(archivo, "a+b");
    stCliente a;
    if(archi)
    {
        if(buscaIdCliente(archivo, numCliente) != 0)
        {
            fseek(archi, (buscaIdCliente(archivo, numCliente) - 1)*sizeof(stCliente), SEEK_SET);
            fread(&a, sizeof(stCliente), 1, archi);
            a.eliminado = 1;

            fseek(archi, - 1*sizeof(stCliente), SEEK_CUR);
            fwrite(&a, sizeof(stCliente), 1, archi);
        }
        else
        {
            printf("No hay ningun cliente con ese numero!!!");
        }
        fclose(archi);
    }
}
//Da la posibilidad al usuario de cambiar las caracteristicas del cliente
void modificaCliente(char archivo[], int numCliente)
{
    FILE* archi = fopen(archivo, "a+b");
    stCliente a;
    int dato;
    char aux[30];
    char opcion = 0;
    if(archi)
    {
        if(buscaIdCliente(archivo, numCliente) != 0)
        {
            fseek(archi, (buscaIdCliente(archivo, numCliente) - 1)*sizeof(stCliente), SEEK_SET);
            fread(&a, sizeof(stCliente), 1, archi);
            while(opcion!= 's' && opcion!= 'n')
            {
                printf("Desea modificar el numero de cliente?(s/n):");
                opcion = getch();
            }
            if(opcion == 's')
            {
                printf("\nIngresa el nuevo numero de cliente:");
                scanf("%i", &dato);
                while(verificaNroCliente(AR_CLIENTE, dato) == 1)
                {
                    printf("\nNro de cliente ya existente, intente otro: ");
                    scanf("%i", &dato);
                }
                a.nroCliente = dato;
            }
            opcion = 0;
            while(opcion!= 's' && opcion!= 'n')
            {
                printf("\nDesea modificar el nombre del cliente?(s/n):");
                opcion = getch();
            }
            if(opcion == 's')
            {
                printf("\nIngresa el nuevo nombre:");
                fflush(stdin);
                gets(aux);
                while(validarPalabra(aux) == 1)
                {
                    printf("\nLo ingresado no es un nombre, intente de nuevo:");
                    fflush(stdin);
                    gets(aux);
                }
                strcpy(a.nombre, aux);
            }
            opcion = 0;
            while(opcion!= 's' && opcion!= 'n')
            {
                printf("\nDesea modificar el apellido del cliente?(s/n):");
                opcion = getch();
            }
            if(opcion == 's')
            {
                printf("\nIngresa el nuevo apellido:");
                fflush(stdin);
                gets(aux);

                strcpy(a.apellido, aux);
            }
            opcion = 0;
            while(opcion!= 's' && opcion!= 'n')
            {
                printf("\nDesea modificar el dni del cliente?(s/n):");
                opcion = getch();
            }
            if(opcion == 's')
            {
                printf("\nIngrese el nuevo dni:");
                fflush(stdin);
                gets(aux);

                while(verificaDniCliente(AR_CLIENTE, aux) == 1)
                {
                    printf("\nDNI ya existente, intente ingresar otro: ");
                    fflush(stdin);
                    gets(aux);
                }
                strcpy(a.dni, aux);
            }
            opcion = 0;
            while(opcion!= 's' && opcion!= 'n')
            {
                printf("\nDesea modificar el Email del cliente?(s/n):");
                opcion = getch();
            }
            if(opcion == 's')
            {
                printf("\nIngresa el nuevo email (sin el dominio):");
                fflush(stdin);
                gets(aux);
                strcat(aux, "@gmail.com");
                while(verificaEmailCliente(AR_CLIENTE, aux) == 1)
                {
                    printf("\nEmail ya existente, intente ingresar otro: ");
                    fflush(stdin);
                    gets(aux);
                    strcat(aux, "@gmail.com");
                }
                strcpy(a.email, aux);
            }
            opcion = 0;
            while(opcion!= 's' && opcion!= 'n')
            {
                printf("\nDesea modificar el telefono del cliente?(s/n):");
                opcion = getch();
            }
            if(opcion == 's')
            {
                printf("\nIngrese el nuevo telefono:");
                fflush(stdin);
                gets(aux);

                while(verificaTelCliente(AR_CLIENTE, aux) == 1)
                {
                    printf("\nTelefono ya existente, intente ingresar otro: ");
                    fflush(stdin);
                    gets(aux);
                }
                strcpy(a.telefono, aux);
            }
            fseek(archi, -1*sizeof(stCliente), SEEK_CUR);
            fwrite(&a, sizeof(stCliente), 1, archi);
        }
        else
        {
            printf("\nNo hay ningun cliente con ese numero!!!");
        }
        fseek(archi, -1 * sizeof(stCliente), SEEK_CUR);
        fwrite(&a, sizeof(stCliente), 1, archi);
        fclose(archi);
    }
}
//Muestra un cliente a partir de su numero
void consultaCliente(char archivo[], int numCliente)
{
    FILE* archi = fopen(archivo, "rb");
    stCliente a;
    if(archi)
    {
        if(buscaIdCliente(archivo, numCliente) != 0)
        {
            fseek(archi, (buscaIdCliente(archivo, numCliente) - 1)*sizeof(stCliente), SEEK_SET);
            fread(&a, sizeof(stCliente), 1, archi);
            muestraUnCliente(a);
        }
        else
        {
            printf("No existe ningun cliente con ese numero!!!");
        }
        fclose(archi);
    }
}


//Verifica si el numero de cliente ya existe en el archivo, devuelve 1 si existe y 0 sino
int verificaNroCliente(char archivo[], int dato)
{
    FILE* archi = fopen(archivo, "rb");
    stCliente a;
    int flag = 0;
    if(archi)
    {
        while(flag == 0 && fread(&a, sizeof(stCliente), 1, archi)>0)
        {
            if(a.nroCliente == dato)
            {
                flag = 1;
            }
        }
        fclose(archi);
    }
    return flag;
}

//Recibe el numero de cliente y devuelve 0 si no existe y el id del cliente si existe
int buscaIdCliente(char archivo[], int numCliente)
{
    FILE* archi = fopen(archivo, "rb");
    stCliente a;
    int flag = 0;
    if(archi)
    {
        while(flag == 0 && fread(&a, sizeof(stCliente), 1, archi)>0)
        {
            if(a.nroCliente == numCliente)
            {
                flag = a.id;
            }
        }
        fclose(archi);
    }
    return flag;
}

//Verifica si el telefono del cliente ya existe en el archivo, devuelve 1 si existe y 0 sino
int verificaTelCliente(char archivo[], char dato[])
{
    FILE* archi = fopen(archivo, "rb");
    stCliente a;
    int flag = 0;
    if(archi)
    {
        while(flag == 0 && fread(&a, sizeof(stCliente), 1, archi)>0)
        {
            if(strcmp(a.telefono, dato) == 0)
            {
                flag = 1;
            }
        }
        fclose(archi);
    }
    return flag;
}
//Verifica si el DNI del cliente ya existe en el archivo, devuelve 1 si existe y 0 sino
int verificaDniCliente(char archivo[], char dato[])
{
    FILE* archi = fopen(archivo, "rb");
    stCliente a;
    int flag = 0;
    if(archi)
    {
        while(flag == 0 && fread(&a, sizeof(stCliente), 1, archi)>0)
        {
            if(strcmp(a.dni, dato) == 0)
            {
                flag = 1;
            }
        }
        fclose(archi);
    }
    return flag;
}
//Verifica si el Email del cliente ya existe en el archivo, devuelve 1 si existe y 0 sino
int verificaEmailCliente(char archivo[], char dato[])
{
    FILE* archi = fopen(archivo, "rb");
    stCliente a;
    int flag = 0;
    if(archi)
    {
        while(flag == 0 && fread(&a, sizeof(stCliente), 1, archi)>0)
        {
            if(strcmp(a.email, dato) == 0)
            {
                flag = 1;
            }
        }
        fclose(archi);
    }
    return flag;
}

