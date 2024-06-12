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
    stDomicilio domicilio; /// Falta archivo de domicilio
    char telefono[12];
    int eliminado; /// 0 si está activo - 1 si está eliminado


}stCliente;

stCliente cargaCliente(); // OK
void muestraCliente(stCliente a); // OK
void cargaArchivoClientesRandoms(char nombreArchivo[], int cantidad);
void muestraArchivoClientes(char nombreArchivo[]);






#endif // CLIENTE_H_INCLUDED
