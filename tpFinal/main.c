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

#define AR_CLIENTE "archivoClientes.dat"

int main()
{
    srand(time(NULL));//Generador de semilla random

    stCliente cliente;

    //cargaArchivoClientesRandoms(AR_CLIENTE,5);//FUNCIONANDO
    //muestraArchivoClientes(AR_CLIENTE);
    //altaCliente(AR_CLIENTE); // FUNCIONANDO
    //bajaCliente(AR_CLIENTE,4); // FUNCIONANDO
    muestraArchivoClientes(AR_CLIENTE);
    printf("............\n");
    //imprimirCabecera("Cabecera");
    //getch();
    //modificaCliente(AR_CLIENTE,4,1);



    return 0;
}
