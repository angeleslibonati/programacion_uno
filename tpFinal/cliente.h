#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include <stdio.h>
#include "domicilio.h"
#include "mockDomicilio.h"

typedef struct
{
    int id; /// campo único y autoincremental
    int nroCliente;
    char nombre[30];
    char apellido[30];
    char dni[10];
    char email[30];
    stDomicilio domicilio;
    char telefono[12];
    int eliminado; /// 0 si está activo - 1 si está eliminado


}stCliente;


stCliente cargaCliente();
void muestraCliente(stCliente cliente);
void cargaArchivoClientesRandoms(char nombreArchivo[], int cantidad);
void muestraArchivoClientes(char nombreArchivo[]);
void altaCliente(char archivo[]);
int bajaCliente (char nombreArchivo[], int numId);
stCliente buscarClientePorId(char nombreArchivo [], int numId);
int  modificaNombre(char nombreArchivo[],stCliente cliente, char nombre[]);
int  modificaMail(char nombreArchivo[],stCliente cliente, char mail[]);
int  modificaApellido(char nombreArchivo[],stCliente cliente, char apellido[]);
int  modificaDni(char nombreArchivo[],stCliente cliente, char dni[]);
int  modificaDomicilio(char nombreArchivo[],stCliente cliente, char domicilio[]);
int  modificaTelefono(char nombreArchivo[],stCliente cliente, char telefono[]);
int buscaClientePorDni (FILE * archi, char dni[]);
void mostrarClientesDesdeArch(char nombreArchivo []);


#endif // CLIENTE_H_INCLUDED
