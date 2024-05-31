#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "mockCliente.h"

#define DIM 100
#define AR_CLIENTE "cliente.dat"

int main()
{
    srand(time(NULL)); // Inicializa la semilla del generador de números aleatorios

    stCliente clientesAr[DIM];
    int vClientes = 0;

//    stCliente aye;
//    aye = cargaCliente();
//    muestraCliente(aye);


  /*  cargaArchClientesRandom(clientesAr, 10);
    printf("Listado de clientes: \n");
    muestraArchivoClientes(clientesAr);
    */
    stCliente clientePrueba;


    clientePrueba = getClienteRandom();

    return 0;
}
