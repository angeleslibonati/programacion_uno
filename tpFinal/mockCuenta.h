#ifndef MOCKCUENTA_H_INCLUDED
#define MOCKCUENTA_H_INCLUDED

stCuenta altaCuentaRandom(FILE * archi, char nombreArchCliente []);
void cargaArchivoCuentaRandom(char nombreArchivo [], int cantidad, char nombreArchCliente []);
int randomTipoCuenta();
int randomIdCliente(char nombreArchivo []);
<<<<<<< HEAD
stCuenta cuentasRandomPorCantidad (int cantidad, FILE * archiCuenta);
int cantCuentasArchivo (FILE * archiCuenta);
int randomNroCuenta(FILE * archi);

=======
int randomNroCuenta(FILE * archi, int tipoCuenta);
stCuenta cuentasRandomPorCantidad (int cantidad, FILE * archiCuenta);
int cantCuentasArchivo (FILE * archiCuenta);
>>>>>>> be7afba (actualizacion menu)

#endif // MOCKCUENTA_H_INCLUDED
