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


stCuenta altaCuentaRandom(FILE * archi) {///modificar cabecera nombre archivo cliente
    stCuenta cuenta;

    cuenta.id = id(archi);
    cuenta.idCliente = 1; ///cuando esté unido utilizar funcion int randomIdCliente(char nombreArchivo [])
    cuenta.tipoDeCuenta = randomTipoCuenta();
    cuenta.nroCuenta = randomNroCuenta(archi, cuenta.tipoDeCuenta);
    cuenta.costoMensual = costoMantenimiento(cuenta.tipoDeCuenta);
    cuenta.saldo = 0;
    cuenta.eliminado = 0;

    return cuenta;
}


//Carga cuentas en archivo Random
void cargaArchivoCuentaRandom(char nombreArchivo [], int cantidad) {
    stCuenta cuenta;
    FILE * archi = fopen(nombreArchivo, "ab");

    if (archi) {
        for (int i = 0; i < cantidad; i++) {
            cuenta = altaCuentaRandom(archi);
            fseek(archi, 0, 2);
            fwrite(&cuenta, sizeof(stCuenta), 1, archi);
        }
        fclose(archi);
    }
}

//Eleccion ramdom de id cliente
/*int randomIdCliente(char nombreArchivo []) {
    FILE * archi = fopen(nombreArchivo, "rb");
    stCliente = cliente;
    int idCliente = 1;

    if(archi) {
        fseek(archi, sizeof(stCliente) * -1, SEEK_END);
        fread(&cliente, sizeof(stCliente), 1, archi);
        idCliente = rand()%cliente.id+1;
        fclose(archi);
    }

    return idCliente;
}*/

//Calculo random de tipo de cuenta
int randomTipoCuenta() {
    return rand()%3+1;
}

//Calculo random numero de cuenta. ver numero máximo y posible bucle sin fin
int randomNroCuenta(FILE * archi, int tipoCuenta) {
    int nroCuenta;
    int flag = 1;

    while (flag == 1){
        nroCuenta = 94000000 + rand()%999999+1;
        flag = existeCuenta(archi, tipoCuenta, nroCuenta);
    }
    return nroCuenta;
}
