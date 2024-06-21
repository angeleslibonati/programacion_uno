#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "domicilio.h"
#include "cliente.h"
#include "mockCliente.h"
#include "mockDomicilio.h"
#include "menu.h"
#include "movimiento.h"
#include "mockMovimiento.h"
#include "cuenta.h"
#include "mockCuenta.h"



stDomicilio cargaUnDomicilio(){
    stDomicilio d;

    printf("\nIngrese una Calle:  ");
    fflush(stdin);
    gets(d.calle);
    printf("\nIngrese un Nro.:  ");
    fflush(stdin);
    gets(d.nro);
    printf("\nIngrese una Localidad: ");
    fflush(stdin);
    gets(d.localidad);
    printf("\nIngrese una Provincia: ");
    fflush(stdin);
    gets(d.provincia);
    printf("\nCodigo Postal: ");
    fflush(stdin);
    gets(d.cpos);

    return d;
}

void muestraUnDomicilio(stDomicilio d){

printf("\nCalle:................: %s", d.calle);
printf("\nNro:..................: %s", d.nro);
printf("\nLocalidad:............: %s", d.localidad);
printf("\nProvincia:............: %s", d.provincia);
printf("\nCodigo Postal:........: %s", d.cpos);

}
