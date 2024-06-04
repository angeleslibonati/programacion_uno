#include "mockMovimiento.h"
#include "cuenta.h"

//campo unico autoincrementable
int id (int id)
{
    id += 1;

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
    extraccionDepositoDinero(archi,movBancario, saldoRand,idCuenta);

    return saldoRand;
}

