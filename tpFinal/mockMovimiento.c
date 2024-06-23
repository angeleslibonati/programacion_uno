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
    int id = 0;

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
    stMovimiento movBancario;

    int dia = 0;
    int mes = 0;

    movBancario.mes = getMes();

    if (movBancario.mes == 2)
    {
        dia = (rand ()% 28) + 1;
    }
    else if (movBancario.mes == 4 || movBancario.mes == 6 || movBancario.mes == 9 || movBancario.mes == 11)
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
    return (rand ()% 104) + 1920;
}

int getAltaMovimiento (int getMes, int getDia, stMovimiento movBancario, stCuenta cuenta, char nombreArchivo[], int idCuenta)
{

    int saldoRand = (rand()% 1000) + 1;
    escribirMovimiento(nombreArchivo,movBancario,saldoRand,cuenta);

    return saldoRand;
}


//Carga movimientos en archivo
void cargaArchivoMovimientos(char nombreArchivo [],char nombreArchivoCuenta[], int cantidad)
{
    stMovimiento movBancario;
    stCuenta cuenta;

    FILE * archi = fopen(nombreArchivo, "ab");
    FILE * archiCuenta = fopen(nombreArchivoCuenta, "rb");

    if (archi && archiCuenta) {

        for (int i = 0; i < cantidad; i++) {

            movBancario = inicializarMovimiento(cuenta);

            fseek(archi, 0, 2);
            fwrite(&movBancario, sizeof(stMovimiento), 1, archi);
        }
        fclose(archi);
        fclose(archiCuenta);
    }
}

