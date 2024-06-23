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

<<<<<<< HEAD
/*int getAltaMovimiento (int cantidad)
{


    return ;
}*/
=======
>>>>>>> c9bcb08e93a2b14037ed41dc5da476b552651a83


//Carga movimientos en archivo
void cargaArchivoMovimientosRandom(char nombreArchivo [],char nombreArchivoCuenta[], int cantidad)
{
    stMovimiento movBancario;
    stCuenta cuenta;

    FILE * archi = fopen(nombreArchivo, "ab");
    FILE * archiCuenta = fopen(nombreArchivoCuenta, "rb");

    if (archi && archiCuenta) {

        for (int i = 0; i < cantidad; i++) {

            movBancario = inicializarMovimiento(cuenta);
            getDescripcionMov(movBancario.detalle, movBancario.importe);
            fseek(archi, 0, 2);
            fwrite(&movBancario, sizeof(stMovimiento), 1, archi);
        }
        fclose(archi);
        fclose(archiCuenta);
    }
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
