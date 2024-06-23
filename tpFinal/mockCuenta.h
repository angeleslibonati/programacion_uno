#ifndef MOCKCUENTA_H_INCLUDED
#define MOCKCUENTA_H_INCLUDED

stCuenta altaCuentaRandom(FILE * archi, char nombreArchCliente []);
void cargaArchivoCuentaRandom(char nombreArchivo [], int cantidad, char nombreArchCliente []);
int randomTipoCuenta();
int randomIdCliente(char nombreArchivo []);
<<<<<<< HEAD
int randomNroCuenta(FILE * archi, int tipoCuenta);
stCuenta cuentasRandomPorCantidad (int cantidad, FILE * archiCuenta);
int cantCuentasArchivo (FILE * archiCuenta);
=======
int randomNroCuenta(FILE * archi);
>>>>>>> 8978953f446fdf0309b51f83f13015fc75e2aa23

#endif // MOCKCUENTA_H_INCLUDED
