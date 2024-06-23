#ifndef MOCKCUENTA_H_INCLUDED
#define MOCKCUENTA_H_INCLUDED

stCuenta altaCuentaRandom(FILE * archi, char nombreArchCliente []);
void cargaArchivoCuentaRandom(char nombreArchivo [], int cantidad, char nombreArchCliente []);
int randomTipoCuenta();
int randomIdCliente(char nombreArchivo []);
stCuenta cuentasRandomPorCantidad (int cantidad, FILE * archiCuenta);
int cantCuentasArchivo (FILE * archiCuenta);
int randomNroCuenta(FILE * archi);


#endif // MOCKCUENTA_H_INCLUDED
