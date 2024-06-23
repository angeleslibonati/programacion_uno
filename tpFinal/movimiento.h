#ifndef MOVIMIENTO_H_INCLUDED
#define MOVIMIENTO_H_INCLUDED
#include <stdio.h>
#include "cuenta.h"

typedef struct
{
    int id; //campo unico y auto incrementable
    int idCuenta;  //id de la cuenta. Relacion con stCuenta.
    char detalle [100];  //descripcion de operacion.
    float importe;
    int anio;
    int mes;  //validar del 1 al 12 (segun mes)
    int dia;  //validar del 1 al... (segun cantidad de dias, por mes)
    int eliminado; // "0" es activo. "1" eliminado.

}stMovimiento;

void mostrarMovimiento (stMovimiento movBancario);
void cargarMovimientosToArchivo (char nombreArchivo [], char nombreArchivoCuenta[]);
stMovimiento inicializarMovimiento ();
void ejecutaDeposito (float importe, char nombreArchivoMov[], stMovimiento movBancario, char nombreArchivoCuenta[],stCuenta cuenta);
void ejecutarExtraccion (char nombreArchivoMov [], char nombreArchivoCuenta[], stMovimiento movBancario,stCuenta cuenta, float importe);
void escribirMovimiento (char nombreArchivo [], stMovimiento movBancario, float importe, stCuenta cuenta);
void opcionMovimiento (stMovimiento movBancario, char nombreArchivoMov[], char nombreArchivoCuenta []);
int modificacionImporte (float importe, char nombreArchivo[], int id);
stMovimiento buscaMovimiento (int id, FILE * archi);
int cambioEstadoMovimientoPorId (char nombreArchivo [], int id);
stMovimiento buscaMovimientoPorId (char nombreArchivo [], int id);
void listadoMovimientoCuenta (int idCuenta, char nombreArchivo[]);
void listadoMovimientoMes (int mes, char nombreArchivo[]);
void mostrarMovimientosDesdeArch(char nombreArchivo []);

#endif // MOVIMIENTO_H_INCLUDED
