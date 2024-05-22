#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include <string.h>
#include <time.h>
#include <conio.h>

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
    printf("\nIngrese el Telefono");
    fflush(stdin);
    gets(a.telefono);
}

void muestraCliente(stCliente a){
    printf("\nID: %d", a.id);
    printf("\nNroCliente: %d", a.nroCliente);
    printf("\nNombre: %s", a.nombre);
    printf("\nApellido: %s", a.apellido);
    printf("\nDNI: %s", a.dni);
    printf("\nEMAIL: %s", a.email);
    printf("\nTelefono: %s", a.telefono);
}
