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

int main()
{
    srand(time(NULL));//Generador de semilla random

    stCliente cliente;


    cliente = getClienteRandom();
//  domi = getDomicilioRandom();
//  muestraUnDomicilio(domi);
    muestraCliente(cliente);

    getEmail(cliente);

    return 0;
}

