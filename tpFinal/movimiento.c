#include <stdio.h>
#include <stdlib.h>
#include "movimiento.h"
#include "cuenta.h"


//AMBL MOVIMIENTO

//Alta de Movimiento  (realiza extraccion o deposito)

void extraccionDepositoDinero (char nombreArchivo[],stMovimiento movBancario, float importe, int idCuenta)
{

    //stMovimiento movBancario;
    int flag = 0;

    FILE * archi = fopen(nombreArchivo, "ab");

    if (archi)
    {
        fseek(archi,0,SEEK_SET);

        while (flag == 0 && fread(&movBancario,sizeof(stMovimiento),1,archi) > 0)
        {

            if (movBancario.idCuenta == idCuenta)
            {
                flag = 1;
            }
        }
        fseek(archi, -1 * sizeof(stMovimiento), SEEK_CUR);

        fwrite(&movBancario,sizeof(stMovimiento),1, archi);

    }

}



void opcionMovimiento (float importe, stCuenta cuenta, char nombreArchivo[],int idCuenta)
{
    int monto = 0;
    int opcion = 0;
    stMovimiento movBancario;

    printf("Ingrese 1 para Extraccion.\n");
    printf("Ingrese 2 para Deposito.\n");
    scanf("%d", &opcion);

    switch (opcion)
    {

    case 1:

        printf("Ingrese el monto para la extraccion.\n");
        scanf ("%d", &monto);

        if (monto <= cuenta.saldo)
        {
            cuenta.saldo = (float) cuenta.saldo - monto;

            extraccionDepositoDinero(archi,movBancario,importe,idCuenta);

        }
        else
        {
            printf("Saldo no disponible.\n");
        }

        break;
    case 2:

        printf("Ingrese el monto a Depositar.\n");
        scanf("%d",&monto);

        if (monto < 0 )
        {

            printf("El saldo ingresado es invalido.\n");
        }
        else
        {
            cuenta.saldo = (float) cuenta.saldo + monto;

            extraccionDepositoDinero(archi,movBancario,importe,idCuenta);
        }
        break;

    default:
        printf("Opcion invalida.\n");
    }
}



//Modificaicon de Movimiento (modifica importe en cuenta)
int modificacionImporte (float importe, char nombreArchivo[], int id)
{
    int flag = 0;
    stMovimiento movBancario;
    stMovimiento movActual;


    FILE * archi = fopen(nombreArchivo, "a+b");


    if(archi)
    {
        movBancario = buscaMovimiento (id, archi);
        movBancario.importe = importe;

        fseek(archi, 0, SEEK_SET);

        while (flag == 0 && fread(&movActual,sizeof(stMovimiento), 1, archi)> 0)
        {
            if(movActual.id == id)
            {
                flag = 1;
            }
        }
        fseek(archi,-1*sizeof(stMovimiento), SEEK_CUR);

        fwrite(&movBancario,sizeof(stMovimiento), 1, archi);

        fclose(archi);
    }

    return flag;
}

//utiliza el archivo por parametro, es para usar dentro de otra funcion.

stMovimiento buscaMovimiento (int id, FILE * archi)
{
    stMovimiento movBancario;
    int flag = 0;

    fseek(archi,sizeof(stMovimiento),SEEK_SET);

    if(archi)
    {

        while (flag == 0 && fread(&movBancario,sizeof(stMovimiento),1, archi)>0)
        {

            if (movBancario.id == id)
            {
                flag = 1;
            }

        }
    }

    return movBancario;
}

//Baja de Movimiento (cambia estado de activo "0" o eliminado "1")

int bajaMovimiento (int id, char nombreArchivo[])
{
    int flag = 0;
    stMovimiento movBancario;

    FILE * archi = fopen(nombreArchivo, "ab");

    if(archi)
    {

        movBancario = consultaMovimiento(id,nombreArchivo);

        if (movBancario.id == id)
        {

            flag = 1;
        }

        fclose(archi);
    }

    return flag;
}


//Consulta de Movimiento

stMovimiento consultaMovimiento (int id, char nombreArchivo[])
{
    stMovimiento movBancario;
    FILE * archi = fopen(nombreArchivo, "rb");

    int flag = 0;

    if(archi)
    {
        while (flag == 0 && fread(&movBancario,sizeof(stMovimiento),1, archi)>0)
        {

            if (movBancario.id == id)
            {
                flag = 1;
            }
        }
        fclose(archi);
    }

    return movBancario;
}

//Listado de Movimientos (Por cuenta)
void listadoMovimientoCuenta (int idCuenta, char nombreArchivo[])
{
    stMovimiento movBancario;
    FILE * archi = fopen(nombreArchivo, "rb");

    if(archi)
    {
        while(fread(&movBancario,sizeof(stMovimiento),1, archi) > 0)
        {

            muestraUnMovimiento(movBancario);
        }
        fclose(archi);
    }

}


//Listado de Movimentos(Por mes)
void listadoMovimientoMes (int idCuenta, int dia, int mes, int anio, char nombreArchivo[])
{
    stMovimiento movBancario;
    FILE * archi = fopen(nombreArchivo, "rb");

    if(archi)
    {

        while(fread(&movBancario, sizeof(stMovimiento),1, archi) >0)
        {

            muestraUnMovimiento(movBancario);

        }
        fclose(archi);
    }


}

//Muestra 1 movimiento

void muestraUnMovimiento (stMovimiento movBancario)
{
    printf("\nId N° ................ %d\n", movBancario.id);
    printf("\nId Cuenta N°................  %d\n", movBancario.idCuenta);
    printf("\nImporte $ ................  %f\n", movBancario.importe);
    printf("\nDetalle ....... %s\n", movBancario.detalle);
    printf("\nFecha de Movimiento ..... %d / %d / %d\n", movBancario.dia, movBancario.mes, movBancario.anio);
    printf("=======================================================================\n");

}



//Auto incremento id

int autoIncrementoId ()
{
    int id = 0;


    return id;
}
