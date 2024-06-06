#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include "domicilio.h"

typedef struct
{
    int id; /// campo �nico y autoincremental
    int nroCliente;
    char nombre[30];
    char apellido[30];
    char dni[10];
    char email[30];
    stDomicilio domicilio;
    char telefono[12];
    int eliminado; /// 0 si est� activo - 1 si est� eliminado


}stCliente;

stCliente cargaCliente();
void muestraCliente(stCliente a);


#endif // CLIENTE_H_INCLUDED
