#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "domicilio.h"
#include "mockDomicilio.h"
#include "cliente.h"
#include "mockCliente.h"
#include "movimiento.h"
#include "mockMovimiento.h"
#include "cuenta.h"
#include "mockCuenta.h"

#define AR_CLIENTE "archivoClientes.dat"
#define AR_CUENTA "cuenta.dat"
#define AR_MOVIMIENTO "movimiento.dat"


//Funcion generica para mostrar una cabecera con un recuadro
void imprimirCabecera(char cabecera[]){
    int i;
    printf("%c", 201);
    for(i=0; i<50; i++)
    {
        printf("%c",205);
    }
    printf("%c\n", 187);
    printf("%c%32s%19c\n", 186,cabecera,186);
    printf("%c", 200);
    for(i=0; i<50; i++)
    {
        printf("%c",205);
    }
    printf("%c", 188);
}

void imprimeOpcionMenuPrincipal ()
{
    printf("1. CLIENTE\n");
    printf("2. CUENTA\n");
    printf("3. MOVIMIENTO\n");
    printf("0. SALIR\n");

}

void iniciarMenu()
{
    int salida;
    do
    {
        system("cls");
        imprimirCabecera("MENU PRINCIPAL");
        printf("\n\n");
        imprimeOpcionMenuPrincipal();
        salida = switchMenuPrincipal();

    }while(salida != 0);
}

int ingresaOpcion ()
{
    int opcion = 0;
    printf("\nIngrese la opcion\n");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int imprimirSolicitarDato (char txtDato[])
{
    int numId = 0;
    printf("\n%s\n", txtDato);
    fflush(stdin);
    scanf("%d", &numId);

    return numId;
}

int switchMenuPrincipal ()
{
    int opcion = 0;

    do
    {
        opcion = ingresaOpcion ();

        switch (opcion)
        {
        case 0:
            // SALE DEL PROGRAMA.
            printf("\nHasta la proxima.\n");
            exit(0);

            break;
        case 1:

            //LLAMA FUNCION DEL MENU CLIENTE.
            system ("cls");
            imprimirCabecera ("CLIENTES");
            printf("\n\n");
            switchSubMenuCliente();
            system("pause");

            break;

        case 2:

            //LLAMA FUNCION DEL MENU CUENTA.
            system("cls");
            imprimirCabecera("CUENTA");
            printf("\n\n");
            swithcSubMenuCuenta();
            system ("pause");

            break;

        case 3:

            //LLAMA FUNCION DEL MENU MOVIMIENTO.
            system ("cls");
            imprimirCabecera("MOVIMIENTOS");
            printf("\n\n");
            switchSubMenuMovimiento();
            system("pause");

            break;
        case 4:
            //LLAMA A LAS FUNCIONES DE CARGA AUTOMATICA.
            system ("cls");
            imprimirCabecera("MAS OPCIONES");
            printf("\n\n");
            swithSubMenuOpciones();

            break;

        default:

            printf("Opcion invalida");
        }

    }while (opcion != 0);

    return opcion;
}

void imprineOpcionesSubMenuOpciones()
{
    printf("\n1. CARGA CLIENTE RANDOM\n");
    printf("2. CARGA CUENTA RANDOM\n");
    printf("3. CARGA MOVIMIENTOS RANDOM\n");
    printf("0. REGRESA\n");
}

void swithSubMenuOpciones ()
{
    int opcion = 0;
    int cantidad = 0;

    do
    {
        imprineOpcionesSubMenuOpciones();
        opcion = ingresaOpcion();

        switch (opcion)
        {
        case 0:

            //volver al menu anterior
            system ("cls");
            imprimirCabecera("MENU PRINCIPAL");
            printf("\n\n");
            imprimeOpcionMenuPrincipal();
            switchMenuPrincipal();

            break;

        case 1:

            //carga random de clientes
            system ("cls");
            imprimirCabecera("CARGA CLIENTES RANDOM");
            printf("\n\n");
            printf("Ingrese la cantidad de clientes que desea cargar\n");
            fflush(stdin);
            scanf("%d", &cantidad);
            int flag = cargaArchivoClientesRandoms(AR_CLIENTE, cantidad);

            if (flag == 1){

                system("cls");
                imprimirCabecera("CARGA EXITOSA");
                printf("\n\n");
            }

            break;

        case 2:

            //carga random de cuentas
            system ("cls");
            imprimirCabecera("CARGA CUENTAS RANDOM");
            printf("\n\n");
            printf("Ingrese la cantidad de cuentas que desea cargar\n");
            fflush(stdin);
            scanf("%d", &cantidad);
//            flag = cargaArchivoCuentaRandom(AR_CUENTA, cantidad);
//
//            if (flag == 1){
//
//                system("cls");
//                imprimirCabecera("CARGA EXITOSA");
//                printf("\n\n");
//            }
            break;

        case 3:

            //carga random movimientos
            system ("cls");
            imprimirCabecera("CARGA MOVIMIENTOS RANDOM");
            printf("\n\n");
            printf("Ingrese la cantidad de movimientos que desea cargar\n");
            fflush(stdin);
            scanf("%d", &cantidad);
            flag = cargaArchivoMovimientosRandom (AR_MOVIMIENTO,AR_CUENTA,cantidad);
            if (flag == 1){

                system("cls");
                imprimirCabecera("CARGA EXITOSA");
                printf("\n\n");
            }

            break;

        default:

            printf("Opcion invalida\n");
        }

    }while (opcion != 0);

}

void imprimeOpcionesSubMenu ()
{
    printf("\n1. Alta\n");
    printf("2. Baja\n");
    printf("3. Modificacion\n");
    printf("4. Consultar\n");
    printf("5. Listado\n");
    printf("0. Volver Atras\n");
}

void switchSubMenuCliente ()
{
    int opcion = 0;

    do
    {
        imprimeOpcionesSubMenu();
        opcion = ingresaOpcion();

        switch (opcion)
        {
        case 0:

            //volver al menu anterior
            system ("cls");
            imprimirCabecera("MENU PRINCIPAL");
            printf("\n\n");
            imprimeOpcionMenuPrincipal();
            switchMenuPrincipal();

            break;

        case 1:

            //ALTA CLIENTE
            system ("cls");
            imprimirCabecera("ALTA DE CLIENTE");
            printf("\n\n");
            altaCliente(AR_CLIENTE);
            imprimirCabecera("CARGA EXITOSA");

            break;

        case 2:

            //BAJA CLIENTE
            system ("cls");
            imprimirCabecera("BAJA DE CLIENTE");
            printf("\n\n");

            int numId = imprimirSolicitarDato("\nIngrese el ID");

            int flag = bajaCliente(AR_CLIENTE,numId);
            if(flag){
                imprimirCabecera("CLIENTE ELIMINADO");
            } else {
                imprimirCabecera("ERROR AL ELIMINAR");
            }

            break;

        case 3:

            //MODIFICACION DE CLIENTE
            system ("cls");
            imprimirCabecera("MODIFICACION DE CLIENTE");
            printf("\n\n");

            numId = imprimirSolicitarDato("\nIngrese el ID");

            stCliente cliente;
            cliente = buscarClientePorId(AR_CLIENTE,numId);
            muestraCliente(cliente);
            imprimeOpcionSubMenuModificar ();
            opcion = ingresaOpcion ();
            modificaCliente(AR_CLIENTE, id, opcion);
            system ("cls");
            muestraCliente(cliente);
            system ("pause");   //prestar atencion por si tenemos q sacarlo.

            break;

        case 4:

            //CONSULTAR UN CLIENTE
            system ("cls");
            imprimirCabecera("BUSCAR UN CLIENTE");
            printf("\n\n");

            numId = imprimirSolicitarDato("\nIngrese el ID");
            cliente = buscarClientePorId(AR_CLIENTE, numId);
            muestraCliente(cliente);


            break;

        case 5:

            //LISTADO DE CLIENTES
            system("cls");
            imprimirCabecera("LISTADO CLIENTES");
            printf("\n\n");
            mostrarClientesDesdeArch(AR_CLIENTE);

            break;

        default:

            printf("Opcion invalida\n");
        }
    }while(opcion != 0);
}

void imprimeOpcionSubMenuModificar ()
{
    printf("1. NOMBRE\n");
    printf("2. APELLIDO\n");
    printf("3. DNI\n");
    printf("4. EMAIL\n");
    printf("5. DOMICILIO\n");
    printf("6. TELEFONO\n");
    printf("0. VOLVER ATRAS\n");
}


void swithcSubMenuCuenta ()
{
    int opcion = 0;

    do
    {
        imprimeOpcionesSubMenu();
        opcion = ingresaOpcion();
        int numId;

        switch (opcion)
        {
        case 0:

            //volver al menu anterior
            system ("cls");
            imprimirCabecera("MENU PRINCIPAL");
            printf("\n\n");
            imprimeOpcionMenuPrincipal();
            switchMenuPrincipal();
            break;

        case 1:

            //ALTA CUENTA
            system ("cls");
            imprimirCabecera("ALTA DE CUENTA");
            printf("\n\n");
            cargaCuentaUsuario2Arch(AR_CUENTA, AR_CLIENTE);

            break;

        case 2:

            //BAJA CUENTA
            system ("cls");
            imprimirCabecera("BAJA DE CUENTA");
            printf("\n\n");

            numId = imprimirSolicitarDato("\nIngrese el ID");
            int flag = cambioEstadoCuentaPorId(AR_CUENTA, numId);

            if(flag){
                imprimirCabecera("CUENTA ELIMINADA");
            } else {
                imprimirCabecera("ERROR AL ELIMINAR");
            }
            break;

       case 3:

            //MODIFICACION DE CUENTA
            system ("cls");
            imprimirCabecera("MODIFICACION DE CUENTA");
            printf("\n\n");

            numId = imprimirSolicitarDato("\nIngrese el ID");

            int tipoCuenta;

            printf("\n 1. Caja de Ahorro en Pesos, 2. Caja de Ahorro en U$D, 3. Cta Cte en $");
            printf("\nIngrese el tipo de cuenta: ");
            scanf("%d", &tipoCuenta);

            flag = modificaTipoCuentaPorId(AR_CUENTA, numId, tipoCuenta);
            if(flag){
                imprimirCabecera("TIPO DE CUENTA MODIFICADO");
            } else {
                imprimirCabecera("ERROR AL MODIFICAR");
            }
            break;

        case 4:

            //CONSULTAR UN CUENTA
            system ("cls");
            imprimirCabecera("BUSCAR UNA CUENTA");
            printf("\n\n");

            numId = imprimirSolicitarDato("\nIngrese el ID");

            consultaCuentaPorId(AR_CUENTA, numId);
            break;

        case 5:

            //LISTADO DE CUENTAS
            system("cls");
            imprimirCabecera("LISTADO CUENTAS");
            printf("\n\n");
            mostrarCuentasDesdeArch(AR_CUENTA);
            break;
        default:

            printf("No podemos procesar la opcion ingresada.\n");
        }
    }while(opcion != 0);
}

void switchSubMenuMovimiento ()
{
    int opcion;

    do
    {
        imprimeOpcionesSubMenu();
        opcion = ingresaOpcion();
        int numId;

        switch (opcion)
        {
        case 0:

            //volver al menu anterior
            system ("cls");
            imprimirCabecera("MENU PRINCIPAL");
            printf("\n\n");
            imprimeOpcionMenuPrincipal();
            switchMenuPrincipal();
            break;

        case 1:

            //ALTA MOVIMIENTO
            system ("cls");
            imprimirCabecera("ALTA DE MOVIMIENTO");
            printf("\n\n");
<<<<<<< HEAD
            ///AGREGAR FUNCION CORRESPONDIENTE
=======

            opcionMovimiento(AR_MOVIMIENTO,AR_CUENTA);

>>>>>>> 64c2f33f20f1383bd7e8448b1aaa804827dc4da4
            break;

        case 2:

            //BAJA MOVIMIENTO
            system ("cls");
            imprimirCabecera("BAJA DE MOVIMIENTO");
            printf("\n\n");
<<<<<<< HEAD
            numId = ingresaID();
=======

            numId = imprimirSolicitarDato("\nIngrese el ID");

>>>>>>> c9bcb08e93a2b14037ed41dc5da476b552651a83
            int flag = cambioEstadoMovimientoPorId(AR_MOVIMIENTO,numId);
            if(flag){
                imprimirCabecera("MOVIMIENTO ELIMINADO");
            } else {
                imprimirCabecera("ERROR AL ELIMINAR");
            }

            break;

        case 3:

            //MODIFICACION MOVIMIENTO
            system ("cls");
            imprimirCabecera("MODIFICACION DEL IMPORTE");
            printf("\n\n");
            numId = imprimirSolicitarDato("\nIngrese el ID");
            printf("Ingrese el importe para modificar.\n");
            float nuevoImporte;
            fflush(stdin);
            scanf("%f", &nuevoImporte);
            flag = modificacionImporte(nuevoImporte, AR_MOVIMIENTO, numId);

            if(flag){
                imprimirCabecera("IMPORTE MODIFICADO");
            } else {
                imprimirCabecera("ERROR REINTENTE");
            }

            break;

        case 4:

            //CONSULTA DE MOVIMIENTO
            system ("cls");
            imprimirCabecera("CONSULTA DE MOVIMIENTO");
            printf("\n\n");
<<<<<<< HEAD
            numId = ingresaID();
            stMovimiento movBancario = buscaMovimientoPorId(AR_MOVIMIENTO, numId);
            muestraUnMovimiento(movBancario);
=======

            numId = imprimirSolicitarDato("\nIngrese el ID");
            stMovimiento movBancario = buscaMovimientoPorId(AR_MOVIMIENTO, numId);
            mostrarMovimiento(movBancario);
>>>>>>> c9bcb08e93a2b14037ed41dc5da476b552651a83

            break;

        case 5:

            //LISTADO DE MOVIMIENTOS
            system ("cls");
            imprimirCabecera("LISTADO DE MOVIMIENTOS");
            printf("\n\n");
            switSubMenuListado();

            break;

        default:

            printf("No podemos procesar la opcion ingresada.\n");
        }
    }while(opcion != 0);
}

void imprimirOpcionListado()
{
    printf("1. NUMERO DE CUENTA\n");
    printf("2. MES\n");
    printf("0. VOLVER ATRAS\n");
}
void switSubMenuListado()
{
    imprimirOpcionListado();
    int opcion;
    do
    {
        opcion = ingresaOpcion();
        int numId;

        switch (opcion)
        {

        case 0:
            //VUELVE MENU ANTERIOR
            system ("cls");
            imprimirCabecera("MOVIMIENTOS");
            printf("\n\n");
            imprimeOpcionesSubMenu();
            switchSubMenuMovimiento();
            system ("pause");
            break;

        case 1:

            //MOVIMIENTOS POR NUMERO DE CUENTA.
            system ("cls");
            imprimirCabecera("MOVIMIENTO POR NUM. CUENTA");
            printf("\n\n");
            numId = imprimirSolicitarDato("\nIngrese el Numero de Cuenta");
            listadoMovimientoCuenta(numId, AR_MOVIMIENTO);

            break;
        case 2:
            //MOVIMIENTO POR MES.
            system ("cls");
            imprimirCabecera("MOVIMIENTO POR MES");
            printf("\n\n");
            int mes;
            do{
                printf("Ingrese el mes para buscar. (1 al 12)\n");

                scanf("%d", &mes);
                if(mes < 1 || mes > 12){
                    printf("Opcion invalida.\n");
                    printf("Reintente\n");
                }

            }while (mes < 1 || mes > 12);

            listadoMovimientoMes(mes, AR_MOVIMIENTO);

            break;
        default:
            printf("Opcion invalida\n");
        }

    }while (opcion != 0);

}

