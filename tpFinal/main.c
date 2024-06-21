#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cuenta.h"
#include "mockCuenta.h"

int main()
{
    srand(time(NULL));
    printf("Hello world!\n");
    stCuenta cuenta, cuenta2;
    int flag;
    //cargaCuentaUsuario2Arch("cuenta.dat");
    //cargaArchivoCuentaRandom("cuenta.dat", 10);

    //mostrarCuentasDesdeArch("cuenta.dat");
    //listarCuentasPorCliente("cuenta.dat", 12);
    /*cuenta2 = buscaCuentaPorId("cuenta.dat", 3);
    printf("\nCuenta buscada\n");
    mostrarDatosCuenta(cuenta2);
    flag = cambioEstadoCuentaPorId("cuenta.dat", 3);
    printf("\n%d", flag);
    cuenta2 = buscaCuentaPorId("cuenta.dat", 3);
    mostrarDatosCuenta(cuenta2);
    printf("\n-------------------------------------\n\n\n");
    mostrarCuentasDesdeArch("cuenta.dat");*/



    return 0;
}
