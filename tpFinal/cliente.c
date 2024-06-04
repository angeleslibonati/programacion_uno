#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include <string.h>
#include <time.h>
#include <conio.h>
#include "mockCliente.h"

//#define DIM 100
//#define AR_CLIENTE "cliente.dat"

//Cargar un cliente
stCliente cargaCliente(){
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
    printf("\nIngrese el Telefono: ");
    fflush(stdin);
    gets(a.telefono);

    return a;
}

//Muestra de cliente modularizada
void muestraCliente(stCliente a){
    printf("........................................");
    printf("\nID:................... %d", a.id);
    printf("\nNroCliente:........... %d", a.nroCliente);
    printf("\nNombre:............... %s", a.nombre);
    printf("\nApellido:............. %s", a.apellido);
    printf("\nDNI:.................. %s", a.dni);
    printf("\nEMAIL:................ %s", a.email);
    printf("\nTelefono:............. %s", a.telefono);
    printf("\n........................................");
}

//Carga el Archivo con clientes randoms generados en el get
void cargaArchClientesRandom(char nombreArchivo[], int cant)
{
    FILE* archi = fopen(nombreArchivo, "ab");
    stCliente cliente;
    int i = 0;
    if(archi)
    {
        while(i<cant)
        {
            //Funcion final del mockCliente
            cliente = getClienteRandom();
            fwrite(&cliente, sizeof(stCliente), 1, archi);
            i++;
        }
        fclose(archi);
    }
}

//Muestra la funcion anterior
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

//Muestra de Telefonos
void mostrarTelefonos(char telefonos[])
{
    for (int i = 0; i < 12; i++)
    {
        printf("%s\n", telefonos[i]);
    }
}

//Muestra de DNI
void muestraDNI(char nombreArchivo[], stCliente a[])
{
    for (int i = 0; i < 10; i++)
    {
        printf("%00d\n", a[i]); // Imprime con ceros a la izquierda si es necesario
    }
}













