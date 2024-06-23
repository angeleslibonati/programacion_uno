#ifndef CUENTA_H_INCLUDED
#define CUENTA_H_INCLUDED
#include <stdio.h>

typedef struct {
int id;
int idCliente;
int nroCuenta;
int tipoDeCuenta;
float costoMensual;
float saldo;
int eliminado;

} stCuenta;

void consultaCuentaPorId(char nombreArchivo [], int id);
int existeCuenta(FILE * archi, int tipoCuenta, int numeroCuenta);
void mostrarCuentasDesdeArch(char nombreArchivo []);
void cargaCuentaUsuario2Arch(char nombreArchivo []);
int id (FILE* archi);
void mostrarDatosCuenta(stCuenta cuenta);
stCuenta altaCuentaUsuario(FILE *  archi);
float costoMantenimiento(int tipoCuenta);
stCuenta buscaCuentaPorId (char nombreArchivo [], int idCuenta);
stCuenta buscaCuentaPorNumCuenta (char nombreArchivo [], int nroCuenta);
int existeCuentaNroCuenta(char nombreArchivo[], int numeroCuenta);
int cambioEstadoCuentaPorId (char nombreArchivo [], int idCuenta);
void listarCuentasPorCliente(char nombreArchivo [], int idCliente);
int contarCantRegistros(char nombreArchivo [], int tamStruc);//ver borrar
int id (FILE* archi);
int modificaTipoCuentaPorId(char nombreArchivo [], int id, int tipoCuenta);

#endif // CUENTA_H_INCLUDED
