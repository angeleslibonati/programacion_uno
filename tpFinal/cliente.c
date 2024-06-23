#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include "cliente.h"
#include "mockCliente.h"
#include "domicilio.h"
#include "mockDomicilio.h"
#include "menu.h"
#include "cuenta.h"
#include "mockCuenta.h"
#include "movimiento.h"
#include "mockMovimiento.h"


#define DIM 100
#define AR_CLIENTE "archivoClientes.dat"

//Cargar un cliente
stCliente cargaCliente()
{
    stCliente cliente;

    printf("\nIngrese el Nombre: ");
    fflush(stdin);
    gets(cliente.nombre);
    printf("\nIngrese el Apellido: ");
    fflush(stdin);
    gets(cliente.apellido);
    printf("\nIngrese el DNI: ");
    fflush(stdin);
    gets(cliente.dni);
    printf("\nIngrese el EMAIL: ");
    fflush(stdin);
    gets(cliente.email);
    cliente.domicilio = cargaUnDomicilio();
    printf("\nIngrese el Telefono: ");
    fflush(stdin);
    gets(cliente.telefono);
    cliente.eliminado = 0;

    return cliente;
}

//Muestr un cliente
void muestraCliente(stCliente cliente)
{
    puts("_______________________________________\n");
    printf("\nID:...................: %d", cliente.id);
    printf("\nNroCliente:...........: %d", cliente.nroCliente);
    printf("\nNombre:...............: %s", cliente.nombre);
    printf("\nApellido:.............: %s", cliente.apellido);
    printf("\nDNI:..................: %s", cliente.dni);
    printf("\nEMAIL:................: %s", cliente.email);
    printf("\nTelefono:.............: %s", cliente.telefono);
    muestraUnDomicilio(cliente.domicilio);
    printf("\nEstado:...............: ");
    estado2String(cliente.eliminado);
    puts("\n_______________________________________\n");
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
            if(cliente.eliminado == 1)
            {
                muestraCliente(cliente);
            }
        }
        fclose(archi);
    }
}


//ALTA CLIENTE
void altaCliente(char archivo[])
{
    FILE* archi = fopen(archivo, "ab");
    stCliente cliente;
    if(archi)
    {
        cliente = cargaCliente();
        cliente.id = getId(archi);
        cliente.nroCliente = getNroCliente(archivo,cliente.dni);
        fwrite(&cliente, sizeof(stCliente), 1, archi);
        fclose(archi);
    }
}

//BAJA CLIENTE
int bajaCliente (char nombreArchivo[], int numId)
{
    stCliente cliente;
    int posId;
    int flag = 0;
    cliente = buscarClientePorId(nombreArchivo, numId);
    posId = sizeof(stCliente) * (cliente.id - 1) ;

    FILE * archi = fopen(nombreArchivo, "r+b");

    if (archi) {
        if (cliente.id > 0) {
            if(cliente.eliminado == 0){
                cliente.eliminado = 1;
            } else {
                cliente.eliminado = 0;
            }
            fseek(archi, posId, SEEK_SET);
            fwrite(&cliente, sizeof(stCliente), 1, archi);
            flag = 1;
        }
        fclose(archi);
    }

    return flag;
}


//Busca cliente por ID. Si cliente.id == 0, el cliente no existe
stCliente buscarClientePorId(char nombreArchivo [], int numId)
{
    stCliente cliente;
    cliente.id = 0;
    int flag = 0;

    FILE * archi = fopen(nombreArchivo, "rb");

    if (archi) {
        while (flag == 0 && fread(&cliente, sizeof(stCliente), 1, archi) > 0) {

            if (cliente.id == numId) {
                flag = 1;
            }
        }
        fclose(archi);
    }
    return cliente;
}

//modificacion datos
int  modificaNombre(char nombreArchivo [], stCliente cliente, char nombre[])
{
    int flag = 0;
    FILE * archi = fopen(nombreArchivo, "r+b");

    if(archi)
    {
        strcpy(cliente.nombre, nombre);

        fseek(archi,sizeof(stCliente)*(cliente.id-1),0);
        fwrite(&cliente,sizeof(stCliente),1,archi);
        flag = 1;

        fclose(archi);
    }
    return flag;
}

int  modificaApellido(char nombreArchivo [], stCliente cliente, char apellido[])
{
    int flag = 0;
    FILE * archi = fopen(nombreArchivo, "r+b");

    if(archi)
    {
        strcpy(cliente.apellido, apellido);

        fseek(archi,sizeof(stCliente)*(cliente.id-1),0);
        fwrite(&cliente,sizeof(stCliente),1,archi);
        flag = 1;

        fclose(archi);
    }
    return flag;
}
int  modificaMail(char nombreArchivo [], stCliente cliente, char email[])
{
    int flag = 0;
    FILE * archi = fopen(nombreArchivo, "r+b");

    if(archi)
    {
        strcpy(cliente.email, email);

        fseek(archi,sizeof(stCliente)*(cliente.id-1),0);
        fwrite(&cliente,sizeof(stCliente),1,archi);
        flag = 1;

        fclose(archi);
    }
    return flag;
}

int  modificaDni(char nombreArchivo [], stCliente cliente, char dni[])
{
    int flag = 0;

    FILE * archi = fopen(nombreArchivo, "r+b");

    if(archi)
    {
        if(buscaClientePorDni(archi,dni)==1)
        {
            printf("\nEl dni ya existe en la Base de datos.\n");

        }else
        {
            strcpy(cliente.dni, dni);
            cliente.nroCliente = atoi(dni);
            fseek(archi,sizeof(stCliente)*(cliente.id-1),SEEK_SET);
            fwrite(&cliente,sizeof(stCliente),1,archi);
            flag = 1;
        }

        fclose(archi);
    }
    return flag;
}

int  modificaDomicilio(char nombreArchivo [], stCliente cliente, char domicilio[])
{
    int flag = 0;

    FILE * archi = fopen(nombreArchivo, "r+b");

    if(archi)
    {
        strcpy(cliente.domicilio.calle, domicilio);

        fseek(archi,sizeof(stCliente)*(cliente.id-1),0);
        fwrite(&cliente,sizeof(stCliente),1,archi);
        flag = 1;

        fclose(archi);
    }
    return flag;
}


int  modificaTelefono(char nombreArchivo [], stCliente cliente, char telefono[])
{
    int flag = 0;

    FILE * archi = fopen(nombreArchivo, "r+b");

    if(archi)
    {
        strcpy(cliente.telefono, telefono);

        fseek(archi,sizeof(stCliente)*(cliente.id-1),0);
        fwrite(&cliente,sizeof(stCliente),1,archi);
        flag = 1;

        fclose(archi);
    }
    return flag;
}

// Busca Cliente por dni (retorna flag, 0 = no esta, 1= esta en registro)
int buscaClientePorDni (FILE * archi, char dni[])
{
    int flag = 0;
    stCliente cliente;

    if (archi != NULL){

        while (fread(&cliente,sizeof(stCliente),1, archi) > 0){

            if (strcmp(cliente.dni, dni) == 0){

                flag = 1;
            }
        }
    }

    return flag;
}
//LISTADO DE CLIENTES

void mostrarClientesDesdeArch(char nombreArchivo [])
{
    FILE * archi = fopen(nombreArchivo, "rb");
    stCliente cliente;
    if (archi) {
        while(fread(&cliente, sizeof(stCliente), 1, archi) > 0) {
            muestraCliente(cliente);
        }
        fclose(archi);
    }
}








