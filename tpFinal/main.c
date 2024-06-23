#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "domicilio.h"
#include "mockDomicilio.h"
#include "cliente.h"
#include "mockCliente.h"
#include "menu.h"
#include "movimiento.h"
#include "mockMovimiento.h"
#include "cuenta.h"
#include "mockCuenta.h"


#define AR_CLIENTE "archivoClientes.dat"
#define AR_CUENTA "cuenta.dat"
#define AR_MOVIMIENTO "movimiento.dat"

int main()
{
    //cargaArchivoCuentaRandom(AR_CUENTA,10, AR_CLIENTE);
    printf("\n\n");

    iniciarMenu();

    return 0;
}
