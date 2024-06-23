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

stCuenta altaCuentaUsuario(FILE *  archi, char nombreArchCliente []);
void cargaCuentaUsuario2Arch(char nombreArchivo [], char nombreArchCliente []);
void mostrarDatosCuenta(stCuenta cuenta);
void mostrarCuentasDesdeArch(char nombreArchivo []);
void consultaCuentaPorId(char nombreArchivo [], int id);
int existeCuenta(FILE * archi, int numeroCuenta);
int id (FILE* archi);
float costoMantenimiento(int tipoCuenta);
stCuenta buscaCuentaPorId (char nombreArchivo [], int idCuenta);
int cambioEstadoCuentaPorId (char nombreArchivo [], int idCuenta);
void listarCuentasPorCliente(char nombreArchivo [], int idCliente);
int contarCantRegistros(char nombreArchivo [], int tamStruc);//ver borrar
int id (FILE* archi);
int modificaTipoCuentaPorId(char nombreArchivo [], int id, int tipoCuenta);
void tipoDeCuentaString(int tipoCuenta);
void estado2String(int eliminado);
//void listadoCuentas(char nombreArchivo []); Listar tipo listado


#endif // CUENTA_H_INCLUDED
