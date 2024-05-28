#include <stdio.h>
#include <stdlib.h>
#include "domicilio.h"
#include <string.h>
#include <conio.h>



stDomicilio cargaUnDomicilio(){
    stDomicilio d;

    printf("\n Ingrese una Calle:  ");
    fflush(stdin);
    gets(d.calle);
    printf("\n Ingrese un Nro.:  ");
    gets(d.nro);
    printf("\n Ingrese una Localidad: ");
    gets(d.localidad);
    printf("\n Ingrese una Provincia: ");
    gets(d.provincia);
    printf("\n Codigo Postal: ");
    gets(d.cpos);

    return d;
}

void muestraUnDomicilio(stDomicilio d){

printf("\n Calle:..........: %s", d.calle);
printf("\n Nro:............: %s", d.nro);
printf("\n Localidad:......: %s", d.localidad);
printf("\n Provincia:......: %s", d.provincia);
printf("\n Codigo Postal:..: %s", d.cpos);
printf("\n =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* \n");

}
