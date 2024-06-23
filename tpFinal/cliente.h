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
int cargaArchivoClientesRandoms(char nombreArchivo[], int cantidad);
void muestraArchivoClientes(char nombreArchivo[]);
void altaCliente(char archivo[]);
int bajaCliente (char nombreArchivo[], int numId);
stCliente buscarClientePorId(char nombreArchivo [], int numId);
void cargaCuentaUsuario2Arch(char nombreArchivo [], char nombreArchCliente []);
int  modificaMail(char nombreArchivo [], stCliente cliente, char email[]);
int  modificaApellido(char nombreArchivo [], stCliente cliente, char apellido[]);
int  modificaDni(char nombreArchivo [], stCliente cliente, char dni[]);
int  modificaDomicilio(char nombreArchivo [], stCliente cliente, char domicilio[]);
int  modificaTelefono(char nombreArchivo [], stCliente cliente, char telefono[]);
int buscaClientePorDni (FILE * archi, char dni[]);
void modificaCliente(char nombreArchivo[], int id, int opcion);
void swithcSubMenuModificarCliente (FILE* archi, int id, int opcion);
void mostrarClientesDesdeArch(char nombreArchivo []);
void consultaClientePorId(char nombreArchivo [], int id);


#endif // CLIENTE_H_INCLUDED
