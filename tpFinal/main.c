#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "mockCliente.h"

typedef struct
{
    int id; /// campo �nico y autoincremental
    int nroCliente;
    char nombre[30];
    char apellido[30];
    char dni[10];
    char email[30];
//  stDomicilio domicilio; /// Falta archivo de domicilio
    char telefono[12];
    int eliminado; /// 0 si est� activo - 1 si est� eliminado
    //Falta hacer

}stCliente;

#define DIM 100
#define AR_CLIENTE "cliente.dat"

int main()
{
    printf("Hello world!sdkjgngnfkasfmsd\n");
    return 0;
}
