#ifndef MOCKCLIENTE_H_INCLUDED
#define MOCKCLIENTE_H_INCLUDED

int getNumeroCliente();
void getNombre(char name[]);
void getApellido(char lastName[]);
void getDNI(char dni[]);
void getEmail(char email[]);
void getTelefono(stCliente cliente[]);
stCliente getClienteRandom();

#endif // MOCKCLIENTE_H_INCLUDED
