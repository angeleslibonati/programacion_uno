#ifndef MOCKCLIENTE_H_INCLUDED
#define MOCKCLIENTE_H_INCLUDED
#include "cliente.h"
#include "domicilio.h"
#include "mockCliente.h"

int getNroCliente(FILE* archi, char dni[]);
int getId (FILE * archi);
int getNroCliente();
void getNombre(char nombre[]);
void getApellido(char apellido[]);
void getDNI(char dni[]);
void getEmail(char mail[],char nombre[], char apellido[]);
void getTelefono(stCliente cliente[]);
stCliente getClienteRandom();

#endif // MOCKCLIENTE_H_INCLUDED
