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
int  modificaNombre(FILE * archi,int id, char nombre[]);
int  modificaMail(FILE * archi,int id, char mail[]);
int  modificaApellido(FILE * archi,int id, char apellido[]);
int  modificaDni(FILE * archi,int id, char dni[]);
int  modificaDomicilio(FILE * archi,int id, char domicilio[]);
int  modificaTelefono(FILE *archi,int id, char telefono[]);
int buscaClientePorDni (FILE * archi, char dni[]);
void modificaCliente(char nombreArchivo[], int id, int opcion);
void swithcSubMenuModificarCliente (FILE* archi, int id, int opcion);
void mostrarClientesDesdeArch(char nombreArchivo []);
void consultaClientePorId(char nombreArchivo [], int id);


#endif // CLIENTE_H_INCLUDED
