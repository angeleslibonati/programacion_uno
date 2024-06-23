#include <stdio.h>
#include <stdlib.h>
#include "cuenta.h"
#include "mockCuenta.h"
#include "movimiento.h"
#include "mockMovimiento.h"
#include "mockDomicilio.h"
#include "domicilio.h"
#include "cliente.h"
#include "mockCliente.h"
#include "menu.h"


stCuenta altaCuentaRandom(FILE * archi, char nombreArchCliente []) {
    stCuenta cuenta;

    cuenta.id = id(archi) ;
    cuenta.idCliente = randomIdCliente(nombreArchCliente);
    cuenta.tipoDeCuenta = randomTipoCuenta();
    cuenta.nroCuenta = randomNroCuenta(archi, cuenta.tipoDeCuenta);
    cuenta.costoMensual = costoMantenimiento(cuenta.tipoDeCuenta);
    cuenta.saldo = 0;
    cuenta.eliminado = 0;

    return cuenta;
}


//Carga cuentas en archivo Random
void cargaArchivoCuentaRandom(char nombreArchivo [], int cantidad, char nombreArchCliente []) {
    stCuenta cuenta;
    FILE * archi = fopen(nombreArchivo, "ab");

    if (archi) {
        for (int i = 0; i < cantidad; i++) {
            cuenta = altaCuentaRandom(archi, nombreArchCliente);
            fseek(archi, 0, 2);
            fwrite(&cuenta, sizeof(stCuenta), 1, archi);
        }
        fclose(archi);
    }
}

//Eleccion ramdom de id cliente
int randomIdCliente(char nombreArchivo []) {
    FILE * archi = fopen(nombreArchivo, "rb");
    int cantClientes = 1;
    int idCliente = 1;

    if(archi) {
        cantClientes = getId(archi) - 1;
        idCliente = rand()%cantClientes+1;
        fclose(archi);
    }

    return idCliente;
}

//Calculo random de tipo de cuenta
int randomTipoCuenta() {
    return rand()%3+1;
}

//Calculo random numero de cuenta. ver numero máximo y posible bucle sin fin
int randomNroCuenta(FILE * archi) {
    int nroCuenta;
    int flag = 1;

    while (flag == 1){
        nroCuenta = 94000000 + rand()%999999+1;
        flag = existeCuenta(archi, nroCuenta);
    }
    return nroCuenta;
}

int cantCuentasArchivo (FILE * archiCuenta)
{
    int cantidad = 0;

    fseek(archiCuenta,0,2);
    cantidad = ftell(archiCuenta)/sizeof(stCuenta);

    return cantidad;
}

stCuenta cuentasRandomPorCantidad (int cantidad, FILE * archiCuenta)
{
    stCuenta cuenta;

    int posicion = (rand ()% cantidad) + 1;

    fseek(archiCuenta, (sizeof(stCuenta)* (posicion - 1)),0);
    fread(&cuenta,sizeof(stCuenta),1,archiCuenta);

    return cuenta;
}
