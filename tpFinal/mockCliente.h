#ifndef MOCKCLIENTE_H_INCLUDED
#define MOCKCLIENTE_H_INCLUDED
#include "cliente.h"
#include "domicilio.h"


int getId(int id);
int getFileNumber();
void getNombre(char nombre[]);
void getApellido(char apellido[]);
void getDNI(char dni[]);
void getEmailRandom(stCliente* a);
void getTelefono(char telefono[]);
stCliente getClienteRandom();

#endif // MOCKCLIENTE_H_INCLUDED
