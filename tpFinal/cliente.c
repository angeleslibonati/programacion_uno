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
#define AR_CLIENTE "archivoClientes.dat"

//Cargar un cliente   OKKKKK
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
    a.domicilio = cargaUnDomicilio();
    printf("\nIngrese el Telefono: ");
    fflush(stdin);
    gets(a.telefono);

    return a;
}
// OKKKKK
void muestraCliente(stCliente c){
    printf("........................................");
    printf("\nID:...................: %d", c.id);
    printf("\nNroCliente:...........: %d", c.nroCliente);
    printf("\nNombre:...............: %s", c.nombre);
    printf("\nApellido:.............: %s", c.apellido);
    printf("\nDNI:..................: %s", c.dni);
    printf("\nEMAIL:................: %s", c.email);
    printf("\nTelefono:.............: %s", c.telefono);
    muestraUnDomicilio(c.domicilio);
    printf("\n........................................");
}

//Cargas el archivo con clientes randoms segun la cantidad pasada por parametro
void cargaArchivoClientesRandoms(char nombreArchivo[], int cantidad)
{
    FILE* archi = fopen(nombreArchivo, "a+b");
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
