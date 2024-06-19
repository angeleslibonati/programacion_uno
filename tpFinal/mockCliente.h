#ifndef MOCKCLIENTE_H_INCLUDED
#define MOCKCLIENTE_H_INCLUDED
#include "cliente.h"
#include "domicilio.h"


int id (FILE * archi);
void getNumeroCliente(char dni, int id);
void getNombre(char nombre[]);
void getApellido(char apellido[]);
void getDNI(char dni[]);
void getEmail(char mail[],char nombre[], char apellido[]);
void getTelefono(char telefono[]);
stCliente getClienteRandom(FILE* archi);

#endif // MOCKCLIENTE_H_INCLUDED
