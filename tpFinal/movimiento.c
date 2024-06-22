#include <stdio.h>
#include <stdlib.h>
#include "movimiento.h"
#include "mockMovimiento.h"
#include "domicilio.h"
#include "mockDomicilio.h"
#include "cliente.h"
#include "mockCliente.h"
#include "menu.h"
#include "cuenta.h"
#include "mockCuenta.h"


#define AR_MOVIMIENTO "movimiento.dat"


stMovimiento inicializarMovimiento (FILE * archi)
{
    stMovimiento movBancario;
    stCuenta cuenta;

    movBancario.id = idMovimiento(archi);

    movBancario.idCuenta = cuenta.nroCuenta;

    printf("num cuenta: %d\n", cuenta.nroCuenta);
    printf("num id cuenta. : %d\n", movBancario.idCuenta);

    printf("Ingrese el detalle de la operacion\n");
    fflush(stdin);
    gets(movBancario.detalle);
    movBancario.importe = 0.0;
    movBancario.anio = getAnio();
    movBancario.mes = getMes();
    movBancario.dia = getDia;
    movBancario.eliminado = 0;
    printf("Cargando...\n");
    system ("pause");
    system ("cls");
    return movBancario;
}

void cargarMovimientosToArchivo (char nombreArchivo [])
{
    stMovimiento movBancario;
    stCuenta cuenta;
    FILE * archi = fopen(nombreArchivo, "ab");

    if (archi){

        movBancario = inicializarMovimiento(archi);
        fseek(archi,0,2);
        fwrite(&movBancario, sizeof(stMovimiento),1, archi);

        fclose(archi);
    }
}

void mostrarMovimiento (stMovimiento movBancario)
{
    puts("_______________________________________\n");
    printf("\nID:...................: %d", movBancario.id);
    printf("\nID Cuenta:............: %d", movBancario.idCuenta);
    printf("\nDetalle:..............: %s", movBancario.detalle);
    printf("\nImporte:..............: %.2f", movBancario.importe);
    printf("\nAA/MM/DD:.............: %d/ %d/ %d", movBancario.anio, movBancario.mes, movBancario.dia);
    printf("\nEstado:...............: %d", movBancario.eliminado);
    puts("\n_______________________________________\n");


}



//AMBL MOVIMIENTO

//Alta de Movimiento  (realiza extraccion o deposito)

void escribirMovimiento (char nombreArchivo [], stMovimiento movBancario, float importe)
{
    FILE * archi = fopen(nombreArchivo, "ab");

    if (archi)
    {

        fwrite(&movBancario.importe, sizeof(stMovimiento), 1, archi);
        fclose(archi);
    }

}

void ejecutarExtraccion (char nombreArchivoMov [], char nombreArchivoCuenta[], stMovimiento movBancario, float importe)
{
    FILE * archiCuenta = fopen(nombreArchivoCuenta, "r+b");
    stCuenta cuenta;

    if (archiCuenta){


        if (importe <= cuenta.saldo)
        {
            cuenta.saldo = (float) cuenta.saldo - importe;
            fwrite(&cuenta.saldo, sizeof(stCuenta) * (cuenta.id - 1),1,archiCuenta);
            escribirMovimiento(nombreArchivoMov,movBancario,importe);
        }
        else
        {
            printf("Saldo no disponible.\n");
        }
        fclose(archiCuenta);
    }

}

void ejecutaDeposito (float importe, char nombreArchivoMov[], stMovimiento movBancario, char nombreArchivoCuenta[])
{
    stCuenta cuenta;

    if (importe <= 0 )
    {

        printf("El saldo ingresado es invalido.\n");
    }
    else
    {
        cuenta.saldo = (float) cuenta.saldo + importe;

        escribirMovimiento(nombreArchivoMov,movBancario, importe);
        fseek (nombreArchivoCuenta, sizeof(stCuenta) * (cuenta.id-1),0);
        fwrite (&cuenta.saldo,sizeof(stCuenta),1,nombreArchivoCuenta);
    }
}

void opcionMovimiento (stMovimiento movBancario, char nombreArchivoMov[], char nombreArchivoCuenta [])
{
    float monto = 0;
    int opcion = 0;


    printf("Ingrese 1 para Extraccion.\n");
    printf("Ingrese 2 para Deposito.\n");
    printf("Ingrese 0 para Salir.\n");
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 0:
        system ("cls");
        imprimirCabecera("MOVIMIENTOS");
        printf("\n\n");
        imprimeOpcionesSubMenu();
        switchSubMenuMovimiento();
        system ("pause");

        break;

    case 1:

        printf("Ingrese el monto para la extraccion.\n");
        scanf ("%f", &monto);
        //int numId = ingresaID();
        ejecutarExtraccion(nombreArchivoMov, nombreArchivoCuenta, movBancario,monto);

        break;
    case 2:

        printf("Ingrese el monto a Depositar.\n");
        scanf("%f",&monto);
       //numId = ingresaID();
        ejecutaDeposito(monto,nombreArchivoMov, movBancario,nombreArchivoCuenta);

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

int cambioEstadoMovimientoPorId (char nombreArchivo [], int id)
{
    stMovimiento movBancario;
    int posMovBancario;
    int flag = 0;

    movBancario = buscaMovimientoPorId(nombreArchivo, id);
    posMovBancario = sizeof (stMovimiento) * (movBancario.id - 1) ;

    FILE * archi = fopen(nombreArchivo, "r+b");

    if (archi)
    {

        if (movBancario.id > 0)
        {
            if(movBancario.eliminado == 0)
            {
                movBancario.eliminado = 1;
            }
            else
            {
                movBancario.eliminado = 0;
            }
            fseek(archi, posMovBancario, SEEK_SET);
            fwrite(&movBancario, sizeof(stMovimiento), 1, archi);

            flag = 1;
        }
        fclose(archi);
    }

    return flag;
}

//Busca movimiento por ID. Si movBancario.id == 0, el movimiento no existe

//Consulta de Movimiento

stMovimiento buscaMovimientoPorId (char nombreArchivo [], int id)
{
    stMovimiento movBancario;
    movBancario.id = 0;
    int flag = 0;

    FILE * archi = fopen(nombreArchivo, "rb");

    if (archi)
    {

        while (flag == 0 && fread(&movBancario, sizeof(stMovimiento), 1, archi) > 0)
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
    stCuenta cuenta;

    FILE * archi = fopen(nombreArchivo, "r+b");

    if(archi)
    {
        while(fread(&movBancario,sizeof(stMovimiento),1, archi) > 0)
        {
            if (cuenta.nroCuenta)
            {

                mostrarMovimiento(movBancario);
            }
        }
        fclose(archi);
    }
}

//Listado de Movimentos(Por mes)
void listadoMovimientoMes (int mes, char nombreArchivo[])
{
    stMovimiento movBancario;
    FILE * archi = fopen(nombreArchivo, "r+b");

    if(archi)
    {
        while(fread(&movBancario, sizeof(stMovimiento),1, archi) >0)
        {
            if(movBancario.mes == mes)
            {

                mostrarMovimiento(movBancario);
            }

        }
        fclose(archi);
    }
}

//Listado de todos los moviminetos en Archivo

void mostrarMovimientosDesdeArch(char nombreArchivo [])
{
    FILE * archi = fopen(nombreArchivo, "rb");
    stMovimiento movBancario;

    if (archi) {
        while(fread(&movBancario, sizeof(stMovimiento), 1, archi) > 0) {
            mostrarMovimiento(movBancario);
        }
        fclose(archi);
    }
}
