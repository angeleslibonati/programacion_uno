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
    else if (movBancario.mes == 4)
    {
        dia = (rand ()% 30) + 1;
    }
    else if (movBancario.mes == 6)
    {
        dia = (rand ()% 23) + 1;
    }
    else
    {
        dia = (rand ()% 31) + 1;
    }

    return dia;
}

int getMes ()
{
    return (rand()% 6) +1 ;
}


int getAnio ()
{
    return 2024;
}



//Carga movimientos en archivo
int cargaArchivoMovimientosRandom(char nombreArchivo [],char nombreArchivoCuenta[], int cantidad)
{
    int flag = 0;
    stMovimiento movBancario;
    stCuenta cuenta;

    FILE * archi = fopen(nombreArchivo, "ab");
    FILE * archiCuenta = fopen(nombreArchivoCuenta, "r+b");

    if (archi && archiCuenta) {

        int cantidad = cantCuentasArchivo (archiCuenta);

        for (int i = 0; i < cantidad; i++) {

            cuenta = cuentasRandomPorCantidad (cantidad,archiCuenta);

            movBancario = inicializarMovimiento(archi);
            movBancario.idCuenta = cuenta.nroCuenta;

            if (cuenta.id % 2 == 0 && cuenta.tipoDeCuenta == 3){

                movBancario.importe =((rand ()% 5000) +1)*(-1);
                flag = 1;
            }
            else {
                movBancario.importe =(rand ()% 5000) +1;
                flag = 1;
            }
            cuenta.saldo += movBancario.importe;

            getDescripcionMov(movBancario.detalle, movBancario.importe);

            fseek(archi, 0, 2);
            fwrite(&movBancario, sizeof(stMovimiento), 1, archi);

            fseek(archiCuenta,sizeof(stCuenta)*(cuenta.id - 1),0);
            fwrite(&cuenta, sizeof(stCuenta), 1, archiCuenta);
        }
        fclose(archi);
        fclose(archiCuenta);
    }
    return flag;
}



///ramdom descripcion movimiento

void getDescripcionMov(char descMov[], float importe)
{
    char movPos[][30] =
    {
        "Haberes", "Transf. de Cta. Propia", "Transf. de Cta. de Terceros" , "Acred. Plazo Fijo", "Acred. Deposito"
    };
    char movNeg[][30] = {
        "Pago Tarj. Credito", "Transf. a Cta. de Terceros", "Transf. a Cta. Propia", "Deposito Plazo Fijo"
    };

    if(importe > 0) {
        strcpy(descMov, movPos[rand()%(sizeof(movPos)/30)]);
    } else {
        strcpy(descMov, movNeg[rand()%(sizeof(movPos)/30)]);
    }
}
