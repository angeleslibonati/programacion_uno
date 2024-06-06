#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include <string.h>
#include <time.h>
#include <conio.h>
#include "mockCliente.h"
#include "domicilio.h"
#include "mockDomicilio.h"

#define DIM 100
#define AR_CLIENTE "cliente.dat"

//Cargar un cliente
stCliente cargaCliente(){
    stCliente a;

    printf("\nIngrese el ID: ");
    scanf("%d", &a.id);
    printf("\nIngrese el numero del Cliente: ");
    scanf("%d", &a.nroCliente);
    printf("\nIngrese el Nombre: ");
    fflush(stdin);
    gets(a.nombre);
    printf("\nIngrese el Apellido: ");
    fflush(stdin);
    gets(a.apellido);
    printf("\nIngrese el DNI: ");
    fflush(stdin);
    gets(a.dni);
    printf("\nIngrese el EMAIL: ");
    fflush(stdin);
    gets(a.email);
    a.domicilio = cargaUnDomicilio();
    printf("\nIngrese el Telefono: ");
    fflush(stdin);
    gets(a.telefono);

    return a;
}
//Muestra de un cliente
void muestraCliente(stCliente c){
    printf("........................................");
    printf("\nID:...................: %d", c.id);
    printf("\nNroCliente:...........: %d", c.nroCliente);
    printf("\nNombre:...............: %s", c.nombre);
    printf("\nApellido:.............: %s", c.apellido);
    printf("\nDNI:..................: %s", c.dni);
    printf("\nEMAIL:................: %s", c.email);
    printf("\nTelefono:.............: %s", c.telefono);
    muestraUnDomicilio(c.domicilio);
    printf("\n........................................");
}

//Muestra de Telefonos
void mostrarTelefonos(char telefonos[])
{
    for (int i = 0; i < 12; i++)
    {
        printf("%s\n", telefonos[i]);
    }
}
