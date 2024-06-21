#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "domicilio.h"
#include "cliente.h"
#include "mockCliente.h"
#include "mockDomicilio.h"
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
    printf("Hello world!\n");
    //cargaArchivoClientesRandoms(AR_CLIENTE,10);
    mostrarClientesDesdeArch(AR_CLIENTE);
    //iniciarMenu();

    return 0;
}
