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
#define AR_CUENTA "cuenta.dat"


stMovimiento inicializarMovimiento (FILE * archi)
{
    stMovimiento movBancario;

    movBancario.id = idMovimiento(archi);
    movBancario.idCuenta = 0;
    movBancario.detalle;
    movBancario.importe = 0.0;
    movBancario.anio = getAnio();
    movBancario.mes = getMes();
    movBancario.dia = getDia();
    movBancario.eliminado = 0;

    return movBancario;
}

void cargarMovimientosToArchivo (char nombreArchivo [], char nombreArchivoCuenta[])
{
    stMovimiento movBancario;
    stCuenta cuenta;

    FILE * archi = fopen(nombreArchivo, "ab");
    FILE * archiCuenta = fopen(nombreArchivoCuenta, "rb");

    if (archi){

        movBancario = inicializarMovimiento(archi);
        fseek(archi,0,2);
        fwrite(&movBancario, sizeof(stMovimiento),1, archi);

        fclose(archi);
        fclose(archiCuenta);
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
    printf("\nEstado:...............: ");
    estado2String(movBancario.eliminado);
    puts("\n_______________________________________\n");

}


//AMBL MOVIMIENTO

//Alta de Movimiento  (realiza extraccion o deposito)

void escribirMovimiento (char nombreArchivo [], float importe, stCuenta cuenta)
{
    stMovimiento movBancario;

    FILE * archi = fopen(nombreArchivo, "ab");

    if (archi)
    {
        movBancario = inicializarMovimiento(archi);

        movBancario.importe = importe;
        movBancario.id = idMovimiento(archi);
        movBancario.idCuenta = cuenta.nroCuenta;
        movBancario.anio = getAnio ();
        movBancario.mes = getMes ();
        movBancario.dia = getDia ();
        movBancario.eliminado = 0;
        printf("\nIngrese el detalle de la operacion\n");
        fflush(stdin);
        gets(movBancario.detalle);

        fwrite(&movBancario, sizeof(stMovimiento), 1, archi);

        fclose(archi);
    }
}

void ejecutarExtraccion (char nombreArchivoMov [], char nombreArchivoCuenta[], stCuenta cuenta, float importe)
{
    FILE * archiCuenta = fopen(nombreArchivoCuenta, "r+b");

    if (archiCuenta){

        if (importe <= cuenta.saldo)
        {
            cuenta.saldo = (float) cuenta.saldo - importe;

            fseek (archiCuenta, sizeof(stCuenta) * (cuenta.id-1),0);
            fwrite(&cuenta, sizeof(stCuenta) * (cuenta.id - 1),1,archiCuenta);
            escribirMovimiento(nombreArchivoMov, importe, cuenta);

            system("cls");
            imprimirCabecera("TICKET");
            mostrarDatosCuenta(cuenta);
        }
        else
        {
            printf("Saldo no disponible.\n");
        }
        fclose(archiCuenta);
    }
}

void ejecutaDeposito (float importe, char nombreArchivoMov[], char nombreArchivoCuenta[],stCuenta cuenta)
{
    FILE * archiCuenta = fopen(nombreArchivoCuenta,"r+b");

    if (archiCuenta){
        if (importe <= 0 )
        {
            printf("El monto ingresado es invalido.\n");
        }
        else
        {
            cuenta.saldo = (float) cuenta.saldo + importe;

            fseek (archiCuenta, sizeof(stCuenta) * (cuenta.id-1),0);
            fwrite (&cuenta,sizeof(stCuenta),1,archiCuenta);
            escribirMovimiento(nombreArchivoMov, importe, cuenta);

            system("cls");
            imprimirCabecera("TICKET");
            mostrarDatosCuenta(cuenta);
        }

        fclose(archiCuenta);
    }
}

void opcionMovimiento ( char nombreArchivoMov[], char nombreArchivoCuenta [])
{
    float monto = 0;
    int opcion = 0;
    int numCuenta = 0;


    printf("1. EXTRACCION.\n");
    printf("2. DEPOSITO.\n");
    printf("3. REGRESAR\n");
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

        system ("cls");
        imprimirCabecera("EXTRACCION");
        printf("\n\n");

        numCuenta = imprimirSolicitarDato("\nIngrese el Numero de Cuenta\n");

        printf("Ingrese el monto para la extraccion.\n");
        scanf ("%f", &monto);
        monto = monto*(-1);

        if (existeCuentaNroCuenta(nombreArchivoCuenta,numCuenta) == 1){

            stCuenta cuenta = buscaCuentaPorNumCuenta(AR_CUENTA,numCuenta);
            ejecutarExtraccion(nombreArchivoMov, nombreArchivoCuenta, cuenta, monto);
        }
        else{
            printf("\Numero de cuenta invalida.\n");
        }

        break;

    case 2:

        system ("cls");
        imprimirCabecera("DEPOSITO");
        printf("\n\n");

        numCuenta = imprimirSolicitarDato("\nIngrese el Numero de Cuenta\n");

        printf("Ingrese el monto a Depositar.\n");
        scanf("%f",&monto);

        if (existeCuentaNroCuenta (AR_CUENTA, numCuenta) == 1){

            stCuenta cuenta = buscaCuentaPorNumCuenta(AR_CUENTA, numCuenta);
            ejecutaDeposito(monto, nombreArchivoMov, nombreArchivoCuenta, cuenta);
        }
        else{
            printf("\Numero de cuenta invalida.\n");
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
