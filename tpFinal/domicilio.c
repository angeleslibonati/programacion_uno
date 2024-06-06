#include <stdio.h>
#include <stdlib.h>
#include "domicilio.h"
#include <string.h>
#include <conio.h>



stDomicilio cargaUnDomicilio(){
    stDomicilio d;

    printf("\nIngrese una Calle:  ");
    fflush(stdin);
    gets(d.calle);
    printf("\nIngrese un Nro.:  ");
    gets(d.nro);
    printf("\nIngrese una Localidad: ");
    gets(d.localidad);
    printf("\nIngrese una Provincia: ");
    gets(d.provincia);
    printf("\nCodigo Postal: ");
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
