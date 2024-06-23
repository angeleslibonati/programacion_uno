#ifndef MOCKCUENTA_H_INCLUDED
#define MOCKCUENTA_H_INCLUDED

stCuenta altaCuentaRandom(FILE * archi);
void cargaArchivoCuentaRandom(char nombreArchivo [], int cantidad);
int randomTipoCuenta();
int randomIdCliente(char nombreArchivo []);
int randomNroCuenta(FILE * archi, int tipoCuenta);
stCuenta cuentasRandomPorCantidad (int cantidad, FILE * archiCuenta);
int cantCuentasArchivo (FILE * archiCuenta);

#endif // MOCKCUENTA_H_INCLUDED
