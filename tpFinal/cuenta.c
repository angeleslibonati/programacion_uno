#include <stdio.h>
#include <stdlib.h>
#include "cuenta.h"
#include "mockCuenta.h"

//Alta cuenta con intervención del usuario
stCuenta altaCuentaUsuario(FILE *  archi) {
    stCuenta cuenta;
    int idCliente = 0;
    int tipoCuenta = 0;

    printf("\nIngrese el numero de ID del Cliente: ");
    scanf("%d", &idCliente);

    while (tipoCuenta < 1 || tipoCuenta > 3) {
    printf("\n 1. Caja de Ahorro en Pesos, 2. Caja de Ahorro en U$D, 3. Cta Cte en $");
    printf("\nIngrese el tipo de cuenta: ");
    scanf("%d", &tipoCuenta);
    if (tipoCuenta < 1 || tipoCuenta > 3) {
        printf("\nTipo de cuenta invalida. Por favor reingrese.");
    }
    }
    cuenta.idCliente = idCliente;
    cuenta.id = id(archi) + 1;
    cuenta.nroCuenta = randomNroCuenta(archi, tipoCuenta);
    cuenta.tipoDeCuenta = tipoCuenta;
    cuenta.costoMensual = costoMantenimiento(tipoCuenta);
    cuenta.saldo = 0;
    cuenta.eliminado = 0;


    return cuenta;
}

//Muestra Datos de la cuenta
void mostrarDatosCuenta(stCuenta cuenta) {
    puts("______________________________");
    printf("\nId Cuenta: %d", cuenta.id);
    printf("\nCliente: %d", cuenta.idCliente);
    printf("\nN%c de Cuenta: %d", 248, cuenta.nroCuenta);
    switch (cuenta.tipoDeCuenta) {
        case 1:
            printf("\nTipo de cuenta: CA $");
            break;
        case 2:
            printf("\nTipo de cuenta: CA U$D");
            break;
        case 3:
            printf("\nTipo de cuenta: CC $");
    }
    printf("\nSaldo: $%2.f", cuenta.saldo);
    printf("\nCosto de Mantenimiento: $%2.f", cuenta.costoMensual);
    if(cuenta.eliminado) {
        printf("\nEstado: Baja\n");
    } else {
        printf("\nEstado: Activa\n");
    }
    puts("______________________________");
}


//campo unico autoincrementable
int id (FILE * archi) {
    int id;

    fseek(archi, 0, 2);

    int cant = ftell(archi)/sizeof(stCuenta);

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

//Carga cuenta Usuario en archivo
void cargaCuentaUsuario2Arch(char nombreArchivo []) {
    FILE * archi = fopen(nombreArchivo, "ab");
    stCuenta cuenta;

    if(archi) {
        cuenta = altaCuentaUsuario(archi);
        fseek(archi, 0, 2);
        fwrite(&cuenta, sizeof(stCuenta), 1, archi);
        fclose(archi);
    }
}

//Listado de todas cuentas desde archivo
void mostrarCuentasDesdeArch(char nombreArchivo []) {
    FILE * archi = fopen(nombreArchivo, "rb");
    stCuenta cuenta;
    if (archi) {
        while(fread(&cuenta, sizeof(stCuenta), 1, archi) > 0) {
            mostrarDatosCuenta(cuenta);
        }
        fclose(archi);
    }
}


//Listar cuentas por cliente
void listarCuentasPorCliente(char nombreArchivo [], int idCliente) {
    stCuenta cuenta;
    FILE * archi = fopen(nombreArchivo, "rb");

    if(archi) {
        while(fread(&cuenta, sizeof(stCuenta), 1, archi) > 0) {
            if(cuenta.idCliente == idCliente) {
                mostrarDatosCuenta(cuenta);
            }
        }
        fclose(archi);
    }
}

/*------------------------------------------------------------------------------*/

//Cambio de Estado (Baja) y activar cuenta. Flag para comprobar exito.
int cambioEstadoCuentaPorId (char nombreArchivo [], int idCuenta) {
    stCuenta cuenta;
    int posCuenta;
    int flag = 0;
    cuenta = buscaCuentaPorId(nombreArchivo, idCuenta);
    posCuenta = sizeof (stCuenta) * (cuenta.id - 1) ;

    FILE * archi = fopen(nombreArchivo, "r+b");

    if (archi) {
        if (cuenta.id > 0) {
            if(cuenta.eliminado == 0){
                cuenta.eliminado = 1;
            } else {
                cuenta.eliminado = 0;
            }
            fseek(archi, posCuenta, SEEK_SET);
            fwrite(&cuenta, sizeof(stCuenta), 1, archi);
            flag = 1;
        }
        fclose(archi);
    }

    return flag;
}


//Busca cuenta por ID. Si cuenta.id == 0, la cuenta no existe
stCuenta buscaCuentaPorId (char nombreArchivo [], int idCuenta) {
    stCuenta cuenta;
    cuenta.id = 0;
    int flag = 0;
    FILE * archi = fopen(nombreArchivo, "rb");

    if (archi) {
        while (flag == 0 && fread(&cuenta, sizeof(stCuenta), 1, archi) > 0) {
            if (cuenta.id == idCuenta) {
                flag = 1;
            }
        }
        fclose(archi);
    }
    return cuenta;
}



//Comprueba existencia de cuenta. Para calcular numero de cuenta
int existeCuenta(FILE * archi, int tipoCuenta, int numeroCuenta) {
    int flag = 0;
    stCuenta cuenta;
    rewind(archi);

    while(flag == 0 && fread(&cuenta, sizeof(stCuenta), 1, archi) > 0) {
        if(cuenta.tipoDeCuenta == tipoCuenta && cuenta.nroCuenta == numeroCuenta) {
            flag = 1;
        }
    }
    return flag;
}

//Calcula el costo de mantenimiento según tipo de cuenta
float costoMantenimiento(int tipoCuenta) {
    float costoMant ;

    switch (tipoCuenta) {
        case 1:
            costoMant = 0;
            break;
        case 2:
            costoMant = 10; //costo al 03/06 BNA U$S 10
            break;
        case 3:
            costoMant = 6670.73; //costo a 03/6 BNA
            break;
        default:
            costoMant = 0;
    }

    return costoMant;
}

//Modificacion tipo de cuenta// retorna 1 si tuvo exito 0 si no
int modificaTipoCuentaPorId(char nombreArchivo [], int id, int tipoCuenta) {
    int flag = 0;
    stCuenta cuenta;
    cuenta = buscaCuentaPorId(nombreArchivo, id);
    FILE * archi = fopen(nombreArchivo, "r+b");

    if(archi) {
        cuenta.nroCuenta = randomNroCuenta(archi, tipoCuenta);
        cuenta.tipoDeCuenta = tipoCuenta;
        fseek(archi, sizeof(stCuenta) * (id-1), 0);
        fwrite(&cuenta, sizeof(stCuenta), 1, archi);
        flag = 1;

        fclose(archi);
    }

    return flag;
}


//Consulta cuenta por id
void consultaCuentaPorId(char nombreArchivo [], int id) {
    stCuenta cuenta;
    cuenta = buscaCuentaPorId(nombreArchivo, id);
    mostrarDatosCuenta(cuenta);
}
