#ifndef MOCKMOVIMIENTO_H_INCLUDED
#define MOCKMOVIMIENTO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "domicilio.h"
#include "mockDomicilio.h"
#include "cliente.h"
#include "mockCliente.h"
#include "menu.h"
#include "cuenta.h"
#include "mockCuenta.h"
#include "movimiento.h"

int getDia ();
int getMes ();
int getAnio ();
int idMovimiento (FILE * archi);
int getAltaMovimiento (int getMes, int getDia, stMovimiento movBancario, stCuenta cuenta, char nombreArchivo[], int idCuenta);
void getDescripcionMov(char descMov[], float importe);


#endif // MOCKMOVIMIENTO_H_INCLUDED
