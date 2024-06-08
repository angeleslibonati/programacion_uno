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

    cargaArchivoClientesRandoms(AR_CLIENTE, 2);//FUNCIONANDO
    muestraArchivoClientes(AR_CLIENTE); //FUNCIONANDO


//    cliente = getClienteRandom();
//    domi = getDomicilioRandom();
//    muestraUnDomicilio(domi);
//    muestraCliente(cliente);


    return 0;
}

