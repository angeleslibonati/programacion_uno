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
    printf("........................................");
    printf("\nID:...................: %d", cliente.id);
    printf("\nNroCliente:...........: %d", cliente.nroCliente);
    printf("\nNombre:...............: %s", cliente.nombre);
    printf("\nApellido:.............: %s", cliente.apellido);
    printf("\nDNI:..................: %s", cliente.dni);
    printf("\nEMAIL:................: %s", cliente.email);
    printf("\nTelefono:.............: %s", cliente.telefono);
    muestraUnDomicilio(cliente.domicilio);
    printf("\nELiminado:............: %d", cliente.eliminado);
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
int  modificaNombre(FILE * archi,int id, char nombre[])
{
    int flag = 0;
    stCliente cliente;

    if(archi)
    {
        cliente = buscarClientePorId(archi,id);
        strcpy(cliente.nombre, nombre);
        fseek(archi,sizeof(stCliente)*(cliente.id-1),SEEK_SET);
        fwrite(&cliente,sizeof(stCliente),1,archi);
        flag = 1;
    }
    return flag;
}

int  modificaMail(FILE * archi,int id, char mail[])
{
    int flag = 0;
    stCliente cliente;
    if(archi)
    {
        cliente = buscarClientePorId(archi,id);
        strcpy(cliente.email, mail);
        fseek(archi,sizeof(stCliente)*(cliente.id-1),SEEK_SET);
        fwrite(&cliente,sizeof(stCliente),1,archi);

        flag = 1;
    }
    return flag;
}

int  modificaApellido(FILE * archi,int id, char apellido[])
{
    int flag = 0;
    stCliente cliente;

    if(archi)
    {

        cliente = buscarClientePorId(archi,id);
        strcpy(cliente.apellido, apellido);
        fseek(archi,sizeof(stCliente)*(cliente.id-1),SEEK_SET);
        fwrite(&cliente,sizeof(stCliente),1,archi);

        flag = 1;
    }
    return flag;
}

int  modificaDni(FILE * archi,int id, char dni[])
{
    int flag = 0;
    stCliente cliente;

    if(archi)
    {
        cliente = buscarClientePorId(archi,id);
        if(buscaClientePorDni(archi,dni)==1)
        {
            printf("El dni ya existe en la Base de datos.\n");

        }else
        {
            strcpy(cliente.dni, dni);
            fseek(archi,sizeof(stCliente)*(cliente.id-1),SEEK_SET);
            fwrite(&cliente,sizeof(stCliente),1,archi);

            flag = 1;
        }
    }
    return flag;
}

int  modificaDomicilio(FILE * archi,int id, char domicilio[])
{
    int flag = 0;
    stCliente cliente;

    if(archi)
    {

        cliente = buscarClientePorId(archi,id);
        strcpy(cliente.domicilio.calle,domicilio);
        fseek(archi,sizeof(stCliente)*(cliente.id-1),SEEK_SET);
        fwrite(&cliente,sizeof(stCliente),1,archi);

        flag = 1;
    }
    return flag;
}

int  modificaTelefono(FILE *archi,int id, char telefono[])
{
    int flag = 0;
    stCliente cliente;

    if(archi)
    {
        cliente = buscarClientePorId(archi,id);
        strcpy(cliente.telefono, telefono);
        fseek(archi,sizeof(stCliente)*(cliente.id-1),SEEK_SET);
        fwrite(&cliente,sizeof(stCliente),1,archi);

        flag = 1;
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

//FUNCION PRINCIPAL PARA MODIFICAR CLIENTE: LLAMA A OTRAS
void modificaCliente(char nombreArchivo[], int id, int opcion)
{
    stCliente cliente;
    FILE * archi = fopen(nombreArchivo, "r+b");

    if(archi)
    {
        swithcSubMenuModificarCliente(archi, id,opcion);
        fclose(archi);
    }

}

//Switch para ingreso a la modificacion.
void swithcSubMenuModificarCliente (FILE* archi, int id, int opcion)
{
    do
    {
        int flag = 0;

        switch (opcion)
        {
        case 0:

            //volver al menu anterior
            system ("cls");
            imprimirCabecera("CLIENTE");
            printf("\n\n");
            imprimeOpcionesSubMenu();
            switchSubMenuCliente();

            break;

        case 1:

            //MODIFICA EL NOMBRE DEL CLIENTE
            system ("cls");
            imprimirCabecera("NOMBRE");
            printf("\n\n");
            printf("Ingrese el nuevo Nombre: \n");
            char nuevoNombre[30];
            fflush(stdin);
            gets(nuevoNombre);
            system("pause");
            flag = modificaNombre(archi,id,nuevoNombre);
            if (flag == 1){
                printf("\nDato modificado con Exito.\n");
            }
            else{
                printf("\nEl dato no pudo ser modificado.\n");
            }
            break;

        case 2:

            //MODIFICA EL APELLIDO DEL CLIENTE
            system ("cls");
            imprimirCabecera("APELLIDO");
            printf("\n\n");
            printf("Ingrese el nuevo Apellido: \n");
            char nuevoApellido[30];
            fflush(stdin);
            gets(nuevoApellido);
            flag = modificaApellido(archi,id,nuevoApellido);
            if (flag == 1){
                printf("\nDato modificado con Exito.\n");
            }
            else{
                printf("\nEl dato no pudo ser modificado.\n");
            }
            break;

       case 3:

            //MODIFICA DNI DEL CLIENTE
            system ("cls");
            imprimirCabecera("DNI");
            printf("\n\n");
            printf("Ingrese el nuevo DNI: \n");
            char nuevoDni[10];
            fflush(stdin);
            gets(nuevoDni);
            flag = modificaDni(archi,id,nuevoDni);
            if (flag == 1){
                printf("\nDato modificado con Exito.\n");
            }
            else{
                printf("\nEl dato no pudo ser modificado.\n");
            }

            break;

        case 4:

            //MODIFICA EMAIL
            system ("cls");
            imprimirCabecera("EMAIL");
            printf("\n\n");
            printf("Ingrese el nuevo Mail: \n");
            char nuevoMail[30];
            fflush(stdin);
            gets(nuevoMail);
            flag = modificaMail(archi,id,nuevoMail);
            if (flag == 1){
                printf("\nDato modificado con Exito.\n");
            }
            else{
                printf("\nEl dato no pudo ser modificado.\n");
            }

            break;

        case 5:

            //MODIFICA DOMICILIO
            system ("cls");
            imprimirCabecera("DOMICILIO");
            printf("\n\n");
            printf("Ingrese el nuevo Domicilio: \n");
            char nuevoDomicilio[30];
            fflush(stdin);
            gets(nuevoDomicilio);
            flag = modificaDomicilio(archi,id,nuevoDomicilio);
            if (flag == 1){
                printf("\nDato modificado con Exito.\n");
            }
            else{
                printf("\nEl dato no pudo ser modificado.\n");
            }

            break;

        case 6:

            //MODIFICA TELEFONO
            system("cls");
            imprimirCabecera("TELEFONO");
            printf("\n\n");
            printf("Ingrese el nuevo Telefono: \n");
            char nuevoTelefono[12];
            fflush(stdin);
            gets(nuevoTelefono);
            flag = modificaTelefono(archi,id,nuevoTelefono);
            if (flag == 1){
                printf("\nDato modificado con Exito.\n");
            }
            else{
                printf("\nEl dato no pudo ser modificado.\n");
            }

            break;

        default:

            printf("No podemos procesar la opcion ingresada.\n");
        }
    }while(opcion !=0);
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








