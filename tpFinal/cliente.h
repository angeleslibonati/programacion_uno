#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include "domicilio.h"

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
void muestraCliente(stCliente a);
void mostrarTelefonos(char telefonos[]);
void cargaArchivoClientesRandoms(char nombreArchivo[], int cantidad);
void muestraArchivoClientes(char nombreArchivo[]);
int cuentaRegistroArchivo(char nombreArchivo[], int tamEstructura);


#endif // CLIENTE_H_INCLUDED
