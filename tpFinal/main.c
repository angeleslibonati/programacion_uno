#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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
    srand (time (NULL));
    printf("\n\n");

    //iniciarMenu();
    mostrarMovimientosDesdeArch(AR_MOVIMIENTO);
    printf("CUENTAS\n");
    mostrarCuentasDesdeArch(AR_CUENTA);
    return 0;
}
