#ifndef MOCKCLIENTE_H_INCLUDED
#define MOCKCLIENTE_H_INCLUDED
#include "cliente.h"
#include "domicilio.h"
#include "mockDomicilio.h"


int getId (FILE * archi);
int getNroCliente(FILE* archi, char dni[]);
void getNombre(char nombre[]);
void getApellido(char apellido[]);
void getDNI(char dni[]);
void getTelefono(stCliente cliente[]);
void mostrarTelefonos(char telefonos[]);
void getEmail(char mail[],char nombre[], char apellido[]);
stCliente getClienteRandom(FILE * archi);

#endif // MOCKCLIENTE_H_INCLUDED
