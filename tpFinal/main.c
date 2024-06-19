#include <stdio.h>
#include <stdlib.h>
#include "domicilio.h"
#include <string.h>
#include <conio.h>
#include <time.h>
#include "mockDomicilio.h"
#include "mockCliente.h"
#include "cliente.h"
#include "domicilio.h"

#define AR_CLIENTE "clientes.dat"

int main()
{
    srand(time(NULL));//Generador de semilla random

    stCliente cliente;

    cargaArchivoClientesRandoms(AR_CLIENTE, 5);//FUNCIONANDO
    muestraArchivoClientes(AR_CLIENTE); //FUNCIONANDO

    //probando las cantidades
//    printf("La cantidad es: %d", cuentaRegistroArchivo(AR_CLIENTE, sizeof(stCliente)));





    return 0;
}







