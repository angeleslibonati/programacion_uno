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

    printf("\n\n");
    //cargaArchivoCuentaRandom(AR_CUENTA,5);

    //cargarMovimientosToArchivo(AR_MOVIMIENTO);
   //cargaArchivoMovimientos(AR_MOVIMIENTO,AR_CUENTA,);

    mostrarMovimientosDesdeArch(AR_MOVIMIENTO);
   // mostrarCuentasDesdeArch(AR_CUENTA);
    //iniciarMenu();

    return 0;
}
