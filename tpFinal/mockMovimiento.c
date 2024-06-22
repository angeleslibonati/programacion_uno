#include "movimiento.h"
#include "mockMovimiento.h"
#include "domicilio.h"
#include "mockDomicilio.h"
#include "cliente.h"
#include "mockCliente.h"
#include "menu.h"
#include "cuenta.h"
#include "mockCuenta.h"

//campo unico autoincrementable
int idMovimiento (FILE * archi)
{
    int id;

    fseek(archi, 0, 2);

    int cant = ftell(archi)/sizeof(stMovimiento);

    if(cant > 0)
    {
        id = cant + 1;
    }
    else
    {
        id = 1;
    }
    return id;
}

int getDia ()
{
    int dia = 0;
    int mes = 0;

    mes = getMes();

    if (mes == 2)
    {
        dia = (rand ()% 28) + 1;
    }
    else if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        dia = (rand ()% 30) + 1;
    }
    else
    {
        dia = (rand ()% 31) + 1;
    }

    return dia;
}

int getMes ()
{
    return (rand()% 12) +1 ;
}


int getAnio ()
{
    return (rand ()% 2024) + 1920;
}

int getAltaMovimiento (int getMes, int getDia, stMovimiento movBancario, stCuenta cuenta, char nombreArchivo[], int idCuenta)
{
    int saldoRand = (rand()% 1000) + 1;
    escribirMovimiento(nombreArchivo,movBancario,saldoRand);

    return saldoRand;
}

